#!/usr/bin/env python3
"""Patch the 80-entry speaker-name table in MAIN_L.BIN to English.

Names are raw SJIS with ＠color wrappers, pointer-referenced from a table at
0x060C1F14. English names are longer, so we RELOCATE: write new strings into
the verified-free zero region at 0x060E71F0 (2494 bytes, 0 code refs) and
repoint the table. Preserves each original ＠color prefix / ＠白 suffix; only
the name text is replaced (as full-width SJIS).

Usage: patch_speakers.py <build_dir>   (patches the build's MAIN_L.BIN on-disc)
"""

import struct
import sys

BASE = 0x060B0000
TABLE = 0x060C1F14
FREE = 0x060E71F0
FREE_LEN = 2494
MAIN_LBA = 5451
SECTOR = 2352
USER = 16

# id -> English name (ids 0,1 are non-speaker sentinels, left untouched)
NAMES = {
    2: "Metal Gear", 3: "Harry", 4: "Receptionist", 5: "Gillian", 6: "Mika",
    7: "Chief", 8: "Gaudi", 9: "Napoleon", 10: "Jamie", 11: "Clerk",
    12: "Katrina", 13: "Man", 14: "Woman", 15: "Passerby", 16: "Announcer",
    17: "Barker", 18: "Master", 19: "Power Pro", 20: "Goemon", 21: "Pastel",
    22: "Light", 23: "Dracula", 24: "Simon", 25: "Design Man", 26: "Isabella",
    27: "Freeman", 28: "Ivan", 29: "Lisa", 30: "Rie", 31: "Himago Girl",
    32: "Fukui II", 33: "Voice", 34: "Aizawa", 35: "Asata", 36: "Voicemail",
    37: "Mizutani", 38: "Kiyohara", 39: "Kidasun", 40: "Noguchi", 41: "Adachi",
    42: "Yoshitomi", 43: "Object", 44: "Takayuki", 45: "Asami", 46: "Naoya",
    47: "Yumiko", 48: "Komatsubara", 49: "Komatsubara Jr", 50: "Matsukawa",
    51: "Tacchan", 52: "Gaudi", 53: "Konami", 54: "Nijino", 55: "Fujisaki",
    56: "Kisaragi", 57: "Himoo", 58: "Katagiri", 59: "Koshiki", 60: "Kiyokawa",
    61: "Kagami", 62: "Asahina", 63: "Mikihara", 64: "Saotome", 65: "Ijuin",
    66: "Skios", 67: "Tsunashima", 68: "Takagi", 69: "Yamagishi", 70: "Koike",
    71: "Kimura", 72: "Hirata", 73: "Shoji", 74: "Nakamura", 75: "Parrot",
    76: "Customer", 77: "Petrovich", 78: "Random", 79: "Driver",
}

AT = b"\x81\x97"       # ＠ marker
SHIRO = b"\x81\x97\x94\x92"  # ＠白


def to_fw_sjis(s):
    out = b""
    for ch in s:
        o = ord(ch)
        if ch == " ":
            fw = "　"
        elif ch == "'":
            fw = "’"
        elif 0x21 <= o <= 0x7E:
            fw = chr(o - 0x20 + 0xFF00)
        else:
            fw = ch
        out += fw.encode("shift_jis")
    return out


def split_wrapper(raw):
    """Return (prefix ＠color bytes, suffix ＠白 or b'')."""
    prefix = raw[:4]  # ＠ + color kanji
    suffix = SHIRO if raw.endswith(SHIRO) and len(raw) > 8 else b""
    return prefix, suffix


def main():
    build = sys.argv[1]
    track1 = f"{build}/Snatcher (Japan) (Track 1).bin"
    d = open("extracted/saturn/files/MAIN_L.BIN", "rb").read()

    ptrs = [struct.unpack_from(">I", d, TABLE - BASE + i * 4)[0] for i in range(80)]
    blob = bytearray()          # new strings, packed
    new_ptrs = list(ptrs)
    cursor = FREE
    for i, en in NAMES.items():
        raw = d[ptrs[i] - BASE:]
        raw = raw[:raw.index(b"\x00")]
        prefix, suffix = split_wrapper(raw)
        s = prefix + to_fw_sjis(en) + suffix + b"\x00"
        new_ptrs[i] = cursor
        blob += s
        cursor += len(s)
    assert len(blob) <= FREE_LEN, f"names overflow free region ({len(blob)}>{FREE_LEN})"

    # edits: new blob at FREE, new pointer table
    new_table = b"".join(struct.pack(">I", p) for p in new_ptrs)
    edits = {FREE - BASE: bytes(blob), TABLE - BASE: new_table}

    f = open(track1, "r+b")
    for foff, data in edits.items():
        pos = foff
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
    print(f"patched {len(NAMES)} speaker names ({len(blob)} bytes into free region, "
          f"{FREE_LEN - len(blob)} free); table repointed")


if __name__ == "__main__":
    main()
