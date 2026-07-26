#!/usr/bin/env python3
"""Decompress Saturn Snatcher DATA.BIN chunks.

Three-stream LZ (reverse-engineered from MAIN_L.BIN FUN_060cb548/FUN_060cb6fc):
  header: u32 BE decompressed size; u16 BE bit-stream length (in u32 words);
          u16 BE token-stream length (in u16 words)
  streams: bit flags (BE u32 words, consumed LSB-first), u16 BE match tokens,
           literal/aux bytes
  flag 0            -> literal byte from byte stream
  flag 1,1          -> short match: dist = byte+1, len = 2 more flag bits + 2
  flag 1,0 -> token t: t==0 -> end
                       t&0xF -> len=(t&0xF)+2, dist=(t>>4)+1
                       else  -> len=next byte, dist=t>>4

Usage: decompress_chunk.py <chunk.bin> [out.bin]
"""

import struct
import sys


def decompress(raw):
    size = struct.unpack_from(">I", raw, 0)[0]
    nbits_u32 = struct.unpack_from(">H", raw, 4)[0]
    ntok_u16 = struct.unpack_from(">H", raw, 6)[0]
    bit_off = 8
    tok_off = bit_off + nbits_u32 * 4
    byte_off = tok_off + ntok_u16 * 2

    bits_i, tok_i, byte_i = bit_off, tok_off, byte_off
    bitbuf = struct.unpack_from(">I", raw, bits_i)[0]
    bits_i += 4
    bitcnt = 32
    out = bytearray()

    def getbit():
        nonlocal bitbuf, bitcnt, bits_i
        b = bitbuf & 1
        bitbuf >>= 1
        bitcnt -= 1
        if bitcnt == 0:
            bitbuf = struct.unpack_from(">I", raw, bits_i)[0]
            bits_i += 4
            bitcnt = 32
        return b

    while len(out) < size:
        if getbit() == 0:
            out.append(raw[byte_i])
            byte_i += 1
            continue
        if getbit():  # short match
            dist = raw[byte_i] + 1
            byte_i += 1
            ln = (getbit() << 1 | getbit()) + 2
        else:
            t = struct.unpack_from(">H", raw, tok_i)[0]
            tok_i += 2
            if t == 0:
                break
            if t & 0xF:
                ln = (t & 0xF) + 2
                dist = (t >> 4) + 1
            else:
                ln = raw[byte_i]
                byte_i += 1
                dist = t >> 4
        for _ in range(ln):
            out.append(out[-dist])
    return bytes(out), size


if __name__ == "__main__":
    raw = open(sys.argv[1], "rb").read()
    out, size = decompress(raw)
    status = "OK" if len(out) == size else f"SHORT ({len(out)}/{size})"
    print(f"{sys.argv[1]}: {len(raw)} -> {len(out)} bytes [{status}]")
    if len(sys.argv) > 2:
        open(sys.argv[2], "wb").write(out)
