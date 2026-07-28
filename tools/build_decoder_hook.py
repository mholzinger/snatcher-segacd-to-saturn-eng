#!/usr/bin/env python3
"""Build the decoder-hook disc: replace the record decoder FUN_060c4d24 with an
ASCII-aware superset (asm/decoder_hook.c) injected at 0x060FF090.

The 7 call pointers to FUN_060c4d24 are repointed to the injected decode(). With
NO text re-encoded (no 0x01 sentinels), decode() behaves identically to the
original (byte-negate) -> FIRST BOOT validates TRANSPARENCY: existing English must
render exactly like build/stable_en. Then a re-encoded line tests ASCII mode.

Disc = build_inject_test layout (MAIN_L grow above BSS + shift + track-2 MSF) +
stable in-place English text.

Usage: build_decoder_hook.py [out_dir]   (default build/decoder_hook)
"""
import json
import os
import shutil
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble
import sh2_inject
import build_full_en2 as B

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR, USER = 2352, 16
DATA_LBA, MAIN_LBA = 96, 5451
INDEX = 0x362F4
SRC = os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")
MARS = os.environ.get("MARSDEV", "/Users/mikeholzinger/src/marsdev/mars") + "/sh-elf/bin"

DECODE_ORIG = 0x060C4D24
DECODE_PTRS = [0x835c, 0x84a0, 0x907c, 0x9714, 0x97e8, 0xa040, 0xa67c]  # MAIN_L file offsets


def compile_decoder(load_addr):
    """Compile asm/decoder_hook.c to a flat binary linked at load_addr; return
    bytes. Asserts `decode` lands exactly at load_addr."""
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        o = os.path.join(td, "d.o")
        elf = os.path.join(td, "d.elf")
        binf = os.path.join(td, "d.bin")
        ld = os.path.join(td, "d.ld")
        open(ld, "w").write(
            "ENTRY(_decode)\nSECTIONS { . = %#x; "
            ".text : { *(.text.decode) *(.text*) *(.rodata*) } }\n" % load_addr)
        subprocess.run([os.path.join(MARS, "sh-elf-gcc"), "-m2", "-O2",
                        "-ffreestanding", "-fno-builtin", "-fomit-frame-pointer",
                        "-c", os.path.join(ROOT, "asm/decoder_hook.c"),
                        "-o", o, "-I", os.path.join(ROOT, "asm")], check=True)
        subprocess.run([os.path.join(MARS, "sh-elf-ld"), "-T", ld, "-o", elf, o],
                       check=True, stderr=subprocess.DEVNULL)
        nm = subprocess.run([os.path.join(MARS, "sh-elf-nm"), elf],
                            capture_output=True, text=True).stdout
        addr = next(l.split()[0] for l in nm.splitlines() if l.split()[-1] == "_decode")
        assert int(addr, 16) == load_addr, f"_decode at 0x{addr} != {load_addr:#x}"
        subprocess.run([os.path.join(MARS, "sh-elf-objcopy"), "-O", "binary", elf, binf],
                       check=True)
        return open(binf, "rb").read()


def encode_1byte(en, slot):
    """Encode English into the 1-byte scheme for the ASCII-aware decoder:
    ASCII runs -> 0x01 <raw ascii> 0x02 ; <br> and full-width chars (＠color,
    kanji) -> per-byte-negated SJIS tokens (the original decode form). Result is
    truncated at a safe boundary to fit `slot` bytes, then 0x00-padded (decoder
    stops at the first 0x00)."""
    out = bytearray()
    run = bytearray()

    def flush():
        if run:
            out.append(0x01); out.extend(run); out.append(0x02)
            run.clear()

    i = 0
    while i < len(en):
        if en[i:i+4] == "<br>":
            flush()
            out += bytes(((0x100 - 0x81) & 0xFF, (0x100 - 0x8F) & 0xFF))  # ¥ line break
            i += 4
            continue
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
    # fit to slot: drop trailing whole segments until it fits (segments end at 0x02
    # or after a 2-byte token; simplest safe cut = at an 0x01/token boundary).
    if len(out) > slot:
        out = out[:slot]
        # ensure we didn't cut inside an ascii run without closing it: if the last
        # 0x01 has no 0x02 after it within the kept bytes, that's still valid (decoder
        # reads ascii until the 0x00 pad). Trim a dangling lone 0x01 at the very end.
        while out and out[-1] == 0x01:
            out = out[:-1]
    return bytes(out) + b"\x00" * (slot - len(out))


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
            out[off:off + jl] = encode_1byte(B.wrap(en), jl)
        writes.append((sec, bytes(out)))
    return writes


def msf(lba, bcd=lambda v: ((v // 10) << 4) | (v % 10)):
    m = lba + 150
    mm, rem = divmod(m, 4500)
    ss, ff = divmod(rem, 75)
    return bytes([bcd(mm), bcd(ss), bcd(ff)])


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/decoder_hook")
    os.makedirs(out, exist_ok=True)

    payload = compile_decoder(sh2_inject.RESIDENCY)
    hooks = [(p, struct.pack(">I", sh2_inject.RESIDENCY)) for p in DECODE_PTRS]
    main_bin = sh2_inject.build_main_l(payload, hooks=hooks)
    # sanity: every decoder pointer now points at our decode()
    for p in DECODE_PTRS:
        assert struct.unpack_from(">I", main_bin, p)[0] == sh2_inject.RESIDENCY
    main_secs = (len(main_bin) + 2047) // 2048
    orig_main_secs = (sh2_inject.MAIN_L_END + 2047) // 2048
    delta = main_secs - orig_main_secs
    print(f"decode() payload {len(payload)}B at {sh2_inject.RESIDENCY:#x}; "
          f"{len(DECODE_PTRS)} pointers repointed from {DECODE_ORIG:#x}")
    print(f"MAIN_L {sh2_inject.MAIN_L_END:#x}->{len(main_bin):#x} ({delta:+d} sectors)")

    scene = scene_writes(main_bin)

    src_t1 = os.path.join(SRC, "Snatcher (Japan) (Track 1).bin")
    dst_t1 = os.path.join(out, "Snatcher (Japan) (Track 1).bin")
    src = open(src_t1, "rb")
    dst = open(dst_t1, "wb")
    print("building track 1...")
    dst.write(src.read(MAIN_LBA * SECTOR))
    for s in range(main_secs):
        user = main_bin[s * 2048:s * 2048 + 2048]
        user += b"\x00" * (2048 - len(user))
        dst.write(b"\x00" + b"\xff" * 10 + b"\x00" + msf(MAIN_LBA + s) + b"\x01" + user
                  + b"\x00" * (SECTOR - 16 - 2048))
    src.seek((MAIN_LBA + orig_main_secs) * SECTOR)
    t1_secs = os.path.getsize(src_t1) // SECTOR
    lba = MAIN_LBA + main_secs
    for old in range(MAIN_LBA + orig_main_secs, t1_secs):
        raw = src.read(SECTOR)
        dst.write(raw[:12] + msf(lba) + raw[15:])
        lba += 1
    src.close()
    dst.close()

    f = open(dst_t1, "r+b")
    for sec, dn in scene:
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
    print("TRANSPARENCY TEST: existing English must render exactly like stable_en.")


if __name__ == "__main__":
    main()
