# Snatcher (Sega Saturn, Japan, T-9508G) — English Patch Technical Reference

Authoritative, standalone reference for the reverse-engineering and patching of the
Japanese Saturn release of *Snatcher*. Written so a ROM hacker with the disc and a
SH-2 toolchain can pick this up cold. **Every claim is tagged:**

- **[PROVEN]** — confirmed in-emulator or by direct byte inspection. Evidence given.
- **[HYPOTHESIS]** — current best model, NOT yet confirmed. Do not build on it blindly.
- **[TRAP]** — a failure mode that cost real debugging time. Avoid.

Emulator of record: Mednafen (Saturn core). All addresses are for this build unless noted.

---

## 1. Disc & file layout  [PROVEN — byte inspection of the original disc]

- 3 tracks. Track 1 (data) holds the ISO9660 filesystem + `DATA.BIN` + `MAIN_L.BIN`.
- Sector = **2352 bytes**, Mode 1: 16-byte header (sync + BCD MSF + mode) then 2048
  bytes user data, then EDC/ECC (Mednafen ignores EDC/ECC; real hardware needs it).
- **`DATA.BIN` starts at LBA 96.** Holds 639 "chunks" (scene scripts + text).
- **`MAIN_L.BIN` starts at LBA 5451.** This is the SH-2 game engine. File size `0x3F478`.
- ISO fs: PVD at LBA 16; path/dir records hold each file's `(LBA, size)` in both
  little- and big-endian. Growing any file shifts every later file → must patch the
  PVD volume size and every directory extent, and restamp track-2/3 sector MSF headers.

### Chunk index  [PROVEN — byte inspection + working builds]
- Located in `MAIN_L.BIN` at **file offset `0x362F4`**. 639 entries × 4 bytes:
  `(start_sector:u16_BE, size_words:u16_BE)`, big-endian. `start_sector` is relative
  to `DATA.BIN` (LBA 96). `size_words` = chunk byte size / 2.
- **[HYPOTHESIS] The game may NOT use `size_words` to bound how much it loads** — see §7.

### Chunk internal structure  [PROVEN — `tools/reassemble.py`, matches all scene chunks]
- Header: `struct >2H` at bytes `[0:4]` = `(h0, h1)`.
  - `h0` = code-section size marker. Text section starts at **`ts = h0 + 5`**.
  - `h1` = text-section size. Text section ends at **`te = ts + h1`**.
- Text records live in `[ts, te)`, separated by `0x00`. The engine consumes them
  **sequentially** (there is no per-record offset table inside the chunk).

### Text record encoding  [PROVEN — decompiled `FUN_060c4d24` + working decoder replacement]
- On disc, each record is a stream of **byte-negated Shift-JIS**: the decoder emits
  `out_byte = (0x100 - in_byte) & 0xFF` for each byte (so a full-width SJIS char stored
  as its two negated bytes decodes back to real SJIS). `0x00` terminates a record.
- **A record's byte budget = the length of the original Japanese string** (bytes to the
  next `0x00`). This is THE constraint that truncates English. A 2-kanji menu = 4 bytes.

---

## 2. The decoder (`FUN_060c4d24`)  [PROVEN — decompiled, replaced, verified in-emulator]

- Signature: `char *decode(char *p)`. Reads the record at `p`, `malloc`s an output
  buffer (`game_malloc` at `0x060C4F3C`), writes decoded SJIS, returns it.
- **CRITICAL PROPERTY: the output length is NOT bounded by the record length.** It
  mallocs and can return an arbitrarily longer string than the input record.
  - Evidence: our replacement decodes a dense 1-byte encoding (1 input byte → 2 output
    SJIS bytes) and the game renders the longer result correctly — full multi-line
    English out of a short record, observed in-emulator.
- Called from **7 sites**; the call goes through function-pointer literals at MAIN_L
  **file offsets `0x835c, 0x84a0, 0x907c, 0x9714, 0x97e8, 0xa040, 0xa67c`**. Repointing
  all 7 to a replacement swaps the decoder globally.

---

## 3. SH-2 code injection  [PROVEN — resident payload runs across the whole game]

- `MAIN_L.BIN` loads to **`0x060B0000`** (HWRAM). File end `0x3F478` → VRAM `0x060EF478`.
- Engine BSS-clear range at startup: **`0x060EF480`–`0x060FF090`** (do NOT place
  persistent code/data here — it is zeroed at boot).
- **RESIDENCY = `0x060FF090`** — just above the BSS-clear range, below end of HWRAM
  (`0x06100000`). Zero across all savestates = genuinely free. **Free window ≈ 3952
  bytes.** Reached by GROWING `MAIN_L.BIN` so the payload lands at file offset
  `RESIDENCY - 0x060B0000 = 0x4F090`; the gap `0x3F478..0x4F090` is zero padding.
- **Hooking = repoint a function-pointer literal** in MAIN_L to the payload entry, and
  have the payload tail-call the original (`jmp @r0`, preserving `pr`) when it must.
- Toolchain: MARSDEV `sh-elf-gcc -m2 -O2 -ffreestanding -fno-builtin -fomit-frame-pointer`;
  link so the entry symbol lands exactly at RESIDENCY; `objcopy -O binary`. Disassembly:
  capstone SH-2 **big-endian**.

### [TRAP] Do not use these "free-looking" addresses
- **`0x060E71F0` is a RUNTIME BUFFER, not free space.** Writing data here (the English
  speaker-name table did) HANGS the game on scene load. Zero-runs in the MAIN_L file are
  runtime buffers, not free RAM. Only `0x060FF090`+ is verified safe.

---

## 4. Text rendering — VDP1  [PROVEN — in-emulator glyph replacement]

- VDP1 command list (sprite list) at **`0x25C00000`**. VDP1 framebuffer at `0x25C80000`.
- Each command = 32 bytes / 16 × u16 (big-endian):
  `[0]=CMDCTRL, [1]=CMDLINK, [2]=CMDPMOD, [3]=CMDCOLR, [4]=CMDSRCA, [5]=CMDSIZE,
  [6]=CMDXA, [7]=CMDYA`. List ends at a command whose `CMDCTRL == 0x8000`.
- Text sprites: `CMDCTRL & 0xF == 0`, `CMDSRCA` in ~`[0x1000, 0x2100]`.
- **A sprite's glyph pixels are read from `0x25C00000 + CMDSRCA*8`.**
  - Evidence: writing a solid block to `0x25C00000 + CMDSRCA*8` replaced the on-screen
    dialogue glyphs with blocks. The earlier assumed formula `0x25C08000 + SJIS_low*0x80`
    wrote to unused VRAM and had ZERO visible effect (it was a red herring for a long time).
- `CMDSIZE = (width/8 << 8) | height`. Text uses `0x020E` = 16 px wide × 14 rows (glyph
  slot = 16×14 × 4bpp = `0x70` bytes; slots are spaced `0xE` in CMDSRCA units).
- **[TRAP] The game's font cache maps different characters onto SHARED slots.** Multiple
  distinct Latin letters can resolve to the same `CMDSRCA`. One slot = one glyph, so you
  cannot render two different letters that share a slot. Fix: in the per-frame hook, give
  each on-screen cell a PRIVATE slot in free VRAM (we use `0x25C20000 + cell*0x80`) and
  overwrite that sprite's `CMDSRCA` to point there.
- The per-frame hook runs at frame-sync `FUN_060b55a0`; its pointer literal is at MAIN_L
  **file offset `0x472c`**. Writes to VRAM (glyphs + CMDSRCA) made here survive to draw.

### Line buffer & cell mapping  [PROVEN — savestate inspection]
- The on-screen text-window contents live at **`0x060F28AA`**: 80 cells × 4 bytes =
  `[SJIS_hi][SJIS_lo][color][00]`. Layout = 20 columns × 4 rows.
- **Map a sprite to its cell by SCREEN POSITION, not by counting sprites.** Row = the
  sprite's `CMDYA` group; column = `(CMDXA − row_origin) / 14` (pitch 14 px). A naive
  sprite counter desyncs because some cells (e.g. a middle speaker-name kanji) produce no
  sprite. Evidence: counter-based mapping rendered "Welcome to JUNKER HQ" as garbage;
  position-based mapping rendered it correctly.

---

## 4b. Half-width font effort — glyph-cache mechanism  [IN PROGRESS]
Goal: render text half-width (like the SegaCD) so menus fit their columns. The
per-frame `frame()` renderer is a DEAD END — it reassigns CMDSRCA every frame and
the game rebuilds the command list after our frame-sync hook, so our changes never
reach the draw (VERIFIED: post-hook savestate shows the game's srca, not ours).
- **Font upload = `FUN_060b4530`** (ptr at MAIN_L file `0x1208`). Runs ONCE per
  scene. Bulk-copies the font (DECOMPRESSED via `FUN_060b2f8c` → `FUN_060b22ec` /
  `FUN_060b23c8` / `FUN_060cb6fc`, source indexed by `r4` from table `0x060e62f6`,
  work buffers `0x20248000`/`0x20258000`) into the glyph cache at VDP1 VRAM
  `0x25c08000` (0xd000 bytes) + `0x25c15000/0x25c15800/0x25c17800`.
- **Text sprites read glyphs from `0x25c08000 + (srca-0x1000)*8`** (srca ~`0x1000`–
  `0x1150`, i.e. the first ~0xa80 bytes = ~24 slots of `0x70` bytes each = 16px×14
  4bpp). Each char maps to a fixed-looking slot: E→13, L→15, a→18, e→19, i→20,
  m→21, n→22, x→24 (slot = (srca-0x1000)/0xe), and E/e/o gave the SAME slot across
  two different scenes → the mapping looks FIXED per char (not first-appearance).
- **[PROVEN] The glyph cache is STABLE and overwriting it works.** Test: hook the
  font upload, run it, then blast slot 13 with a solid block → every uppercase **E**
  rendered as a block, in dialogue AND in the menu that loads later in the same
  scene (lowercase e untouched = different slot). So the cache is loaded once per
  scene and sprites read it directly; overwriting a slot changes that glyph
  everywhere, persistently, with NO command-list/per-frame race. This is THE
  correct mechanism (the per-frame `frame()` renderer is abandoned).
- **Slot 13 = uppercase 'E'** (anchor). Cache addr of slot N = `0x25c08000 + N*0x70`
  (16px×14, 4bpp). OPEN: the COMPLETE char→slot map (find the SJIS→slot conversion,
  or probe slots). Then: build the 8px font indexed by slot, overwrite each Latin
  slot in the font-upload hook, and patch sprite width + pitch to 8px (table
  `0x060e5358`, incl. menu columns).

## 5. The font  [PROVEN — renders in-emulator]
- Source asset: `assets/halfwidth_ascii_8x16_4bpp.bin` — 95 glyphs, ASCII `0x20–0x7E`
  order, 8×16 px, 4bpp, 64 bytes/glyph. **Order matters:** an earlier `font1bpp.h` was in
  a scrambled "priority order" and rendered every letter as a different letter.
- `asm/ascii_sjis.h` maps ASCII index → full-width SJIS code (e.g. `A`→`0x8260`,
  `a`→`0x8281`, space→`0x8140`). Used both to reverse-map on-screen SJIS → glyph and to
  build full-width text.

---

## 6. Overflow / paging  [PROVEN — reproduced hang + fix]
- The fill routine `FUN_060b45c4` auto-wraps at column 20, but **only the explicit
  line-break (`¥`, SJIS `0x818F`) path guards row 4** (it scrolls via `FUN_060b4730`).
  Text that auto-wraps past row 4 overruns the line buffer → memory corruption → **HANG**.
  - Evidence: asking the receptionist about JUNKER with >3 rows of English hung the game;
    clamping to ≤3 rows fixed it. See `tools/layout_clamp.py` (`clamp_text(max_rows=3)`).
- **Always clamp dialogue to ≤3 rows** (row 0 is often the speaker name).

---

## 7. Getting English PAST the record byte budget

### [TRAP] Growth + repoint (`tools/build_full_en2.py`) — DEAD END
- It grows records in place (full English on disc) and repoints the VM's text-address
  tokens. The repointing is fragile: it leaves many menus Japanese (`noref`) and
  corrupts some scripts. It also carried the `0x060E71F0` speaker trap. Do not base work
  on it.

### KEY + BLOB engine (`tools/build_engine.py`) — the intended solution
- Each translated record is overwritten IN PLACE with a 4-byte **KEY**:
  `[0x04][offset_hi][offset_mid][offset_lo]` = a 24-bit **self-relative** offset. The
  full (untruncated) 1-byte-encoded English for that record is stored in a **blob**, and
  the key means "the real text is at `p + offset`."
- Records never move → their disc offsets are unchanged → **no VM repointing needed.**
  This is the key advantage over growth.
- Smallest record is `jl = 4`, so a 4-byte key fits every record exactly. `decode()`
  detects a leading `0x04`, redirects its read pointer to `p + offset`, then decodes
  normally.
- **1-byte encoding** (used inline and in the blob): `0x01` = enter ASCII mode (raw
  bytes `0x20–0x7E` follow), `0x02` = exit ASCII mode, `0x03` = line-break → `¥`
  (`0x818F`), anything else = byte-negated SJIS token. Halves the size vs. 2-byte SJIS.

### [PROVEN] Where the blob must live
- **The game loads a chunk by its INTERNAL header `h1` (text-section size), NOT by the
  disc index `size_words`.** A blob appended *past* `te` never appeared in RAM and the
  dialogue rendered blank; placing the blob INSIDE the text section by extending `h1`
  made the full untruncated English render in-emulator ("I can't admit anyone whose
  identity is unknown" — longer than the record's byte budget). Records keep their
  offsets → no repoint.
- `h1` is 16-bit → **text section capped at 64 KB.** Chunks whose records+blob exceed
  that fall back to in-place truncation (open: harder dedup, or a second blob region).

---

## 8. Emulator & workflow  [PROVEN]
- Mednafen Saturn savestate stores WorkRAM and VDP1 VRAM **16-bit byte-swapped**; swap
  bytes when searching a savestate for known values. (Confirmed: on-screen SJIS only
  matched in swapped form.)
- Savestates embed the previously-injected code; always boot a fresh build with cleared
  save slots. Local alias `meddy "<cue>"` clears `~/.mednafen/mcs/*.mc*` then boots.
- Known-good stable build: `tools/build_decoder_hook.py` → `build/full` (all-English
  clamped dialogue, our font, no hang; menus truncated; speaker names Japanese).

---

### [PROVEN] Menus use a SEPARATE decoder — the KEY breaks them
- The dialogue decoder `FUN_060c4d24` has exactly **7 references in MAIN_L** (all
  hooked). The action-menu text does NOT go through it: with a keyed record, the menu
  line buffer contained **byte-negated key bytes** (`0x04`→`0xFC`, etc.), i.e. the menu
  ran the raw record through an INLINE byte-negate decoder of its own and never saw our
  `decode()`. So `0x04` keys garble menus.
- **RESOLVED mechanism (probe-proven):** the menu DOES call our `decode()` (via 4 of
  the 7 decode call sites, the ones whose literal pools also hold the work-buffer
  address `0x060FAC60`: file offsets near `0x9714`, `0x97e8`, `0xa040`, `0xa67c`). But
  those sites first **COPY the record into a fixed 40-byte work buffer at `0x060FAC60`**
  and call `decode()` with the COPY pointer. Dialogue sites pass the real chunk pointer
  (LWRAM, e.g. `0x2e801e`), so the self-relative `p + offset` reaches the blob; the menu
  copy is detached, so `p + offset` lands in garbage. A decode-logger probe (ring at
  `0x060FFC00`) captured exactly this: menu records arrive at `p = 0x060fac60`,
  `0x060faca0`, `0x060face0` (stride `0x40`, HWRAM), first bytes `01 52`(R) `01 50`(P)
  `01 43`(C) = Recep/Poster/Camer.
- **DISPROVEN:** prefixing the key with `0x01` — the copy still detaches it from the
  blob. Not a dispatch problem; a pointer problem.
- Mitigation (in `build_engine.py`): records with `jl < 16` kept in-place (readable-
  truncated); only longer dialogue records keyed. **Real fix (open):** give `decode()`
  the current chunk's base so it can resolve `chunk_base + absolute_offset` when `p` is
  the `0x060FAC60` copy buffer — capture the base by hooking the chunk loader, or store
  the absolute chunk offset in the key. (Note: LWRAM holds several chunks at non-fixed
  bases, so a single global is needed, not a constant.)

## 9. Open problems (honest status)
1. **h1-load hypothesis** (§7) — confirm in-emulator.
2. **64 KB text-section cap** for big chunks under KEY+BLOB.
3. **English speaker names** — need a verified-safe RAM address (NOT `0x060E71F0`).
4. **Menu slot overflow** — a longer English menu option may visually overrun its fixed
   column slot even when the text fits; layout not yet handled.
