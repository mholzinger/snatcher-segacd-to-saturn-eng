#!/usr/bin/env python3
"""Extract files and audio from a BIN/CUE disc image.

Handles multi-file cue sheets (redump style), MODE1/2352, MODE2/2352
(Form 1 and Form 2), and AUDIO tracks. Walks the ISO9660 filesystem on
the data track and extracts every file; rips audio tracks to WAV.

Usage:
    extract_disc.py <cuefile> <outdir> [--no-audio]

Output layout:
    <outdir>/files/...      extracted ISO9660 filesystem
    <outdir>/audio/trackNN.wav
    <outdir>/manifest.tsv   path, disc LBA, size, sha1
"""

import hashlib
import os
import re
import struct
import sys

SECTOR_RAW = 2352
SYNC = b"\x00" + b"\xff" * 10 + b"\x00"


class Track:
    def __init__(self, number, mode, path):
        self.number = number
        self.mode = mode  # 'MODE1/2352', 'MODE2/2352', 'AUDIO'
        self.path = path
        self.sectors = os.path.getsize(path) // SECTOR_RAW
        self.start_lba = 0  # filled in by parse_cue


def parse_cue(cue_path):
    cue_dir = os.path.dirname(os.path.abspath(cue_path))
    tracks = []
    current_file = None
    with open(cue_path, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.strip()
            m = re.match(r'FILE\s+"(.+)"\s+BINARY', line, re.IGNORECASE)
            if m:
                current_file = os.path.join(cue_dir, m.group(1))
                continue
            m = re.match(r"TRACK\s+(\d+)\s+(\S+)", line, re.IGNORECASE)
            if m:
                tracks.append(Track(int(m.group(1)), m.group(2).upper(), current_file))
    lba = 0
    for t in tracks:
        t.start_lba = lba
        lba += t.sectors
    return tracks


class Disc:
    def __init__(self, tracks):
        self.tracks = tracks
        self.handles = {}

    def track_for_lba(self, lba):
        for t in self.tracks:
            if t.start_lba <= lba < t.start_lba + t.sectors:
                return t
        raise ValueError(f"LBA {lba} outside disc")

    def read_sector_raw(self, lba):
        t = self.track_for_lba(lba)
        fh = self.handles.get(t.path)
        if fh is None:
            fh = self.handles[t.path] = open(t.path, "rb")
        fh.seek((lba - t.start_lba) * SECTOR_RAW)
        return fh.read(SECTOR_RAW), t

    def read_user_data(self, lba):
        """Return (data, form) — 2048 bytes for Mode1/Mode2Form1, 2324 for Form2."""
        raw, t = self.read_sector_raw(lba)
        if t.mode == "AUDIO":
            return raw, "audio"
        if raw[:12] != SYNC:
            # Some images store already-cooked 2048 sectors; not expected here.
            raise ValueError(f"Bad sync at LBA {lba} in {t.path}")
        mode = raw[15]
        if mode == 1:
            return raw[16 : 16 + 2048], "m1"
        if mode == 2:
            submode = raw[18]
            if submode & 0x20:  # Form 2
                return raw[24 : 24 + 2324], "m2f2"
            return raw[24 : 24 + 2048], "m2f1"
        raise ValueError(f"Unknown sector mode {mode} at LBA {lba}")


def read_extent(disc, lba, size):
    out = bytearray()
    while len(out) < size:
        data, _ = disc.read_user_data(lba)
        out += data
        lba += 1
    return bytes(out[:size])


def parse_dir_records(data):
    """Yield (name, lba, size, is_dir) from one directory extent."""
    off = 0
    while off < len(data):
        rec_len = data[off]
        if rec_len == 0:
            # rest of this 2048-byte sector is padding; jump to next sector
            off = (off // 2048 + 1) * 2048
            continue
        rec = data[off : off + rec_len]
        lba = struct.unpack_from("<I", rec, 2)[0]
        size = struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]
        name_len = rec[32]
        name = rec[33 : 33 + name_len]
        if name not in (b"\x00", b"\x01"):
            clean = name.decode("ascii", "replace").split(";")[0]
            yield clean, lba, size, bool(flags & 0x02)
        off += rec_len


def walk_iso(disc, out_dir, manifest):
    pvd, _ = disc.read_user_data(16)
    if pvd[1:6] != b"CD001" or pvd[0] != 1:
        raise ValueError("No ISO9660 PVD at LBA 16")
    root = pvd[156 : 156 + 34]
    root_lba = struct.unpack_from("<I", root, 2)[0]
    root_size = struct.unpack_from("<I", root, 10)[0]

    def recurse(lba, size, rel):
        data = read_extent(disc, lba, size)
        for name, elba, esize, is_dir in parse_dir_records(data):
            rpath = os.path.join(rel, name)
            if is_dir:
                recurse(elba, esize, rpath)
            else:
                dest = os.path.join(out_dir, "files", rpath)
                os.makedirs(os.path.dirname(dest), exist_ok=True)
                blob = read_extent(disc, elba, esize)
                with open(dest, "wb") as f:
                    f.write(blob)
                sha = hashlib.sha1(blob).hexdigest()
                manifest.append((rpath, elba, esize, sha))
                print(f"  {rpath:<40} LBA {elba:<8} {esize:>10} bytes")

    recurse(root_lba, root_size, "")


def rip_audio(track, out_dir):
    dest = os.path.join(out_dir, "audio", f"track{track.number:02d}.wav")
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    data_size = track.sectors * SECTOR_RAW
    with open(track.path, "rb") as src, open(dest, "wb") as f:
        f.write(b"RIFF" + struct.pack("<I", 36 + data_size) + b"WAVE")
        f.write(b"fmt " + struct.pack("<IHHIIHH", 16, 1, 2, 44100, 176400, 4, 16))
        f.write(b"data" + struct.pack("<I", data_size))
        while True:
            chunk = src.read(1 << 20)
            if not chunk:
                break
            f.write(chunk)
    print(f"  track {track.number:02d} -> {dest} ({data_size} bytes)")


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    no_audio = "--no-audio" in sys.argv
    if len(args) != 2:
        sys.exit(__doc__)
    cue_path, out_dir = args
    tracks = parse_cue(cue_path)
    disc = Disc(tracks)
    print(f"{len(tracks)} tracks:")
    for t in tracks:
        print(f"  {t.number:02d} {t.mode:<12} LBA {t.start_lba:<8} {t.sectors} sectors")

    manifest = []
    print("\nExtracting ISO9660 filesystem:")
    walk_iso(disc, out_dir, manifest)

    if not no_audio:
        print("\nRipping audio tracks:")
        for t in tracks:
            if t.mode == "AUDIO":
                rip_audio(t, out_dir)

    mpath = os.path.join(out_dir, "manifest.tsv")
    with open(mpath, "w") as f:
        f.write("path\tlba\tsize\tsha1\n")
        for row in sorted(manifest):
            f.write("\t".join(str(x) for x in row) + "\n")
    print(f"\n{len(manifest)} files extracted. Manifest: {mpath}")


if __name__ == "__main__":
    main()
