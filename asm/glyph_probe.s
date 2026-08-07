! Glyph-mapping probe (coarse, 8 bands). For each 0x80-byte glyph slot i in the
! dialogue glyph region (VDP1 VRAM 0x25C08000 + i*0x80, i=0..127): clear it, then
! draw a 2px white horizontal bar at row (i>>4)*2.  So every glyph in band k=i>>4
! shows a bar at vertical position k (0..7).  On a known-text screen each letter's
! bar HEIGHT reveals which band its glyph slot is in -> maps letters to a 16-slot
! range in one boot.  Hook: repoint frame-sync ptr (MAIN_L file 0x472c) here.
    .text
    .global _start
_start:
    mov     #0, r4               ! i = 0
    mov.l   base, r1
    mov.l   nslots, r7
outer:
    mov     r1, r5               ! clear glyph slot (0x80 bytes)
    mov     #32, r6
    mov     #0, r0
clr:
    mov.l   r0, @r5
    add     #4, r5
    dt      r6
    bf      clr
    mov     r4, r0               ! offset = i & 0xF0  (row = band*2, band = i>>4)
    and     #0xf0, r0
    mov     r1, r5
    add     r0, r5
    mov     #-1, r0              ! white
    mov.l   r0, @r5              ! bar row band*2 (8 bytes = full width)
    add     #4, r5
    mov.l   r0, @r5
    add     #4, r5
    mov.l   r0, @r5              ! bar row band*2+1 (2px thick)
    add     #4, r5
    mov.l   r0, @r5
    add     #1, r4               ! i++
    add     #0x40, r1            ! next glyph (+0x80 via two +0x40)
    add     #0x40, r1
    dt      r7
    bf      outer
    mov.l   orig, r0             ! tail-call the real frame-sync (pr preserved)
    jmp     @r0
    nop
    .align 2
base:   .long 0x25c08000
nslots: .long 128
orig:   .long 0x060b55a0
