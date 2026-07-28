#!/usr/bin/env python3
"""Assemble SH-2 (big-endian) source to raw bytes, for engine injection.

Wraps the MARSDEV sh-elf toolchain (verified present at MARSDEV path). Given an
.s file and a load address, returns the linked raw .text bytes ready to splice
into MAIN_L.BIN. Also disassembles (capstone) for a verification dump.

The scene engine is SuperH SH-2, big-endian, loaded at 0x060B0000.

Usage (module):  code = assemble(src_text, load_addr)
Usage (cli):     sh2_asm.py file.s 0x060f006c
"""
import os
import subprocess
import sys
import tempfile

MARS = os.environ.get(
    "MARSDEV", "/Users/mikeholzinger/src/marsdev/mars") + "/sh-elf/bin"
AS = os.path.join(MARS, "sh-elf-as")
LD = os.path.join(MARS, "sh-elf-ld")
OBJCOPY = os.path.join(MARS, "sh-elf-objcopy")


def assemble(src, load_addr=0):
    """Assemble big-endian SH-2 `src` linked at `load_addr`; return raw bytes."""
    with tempfile.TemporaryDirectory() as td:
        s = os.path.join(td, "a.s")
        o = os.path.join(td, "a.o")
        elf = os.path.join(td, "a.elf")
        binf = os.path.join(td, "a.bin")
        open(s, "w").write(src)
        subprocess.run([AS, "-big", "-o", o, s], check=True)
        # link at the true load address so PC-relative refs resolve correctly
        subprocess.run([LD, f"-Ttext={load_addr:#x}", "-e", "_start",
                        "-o", elf, o], check=True,
                       stderr=subprocess.DEVNULL)
        subprocess.run([OBJCOPY, "-O", "binary",
                        "--only-section=.text", elf, binf], check=True)
        return open(binf, "rb").read()


def disasm(code, addr=0):
    """Return list of (addr, mnemonic, op_str) via capstone SH-2 BE."""
    from capstone import Cs, CS_ARCH_SH, CS_MODE_SH2, CS_MODE_BIG_ENDIAN
    md = Cs(CS_ARCH_SH, CS_MODE_SH2 | CS_MODE_BIG_ENDIAN)
    return [(i.address, i.mnemonic, i.op_str) for i in md.disasm(code, addr)]


# ---- SH-2 opcode helpers (hand-encodable branch/call patches) --------------
def bra(from_addr, to_addr):
    """12-bit PC-relative unconditional branch. delay slot follows (caller adds
    a nop or a useful instr). disp = (target - (from+4)) / 2, must fit signed12."""
    disp = (to_addr - (from_addr + 4)) // 2
    assert -0x800 <= disp <= 0x7FF, f"bra out of range: {disp}"
    return (0xA000 | (disp & 0xFFF)).to_bytes(2, "big")


def bsr(from_addr, to_addr):
    """12-bit PC-relative branch-to-subroutine (call), delay slot follows."""
    disp = (to_addr - (from_addr + 4)) // 2
    assert -0x800 <= disp <= 0x7FF, f"bsr out of range: {disp}"
    return (0xB000 | (disp & 0xFFF)).to_bytes(2, "big")


if __name__ == "__main__":
    src = open(sys.argv[1]).read()
    addr = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0
    code = assemble(src, addr)
    print(f"{len(code)} bytes @ {addr:#x}:")
    print(" ".join(f"{b:02x}" for b in code))
    try:
        for a, m, o in disasm(code, addr):
            print(f"  {a:#010x}: {m} {o}")
    except Exception as e:
        print(f"(disasm unavailable: {e})")
