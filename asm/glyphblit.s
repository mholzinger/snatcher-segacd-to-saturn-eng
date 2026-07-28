    .section .text
    .global _start
! Glyph-blit primitive: copy `count` longwords from source to VDP1 VRAM.
! r4 = source addr (injected glyph data), r5 = dest VRAM, r6 = longword count.
! Saturn VDP1 VRAM is memory-mapped at 0x25C00000 — plain mov.l stores work.
_start:
    tst     r6, r6
    bt      done
copyloop:
    mov.l   @r4+, r0
    mov.l   r0, @r5
    add     #4, r5
    dt      r6
    bf      copyloop
done:
    rts
    nop
