# Translation QA Notes — items to reconcile before final build

Running list of cross-cutting concerns flagged by translation agents. Resolve during
the glossary-consistency sweep + in-game testing (Phase 5).

## Gameplay-logic risks (verify in emulator)
- **Answer-matching puzzles**: Napoleon's password quiz (chunk_028, 0x258e–0x2730) and the
  Konami trivia quiz (chunk_045) present selectable answer strings. SAFE to translate IF the
  engine keys the correct answer on option index/position, not on matching the displayed text.
  Verify in-game before trusting. If any puzzle uses free-text input matching, those strings
  need special handling.
- **OLEEN/QUEEN neon puzzle** (chunk_047): the wordplay depends on a broken-neon visual
  ("QUEEN" reads as "OLEEN"). English kept the gag via Queen/Oleen romanization — verify it
  still reads on screen.

## Name / term spellings to standardize (add to GLOSSARY.md once decided)
- Hospital: "Queen Hospital" vs "Ohrin/Oleen Hospital" (オウリン病院) — pick one.
- ネオ・コウベ薬研 → "Neo Kobe Pharmaceutical Lab" (proposed).
- 大惨事 → "the Catastrophe" (Neo Kobe backstory event) — proposed canonical.
- スノースギ → "Snow Cedar" (fictional plant/scent) — proposed.
- Random Hajile / "Elijah" (エリア) vs "Elia" — reverse-reading gimmick; pick spelling (021).
- **Benson Cunningham** (chunk_024): possible conflation of Harry Benson + Chief Cunningham —
  check the source line; the chief is Cunningham, Benson is Harry. Likely needs fixing.

## Extractor noise (harmless, kept verbatim)
- Occasional garbage-kanji lines (e.g. 021 none; 023 0x14c7; 029 0x105b/0x1d4e/0x2651;
  028 0x0c4a; 055 0x06ac) are false positives from the 3-char SJIS extractor threshold.
  Not player-facing. Optional: tighten extractor later.
- `数…` lines (chunk_028): videophone number DATA rows; `数` = display marker. Confirm keep/strip.
- `＠Ｃ` and `ω` are engine control codes — always preserve, never translate.
