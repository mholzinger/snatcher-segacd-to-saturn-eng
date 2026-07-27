#!/usr/bin/env python3
"""Extract Japanese script from Saturn Snatcher scene bytecode chunks.

Scene scripts are DATA.BIN chunks 21-98 (raw, not LZ). Text is embedded in
the VM bytecode as u16 tokens: stored = 0x10100 - SJIS_code (so the engine
decodes with a simple negate-and-add). Control chars appear in-text:
0x818F (yen sign) = line break, ＠色 sequences = color tags.

Usage: extract_saturn_script.py <data_bin_dir> <out_json>
"""

import glob
import json
import os
import struct
import sys


def decode_chunk(d, min_chars=2):
    """Yield (offset, decoded_string) for every token run decoding to SJIS."""
    out = bytearray()
    start = None
    i = 0
    while i < len(d) - 1:
        v = struct.unpack_from(">H", d, i)[0]
        neg = (0x10100 - v) & 0xFFFF
        hi, lo = neg >> 8, neg & 0xFF
        if (0x81 <= hi <= 0x9F or 0xE0 <= hi <= 0xEA) and (0x40 <= lo <= 0xFC and lo != 0x7F):
            if start is None:
                start = i
            out += bytes((hi, lo))
            i += 2
        else:
            if len(out) >= min_chars * 2:
                try:
                    yield start, out.decode("shift_jis")
                except UnicodeDecodeError:
                    pass
            out = bytearray()
            start = None
            i += 1
    if len(out) >= min_chars * 2:
        try:
            yield start, out.decode("shift_jis")
        except UnicodeDecodeError:
            pass


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    src_dir, out_json = sys.argv[1:]
    script = {}
    total = 0
    for idx in range(21, 99):
        p = os.path.join(src_dir, f"chunk_{idx:03d}.bin")
        if not os.path.exists(p):
            continue
        d = open(p, "rb").read()
        entries = [
            {"offset": off, "text": s.replace("￥", "<br>")}
            for off, s in decode_chunk(d)
        ]
        script[f"chunk_{idx:03d}"] = entries
        total += len(entries)
        print(f"chunk_{idx:03d}: {len(entries)} strings")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(script, f, ensure_ascii=False, indent=1)
    print(f"\n{total} strings -> {out_json}")


if __name__ == "__main__":
    main()
