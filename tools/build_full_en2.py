#!/usr/bin/env python3
"""Full-corpus English build v2 — growth-based (untruncated), disc-layout rebuild.

Per scene chunk (21-59):
  - lines whose full-width EN fits the JP record: overwritten IN PLACE (padded)
  - longer lines: EN record is DEDUPED and placed either in a DEAD SLOT (the JP
    record of another re-homed line) or APPENDED at the text-section end; all of
    that line's reference tokens are repointed (say-line pattern scan + vm_trace
    text-token positions). Repointing verifies the old token bytes first.
  - lines with no findable reference, or that would push the section past the
    64KB token-address limit, KEEP their original JP text (graceful).

Disc rebuild:
  - chunks laid out sequentially -> new 639-entry index; DATA.BIN grows by
    delta sectors; every ISO fs extent >= 5451 (MAIN_L onward, including
    track-2/3 files) is shifted by delta; PVD volume size updated
  - MAIN_L.BIN gets the new chunk index + English speaker table, then is
    written at its shifted location
  - all sectors >= LBA 96 get fresh MODE1 headers (sync + BCD MSF); EDC/ECC
    regeneration is deferred (Mednafen ignores it; real hardware needs it later)

Usage: build_full_en2.py [out_dir]     (default build/full_en2)
"""
import json
import os
import re
import struct
import sys

import subprocess

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble
import vm_trace
import patch_speakers as spk
import sh2_inject
import layout_clamp

FONT = os.environ.get("FONT", "1") == "1"   # inject the half-width font renderer
FRAME_PTR = 0x472c                          # frame-sync fn-ptr literal (MAIN_L file offset)


def compile_renderer(load_addr):
    """Compile asm/font_render.c (frame() only) linked at load_addr; return
    (bytes, frame_addr). The 2-byte native text puts full-width SJIS in the line
    buffer, which frame() maps to our half-width glyphs."""
    import tempfile
    MARS = os.environ.get("MARSDEV", "/Users/mikeholzinger/src/marsdev/mars") + "/sh-elf/bin"
    with tempfile.TemporaryDirectory() as td:
        o, elf, binf, ld = (os.path.join(td, x) for x in ("d.o", "d.elf", "d.bin", "d.ld"))
        open(ld, "w").write(
            "ENTRY(_frame)\nSECTIONS { . = %#x; "
            ".text : { *(.text.frame) *(.text*) *(.rodata*) } }\n" % load_addr)
        subprocess.run([os.path.join(MARS, "sh-elf-gcc"), "-m2", "-O2", "-ffreestanding",
                        "-fno-builtin", "-fomit-frame-pointer", "-c",
                        os.path.join(ROOT, "asm/font_render.c"), "-o", o,
                        "-I", os.path.join(ROOT, "asm")], check=True)
        subprocess.run([os.path.join(MARS, "sh-elf-ld"), "-T", ld, "-o", elf, o],
                       check=True, stderr=subprocess.DEVNULL)
        nm = subprocess.run([os.path.join(MARS, "sh-elf-nm"), elf], capture_output=True, text=True).stdout
        addr = next(int(l.split()[0], 16) for l in nm.splitlines() if l.split()[-1] == "_frame")
        assert addr == load_addr, f"_frame at {addr:#x} != {load_addr:#x}"
        subprocess.run([os.path.join(MARS, "sh-elf-objcopy"), "-O", "binary", elf, binf], check=True)
        return open(binf, "rb").read(), addr

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR = 2352
USER = 16
DATA_LBA = 96
MAIN_LBA = 5451
INDEX_OFF = 0x362F4
N_CHUNKS = 639
SECT_LIMIT = 0xFFFF          # max text-section size addressable by tokens
FILLER = 0x11                # dead-slot residue (never referenced)

SRC = os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")


def wrap(en):
    # Clamp to <=3 dialogue rows: the fill routine's auto-wrap doesn't guard row 4,
    # so >3-row text overflows the line buffer and hangs (the JUNKER-explanation
    # crash). clamp_text re-wraps to 20 cols AND caps rows (stable, proven fix).
    return layout_clamp.clamp_text(en, max_rows=3, row=20)


def token_for(B):
    return B // 2 if B % 2 == 0 else (B + 1) // 2


def find_refs(d, code_end, h0, tracer_tokens):
    """Map record file offset -> list of token positions referencing it."""
    refs = {}
    # say-line pattern: c0 01 a0 XX <token>
    for m in re.finditer(rb"\xc0\x01\xa0.", d[4:code_end], re.S):
        pos = 4 + m.start() + 4
        if pos + 2 > code_end:
            continue
        tok = struct.unpack(">H", d[pos:pos + 2])[0]
        if tok < 0x8000:
            refs.setdefault(tok, set()).add(pos)
    for pos in tracer_tokens:
        tok = struct.unpack(">H", d[pos:pos + 2])[0]
        refs.setdefault(tok, set()).add(pos)
    return refs


def batch_chunk(d, jobs, stats):
    """Apply [(record_off, en)] to one chunk. Returns new chunk bytes.

    v3 SAFE MODE: voiced lines (any say-call with mode 4/5 referencing the
    record) are only replaced IN PLACE (positions unchanged keeps the
    companion sync-chunk keys valid); appends are limited to unvoiced/menu
    lines; dead slots are never reused (original records stay intact as the
    fallback for every untouched reference)."""
    h0, h1, ts, te = reassemble.sections(d)
    recs = dict(reassemble.records(d))
    t = vm_trace.Tracer(d)
    t.trace_entry()
    refmap = find_refs(d, ts, h0, t.text_tokens)
    voiced_toks = set()
    for m in re.finditer(rb"\xc0\x01\xa0[\x04\x05]", d[4:ts], re.S):
        pos = 4 + m.start() + 4
        if pos + 2 <= ts:
            v = struct.unpack(">H", d[pos:pos + 2])[0]
            if v < 0x8000:
                voiced_toks.add(v)

    out = bytearray(d)
    tail = bytes(out[te:])
    del out[te:]

    # classify
    appends = []                     # (off, enc, jl)
    for off, en in jobs:
        if off not in recs:
            stats["skip_norec"] += 1
            continue
        jl = recs[off] - off
        enc = reassemble.encode_text(wrap(en))
        if len(enc) <= jl:
            pad = (jl - len(enc)) // 2
            filled = enc + reassemble.encode_text(" " * pad)
            filled += b"\x00" * (jl - len(filled))          # odd residue
            out[off:off + jl] = filled
            stats["inplace"] += 1
            continue
        B = off - (h0 + 4)
        tok = token_for(B)
        if not refmap.get(tok):
            stats["noref"] += 1
            continue
        if tok in voiced_toks:
            stats["voiced_jp"] += 1
            continue
        if any(t == tok for _, __, ___, t in appends):
            stats["tokclash"] += 1
            continue
        appends.append((off, bytes(enc), jl, tok))

    # dedupe content
    contents = {}                    # enc -> [(off, jl, tok)]
    order = []
    for off, enc, jl, tok in appends:
        if enc not in contents:
            order.append(enc)
        contents.setdefault(enc, []).append((off, jl, tok))

    placed = {}                      # enc -> new record file offset
    free_slots = []                  # (jl, off) of re-homed lines
    # phase 1: append at end (scene order) within the 64KB token budget
    for enc in order:
        new_h1 = (len(out) - (h0 + 5)) + len(enc) + 1
        if new_h1 <= SECT_LIMIT:
            placed[enc] = len(out)
            out += enc + b"\x00"
            for off, jl, tok in contents[enc]:
                free_slots.append((jl, off))
    # (v3: no dead-slot reuse — original records must stay intact because the
    # voiced pipeline and companion sync chunks reference them by position)
    # repoint every reference of every placed line
    repoints = []                    # (pos, oldtok, newtok)
    for enc, group in contents.items():
        if enc not in placed:
            stats["overflow"] += len(group)
            continue
        B = placed[enc] - (h0 + 4)
        newtok = token_for(B)
        for off, jl, tok in group:
            ok = False
            for pos in refmap[tok]:
                cur = struct.unpack(">H", out[pos:pos + 2])[0]
                if cur == tok:
                    struct.pack_into(">H", out, pos, newtok)
                    repoints.append((pos, tok, newtok))
                    ok = True
            if ok:
                stats["appended"] += 1
            else:
                stats["refgone"] += 1
    new_h1 = len(out) - (h0 + 5)
    assert new_h1 <= SECT_LIMIT
    out += tail
    struct.pack_into(">H", out, 2, new_h1)
    if len(out) & 1:
        out += b"\x00"
    # structural-equivalence guard: a repoint that changed the PARSE hit bytes
    # that were not really a text token; revert the culprit and re-check.
    def structure(data):
        tt = vm_trace.Tracer(bytes(data))
        tt.trace_entry()
        return tt.boundaries
    ref_struct = {k: set(v) for k, v in t.boundaries.items()}
    for _round in range(200):
        cur = structure(out)
        first = None
        for ctx in ("stmt", "wait", "disp"):
            d1 = ref_struct[ctx] ^ cur[ctx]
            if d1:
                m = min(d1)
                first = m if first is None else min(first, m)
        if first is None:
            break
        culprits = [r for r in repoints if r[0] <= first + 2]
        if not culprits:
            break
        pos, oldtok, newtok = max(culprits, key=lambda r: r[0])
        struct.pack_into(">H", out, pos, oldtok)
        repoints.remove((pos, oldtok, newtok))
        stats["reverted"] = stats.get("reverted", 0) + 1
    return bytes(out)


def patched_main_l(index_entries):
    """MAIN_L.BIN with new chunk index + English speaker table."""
    d = bytearray(open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read())
    for i, (sec, words) in enumerate(index_entries):
        struct.pack_into(">HH", d, INDEX_OFF + i * 4, sec, words)
    # speaker names (logic from patch_speakers.py)
    ptrs = [struct.unpack_from(">I", d, spk.TABLE - spk.BASE + i * 4)[0] for i in range(80)]
    blob = bytearray()
    new_ptrs = list(ptrs)
    cursor = spk.FREE
    for i, en in spk.NAMES.items():
        raw = bytes(d[ptrs[i] - spk.BASE:])
        raw = raw[:raw.index(b"\x00")]
        prefix, suffix = spk.split_wrapper(raw)
        s = prefix + spk.to_fw_sjis(en) + suffix + b"\x00"
        new_ptrs[i] = cursor
        blob += s
        cursor += len(s)
    assert len(blob) <= spk.FREE_LEN
    d[spk.FREE - spk.BASE:spk.FREE - spk.BASE + len(blob)] = blob
    struct.pack_into(">" + "I" * 80, d, spk.TABLE - spk.BASE, *new_ptrs)
    return bytes(d)


def mode1_header(lba):
    m = lba + 150
    mm, rem = divmod(m, 75 * 60)
    ss, ff = divmod(rem, 75)
    bcd = lambda v: ((v // 10) << 4) | (v % 10)
    return b"\x00" + b"\xff" * 10 + b"\x00" + bytes([bcd(mm), bcd(ss), bcd(ff), 1])


def main():
    out_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/full_en2")
    os.makedirs(out_dir, exist_ok=True)

    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    by_chunk = {}
    for e in master:
        if e.get("en"):
            by_chunk.setdefault(int(e["chunk"].split("_")[1]), []).append(
                (int(e["offset"], 16), e["en"]))

    stats = {k: 0 for k in ("inplace", "appended", "noref", "overflow",
                            "skip_norec", "refgone", "tokclash", "voiced_jp")}
    chunks = []
    for i in range(N_CHUNKS):
        p = os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{i:03d}.bin")
        d = open(p, "rb").read()
        jobs = sorted(by_chunk.get(i, []))
        if jobs and 21 <= i <= 59:
            try:
                d = batch_chunk(d, jobs, stats)
                print(f"chunk_{i:03d}: {len(d)} bytes "
                      f"(cum: inplace {stats['inplace']} appended {stats['appended']} "
                      f"noref {stats['noref']} overflow {stats['overflow']})")
            except Exception as ex:
                print(f"chunk_{i:03d}: FAILED ({ex}) — keeping original")
        chunks.append(d)

    # sequential layout -> index + new DATA.BIN image
    entries = []
    datab = bytearray()
    for d in chunks:
        sec = len(datab) // 2048
        entries.append((sec, len(d) // 2))
        datab += d
        if len(datab) % 2048:
            datab += b"\x00" * (2048 - len(datab) % 2048)
    new_secs = len(datab) // 2048
    delta = new_secs - (MAIN_LBA - DATA_LBA)
    print(f"DATA.BIN: {new_secs} sectors (delta {delta:+d}); "
          f"totals {stats}")

    main_l = patched_main_l(entries)

    # inject the font renderer -> MAIN_L grows by main_delta; files after it shift
    # by (delta + main_delta). DATA.BIN's own growth is `delta` (already computed).
    orig_main_secs = (sh2_inject.MAIN_L_END + 2047) // 2048
    if FONT:
        payload, frame_addr = compile_renderer(sh2_inject.RESIDENCY)
        main_l = sh2_inject.grow_main_l(
            main_l, payload, hooks=[(FRAME_PTR, struct.pack(">I", frame_addr))])
        print(f"font renderer: payload {len(payload)}B @ {sh2_inject.RESIDENCY:#x}; "
              f"frame() @ {frame_addr:#x}; ptr 0x{FRAME_PTR:x} repointed")
    main_secs = (len(main_l) + 2047) // 2048
    main_delta = main_secs - orig_main_secs
    total_delta = delta + main_delta

    src_t1 = os.path.join(SRC, "Snatcher (Japan) (Track 1).bin")
    dst_t1 = os.path.join(out_dir, "Snatcher (Japan) (Track 1).bin")
    print(f"building track 1... (DATA delta {delta:+d}, MAIN_L delta {main_delta:+d})")
    src = open(src_t1, "rb")
    dst = open(dst_t1, "wb")
    # sectors 0..96 unchanged
    dst.write(src.read(DATA_LBA * SECTOR))

    def emit(lba, user):
        """Write one 2352 sector with fresh header; zero EDC/ECC area kept from template."""
        dst.write(mode1_header(lba) + user + b"\x00" * (SECTOR - 16 - 2048))

    # new DATA.BIN
    for s in range(new_secs):
        emit(DATA_LBA + s, bytes(datab[s * 2048:(s + 1) * 2048]))
    # grown MAIN_L at MAIN_LBA+delta
    for rel in range(main_secs):
        user = main_l[rel * 2048:rel * 2048 + 2048]
        user += b"\x00" * (2048 - len(user))
        emit(MAIN_LBA + delta + rel, user)
    # files after the original MAIN_L, shifted by total_delta
    t1_secs = os.path.getsize(src_t1) // SECTOR
    src.seek((MAIN_LBA + orig_main_secs) * SECTOR)
    for old_lba in range(MAIN_LBA + orig_main_secs, t1_secs):
        raw = src.read(SECTOR)
        emit(old_lba + total_delta, raw[16:16 + 2048])
    src.close()
    dst.close()

    # patch ISO fs in the new image: PVD volume size + shifted extents
    f = open(dst_t1, "r+b")

    def rd(lba):
        f.seek(lba * SECTOR + USER)
        return bytearray(f.read(2048))

    def wr(lba, data):
        f.seek(lba * SECTOR + USER)
        f.write(data)

    pvd = rd(16)
    vol = struct.unpack("<I", pvd[80:84])[0] + delta
    pvd[80:84] = struct.pack("<I", vol)
    pvd[84:88] = struct.pack(">I", vol)
    wr(16, pvd)
    root_lba = struct.unpack("<I", pvd[158:162])[0]
    root_len = struct.unpack("<I", pvd[166:170])[0]
    patched = 0
    for s in range(root_lba, root_lba + (root_len + 2047) // 2048):
        d = rd(s)
        i = 0
        while i < 2048:
            ln = d[i]
            if ln == 0:
                break
            lba = struct.unpack("<I", d[i + 2:i + 6])[0]
            size = struct.unpack("<I", d[i + 10:i + 14])[0]
            if lba == MAIN_LBA:                       # MAIN_L: shift by delta, grew
                d[i + 2:i + 6] = struct.pack("<I", lba + delta)
                d[i + 6:i + 10] = struct.pack(">I", lba + delta)
                d[i + 10:i + 14] = struct.pack("<I", len(main_l))
                d[i + 14:i + 18] = struct.pack(">I", len(main_l))
                patched += 1
            elif lba > MAIN_LBA:                      # after MAIN_L: shift by total
                d[i + 2:i + 6] = struct.pack("<I", lba + total_delta)
                d[i + 6:i + 10] = struct.pack(">I", lba + total_delta)
                patched += 1
            nl = d[i + 32]
            name = d[i + 33:i + 33 + nl]
            if name == b"DATA.BIN;1":
                d[i + 10:i + 14] = struct.pack("<I", new_secs * 2048)
                d[i + 14:i + 18] = struct.pack(">I", new_secs * 2048)
            i += ln
        wr(s, d)
    f.close()
    print(f"fs: {patched} extents shifted by {delta:+d}, volume {vol} sectors")

    # track 2 physically shifts by delta: rewrite each sector's header MSF
    # (Mode-2 EDC/ECC exclude the header, so no regeneration needed)
    print("rebuilding track 2 headers...")
    t2_src = open(os.path.join(SRC, "Snatcher (Japan) (Track 2).bin"), "rb")
    t2_dst = open(os.path.join(out_dir, "Snatcher (Japan) (Track 2).bin"), "wb")
    t1_new_secs = t1_secs + total_delta
    lba = t1_new_secs                      # track 2 starts right after track 1
    bcd = lambda v: ((v // 10) << 4) | (v % 10)
    while True:
        raw = t2_src.read(SECTOR)
        if len(raw) < SECTOR:
            break
        m = lba + 150
        mm, rem = divmod(m, 75 * 60)
        ss, ff = divmod(rem, 75)
        t2_dst.write(raw[:12] + bytes([bcd(mm), bcd(ss), bcd(ff)]) + raw[15:])
        lba += 1
    t2_src.close()
    t2_dst.close()
    p = os.path.join(out_dir, "Snatcher (Japan) (Track 3).bin")
    if not os.path.exists(p):
        os.link(os.path.join(SRC, "Snatcher (Japan) (Track 3).bin"), p)
    import shutil
    shutil.copyfile(os.path.join(SRC, "Snatcher (Japan).cue"),
                    os.path.join(out_dir, "Snatcher (Japan).cue"))
    print(f'boot: mednafen "{os.path.join(out_dir, "Snatcher (Japan).cue")}"')


if __name__ == "__main__":
    main()
