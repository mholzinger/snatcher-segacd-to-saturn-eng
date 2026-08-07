! VDP1-VRAM probe: fill part of the VDP1 font region with a bright pattern every
! time the per-char frame-sync runs, then tail-call the original sync.  If the
! on-screen text garbles, injected code controls the displayed text pixels
! (green-lights the bitmap text renderer).  Hook: repoint the frame-sync pointer
! at MAIN_L file 0x472c (-> FUN_060b55a0) to this routine.
    .text
    .global _start
_start:
    mov.l   vram_addr, r1        ! VDP1 VRAM (SH-2 view) + font offset
    mov.l   count, r2            ! longword count
    mov.l   pattern, r3
fill_loop:
    mov.l   r3, @r1
    add     #4, r1
    dt      r2
    bf      fill_loop
    mov.l   orig_fn, r0          ! tail-call the real frame-sync (pr preserved)
    jmp     @r0
    nop
    .align 2
vram_addr:  .long 0x25c08000
count:      .long 0x00001000     ! 0x1000 longwords = 16 KB of font glyphs
pattern:    .long 0xf0f0f0f0
orig_fn:    .long 0x060b55a0
