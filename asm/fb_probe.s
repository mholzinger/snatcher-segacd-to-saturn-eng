! VDP1 framebuffer probe. Every frame-sync, fill a block of the VDP1 framebuffer
! (SH-2 view 0x25C80000, 16bpp RGB555) with white, then tail-call the real sync.
! If a white block appears on screen, direct FB writes work (and survive the erase)
! -> we can point font.c at the framebuffer and draw our own text.  Hook: frame-sync
! ptr at MAIN_L file 0x472c.
    .text
    .global _start
_start:
    mov.l   dst, r1              ! VDP1 framebuffer
    mov.l   cnt, r2
    mov.l   pat, r3              ! two RGB555 white pixels
fill:
    mov.l   r3, @r1
    add     #4, r1
    dt      r2
    bf      fill
    mov.l   orig, r0             ! tail-call the real frame-sync (pr preserved)
    jmp     @r0
    nop
    .align 2
dst:    .long 0x25c80000
cnt:    .long 0x00002000         ! 0x2000 longwords = 32 KB (a visible block)
pat:    .long 0x7fff7fff
orig:   .long 0x060b55a0
