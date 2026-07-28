#!/usr/bin/env python3
"""Produce the injection-ready half-width font for the VDP1 glyph cache.

Input  : assets/halfwidth_ascii_8x16_4bpp.bin  (95 glyphs, 8x16 4bpp, 64B/glyph,
          4 bytes/row; ASCII 0x20-0x7E; local working asset, gitignored)
Output : assets/halfwidth_ascii_16cell_4bpp.bin (95 glyphs, 128B/glyph)

Layout: each 8px glyph is placed in the LEFT 4 bytes of a 16px-wide (8-byte) row,
right half blank — so an 8-wide VDP1 sprite reading from a 16px-stride glyph slot
(0x25C15000 + slot*0x80) draws the half-width character. (.bin outputs are
gitignored blobs; this script is the tracked, reproducible source of them.)
"""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "assets/halfwidth_ascii_8x16_4bpp.bin")
DST = os.path.join(ROOT, "assets/halfwidth_ascii_16cell_4bpp.bin")


def convert(src_bytes):
    n = len(src_bytes) // 64
    out = bytearray()
    for g in range(n):
        gl = src_bytes[g * 64:g * 64 + 64]
        for row in range(16):
            out += gl[row * 4:row * 4 + 4] + b"\x00\x00\x00\x00"
    return bytes(out)


if __name__ == "__main__":
    data = convert(open(SRC, "rb").read())
    open(DST, "wb").write(data)
    print(f"wrote {DST}: {len(data)} bytes ({len(data)//128} glyphs, 128B/glyph)")
