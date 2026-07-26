#!/usr/bin/env python3
"""Proof-of-concept English text injection for Saturn Snatcher.

Replaces a Japanese line in scene chunk_022 (JunkerHQ reception) with
English rendered as full-width SJIS characters, re-encodes with the
game's token scheme (stored = 0x10100 - SJIS), patches the bytes into
DATA.BIN inside a copy of the track-1 BIN, and emits a bootable cue.

Usage: inject_poc.py <src_disc_dir> <out_dir>
"""

import os
import shutil
import struct
import sys

# --- patch definition -----------------------------------------------------
ORIG = "ＪＵＮＫＥＲ本部です。￥何のご用でしょうか？"
NEW = "ＷＥＬＣＯＭＥ　ＴＯ￥ＪＵＮＫＥＲ　ＨＱ．"  # padded to same length below

# chunk_022 = DATA.BIN index entry 22; located during analysis
DATA_BIN_LBA = 96          # DATA.BIN extent start (ISO9660)
INDEX_TABLE_MAIN_OFF = 0x362F4  # index table inside MAIN_L.BIN
CHUNK = 22
SECTOR_RAW = 2352
USER_OFF = 16              # MODE1/2352 user data offset


def encode(text):
    out = b""
    for c in text:
        sjis = struct.unpack(">H", c.encode("shift_jis"))[0]
        out += struct.pack(">H", (0x10100 - sjis) & 0xFFFF)
    return out


def main():
    src_dir, out_dir = sys.argv[1:]
    os.makedirs(out_dir, exist_ok=True)

    # pad NEW with full-width spaces to match ORIG length
    new = NEW + "　" * (len(ORIG) - len(NEW))
    enc_orig, enc_new = encode(ORIG), encode(new)
    assert len(enc_orig) == len(enc_new), (len(enc_orig), len(enc_new))

    # chunk_022 location inside DATA.BIN, from the index table
    main = open("extracted/saturn/files/MAIN_L.BIN", "rb").read()
    sec, words = struct.unpack_from(">HH", main, INDEX_TABLE_MAIN_OFF + CHUNK * 4)
    chunk = open(f"extracted/saturn/data_bin/chunk_{CHUNK:03d}.bin", "rb").read()
    off_in_chunk = chunk.find(enc_orig)
    assert off_in_chunk >= 0, "original string not found in chunk"
    print(f"chunk_{CHUNK}: DATA.BIN sector {sec}, string at chunk offset {off_in_chunk:#x}")

    # absolute position within DATA.BIN
    data_bin_off = sec * 2048 + off_in_chunk

    # copy disc files
    t1_src = os.path.join(src_dir, "Snatcher (Japan) (Track 1).bin")
    t1_dst = os.path.join(out_dir, "Snatcher (Japan) (Track 1).bin")
    print("copying track 1 (457MB)...")
    shutil.copyfile(t1_src, t1_dst)
    for n in (2, 3):
        s = os.path.join(src_dir, f"Snatcher (Japan) (Track {n}).bin")
        d = os.path.join(out_dir, f"Snatcher (Japan) (Track {n}).bin")
        if not os.path.exists(d):
            os.link(s, d)  # hardlink to save space
    shutil.copyfile(os.path.join(src_dir, "Snatcher (Japan).cue"),
                    os.path.join(out_dir, "Snatcher (Japan).cue"))

    # patch bytes across MODE1 raw sectors
    f = open(t1_dst, "r+b")
    remaining = enc_new
    pos = data_bin_off
    while remaining:
        lba = DATA_BIN_LBA + pos // 2048
        in_sec = pos % 2048
        n = min(2048 - in_sec, len(remaining))
        f.seek(lba * SECTOR_RAW + USER_OFF + in_sec)
        f.write(remaining[:n])
        remaining = remaining[n:]
        pos += n
    f.close()
    print(f"patched {len(enc_new)} bytes at DATA.BIN+{data_bin_off:#x} "
          f"(track LBA {DATA_BIN_LBA + data_bin_off // 2048})")
    print(f"boot with: mednafen \"{os.path.join(out_dir, 'Snatcher (Japan).cue')}\"")


if __name__ == "__main__":
    main()
