#!/usr/bin/env python3
"""STABLE English build — the hang-free recipe (2026-07-27).

Hard-won rules from ~15 in-emulator boot tests:
  * NEVER shift the disc layout. Track 1 stays byte-identical to the original
    except the scene-chunk sectors and (optionally) MAIN_L; tracks 2/3 are the
    untouched originals. Growing the disc moves track 2 and, more importantly,
    every build that differed from a working one by the SPEAKER PATCH hung.
  * NEVER run the speaker-name relocation patch (tools/patch_speakers.py):
    writing names into the "free" region 0x060E71F0 + repointing the table at
    0x060C1F14 deterministically hangs the receptionist interaction (proven by
    the noshift_en vs noshift_nospk differential — identical builds except the
    speaker patch; with it hangs, without it works). Speaker names stay JP.
  * Text is written IN PLACE into each record's original byte slot (chunk size
    unchanged -> no index/layout change). English longer than the slot is
    TRUNCATED (the half-width font is the real fix for that). Voiced records
    (say-call mode 4/5) are left untouched.

Result: fully playable English build. Voiced dialogue = JP voice + JP text;
everything else = English (truncated where the original slot is too small).

Usage: build_stable_en.py [out_dir]   (default build/stable_en)
"""
import json
import os
import re
import shutil
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble
import build_full_en2 as B

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR, USER = 2352, 16
DATA_LBA, MAIN_LBA = 96, 5451
INDEX = 0x362F4
SRC = os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")


def inplace_fit(d, jobs, stats):
    h0, h1, ts, te = reassemble.sections(d)
    recs = dict(reassemble.records(d))
    voiced = set()
    for m in re.finditer(rb"\xc0\x01\xa0.", d[4:ts], re.S):
        pos = 4 + m.start() + 4
        mode = d[4 + m.start() + 3]
        if pos + 2 <= ts:
            v = struct.unpack(">H", d[pos:pos + 2])[0]
            if v < 0x8000 and mode in (4, 5):
                voiced.add(v)
    out = bytearray(d)
    for off, en in jobs:
        if off not in recs:
            continue
        tok = B.token_for(off - (h0 + 4))
        if tok in voiced:
            stats["voiced_skip"] += 1
            continue
        jl = recs[off] - off
        enc = reassemble.encode_text(B.wrap(en))
        if len(enc) > jl:
            stats["truncated"] += 1
        enc = enc[:jl]
        pad = (jl - len(enc)) // 2
        filled = enc + reassemble.encode_text("　" * pad)
        filled += b"\x00" * (jl - len(filled))
        out[off:off + jl] = filled
        stats["inplace"] += 1
    assert len(out) == len(d)
    return bytes(out)


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/stable_en")
    os.makedirs(out, exist_ok=True)
    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    by_chunk = {}
    for e in master:
        if e.get("en"):
            by_chunk.setdefault(int(e["chunk"].split("_")[1]), []).append(
                (int(e["offset"], 16), e["en"]))
    main_bin = open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read()

    stats = {k: 0 for k in ("inplace", "truncated", "voiced_skip")}
    writes = []
    for i in sorted(by_chunk):
        if not (21 <= i <= 59):
            continue
        sec, _ = struct.unpack_from(">HH", main_bin, INDEX + i * 4)
        d = open(os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{i:03d}.bin"), "rb").read()
        writes.append((sec, inplace_fit(d, sorted(by_chunk[i]), stats)))
    print(f"stats: {stats}")

    src_t1 = os.path.join(SRC, "Snatcher (Japan) (Track 1).bin")
    dst_t1 = os.path.join(out, "Snatcher (Japan) (Track 1).bin")
    print("copying track 1 (verbatim base)...")
    shutil.copyfile(src_t1, dst_t1)
    f = open(dst_t1, "r+b")
    for sec, dn in writes:
        pos, rem = sec * 2048, dn
        while rem:
            lba = DATA_LBA + pos // 2048
            ins = pos % 2048
            n = min(2048 - ins, len(rem))
            f.seek(lba * SECTOR + USER + ins)
            f.write(rem[:n])
            rem = rem[n:]
            pos += n
    f.close()
    # MAIN_L untouched (NO speaker patch). Tracks 2/3 hard-linked verbatim.
    for n in (2, 3):
        p = os.path.join(out, f"Snatcher (Japan) (Track {n}).bin")
        if not os.path.exists(p):
            os.link(os.path.join(SRC, f"Snatcher (Japan) (Track {n}).bin"), p)
    shutil.copyfile(os.path.join(SRC, "Snatcher (Japan).cue"),
                    os.path.join(out, "Snatcher (Japan).cue"))
    print(f'boot: mednafen "{os.path.join(out, "Snatcher (Japan).cue")}"')


if __name__ == "__main__":
    main()
