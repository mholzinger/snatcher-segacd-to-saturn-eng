#!/usr/bin/env python3
"""Patch MAIN_L.BIN in a disc build to render condensed/half-width dialogue text.

Two data edits (no code change), both in MAIN_L.BIN (load base 0x060B0000,
disc LBA 5451, MODE1/2352):

1. Glyph sprite size @ 0x060E0CC0 (file 0x30CC0): 0x020E (16w x 14h) -> 0x010E
   (8w x 14h). VDP1 samples the glyph texture to the sprite size, so existing
   16px glyphs are squished to half-width.
2. Pitch table @ 0x060E5358 (file 0x35358): 80 records x 12 bytes (4 rows x 20),
   X coord at short-index 4. Re-space from step 14 to step `PITCH` (default 8),
   keeping each row's start X.

This is an experiment: if VDP1 scaling reads clean, we get condensed English
in the same 20-slot rows. (Full 40-char rows need a rebuilt/expanded table.)

Usage: patch_halfwidth.py <build_dir> [pitch=8]
"""

import struct
import sys

MAIN_LBA = 5451
SECTOR = 2352
USER = 16
BASE = 0x060B0000
SIZE_OFF = 0x060E0CC0 - BASE   # 0x30CC0
PITCH_OFF = 0x060E5358 - BASE  # 0x35358


def rw_mainl(path, edits):
    """Apply {file_offset: bytes} edits to MAIN_L.BIN across its MODE1 sectors."""
    f = open(path, "r+b")
    for off, data in edits.items():
        pos = off
        rem = data
        while rem:
            lba = MAIN_LBA + pos // 2048
            ins = pos % 2048
            n = min(2048 - ins, len(rem))
            f.seek(lba * SECTOR + USER + ins)
            f.write(rem[:n])
            rem = rem[n:]
            pos += n
    f.close()


def read_mainl(path, off, length):
    f = open(path, "rb")
    out = b""
    pos = off
    while len(out) < length:
        lba = MAIN_LBA + pos // 2048
        ins = pos % 2048
        n = min(2048 - ins, length - len(out))
        f.seek(lba * SECTOR + USER + ins)
        out += f.read(n)
        pos += n
    return out


def main():
    build = sys.argv[1]
    pitch = int(sys.argv[2]) if len(sys.argv) > 2 else 8
    track1 = f"{build}/Snatcher (Japan) (Track 1).bin"

    edits = {}
    # 1. size field 0x020E -> 0x010E
    cur = read_mainl(track1, SIZE_OFF, 2)
    assert cur == b"\x02\x0e", f"size slot not 0x020E (got {cur.hex()}) — aborting"
    edits[SIZE_OFF] = b"\x01\x0e"

    # 2. pitch table: re-space X coords
    tbl = bytearray(read_mainl(track1, PITCH_OFF, 80 * 12))
    for g in range(80):
        rec = tbl[g * 12:(g + 1) * 12]
        ctrl = struct.unpack_from(">h", rec, 0)[0]
        if ctrl != 18432:
            break
        col = g % 20
        x0 = struct.unpack_from(">h", tbl, (g - col) * 12 + 8)[0] if col else \
             struct.unpack_from(">h", tbl, g * 12 + 8)[0]
        new_x = x0 + col * pitch
        struct.pack_into(">h", tbl, g * 12 + 8, new_x)
    edits[PITCH_OFF] = bytes(tbl)

    rw_mainl(track1, edits)
    print(f"patched MAIN_L.BIN: glyph size -> 8x14, pitch -> {pitch}px")
    print(f"boot: mednafen \"{build}/Snatcher (Japan).cue\"")


if __name__ == "__main__":
    main()
