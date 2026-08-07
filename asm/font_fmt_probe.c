/* VDP1 8px-sprite texture-format probe. Write a KNOWN shape into every dialogue
 * glyph slot and look at how an 8px-wide sprite renders it — no guessing.
 * Shape: 16 rows of 4 bytes (the 8px/4bpp pitch hypothesis); TOP 7 rows solid
 * (0xFF = two bright pixels/byte), BOTTOM 9 rows empty.
 *   correct  -> each char cell shows a solid block in its TOP half, 8px wide, tight
 *   squished -> block compressed / offset  (height or pitch wrong)
 *   striped  -> block interleaved          (row stride wrong)
 * The distortion is the diagnosis.  Tail-call the real frame-sync. */
typedef unsigned char u8;
static void (*const orig)(void) = (void (*)(void))0x060b55a0u;

void __attribute__((section(".text.frame"))) frame(void)
{
    int slot, r, b;
    for (slot = 0x40; slot <= 0x9f; slot++) {           /* dialogue glyph slots */
        u8 *d = (u8 *)(0x25c08000u + ((unsigned)slot << 7));
        for (r = 0; r < 16; r++)
            for (b = 0; b < 4; b++)                      /* 4 bytes/row = 8px @4bpp */
                *d++ = (r < 7) ? 0xFF : 0x00;
    }
    orig();
}
