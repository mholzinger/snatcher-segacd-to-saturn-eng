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
#ifndef DLG_MAXROWS
#define DLG_MAXROWS 2        /* rows per page (must match build_engine MAXROWS) */
#endif
static void set_table(int cols);        /* per-call dialogue/menu geometry swap (below) */
static char *split_page(char *s, int maxrows);   /* paging: cut one page, return next (below) */
static void clear_box(void);            /* blank the dialogue line buffer (below) */
static void fill_page(char *sjis);      /* manually lay a page into the line buffer (below) */

/* Paging scratch (above BSS): [0x060fffe0]=g_text, [0x060fffe4]=u8 page-pending, [0x060fffe8]=char* next page. */

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
    *(volatile u8 *)0x060fffe4u = 0;   /* reset paging state at scene load */
    for (rank = 0; rank < 52; rank++) {                /* A..Za..z = 49+rank */
        int c = (rank < 26) ? ('A' + rank) : ('a' + rank - 26);
        stampglyph(49 + rank, c);
    }
    for (i = 0; i < (int)sizeof(subidx); i++)          /* digits + punctuation */
        stampglyph(subidx[i], subchr[i]);
}

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
            {   /* PAGING: at the dialogue struct, while a page is pending, on a real
                 * A/C/Start press: eat the advance and render the next page DIRECTLY into
                 * the line buffer. Debugger-confirmed: at the ◇ wait the game does NOT
                 * rewrite the line buffer (0x060f28aa) — the layout only runs on advance,
                 * and the renderer re-scans the 80 cells every frame. So a plain memory
                 * write here (fill_page = no VM calls) sticks and shows next frame. */
                volatile unsigned char *pend = (volatile unsigned char *)0x060fffe4u;
                if ((unsigned)p1 == 0x060f2710u && *pend && (p1[2] & 0x0E00)) {
                    char *page = *(char **)0x060fffe8u;
                    unsigned gv = (unsigned)page;
                    p1[2] = (unsigned short)(p1[2] & ~0x0E00);   /* consume the advance */
                    if (gv >= 0x00200000u && gv < 0x06100000u) {
                        char *next = split_page(page, DLG_MAXROWS);
                        fill_page(page);                          /* direct line-buffer write */
                        *(char **)0x060fffe8u = next;
                        *pend = (unsigned char)(next != 0);
                    } else {
                        *pend = 0;
                    }
                }
            }
            return;
        }
    }
    *p1 = 1;
    p1[2] = 0;
}

/* Deferred page redraw. inputcompute() only sets the signal (calling the fill routine
 * from inside the input poll re-enters the VM and hangs); the render happens here at the
 * frame-sync — a safe standalone point. Fill the box with the next page, advance to the
 * page after, clear the pending flag once the last page has shown. */
void __attribute__((section(".text.pagehook"))) redraw_hook(void)
{
    volatile unsigned char *sig = (volatile unsigned char *)0x060fffecu;
    if (*sig) {
        char *page = *(char **)0x060fffe8u;
        unsigned pv = (unsigned)page;
        volatile unsigned char *pend = (volatile unsigned char *)0x060fffe4u;
        *sig = 0;
        if (pv >= 0x00200000u && pv < 0x06100000u) {
            char *next = split_page(page, DLG_MAXROWS);
            fill_page(page);                             /* manual line-buffer write */
            *(char **)0x060fffe8u = next;
            *pend = (unsigned char)(next != 0);
        } else {
            *pend = 0;
        }
    }
    orig_frame();
}

/* Terminate the SJIS string `s` after `maxrows` rows (¥ = 0x81 0x8f = row break) and
 * return the start of the next page, or 0 if `s` was the last page. decode() output is
 * uniformly 2-byte SJIS, so we step 2 bytes per char. */
static char *split_page(char *s, int maxrows)
{
    int br = 0;
    while ((u8)*s) {
        if ((u8)s[0] == 0x81 && (u8)s[1] == 0x8f) {   /* ¥ / row break */
            br++;
            if (br == maxrows) { s[0] = 0; s[1] = 0; return s + 2; }
        }
        s += 2;
    }
    return 0;
}

/* Blank the dialogue line buffer (80 cells x 4 bytes) so a shorter next page can't leave
 * the previous page's tail behind. 0x889e = the game's blank-cell SJIS. */
static void clear_box(void)
{
    volatile u16 *lb = (volatile u16 *)0x060f28aau;
    int i;
    for (i = 0; i < 80; i++) { lb[i * 2] = 0x889e; lb[i * 2 + 1] = 0; }
}

/* Lay a decoded SJIS page directly into the dialogue line buffer (0x060f28aa, cells of
 * [SJIS:2][color:1][00:1]). Body starts at row 1 (cell 26) to keep the speaker in row 0;
 * ¥ (0x81 0x8f) advances to the next row. Colour 0x07 = white body text. Avoids calling
 * the game's fill routine, which re-enters and hangs. */
static void fill_page(char *sjis)
{
    volatile u16 *lb = (volatile u16 *)0x060f28aau;
    int cell = 26, i;
    for (i = 26; i < 80; i++) { lb[i * 2] = 0x889e; lb[i * 2 + 1] = 0; }  /* clear rows 1-3 */
    while ((u8)*sjis && cell < 80) {
        if ((u8)sjis[0] == 0x81 && (u8)sjis[1] == 0x8f) {   /* ¥ row break */
            cell = (cell / 26 + 1) * 26;
            sjis += 2; continue;
        }
        lb[cell * 2]     = (u16)(((u8)sjis[0] << 8) | (u8)sjis[1]);   /* SJIS */
        lb[cell * 2 + 1] = 0x0700;                                    /* colour 0x07 */
        cell++;
        sjis += 2;
    }
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
#ifdef DIAG_ADVANCE
        /* DIAGNOSTIC: log (record ptr, caller return addr) for each dialogue decode
         * into a ring at 0x060fff00 [u32 idx][8 x (u32 rec, u32 caller)]. Read from a
         * savestate to find the record pointer's advance delta + the game's print path. */
        if (dlg) {
            volatile unsigned *ri = (volatile unsigned *)0x060fff00u;
            volatile unsigned *rb = (volatile unsigned *)0x060fff10u;
            unsigned idx = *ri & 7u;
            rb[idx * 2]     = up0;
            rb[idx * 2 + 1] = (unsigned)__builtin_return_address(0);
            *ri = idx + 1u;
        }
#endif
    }
    /* PAGING CONTINUING: print_hook() re-invoked the game's print command with the SAME
     * record while pages remain. Serve the next cached page directly — no re-decode, no
     * re-malloc (the line was converted once on the FRESH call; pages point into it). */
    {
        unsigned uu = (unsigned)p;
        int lw = (uu >= 0x00200000u && uu < 0x00400000u) ||
                 (uu >= 0x20200000u && uu < 0x20400000u);
        volatile u8 *pend = (volatile u8 *)0x060fffe4u;
        volatile char **glast = (volatile char **)0x060fffd8u;
        if (lw && *pend && p == (char *)*glast) {
            volatile unsigned *gidx = (volatile unsigned *)0x060fffe8u;   /* next page idx */
            volatile unsigned *pparr = (volatile unsigned *)0x060fffb4u;  /* page starts */
            volatile unsigned *gnp = (volatile unsigned *)0x060fffb0u;    /* page count */
            unsigned idx = *gidx;
            if (idx >= *gnp) { *pend = 0; }                 /* safety */
            else {
                *gidx = idx + 1;
                *pend = (u8)(idx + 1 < *gnp);
                return (char *)pparr[idx];
            }
        }
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
    int is_dlg = 0;
    if ((u8)p[0] == 0x01 && (u8)p[1] == 0x04) {
        unsigned roff = ((unsigned)(u8)p[2] << 8) | (u8)p[3];
        unsigned boff = ((unsigned)(u8)p[4] << 8) | (u8)p[5];
        volatile char **g_text = (volatile char **)0x060fffe0u;
        unsigned up = (unsigned)p;
        char *text;
        if ((up >= 0x00200000u && up < 0x00400000u) ||
            (up >= 0x20200000u && up < 0x20400000u)) {   /* LWRAM chunk pointer */
            text = p - roff;
            *g_text = text;
            is_dlg = 1;                          /* dialogue (not a menu copy) -> pageable */
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
    /* PAGING FRESH (new dialogue record): convert the full line ONCE, split it into
     * DLG_MAXROWS-row pages in place (terminating each boundary), and cache every page's
     * start pointer. print_hook() re-invokes print per page; those calls hit the
     * CONTINUING fast-path above and read straight from this cache — one malloc per line. */
    {
        volatile u8 *pend = (volatile u8 *)0x060fffe4u;
        if (is_dlg) {
            volatile char **glast = (volatile char **)0x060fffd8u;
            volatile unsigned *gidx = (volatile unsigned *)0x060fffe8u;
            volatile unsigned *pparr = (volatile unsigned *)0x060fffb4u;
            volatile unsigned *gnp = (volatile unsigned *)0x060fffb0u;
            char *page = out, *next;
            int n = 0;
            while (n < 8) {
                pparr[n++] = (unsigned)page;
                next = split_page(page, DLG_MAXROWS);         /* terminate page, next start */
                if (!next) break;
                page = next;
            }
            *gnp = (unsigned)n;
            *glast = p;
            *gidx = 1;
            *pend = (u8)(n > 1);
            return (char *)pparr[0];                          /* page 0 */
        }
        *pend = 0;
    }
    return out;
}

/* Paging wrapper for the VM's dialogue-print command (orig FUN_060b8390). The VM's
 * command table entry is repointed here. orig_print() does the whole safe cycle:
 * decode(record) -> lay text -> typewriter -> wait for A -> return. We just loop it
 * while decode reports more pages pending, so each page shows and waits for A in the
 * game's OWN synchronized context (no line-buffer poking, no 2nd-CPU race). */
typedef void (*printfn)(int, int, int, int);
void __attribute__((section(".text.pagehook")))
print_hook(int a4, int a5, int a6, int a7)
{
    volatile u8 *pend = (volatile u8 *)0x060fffe4u;
    int guard = 8;
    ((printfn)0x060b8390u)(a4, a5, a6, a7);                  /* page 1 */
    while (*pend && --guard > 0)
        ((printfn)0x060b8390u)(a4, a5, a6, a7);              /* subsequent pages */
    *pend = 0;                                               /* safety: never leave pending */
}

/* Row-0 render-table geometry. print_dialogue's own row-0 X loop (patched to jsr here)
 * always wrote a 14px pitch (right for the FULL-WIDTH Japanese speaker names in row 0,
 * but it stretches HALF-WIDTH English badly when a no-speaker line's body lands in row
 * 0). So make it conditional on the speaker flag (0x060f2aae): speaker present -> 14px
 * (start X=9), no speaker -> 8px (start X=0x13, matching body rows 1..3). Row 0 = 20
 * cells; X field is +8 (u16 index +4) of each 12-byte entry, like set_table(). */
void __attribute__((section(".text.pagehook"))) row0_geom(void)
{
    volatile u16 *e = (volatile u16 *)0x060e5358u;
    int col, x, pitch;
    if (*(volatile u16 *)0x060f2aaeu) { x = 9;    pitch = 14; }  /* JP speaker: full-width */
    else                              { x = 0x13; pitch = 8;  }  /* EN body: half-width     */
    for (col = 0; col < 20; col++) { e[col * 6 + 4] = (u16)x; x += pitch; }
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

