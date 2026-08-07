# Snatcher: Sega CD → Sega Saturn English

An in-progress fan translation that brings the English localization of Konami's
**Snatcher** (Sega CD, 1994) to the Japanese-only **Sega Saturn** release (1996).

The Saturn version of Snatcher — Hideo Kojima's cyberpunk noir detective adventure —
was never released outside Japan. This project reverse-engineers the Saturn release
and ports an English script to it.

> **Note on scope:** This repository contains only the project's *own* work — tooling,
> reverse-engineering notes, and the English translation data. It contains **no
> copyrighted game data**: no disc images, ROMs, audio, graphics, extracted assets, the
> decompiled game binary, or the original Japanese script. You must supply your own
> legally-obtained Saturn disc; the tools operate on it locally.

## Status

| Area | State |
|------|-------|
| Disc extraction (BIN/CUE → files) | ✅ |
| DATA.BIN archive + custom LZ codec | ✅ cracked (`tools/decompress_chunk.py`) |
| Saturn text encoding | ✅ cracked — u16 tokens `= 0x10100 − SJIS` |
| **Full script translated** | ✅ **12,836 / 12,836 lines (100%)**, all 36 scenes |
| Speaker-name table → English | ✅ (pointer relocation, `tools/patch_speakers.py`) |
| Proof-of-concept English in-game | ✅ renders on hardware-accurate emulation |
| Half-width (SegaCD-style) font | ✅ glyph-cache substitution at font-upload (`asm/full_hook.c`) |
| **Full untruncated English dialogue** | ✅ **in-record paging** — long lines page (press A), nothing dropped |
| Consistent dialogue geometry | ✅ 20/row, 2-row pages, half-width row-0 for no-speaker lines |
| Menu labels (full English) | 🔜 next — copy-buffer decode detaches the blob (truncated for now) |
| English speaker names | 🔜 needs a hang-safe address (not `0x060E71F0`) |
| Voice dub port (from Sega CD) | 🔜 formats identified |
| Packaging (xdelta / SSP patch) | 🔜 |

## How it works

1. **Extract** the Saturn disc's ISO9660 filesystem (`tools/extract_disc.py`).
2. **Decompress** the `DATA.BIN` archive (custom 3-stream LZ; `tools/decompress_chunk.py`).
3. **Extract the script** from scene bytecode (`tools/extract_saturn_script.py`) — text is
   stored as u16 tokens where `stored = 0x10100 − SJIS_code`.
4. **Translate** into `translation/` (source of truth: `translation/master.json`, keyed by
   scene chunk + byte offset). Translations are plain English — font/rendering is applied
   only at build time, so the data is presentation-agnostic.
5. **Validate** every scene (`tools/validate_translation.py`) — key parity, control-code
   integrity, SJIS-encodability.
6. **Build** a patched disc (`tools/build_full_patch.py`) and boot-test in an emulator.

## Layout

- `tools/` — extraction, decompression, script/font/patch tooling.
- `translation/` — the English script (`master.json` + per-scene `chunk_*.json`),
  `GLOSSARY.md` (canonical names/terms), `QA_NOTES.md` (open items).
- `analysis/` — reverse-engineering findings (`findings.md`) and disc manifests.
- `reference/` — SH-2 assembly reference (font/blitting patterns) for the font work.

## Credits

Original game © Konami. This is a non-commercial fan project; no game assets are
distributed here. Built with the help of Claude Code.
