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
