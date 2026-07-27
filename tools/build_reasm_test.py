#!/usr/bin/env python3
"""Boot-test build for the text-growth reassembler.

Grows chunk_022's JunkerHQ greeting (record @0x2a34, 44 bytes JP) to
"WELCOME TO JUNKER<br>HEADQUARTERS." (62 bytes, delta +18) via
tools/reassemble.py, then builds a bootable disc in build/reasm_test:
  - rebuilt chunk written over DATA.BIN sectors (chunk starts sector 58,
    grown size 41544 <= 43008 sector budget, 1482 bytes slack)
  - DATA.BIN index entry 22 size_words updated in MAIN_L.BIN on disc
    (index at MAIN_L 0x362F4, MAIN_L.BIN at LBA 5451)

Pass/fail in Mednafen: greeting shows the full grown English AND the scene
keeps working (menu, later dialogue) with no garbling. That confirms
h1 += delta is the complete growth fixup (no bytecode relocation needed).

Usage: build_reasm_test.py [src_disc_dir] [out_dir]
"""
import os
import shutil
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import reassemble

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR = 2352
USER = 16
DATA_BIN_LBA = 96
MAIN_LBA = 5451
INDEX_OFF = 0x362F4

CHUNK = 22
RECORD = 0x2A34
NEW_TEXT = "WELCOME TO JUNKER<br>HEADQUARTERS."


def write_file_bytes(track, file_lba, file_off, blob):
    """Write blob into a file inside the MODE1/2352 track image."""
    pos = file_off
    rem = blob
    while rem:
        lba = file_lba + pos // 2048
        ins = pos % 2048
        n = min(2048 - ins, len(rem))
        track.seek(lba * SECTOR + USER + ins)
        track.write(rem[:n])
        rem = rem[n:]
        pos += n


def main():
    src = sys.argv[1] if len(sys.argv) > 2 else os.path.join(ROOT, "iso/Snatcher (Japan) [Saturn]")
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(ROOT, "build/reasm_test")
    os.makedirs(out, exist_ok=True)

    main_bin = open(os.path.join(ROOT, "extracted/saturn/files/MAIN_L.BIN"), "rb").read()
    sec, words = struct.unpack_from(">HH", main_bin, INDEX_OFF + CHUNK * 4)
    next_sec = struct.unpack_from(">HH", main_bin, INDEX_OFF + (CHUNK + 1) * 4)[0]

    chunk = open(os.path.join(ROOT, f"extracted/saturn/data_bin/chunk_{CHUNK:03d}.bin"), "rb").read()
    new_bytes = reassemble.encode_text(NEW_TEXT)
    rebuilt = reassemble.rebuild_chunk(chunk, {RECORD: new_bytes})
    delta = len(rebuilt) - len(chunk)
    budget = (next_sec - sec) * 2048
    assert len(rebuilt) <= budget, f"grown chunk {len(rebuilt)} > sector budget {budget}"
    new_words = len(rebuilt) // 2
    print(f"chunk_{CHUNK:03d}: {len(chunk)} -> {len(rebuilt)} bytes (delta {delta:+d}), "
          f"size_words {words:#x} -> {new_words:#x}, budget {budget}")

    t1 = os.path.join(out, "Snatcher (Japan) (Track 1).bin")
    print("copying track 1...")
    shutil.copyfile(os.path.join(src, "Snatcher (Japan) (Track 1).bin"), t1)
    for n in (2, 3):
        dst = os.path.join(out, f"Snatcher (Japan) (Track {n}).bin")
        if not os.path.exists(dst):
            os.link(os.path.join(src, f"Snatcher (Japan) (Track {n}).bin"), dst)
    shutil.copyfile(os.path.join(src, "Snatcher (Japan).cue"), os.path.join(out, "Snatcher (Japan).cue"))

    with open(t1, "r+b") as f:
        # rebuilt chunk over its DATA.BIN sectors (pad to old footprint not needed;
        # only the indexed size is read)
        write_file_bytes(f, DATA_BIN_LBA, sec * 2048, rebuilt)
        # index entry: new size_words
        write_file_bytes(f, MAIN_LBA, INDEX_OFF + CHUNK * 4 + 2, struct.pack(">H", new_words))

    print(f'boot: mednafen "{os.path.join(out, "Snatcher (Japan).cue")}"')


if __name__ == "__main__":
    main()
