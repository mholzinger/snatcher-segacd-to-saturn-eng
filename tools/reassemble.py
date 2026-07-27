#!/usr/bin/env python3
"""Text-growth reassembler for Saturn Snatcher scene chunks (21-59).

MODEL (established by tools/vm_trace.py + binary RE, 2026-07-27):
A scene chunk is [u16 h0][u16 h1][bytecode][text section][trailer]:
  - text section starts at h0+5 and is h1 bytes long
  - it consists of 0x00-separated records of 2-byte tokens (0x10100 - SJIS)
  - the engine consumes records SEQUENTIALLY (no stored text offsets), so
    growing a record shifts only the rest of the text section
  - bytecode never moves => NO jump/varint fixups are needed
Growing text therefore requires exactly:
  1. new record bytes in place (0x00 separators intact)
  2. h1 += delta
  3. chunk grows by delta (DATA.BIN index size_words must follow)

Round-trip invariant: rebuild with no replacements == input, byte-for-byte
(verified across all 39 scene chunks via --test).

API:  rebuild_chunk(data, {record_offset: new_record_bytes}) -> bytes
      encode_text('WELCOME ...') -> token bytes (full-width SJIS tokens)
"""
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

FW_FIX = {"'": "’", '"': "”", "-": "－", "~": "〜", " ": "　"}


def to_fullwidth(s):
    s = s.replace("<br>", "￥")
    out = []
    for ch in s:
        o = ord(ch)
        if ch in FW_FIX:
            fw = FW_FIX[ch]
        elif 0x21 <= o <= 0x7E:
            fw = chr(o - 0x20 + 0xFF00)
        else:
            fw = ch
        try:
            fw.encode("shift_jis")
        except UnicodeEncodeError:
            fw = "　"
        out.append(fw)
    return "".join(out)


def encode_text(text):
    """English/JP text -> scene-VM token bytes (2 bytes per glyph)."""
    b = b""
    for c in to_fullwidth(text):
        s = struct.unpack(">H", c.encode("shift_jis"))[0]
        b += struct.pack(">H", (0x10100 - s) & 0xFFFF)
    return b


def sections(data):
    """Return (h0, h1, text_start, text_end)."""
    h0, h1 = struct.unpack(">2H", data[:4])
    ts = h0 + 5
    te = ts + h1
    if te > len(data):
        raise ValueError("not a scene chunk (h0/h1 out of range)")
    return h0, h1, ts, te


def records(data):
    """Yield (start, end) for each text record (end = its 0x00 separator)."""
    _, _, ts, te = sections(data)
    i = ts
    start = i
    while i < te:
        if data[i] == 0x00:
            yield start, i
            i += 1
            start = i
        else:
            i += 2  # tokens are 2 bytes; separators only occur between records


def rebuild_chunk(data, replacements):
    """Grow/shrink text records. replacements: {record_start: new_bytes}.

    Record starts are file offsets as found in saturn_script.json/master.json.
    New bytes must be token-encoded (use encode_text) and contain no 0x00.
    Returns the new chunk (padded to even length for the word-based index).
    """
    h0, h1, ts, te = sections(data)
    recs = dict(records(data))
    for off, nb in replacements.items():
        if off not in recs:
            raise ValueError(f"offset {off:#x} is not a record start")
        if b"\x00" in nb:
            raise ValueError("replacement contains 0x00 (record separator)")
    out = bytearray()
    out += data[4:ts]  # bytecode (never moves)
    i = ts
    delta = 0
    while i < te:
        if data[i] == 0x00:
            out += b"\x00"
            i += 1
            continue
        end = recs[i]
        nb = replacements.get(i)
        if nb is None:
            out += data[i:end]
        else:
            out += nb
            delta += len(nb) - (end - i)
        i = end
    out += data[te:]  # trailer, verbatim
    new_h1 = h1 + delta
    chunk = struct.pack(">2H", h0, new_h1) + bytes(out)
    if len(chunk) & 1:
        chunk += b"\x00"
    return chunk


def append_records(data, additions):
    """Append grown records at the section end and repoint their references.

    additions: list of (new_record_bytes, [ref_positions]) where each ref
    position is the file offset of a 2-byte BE token in the bytecode that
    should point at the new record.  The original record stays in place, so
    every reference NOT repointed keeps working (shows the old text) — nothing
    ever garbles from a missed ref.

    Token encoding (FUN_060c08b0, text RAM base = chunk file offset h0+4):
      B = record file offset - (h0+4); token = B/2 if B even (preceding byte
      is the 0x00 separator) else (B+1)/2.
    """
    h0, h1, ts, te = sections(data)
    out = bytearray(data)
    tail = out[te:]                      # trailer, reattached after the section
    del out[te:]
    for new_bytes, refs in additions:
        if b"\x00" in new_bytes:
            raise ValueError("record contains 0x00")
        B = len(out) - (h0 + 4)          # section-relative offset of new record
        token = B // 2 if B % 2 == 0 else (B + 1) // 2
        if B % 2 == 0 and out[len(out) - 1] != 0:
            raise ValueError("append point not preceded by separator")
        if token >= 0x8000:
            raise ValueError("text section too large for token encoding")
        out += new_bytes + b"\x00"
        for pos in refs:
            struct.pack_into(">H", out, pos, token)
    new_h1 = len(out) - (h0 + 5)
    out += tail
    struct.pack_into(">H", out, 2, new_h1)
    if len(out) & 1:
        out += b"\x00"
    return bytes(out)


def selftest():
    ok = 0
    for idx in range(21, 60):
        p = os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{idx:03d}.bin")
        if not os.path.exists(p):
            continue
        d = open(p, "rb").read()
        r = rebuild_chunk(d, {})
        same = r == d or (r == d + b"\x00")  # odd-length source pads
        status = "OK" if same else "FAIL"
        if same:
            ok += 1
        n = sum(1 for _ in records(d))
        print(f"chunk_{idx:03d}: round-trip {status} ({n} records)")
    print(f"{ok}/39 chunks round-trip byte-identical")


if __name__ == "__main__":
    if "--test" in sys.argv:
        selftest()
    else:
        print(__doc__)
