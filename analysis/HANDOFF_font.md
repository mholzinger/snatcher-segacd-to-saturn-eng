# Handoff: half-width font (the untruncation project)

## Why the font is the ONLY remaining path to untruncation
- Text is stored as 2-byte full-width SJIS tokens (value = 0x10100 − SJIS). Every
  char = 2 bytes. Long English clips at each record's original byte slot.
- The APPEND path (grow the record, repoint refs) is ABANDONED — confirmed unsafe
  twice in-emulator: a LOOK hang, then garbled text drawn INTO Mika's portrait
  window (a repointed reference drove a sprite, not text). Repointing tracer
  tokens hits non-text refs; the structural guard only checks parse shape.
- => The only safe way to fit more English is FEWER BYTES per char, i.e. a
  half-width (1-byte) text path + 8px glyphs. No repoints, no disc growth.

## Shipping build (done, stable): build/stable_en (tools/build_stable_en.py)
In-place English into every record's original slot; no repoints, no speaker
patch, no disc shift. Full coverage, hang-free, graphics-safe. Long lines
truncate — that's what the font fixes.

## The font hack = THREE parts (all needed for real untruncation)
1. **Engine encoding hook** — the hard part. The VM text reader (FUN_060c08b0,
   and the operand fetcher FUN_060c0c78 that classes leading byte <0x80 as a
   2-byte token) must gain a 1-byte ASCII mode. Options: repurpose a leading-byte
   range as "next byte = one 8px ASCII glyph", or a sentinel that switches the
   reader to 1-byte mode for the rest of the record. SH-2 patch into MAIN_L free
   space + hook the reader.
2. **8px glyphs** — author true 8px-wide 4bpp Latin art (assets/
   halfwidth_ascii_8x16_4bpp.bin exists as a start). The font is NOT verbatim on
   disc (streams via FUN_060b2f8c DMA channels to VRAM 0x25C08000, transformed at
   load — a glyph search over all disc files found nothing). So glyphs go in via
   either (a) reverse the load transform, or (b) an SH-2 routine that overwrites
   Latin glyph slots in VRAM 0x25C08000 AFTER FUN_060b4530's upload.
3. **Render size/pitch** — renderer FUN_060b4970 builds VDP1 sprites at 14px
   pitch, sprite size 0x020E (16w×14h). For half-width: 8px art in the left of the
   cell, size→8w, pitch→8. NOTE the known wall: the VDP1 size field CROPS (not
   scales) — so the art must genuinely be 8px in the left columns.

## FIRST STEP for next session (unblocks everything)
Get a CLEAN dialogue savestate (F5 at any English dialogue screen, no crash) so
the VDP1 command list + resident font give ground-truth render params:
- cell size, exact pitch, glyph source addr per char (parse the VDP1 command
  table at VDP1 VRAM offset 0, 32-byte cmds, LE).
- render the resident font at VRAM 0x8000 (128B/glyph, 16x16 4bpp) to locate the
  Latin glyph slots and confirm format.
Then: prototype the size/pitch edit on ONE line, confirm 8px art renders clean
(defeats the crop wall), then the encoding hook, then re-encode + rebuild.

## Reference
- 8px SH-2 font/draw refs: reference/32x_font_8px_4bpp.s, ~/src/32x-builder.
- SH-2 toolchain via MARSDEV (Docker) in ~/src/32x-builder.
- Renderer FUN_060b4970, font upload FUN_060b4530, DMA FUN_060b2f8c, text reader
  FUN_060c08b0, operand fetcher FUN_060c0c78. Width table 0x060D6A70.


## SESSION PROGRESS (2026-07-27) — injection harness foundation PROVEN
Committed to the targeted-recompile approach (rewrite the text reader + glyph
renderer, not decompile the whole game). Foundation now in place:

- **SH-2 toolchain WORKS**: MARSDEV at /Users/mikeholzinger/src/marsdev/mars
  (sh-elf-as binutils 2.44, sh-elf-gcc 15.2.0). tools/sh2_asm.py wraps it:
  assemble big-endian SH-2 -> link at load addr -> raw .text bytes -> capstone
  verify. Proven: `mov r4,r0; add r5,r0; rts; nop` -> 60 43 30 5c 00 0b 00 09.
- **Safe residency address FOUND: 0x060F006C, 8808 bytes**, zero across all 9
  savestates (diverse scenes) = genuinely free RAM. (The obvious file zero-runs
  like 0x060E71F0 are runtime BUFFERS — that's what made the speaker patch hang;
  the code region 0x060B0000..0x060E0000 is densely packed, no padding.)
- **Reference SH-2 code**: ~/src/32x-builder/srcref/d32xr/sh2_draw4b.s is a 4bpp
  glyph draw routine — direct starting point for the renderer rewrite.

### RESIDENCY PLAN (next build)
Grow MAIN_L.BIN so injected code+glyphs load at 0x060F006C: pad the gap
0x060EF478 (file end) .. 0x060F006C with zeros (engine BSS harmlessly uses that
gap), place code+data at 0x060F006C+. Growing MAIN_L shifts only track-1 files
AFTER it (TRMs/ADPCM/SDAIF) + track 2 -> reuse the proven disc-growth machinery
(fs extent shift + track-2 MSF restamp); DATA.BIN (LBA 96, before MAIN_L) and all
scene chunks are UNAFFECTED. Disc shift itself is safe (test_H/N proved).

### NEXT CONCRETE STEP
1. Build tools/sh2_inject.py: assemble -> place at 0x060F006C via MAIN_L growth
   -> apply hook patch(es) (bsr/bra helpers in sh2_asm.py) -> emit patched disc.
2. FIRST LIVE TEST: hook a harmless spot to run a trivial injected routine that
   makes a VISIBLE change (prove injected code executes in-emulator). Needs one
   boot test.
3. Then: 8px glyph draw (adapt sh2_draw4b.s), then the 1-byte reader mode.


## RENDERER INTERNALS (disassembled this session, ground truth from binary)
FUN_060b4970 (file 0x4970) builds the per-glyph layout table:
- **PITCH constant = `mov #14,r1` at file 0x4A26 (bytes e1 0e), then mul.l r1,r2
  at 0x4A2C** -> X advance = 14 * (charAttr>>2). Change byte at file 0x4A27
  from 0e to 08 for 8px pitch (trivial in-place patch; alone it garbles because
  glyphs are still 16px — needs 8px art too). This IS the pitch edit site.
- Glyph source (0x4A08-0x4A18): addr = charSlot*0x80 + subcell*0x20 + 0x15000,
  then >>3 (8-byte units) into the sprite "source" field. => glyphs at VRAM
  0x25C15000 + slot*0x80 (128B = 16x16 4bpp). subcell = (attr&3), 32B each.
- charAttr = width-table[char] at DAT_060b4a70 = 0x060D6A70 (u16 per char).
- Y coord base DAT_060b4a58; X base DAT_060b4a58 region.

NOTE: this table feeds a VDP1 command builder elsewhere. Confirm vs the DIALOGUE
box specifically with a clean savestate (there may be a second renderer for the
menu/scroller). The 8px art must land in the 0x25C15000 glyph cache (uploaded by
FUN_060b4530 from MAIN_L 0x060E5BE6, len 0x440) or the main font 0x25C08000.

## SESSION STOP POINT
Foundation done: toolchain + sh2_asm.py + safe residency 0x060F006C + pitch edit
site located. TO RESUME: (1) clean dialogue savestate for VDP1 ground truth;
(2) build sh2_inject.py (grow-MAIN_L residency + hook); (3) inject 8px glyphs to
the 0x25C15000 cache + set pitch/size; (4) 1-byte reader mode + re-encode.
Canonical playable build meanwhile: build/stable_en (full English, truncated).


## SESSION 2 CHURN (2026-07-28) — injection payload + font asset READY
Autonomous progress (all byte-verified; boot-test only needed for the hook + slot
mapping, which require a clean dialogue savestate):

- **tools/sh2_inject.py** — injection harness PROVEN. Grows MAIN_L so payload lands
  at RESIDENCY 0x060F006C (gap 0x3F478..0x4006C zero-padded); applies in-place hook
  patches. Self-test passes (payload placed, gap zero, hook applied, disasm OK).
- **asm/glyphblit.s** — SH-2 glyph-blit primitive (VRAM copy loop), assembled +
  verified: `tst r6; copyloop: mov.l @r4+,r0; mov.l r0,@r5; add #4,r5; dt r6; bf` .
  r4=src, r5=VDP1 VRAM dest, r6=longword count. Reusable to push 8px glyphs to
  0x25C08000/0x25C15000.
- **assets/halfwidth_ascii_16cell_4bpp.bin** — the 8x16 half-width font converted
  to 16px-cell layout (128B/glyph, glyph left-aligned so an 8-wide VDP1 sprite
  reads it). 95 glyphs (ASCII 0x20-0x7E), verified legible (A/W/g/y render clean
  with proper ascenders/descenders). Source: assets/halfwidth_ascii_8x16_4bpp.bin.

### STILL SAVESTATE-BLOCKED (the two hooks)
1. GLYPH upload hook — need the live VRAM to learn the on-demand glyph SLOT
   assignment (which VRAM slot each ASCII char uses) before glyphblit can target
   the right slots. Hook after FUN_060b4530 / the on-demand upload path.
2. Pitch/size — byte at file 0x4A27 (0e->08) for 8px pitch; size field to 8-wide.
   (Pitch alone garbles without the 8px glyphs above.)

### 1-BYTE ENCODING (truncation fix, savestate-INDEPENDENT, next deep-RE target)
Text tokens are 2-byte (value=0x10100-SJIS), read by FUN_060c08b0 via the operand
fetcher (leading byte <0x80). A 1-byte token that maps to the SAME full-width SJIS
char fixes truncation WITHOUT needing 8px glyphs (text stays wide but untruncated).
Plan: a mode-switch control code puts the reader in 1-byte mode for the rest of a
record; each 0x20-0x7E byte -> full-width SJIS char in the line buffer 0x060F28AA.
Requires: RE the token->line-buffer emit point, an SH-2 reader hook (inject via
the harness), and a re-encoder. This is the highest-value remaining work and needs
NO savestate — do this next.


## 1-BYTE ENCODING — concrete design (ready to implement + validate)
Reader FUN_060c08b0 (called via PTR_FUN_060c0de8 / PTR_FUN_060c34cc) reads a
2-byte token, returns index = token*2 into char-prop table 0x060FD164, advances
cursor by 2. Token = 0x10100 - SJIS. Valid text-token high bytes are ~0x16-0x7F,
so **0x01 is unused and free to use as a mode sentinel.**

Scheme (record-level ASCII mode):
- Re-encode an English record as: 0x01 (enter ASCII) + ascii bytes (0x20-0x7E) +
  0x00 (record terminator, already the separator). N chars = N+2 bytes vs 2N+term
  for full-width => untruncated in the original slot for most lines.
- Replacement reader (inject at 0x060F006C via sh2_inject; repoint the PTR_* to
  it): keep a 1-byte ASCII-mode flag in the free residency RAM.
    if flag: read 1 byte; if 0x00 -> clear flag + normal terminator path;
             else index = asciiTable[byte-0x20]; cursor+=1; return index.
    else:    read byte0; if 0x01 -> set flag, cursor+=1, tail-call self;
             else the ORIGINAL 2-byte path (verbatim).
  asciiTable[95] maps ascii->index (= (0x10100 - fullwidthSJIS)*2), precomputed,
  stored in the residency data. This renders each ASCII char as its EXISTING
  full-width glyph -> untruncated, still wide (8px font is the separate spacing
  fix). No repoints, no disc-growth of scene chunks.

## DISCIPLINE NOTE (learned this session)
Build small, validate often. Do NOT build the full reader-hook + re-encoder before
a FIRST injection boot test proves injected code runs in-emulator. Sequence:
  1. First injection boot test: inject a trivial routine + one safe visible hook
     (prove the harness executes on hardware/emulator). No savestate needed.
  2. Then the 1-byte reader hook on ONE chunk, validate untruncation on screen.
  3. Then the glyph 8px hook (needs the dialogue savestate for slot mapping).
Each gated by a boot test. build/stable_en stays the shipping build throughout.


## 2026-07-28 — SH-2 INJECTION FOUNDATION PROVEN IN-EMULATOR
End-to-end confirmed: assemble -> inject -> hook -> RUNS, non-destructively, game
plays fully in English. Savestate (669281da) shows code intact at 0x060FF090 and
marker 0x0DEADBEE written at 0x060FF800 => injected SH-2 EXECUTED.

RESIDENCY MAP (hard-won over 3 attempts — the engine memory model):
  * 0x060B0000..0x060EF478  MAIN_L file (loaded, not cleared) BUT data tables here
    are READ; nonzero in the 0x060E71F0 zero-terminated-scan region hangs (also
    killed the speaker patch). Densely packed — no code padding.
  * 0x060EF480..0x060FF090  BSS-clear range (init fn 0x060b002c) — wipes any code.
  * 0x060FF090..0x06100000  ABOVE BSS, ~3952 bytes: NOT cleared, NOT a read table,
    above the low stack (SP=0x06006000). ** THE safe residency. ** Reached via
    MAIN_L growth (+32 sectors; disc shift + track-2 MSF, proven safe).

HOOK MECHANISM: repoint a function-pointer literal (e.g. font-upload ptr at MAIN_L
file 0x1208 = 0x060B4530) to the injected routine; routine does its work then
tail-calls the original via `mov.l orig,r0; jmp @r0; nop` (pr preserved, flow
transparent). Confirmed against 0x060b11bc `mov.l 0x1208,r0; jsr @r0`.

TOOLING: tools/sh2_asm.py (assemble+link+_start assertion), tools/sh2_inject.py
(RESIDENCY=0x060FF090, grow MAIN_L, apply hooks), tools/build_inject_test.py
(disc build with shift). asm/inject_test.s = the proven marker routine.

### NEXT: the 1-byte encoding truncation fix (design already in this doc)
Now unblocked. Text reader FUN_060c08b0 is called via PTR_FUN_060c0de8 /
PTR_FUN_060c34cc / PTR_FUN_060c4b3c. Build the replacement reader (ASCII 1-byte
mode via 0x01 sentinel) at 0x060FF090, repoint those pointers, re-encode English.
Discipline: hook ONE display path, boot-test on one line, before the full corpus.
