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
