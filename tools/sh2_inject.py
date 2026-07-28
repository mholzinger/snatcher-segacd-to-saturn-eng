#!/usr/bin/env python3
"""Inject SH-2 code + data into MAIN_L.BIN at the verified-free residency window.

Residency: 0x060F006C (8808 bytes zero across all savestates — genuinely free
RAM; the file's own zero-runs like 0x060E71F0 are runtime buffers, the trap that
hung the speaker patch). MAIN_L loads at 0x060B0000; its file ends at 0x3F478
(VRAM 0x060EF478). We GROW MAIN_L so the payload lands at file offset 0x4006C
(= VRAM 0x060F006C); the gap 0x3F478..0x4006C stays zero padding (engine BSS
harmlessly lives there at runtime).

Growing MAIN_L shifts only track-1 files AFTER it + track 2 (handled by the disc
builder's fs-extent shift + track-2 MSF restamp); DATA.BIN (LBA 96, before
MAIN_L) and every scene chunk are UNAFFECTED — so scene-text edits compose with
this cleanly.

API:
  patched = build_main_l(payload_bytes, hooks)      -> grown MAIN_L bytes
    payload_bytes : assembled SH-2 (+ appended data), linked at RESIDENCY
    hooks         : list of (file_offset, patch_bytes) applied to MAIN_L in place
  RESIDENCY, RESIDENCY_FILE, RESIDENCY_MAX are exported for the caller/assembler.
"""
import os
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x060B0000
MAIN_L_END = 0x3F478            # stock file size
BSS_START = 0x060EF480          # engine BSS-clear range (from init fn 0x060b002c)
BSS_END = 0x060FF090

# RESIDENCY = just ABOVE bss_end. NOT cleared by the startup BSS-clear (which
# wiped the 0x060F006C attempt), and NOT an in-file data table (the 0x060E71F0
# attempt hung — the engine scans that region as a zero-terminated table, so any
# nonzero runs it off the end; same cause as the speaker-patch hang). The stack
# is LOW (SP=0x06006000, grows down), so the top of HWRAM is free; zero across
# all savestates. Reached by GROWING MAIN_L: the gap 0x060EF478..bss_end is zero
# padding that the BSS-clear harmlessly re-zeroes; code at bss_end survives.
RESIDENCY = BSS_END              # 0x060FF090
RESIDENCY_FILE = RESIDENCY - BASE
RESIDENCY_MAX = 0x06100000 - RESIDENCY   # 3952 bytes to end of HWRAM


def build_main_l(payload, hooks=()):
    """Return MAIN_L.BIN GROWN so `payload` loads at RESIDENCY (above BSS), with
    `hooks` (file_offset, bytes) applied. The gap between the stock file end and
    RESIDENCY is zero-padded. Caller handles the resulting disc-layout shift."""
    if len(payload) > RESIDENCY_MAX:
        raise ValueError(f"payload {len(payload)} > free window {RESIDENCY_MAX}")
    m = bytearray(open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read())
    assert len(m) == MAIN_L_END, f"unexpected MAIN_L size {len(m):#x}"
    m += b"\x00" * (RESIDENCY_FILE - len(m))       # zero-pad gap (BSS-cleared range)
    assert len(m) == RESIDENCY_FILE
    m += payload
    if len(m) & 1:
        m += b"\x00"
    for off, patch in hooks:
        m[off:off + len(patch)] = patch
    return bytes(m)


def sample_call_hook(target_addr):
    """Build a hook that DIVERTS an existing near call site to `target_addr`.
    Returns the 2-byte bsr/bra encoding — caller must place it where the delay
    slot semantics are safe. Provided for tests; real hooks are chosen per site.
    """
    # placeholder — real hooks computed against a specific call site by the caller
    raise NotImplementedError


if __name__ == "__main__":
    # self-test: inject a trivial routine, verify residency bytes + disasm
    import sh2_asm
    src = """
    .section .text
    .global _start
_start:
    mov     r4, r0
    add     r5, r0
    rts
    nop
"""
    payload = sh2_asm.assemble(src, RESIDENCY)
    patched = build_main_l(payload, hooks=[(0x1208, struct.pack(">I", RESIDENCY))])
    got = patched[RESIDENCY_FILE:RESIDENCY_FILE + len(payload)]
    print(f"MAIN_L grown {MAIN_L_END:#x} -> {len(patched):#x}; payload at RAM {RESIDENCY:#x}")
    print("residency bytes:", got.hex())
    assert got == payload, "payload not placed correctly"
    assert struct.unpack_from(">I", patched, 0x1208)[0] == RESIDENCY, "hook not applied"
    assert patched[MAIN_L_END:RESIDENCY_FILE] == b"\x00"*(RESIDENCY_FILE-MAIN_L_END), "gap not zero"
    for a, mn, op in sh2_asm.disasm(got, RESIDENCY):
        print(f"  {a:#010x}: {mn} {op}")
    print("OK: payload above BSS, hook applied, gap zero-padded")
