#!/usr/bin/env bash
# Regenerate the v0.01 English text patch (xdelta3, Track 1 only).
set -euo pipefail
SRC="iso/Snatcher (Japan) [Saturn]"
VER="${1:-0.01}"
python3 tools/build_stable_en.py
xdelta3 -e -9 -s "$SRC/Snatcher (Japan) (Track 1).bin" \
    "build/stable_en/Snatcher (Japan) (Track 1).bin" \
    "release/snatcher-saturn-en-v${VER}.xdelta"
echo "wrote release/snatcher-saturn-en-v${VER}.xdelta"
