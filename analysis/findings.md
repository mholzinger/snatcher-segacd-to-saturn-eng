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
