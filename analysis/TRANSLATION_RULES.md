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
- **[DECODED] Glyph storage = bitplane-packed 1bpp, 4 chars per 4bpp tile, VDP1
  4bpp-LUT mode.** Each text sprite: `CMDPMOD=0x08c8` (4bpp LUT), `CMDSRCA` = a tile
  SHARED by 4 characters, `CMDCOLR` = a per-char 16-entry LUT (at `CMDCOLR*8` in VDP1
  VRAM) that maps the indices carrying that char's bit to text-colour and the rest to
  transparent. So a tile's 4bpp pixel = OR of the bits of whichever of its 4 chars
  have ink there; each char is one bitplane (bit 0-3). `CMDSIZE=0x020e` = 16px×14.
- **Char→tile map (VERIFIED exact, read from the cache):** `glyph_index` → char, then
  `tile_slot = index//4`, `bit = index%4`, tile addr `0x25c08000 + tile_slot*0x70`.
  Letters `A..Za..z = 49+rank` (A=0…z=51). Digits `0-9 = 39-48`. Punct:
  `,`=3 `.`=4 `・`=5 `:`=6 `;`=7 `?`=8 `!`=9 `_`=10 `/`=13 `~`=14 `(`=16 `)`=17
  `+`=24 `-`=25 `=`=27 `%`=30 `#`=31 `&`=32 `*`=33 `@`=34. Hiragana start at 101.
  **Do NOT extrapolate indices from the A=49 anchor — digits are 39-48, not 32-41.**
  The game font has NO glyph for `'` `"` `$` `<` `>` (blank). Apostrophe is done by
  remapping `ascii_sjis['] 0x8166→0x8145` (middle-dot `・`, idx 5, unused in English)
  and stamping our apostrophe into slot 5. This map is stable per char across scenes.
- **[TOOL] To read the map definitively: render the cache from a savestate.** In the
  `.mc0` (gzip), VDP1 VRAM is the `VRAM` 0x80000 section right after the `VDP1` tag
  (~offset 723555); data is 16-bit byte-swapped. Cache = VDP1-VRAM offset `0x8000`.
  For index gi: tile `0x8000+(gi/4)*0x70`, `bit=gi&3`, 16×14 @8 bytes/row, pixel on =
  `((byte>>4 if col even else byte&0xf)>>bit)&1`. Render indices 0..111 to a PNG and
  read the characters off. The LOGGER (frame-sync srca/colr capture) is a DEAD END —
  the VDP1 command list isn't populated at that hook (same reason `frame()` failed).
- **Substitution (half-width) is therefore a COMPOSITE, not a flat overwrite:** for
  each tile, build the 4bpp texture whose bit `b` plane = our 8px glyph for the char
  at (slot,b), write it over the game's tile in the font-upload hook, and patch
  `CMDSIZE`+pitch to 8px. The FONTTEST 0xFF block worked because it set every bit
  (all 4 chars opaque). This is intricate but fully specified now.

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
- **[TESTED — scrolling DOES NOT save you]** Removing the row cap so long `<br>`-wrapped
  text scrolls via `FUN_060b4730` was tried: it still HARD-HANGS with the scene image
  wiped to black once text passes the visible rows. `FUN_060b4730` is NOT a safe
  overflow handler. Clamp, never scroll.

## 6b. Dialogue box geometry — WIDE layout  [SUPERSEDED — see §6e; 26/row is a TRAP]
> **[TRAP] COLS=26 (the "wide" layout below) HARD-HANGS the game** on any line whose
> row fills to a full 26 cells. The game's own text processor (`FUN_060b8148`, called
> from the frame fn `FUN_060b55a0`) assumes the stock **20/row × 4-row** layout; a full
> 26-cell row wedges the fill/frame path forever (no music, no advance). PROVEN
> 2026-08-06 on stock `build/engine` (print_hook NOT installed) at the Mika line "The
> chief is watching that camera feed too, you know." **Default is now COLS=20** (§6e).
> The historical wide-layout notes below are kept for reference only.

- **The render table `0x060e5358` is EXACTLY 80 cells** (12 bytes each: s2/s3 = glyph
  source written per-frame by the renderer `FUN_060b4970`; **s4=X (+8), s5=Y (+10)** =
  static geometry). Entry 80 is other UI — the table CANNOT be extended. Renderer walks
  80 cells linearly (`iVar8 < 0x50`), row/col-agnostic → geometry is 100% the table's X/Y.
- **Speaker name occupies buffer row 0** (verified: cells 0-3 hold the name, color 0x04);
  so speaker dialogue body starts at **row 1**. Speaker-less/narration starts at row 0.
- **Fill routine `FUN_060b45c4` geometry immediates (MAIN_L.BIN file offsets):** wrap
  column `0x14` at **0x46b1**; row byte-stride `0x50` at **0x45e7, 0x4657, 0x46b5**;
  row-overflow guard `cmp #4` at 0x4661. To widen to COLS/row: set wrap=COLS, stride=COLS*4.
- **Menu uses its OWN layout** `FUN_060b95b8` (2-col × 4-row, row stride `0x50` at file
  0x966a, col offset computed 0x28) — needs 20/row×4. So menu and dialogue want DIFFERENT
  geometry but share one table.
- **Fix = mode-aware table swap in `decode()`**: it already knows caller (LWRAM ptr =
  dialogue → 26/row; HWRAM copy buffer = menu → 20/row) and rewrites s4/s5 per call
  (`set_table()` in full_hook.c, running col/row counters, no divide). Self-heals because
  both share the buffer (whatever's decoded last sets the matching geometry).
- **Hard tradeoff (80-cell wall):** speaker body starts row 1, so 3 full rows need
  4×COLS ≤ 80 → COLS ≤ 20. Any COLS>20 gives speaker only **2 full rows**. Thus:
  COLS=26 → MAXROWS=2 (wide, box-filling, ~38% of lines drop a trailing line);
  COLS=20 → MAXROWS=3 (narrow ~53% width, ~29% drop). Both env-selectable in build_engine.
  True completeness needs tighter (SegaCD-fit) translations, not engine changes.

---

## 6c. Dialogue VM map  [for the paging effort — task #15]
The display is **one-record-one-screen**; ZERO original JP records exceed ~4 rows
(measured), so there is NO native in-record paging to reuse. To show long English
completely, paging must be BUILT. Architecture mapped so far:
- **`FUN_060b55a0`** = per-frame frame-sync (vsync busy-wait + subsystem calls); first
  subsystem it calls is the VM tick.
- **`FUN_060b8148`** = per-frame VM/typewriter tick. Gated by active flag; decrements a
  typing timer; while timer done and not at terminator, processes script TOKENS via the
  handler table **`0x060e4df0`** (indexed by token byte 0..0x6b, ~108 entries); when the
  waiting-flag is set it calls the wait handler instead.
- **VM state struct base = `0x060f24b0`** (same struct the menu code uses via
  `DAT_060b970c`). Holds: typing-timer, current text pointer, a "waiting-for-input" flag,
  terminator value — all at small offsets (exact offsets TBD).
- **Wait handler `FUN_060c603c`** (pointer at MAIN_L file **0x821c**, repointable like the
  DECODE_PTRS) = a **15-state** `switch(*DAT_060c60dc)` dispatch (states 0..0xe →
  `PTR_FUN_060c60e0..6118`). This is the text-display state machine; the "waiting→advance"
  transition lives here.
- **Display driver `FUN_060b8224`**: setup → fill `FUN_060b45c4(0,0,text)` → render
  `FUN_060b55a0` → `FUN_060b4e28`. Renderer of the 80-cell grid = `FUN_060b4970`.
- **Paging plan (not yet built):** `decode()` splits an over-long record into pages,
  returns page 1 (ends at terminator so the VM waits), stashes page 2+ptr + a pending
  flag in scratch RAM; repoint `0x821c` to a wrapper around `FUN_060c603c` that, on the
  advance transition, if a page is pending, points the VM text ptr (struct@0x060f24b0) at
  the next page, clears the box, clears the flag — else calls the original. Unknowns to
  nail before coding: the struct field offsets, the state var `DAT_060c60dc` + which state
  is "advance", and the box-clear routine. HANG-test every step.

## 6d. Input / advance mechanism  [debugger-confirmed, for paging task #15]
Found via mednafen SS debugger (SHIFT+R read-watch on the pad global):
- **Pad global (raw, active-LOW): `0x060f2422` (high byte), `0x060f2423` (low byte).**
  Standard Saturn layout in the high byte: Right=0x80 Left=0x40 Down=0x20 Up=0x10
  Start=0x08 **A=0x04** C=0x02 B=0x01 (pressed = bit CLEAR). Confirmed via cheat search
  (Right -> 0x7F) and the debugger.
- **Input routine `FUN_060b20d4`** (read site PC **`060B2160`** = `mov.b @r1,r1`, r1=pad):
  reads raw, `not`s it -> **current (active-HIGH) at `0x060f2710`**; saves last frame's
  current to `0x060f2712` (prev); computes `current & ~prev` = **newly-pressed EDGE**,
  stored via `mov r1,@r3` with r3=`0x060f2302` (32-bit store; the A/dir/ABC edge byte
  should land at `0x060f2304`, A-edge=0x04). The dialogue ADVANCE reads this edge and
  accepts **A OR C** (probably Start too).
- **Why pad-consumption failed:** `FUN_060b20d4` is called **directly (BSR) from the
  dialogue path** (`0x060b1540 -> 0x060b20d4`; a pointer to it also exists at
  `0x060c5fcc` but that's a different caller). The VM computes AND checks the edge
  inside its own call chain, so a pre-frame hook at 0x472c (FUN_060b55a0) that clears
  the edge is either too early (VM recomputes) or outside the path. Clearing raw
  `0x060f2422` or edge byte `0x060f2304` in the frame-sync hook did NOT stop the advance.
- **Next step to consume the advance:** trampoline `FUN_060b20d4` (hook its return, or
  its caller `0x060b1540`) so our code runs AFTER the edge is computed and BEFORE the
  advance-check, and there mask the A/C/Start edge bits when a page is pending. THEN the
  still-unsolved second half: make the box re-display page 2 (redraw) — the deep VM part.
- Emulator gotchas learned: analog triggers mapped to Saturn L/R (`abs_4/abs_5`) rest as
  "held" -> Saturn boots to BIOS Memory Manager (unbind `ss.input.port1.gamepad.ls/rs`).
  Corrupt Saturn backup RAM (`~/.mednafen/sav/*.bkr/.bcr/.smpc`) also loops to BIOS.

## 6e. In-record dialogue paging — SOLVED  [PROVEN — plays through, no hang, default build/engine]
The whole point of the KEY+BLOB engine: show the FULL untruncated English, paging when
a line overflows the box. Working since 2026-08-06. Three pieces, all in `asm/full_hook.c`
+ `tools/build_engine.py` (paging is ON by default; disable with `NOPAGE=1`).

**1. `print_hook` — page through the game's OWN pipeline (no buffer poking).**
- The VM's dialogue-print command is a jump-table entry at **`0x060e4fb0`** (file `0x34fb0`)
  holding **`FUN_060b8390` = print_dialogue** (decode → lay text → typewriter → wait-for-A →
  return; there is no separate "wait" opcode). Repoint that entry to `print_hook`.
- `print_hook` just calls the original, then **loops it while decode reports pages pending**:
  `orig_print(); while(*pend && --guard>0) orig_print();`. Each call is a full, *synchronized*
  cycle in the VM's own context — so paging never touches the line buffer directly and never
  races VDP1. (Snatcher is SINGLE-CPU — the slave SH-2 is held in reset, so this is not a
  dual-CPU problem.)
- **[TRAP] Everything that pokes the line buffer async DEADLOCKS.** Writing `0x060f28aa`
  from the input hook, or copying page-2 over decode's out buffer, hangs the master spinning
  at `0x06000952` (a deliberate `mask-IRQ; bf self` panic stub reached via CPU-exception
  vectors). VDP1 is master-driven; async writes desync the frame-sync. Only the print
  pipeline is safe. Cost: ~2 days. Don't repeat.

**2. `decode()` is stateful — one page per call.** FRESH record: convert full text once,
split into `DLG_MAXROWS`-row pages *in place* (¥ = `0x81 0x8f`), cache each page-start ptr;
serve page 0. CONTINUING (same record ptr while pending): return the next cached page. Scratch
above the payload: g_lastrec `0x060fffd8`, pending `0x060fffe4`, pageidx `0x060fffe8`, npages
`0x060fffb0`, page ptrs[8] `0x060fffb4`.

**3. Safe geometry — COLS=20, MAXROWS=2, row0_geom.**
- **COLS=20** (not 26 — 26 hangs, §6b). **MAXROWS=2** always: the box is 4 rows (row 0 =
  speaker, rows 1-2 = body, row 3 = margin). A 3-row body fills the box and the game reflows
  it into a broken rows-{0,2,3}-with-a-gap layout AND drops the speaker. 2 is safe+clean;
  paging shows the rest.
- **`row0_geom` — row-0 pitch by speaker presence.** print_dialogue's own row-0 X loop
  (file `0x8406..0x841d`, 24 bytes) hardcodes a **14px** pitch (right for FULL-WIDTH Japanese
  speaker names, but it stretches HALF-WIDTH English badly when a no-speaker line's body lands
  in row 0). Patch replaces that loop with a trampoline `jsr row0_geom; bra 0x841e`, and
  `row0_geom()` picks pitch from the speaker flag **`0x060f2aae`**: set → 14px (X start 9),
  clear → 8px (X start `0x13`, matching body rows). Menus use a DIFFERENT render path and are
  NOT covered by this (see §8 menu note / open problems).
- Residual cosmetic: 20/row + 2-row pages = shorter lines / more page-turns ("airy"). Legible;
  tightening would need a safe COLS between 21-25 (untested vs the 26 hang) or SegaCD-fit
  translations.

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
  truncated); only longer dialogue records keyed.
- **[PROVEN 2026-08-06 — REFRAME] The blob resolution is NOT the real menu problem.**
  The live chunk base is at **`0x060fd164`** (print_dialogue computes the record ptr as
  `r5 + *0x060fd164`). Savestate at the "About JUNKER" menu: `*0x060fd164 = 0x202e8000`,
  cached `g_text = 0x202e8001` — essentially identical. Menu option [0] "About JUNKER"
  arrives as a KEYED copy (`01 04 0c64 84ce`) and DOES resolve to the full English via
  the cached base. The truncation is purely the **menu LAYOUT**: render fn `0x060b95b8`
  lays options **2 columns × 4 rows, 10 cells per column** (line buffer shows
  `|About JUNK|About Navi|`), so any label >10 chars is cut to 10 regardless of decode.
- **Menu render is type-dispatched** at `0x060b9540` (jump table `0x060b9564`) to 6
  variants: `0x060b95b8, 0x060b9ec0, 0x060ba140, 0x060ba2c8, 0x060ba418, 0x060ba69c`.
  Option count = `*0x060fd0c0`. `0x060b95b8` position math (0x9662–0x968e):
  `row=(i&3)`, `col=(i&4)`, offset `= 0x3fa + (i&3)*80 + ((i&4)?40:0)`.
- **Chosen fix (task #14): WIDEN the engine to 1-column** (full ~20-char row) + scrolling
  for >4 options — no translation edits. Diag build `build/engine_menudiag` (env
  `DIAG_MENU=1`) logs each menu-path decode (copy-buffer p in `0x060fac60..0x060fb060`)
  to a ring at **`0x060fff60`**: `[0]`=chunk base, `[1]`=hit count, `[2+i*2]`=copy[0:4],
  `[3+i*2]`=copy[4:8] per option i. Keyed option → copy[0:4]=`01 04 <roff:2>`.

## 9. Open problems (honest status)
1. **h1-load hypothesis** (§7) — confirm in-emulator.
2. **64 KB text-section cap** for big chunks under KEY+BLOB.
3. **English speaker names** — need a verified-safe RAM address (NOT `0x060E71F0`).
4. **Menu slot overflow** — a longer English menu option may visually overrun its fixed
   column slot even when the text fits; layout not yet handled.
