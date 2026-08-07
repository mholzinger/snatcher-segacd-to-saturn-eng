#!/usr/bin/env python3
"""Layout-safe clamp for the dialogue window (overflow stability fix).

The fill routine FUN_060b45c4 auto-wraps at col 20 but only the ¥-break path
guards row 4; the auto-wrap path does NOT, so English lines >20 chars auto-wrap
past the 80-cell buffer and corrupt scene state (garble + Go-Inside hang).

clamp_text() re-wraps ALL text to <=20-cell lines (no auto-wrap can occur) and
keeps only the first MAX_ROWS lines, so the fill routine never advances past the
safe window. Pure data — no engine patch. Long records clip (option 2: stability
over completeness). ＠color codes are 0-width; <br> forces a line; ▽ etc = 1 cell.
"""
ROW = 20
MAX_ROWS = 3   # safe for dialogue (fill starts row 1 -> rows 1..3 = cells 20..79)


def _tokens(s):
    """Yield ('color', '＠X') | ('br',) | ('word', text) tokens; spaces split words."""
    i, n = 0, len(s)
    while i < n:
        if s[i:i + 4] == "<br>":
            yield ("br",); i += 4; continue
        c = s[i]
        if c == "＠" and i + 1 < n:
            yield ("color", s[i:i + 2]); i += 2; continue
        if c in " 　":
            i += 1; continue
        j = i
        while j < n and s[j] not in " 　" and s[j:j + 4] != "<br>" and s[j] != "＠":
            j += 1
        yield ("word", s[i:j]); i = j


def _full(lines, max_rows):
    return max_rows is not None and len(lines) >= max_rows


def clamp_text(s, max_rows=MAX_ROWS, row=20):
    """Return `s` re-wrapped to <=`row`-cell lines, truncated to `max_rows` lines
    (max_rows=None -> unlimited, for the scroll build).
    Color codes carry no width and stick to the following word."""
    lines = [""]          # rebuilt text per line (may include ＠codes)
    widths = [0]          # visible cell count per line
    pending_color = ""    # color code(s) waiting to attach to next word
    for tok in _tokens(s):
        if tok[0] == "color":
            pending_color += tok[1]
            continue
        if tok[0] == "br":
            if _full(lines, max_rows):
                break
            lines.append(pending_color); widths.append(0); pending_color = ""
            continue
        w = tok[1]
        need = len(w)
        # long word longer than a row: hard-split it
        while need > row:
            if widths[-1] != 0:
                if _full(lines, max_rows):
                    return _join(lines)
                lines.append(""); widths.append(0)
            take = row
            lines[-1] += pending_color + w[:take]; pending_color = ""
            widths[-1] = take
            w = w[take:]; need = len(w)
            if _full(lines, max_rows) and need:
                return _join(lines)
            if need:
                lines.append(""); widths.append(0)
        # normal word: fit on current line or wrap
        sep = 1 if widths[-1] > 0 else 0
        if widths[-1] + sep + need > row:
            if _full(lines, max_rows):
                break
            lines.append(""); widths.append(0); sep = 0
        if sep:
            lines[-1] += " "; widths[-1] += 1
        lines[-1] += pending_color + w; widths[-1] += need; pending_color = ""
    return _join(lines)


def _join(lines):
    return "<br>".join(l for l in lines).rstrip()


if __name__ == "__main__":
    import json, sys
    sys.path.insert(0, "tools")
    import reassemble, build_full_en2 as B
    master = json.load(open("translation/master.json"))
    # validate: after clamp, every record lays out to <= MAX_ROWS rows of <=20
    def rows_of(s):
        r = 1; col = 0; i = 0
        while i < len(s):
            if s[i:i + 4] == "<br>": r += 1; col = 0; i += 4; continue
            if s[i] == "＠" and i + 1 < len(s): i += 2; continue
            col += 1
            if col > ROW: r += 1; col = 1
            i += 1
        return r, max((len(x) for x in s.split("<br>")), default=0)
    bad = 0; samples = []
    for e in master:
        en = e.get("en")
        if not en: continue
        c = clamp_text(B.wrap(en))
        r, maxlen = rows_of(c)
        # strip ＠codes for the width check
        if r > MAX_ROWS:
            bad += 1
            if len(samples) < 5: samples.append((r, en[:40], c[:60]))
    print(f"records clamped; violations (>{MAX_ROWS} rows): {bad}")
    for r, o, c in samples:
        print(f"  {r} rows  orig={o!r}  clamped={c!r}")
    # show the JUNKER record before/after
    for e in master:
        if e["chunk"] == "chunk_022" and e["offset"] == "0x36b5":
            print("\nJUNKER 0x36b5:")
            print("  before:", repr(B.wrap(e["en"])))
            print("  after :", repr(clamp_text(B.wrap(e["en"]))))
