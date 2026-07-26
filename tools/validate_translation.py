#!/usr/bin/env python3
"""Validate a translation/chunk_XXX.json before it merges into the master DB.

Checks, against the extracted Japanese source:
  1. Key parity — every JP offset present, no extras.
  2. No HTML-escaped control codes (&lt; &gt; &amp;).
  3. Every line SJIS-encodable after full-width conversion (would the encoder choke?).
  4. Line-break sanity — <br> count is plausible vs the JP line.

Usage: validate_translation.py <chunk_XXX.json> [more.json ...]
Exit non-zero if any file fails.
"""

import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
from build_full_patch import to_fullwidth  # noqa: E402

SCRIPT = json.load(open(os.path.join(ROOT, "extracted/script/saturn_script.json"), encoding="utf-8"))


def validate(path):
    data = json.load(open(path, encoding="utf-8"))
    chunk = list(data.keys())[0]
    lines = data[chunk]
    jp = {f"{e['offset']:#06x}": e["text"] for e in SCRIPT.get(chunk, [])}
    errs, warns = [], []

    jp_keys, tr_keys = set(jp), set(lines)
    if jp_keys - tr_keys:
        warns.append(f"incomplete: {len(jp_keys - tr_keys)}/{len(jp_keys)} keys untranslated")
    if tr_keys - jp_keys:
        errs.append(f"{len(tr_keys - jp_keys)} extra keys not in JP source")

    for k, v in lines.items():
        if re.search(r"&(lt|gt|amp);", v):
            errs.append(f"{k}: HTML-escaped code")
        # SJIS-encodability check via the real encoder path
        try:
            fw = to_fullwidth(v)
            for ch in fw.replace("￥", ""):
                ch.encode("shift_jis")
        except UnicodeEncodeError as e:
            errs.append(f"{k}: unencodable char {e.object!r}")
        # line-break sanity: EN <br> count shouldn't wildly exceed JP
        if k in jp:
            jb, eb = jp[k].count("<br>"), v.count("<br>")
            if eb > jb + 2:
                warns.append(f"{k}: {eb} <br> vs {jb} in JP")

    return chunk, len(lines), errs, warns


def main():
    ok = True
    for path in sys.argv[1:]:
        chunk, n, errs, warns = validate(path)
        status = "PASS" if not errs else "FAIL"
        print(f"[{status}] {chunk}: {n} lines, {len(errs)} errors, {len(warns)} warnings")
        for e in errs[:10]:
            print(f"   ERROR {e}")
        for w in warns[:5]:
            print(f"   warn  {w}")
        if errs:
            ok = False
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
