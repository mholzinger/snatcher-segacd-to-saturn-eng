/* Real glyph renderer. Every frame-sync, walk the VDP1 command list; for each
 * text sprite read the char from its line-buffer cell (sprite i == cell i, proven),
 * reverse-map SJIS -> our 95-glyph half-width font, and write the glyph to the
 * address the sprite ACTUALLY reads: 0x25C00000 + CMDSRCA*8 (proven correct).
 * Chars not in our table (kanji speaker names) are skipped -> game font stays.
 * Glyph is drawn in a 16px-wide 4bpp texture (8 bytes/row): our 8px glyph in the
 * left half, right half blank. Tight spacing comes later via the pitch table.
 * Tail-call the real frame-sync (pr preserved). */
typedef unsigned char u8;
typedef unsigned short u16;

static void (*const orig)(void) = (void (*)(void))0x060b55a0u;
static const u16 ascii_sjis[95] = {
#include "ascii_sjis.h"
};
static const u8 font1bpp[95 * 16] = {   /* ASCII order 0x20-0x7e, 8px 1bpp, 1 byte/row */
#include "font1bpp_ascii.h"
};

void __attribute__((section(".text.frame"))) frame(void)
{
    volatile u16 *cmd = (volatile u16 *)0x25c00000u;    /* VDP1 command list */
    volatile u16 *lb  = (volatile u16 *)0x060f28aau;    /* line buffer, 4 bytes/cell */
    int i, g, k, r, j, col, cell, dx;
    int row = -1, x0 = 0, prev_y = -1;

    for (i = 0; i < 300; i++) {
        u16 ctrl = cmd[i * 16 + 0];
        if (ctrl == 0x8000) break;                      /* draw-end */
        u16 srca = cmd[i * 16 + 4];
        if (!((ctrl & 0xf) == 0 && srca >= 0x1000 && srca <= 0x2100))
            continue;

        /* Derive the line-buffer cell from screen position, NOT a sprite counter:
         * sprites are grouped by row (Y), some cells have no sprite (kanji gaps).
         * New Y => next row; first sprite in a row = col 0 => its X is the origin. */
        int y = cmd[i * 16 + 7];
        int x = cmd[i * 16 + 6];
        if (y != prev_y) { row++; prev_y = y; x0 = x; }
        dx = x - x0; col = 0;
        while (dx >= 14) { dx -= 14; col++; }            /* pitch 14, no divide */
        cell = row * 20 + col;
        if (cell < 0 || cell >= 80) continue;

        u16 sjis = lb[cell * 2];                          /* [hi][lo] = SJIS code */

        g = -1;
        for (k = 0; k < 95; k++)
            if (ascii_sjis[k] == sjis) { g = k; break; }
        if (g < 0) continue;                             /* kanji/no glyph: leave game's */

        /* The game's font cache collides different Latin letters onto one slot
         * (srca = f(SJIS), many-to-one). Give this cell a PRIVATE slot in the big
         * free VRAM gap and repoint its CMDSRCA there, so no two cells share. */
        u16 new_srca = 0x4000 + (u16)(cell * 0x10);      /* addr 0x25c20000 + cell*0x80 */
        cmd[i * 16 + 4] = new_srca;
        u8 *d = (u8 *)(0x25c00000u + (unsigned)new_srca * 8u);
        const u8 *s = font1bpp + g * 16;                 /* 16 bytes = 16 rows x 1 byte */
        for (r = 0; r < 16; r++) {
            u8 v = s[r];                                 /* 8 px, 1bpp */
            for (j = 0; j < 4; j++) {                    /* expand -> 4 bytes 4bpp */
                u8 hi = (v & 0x80) ? 0xF0 : 0; v <<= 1;
                u8 lo = (v & 0x80) ? 0x0F : 0; v <<= 1;
                *d++ = hi | lo;
            }
            *d++ = 0; *d++ = 0; *d++ = 0; *d++ = 0;      /* right 8px blank */
        }
    }
    orig();
}
