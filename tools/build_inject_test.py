#!/usr/bin/env python3
"""Build the injection-test disc (v3, residency ABOVE BSS at 0x060FF090).

asm/inject_test.s assembled at 0x060FF090 (above the BSS-clear range; not an
in-file read table), placed via MAIN_L growth. Font-upload call pointer at MAIN_L
file 0x1208 (0x060B4530) repointed to 0x060FF090. Routine writes marker
0x0DEADBEE to 0x060FF800 and tail-calls the real font upload.

Disc: DATA.BIN (LBA 96, before MAIN_L) gets the stable in-place English text —
UNSHIFTED. MAIN_L (LBA 5451) grows, so track-1 files after it + track 2 shift by
delta (fs extents + track-2 MSF restamp). Same shift machinery proven in test_H.

Verify: savestate, WorkRAMH @0x060FF800 == 0x0DEADBEE.  AND: does it reach the
title/menu now (residency survives) vs the previous hangs (BSS-clear / read-table).

Usage: build_inject_test.py [out_dir]   (default build/inject_test)
"""
import json
import os
import shutil
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble
import sh2_asm
import sh2_inject
import build_full_en2 as B

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR, USER = 2352, 16
DATA_LBA, MAIN_LBA = 96, 5451
INDEX = 0x362F4
SRC = os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")
HOOK_PTR_FILE = int(os.environ.get("PROBE_HOOK", "0x1208"), 16)
PROBE_ASM = os.environ.get("PROBE_ASM", "asm/inject_test.s")


def compile_c(cfile, load_addr, entry):
    """Compile a C file to a flat binary linked so `entry` lands at load_addr."""
    import tempfile
    MARS = os.environ.get("MARSDEV", "/Users/mikeholzinger/src/marsdev/mars") + "/sh-elf/bin"
    with tempfile.TemporaryDirectory() as td:
        o, elf, binf, ld = (os.path.join(td, x) for x in ("d.o", "d.elf", "d.bin", "d.ld"))
        open(ld, "w").write(
            "ENTRY(_%s)\nSECTIONS { . = %#x; .text : { *(.text.%s) *(.text*) *(.rodata*) } }\n"
            % (entry, load_addr, entry))
        subprocess.run([os.path.join(MARS, "sh-elf-gcc"), "-m2", "-O2", "-ffreestanding",
                        "-fno-builtin", "-fomit-frame-pointer", "-c", os.path.join(ROOT, cfile),
                        "-o", o, "-I", os.path.join(ROOT, "asm")], check=True)
        subprocess.run([os.path.join(MARS, "sh-elf-ld"), "-T", ld, "-o", elf, o],
                       check=True, stderr=subprocess.DEVNULL)
        nm = subprocess.run([os.path.join(MARS, "sh-elf-nm"), elf], capture_output=True, text=True).stdout
        addr = next(l.split()[0] for l in nm.splitlines() if l.split()[-1] == "_" + entry)
        assert int(addr, 16) == load_addr, f"_{entry} at 0x{addr} != {load_addr:#x}"
        subprocess.run([os.path.join(MARS, "sh-elf-objcopy"), "-O", "binary", elf, binf], check=True)
        return open(binf, "rb").read()


def scene_writes(main_bin):
    master = json.load(open(os.path.join(ROOT, "translation/master.json"), encoding="utf-8"))
    by_chunk = {}
    for e in master:
        if e.get("en"):
            by_chunk.setdefault(int(e["chunk"].split("_")[1]), []).append(
                (int(e["offset"], 16), e["en"]))
    writes = []
    for i in sorted(by_chunk):
        if not (21 <= i <= 59):
            continue
        sec, _ = struct.unpack_from(">HH", main_bin, INDEX + i * 4)
        d = open(os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{i:03d}.bin"), "rb").read()
        recs = dict(reassemble.records(d))
        out = bytearray(d)
        for off, en in sorted(by_chunk[i]):
            if off not in recs:
                continue
            jl = recs[off] - off
            enc = reassemble.encode_text(B.wrap(en))[:jl]
            pad = (jl - len(enc)) // 2
            filled = enc + reassemble.encode_text("　" * pad)
            filled += b"\x00" * (jl - len(filled))
            out[off:off + jl] = filled
        writes.append((sec, bytes(out)))
    return writes


def msf(lba, bcd=lambda v: ((v // 10) << 4) | (v % 10)):
    m = lba + 150
    mm, rem = divmod(m, 4500)
    ss, ff = divmod(rem, 75)
    return bytes([bcd(mm), bcd(ss), bcd(ff)])


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/inject_test")
    os.makedirs(out, exist_ok=True)

    if PROBE_ASM.endswith(".c"):
        payload = compile_c(PROBE_ASM, sh2_inject.RESIDENCY, "frame")
    else:
        payload = sh2_asm.assemble(open(os.path.join(ROOT, PROBE_ASM)).read(),
                                   sh2_inject.RESIDENCY)
    hook = (HOOK_PTR_FILE, struct.pack(">I", sh2_inject.RESIDENCY))
    hooks = [hook]
    if os.environ.get("EXTRA_HOOK"):        # "offset:hexbytes" in-place patch(es), ';'-separated
        for part in os.environ["EXTRA_HOOK"].split(";"):
            off, val = part.split(":")
            hooks.append((int(off, 16), bytes.fromhex(val)))
            print(f"extra patch: 0x{int(off,16):x} = {val}")
    main_bin = sh2_inject.build_main_l(payload, hooks=hooks)
    if os.environ.get("PITCH"):        # rewrite the static X-grid (table @0x060e5358, short[4])
        pitch = int(os.environ["PITCH"])
        mb = bytearray(main_bin); TBL = 0x35358
        for i in range(20, 80):                # rows 1-3 = dialogue; row 0 = speaker (kanji, keep 16px)
            struct.pack_into(">H", mb, TBL + i * 12 + 8, 0x13 + (i % 20) * pitch)
            if os.environ.get("SPRITEW"):      # short[1] = width<<8 | height (pixels)
                struct.pack_into(">H", mb, TBL + i * 12 + 2,
                                 (int(os.environ["SPRITEW"]) << 8) | 0x0e)
        main_bin = bytes(mb)
        print(f"PITCH patch (cells 20-79): X = 0x13 + col*{pitch} (was col*14)"
              + (f"; sprite width -> {os.environ['SPRITEW']}px" if os.environ.get("SPRITEW") else ""))
    main_secs = (len(main_bin) + 2047) // 2048
    orig_main_secs = (sh2_inject.MAIN_L_END + 2047) // 2048
    delta = main_secs - orig_main_secs
    print(f"MAIN_L {sh2_inject.MAIN_L_END:#x}->{len(main_bin):#x} "
          f"({orig_main_secs}->{main_secs} sec, {delta:+d}); "
          f"payload@{sh2_inject.RESIDENCY:#x}; hook 0x{HOOK_PTR_FILE:x}->{sh2_inject.RESIDENCY:#x}")

    scene = scene_writes(main_bin)

    src_t1 = os.path.join(SRC, "Snatcher (Japan) (Track 1).bin")
    dst_t1 = os.path.join(out, "Snatcher (Japan) (Track 1).bin")
    src = open(src_t1, "rb")
    dst = open(dst_t1, "wb")
    print("building track 1...")
    dst.write(src.read(MAIN_LBA * SECTOR))                    # verbatim incl DATA.BIN
    for s in range(main_secs):                                # grown MAIN_L
        user = main_bin[s * 2048:s * 2048 + 2048]
        user += b"\x00" * (2048 - len(user))
        lba = MAIN_LBA + s
        dst.write(b"\x00" + b"\xff" * 10 + b"\x00" + msf(lba) + b"\x01" + user
                  + b"\x00" * (SECTOR - 16 - 2048))
    src.seek((MAIN_LBA + orig_main_secs) * SECTOR)            # shifted remainder
    t1_secs = os.path.getsize(src_t1) // SECTOR
    lba = MAIN_LBA + main_secs
    for old in range(MAIN_LBA + orig_main_secs, t1_secs):
        raw = src.read(SECTOR)
        dst.write(raw[:12] + msf(lba) + raw[15:])
        lba += 1
    src.close()
    dst.close()

    f = open(dst_t1, "r+b")
    for sec, dn in scene:                                     # English text (unshifted)
        pos, rem = sec * 2048, dn
        while rem:
            lb = DATA_LBA + pos // 2048
            ins = pos % 2048
            n = min(2048 - ins, len(rem))
            f.seek(lb * SECTOR + USER + ins)
            f.write(rem[:n])
            rem = rem[n:]
            pos += n

    def rd(l):
        f.seek(l * SECTOR + USER)
        return bytearray(f.read(2048))

    def wr(l, d):
        f.seek(l * SECTOR + USER)
        f.write(d)

    pvd = rd(16)
    vol = struct.unpack("<I", pvd[80:84])[0] + delta
    pvd[80:84] = struct.pack("<I", vol)
    pvd[84:88] = struct.pack(">I", vol)
    wr(16, pvd)
    rl = struct.unpack("<I", pvd[158:162])[0]
    rlen = struct.unpack("<I", pvd[166:170])[0]
    for s in range(rl, rl + (rlen + 2047) // 2048):
        d = rd(s)
        i = 0
        while i < 2048:
            ln = d[i]
            if ln == 0:
                break
            lba2 = struct.unpack("<I", d[i + 2:i + 6])[0]
            nl = d[i + 32]
            name = d[i + 33:i + 33 + nl]
            if name == b"MAIN_L.BIN;1":
                d[i + 10:i + 14] = struct.pack("<I", len(main_bin))
                d[i + 14:i + 18] = struct.pack(">I", len(main_bin))
            elif lba2 > MAIN_LBA:
                d[i + 2:i + 6] = struct.pack("<I", lba2 + delta)
                d[i + 6:i + 10] = struct.pack(">I", lba2 + delta)
            i += ln
        wr(s, d)
    f.close()

    t2s = open(os.path.join(SRC, "Snatcher (Japan) (Track 2).bin"), "rb")
    t2d = open(os.path.join(out, "Snatcher (Japan) (Track 2).bin"), "wb")
    lba = t1_secs + delta
    while True:
        raw = t2s.read(SECTOR)
        if len(raw) < SECTOR:
            break
        t2d.write(raw[:12] + msf(lba) + raw[15:])
        lba += 1
    t2s.close()
    t2d.close()
    p = os.path.join(out, "Snatcher (Japan) (Track 3).bin")
    if not os.path.exists(p):
        os.link(os.path.join(SRC, "Snatcher (Japan) (Track 3).bin"), p)
    shutil.copyfile(os.path.join(SRC, "Snatcher (Japan).cue"),
                    os.path.join(out, "Snatcher (Japan).cue"))
    print(f'boot: mednafen "{os.path.join(out, "Snatcher (Japan).cue")}"')
    print("VERIFY: reaches title? + savestate WorkRAMH @0x060FF800 == 0x0DEADBEE")


if __name__ == "__main__":
    main()
