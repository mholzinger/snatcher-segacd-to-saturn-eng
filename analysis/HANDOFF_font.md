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


## 2026-07-28 — TEXT PIPELINE MAP (corrected; avoid the wrong hooks)
Traced the display path to find the RIGHT 1-byte-encoding hook. Corrections:
- **FUN_060c08b0 is NOT the char decoder** — it RESOLVES a display-item <0x80 token
  (a RECORD REFERENCE) to a text-section byte offset (index=token*2, odd-start
  adjust via text base at 0x060FD164). Hooking it for 1-byte encoding = WRONG,
  would break all text. (Called via PTR_FUN_060c0de8/34cc/4b3c.)
- **emit FUN_060c31a0** takes that resolved offset, computes record_addr =
  text_base(*0x060FD164) + index, and QUEUES the record (into a list indexed by a
  counter *0x060FD0C0) for rendering. Its callees FUN_060dbc80 / FUN_060dbef8 are
  generic **strcpy / strlen** (byte copy/len of the record) — staging, not decode.
- So the pipeline is: display token (record ref) -> reader RESOLVE -> emit QUEUE
  -> [stage record bytes] -> renderer reads staged record -> glyphs. The
  0x10100-SJIS -> SJIS decode + glyph mapping is DOWNSTREAM (renderer/decode), not
  in the reader/emit.

### => 1-byte hook target is the RECORD-CONTENT decoder (still to pinpoint)
Needs a live dialogue savestate to trace which routine reads a queued record's
2-byte tokens and produces the line-buffer SJIS (line buf 0x060F28AA, 4B cells
[SJIS hi][SJIS lo][color][00]). Hook THAT to read 1-byte ASCII (0x01 sentinel ->
ascii run) instead of 2-byte tokens. The injection foundation (0x060FF090 + hook)
is ready to host it. DO NOT hook FUN_060c08b0.

STATE: injection foundation PROVEN. 1-byte encoding = next dedicated RE session
(trace the record decoder with a savestate), then the reader hook + re-encode.
Shipping build remains build/stable_en (v0.01 patch published).


## 2026-07-28 — TRUNCATION FIXED IN-EMULATOR (1-byte encoding + injected decoder)
CONFIRMED on screen: the JunkerHQ greeting shows BOTH full lines
"Welcome to JUNKER HQ." AND "May I help you?" — the second line was truncated in
EVERY prior build. Untruncated English achieved via engine injection, zero
disc-content corruption (no repoints/reference surgery — the thing that broke the
append path). Pipeline:
  * asm/decoder_hook.c: ASCII-aware replacement for the record decoder FUN_060c4d24,
    compiled with sh-elf-gcc, injected at 0x060FF090; all 7 decoder pointers
    repointed. 0x01 = enter ASCII (bytes 0x20-0x7E -> full-width SJIS), 0x02 =
    exit; outside ASCII = original byte-negate. Superset of the original ->
    transparent for un-encoded text (validated first).
  * tools/build_decoder_hook.py encode_1byte(): ASCII runs -> 0x01<ascii>0x02;
    <br>/＠color/kanji -> negated SJIS tokens. ~2x text per original slot.
  * Disc = stable_en text (now 1-byte encoded) + injected decoder (MAIN_L grow
    above BSS 0x060FF090 + shift + track-2 MSF). No repoints of scene refs.
build/decoder_hook is the untruncated build. REMAINING: wide full-width spacing
(the 8px half-width glyph polish — separate, needs the VRAM slot mapping). The
CORE truncation complaint is resolved. This is the basis for v0.02.


## 2026-07-28 (session cont.) — OVERFLOW ROOT CAUSE + THE REAL CAPACITY PROBLEM
In-emulator, build/decoder_hook hit TWO failures on longer content:
  * Asking Mika about JUNKER: garbled text drawn INTO her portrait window, THEN the
    "Go Inside" scene transition HANGS the CD forever (text interactions before it
    still worked — they read already-loaded chunk RAM; the transition CD-load uses
    corrupted pointers).
Both are ONE bug: **text-window buffer OVERFLOW.**

### GROUND TRUTH from savestate 669281da (the JUNKER screen, decompressed + WRAMH read)
- Line buffer 0x060F28AA, 4B cells [SJIS hi][SJIS lo][color][00], 0x889E = padding.
- **Window = fixed 80-cell buffer; ROWS ARE 20 full-width chars wide** (verified:
  "JUNKER is a special " is exactly cells 20-39; speaker "ミカ" occupies row 0,
  cells 0-1). Text word-wraps at 20; <br> pads to end-of-row.
- The JUNKER record rendered correctly THROUGH cell 83 ("...destroy the"), then
  cell 84+ = garbage (0x0001/0x0000) = the overflow corruption, caught mid-crash.
  So usable capacity ≈ 80-84 cells (~4 rows), speaker row included.
- Savestate mining recipe (WORKS): .mc0 is GZIP; decompress; sections are
  `[len:1]["Name"][size:u32LE][data]`. WorkRAMH @name 0x43447c (swap16 to normalize
  SH-2 BE). VDP2 VRAM @0x1b18ae (512KB), VDP2 RawRegs @0x1b1561 (0x200).
  tmp extractor left at $CLAUDE_JOB_DIR/tmp/state0.raw.

### THE REAL PROBLEM (measured across full corpus, proper 20-col layout sim)
English is ~2x more VERBOSE (cells) than Japanese. **Median translated record = 80
laid-out cells = AT the window limit. 30-50% of records in EVERY chunk overflow**
(not just info-dumps). 75th pct = 100 cells, 90th = 120, worst = 206. This is why
the crash is pervasive once you reach substantive lines.
  * There is NO in-stream page-break control code (pages = individual records; the
    engine shows a record, waits, advances). So pagination is NOT available.

### KEY CORRECTION: half-width RENDERING alone does NOT fix overflow
The 80-cell buffer counts CHARACTERS (1 cell/char), not pixels. Rendering glyphs at
8px (pitch edit 0x4A27 0e->08) makes text tighter/less wrap-padding but does NOT
reduce the character count that overflows the buffer. To fix the crash you must
reduce CELL COUNT = **PACK 2 letters into 1 cell** (1 buffer entry, 1 VDP1 sprite,
whose cache glyph is a 2-letter COMPOSITE). Then 73 chars -> 37 cells << 80. Renderer
FUN_060b4970 is bounded at 80 cells and draws each cell as one 16x16 sprite from
cache slot 0x25C15000+slot*0x80 — so a composite glyph per packed cell "just works"
in the renderer; the work is the GLYPH COMPOSER.

### DECISION (user, with corrected numbers): HALF-WIDTH PACKING, prove-first
Rejected: condensing ~4000 lines terser (guts the translation's voice across half
the game). Chosen: pack 2 half-width 8x16 glyphs per 16x16 cell -> verbose English
fits as-is, written once. PROVE packing renders before building the full pipeline.

### NEXT (the proof, then the pipeline)
1. GLYPH COMPOSER is the hook + the last unknown. Font source still not located on
   disc (streams via DMA FUN_060b2f8c to VRAM, transformed at load). Use the NOW-
   AVAILABLE savestate VRAM (vdp1_vram.bin @0x25C15000 cache; state0.raw) to map the
   on-demand glyph SLOT assignment: which cache slot each cell's glyph uses, and the
   routine that uploads it (hook after FUN_060b4530 / the on-demand path).
2. Decoder emits PACKED cells (2 ascii bytes -> 1 cell code); compose-hook builds the
   16x16 pair tile (left 8px = glyphA, right 8px = glyphB) into that cell's slot.
   Only ~40 visible cells/screen -> compose on demand is cheap.
3. PROOF DISC: render "JUNKERjunker" packed 2/cell in an early record; user boots,
   confirms tight 2-per-cell packing. THEN build the full re-encoder + integrate.
Assets ready: assets/halfwidth_ascii_16cell_4bpp.bin (95 glyphs, 8px left-aligned),
asm/glyphblit.s. Injection harness proven (RESIDENCY 0x060FF090).
build/decoder_hook (full-width, untruncated but OVERFLOWS long records) stays the
current build; it is NOT crash-safe on long lines — do not ship as-is.


## 2026-07-29 — OVERFLOW STABILITY FIX SHIPPED (option 2), CONFIRMED IN-EMULATOR
User chose stability-over-completeness (packing shelved as intractable: the glyph
cache/font format would not crack from crashed/static savestates — needs a live
debugger). Root cause nailed: fill routine FUN_060b45c4 auto-wraps at col 20
(param_1==0x14) but ONLY the ¥-break path guards row 4 (param_2==4 -> page handler
FUN_060b4698); the AUTO-WRAP path has no row guard, so English lines >20 chars
auto-wrap past the 80-cell buffer into scene state -> garble + Go-Inside hang.

FIX (pure data, tools/layout_clamp.py -> build_decoder_hook.py):
  clamp_text() re-wraps every record to <=20-char lines and caps at MAX_ROWS=3
  (safe for dialogue starting at row 1 -> rows 1..3 = cells 20..79). No auto-wrap
  can occur; nothing writes past cell 79. 0/12641 records exceed 3 rows after clamp.
CONFIRMED on screen (savestate 0): asking Mika about JUNKER now renders 3 clean
lines, Mika's PORTRAIT IS INTACT (no garble), and "Go Inside" TRANSITIONS (no hang).
Also fixed asm/ascii_sjis.h: ' " - ~ were mapped to blank (0x8140); now ’(0x8166)
”(0x8168) ―(0x815d) 〜(0x8160) so contractions/hyphens render.

build/overflow_fix = the STABLE build: untruncated short/medium text, long records
CLIP at 3 lines (accepted tradeoff), zero crashes. THIS is the v0.02 basis.
No realistic path to full verbose English without the glyph-packing hack (shelved).


## 2026-07-29 — SCROLLING TEXT (fill-routine patch) + GLYPH-PIXEL CONTROL PROVEN
Two big wins this session:

1. SCROLLING: patched fill routine FUN_060b45c4 so the ¥-break path scrolls for ANY
   row>=4 (not just ==4). 2-opcode in-place patch: file 0x4660 cmp/eq #4,r0 (8804)
   -> tst #0xFC,r0 (c8fc); 0x4666 bf/s (8f07) -> bt/s (8d07). In the scroll path the
   write goes to a FIXED bottom-row base (DAT_060b4680) so param_2 growing can't
   overflow. Text re-wrapped to <=19 cols (clamp_text row=19, max_rows=None) so the
   un-patched auto-wrap (col 14/20) never fires; only the now-safe ¥ path is used.
   The scroll routine FUN_060b4730 (=PTR_FUN_060b4698) copies 3 rows up + writes the
   continuation. The fill routine IS the typewriter (calls frame-sync FUN_060b55a0
   =PTR_FUN_060b472c per char), so scrolling happens live while typing -> READABLE.
   CONFIRMED in-emulator: long passages scroll through, natural width, color+portrait
   intact. build/scroll_test (SCROLL=1 SCROLL_WIDTH=19). Also added 1-byte line-break
   0x03 to the decoder (asm/decoder_hook.c) + encoder -> saves ~3 bytes/line, recovers
   byte-slot cutoffs. Remaining cutoff = each record's DISC BYTE SLOT (~9 bytes short
   for 69% of records -> partial last word); only record-growth fully fixes that.

2. GLYPH-PIXEL CONTROL PROVEN (un-shelves the font/packing work!): the de-risk probe
   asm/vram_fill.s (hooked at frame-sync ptr 0x472c via build_inject_test.py with
   PROBE_ASM/PROBE_HOOK env) fills VDP1 VRAM 0x25C08000..+0x4000 every frame. RESULT:
   the DIALOGUE TEXT WINDOW garbled to stripes while the speaker name (受付嬢) and the
   picture stayed intact. => the dialogue glyph SOURCE is at VDP1 VRAM 0x8000 (SH-2
   view 0x25C08000) and injected code CONTROLS those pixels. This is exactly what was
   missing before (couldn't locate/write the font). The renderer FUN_060b4970 draws
   per-cell 16x16 glyphs; the source at 0x8000 feeds the cache at 0x15000. Speaker font
   is elsewhere (>0xC000, unaffected by the 0x8000..0xC000 fill).

### NEXT: write PROPER glyphs at 0x8000 -> half-width font + glyph packing
Green-lit. Steps: (1) map which 0x8000 offset each Latin SJIS code uses (render the
region from a clean savestate, find ＡＢＣ, derive SJIS->offset). (2) upload proper
8px half-width glyphs there (asset assets/halfwidth_ascii_16cell_4bpp.bin) via an
injected routine hooked after font upload. (3) optionally compose 2 half-width glyphs
per 16x16 cell (packing) so verbose English fits. This is the path to fully readable
English via the glyph route. Full free-form bitmap overlay would ALSO need sprite-
position control (VDP1 command coords) — a further step, not needed for proper-font.
STABLE fallback throughout: build/overflow_fix (3-row clamp, zero crashes).

## 2026-07-29 — CUSTOM FONT RENDERING PROVEN ON SCREEN (the wall is broken)
GLYPH MAPPING CONFIRMED + CUSTOM GLYPHS RENDER CLEAN. The dialogue glyph cache is a
DYNAMIC, per-screen cache at VDP1 VRAM 0x25C08000, indexed by SJIS LOW BYTE:
  glyph for SJIS code C  ->  VDP1 VRAM 0x25C08000 + (C & 0xFF)*0x80   (0x80 = 16x16 4bpp)
(That's why static dumps kept showing kanji — a given scene's cache holds only that
scene's glyphs. The renderer FUN_060b4970's 0x15000 formula is a DIFFERENT text mode.)
Format is PLAIN 4bpp; letter pixels use palette index 0xF (renders white/visible).

PROVEN in-emulator (build/font_write, asm/font_write.s): a per-frame routine (hooked
at frame-sync ptr 0x472c) copies 26 half-width uppercase glyphs (assets/hw_upper.bin,
A-Z) to slots 0x60-0x79 (0x25C0B000). The greeting rendered "Welcome to JUNKER HQ."
with the UPPERCASE letters as our CLEAN half-width glyphs. => injected code writes
proper, correct, custom text glyphs. The whole bitmap/font-renderer approach is real.

### REMAINING (all engineering, no unknowns)
1. FULL FONT: only A-Z fit the 4KB residency this pass. Store all 95 glyphs as 1bpp
   (~3KB, font is 2-color) and expand to 4bpp on write -> full upper/lower/digits/punct.
   Slot for ascii ch = ascii_sjis[ch-0x20] & 0xFF (table in asm/ascii_sjis.h).
2. TIGHT SPACING: glyphs are 8px in 16px cells (crisp but gappy). Closing gaps = the
   PACKING step (2 half-width glyphs composed into one 16x16 cell; decoder emits pair
   codes). All pieces now exist.
3. COLLISION REFINEMENT: slots shared by SJIS low byte -> only override Latin ranges,
   or hook the glyph-upload path to substitute by SJIS. Fine for English-heavy screens
   already; kanji collisions rare.
KEY ASSETS/TOOLS: asm/font_write.s (per-frame glyph writer), assets/hw_upper.bin,
assets/halfwidth_ascii_16cell_4bpp.bin (95 glyphs), build_inject_test.py (PROBE_ASM/
PROBE_HOOK env). Stable fallback: build/overflow_fix. Best readable: build/scroll_test.

## 2026-07-29 — HORIZONTAL KERNING (X-PITCH) CRACKED
The dialogue X-grid is STATIC DATA: table at MAIN_L file 0x35358 (RAM 0x060e5358),
80 entries x 12 bytes (6 shorts). short[4] (byte +8 of each entry) = the per-cell X
coordinate = 0x13 + (col%20)*14, static (FUN_060b4970 only overwrites short[2]=glyph
and short[3]=14*(attr>>2); it does NOT touch short[4]). 20 cells/row, X resets at
col 20. => halve the kerning by rewriting short[4] to 0x13 + (col%20)*PITCH.
build_inject_test.py now supports env PITCH=N (rewrites all 80 short[4]) and
EXTRA_HOOK="off:hex;..." (in-place byte patches). CONFIRMED in-emulator (build/pitch8,
PITCH=8 + uppercase font): text visibly TIGHTENED (JUNKER/HQ close together).
CAVEAT — at PITCH=8 the text currently MANGLES/overlaps because (a) only uppercase is
our 8px font; lowercase are still 16px full-width -> heavy overlap; (b) the sprite is
likely still 16px wide so even 8px glyphs may overlap unless the right half is truly
transparent or the sprite width (CMDSIZE) is trimmed to 8. DO NOT patch the '14' inside
FUN_060b4970 (file 0x4A27) — that's short[3], glyph-addr related, corrupts content.

### NEXT (culminating build): full 8px font + PITCH=8 (+ maybe sprite-width trim)
Store all 95 glyphs 1bpp (~3KB), expand 1bpp->4bpp on write (nibble LUT), write each
to slot = ascii_sjis[ch-0x20]&0xFF (base 0x25C08000). Combine with PITCH=8. If 8px
glyphs still overlap, find CMDSIZE (VDP1 sprite width) in the command template
(file 0x4950 region) and set X-size to 8px. That yields clean, tight, readable English.

## 2026-07-29 late — FULL FONT + PITCH built; TIGHT but OVERLAPPING (need sprite width)
DONE: asm/font_full.c (compiled C via build_inject_test compile_c(); writes all 95
half-width glyphs, stored 1bpp in slots.h/font1bpp.h [priority order: letters last so
they win the SJIS-low-byte collisions], expanded 1bpp->4bpp per frame to
0x25C08000+slot*0x80). build/fulltight = full font + PITCH=8. Tools: build_inject_test
now compiles .c payloads (compile_c) and supports env PITCH=N and EXTRA_HOOK.
RESULT in-emulator: text is TIGHT (pitch works) but LETTERS OVERLAP ("Welcome to JUNKER
HQ" -> "Velccrre tc .LNKEF HQ"). ROOT CAUSE: each glyph is 8px content inside a 16px-
wide sprite; at 8px pitch the sprite's right half covers the next glyph. NO pitch value
fixes this with 16px sprites — the SPRITE must be 8px wide (CMDSIZE) or its right half
made transparent (CMDPMOD index-0 transparency). The sprite table @0x060e5358 (12-byte
entries: [0]=4800,[1]=100e,[2]=glyph(dyn),[3]=Y(dyn),[4]=X(static,pitch),[5]=009e) does
NOT parse as standard 32-byte VDP1 commands, so where CMDSIZE/CMDPMOD live is UNSOLVED.
KNOWN COLLISIONS (letters win): apostrophe->G (0x66), "->I, (->J, )->K, etc. — fully
clean punctuation needs unique per-char slot assignment (encoder change).

### FINISH-LINE STEP (next session): trim sprite width to 8px OR enable index-0
transparency. Options to find it: parse the VDP1 command list in VRAM (offset 0) from a
clean savestate to read the text sprites' actual CMDSIZE/CMDPMOD and trace who writes
them; or examine the routine that consumes table 0x060e5358 and builds VDP1 commands
(find via how 0x060e5358 is DMA'd/read — not by symbol, it's computed). Once 8px-wide:
clean tight readable English (the goal). Meanwhile readable-but-wide = build/scroll_test.
