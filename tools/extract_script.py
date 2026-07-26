#!/usr/bin/env python3
"""Extract English script from Sega CD Snatcher SP*.BIN files.

Text region starts at 0x3800; strings are 0xFF-terminated ASCII with
embedded control bytes (0xF2 = line break, others preserved as <hex> tags).

Usage:
    extract_script.py <files_dir> <out_json>

Output: JSON {"SP06.BIN": [{"index": n, "offset": abs_off, "text": "..."}]}
"""

import glob
import json
import os
import sys

TEXT_BASE = 0x3800

# Control bytes observed across SP files; 0xF2 confirmed as line break.
TAGS = {0xF2: "<br>"}


def decode(raw):
    out = []
    for b in raw:
        if 0x20 <= b <= 0x7E:
            out.append(chr(b))
        else:
            out.append(TAGS.get(b, f"<{b:02x}>"))
    return "".join(out)


def extract_file(path):
    data = open(path, "rb").read()
    if len(data) <= TEXT_BASE:
        return []
    entries = []
    off = TEXT_BASE
    for raw in data[TEXT_BASE:].split(b"\xff"):
        # trailing zero padding after the last real string
        stripped = raw.strip(b"\x00")
        if stripped:
            entries.append(
                {"index": len(entries), "offset": off, "text": decode(stripped)}
            )
        off += len(raw) + 1
    return entries


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    files_dir, out_json = sys.argv[1:]
    script = {}
    total = 0
    for path in sorted(glob.glob(os.path.join(files_dir, "SP*.BIN"))):
        name = os.path.basename(path)
        entries = extract_file(path)
        script[name] = entries
        total += len(entries)
        print(f"{name}: {len(entries)} strings")
    os.makedirs(os.path.dirname(os.path.abspath(out_json)), exist_ok=True)
    with open(out_json, "w") as f:
        json.dump(script, f, indent=1, ensure_ascii=True)
    print(f"\n{total} strings -> {out_json}")


if __name__ == "__main__":
    main()
