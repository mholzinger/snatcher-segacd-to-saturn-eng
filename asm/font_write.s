! Write REAL half-width glyphs into the dialogue glyph cache every frame.
! Mapping (confirmed): glyph for SJIS code C lives at VDP1 VRAM 0x25C08000 +
! (C & 0xFF)*0x80.  Full-width Latin Ａ..Ｚ = SJIS 0x8260..0x8279 -> slots
! 0x60..0x79 -> VRAM 0x25C0B000..0x25C0BD00 (contiguous).  Copy 26 half-width
! glyphs (assets/hw_upper.bin, 832 longwords) there, then tail-call the frame-sync.
! Hook: repoint frame-sync ptr (MAIN_L file 0x472c) here.  On the English greeting,
! the UPPERCASE letters (W J U N K E R H Q M I) should render as clean half-width
! glyphs -> proves injected code writes proper text glyphs.
    .text
    .global _start
_start:
    mov.l   dst, r1              ! VDP1 VRAM slot 0x60 = 0x25C0B000
    mova    fontdata, r0         ! r0 = runtime address of embedded font
    mov     r0, r2               ! r2 = src
    mov.l   cnt, r3              ! 832 longwords
copy:
    mov.l   @r2+, r0
    mov.l   r0, @r1
    add     #4, r1
    dt      r3
    bf      copy
    mov.l   orig, r0             ! tail-call the real frame-sync (pr preserved)
    jmp     @r0
    nop
    .align 2
dst:    .long 0x25c0b000
cnt:    .long 832
orig:   .long 0x060b55a0
    .align 2
fontdata:
    .incbin "assets/hw_upper.bin"
