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
static void (*const orig_fontup)(void)   = (void (*)(void))0x060b4530u;

#ifndef DLG_COLS
#define DLG_COLS 26          /* dialogue cells/row (must match build_engine COLS) */
#endif
static void set_table(int cols);   /* per-call dialogue/menu geometry swap (below) */

static const u16 ascii_sjis[95] = {
#include "ascii_sjis.h"
};
static const u8 font1bpp[95 * 16] = {   /* ASCII 0x20-0x7e, 8px 1bpp, 1 byte/row */
#include "font1bpp_ascii.h"
};

/* Half-width font substitution. The game font is bitplane-packed: 4 chars share a
 * 4bpp tile, each char = one bit-plane (bit 0-3), isolated by a per-sprite LUT.
 * For A..Za..z, glyph_index = 49 + rank; tile_slot = index/4; bit = index%4; tile
 * at 0x25c08000 + slot*0x70 (16px wide, 14 rows, 8 bytes/row). We load the game
 * font, then write our 8px glyph into each char's bit-plane (left 8px; clear the
 * right so it reads narrow), preserving the other planes. LUTs stay untouched. */
/* game glyph_index -> ASCII char whose 8px form we stamp into that slot's plane.
 * Read DIRECTLY from the font cache (savestate render), not extrapolated: digits
 * 39-48 sit just below A=49; punctuation is in 0..34. Letters A..Za..z = 49+rank
 * are handled by the loop below. Extend this table as more glyphs are confirmed. */
static const u8 subidx[] = {
    3,   4,   5,   6,   7,   8,   9,  10,  13,  14,  16,  17,  24,  25,  27,
    30,  31,  32,  33,  34,
    39,  40,  41,  42,  43,  44,  45,  46,  47,  48
};
static const u8 subchr[] = {
    ',', '.', '\'', ':', ';', '?', '!', '_', '/', '~', '(', ')', '+', '-', '=',
    '%', '#', '&', '*', '@',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

/* stamp our 8px glyph for ASCII `c` into the plane of game glyph index `gi` */
static void stampglyph(int gi, int c)
{
    static const u8 lom[4] = {0x01, 0x02, 0x04, 0x08};
    static const u8 him[4] = {0x10, 0x20, 0x40, 0x80};
    int r, col, bit = gi & 3;
    volatile u8 *tile = (volatile u8 *)(0x25c08000u + (gi / 4) * 0x70u);
    const u8 *g = font1bpp + (c - 0x20) * 16;          /* our 8px glyph, 1 byte/row */
    for (r = 0; r < 14; r++) {
        u8 gv = g[r + 1];                              /* rows 1..14 of our 16-row glyph */
        for (col = 0; col < 16; col++) {
            volatile u8 *pb = &tile[r * 8 + (col >> 1)];
            u8 mask = (col & 1) ? lom[bit] : him[bit];
            int ink = (col < 8) && (gv & 0x80);
            if (col < 8) gv = (u8)(gv << 1);
            if (ink) *pb = (u8)(*pb | mask); else *pb = (u8)(*pb & ~mask);
        }
    }
}

void __attribute__((section(".text.fontblock"))) fontblock(void)
{
    int rank, i;
    orig_fontup();
    for (rank = 0; rank < 52; rank++) {                /* A..Za..z = 49+rank */
        int c = (rank < 26) ? ('A' + rank) : ('a' + rank - 26);
        stampglyph(49 + rank, c);
    }
    for (i = 0; i < (int)sizeof(subidx); i++)          /* digits + punctuation */
        stampglyph(subidx[i], subchr[i]);
}

/* Map logger (dev tool). Hooked at frame-sync; accumulates each grid-row text
 * sprite's (line-buffer SJIS, CMDSRCA, CMDCOLR) into a scratch table above the
 * payload, deduped by SJIS, across all frames — so any savestate carries the map
 * for every character that has rendered. Python turns (srca,colr) into the glyph
 * index. Skips row 0 (mixed pitch). Table: [count:u16][sjis,srca,colr]*N at 0x060ffc10. */
void __attribute__((section(".text.logger"))) logger(void)
{
    volatile u16 *cmd = (volatile u16 *)0x25c00000u;
    volatile u16 *lb  = (volatile u16 *)0x060f28aau;
    volatile u16 *tbl = (volatile u16 *)0x060ffc10u;
    int i, row = -1, x0 = 0, prev_y = -1, col, cell, dx, j;
    for (i = 0; i < 300; i++) {
        u16 ctrl = cmd[i * 16 + 0];
        if (ctrl == 0x8000) break;
        u16 srca = cmd[i * 16 + 4], colr = cmd[i * 16 + 3];
        if (!((ctrl & 0xf) == 0 && srca >= 0x1000 && srca <= 0x2100)) continue;
        int y = cmd[i * 16 + 7], x = cmd[i * 16 + 6];
        if (y != prev_y) { row++; prev_y = y; x0 = x; }
        if (y <= 158) continue;                     /* skip row 0 (X=9/pitch-14 path) */
        dx = x - x0; col = 0;
        while (dx >= 8) { dx -= 8; col++; }          /* grid pitch = 8 (GEOM) */
        cell = row * 20 + col;
        if (cell < 0 || cell >= 80) continue;
        u16 sjis = lb[cell * 2];
        if (sjis == 0) continue;
        {
            int cnt = tbl[0], found = 0;
            for (j = 0; j < cnt; j++) if (tbl[1 + j * 3] == sjis) { found = 1; break; }
            if (!found && cnt < 128) {
                tbl[1 + cnt * 3] = sjis; tbl[2 + cnt * 3] = srca; tbl[3 + cnt * 3] = colr;
                tbl[0] = (u16)(cnt + 1);
            }
        }
    }
    orig_frame();
}

/* Dev tool: per-frame ring log of the dialogue VM's SCRIPT POINTER (low 16 bits of
 * 0x060f2a3c) + typing timer (0x060f2a04), so a savestate after pressing "advance"
 * shows the full trajectory: typing (timer>0) -> waiting (timer=0, ptr static) ->
 * advance (ptr jumps). Reveals the exact advance frame + command structure for paging.
 * Rings of 128 u16 each: head@0x060ffc10, ptr-low@0x060ffc12, timer@0x060ffd12. */
void __attribute__((section(".text.statelog"))) statelog(void)
{
    volatile u16 *head = (volatile u16 *)0x060ffc10u;
    volatile u16 *pbuf = (volatile u16 *)0x060ffc12u;   /* script ptr low-16 */
    volatile u16 *tbuf = (volatile u16 *)0x060ffd12u;   /* typing timer */
    volatile u16 *sptr = (volatile u16 *)0x060f2a3eu;   /* low half of 0x060f2a3c */
    volatile u16 *tmr  = (volatile u16 *)0x060f2a04u;
    u16 h = *head;
    pbuf[h & 0x7f] = *sptr;
    tbuf[h & 0x7f] = *tmr;
    *head = (u16)(h + 1);
    orig_frame();
}

/* Paging foundation test: frame-sync wrapper that reads the pad global (0x060f2422,
 * active-low, A=0x04) and SWALLOWS the first 3 fresh A-presses (sets the A bit back
 * so the VM tick — which runs inside orig_frame — never sees them). If the dialogue
 * refuses to advance for 3 A-presses then works, the pad address + A-bit + consume
 * mechanism are all confirmed. count@0x060ffc30, prevA@0x060ffc32. */
/* Trampoline replacement for the input-edge routine FUN_060b2134 (its first instruction
 * is patched to jmp here). Faithfully reimplements it: walks param_2 for the connected
 * pad, then for that pad sets current/prev/edge-pressed/edge-released in param_1[0..3].
 * THEN, for the DIALOGUE input struct (param_1 == 0x060f2710), masks the advance edge
 * (A=0x0400 | C=0x0200 | Start=0x0800) out of edge-pressed — so the advance-check that
 * runs right after sees no press. This is the correct injection point: after the edge is
 * computed, before it's read. (Test build masks unconditionally; real build gates on a
 * pending-page flag.) */
void __attribute__((section(".text.pagehook")))
inputcompute(unsigned short *p1, char *p2, int p3)
{
    if (p3 != 0) {
        do {
            if (*p2 == 0) break;
            p3--; p2 += 4;
        } while (p3 != 0);
        if (p3 != 0) {
            unsigned short *pv = p1 + 1;
            *pv = *p1;                                          /* prev = current */
            unsigned short cur = (unsigned short)~((unsigned short)(unsigned char)p2[3]
                                 + (unsigned short)(unsigned char)p2[2] * 0x100);
            *p1 = cur;                                          /* current (active high) */
            p1[2] = (unsigned short)(~*pv & cur);               /* edge-pressed */
            p1[3] = (unsigned short)(~*p1 & *pv);               /* edge-released */
            {   /* GATED consume: only at the dialogue struct, only while a page is
                 * pending (flag@0x060ffc34 set by decode()), only on a real A/C/Start
                 * press — then eat it and clear the flag so the NEXT press advances. */
                volatile unsigned char *pend = (volatile unsigned char *)0x060ffc34u;
                if ((unsigned)p1 == 0x060f2710u && *pend && (p1[2] & 0x0E00)) {
                    p1[2] = (unsigned short)(p1[2] & ~0x0E00);
                    *pend = 0;
                }
            }
            return;
        }
    }
    *p1 = 1;
    p1[2] = 0;
}

/* ---- hook 1: record decoder (must be first = entry at RESIDENCY) ---- */
char __attribute__((section(".text.decode"))) *decode(char *p)
{
    if (!p) return orig_decode(p);
    /* Dialogue and menus share the render table but need different geometry
     * (dialogue 26/row fills the box; menus 20/row for their 2-col layout). The
     * caller tells us which: dialogue passes a real LWRAM chunk pointer, menus pass
     * an HWRAM copy of the record. Swap the table's X/Y to match before it renders. */
    {
        unsigned up0 = (unsigned)p;
        int dlg = (up0 >= 0x00200000u && up0 < 0x00400000u) ||
                  (up0 >= 0x20200000u && up0 < 0x20400000u);
        set_table(dlg ? DLG_COLS : 20);
    }
    /* KEY redirect: a record of [0x04][off_hi][off_mid][off_lo] means "the real
     * (untruncated) 1-byte-encoded text is at p + offset" — the full-English blob
     * appended to this loaded chunk. Redirect the read pointer, then decode as
     * normal. This is what lifts text past the record's tiny byte budget. */
    /* KEY = [0x01][0x04][roff:2BE][boff:2BE], both offsets relative to the chunk's
     * text-section start (ts). Dialogue calls pass a real LWRAM chunk pointer, so
     * text_start = p - roff and we cache it. Menus pass a detached HWRAM copy of
     * the record (buffer 0x060FAC60) — there p-relative fails, so we reuse the
     * cached text_start. blob = text_start + boff. (Cache lives above the payload.) */
    char *start = p;
    if ((u8)p[0] == 0x01 && (u8)p[1] == 0x04) {
        unsigned roff = ((unsigned)(u8)p[2] << 8) | (u8)p[3];
        unsigned boff = ((unsigned)(u8)p[4] << 8) | (u8)p[5];
        volatile char **g_text = (volatile char **)0x060ffc00u;
        unsigned up = (unsigned)p;
        char *text;
        if ((up >= 0x00200000u && up < 0x00400000u) ||
            (up >= 0x20200000u && up < 0x20400000u)) {   /* LWRAM chunk pointer */
            text = p - roff;
            *g_text = text;
            *(volatile u8 *)0x060ffc34u = 1;   /* page pending: this is a dialogue record */
        } else {                                          /* HWRAM copy buffer */
            text = *g_text;
        }
        start = text + boff;
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

/* Rewrite the dialogue X-grid geometry to `cols` cells/row (8px pitch, 15px rows).
 * Only s4(X,+8) and s5(Y,+10) per 12-byte entry; the renderer fills s2/s3 each frame.
 * No divide (SH-2): running col/row counters; shifts are fixed. Skips if unchanged. */
static void set_table(int cols)
{
    static int last = 0;
    volatile u16 *e = (volatile u16 *)0x060e5358u;
    int i, col = 0, row = 0;
    if (cols == last) return;
    last = cols;
    for (i = 0; i < 80; i++) {
        e[i * 6 + 4] = (u16)(0x13 + (col << 3));         /* X = 0x13 + col*8  */
        e[i * 6 + 5] = (u16)(0x9e + (row << 4) - row);   /* Y = 0x9e + row*15 */
        col++;
        if (col == cols) { col = 0; row++; }
    }
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
