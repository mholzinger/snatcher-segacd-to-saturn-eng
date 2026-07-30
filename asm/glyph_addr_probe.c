/* Corrected glyph-address probe. Write a solid block to the address each text
 * sprite ACTUALLY reads: 0x25C00000 + CMDSRCA*8 (not my old bogus slot formula).
 * If every dialogue char turns into a solid top-half block, the address + timing
 * are confirmed and the real renderer is just "block -> glyph". Tail-call frame-sync. */
typedef unsigned char u8;
typedef unsigned short u16;
static void (*const orig)(void) = (void (*)(void))0x060b55a0u;

void __attribute__((section(".text.frame"))) frame(void)
{
    volatile u16 *cmd = (volatile u16 *)0x25c00000u;   /* VDP1 command list */
    int i, r, b;
    for (i = 0; i < 300; i++) {
        u16 ctrl = cmd[i * 16 + 0];
        if (ctrl == 0x8000) break;                      /* draw-end */
        u16 srca = cmd[i * 16 + 4];
        if ((ctrl & 0xf) == 0 && srca >= 0x1000 && srca <= 0x2100) {
            u8 *d = (u8 *)(0x25c00000u + (unsigned)srca * 8u);  /* REAL glyph addr */
            for (r = 0; r < 16; r++)                     /* 16px wide 4bpp = 8 bytes/row */
                for (b = 0; b < 8; b++)
                    *d++ = (r < 8) ? 0xFF : 0x00;        /* solid top half */
        }
    }
    orig();
}
