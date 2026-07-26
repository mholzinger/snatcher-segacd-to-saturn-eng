#!/usr/bin/env python3
"""Build a patched Saturn disc from master.json (length-preserving).

Applies every translated line in translation/master.json into its DATA.BIN
chunk (English as full-width SJIS, token-encoded, padded/truncated to the
original byte length so chunk sizes — and all inline VM offsets — are
preserved), then patches the affected sectors inside a copy of track 1 and
emits a bootable cue.

This is the length-preserving build (works today; long lines truncate until
the half-width font + relocating inserter land). It is the end-to-end path
from source-of-truth → playable disc.

Usage: build_full_patch.py <src_disc_dir> <out_dir>
"""

import json
import os
import shutil
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR = 2352
USER = 16
DATA_BIN_LBA = 96
INDEX_OFF = 0x362F4  # 639-entry chunk index inside MAIN_L.BIN
FW_SPACE = "　"


# ASCII punctuation whose naive full-width form is absent from Shift-JIS;
# map to the SJIS-representable full-width equivalent.
FW_FIX = {"'": "’", '"': "”", "-": "－", "~": "〜"}


def to_fullwidth(s):
    s = s.replace("<br>", "￥")  # line-break control char, already full-width/SJIS
    out = []
    for ch in s:
        o = ord(ch)
        if ch == " ":
            fw = FW_SPACE
        elif ch in FW_FIX:
            fw = FW_FIX[ch]
        elif 0x21 <= o <= 0x7E:
            fw = chr(o - 0x20 + 0xFF00)
        else:
            fw = ch
        try:
            fw.encode("shift_jis")
        except UnicodeEncodeError:
            fw = FW_SPACE  # last-resort: unrepresentable char -> space
        out.append(fw)
    return "".join(out)


LINE_BREAK = "￥"  # SJIS 0x818F; extractor renders it as <br>


def encode(text):
    # restore the line-break control char before tokenizing
    text = text.replace("<br>", LINE_BREAK)
    b = b""
    for c in text:
        s = struct.unpack(">H", c.encode("shift_jis"))[0]
        b += struct.pack(">H", (0x10100 - s) & 0xFFFF)
    return b


def orig_len(chunk, off):
    i, n = off, 0
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
    src_dir, out_dir = sys.argv[1:]
    os.makedirs(out_dir, exist_ok=True)
    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    main_bin = open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read()

    # group translated lines by chunk
    by_chunk = {}
    for e in master:
        if e["en"]:
            by_chunk.setdefault(e["chunk"], []).append((int(e["offset"], 16), e["en"]))

    # build patched chunk bytes and remember each chunk's DATA.BIN sector
    patches = []  # (data_bin_offset, bytes)
    stats = {"applied": 0, "truncated": 0, "chunks": 0}
    for chunk_name, lines in by_chunk.items():
        idx = int(chunk_name.split("_")[1])
        sec, _ = struct.unpack_from(">HH", main_bin, INDEX_OFF + idx * 4)
        chunk = bytearray(open(os.path.join(ROOT, "extracted/saturn/data_bin",
                                            f"{chunk_name}.bin"), "rb").read())
        for off, en in lines:
            target = orig_len(chunk, off)
            if target == 0:
                continue
            fw = to_fullwidth(en)
            enc = encode(fw)[:target]
            enc += encode(FW_SPACE * ((target - len(enc)) // 2))
            enc += b"\x00" * (target - len(enc))
            if len(encode(to_fullwidth(en))) > target:
                stats["truncated"] += 1
            chunk[off:off + target] = enc[:target]
            stats["applied"] += 1
        stats["chunks"] += 1
        # record sector patches for every 2048-block this chunk occupies
        patches.append((sec * 2048, bytes(chunk)))

    # copy disc, hardlink big unchanged tracks
    t1_dst = os.path.join(out_dir, "Snatcher (Japan) (Track 1).bin")
    print("copying track 1...")
    shutil.copyfile(os.path.join(src_dir, "Snatcher (Japan) (Track 1).bin"), t1_dst)
    for n in (2, 3):
        s = os.path.join(src_dir, f"Snatcher (Japan) (Track {n}).bin")
        dd = os.path.join(out_dir, f"Snatcher (Japan) (Track {n}).bin")
        if not os.path.exists(dd):
            os.link(s, dd)
    shutil.copyfile(os.path.join(src_dir, "Snatcher (Japan).cue"),
                    os.path.join(out_dir, "Snatcher (Japan).cue"))

    # write patches into track 1 (DATA.BIN spans MODE1/2352 sectors)
    f = open(t1_dst, "r+b")
    for data_off, blob in patches:
        pos = data_off
        rem = blob
        while rem:
            lba = DATA_BIN_LBA + pos // 2048
            ins = pos % 2048
            n = min(2048 - ins, len(rem))
            f.seek(lba * SECTOR + USER + ins)
            f.write(rem[:n])
            rem = rem[n:]
            pos += n
    f.close()
    print(f"patched {stats['applied']} lines across {stats['chunks']} chunks "
          f"({stats['truncated']} truncated at full-width)")
    print(f"boot: mednafen \"{os.path.join(out_dir, 'Snatcher (Japan).cue')}\"")


if __name__ == "__main__":
    main()
