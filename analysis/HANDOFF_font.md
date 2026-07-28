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
