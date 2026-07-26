#!/usr/bin/env python3
"""Build the master translation database — the project's source of truth.

Merges the extracted Japanese script (every scene line, keyed by chunk+offset)
with any English translations dropped in translation/*.json, producing one
authoritative translation/master.json plus a coverage report.

master.json entry:
  { "chunk": "chunk_022", "offset": "0x2a34",
    "jp": "...", "en": "..." | null, "status": "translated"|"untranslated" }

Usage: build_master_db.py
"""

import glob
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRIPT = os.path.join(ROOT, "extracted/script/saturn_script.json")
TR_DIR = os.path.join(ROOT, "translation")
OUT = os.path.join(TR_DIR, "master.json")


def load_overrides():
    """Merge every translation/*.json (except master) into {chunk: {offset: en}}."""
    merged = {}
    for p in sorted(glob.glob(os.path.join(TR_DIR, "*.json"))):
        if os.path.basename(p) == "master.json":
            continue
        data = json.load(open(p, encoding="utf-8"))
        for chunk, lines in data.items():
            merged.setdefault(chunk, {}).update(lines)
    return merged


def main():
    script = json.load(open(SCRIPT, encoding="utf-8"))
    overrides = load_overrides()
    entries = []
    translated = 0
    for chunk, lines in script.items():
        for e in lines:
            off = f"{e['offset']:#06x}" if isinstance(e["offset"], int) else e["offset"]
            en = overrides.get(chunk, {}).get(off)
            if en:
                translated += 1
            entries.append({
                "chunk": chunk,
                "offset": off,
                "jp": e["text"],
                "en": en,
                "status": "translated" if en else "untranslated",
            })
    os.makedirs(TR_DIR, exist_ok=True)
    json.dump(entries, open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=1)

    total = len(entries)
    print(f"master.json: {total} lines, {translated} translated "
          f"({100*translated//max(1,total)}%), {total-translated} remaining")
    # per-scene coverage
    by_chunk = {}
    for e in entries:
        c = by_chunk.setdefault(e["chunk"], [0, 0])
        c[0] += 1
        if e["status"] == "translated":
            c[1] += 1
    done = [c for c, (t, d) in by_chunk.items() if d == t and t > 0]
    started = [c for c, (t, d) in by_chunk.items() if 0 < d < t]
    print(f"scenes complete: {len(done)}, in progress: {len(started)}, "
          f"untouched: {sum(1 for _, (t, d) in by_chunk.items() if d == 0)}")


if __name__ == "__main__":
    main()
