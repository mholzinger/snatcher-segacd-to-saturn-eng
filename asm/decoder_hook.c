/* ASCII-aware replacement for the record decoder FUN_060c4d24.
 * Original: strlen(p); out=malloc(len+1); for each byte *out = -byte; (negate =
 * 0x10100-SJIS token -> SJIS decode). This SUPERSET adds a 0x01 ASCII-mode
 * sentinel: after 0x01, bytes 0x20..0x7E are ASCII chars expanded to their
 * full-width SJIS (2 bytes each); a non-ASCII byte exits ASCII mode. Records
 * with no 0x01 decode identically to the original (transparent).
 * Compiled with sh-elf-gcc, linked at 0x060FF090, first function = entry. */
typedef unsigned char u8;
typedef unsigned short u16;

static char *(*const game_malloc)(int)  = (char *(*)(int))0x060c4f3cu;
static char *(*const orig_decode)(char*) = (char *(*)(char*))0x060c4d24u;

static const u16 ascii_sjis[95] = {
#include "ascii_sjis.h"
};

char *decode(char *p)
{
    if (!p) return orig_decode(p);            /* NULL path -> original */
    /* pass 1: output length */
    int len = 0, ascii = 0;
    char *q = p; u8 b;
    while ((b = (u8)*q++)) {
        if (!ascii) {
            if (b == 0x01) { ascii = 1; continue; }
            len += 1;
        } else if (b >= 0x20 && b <= 0x7E) {
            len += 2;
        } else { ascii = 0; len += 1; }
    }
    char *out = game_malloc(len + 1);
    char *o = out; ascii = 0; q = p;
    while ((b = (u8)*q++)) {
        if (!ascii) {
            if (b == 0x01) { ascii = 1; continue; }
            *o++ = (char)(-(int)b);
        } else if (b >= 0x20 && b <= 0x7E) {
            u16 s = ascii_sjis[b - 0x20];
            *o++ = (char)(s >> 8);
            *o++ = (char)(s & 0xFF);
        } else { ascii = 0; *o++ = (char)(-(int)b); }
    }
    *o = 0;
    return out;
}
