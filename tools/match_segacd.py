#!/usr/bin/env python3
"""Match Saturn lines to their official Sega CD English localization.

For each Saturn line that already has a (draft) English translation in
master.json, find the closest Sega CD English line by fuzzy similarity.
A high score means the line exists in both versions → we should adopt the
OFFICIAL Sega CD text verbatim (source-of-truth correctness). A low score
means the line is Saturn-exclusive → keep the draft for human review.

Usage: match_segacd.py [threshold=0.6]
Writes translation/segacd_matches.json and prints a summary.
"""

import json
import os
import re
import sys
from difflib import SequenceMatcher

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def norm(s):
    s = s.replace("<br>", " ")
    s = re.sub(r"<[0-9a-f]{2}>", "", s)
    s = re.sub(r"[^a-z0-9 ]", "", s.lower())
    return re.sub(r"\s+", " ", s).strip()


def main():
    threshold = float(sys.argv[1]) if len(sys.argv) > 1 else 0.6
    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    segacd = json.load(open(os.path.join(ROOT, "extracted/script/segacd_script.json"), encoding="utf-8"))
    # flatten Sega CD English lines with normalized keys
    seg_lines = []
    for fname, entries in segacd.items():
        for e in entries:
            n = norm(e["text"])
            if len(n) >= 4:
                seg_lines.append((n, e["text"], fname))

    matches = []
    hi = 0
    for m in master:
        if not m["en"]:
            continue
        q = norm(m["en"])
        if len(q) < 4:
            continue
        # cheap prefilter: share at least one 4+ char word
        qwords = set(w for w in q.split() if len(w) >= 4)
        best = (0.0, None, None)
        for n, orig, fname in seg_lines:
            if qwords and not (qwords & set(n.split())):
                continue
            r = SequenceMatcher(None, q, n).ratio()
            if r > best[0]:
                best = (r, orig, fname)
        if best[0] >= threshold:
            hi += 1
        matches.append({
            "chunk": m["chunk"], "offset": m["offset"], "jp": m["jp"],
            "draft_en": m["en"], "segacd_en": best[1], "score": round(best[0], 3),
            "segacd_file": best[2],
            "verdict": "adopt_official" if best[0] >= threshold else "saturn_exclusive_or_reworded",
        })
    out = os.path.join(ROOT, "translation/segacd_matches.json")
    json.dump(matches, open(out, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print(f"{len(matches)} drafted lines matched vs Sega CD; "
          f"{hi} at/over {threshold} (adopt official), {len(matches)-hi} exclusive/reworded")
    for m in matches[:12]:
        print(f"  [{m['score']}] {m['verdict']}")
        print(f"     draft:  {m['draft_en']}")
        if m["segacd_en"]:
            print(f"     segacd: {m['segacd_en'][:70]}")


if __name__ == "__main__":
    main()
