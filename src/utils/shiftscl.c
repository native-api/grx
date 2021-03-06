/*
 * shiftscl.c ---- shift and copy an array (scanline)
 *                 for 1bpp and 4x1bpp frame driver blit operations
 *
 * Copyright (c) 1998 Hartmut Schirmer
 *
 * This file is part of the GRX graphics library.
 *
 * The GRX graphics library is free software; you can redistribute it
 * and/or modify it under some conditions; see the "copying.grx" file
 * for details.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "highlow.h"
#include "libgrx.h"

void _GR_shift_scanline(GR_int8u **dst, GR_int8u **src, int ws, int shift)
{
    GRX_ENTER();
    if (shift <= 0) {
        shift = -shift;
        GR_int8u *s = *(src++) + ws;
        GR_int8u *d = *(dst++) + ws;
#if defined(__GNUC__) && defined(__i386__)
        int _dummy_, w = ws;
        /* sad but true: the x86 bytesex forces this inefficient code :( */
        asm volatile(
            "\n"
            "   movb    (%0),%%ch    \n"
            "   jmp     1f           \n"
            "   .align  4,0x90       \n"
            "1: decl    %0           \n"
            "   movb    %%ch,%%al    \n"
            "   movb    (%0),%%ah    \n"
            "   movb    %%ah,%%ch    \n"
            "   shrl    %%cl,%%eax   \n"
            "   movb    %%al,(%1)    \n"
            "   decl    %1           \n"
            "   decl    %2           \n"
            "   jne     1b           \n"
            "   shrb    %%cl,%%ch    \n"
            "   movb    %%ch,(%1)      "
            : "=r"((void *)s), "=r"((void *)d), "=r"((int)w), "=c"(_dummy_)
            : "0"((void *)s), "1"((void *)d), "2"((int)w), "3"((int)shift)
            : "ax");
#else
        int w = ws;
        do {
            --s;
            *(d--) = highlowP(s) >> shift;
        } while (--w);
        *d = *s >> shift;
#endif
    }
    else {
        shift = 8 - shift;
        GR_int8u *s = *(src++);
        GR_int8u *d = *(dst++);
#if defined(__GNUC__) && defined(__i386__)
        int _dummy_, w = ws;
        asm volatile(
            "\n"
            "   movb    (%0),%%ch    \n"
            "   jmp     1f           \n"
            "   .align  4,0x90       \n"
            "1: incl    %0           \n"
            "   movb    %%ch,%%ah    \n"
            "   movb    (%0),%%al    \n"
            "   movb    %%al,%%ch    \n"
            "   shrl    %%cl,%%eax   \n"
            "   movb    %%al,(%1)    \n"
            "   incl    %1           \n"
            "   decl    %2           \n"
            "   jne     1b             "
            : "=r"((void *)s), "=r"((void *)d), "=r"((int)w), "=c"(_dummy_)
            : "0"((void *)s), "1"((void *)d), "2"((int)w), "3"((int)shift)
            : "ax");
#else
        int w = ws;
        do {
            *(d++) = highlowP(s) >> shift /* sh */;
            s++;
        } while (--w);
#endif
    }
    GRX_LEAVE();
}
