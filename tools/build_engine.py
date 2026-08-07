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

# Untranslated single-token LOOK/investigate options. These jl=2 records (one 2-byte
# token = one kanji) were skipped by the extractor, so they render as their original
# Japanese. They're too small for a KEY (6 bytes) or spelled-out English in place, so we
# translate them via a payload table: build_chunk marks each such record [0x06][index];
# decode() redirects to tok_en[index]. SJIS kanji -> English (chief-office etc. targets).
LOOK_EN = {
    '窓': 'Window', '扉': 'Door', '壁': 'Wall', '棚': 'Shelf', '絵': 'Painting',
    '床': 'Floor', '瓶': 'Bottle', '夢': 'Dream', '机': 'Desk', '街': 'Street',
    '鏡': 'Mirror', '駒': 'Chess piece', '前': 'Front', '後': 'Back', '空': 'Sky',
    '人': 'Person', '眼': 'Eye', '鼻': 'Nose', '口': 'Mouth', '海': 'Sea',
    '女': 'Woman', '客': 'Customer', '酒': 'Liquor', '銃': 'Gun', '犬': 'Dog',
    '猫': 'Cat', '傷': 'Scar', '砂': 'Sand', '雪': 'Snow',
    # name-search list section headers (chunk_025) — katakana initial -> romaji
    'ア': 'A', 'コ': 'Ko', 'タ': 'Ta', 'マ': 'Ma',
}
_LOOK_ITEMS = list(LOOK_EN.items())          # index order (stable)
LOOK_TOKEN_IDX = {0x10100 - struct.unpack(">H", ch.encode("shift_jis"))[0]: i
                  for i, (ch, en) in enumerate(_LOOK_ITEMS)}


def write_tok_en_h():
    """Emit asm/tok_en.h: 1-byte-encoded English (0x01=ascii-mode) in index order."""
    lines = [f'    "\\x01{en}",' for ch, en in _LOOK_ITEMS]
    with open(os.path.join(ROOT, "asm/tok_en.h"), "w") as fh:
        fh.write("\n".join(lines) + "\n")

# Dialogue box geometry. The game ships 20 cells/row x 4 rows; at half-width (8px)
# 20 cells fill only ~55% of the box, so text wraps early ("extra carriage returns").
# COLS=26 fills the box: 26 cells/row x 3 rows = 78 <= the renderer's 80-cell window.
# The renderer (FUN_060b4970) walks 80 cells linearly and takes X/Y from the table,
# so widening is: rewrite the table's per-cell X/Y for 26/row + patch the fill
# routine's wrap column (0x14->0x1a) and row byte-stride (0x50->0x68) so a char lands
# in buffer cell row*26+col, which maps 1:1 to renderer cell row*26+col. See
# TRANSLATION_RULES "dialogue layout".
# DEFAULT = 20 (safe). 26/row "wide" LOOKS nicer but is a LATENT-HANG FOOTGUN: the
# game's own text processor chokes when a row fills to a full 26 cells (it assumes the
# stock 20/row x 4-row layout) -> the fill/frame path stalls forever. PROVEN 2026-08-06:
# stock build/engine at COLS=26 hard-hangs on a full-26-char line (e.g. Mika "The chief
# is watching that camera feed too, you know."); COLS=20 plays it fine. Only use 26 if
# you ALSO patch the game's text-processor/scroll row logic. See TRANSLATION_RULES.
COLS = int(os.environ.get("COLS", "20"))
# Dialogue row cap (hang-safe: text must not reach buffer row that spills past cell
# 79 -> overflow corrupts scene state and hard-hangs; PROVEN, don't exceed).
# Speaker dialogue puts the name in buffer row 0, so the body starts at row 1. At
# COLS=26 that means rows 1,2 are the only full-width rows (row 3 = cells 78-79 only)
# -> cap 2. At COLS=20 the body gets 3 full rows (1,2,3 = cells 20-79) -> cap 3.
# The game's scroll (FUN_060b4730) is NOT a safe overflow handler (it hangs), so we
# clamp instead of scroll. Flip layouts with:  COLS=20 (narrow/3-row) or default 26.
# Cap 2 body rows ALWAYS. The box is 4 rows: row 0 = speaker, rows 1-2 = body, row 3 =
# margin/prompt. A 3-row body (rows 1-3) fills the box and the game reflows it into a
# broken rows-0,2,3 gap layout (and drops the speaker). PROVEN 2026-08-06. Paging shows
# the rest, so 2 is both safe and clean.
MAXROWS = int(os.environ.get("MAXROWS", "2"))


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
            ".text : { *(.text.decode) *(.text.fontblock) *(.text.pagehook) *(.text*) *(.rodata*) } }\n" % load_addr)
        diag = (["-DDIAG_ADVANCE"] if os.environ.get("DIAG") else []) + \
               (["-DDIAG_MENU"] if os.environ.get("DIAG_MENU") else [])
        subprocess.run([os.path.join(MARS, "sh-elf-gcc"), "-m2", "-O2", "-ffreestanding",
                        "-fno-builtin", "-fomit-frame-pointer", "-c",
                        os.path.join(ROOT, "asm/full_hook.c"), "-o", o,
                        f"-DDLG_COLS={COLS}", f"-DDLG_MAXROWS={MAXROWS}", *diag,
                        "-I", os.path.join(ROOT, "asm")], check=True)
        subprocess.run([os.path.join(MARS, "sh-elf-ld"), "-T", ld, "-o", elf, o],
                       check=True, stderr=subprocess.DEVNULL)
        nm = subprocess.run([os.path.join(MARS, "sh-elf-nm"), elf], capture_output=True, text=True).stdout
        syms = {l.split()[-1]: int(l.split()[0], 16) for l in nm.splitlines() if len(l.split()) == 3}
        assert syms["_decode"] == load_addr
        subprocess.run([os.path.join(MARS, "sh-elf-objcopy"), "-O", "binary", elf, binf], check=True)
        return (open(binf, "rb").read(), syms.get("_fontblock", 0),
                syms.get("_inputcompute", 0), syms.get("_redraw_hook", 0),
                syms.get("_print_hook", 0), syms.get("_row0_geom", 0),
                syms.get("_menu_lay", 0))


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
    # detached copy buffer.
    # KEY_MIN_JL = 16 (NOT 6): menu records are decoded from a DETACHED copy buffer
    # (0x060FAC60) and resolved via ONE global cached text_start. That cache is only
    # valid when the menu's chunk == the last dialogue chunk; cross-chunk it's stale,
    # so keyed menu items decode to wrong/empty text -> menus render out of order and
    # drop options (commit 556210 regression). Keeping jl<16 records in-place makes
    # menus ORDERED + COMPLETE (truncated but correct). Full-length menus need the
    # per-chunk base fix (task #14 / TRANSLATION_RULES "MENU LIMITATION"), not this.
    KEY_MIN_JL = 16
    keys = []                                    # (off, jl, pos) to apply if we keep blob
    for off, en in jobs:
        if off not in recs:
            stats["skip_norec"] += 1; continue
        jl = recs[off] - off
        if jl < KEY_MIN_JL:
            out[off:off + jl] = _encode_trunc(clamp_text(B.wrap(en)), jl)
            stats["inplace_menu"] += 1
            continue
        pos = add(encode_1byte_full(clamp_text(en, max_rows=None, row=COLS)))
        keys.append((off, jl, pos))

    # Translate extractor-missed single-token LOOK options (jl=2): mark [0x06][index] so
    # decode() serves English from the payload table. Untranslated by the normal pipeline
    # (not in `jobs`); too small for a key. Unmapped tokens are left as original Japanese.
    translated = {off for off, _ in jobs}
    for off, end in recs.items():
        if off in translated or end - off != 2:
            continue
        tok = (d[off] << 8) | d[off + 1]
        if tok in LOOK_TOKEN_IDX:
            out[off], out[off + 1] = 0x06, LOOK_TOKEN_IDX[tok]
            stats["look_en"] += 1

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


def patched_index_main_l(entries, payload, fontblock_addr=0, inputcompute_addr=0,
                         redraw_hook_addr=0, print_hook_addr=0, row0_geom_addr=0,
                         menu_lay_addr=0):
    """Stock MAIN_L with new chunk index (no speaker patch), then grown with the
    payload + decode/frame hooks."""
    d = bytearray(open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read())
    for i, (sec, words) in enumerate(entries):
        struct.pack_into(">HH", d, INDEX_OFF + i * 4, sec, words)
    if os.environ.get("GEOM", "1") == "1":   # X-grid table @0x35358 + fill routine.
        TBL = 0x35358                    # ROM DEFAULT = 20 cells/row, 8px pitch (the MENU
        for i in range(80):              # layout). decode() rewrites the table's X/Y to
            struct.pack_into(">H", d, TBL + i * 12 + 8, 0x13 + (i % 20) * 8)  # 26/row for
        #                                                     dialogue, 20/row for menus.
        # fill routine FUN_060b45c4 -> COLS/row (dialogue only): wrap column 0x14->COLS,
        # row byte-stride 0x50->COLS*4. Verified immediate offsets; the renderer is
        # 80-cell linear so no renderer patch. The menu uses its own layout (FUN_060b95b8,
        # 0x50 stride) which stays 20/row, matched by decode()'s per-call table swap.
        d[0x46b1] = COLS                 # cmp/eq #0x14,r0  (wrap column)
        for o in (0x45e7, 0x4657, 0x46b5):
            d[o] = COLS * 4              # mov #0x50,r1     (row byte-stride)
        print(f"GEOM: dialogue {COLS}/row (fill wrap {COLS}, stride {COLS*4:#x}); "
              f"menu 20/row; table swapped per-call by decode()")
    hooks = [(p, struct.pack(">I", sh2_inject.RESIDENCY)) for p in DECODE_PTRS]
    # Default: half-width via the glyph-cache substitution at font-upload (race-free).
    # The per-frame frame() renderer is a DEAD END (game overwrites it) — only hooked
    # if FONT=1 is forced, for reference. FONTSUB=0 disables the substitution.
    if os.environ.get("FONTSUB", "1") == "1" and fontblock_addr:
        hooks.append((FONTUP_PTR, struct.pack(">I", fontblock_addr)))
        print(f"FONTSUB: half-width font @ font-upload ptr 0x{FONTUP_PTR:x} -> {fontblock_addr:#x}")
    # PAGING is ON by default (disable with NOPAGE=1). Repoint the VM's dialogue-print
    # command handler: the command jump table entry at 0x060e4fb0 (file 0x34fb0) holds
    # FUN_060b8390 (print_dialogue = decode+lay+typewriter+wait). Point it at print_hook,
    # which loops the original once per page so long English pages through the game's OWN
    # synchronized pipeline (no buffer poking, no hang). See TRANSLATION_RULES.
    if os.environ.get("NOPAGE") != "1" and print_hook_addr:
        hooks.append((0x34fb0, struct.pack(">I", print_hook_addr)))
        print(f"PAGING: VM print cmd 0x060e4fb0 -> print_hook {print_hook_addr:#x}")
    if os.environ.get("NOPAGE") != "1" and row0_geom_addr:
        # print_dialogue's row-0 X-write loop (file 0x8406..0x841d, 24 bytes) hardcodes a
        # 14px pitch. Replace it with a call to row0_geom(), which picks 14px (JP speaker)
        # or 8px (EN body) from the speaker flag. Trampoline: load addr, jsr, then bra over
        # the literal to the untouched fill setup at 0x841e. r0-r7 are dead past the loop.
        stub = struct.pack(">HHHHHIHHHHH",
                           0xD002, 0x400B, 0x0009, 0xA007, 0x0009,   # mov.l @(2,pc),r0; jsr @r0; nop; bra 0x841e; nop
                           row0_geom_addr,
                           0x0009, 0x0009, 0x0009, 0x0009, 0x0009)   # literal, then nops
        d[0x8406:0x8406 + len(stub)] = stub
        print(f"ROW0GEOM: print_dialogue row-0 X-write -> row0_geom {row0_geom_addr:#x}")
    # MENU 1-COLUMN (opt-in MENU1COL=1 while iterating): the 2-col topic grid render
    # (0x060b95b8) lays each option via 0x060b47fc, loaded from the literal at file 0x9720.
    # Repoint that literal to menu_lay() so labels get the full 20-cell row instead of a
    # 10-cell column. (Increment 1: no scroll — options past row 3 skipped.)
    if os.environ.get("MENU1COL") == "1" and menu_lay_addr:
        d[0x9720:0x9724] = struct.pack(">I", menu_lay_addr)
        print(f"MENU1COL: topic-grid lay 0x060b47fc -> menu_lay {menu_lay_addr:#x}")
    return sh2_inject.grow_main_l(bytes(d), payload, hooks=hooks)


def mode1_header(lba, bcd=lambda v: ((v // 10) << 4) | (v % 10)):
    m = lba + 150
    mm, rem = divmod(m, 75 * 60)
    ss, ff = divmod(rem, 75)
    return b"\x00" + b"\xff" * 10 + b"\x00" + bytes([bcd(mm), bcd(ss), bcd(ff), 1])


def main():
    out_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/engine")
    os.makedirs(out_dir, exist_ok=True)
    write_tok_en_h()                   # payload includes tok_en.h -> emit before compile

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

    stats = {k: 0 for k in ("keyed", "skip_norec", "too_small", "inplace_trunc", "big_chunk", "inplace_menu", "look_en")}
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

    payload, fontblock_addr, inputcompute_addr, redraw_hook_addr, print_hook_addr, \
        row0_geom_addr, menu_lay_addr = compile_payload(sh2_inject.RESIDENCY)
    main_l = patched_index_main_l(entries, payload, fontblock_addr, inputcompute_addr,
                                  redraw_hook_addr, print_hook_addr, row0_geom_addr,
                                  menu_lay_addr)
    orig_main_secs = (sh2_inject.MAIN_L_END + 2047) // 2048
    main_secs = (len(main_l) + 2047) // 2048
    main_delta = main_secs - orig_main_secs
    total_delta = delta + main_delta
    print(f"records keyed {stats['keyed']} (skip_norec {stats['skip_norec']}, too_small {stats['too_small']})")
    print(f"DATA.BIN {new_secs} sec (delta {delta:+d}); MAIN_L delta {main_delta:+d}; "
          f"payload {len(payload)}B; decode@{sh2_inject.RESIDENCY:#x}")

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
