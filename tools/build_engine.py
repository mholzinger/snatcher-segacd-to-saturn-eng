#!/usr/bin/env python3
"""Full-English ENGINE build: key+blob architecture (no record growth, no repoint).

Per chunk (21-59): every translated record is overwritten IN PLACE with a 4-byte
KEY [0x04][3-byte self-relative offset]; the chunk's dedup'd full-English blob is
appended after the original chunk bytes. decode() sees the key and redirects to the
blob entry (p+offset, same loaded chunk) -> outputs the FULL text; the game's own
engine lays it out. Records never move -> VM references stay valid -> no repoint.

Blob entries are clamp_text(wrap(en)) (<=3 rows, safe) encoded 1-byte but NOT
byte-truncated -> removes the record byte-budget ceiling that truncated menus.

Disc: DATA.BIN grows (blobs) + MAIN_L grows (payload); two-growth layout shift.
Payload = asm/full_hook.c (decode w/ key redirect + font renderer). NO speaker
patch (0x060E71F0 hangs).

Usage: build_engine.py [out_dir]   (default build/engine)
"""
import json
import os
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble
import sh2_inject
import build_full_en2 as B          # wrap()
from layout_clamp import clamp_text

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR, USER = 2352, 16
DATA_LBA, MAIN_LBA = 96, 5451
INDEX_OFF = 0x362F4
N_CHUNKS = 639
SRC = os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")
MARS = os.environ.get("MARSDEV", "/Users/mikeholzinger/src/marsdev/mars") + "/sh-elf/bin"
DECODE_PTRS = [0x835c, 0x84a0, 0x907c, 0x9714, 0x97e8, 0xa040, 0xa67c]
FRAME_PTR = 0x472c


def encode_1byte_full(en):
    """1-byte encoding (0x01 ascii runs / 0x03 br / negated SJIS tokens), NO byte
    truncation. 0x00-terminated by the caller."""
    out = bytearray()
    run = bytearray()

    def flush():
        if run:
            out.append(0x01); out.extend(run); out.append(0x02); run.clear()

    i = 0
    while i < len(en):
        if en[i:i + 4] == "<br>":
            (run if run else out).append(0x03); i += 4; continue
        c = en[i]; o = ord(c)
        if 0x20 <= o <= 0x7E:
            run.append(o)
        else:
            flush()
            try:
                for b in c.encode("shift_jis"):
                    out.append((0x100 - b) & 0xFF)
            except UnicodeEncodeError:
                pass
        i += 1
    flush()
    return bytes(out)


def compile_payload(load_addr):
    """Compile asm/full_hook.c (decode()+frame()); decode() at load_addr.
    Returns (bytes, frame_addr)."""
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        o, elf, binf, ld = (os.path.join(td, x) for x in ("d.o", "d.elf", "d.bin", "d.ld"))
        open(ld, "w").write(
            "ENTRY(_decode)\nSECTIONS { . = %#x; "
            ".text : { *(.text.decode) *(.text.frame) *(.text.fontblock) *(.text*) *(.rodata*) } }\n" % load_addr)
        subprocess.run([os.path.join(MARS, "sh-elf-gcc"), "-m2", "-O2", "-ffreestanding",
                        "-fno-builtin", "-fomit-frame-pointer", "-c",
                        os.path.join(ROOT, "asm/full_hook.c"), "-o", o,
                        "-I", os.path.join(ROOT, "asm")], check=True)
        subprocess.run([os.path.join(MARS, "sh-elf-ld"), "-T", ld, "-o", elf, o],
                       check=True, stderr=subprocess.DEVNULL)
        nm = subprocess.run([os.path.join(MARS, "sh-elf-nm"), elf], capture_output=True, text=True).stdout
        syms = {l.split()[-1]: int(l.split()[0], 16) for l in nm.splitlines() if len(l.split()) == 3}
        assert syms["_decode"] == load_addr
        subprocess.run([os.path.join(MARS, "sh-elf-objcopy"), "-O", "binary", elf, binf], check=True)
        return open(binf, "rb").read(), syms["_frame"], syms.get("_fontblock", 0)


def build_chunk(d, jobs, stats):
    """Overwrite translated records with keys; append dedup'd full-English blob
    inside the extended text section (the game loads by header h1, not the disc
    index). Records keep their offsets (no repoint). If the blob would push the
    16-bit text section past 64KB, fall back to in-place truncated encoding for
    the whole chunk (current behavior) so big chunks still work."""
    h0, h1, ts, te = reassemble.sections(d)
    recs = dict(reassemble.records(d))
    out = bytearray(d)
    blob = bytearray()
    entry = {}
    base = len(d)

    def add(enc):
        if enc not in entry:
            entry[enc] = base + len(blob)
            blob.extend(enc); blob.append(0)
        return entry[enc]

    # KEY = [0x01][0x04][roff:2BE][boff:2BE] (6 bytes). roff/boff are offsets from
    # the text-section start ts (both < 64KB via the h1 cap). decode() derives the
    # chunk text_start from a dialogue call (p - roff) and reuses it for the menu's
    # detached copy buffer -> menus get full-length text too. Records jl<6 have no
    # room for the key -> kept in-place (tiny labels that mostly fit).
    KEY_MIN_JL = 6
    keys = []                                    # (off, jl, pos) to apply if we keep blob
    for off, en in jobs:
        if off not in recs:
            stats["skip_norec"] += 1; continue
        jl = recs[off] - off
        if jl < KEY_MIN_JL:
            out[off:off + jl] = _encode_trunc(clamp_text(B.wrap(en)), jl)
            stats["inplace_menu"] += 1
            continue
        pos = add(encode_1byte_full(clamp_text(B.wrap(en))))
        keys.append((off, jl, pos))

    if len(d) + len(blob) - ts <= 0xFFFF:        # blob fits the 16-bit text section
        for off, jl, pos in keys:
            roff, boff = off - ts, pos - ts      # both relative to ts, <64KB
            out[off:off + jl] = bytes([0x01, 0x04, (roff >> 8) & 0xFF, roff & 0xFF,
                                       (boff >> 8) & 0xFF, boff & 0xFF]) + b"\x00" * (jl - 6)
            stats["keyed"] += 1
        result = bytes(out) + bytes(blob)
        new_h1 = len(result) - ts
        return struct.pack(">H", new_h1).join([result[:2], result[4:]])

    # fallback: in-place truncated (no blob) — big chunk
    for off, en in jobs:
        if off not in recs:
            continue
        jl = recs[off] - off
        out[off:off + jl] = _encode_trunc(clamp_text(B.wrap(en)), jl)
        stats["inplace_trunc"] += 1
    stats["big_chunk"] += 1
    return bytes(out)


def _encode_trunc(en, slot):
    enc = encode_1byte_full(en)[:slot]
    while enc and enc[-1] == 0x01:
        enc = enc[:-1]
    return enc + b"\x00" * (slot - len(enc))


FONTUP_PTR = 0x1208                              # font-upload call pointer (-> 0x060b4530)


def patched_index_main_l(entries, payload, frame_addr, fontblock_addr=0):
    """Stock MAIN_L with new chunk index (no speaker patch), then grown with the
    payload + decode/frame hooks."""
    d = bytearray(open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read())
    for i, (sec, words) in enumerate(entries):
        struct.pack_into(">HH", d, INDEX_OFF + i * 4, sec, words)
    if os.environ.get("GEOM", "1") == "1":   # X-grid table @0x35358: tighten pitch to 8px (default).
        TBL = 0x35358                    # keep sprite width 16px (matches tile stride; our glyph
        for i in range(20, 80):          # is the left 8px + transparent right half). rows 1-3.
            col = i % 20
            struct.pack_into(">H", d, TBL + i * 12 + 8, 0x13 + col * 8)  # X = 0x13 + col*8
        print("GEOM: pitch -> 8px (cells 20-79), width kept 16px")
    hooks = [(p, struct.pack(">I", sh2_inject.RESIDENCY)) for p in DECODE_PTRS]
    # Default: half-width via the glyph-cache substitution at font-upload (race-free).
    # The per-frame frame() renderer is a DEAD END (game overwrites it) — only hooked
    # if FONT=1 is forced, for reference. FONTSUB=0 disables the substitution.
    if os.environ.get("FONT") == "1":
        hooks.append((FRAME_PTR, struct.pack(">I", frame_addr)))
    if os.environ.get("FONTSUB", "1") == "1" and fontblock_addr:
        hooks.append((FONTUP_PTR, struct.pack(">I", fontblock_addr)))
        print(f"FONTSUB: half-width font @ font-upload ptr 0x{FONTUP_PTR:x} -> {fontblock_addr:#x}")
    return sh2_inject.grow_main_l(bytes(d), payload, hooks=hooks)


def mode1_header(lba, bcd=lambda v: ((v // 10) << 4) | (v % 10)):
    m = lba + 150
    mm, rem = divmod(m, 75 * 60)
    ss, ff = divmod(rem, 75)
    return b"\x00" + b"\xff" * 10 + b"\x00" + bytes([bcd(mm), bcd(ss), bcd(ff), 1])


def main():
    out_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/engine")
    os.makedirs(out_dir, exist_ok=True)

    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    if os.environ.get("MAPPROBE"):     # override the greeting with a char-enumeration
        import string
        enum = (string.digits + string.punctuation) if os.environ["MAPPROBE"] == "2" \
            else (string.ascii_uppercase + string.ascii_lowercase)   # fits 3 rows
        for e in master:
            if e["chunk"] == "chunk_022" and int(e["offset"], 16) == 0x2a34:
                e["en"] = enum
        print(f"MAPPROBE: greeting -> {enum}")
    by_chunk = {}
    for e in master:
        if e.get("en"):
            by_chunk.setdefault(int(e["chunk"].split("_")[1]), []).append(
                (int(e["offset"], 16), e["en"]))

    stats = {k: 0 for k in ("keyed", "skip_norec", "too_small", "inplace_trunc", "big_chunk", "inplace_menu")}
    chunks = []
    for i in range(N_CHUNKS):
        d = open(os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{i:03d}.bin"), "rb").read()
        if 21 <= i <= 59 and i in by_chunk:
            d = build_chunk(d, sorted(by_chunk[i]), stats)
        chunks.append(d)

    entries, datab = [], bytearray()
    for d in chunks:
        entries.append((len(datab) // 2048, (len(d) + 1) // 2))
        datab += d
        if len(datab) % 2048:
            datab += b"\x00" * (2048 - len(datab) % 2048)
    new_secs = len(datab) // 2048
    delta = new_secs - (MAIN_LBA - DATA_LBA)

    payload, frame_addr, fontblock_addr = compile_payload(sh2_inject.RESIDENCY)
    main_l = patched_index_main_l(entries, payload, frame_addr, fontblock_addr)
    orig_main_secs = (sh2_inject.MAIN_L_END + 2047) // 2048
    main_secs = (len(main_l) + 2047) // 2048
    main_delta = main_secs - orig_main_secs
    total_delta = delta + main_delta
    print(f"records keyed {stats['keyed']} (skip_norec {stats['skip_norec']}, too_small {stats['too_small']})")
    print(f"DATA.BIN {new_secs} sec (delta {delta:+d}); MAIN_L delta {main_delta:+d}; "
          f"payload {len(payload)}B; decode@{sh2_inject.RESIDENCY:#x} frame@{frame_addr:#x}")

    src_t1 = os.path.join(SRC, "Snatcher (Japan) (Track 1).bin")
    dst_t1 = os.path.join(out_dir, "Snatcher (Japan) (Track 1).bin")
    src = open(src_t1, "rb"); dst = open(dst_t1, "wb")
    print("building track 1...")
    dst.write(src.read(DATA_LBA * SECTOR))

    def emit(lba, user):
        dst.write(mode1_header(lba) + user + b"\x00" * (SECTOR - 16 - 2048))

    for s in range(new_secs):
        emit(DATA_LBA + s, bytes(datab[s * 2048:(s + 1) * 2048]))
    for rel in range(main_secs):
        u = main_l[rel * 2048:rel * 2048 + 2048]
        emit(MAIN_LBA + delta + rel, u + b"\x00" * (2048 - len(u)))
    t1_secs = os.path.getsize(src_t1) // SECTOR
    src.seek((MAIN_LBA + orig_main_secs) * SECTOR)
    for old_lba in range(MAIN_LBA + orig_main_secs, t1_secs):
        raw = src.read(SECTOR)
        emit(old_lba + total_delta, raw[16:16 + 2048])
    src.close(); dst.close()

    f = open(dst_t1, "r+b")

    def rd(lba):
        f.seek(lba * SECTOR + USER); return bytearray(f.read(2048))

    def wr(lba, data):
        f.seek(lba * SECTOR + USER); f.write(data)

    pvd = rd(16)
    vol = struct.unpack("<I", pvd[80:84])[0] + total_delta
    pvd[80:84] = struct.pack("<I", vol); pvd[84:88] = struct.pack(">I", vol)
    wr(16, pvd)
    root_lba = struct.unpack("<I", pvd[158:162])[0]
    root_len = struct.unpack("<I", pvd[166:170])[0]
    patched = 0
    for s in range(root_lba, root_lba + (root_len + 2047) // 2048):
        d = rd(s); i = 0
        while i < 2048:
            ln = d[i]
            if ln == 0:
                break
            lba = struct.unpack("<I", d[i + 2:i + 6])[0]
            if lba == MAIN_LBA:
                d[i + 2:i + 6] = struct.pack("<I", lba + delta)
                d[i + 6:i + 10] = struct.pack(">I", lba + delta)
                d[i + 10:i + 14] = struct.pack("<I", len(main_l))
                d[i + 14:i + 18] = struct.pack(">I", len(main_l))
                patched += 1
            elif lba > MAIN_LBA:
                d[i + 2:i + 6] = struct.pack("<I", lba + total_delta)
                d[i + 6:i + 10] = struct.pack(">I", lba + total_delta)
                patched += 1
            nl = d[i + 32]
            if d[i + 33:i + 33 + nl] == b"DATA.BIN;1":
                d[i + 10:i + 14] = struct.pack("<I", new_secs * 2048)
                d[i + 14:i + 18] = struct.pack(">I", new_secs * 2048)
            i += ln
        wr(s, d)
    f.close()
    print(f"fs: {patched} extents shifted; volume {vol} sectors")

    t2s = open(os.path.join(SRC, "Snatcher (Japan) (Track 2).bin"), "rb")
    t2d = open(os.path.join(out_dir, "Snatcher (Japan) (Track 2).bin"), "wb")
    lba = t1_secs + total_delta
    bcd = lambda v: ((v // 10) << 4) | (v % 10)
    while True:
        raw = t2s.read(SECTOR)
        if len(raw) < SECTOR:
            break
        m = lba + 150
        mm, rem = divmod(m, 75 * 60)
        ss, ff = divmod(rem, 75)
        t2d.write(raw[:12] + bytes([bcd(mm), bcd(ss), bcd(ff)]) + raw[15:])
        lba += 1
    t2s.close(); t2d.close()
    p = os.path.join(out_dir, "Snatcher (Japan) (Track 3).bin")
    if not os.path.exists(p):
        os.link(os.path.join(SRC, "Snatcher (Japan) (Track 3).bin"), p)
    import shutil
    shutil.copyfile(os.path.join(SRC, "Snatcher (Japan).cue"),
                    os.path.join(out_dir, "Snatcher (Japan).cue"))
    print(f'boot: mednafen "{os.path.join(out_dir, "Snatcher (Japan).cue")}"')


if __name__ == "__main__":
    main()
