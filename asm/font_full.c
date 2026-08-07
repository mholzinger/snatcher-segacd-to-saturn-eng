/* Full half-width font writer. Every frame-sync, expand all 95 half-width glyphs
 * (stored 1bpp, ~3KB) to 4bpp and write each to its dialogue-cache slot at
 * VDP1 VRAM 0x25C08000 + slot*0x80.  slots[]/font1bpp[] are in priority order
 * (letters last) so letters win the SJIS-low-byte collisions.  Then tail-call the
 * real frame-sync.  Compiled with sh-elf-gcc, linked so `frame` sits at RESIDENCY. */
typedef unsigned char u8;

static void (*const orig)(void) = (void (*)(void))0x060b55a0u;   /* real frame-sync */
static const u8 slots[95] = {
#include "slots.h"
};
static const u8 font1bpp[95 * 32] = {
#include "font1bpp.h"
};

typedef unsigned short u16;

void __attribute__((section(".text.frame"))) frame(void)
{
    int g, b, k, i;
    /* 1) write all 95 half-width glyphs into the dialogue glyph cache,
     * PACKED as 8px-wide rows (4 bytes/row) to match the 8px sprite width:
     * an 8px-wide VDP1 sprite reads 4 bytes per row, so the texture must be
     * stored at that pitch.  Source 1bpp rows are 2 bytes (16px); the glyph
     * lives in the LEFT byte -> take byte 0 of each row pair only. */
    for (g = 0; g < 95; g++) {
        u8 *d = (u8 *)(0x25c08000u + ((unsigned)slots[g] << 7));   /* slot*0x80 */
        const u8 *s = font1bpp + g * 32;
        for (b = 0; b < 32; b += 2) {          /* 16 rows; use left byte only */
            u8 v = s[b];                       /* 8 1bpp pixels -> 4 4bpp bytes */
            for (k = 0; k < 4; k++) {
                u8 hi = (v & 0x80) ? 0xF0 : 0; v <<= 1;
                u8 lo = (v & 0x80) ? 0x0F : 0; v <<= 1;
                *d++ = hi | lo;
            }
        }
    }
    /* 2) trim every text sprite from 16px-wide (CMDSIZE 0x020e) to 8px (0x010e) */
    {
        volatile u16 *cmd = (volatile u16 *)0x25c00000u;   /* VDP1 command list */
        for (i = 0; i < 300; i++) {
            u16 ctrl = cmd[i * 16 + 0];
            if (ctrl == 0x8000) break;                     /* draw-end */
            u16 srca = cmd[i * 16 + 4];
            if ((ctrl & 0xf) == 0 && srca >= 0x1000 && srca <= 0x2100)
                cmd[i * 16 + 5] = 0x010e;                  /* 8px wide, 14 tall */
        }
    }
    orig();
}
