# Handoff: build the scene-VM control-flow tracer

Goal of the next work session: enable **complete, untruncated English** by building a
tracer that locates the relative-jump/block varints so the text-growth reassembler can
fix them. Everything up to this is done (translation 100%, speaker names EN, tokenizer exact).

## The problem in one paragraph
Saturn Snatcher scene text is stored **inline** in per-scene VM bytecode (DATA.BIN chunks
21–98, raw/uncompressed). English is ~2× the bytes of Japanese, so the current build
truncates each line to the JP byte budget. Growing a line shifts everything after it, which
breaks the VM's **relative varint jump/block distances** that span the growth point → garbled
scenes (proven twice in-emulator). Grown text itself renders fine (also proven). So the fix
is: grow text + add the growth delta δ to every jump/block varint whose span crosses the
growth point. The blocker is *finding* those varints.

## Verified facts (don't re-derive)
- Tokenizer `tools/vm_disasm.py`: 100% real-text alignment, 78/78 chunks round-trip byte-exact.
  Token length is by leading-byte class; `0x00`=1-byte separator; `<0x80`=2-byte text token
  (value = 0x10100 − SJIS).
- Jump/skip primitive **FUN_060c0908**: reads a varint, `cursor += distance`. Varint: `b≤0xBF`
  → 1 byte; else 2 bytes = `(b-0xC0)*256 + next` (bias 0xFF40 = −0xC0).
- Length-prefixed blocks **FUN_060c3650 / FUN_060c3758**: same varint = body length; run
  body while `cursor < start+length`.
- `0x060FD164` is a CHARACTER-PROPERTY table (used by text reader FUN_060c08b0), NOT jumps.
- Jump/block varints are consumed **behind multi-level dispatch** — a linear scan finds them
  at 0% (tried: right after opcode, and after tokenized length). Secondary handler tables:
  `0x060c29f0, 0x060c34d0, 0x060c3efc, 0x060c3fbc`. Handlers that call the jump primitive:
  `0x60c2858, 0x60c2ac4, 0x60c2b28, 0x60c3650, 0x60c3758, 0x60c1350`.

## The build
Write a **scene-VM control-flow tracer** (Python) that interprets a chunk's bytecode the way
the game does: step opcodes through the dispatch, and record every varint the jump/block
primitives read, plus its file offset and span (source→target). It does NOT need graphics/
sound/game-state — only control flow + operand consumption. Reference the decompile at
`analysis/ghidra_out/MAIN_L_all.c` (local; not in the public repo) for each opcode handler's
operand behavior. Start from the 6 jump-emitting handlers above and the dispatch tables.

## Self-validation (no emulator needed for the analysis)
Correct decoding ⇒ **every jump target and block end lands on a token boundary** produced by
`vm_disasm.tokenize()`, across all 78 chunks. Iterate to ~100%. (Same self-check that took
the tokenizer 24%→100%.)

## Then the reassembler
`tools/reassemble.py`: given {text_offset: english_tokens}, grow each run, add δ to every
jump/block varint whose span crosses the growth, handle the varint 1→2-byte cascade to a
fixpoint. Round-trip invariant: no growth ⇒ output == input, byte-for-byte.

## Boot-test loop (the only step needing the human)
Build `build/reasm_test` with chunk_022's greeting grown to "WELCOME TO JUNKER HEADQUARTERS."
within its ~1482-byte sector slack (patch DATA.BIN sector 58 + index size_words at MAIN_L
0x362F4+22*4; see `tools/build_full_patch.py` and `tools/patch_speakers.py` for sector-write
mechanics). User boots `mednafen "build/reasm_test/Snatcher (Japan).cue"` and confirms: grown
greeting shows AND scene flows (menu, later dialogue) with no garble.

## Repo / assets
- Public repo: github.com/mholzinger/snatcher-segacd-to-saturn-eng (no copyrighted data).
- Local-only (gitignored): `iso/`, `extracted/`, `build/`, `analysis/ghidra_out/`, `ghidra/`.
- Full history/state: `analysis/findings.md`. Translation source of truth: `translation/master.json`.
- Ghidra 11.2.1 at `~/src/kyocera-2235/ghidra_11.2.1_PUBLIC/`. SH-2 reference: `reference/`.
- Mednafen boots with Hi-Saturn BIOS (persisted in ~/.mednafen/mednafen.cfg).
