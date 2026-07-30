/* Combined resident payload: BOTH game hooks in one image at RESIDENCY.
 *   decode()  - entry at RESIDENCY - ASCII-aware record decoder (1-byte encoding
 *               -> full-width SJIS in the line buffer). Repointed from the 7
 *               DECODE_PTR literals. Gives ~2x English per record (fixes menu
 *               truncation + long dialogue).
 *   frame()   - font renderer at frame-sync. Reads each text sprite's cell from
 *               screen position, maps SJIS -> our half-width glyph, writes it to a
 *               PRIVATE per-cell VRAM slot (collision-free) and repoints CMDSRCA.
 * Shared tables: ascii_sjis[95], font1bpp[95*16]. Built -Os to fit the 3952-byte
 * window above BSS. decode() is first so it links exactly at RESIDENCY. */
typedef unsigned char u8;
typedef unsigned short u16;

static char *(*const game_malloc)(int)   = (char *(*)(int))0x060c4f3cu;
static char *(*const orig_decode)(char*) = (char *(*)(char*))0x060c4d24u;
static void (*const orig_frame)(void)    = (void (*)(void))0x060b55a0u;

static const u16 ascii_sjis[95] = {
#include "ascii_sjis.h"
};
static const u8 font1bpp[95 * 16] = {   /* ASCII 0x20-0x7e, 8px 1bpp, 1 byte/row */
#include "font1bpp_ascii.h"
};

/* ---- hook 1: record decoder (must be first = entry at RESIDENCY) ---- */
char __attribute__((section(".text.decode"))) *decode(char *p)
{
    if (!p) return orig_decode(p);
    /* KEY redirect: a record of [0x04][off_hi][off_mid][off_lo] means "the real
     * (untruncated) 1-byte-encoded text is at p + offset" — the full-English blob
     * appended to this loaded chunk. Redirect the read pointer, then decode as
     * normal. This is what lifts text past the record's tiny byte budget. */
    char *start = p;
    if ((u8)p[0] == 0x04) {
        unsigned off = ((unsigned)(u8)p[1] << 16) | ((unsigned)(u8)p[2] << 8) | (u8)p[3];
        start = p + off;
    }
    int len = 0, ascii = 0;
    char *q = start; u8 b;
    while ((b = (u8)*q++)) {
        if (b == 0x03) { len += 2; continue; }        /* 1-byte <br> -> ¥ */
        if (!ascii) { if (b == 0x01) { ascii = 1; continue; } len += 1; }
        else {
            if (b == 0x02) { ascii = 0; continue; }
            if (b >= 0x20 && b <= 0x7E) len += 2;
            else { ascii = 0; len += 1; }
        }
    }
    char *out = game_malloc(len + 1);
    char *o = out; ascii = 0; q = start;
    while ((b = (u8)*q++)) {
        if (b == 0x03) { *o++ = (char)0x81; *o++ = (char)0x8f; continue; }
        if (!ascii) { if (b == 0x01) { ascii = 1; continue; } *o++ = (char)(-(int)b); }
        else {
            if (b == 0x02) { ascii = 0; continue; }
            if (b >= 0x20 && b <= 0x7E) {
                u16 s = ascii_sjis[b - 0x20];
                *o++ = (char)(s >> 8); *o++ = (char)(s & 0xFF);
            } else { ascii = 0; *o++ = (char)(-(int)b); }
        }
    }
    *o = 0;
    return out;
}

/* ---- hook 2: font renderer at frame-sync ---- */
void __attribute__((section(".text.frame"))) frame(void)
{
    volatile u16 *cmd = (volatile u16 *)0x25c00000u;
    volatile u16 *lb  = (volatile u16 *)0x060f28aau;
    int i, g, k, r, j, col, cell, dx;
    int row = -1, x0 = 0, prev_y = -1;

    for (i = 0; i < 300; i++) {
        u16 ctrl = cmd[i * 16 + 0];
        if (ctrl == 0x8000) break;
        u16 srca = cmd[i * 16 + 4];
        if (!((ctrl & 0xf) == 0 && srca >= 0x1000 && srca <= 0x2100)) continue;

        int y = cmd[i * 16 + 7];
        int x = cmd[i * 16 + 6];
        if (y != prev_y) { row++; prev_y = y; x0 = x; }
        dx = x - x0; col = 0;
        while (dx >= 14) { dx -= 14; col++; }
        cell = row * 20 + col;
        if (cell < 0 || cell >= 80) continue;

        u16 sjis = lb[cell * 2];
        g = -1;
        for (k = 0; k < 95; k++) if (ascii_sjis[k] == sjis) { g = k; break; }
        if (g < 0) continue;                            /* kanji: leave game's */

        u16 new_srca = 0x4000 + (u16)(cell * 0x10);     /* private slot */
        cmd[i * 16 + 4] = new_srca;
        u8 *d = (u8 *)(0x25c00000u + (unsigned)new_srca * 8u);
        const u8 *s = font1bpp + g * 16;
        for (r = 0; r < 16; r++) {
            u8 v = s[r];
            for (j = 0; j < 4; j++) {
                u8 hi = (v & 0x80) ? 0xF0 : 0; v <<= 1;
                u8 lo = (v & 0x80) ? 0x0F : 0; v <<= 1;
                *d++ = hi | lo;
            }
            *d++ = 0; *d++ = 0; *d++ = 0; *d++ = 0;
        }
    }
    orig_frame();
}
