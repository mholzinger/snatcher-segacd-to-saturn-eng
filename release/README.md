# Snatcher (Sega Saturn, Japan) — English Text Patch

## v0.01 — FIRST DRAFT / PROOF OF CONCEPT

This is the **very first draft** of an English text patch for the Japanese
Sega Saturn release of *Snatcher*. It is a proof of concept: the entire in-game
script is translated and playable in English, but with rough edges (see
Limitations). Expect a first-draft experience.

## What it does

- Translates **all 12,641 text lines** — menus, descriptions, and every line of
  dialogue — from Japanese to English.
- Plays through cleanly with **no crashes or hangs**.
- Leaves the **Japanese voice acting** and all audio intact.

## Known limitations (this is v0.01)

- **Long lines are truncated.** English is written into each line's original
  Japanese text slot, and full-width letters use twice the bytes of the original
  characters, so long sentences get cut off mid-word. A half-width font (in
  progress) will fix this.
- **Text is wide / spaced out** (full-width letters). Same font fix will tighten
  it.
- **Speaker name labels stay Japanese** (e.g. the name above the dialogue box).
- Not yet tested on real hardware (EDC/ECC not regenerated). Emulator-verified in
  Mednafen.

## How to apply

You need your own legally-dumped copy of the Japanese Saturn *Snatcher* disc as
a **3-track BIN/CUE** set, and `xdelta3` (https://github.com/jmacd/xdelta).

Only **Track 1** is modified. Tracks 2 and 3 and the `.cue` are unchanged.

1. Confirm your Track 1 matches the expected source (MD5):
   ```
   fd6c0438987fcbc8f520efeed54b37a5   Snatcher (Japan) (Track 1).bin
   ```
2. Apply the patch to Track 1:
   ```
   xdelta3 -d -s "Snatcher (Japan) (Track 1).bin" \
       snatcher-saturn-en-v0.01.xdelta \
       "Snatcher (Japan) (Track 1) [EN].bin"
   ```
3. Replace the original Track 1 with the patched file (keep the same filename the
   `.cue` expects), keep Tracks 2/3 and the `.cue` as-is, and boot the `.cue` in
   a Saturn emulator (Mednafen recommended; needs a Saturn BIOS).

## Legal / distribution

This patch contains **no copyrighted game data** — it is a binary diff that only
works when applied to a disc you already own and dumped yourself. Do not
distribute patched disc images. *Snatcher* is © Konami.

## Project

Reverse-engineering notes, tools, and the translation live at
https://github.com/mholzinger/snatcher-segacd-to-saturn-eng
