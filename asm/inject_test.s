    .text
    .global _start
! First-injection proof (v3): resident ABOVE BSS at 0x060FF090 (not BSS-cleared,
! not an in-file read table, above the low stack). Hooked into the font-upload
! call pointer (MAIN_L file 0x1208). Writes marker to 0x060FF800 (also above BSS),
! then TAIL-CALLs the real font upload (0x060B4530). Flow unchanged.
_start:
    mov.l   .marker_addr, r1
    mov.l   .marker_val, r0
    mov.l   r0, @r1
    mov.l   .orig, r0
    jmp     @r0
    nop
    .align 2
.marker_addr: .long 0x060FF800
.marker_val:  .long 0x0DEADBEE
.orig:        .long 0x060B4530
