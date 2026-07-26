#!/usr/bin/env python3
"""Batch English-insertion for Saturn Snatcher scene chunks.

Length-preserving strategy (safe, no bytecode relocation required):
each Japanese string is replaced in place by English rendered as full-width
SJIS, re-encoded with the game's token scheme (stored = 0x10100 - SJIS), and
padded with full-width spaces / truncated to the EXACT original byte length.
Because total chunk size is unchanged, every inline offset operand in the
bytecode stays valid — the approach proven on-screen by inject_poc.

Input: a translation JSON  { "chunk_022": { "<offset_hex>": "English line", ... }, ... }
       offsets/keys must match tools/extract_saturn_script.py output.
Output: patched chunk files + a per-string fit report.

Usage: build_translation_patch.py <data_bin_dir> <translation.json> <out_dir>
"""

import json
import os
import struct
import sys

FW_SPACE = "　"


def to_fullwidth(s):
    """Map ASCII to full-width SJIS-representable equivalents."""
    out = []
    for ch in s:
        o = ord(ch)
        if ch == " ":
            out.append(FW_SPACE)
        elif 0x21 <= o <= 0x7E:
            out.append(chr(o - 0x20 + 0xFF00))  # ! -> ！ etc.
        else:
            out.append(ch)
    return "".join(out)


def encode_tokens(text):
    out = b""
    for c in text:
        sjis = struct.unpack(">H", c.encode("shift_jis"))[0]
        out += struct.pack(">H", (0x10100 - sjis) & 0xFFFF)
    return out


def fit_to_length(english, target_bytes):
    """Render English full-width, pad/truncate to exactly target_bytes (must be even)."""
    fw = to_fullwidth(english)
    enc = encode_tokens(fw)
    if len(enc) > target_bytes:
        # truncate to whole chars
        enc = enc[:target_bytes]
        return enc, "TRUNCATED"
    pad = encode_tokens(FW_SPACE * ((target_bytes - len(enc)) // 2))
    return enc + pad, "ok"


def orig_len_at(chunk, offset):
    """Byte length of the token run starting at offset (until a non-text token)."""
    i = offset
    n = 0
    while i < len(chunk) - 1:
        v = struct.unpack_from(">H", chunk, i)[0]
        neg = (0x10100 - v) & 0xFFFF
        hi, lo = neg >> 8, neg & 0xFF
        if (0x81 <= hi <= 0x9F or 0xE0 <= hi <= 0xEA) and (0x40 <= lo <= 0xFC and lo != 0x7F):
            n += 2
            i += 2
        else:
            break
    return n


def main():
    src_dir, tr_json, out_dir = sys.argv[1:]
    os.makedirs(out_dir, exist_ok=True)
    translations = json.load(open(tr_json, encoding="utf-8"))
    report = []
    for chunk_name, lines in translations.items():
        idx = int(chunk_name.split("_")[1])
        chunk = bytearray(open(os.path.join(src_dir, f"{chunk_name}.bin"), "rb").read())
        applied = 0
        for off_hex, english in lines.items():
            off = int(off_hex, 16)
            target = orig_len_at(chunk, off)
            if target == 0:
                report.append((chunk_name, off_hex, "NO_TEXT_AT_OFFSET", english))
                continue
            enc, status = fit_to_length(english, target)
            enc = enc + b"\x00" * (target - len(enc))  # pad remainder if truncated odd
            chunk[off:off + target] = enc[:target]
            applied += 1
            report.append((chunk_name, off_hex, status, english))
        open(os.path.join(out_dir, f"{chunk_name}.bin"), "wb").write(chunk)
        print(f"{chunk_name}: {applied} lines patched (chunk size unchanged)")
    trunc = sum(1 for r in report if r[2] == "TRUNCATED")
    print(f"\ntotal lines: {len(report)}, truncated (too long to fit): {trunc}")
    json.dump(report, open(os.path.join(out_dir, "fit_report.json"), "w"),
              ensure_ascii=False, indent=1)


if __name__ == "__main__":
    main()
