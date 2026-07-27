# Snatcher SegaCD→Saturn — Analysis Findings

Status date: 2026-07-26 (Phase 1 complete)

## Disc layouts (verified by extraction)

### Sega CD (USA) — 21 tracks, 100 files
- Track 01 MODE1/2352 (data, 56014 sectors); Tracks 02–21 Red Book audio = **the English dub/music source**, ripped to `extracted/segacd/audio/track*.wav`.
- Script files: `SP01.BIN`–`SP38.BIN` (~15–52 KB each) — English text, documented format (text base 0x3800; girianshido patcher). Verified: "Welcome to Junker" ASCII present.
- `SUBCODE.BIN` — character/speaker ID data.
- `DATA_*.BIN` — graphics/scene data by act/area.

### Saturn (Japan) — 3 tracks, 226 files
- Track 1 MODE1/2352 (main data), Track 2 MODE2/2352 (streaming), Track 3 audio.
- `A.BIN` — boot/loader (SH-2). References `MAIN_L.BIN`, `LOGO.TRM`, `MX0.TRM`, `MX1.TRM`, `PLAYALL.AVI`, `PLAYONCE.AVI`; embeds 68000 SCSP sound-driver code and version string `Ver1.31 95/06/20 SATURN(S)`.
- `MAIN_L.BIN` (259 KB) — **main game engine (SH-2)**. References `DATA.BIN`; debug string "save old scene is 0!". Primary Ghidra target.
- `DATA.BIN` (10.9 MB) — high-entropy archive; **prime suspect for compressed script + graphics** (no plain SJIS found anywhere on disc).
- `ADPCM_00–1E,XX.CAT` (21 files, ~50–60 KB each) — voice data. **Despite the name, statistical analysis says raw signed 8-bit PCM, not ADPCM** (72% of adjacent deltas ≤4; zero-crossing rate 0.102 ≈ speech). No header — index/lengths must live elsewhere (DATA.BIN or engine). Listen: `scratch/adpcm00_as_pcm8_*.wav` (8/11/16/22 kHz candidates).
- `SDAIF_*.AIF` (~90 files, up to 25 MB) — **standard AIFF**, 16-bit stereo PCM (~24 kHz?). Bulk of streamed audio (music/long voice?). Trivial to decode/re-encode.
- `BGM_*.CAT` — sequenced music + `SDDRVS6.TSK` (sound driver task), `SE_XX.BIN/CNV` sound effects.
- `LOGO.TRM`, `MX0.TRM`, `MX1.TRM` (3.3/15/15 MB) — movie files (Cinepak-era "film" middleware per A.BIN strings).
- `ACT1.CAT` (9.9 MB), `ACT2.CAT` (17 MB), `ACT3.CAT` (23 MB) — on track 2; per-act streaming containers.
- `WARNING.DA` — Red Book-adjacent audio on track 3.

## Cross-version mapping
File naming is completely different between versions — no shared `SP*.BIN` on Saturn. The Saturn script is packed/compressed (likely in `DATA.BIN`, possibly per-scene inside ACT*.CAT). Mapping must be rebuilt via engine RE, not file diffing.

## Revised risk picture
1. ~~ADPCM format unknown~~ → **downgraded**: voice appears to be raw 8-bit PCM (confirm by ear + Ghidra on the SCSP driver/engine). Re-encoding SegaCD English dub = resample to 8-bit PCM at the right rate. Remaining unknown: clip index/boundary table location.
2. **New top risk**: locating + decoding the Saturn script (compressed in DATA.BIN?). Ghidra work on MAIN_L.BIN's DATA.BIN loader is the critical path.
3. AIFF files huge & plentiful — which dialogue is AIFF-streamed vs PCM-clip? Need engine RE to see the routing.

## Next actions (Phase 2/3)
1. SegaCD: write `tools/extract_script.py` for SP*.BIN → structured English script dump.
2. Saturn: Ghidra project on `MAIN_L.BIN` (SH-2 BE); trace DATA.BIN load + decompression; find script decoder and ADPCM clip table.
3. Confirm voice PCM by listening to `scratch/adpcm00_as_pcm8_*.wav` (pick rate).

## Phase 3 progress (2026-07-26, session 1)

- Saturn disc header: product `T-9508G`, mastered 1995-02-13. Boot file `A.BIN` loads at 0x06010000 (IP dumped to `extracted/saturn/ip.bin`).
- **`MAIN_L.BIN` load base = 0x060B0000** (verified: direct literal refs to "DATA.BIN" @+0x22A8 and "save old scene" @+0x20BC; 4,340 self-consistent pointers).
- Ghidra project `ghidra/snatcher-saturn` (SuperH:BE:32:SH-2, BinaryLoader @0x060b0000): 961 functions. Full decompilation: `analysis/ghidra_out/MAIN_L_all.c`.
- **DATA.BIN archive format cracked**: index table at 0x060E62F4 (639 entries of u16 pairs: start sector ×2048, size in 16-bit words). Chunks extracted to `extracted/saturn/data_bin/`. Loader fn FUN_060b22b4 (opens "DATA.BIN"), scene loader FUN_060b2624.
- Chunks are **compressed** (entropy 7.1–7.5 b/B). Most start with u32 BE (decompressed size?). Standard LZSS variants brute-forced: no match — custom codec. Decompressor not yet located.
- **Script VM found**: FUN_060c0c78 is the bytecode operand fetcher (opcode class tests on 0x80/0xE0/0xF0 bits, 12-bit operands). This is the interpreter that will render text — key patch target later.

### Next (Phase 3, session 2)
1. Find decompressor: trace what code consumes a freshly-loaded DATA.BIN chunk (follow FUN_060b2624's read-completion path / PTR_FUN_060b2784).
2. Decompress chunk → confirm SJIS script inside.
3. ADPCM clip index: find table mapping voice IDs → offsets in ADPCM_*.CAT.

## Phase 3 progress (2026-07-26, session 2)

- **Voice format CONFIRMED by ear (user)**: ADPCM_*.CAT = raw signed 8-bit PCM @ ~22050 Hz mono. English dub insertion = resample/quantize, no codec work.
- **DATA.BIN compression CRACKED**: custom three-stream LZ. Decompressor at FUN_060cb548, header parser FUN_060cb6fc. Format + working decoder in `tools/decompress_chunk.py`:
  header {u32 out_size; u16 bitstream_u32s; u16 tokenstream_u16s}, streams: bit flags (BE u32, LSB-first), u16 match tokens, literal bytes.
  Flags: 0=literal; 1,1=short match (dist=byte+1, len=2bits+2); 1,0=token (t==0 end; t&0xF: len=(t&0xF)+2 dist=(t>>4)+1; else len=byte, dist=t>>4).
- 561/639 chunks decompress cleanly (`extracted/saturn/data_bin_dec/`); 78 appear to be raw/other-format (no size header).
- **Text is NOT SJIS** even after decompression — custom encoding, almost certainly font-glyph indices. Next: locate font glyphs + the script VM's text-draw opcode handler (start from FUN_060c0c78 dispatch), derive the index→glyph mapping.
- Decompressor state block at 0x060FEAEC..0x060FEB10 (BSS); orchestrator FUN_060cb1a8; init FUN_060cb6fc(src, dst).

### Next (session 3)
1. Trace text-draw opcode in script VM → find font base + index encoding.
2. Look for font bitmap in decompressed chunks / MAIN_L.BIN tail / chunk 0.
3. Then: ADPCM clip boundary table (voice IDs → offsets), CD-DA↔scene map (Phase 2 leftover).

## Script alignment strategy (added 2026-07-26)
Once glyph indices → JP text is solved, alignment of JP↔EN lines is automated:
1. Glyph→char table: kana/punct by hand; kanji via OCR or SJIS-ordered font (check first — free if so).
2. Machine-translate each JP line (API: Google/DeepL/Claude) — used ONLY as an alignment key, never shipped.
3. Fuzzy-match rough EN vs the 10,728-string SegaCD dump + structural signals (scene order, speaker ID, menu structure).
4. Human review of low-confidence matches. Saturn-exclusive lines: MT draft + human polish → subtitles.

## Phase 3 progress (2026-07-26, session 3) — text renderer located

- **Text renderer: FUN_060b4970** (MAIN_L.BIN). Per-frame line layout, up to 0x50 (80) chars.
  - Text buffer: 0x060F28AA (BSS), 4 bytes per char cell.
  - Per-char u16 attribute/width table (proportional font): **0x060D6A70** (static, file off 0x26A70). Layout: bits0-1 sub-cell, upper bits width class ((attr>>2)*14 used in advance calc).
  - Glyphs: **16x16 4bpp, 128 bytes each**, addressed `(attr&3)*0x20 + slot*0x80 + 0x15000` in VDP1 VRAM = dynamic glyph cache at **0x25C15000** (uploaded on demand; slot byte lives in the text cell).
- Font *bitmap source* not yet located (static candidates at 0x35be6 and MAIN_L tail rendered as noise; likely another indirection or stored compressed).
- **Shortcut chosen: emulator save state.** Mednafen boots the game (Hi-Saturn BIOS, persisted in ~/.mednafen/mednafen.cfg). A save state taken at any text screen contains VDP1 VRAM (arranged glyphs) + work RAM (decompressed script + live text buffer w/ codes) → code→glyph→char mapping falls out by correlation.
- Mednafen state files: ~/.mednafen/mcs/*.mcs (F5 saves).

### Waiting on user
Run `mednafen "iso/Snatcher (Japan) [Saturn]/Snatcher (Japan).cue"`, play to any Japanese text, press F5.

## Phase 3 progress (2026-07-26, session 4) — save-state mining

Save state: `~/.mednafen/mcs/Snatcher (Japan).c9ea599588701cffc7848c24b027de78.mc0`
(gzip; captured at JunkerHQ menu with text on screen). Extraction recipe:
- gunzip → sections are `len_byte name size_u32LE data`.
- `WorkRAMH` @0x43447b (data @0x434488, 1MB, 16-bit LE byteswapped vs SH-2 BE view → swap16 to normalize). Verified MAIN_L.BIN image intact at +0xB0000. Saved: `analysis/wramh.bin` (normalized).
- VDP1 `VRAM` @0xb0a61 (data @0xb0a6a, 512KB). u16 fields little-endian in native state order. Saved: `analysis/vdp1_vram.bin` (swap16'd — NOTE glyph pixels read correctly from NATIVE order, so un-swap when rendering).
- **FULL KANJI FONT found resident in VDP1 VRAM ~0x8000+** (16x16 4bpp, 128B/glyph, hundreds+ of glyphs; renders as clean readable kanji from native byte order). See `scratch/font_hunt/vram_band_noswap.png`.
- Font bytes do NOT appear verbatim in any disc file/chunk (4bpp, 1bpp-threshold, byteswap variants all searched) → generated/expanded at upload time; on-disc source still unidentified.
- VDP1 command list parse (LE): 1044 cmds, menu text NOT drawn as per-glyph VDP1 sprites → **text is composed on a VDP2 layer** (or pre-rendered to a bitmap). 
- Earlier-identified FUN_060b4970 (slot*0x80+0x15000 glyph cache) serves some other text mode (scroller?); menu path differs.

### Next (session 5)
1. Dump VDP2 VRAM + pattern-name tables from the state; find the tilemap showing the menu text; tiles → glyph indexes → correlate with WRAM script codes (search WRAMH for plausible u16 code arrays near 0x060F2xxx).
2. Alternative static path: enumerate literals 0x25C00000-0x25C7FFFF in MAIN_L to find the big font upload routine and its source pointer chain.
3. Once code→glyph order known: check if order is JIS/SJIS-derived (would give char mapping for free).

## Phase 3 progress (2026-07-26, session 5) — TEXT PIPELINE CRACKED (dialogue state)

State 2 (Gillian/Mika dialogue at JunkerHQ reception). Extraction: WorkRAML section also present (`len_byte "WorkRAML" size_u32LE data`; swap16 like WRAMH).

- **Text line buffer 0x060F28AA = live SJIS!** Cell = 4 bytes: [SJIS hi][SJIS lo][color][00]. Read directly: speaker 「キリアン」(color 4), dialogue 「じゃあ、俺の事教えれば許してくれる？」(color 7). Padding char 0x889E.
- **Scene script block found in WorkRAML @ 0x002F8000** (VM sees it via cache-through 0x202F8000): plain SJIS strings, null-terminated, each preceded by 8-byte header (two u32s: id?, len?) and followed by 4-byte refs like `1c 0b 04 58` (monotonically increasing → likely voice-clip/stream offsets). Full Mika reception conversation readable.
- **VM cursor vars: IP holder @0x060FC8B0, script base holder @0x060FB460** (resolved via FUN_060c0c78 literals DAT_060c0de0/de4). Bytecode uses u16 script-relative offsets; `c0 01 a0 05 XXXX` patterns = command+text-offset refs.
- **The script block does NOT exist verbatim anywhere on disc** (searched raw track BINs, all files, all decompressed chunks). → There is a **second decompressor** (likely Huffman; the 78 non-LZ DATA.BIN chunks have entropy ~6.1-7.4 b/B and are prime suspects). NOT yet located in code (FUN_060cb1a8 turned out to be unrelated game logic).
- Bonus for Phase 4: the font includes full-width Latin (ＪＵＮＫＥＲ renders in dialogue), so an early English proof-of-concept could encode English as full-width SJIS letters *before* any renderer hack.

### Next (session 6)
1. Find decompressor #2: trace who fills 0x002F8000 (search literals for 0x002F8000/0x202F8000 in MAIN_L; follow the scene-load path); or diff a raw chunk against the RAM script block.
2. Confirm the 4-byte per-line refs = voice clips (correlate with ADPCM_*.CAT / ACT stream offsets).
3. Extract full script per scene once codec #2 is cracked.

## Phase 3 progress (2026-07-26, session 6) — scene bytecode + voice routing

- **DATA.BIN chunks 21–98 = per-scene VM bytecode, stored RAW** (not LZ). Proof: chunk_022 matches the live JunkerHQ script in RAM (168/191 24-byte slices; diffs = runtime patching). One chunk per scene/area.
- **Area text bank** (RAM ~0x0024798C, both states): full JunkerHQ script as SJIS records. Control codes: `￥`(0x818F)=line break, `＠赤`/`＠白`=color tags. Per-line 4-byte refs (`1c 0b 04 58`, increasing) = voice cue refs.
- Text bank does NOT exist on disc in SJIS, in LZ form (deep-scanned DATA.BIN, ACT*.CAT, MX*.TRM, LOGO.TRM, raw tracks), and kanji like 俺/事/教/許 do NOT appear in MAIN_L.BIN → no static charmap. Hypothesis: text is encoded inside the bytecode chunks (12-bit VM tokens?) and expanded at scene load. NEXT: find the writer of the 0x247xxx bank (candidates: FUN_060e4a7c — has 0x240000/0x250000/0x260000 literals; also FUN_060b10cc/FUN_060b6f20/FUN_060b918c touch staging 0x20248000).
- **Voice routing solved at the format level**:
  - `ADPCM_*.CAT` = raw 8-bit PCM 22050 (system/short voices) — trivial to replace.
  - **Dialogue voice = Konami-custom ADPCM inside ACT1/2/3.CAT** (track 2, Mode2 Form2 DATA sectors — submode 0x28, NOT CD-XA audio, coding=0). Sound driver (68K: SDDRVS6.TSK + driver embedded in A.BIN, 'Ver1.31 95/06/20 SATURN(S)') decodes to PCM in sound RAM (mid-playback state proved no byte-identity with disc). → Dub patch requires REing the 68K driver's ADPCM decode, then writing an encoder for the English audio.
- Save-state recipe addition: SCSP SoundRAM section = name `RAM` (len 3), size 0x80000, swap16.

### Next (session 7)
1. Ghidra 68000 project on SDDRVS6.TSK (+ A.BIN embedded driver): identify ADPCM decode loop → derive encoder.
2. Trace text-bank writer (FUN_060e4a7c first) → crack text encoding in bytecode chunks.
3. Then Phase 3 exit criteria: script extraction tool + voice clip map.

## Phase 3 progress (2026-07-26, session 7) — **SATURN TEXT ENCODING CRACKED**

- **Encoding: stored_u16 = 0x10100 − SJIS** (engine decodes with negate+add — why plain scans failed).
  Cracked via ＪＵＮＫＥＲ token arithmetic in chunk_022 (`7e97..` ↔ `8269..`, constant sum 0x10100).
- Text lives interleaved in the scene bytecode chunks (21–98), u16 BE tokens; in-text controls: ￥=line break, ＠色=color (＠白/＠赤/＠水…).
- `tools/extract_saturn_script.py` → **12,259 strings from 36 scene chunks** (`extracted/script/saturn_script.json`). Chunks 63+ carry no text (u16 index tables/other data).
- Corpus sizes: Saturn 12,259 JP vs SegaCD 10,728 EN — consistent with Saturn's added scenes.
- MX0/MX1/LOGO.TRM identified: RIFF AVI, Duck TrueMotion video + '01wb' 16-bit PCM audio = FMV cutscenes (dub swap for FMVs = replace AVI audio stream! Standard tooling applies).

### Phase 3 remaining
1. Voice ADPCM in ACT*.CAT: RE the 68K sound driver (SDDRVS6.TSK) → decoder + encoder.
2. Text record fine-structure (speaker/voice-ref association per line) — needed for dub line mapping, not for translation start.
3. Re-insertion: token re-encode (trivial: 0x10100−SJIS) + chunk rebuild + DATA.BIN repack — sizes must be managed.

### PHASE 4 CAN BEGIN (alignment)
Both scripts extracted → start JP↔EN alignment per plan (MT-assisted matching vs SegaCD dump).

## Session 7 addendum — sound driver confirmed
- SDDRVS6.TSK verified resident+running at sound RAM 0x0000 in mid-playback state (70/80 blocks byte-identical; vector table SP=0xA000 PC=0x1000). Ghidra 68000 import done (`analysis/ghidra_out/SDDRVS6_all.c`, sparse — needs entry-point-guided re-analysis at 0x1000 next session).

## 2026-07-26 — PROOF OF CONCEPT VERIFIED ON SCREEN
English text ("ＷＥＬＣＯＭＥ ＴＯ ＪＵＮＫＥＲ ＨＱ．") rendered in-game by the
unmodified engine (Mednafen, fresh boot of patched build/poc_en disc), JunkerHQ
reception. Screenshot: `screenshots/2026-07-26_first_english_text_junkerhq.png`.
Data path proven end-to-end: token re-encode → chunk patch → sector patch → boot.
User has a save state on the patched build (new disc hash) for renderer work.

## Session 8 — VM internals + speaker table

- **Operand encoding classes** (from fetcher FUN_060c0c78 constants): byte <0x80 → two-byte
  index form via FUN_060c08b0 (u16 ×2 into a flag-adjusted table); 0x80–0x9F class; 0xA0/0xB0
  = 12-bit immediate ((b&0xF)<<8|next); 0xC0 = 12-bit + indirect call (PTR_060c14a4);
  0xD0 = 4-bit immediate; 0xE0+ switch: E0=byte, E1=byte+byte, E2/E4=u32 build, E3=u16, E5=call(-1)...
  This is the spec base for the bytecode disassembler (needed for offset-safe English insertion).
- **SPEAKER TABLE FOUND: 0x060C1F14, 80 entries** (pointer table → SJIS names with ＠color
  prefixes): 02 Metal Gear/blue, 03 Harry/cyan, 04 Receptionist/purple, 05 Gillian/green,
  06 Mika/purple, 07 Chief/yellow, 0C Katrina, 1C Ivan/red, 1D Lisa/red, etc. Includes
  Saturn-exclusive cameo speakers: Goemon, Dracula, Simon, Pastel, Power Pro-kun, and the
  Tokimeki Memorial cast (藤崎/如月/紐緒/…), plus Konami staff names.
  Saved: `extracted/script/saturn_speakers.json`. Names are pointer-referenced → English
  speaker names = simple string relocation patch in MAIN_L.BIN.
  Speaker IDs also strengthen JP↔EN line alignment (SegaCD SUBCODE.BIN has speaker data too).

### Next
1. Finish bytecode disassembler: map handler semantics for print-text opcode + branch opcodes
   (which operands are code offsets) → relocating inserter.
2. Then: batch English insertion pipeline (alignment → re-encode → rebuild chunks/DATA.BIN index).

## Session 9 — inserter built + CRITICAL sizing finding

- `tools/build_translation_patch.py`: batch length-preserving English insertion (full-width SJIS,
  0x10100-token, pad/truncate to exact JP byte length → chunk size unchanged → inline offsets safe).
  Demoed 5 JunkerHQ lines into chunk_022.
- **Text is stored INLINE in the scene bytecode** (verified: `a0 05`-class opcodes precede inline
  token runs; chunk holds offset operands = jump/call targets into the chunk). So variable-length
  insertion requires recomputing those offsets.
- **SIZING REALITY (measured across full corpus):** Saturn JP median line budget = 34 bytes;
  SegaCD EN median line = 43 chars. Capacity per piece at median budget: full-width 8 chars,
  half-width 17 chars. English lines that fit the JP byte budget: **full-width 10%, half-width 22%.**
  → Length-preserving insertion is a PoC only. A real English patch REQUIRES a **relocating
  inserter** (grow strings, rebuild chunk, fix all inline offset operands) PLUS the half-width font.
  Both are now mandatory, not optional.

## ROADMAP (data-backed, ordered)
1. **Half-width 8x16 font hack** — doubles line capacity; renderer FUN_060b4970 uses a width table
   at 0x060D6A70 (proportional already!) — may need only font glyphs + width entries, not code.
2. **Relocating bytecode inserter** — the real text tool. Needs the offset-operand map per opcode
   (session 8 operand classes are the base); grow chunks, recompute inline jump/call targets,
   rebuild DATA.BIN index (639-entry table at MAIN_L 0x362F4) + repack track 1.
3. **JP↔EN alignment** — 12,259 JP ↔ 10,728 EN via MT-assisted matching + speaker-ID + scene order
   (speaker table done, session 8). Produces the translation.json the inserter consumes.
4. **Voice**: 68K ADPCM decode loop (dialogue in ACT*.CAT) → encoder; system PCM + FMV-AVI + CD-DA
   are already trivial swaps.
5. **Packaging**: EDC/ECC regen for real hardware; xdelta/SSP patch distribution.

## Session 10 — dialogue capacity measured on-screen; half-width path scoped

- **Measured real glyph layout from save-state VDP1 command list**: dialogue box = fixed
  **monospace, 14px pitch, ~20 glyphs/line, 4 visible lines** (advance run = 14,14,14…; rows at
  y=158/173/188/204). So usable capacity ≈ 20×4 = 80 chars/page at full-width — this is THE
  translation fit constraint (matches the corpus analysis: full-width English overflows).
- **Renderer = FUN_060b4970** (80-iter loop, DAT_060b4a70=width table @0x060D6A70, glyph source
  VRAM 0x15000). Coordinate math line 3064: `(width>>2)*0xe(14)+base`. Second text renderer at
  decompile line 4770 (same shape) = the status/scroll layer.
- **Half-width lead**: FUN_060b4970 has a *proportional* code branch already
  (`sVar5 = (uVar1&3)*4 + sVar2`) alongside the monospace one. Two routes to ~40 chars/line:
  (a) supply 8px Latin glyphs + halve the 14px pitch in the VDP1 command builder, or
  (b) drive Latin through the existing proportional branch. Route (b) may be data-mostly.
- NEXT: pin the pitch/size write in the command builder (trace psVar7/psVar9 arrays →VDP1 cmd),
  craft a half-width test build, screenshot.

## Session 11 — HALF-WIDTH MECHANISM FULLY MAPPED (all edit sites located)

Live dialogue glyph VDP1 command (from save state): 16×14px, size field 0x020E, 14px pitch.
Three edit sites for half-width (~40 chars/line, matching the SegaCD reference shot):
1. **Pitch table @ 0x060E5358** — 80 records × 12 bytes (4 rows × 20 glyphs), X coord at short
   index 4, currently step 14. Edit → step 8 (+ extend to ~34/row). Pure data.
2. **Glyph size @ 0x060E0CC0** = 0x020E (16w×14h) in a sprite-size lookup table (index 32).
   Edit → 0x010E (8w×14h). Verify not shared with other 16px sprites first.
3. **8px Latin glyphs** — author half-width A–Z/a–z/punct into the font source; the font is
   expanded into VRAM at load (on-disc source still to be located, or inject into VRAM-upload path).
Renderer FUN_060b4970 fills per-frame; pitch/size are static data → route is mostly data edits + font art.

Reference target archived: `screenshots/20260726_212053-screen-segacd.png` (SegaCD "Welcome to
Junker Headquarters. May I help you?" — proportional mixed-case, the visual goal).

### Phase 3 = COMPLETE (all formats cracked). Phase 4 underway.
Remaining Phase 4: half-width font build (sites above) · relocating inserter · alignment · voice codec.

## Session 12 — both threads advanced

### Alignment (Thread 1)
- **First full scene translated & aligned**: `translation/chunk_022.json` — 43 JunkerHQ lines,
  English matched to Saturn token offsets, phrased to the SegaCD localization. This is the
  translation-data format the inserter consumes. Scaling = repeat for 36 scenes (MT-assisted bulk
  + review). Note: chunk_022 exposes the Saturn JUNKER backronym text at 0x3418
  (Judgement/Uninfected/Naked/Kind & Execute Ranger) — matches SegaCD.

### Half-width (Thread 2)
- **Font asset authored**: `assets/halfwidth_ascii_8x16_4bpp.bin` — 95 glyphs (ASCII 0x20-0x7E),
  8x16 VDP1 4bpp, legible (preview PNG in assets/).
- **Font upload routine located: FUN_060b4530**; resident kanji font DMA'd to VDP1 VRAM
  **0x25C08000** (dest const @0x060b4590), plus the 0x25C15000 on-demand glyph cache. Font disc
  source is NOT staged in WRAM and NOT a plain 1bpp/verbatim chunk → uploaded/expanded from a
  DATA.BIN region via this routine (exact source ptr/len is the last trace).
- Half-width build recipe (all sites known): inject 95 ASCII glyphs into a free VRAM font region
  via an added transfer in FUN_060b4530's path → map English codes to those slots → set pitch
  table 0x060E5358 to step 8 (34/row) → set size 0x060E0CC0 to 0x010E. Multi-step but fully scoped.

## Session 13 — SOURCE OF TRUTH established (master DB + matcher) + key correctness finding

- **`translation/master.json` = the project's source of truth**: all 12,259 Saturn lines keyed by
  (chunk, offset) with jp / en / status. Built by `tools/build_master_db.py` (merges
  translation/*.json overrides). Currently 43/12,259 translated (JunkerHQ scene).
- **`tools/match_segacd.py`**: fuzzy-matches drafted English vs the SegaCD official localization.
- **CRITICAL FINDING — matcher must be ADVISORY, not automatic.** The SegaCD is English-only (no JP
  side to match against), so matching is English-surface only → false positives on shared sentence
  openers (e.g. Saturn "Quite an Oriental beauty" fuzz-matched SegaCD "Quite a convenient little
  item", 0.556; blind adoption would be WRONG). Also: Saturn (1996) has different/added content vs
  SegaCD (1994) — line-by-line correspondence is partial.
  → **Correct pipeline:** faithful fresh translation of the Saturn JP is the source of truth;
  SegaCD text is a *phrasing reference* adopted only on HIGH score (>0.8) AND human confirmation
  (recovers the beloved official wording for true matches like "Welcome to Junker Headquarters.
  May I help you?"). Low/mid scores stay as the faithful Saturn translation.
- Remaining: translate the other 35 scenes (faithful JP→EN), run matcher to flag official-wording
  candidates, human-confirm the high-score adoptions.

## Boot-sequence disclaimer screen (2026-07-27, user-flagged)
The post-title "この物語はフィクション…" fiction disclaimer is NOT in the translatable script:
searched every binary (MAIN_L, A.BIN, LOGO/MX TRMs, all DATA.BIN chunks raw+decompressed, disc
tracks) and the live save-state WRAM in both SJIS and 0x10100-token forms — zero hits. The only
フィクション match is unrelated chunk_042 dialogue. → The disclaimer is a **pre-rendered bitmap/
graphic** (boot sequence), not string-rendered text. Same likely true of title/warning screens.
Translation impact: NONE on the 12,259-line dialogue/menu script (our source of truth). To
localize it later = a graphics-replacement task (edit/replace the boot image), not script work.
Standard fan-patch practice is to leave the legal disclaimer in Japanese; optional to graphic-swap.

## 2026-07-27 — FULL SCRIPT TRANSLATED (100%)
All 36 text scenes (12,259 lines) of Saturn Snatcher translated JP→EN, validated, committed.
- Source of truth: `translation/master.json` (12,259/12,259 translated).
- Pipeline: per-scene subagent translation (glossary-guided) → `validate_translation.py` gate
  → `build_master_db.py` merge → commit. Survived 2 crashes + 1 usage-limit reset, zero loss.
- Full patched disc builds from master.json via `build_full_patch.py` (`build/full_en`).
  11,889/12,259 lines truncate at full-width → confirms half-width font is required for release
  quality (short lines already display correctly; the pipeline & data are complete).
- QA sweep pending: `translation/QA_NOTES.md` (name spellings, input-matching puzzles, ＠桃 tag).

### Next milestones
1. Boot-test build/full_en in Mednafen (spot-check translated scenes render).
2. Half-width font (assets/ font authored; edit sites mapped in session 11).
3. Relocating inserter (for lines that overflow even half-width).
4. Voice: 68K ADPCM decode (ACT*.CAT) + system PCM/FMV/CD-DA swaps.
5. Packaging: EDC/ECC regen, xdelta/SSP patch distribution.

## 2026-07-27 — In-game test findings + font architecture (the hard frontier)

Booted full English disc. Results:
- SCRIPT renders in English end-to-end. ✓
- Two rendering problems, both full-width-encoding artifacts (NOT space chars — proven byte-level):
  1. TRUNCATION ("Go inside"->"Go i"): length-preserving build cuts English to JP byte budget.
  2. WIDTH: every glyph is full-width (16px cell, 14px pitch) -> text looks spread out.
- Speaker names were untranslated: they live in a POINTER TABLE at 0x060C1F14 (raw SJIS), not
  the scene chunks. FIXED via relocation: `tools/patch_speakers.py` writes English names into the
  verified-free zero region 0x060E71F0 (0 code refs) and repoints. Proves growing-text-past-budget.
- Extractor bug: min_chars=3 dropped 577 two-char menu verbs (見る/話す/移動...). Fixed (min_chars=2),
  re-extracted 12,259->12,836, translated. `tools/patch_halfwidth.py` size/pitch edit CONFIRMED
  spacing tightens (user) but VDP1 CROPS to left-8px so scaled 16px glyphs garble -> need true 8px art.

### FONT ARCHITECTURE (mapped)
- Font upload routine: FUN_060b4530. Main font DMA'd to VRAM 0x25C08000 (len 0xD000 = 416 glyphs);
  small cache preload from MAIN_L 0x060E5BE6 (0x440 bytes) to 0x25C15000.
- Dialogue renderer FUN_060b4970 reads glyphs from cache region (0x25C15000+, slot*0x80).
- Menu = a SECOND renderer (decompile line 4770) with its own path.
- Font NOT stored verbatim on disc (expanded/transformed at load) — so no simple data patch.

### HALF-WIDTH = ASM-HOOK ROMHACK (multi-session; the real remaining frontier)
Path: inject 8px 4bpp Latin glyphs + a small SH-2 routine into MAIN_L free space; hook the glyph
fetch/cache-fill so Latin codes draw the 8px glyphs; set pitch/size per renderer. Then half-width
ENCODING (1 byte/char) to also fix truncation. Do dialogue first, then menu.

### RESOURCES (from ~/src/32x-builder — SH-2 reference, user-pointed)
- `reference/32x_font_8px_4bpp.s` (copied) = ready 8x8 4bpp font, VDP1 format, ASCII 0x20+.
- `~/src/32x-builder/srcref/d32xr/sh2_draw4b.s` = SH-2 4bpp draw patterns.
- SH-2 toolchain (sh-elf-gcc/as) via MARSDEV — builds in Docker in that project.
- `assets/halfwidth_ascii_8x16_4bpp.bin` = our authored 8x16 font (alternative to font.s).

## 2026-07-27 — Presentation layer: precise state (the real frontier)

TRUNCATION ROOT CAUSE: build_full_patch is length-preserving — English is cut to the
Japanese byte budget. Complete text is safe in master.json; the BUILDER truncates.
Scene text is INLINE bytecode (verified: no pointer refs to text offsets; VM executes
into it after a print-opcode + 0x00). So growing it needs a RELOCATING REASSEMBLER.

REASSEMBLER FEASIBILITY (confirmed) + BLOCKER:
- Token length is class-determined by the leading byte (FUN_060c0c78 operand fetcher):
  <0x80 = 2-byte text token (value = 0x10100-SJIS); 0xA0/0xB0/0xC0 = 2B; 0xD0 = 1B;
  0x80-0x9F and 0xE0+ = still-unverified lengths.
- Prototype tokenizer with guessed lengths aligns only 24% of known text offsets ->
  desyncs on unverified opcodes. Need exact lengths (decode FUN_060c0dec + 0xE0 switch
  fully) AND per-opcode identification of which operands are chunk-offset jump targets
  (to adjust when text grows). This is multi-session, crash-prone romhacking.

FONT (half-width): master KANJI font = chunk_000 (data-patchable). Latin/kana font block
still not located on disc. VDP1 size field CROPS to left-8px (not scale) -> true 8px
left-aligned glyphs would render clean; scaled 16px glyphs garble (confirmed on-screen).

DONE THIS SESSION: speaker names -> English (relocation, works). QA consistency sweep
(43 fixes). Repo published (no copyrighted content). Translation 100% + QA'd.

NEXT (dedicated session): (a) verify full opcode length table -> round-trip a chunk
byte-identical; (b) tag offset operands; (c) relocating reassembler + DATA.BIN repack;
(d) then half-width font. Each gated by emulator boot-test.

## 2026-07-27 — Reassembler: mechanism fully cracked, blocked on VM control-flow tracer

TWO tests proved: (1) grown text RENDERS in-game ✓; (2) naive growth garbles downstream
because the scene VM uses RELATIVE varint distances that break when a span crosses the growth.

VM MECHANISM (verified, tools/vm_disasm.py, commit 764a757):
- Jump/skip primitive FUN_060c0908: varint distance, cursor += distance. Varint: b≤0xBF → 1 byte;
  else 2 bytes = (b-0xC0)*256+next (bias 0xFF40). Blocks FUN_060c3650/3758: varint = body length.
- 0x060FD164 is a CHARACTER-PROPERTY table (text reader), NOT a jump table.
- Tokenizer: 100% real-text alignment, 78/78 round-trip.

GROWTH RECIPE (design confirmed): grow text at X by δ → bump index size_words; add δ to every
jump/block varint whose span crosses X; handle varint 1→2 byte cascade to fixpoint; stay in slack.

BLOCKER: identifying WHICH opcode bytes carry a jump/block varint. Linear scan = 0% target
alignment under all tried placements → varints consumed behind multi-level dispatch (secondary
handler tables 0x060c29f0/34d0/3efc/3fbc). REQUIRES a scene-VM control-flow tracer (step opcodes
through dispatch, record varints read by jump/block primitives). Bounded but a real build.

STATUS: translation 100% + QA'd + public; speaker names EN; grown text renders; reassembler
mechanism understood; remaining = VM tracer (dedicated multi-session build) OR half-width
single-byte encoding path (needs engine single-byte-text support confirmation + font).

## 2026-07-27 — VM TRACER BUILT; "SPANNING VARINTS" DIAGNOSIS OVERTURNED — TEXT GROWTH IS TRIVIAL

Built the scene-VM tracer (tools/vm_trace.py) from a full RE of the interpreter's exec/skip
function pairs. The headline discovery makes the planned growth-fixup machinery unnecessary:

### CHUNK LAYOUT (verified arithmetically on ALL 39 scene chunks 21-59)
  [u16 h0][u16 h1][bytecode from offset 4][TEXT SECTION][3-4 byte trailer]
  - Text section = [h0+5, h0+5+h1). h1 = section byte length (h1==1 for textless scenes).
  - Section = 0x00-separated records of 2-byte tokens (0x10100-SJIS), consumed
    SEQUENTIALLY by the engine — no stored text offsets exist in bytecode (verified:
    record-start offsets do not correlate with any operand encoding).
  - Trailer = 00 + u16 globally-ascending counter (+pad). Chunks 60+ = non-scene data.
  - ALL text lives AFTER all bytecode => growing text moves ZERO code. The old
    "relative varints break when spanning growth" model is DEAD: nothing spans.
    The earlier in-emulator garble was (in hindsight) caused by not updating h1 —
    the engine reads h1 at scene load; text-cursor sync breaks => wrong records shown.

### VM GRAMMAR (for the tracer; exec/skip pairs cross-validated in MAIN_L.BIN)
  - THREE bytecode contexts + expressions, one shared stream (IP 0x060FC8B0, base 0x060FB460):
    STATEMENT exec FUN_060c2858/skip 2ac4/operands 2b28; WAIT-item exec 3dd0/skip 3fec;
    DISPLAY-item exec 3358 (text blocks via 32dc); EXPRESSION exec 0c78/skip 1350.
  - Statement: 0x0A=end; 0x09=varint wait-block; flag 0x20=varint wait-block (3bec);
    flag 0x10=trailing varint choice-block; nibble 0-3=CALL (07c0 addr operand),
    8=menu (varint display-block), c/d/e/f=varint blocks (if/switch/threshold lists).
  - Native calls: 0xC0-class, 12-bit id -> 20-entry table at 0x060E4FA8 {fn,ret,argc};
    args are argc in-stream expressions; natives NEVER read the stream themselves
    (all 20 decompiled via headless Ghidra — pure side-effect fns, e.g. native 1 =
    voice/wait: the c0 01 a0 05 XXXX before each line = play voice cue XXXX).
  - Address operands (FUN_060c07c0): 2-byte form = signed16, target = operand_pos + i16;
    3-byte form [bank][u16]: bank 0xFF = relative, else external/tagged (bank<<15|off).
  - Expression lengths as vm_disasm.py PLUS corrections: E8-EF carry 2/3-byte ADDRESS
    operands (3/4/3/4/3/4/4/5 bytes total), F0=4 bytes, F7/FE/FF = varint expr blocks.
    0x00 is 2 bytes in expression context (the 1-byte-0x00 rule is text-section only).
  - Varint everywhere: b<=0xBF ? b : (b-0xC0)*256+next (thresholds verified uniform).
  - Wait-item classes: 0x00-0x5F=(n&0x1f+1)x3-byte flag refs; 0x60-0x7F=cond chain
    (n+1 x [expr][varint blk] + else-blk); 0x80-0x9F=switch; 0xA0=3-byte sel + (n+2)
    pairs; 0xB0=(n+2) pairs; 0xC0=native; 0xD0=(n+1)x3 + expr; 0xE0-E7=call/goto addr;
    E9/EB=varint blk; ED=+2; EE=count refs+expr; FB-FF=varint constructs.
  - Menus (stmt nibble 8): display items = [2-byte label-table token][attached
    statement] pairs; nested submenus are common.
  - tools/vm_trace.py: recursive parse, 39/39 chunks, 80.7% of intra-chunk address
    targets land on parsed boundaries, remaining gaps opaque-skipped exactly like the
    engine's own skip path (varint). Open warts (don't block anything): statement
    opcode 0x9f-style constructs, 3-byte bank semantics.

### REASSEMBLER (tools/reassemble.py) — COMPLETE
  Growth = new record bytes + h1 += delta + chunk size (+ DATA.BIN index size_words).
  No bytecode fixups. Round-trip invariant verified 39/39 chunks byte-identical.

### BOOT TEST v1 (in-place growth): grown greeting RENDERED FULLY, but downstream
  dialogue/menus garbled — h1 was NOT the missing piece. Savestate forensics found it:

### TEXT REFERENCING MECHANISM (solved via savestate + 08b0 semantics)
  - Scene load SPLITS the chunk: bytecode -> WRAM 0x202F8000 (from file offset 4),
    TEXT SECTION -> its own region 0x202E8000 (base corresponds to file h0+4);
    a decoded SJIS staging bank lives at ~0x247xxx (per-line copies + voice refs).
  - *0x060FD164 (FUN_060c08b0's "charprop table") = 0x202E8000 = TEXT BASE.
    **The bytecode's <0x80 2-byte tokens ARE text-section offsets/2**: token T ->
    byte offset 2T if text[2T-1]==0 (record follows a separator) else 2T-1 (odd
    starts). So text IS referenced by absolute section offset — via tokens, not
    operands. In-place growth shifts records => every token past the growth point
    mis-resolves mid-record => misaligned token decode => the observed half-garbled
    glyphs. (v1's arithmetic was right; this reference layer was the real breaker.)
  - *0x060FD150 = chunk trailer u16 (0x1CB for ch022) = the chunk's FIRST GLOBAL
    TEXT ID; FUN_060c096c maps u16 args: <=0x9fff literal, 0xa000-0xdfff ->
    global id (v-0xa000)+trailer_base, >=0xe000 -> relative to current id
    (*0x060FD158). Those args are growth-immune.
  - Say-line native call = c0 01 [mode][text-offset token]; greeting @ch022 code
    0x10e: c0 01 a0 03 00 0f (token 0x0f -> B=0x1e -> file 0x2a34 ✓).

### REASSEMBLER v2 — APPEND + REPOINT (reassemble.append_records)
  Append grown record at section end (h1 grows), leave the original record in
  place, and repoint ONLY the explicit reference tokens. Consequences:
  - No other record moves => no mass token relocation, tracer accuracy not
    load-bearing for correctness.
  - A missed/unpatched reference still shows the ORIGINAL JP text — graceful
    degradation, never garble. Ideal for incremental full-corpus insertion.
  - Old record slots become reusable free space for short strings later.
  BOOT TEST v2 (build/reasm_test): greeting appended (+63 bytes incl. separator,
  h1 0x781b->0x785a), say-line token @0x112 repointed 0x000f->0x3c0e, all other
  section bytes byte-identical to original (verified by sector readback).

### BOOT TEST v2 = **PASSED IN-EMULATOR (user, 2026-07-27)**
  Full "WELCOME TO JUNKER / HEADQUARTERS." rendered untruncated AND the scene is
  completely clean afterward (中に入る/見る/調べる/話す menu perfect, dialogue
  normal). THE TEXT-GROWTH PIPELINE IS PROVEN: append record + repoint reference
  token + h1 + DATA.BIN index = complete, safe fixup set.
  Remaining cosmetic issue: wide spacing between English glyphs = the known
  full-width 16px-cell/14px-pitch rendering — that is the separate half-width
  font project (edit sites mapped in session 11), not a reassembler issue.
  Scaling plan for the full corpus: per translated line, find its reference
  token(s) (say-line calls c0 01 [mode][tok] + menu label tokens; vm_trace.py
  locates them by context), append + repoint; repack DATA.BIN sector layout
  when a chunk outgrows its slack (old record slots become free space).

## 2026-07-27 (late) — VOICED-LINE ARCHITECTURE CRACKED: companion sync chunks

Root cause of the full-build hangs (LOOK/ask-JUNKER): voiced dialogue does NOT
display via the say-call token. Chain of evidence (differential discs + savestate
forensics): test_C repointed a voiced say token -> JP still displayed, no hang;
full build (slot-reuse destroyed originals) -> hang at the same line.

- **Chunks 60-98 = per-scene SUBTITLE/SYNC scripts** (scene N chunk maps to
  companion N+39: ch021-060, ch022-061 ... ch059-098; verified by token-match).
  Stream of [u16 op][args] pairs; 104-entry handler table at MAIN_L 0x60E4E00
  (right before the native argc table). Entries like `00 28 [record-token]
  00 2a [link]` key VOICED lines by their TEXT-SECTION TOKEN (857 ch022 token
  hits in ch061). Handler arities extracted for 56 ops (sync_handlers.txt);
  47 complex ops (pointer-followers/terminators) still to model.
- Voiced flow: native2(text-key, cue) stores a pending pair (0x60F29FE/0x60F2A00);
  the sync stream matches the key (walker FUN_060b7398) and drives staging,
  subtitle display, voice, and the dismiss. So: repointing the say token does
  nothing for voiced lines; DESTROYING the original record (slot reuse) breaks
  the sync path -> hang. Track-2 MSF rewrite (test A pre-fix hang) was a real,
  separate bug; the shift is believed clean post-fix.
- **v3 SAFE BUILD** (current build/full_en2): in-place EN for every line that
  fits (positions unchanged -> sync keys stay valid, so even voiced fits show
  EN with voice); appended EN only for lines with exclusively unvoiced (mode-3)
  say refs and menu tokens; NO slot reuse; structural guard (entry-parse
  equivalence, unsafe repoints reverted). 7,440 lines EN, 3,190 voiced kept JP.
- NEXT: model the 47 complex sync ops -> full companion-stream parser with
  self-check (links land on entry boundaries) -> remap record tokens inside
  companions + native2/3 imm args -> voiced dialogue EN. Then half-width font.
