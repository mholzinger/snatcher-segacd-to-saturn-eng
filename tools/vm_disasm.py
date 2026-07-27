#!/usr/bin/env python3
"""Verified tokenizer/disassembler for Saturn Snatcher scene bytecode.

Length table derived from the operand fetcher FUN_060c0c78 (MAIN_L.BIN) and its
byte-consuming sub-functions. All three apparent "cursors" (DAT_060c0de0,
DAT_060c08f8/08a4, DAT_060c101c) resolve to the SAME address 0x060FC8B0 — one
linear stream. FUN_060c103c == FUN_060c0c78 (self-recursion): arithmetic opcodes
are 1 byte and their operands are simply the following tokens, so a linear walk
is correct.

VERIFIED LENGTH TABLE (bytes consumed, including the leading opcode byte):
  b < 0x80          -> 2   TEXT token   (value = 0x10100 - SJIS), via FUN_060c08b0 (reads 2)
  0x80-0x9F         -> 3   24-bit operand, via FUN_060c085c (reads 3)
  0xA0-0xAF         -> 2   12-bit immediate (op&0xF)<<8 | next
  0xB0-0xBF         -> 2   12-bit immediate
  0xC0-0xCF         -> 2   12-bit + action (FUN_060c0df4)
  0xD0-0xDF         -> 1   4-bit immediate (op&0xF)
  0xE0+             -> per sub-code (op-0xE0) below
E-subcode lengths (from the switch in FUN_060c0c78):
  E0:2 E1:3 E2:5 E3:3 E4:5 E5:1 E6:2 E7:2 E8:1 E9:1 EA:1 EB:1 EC:1 ED:1 EE:2 EF:2
  F0:1 F1:1 F2..FD:1 (binary ops, operands follow as tokens) FE:1 FF:1

Also: 0x00 is a 1-byte separator/terminator (NOT a 2-byte text token) — this was
the key fix that took alignment from 24% to 100%.

VERIFIED (chunks 21-98): walking from offset 0, 100% of real text runs (>=6 chars,
10915/10915) land on a token boundary and classify TEXT; 99% of ALL offsets incl.
the 2-char extractor false-positives (12725/12836). Gap test (resync at each text
run, tokenize bytecode to next run): 10879/10879 land exactly.

OFFSET/JUMP OPERANDS (for the future relocating reassembler): NOT simple inline
values. The <0x80 "text" tokens double as table indices (FUN_060c08b0 does
CONCAT11(hi,lo)*2 into a runtime label table at 0x060FD164), so jump targets appear
to be indirected through a per-chunk label table, not inline offsets. E1/E2/E3/E4
embedded values are only 18-41% valid in-chunk offsets (i.e. mostly immediates, not
jumps). The chunk header is NOT a clean offset table (only 3 ascending entries).
=> Next investigation before a reassembler: locate/decode the label table that the
<0x80 index tokens resolve against; relocation likely updates THAT table (tractable,
pointer-table style) rather than fixing inline offsets.
"""
import json
import os
import struct

E_LEN = {0x0:2,0x1:3,0x2:5,0x3:3,0x4:5,0x5:1,0x6:2,0x7:2,0x8:1,0x9:1,
         0xA:1,0xB:1,0xC:1,0xD:1,0xE:2,0xF:2}


def toklen(b):
    """Bytes consumed by the token whose leading byte is b, and its kind."""
    if b == 0x00:
        return 1, 'nul'          # 1-byte separator/terminator (not a text token)
    if b < 0x80:
        return 2, 'text'
    if b & 0xE0 == 0x80 and b < 0xA0:
        return 3, 'op80'
    c = b & 0xF0
    if c == 0xA0: return 2, 'a0'
    if c == 0xB0: return 2, 'b0'
    if c == 0xC0: return 2, 'c0'
    if c == 0xD0: return 1, 'd0'
    return E_LEN.get(b - 0xE0, 1), f'e{b-0xE0:x}'


def tokenize(d):
    """Return list of (offset, length, kind). Walks the whole chunk linearly."""
    toks = []
    i = 0
    n = len(d)
    while i < n:
        ln, k = toklen(d[i])
        if i + ln > n:
            ln = n - i           # trailing padding / truncated final token
            k = 'pad'
        toks.append((i, ln, k))
        i += ln
    return toks


# ---- validation -----------------------------------------------------------
def _load_script():
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    return json.load(open(os.path.join(root, 'extracted/script/saturn_script.json')))


def validate(verbose=False):
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    script = _load_script()
    tot = aligned = astext = 0
    rt_ok = rt_total = 0
    worst = []
    for idx in range(21, 99):
        p = os.path.join(root, f'extracted/saturn/data_bin/chunk_{idx:03d}.bin')
        if not os.path.exists(p):
            continue
        d = open(p, 'rb').read()
        toks = tokenize(d)
        # round-trip: token spans must exactly tile [0, len)
        rebuilt = b''.join(d[o:o+ln] for o, ln, k in toks)
        rt_total += 1
        rt_ok += (rebuilt == d)
        starts = {o: k for o, ln, k in toks}
        known = [e['offset'] for e in script.get(f'chunk_{idx:03d}', [])]
        a = sum(1 for o in known if o in starts)
        t = sum(1 for o in known if starts.get(o) == 'text')
        tot += len(known); aligned += a; astext += t
        if verbose and known and a < len(known):
            miss = sorted(o for o in known if o not in starts)
            worst.append((idx, len(known) - a, hex(miss[0]) if miss else None))
    print(f"text offsets: {tot} | on boundary: {aligned} ({100*aligned//tot}%) | "
          f"as text: {astext} ({100*astext//tot}%)")
    print(f"round-trip byte-identical: {rt_ok}/{rt_total} chunks")
    if verbose:
        for idx, n, first in sorted(worst, key=lambda x: -x[1])[:12]:
            print(f"  chunk_{idx:03d}: {n} misaligned, first miss @ {first}")


if __name__ == '__main__':
    import sys
    validate(verbose='-v' in sys.argv)


# ---- jump/block varint (verified from FUN_060c0908 / FUN_060c3650 / FUN_060c3758) ----
# Relative-distance varint used by the scene VM's jump/skip primitive and by
# length-prefixed blocks. Constants confirmed: threshold DAT_060c0950 = 0x00BF,
# bias DAT_060c0952 = 0xFF40 (= -0xC0 signed).
#   b <= 0xBF          -> distance = b            (1 byte)
#   b >  0xBF          -> distance = (b-0xC0)*256 + next   (2 bytes)
# After reading the varint the VM does: cursor += distance  (relative FORWARD skip);
# blocks run their body while cursor < body_start + length.
VARINT_THRESHOLD = 0xBF
def parse_varint(d, i):
    """Return (value, nbytes) for the jump/block varint at offset i."""
    b = d[i]
    if b <= VARINT_THRESHOLD:
        return b, 1
    return (b - 0xC0) * 256 + d[i + 1], 2

# NOTE (reassembler blocker, verified negative result 2026-07-27):
# The varint does NOT sit at a fixed position after the opcode byte or after the
# opcode's tokenized length. Empirical scan over chunks 21-98 under both placement
# hypotheses found ZERO opcodes whose computed jump target lands on a token boundary
# (>=90% rate). => jump/block varints are consumed at handler-specific points reached
# through the scene VM's MULTI-LEVEL dispatch (secondary handler tables at 0x060c29f0,
# 0x060c34d0, 0x060c3efc, 0x060c3fbc). Reliably locating spanning jumps therefore
# requires EMULATING the dispatch + operand fetcher (i.e. a scene-VM control-flow
# tracer), not a linear scan. That is the remaining work before growth-fixup is safe.
