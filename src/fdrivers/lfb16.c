/**
 ** LFB16.C ---- the 32768/65536 color Super VGA linear frame buffer driver
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 ** Contributions by: (See "doc/credits.doc" for details)
 ** Hartmut Schirmer (hsc@techfak.uni-kiel.de)
 ** Andrzej Lawa [FidoNet: Andrzej Lawa 2:480/19.77]
 **/

/* some systems map LFB in normal user space (eg. Linux/svgalib) */
/* near pointer stuff is equal to ram stuff :)                   */
/* in this is the far pointer code using %fs descriptor          */
#ifndef LFB_BY_NEAR_POINTER

#ifdef   __TURBOC__
#error This library will not work with as a 16-bit real-mode code
#endif

#include "grdriver.h"
#include "libgrx.h"
#include "arith.h"
#include "mempeek.h"
#include "memfill.h"

#if BYTE_ORDER!=HARDWARE_BYTE_ORDER
#error Mismatching byte order between ram and video ram !
#endif

static
#ifdef __GNUC__
inline
#endif
long readpixel(GrFrame *c,int x,int y)
{
        long offs = umul32(y,SCRN->gc_lineoffset) + (x << 1);
        setup_far_selector(SCRN->gc_selector);
        return((ushort)peek_w_f(&SCRN->gc_baseaddr[0][offs]));
}

static
#ifdef __GNUC__
inline
#endif
void drawpixel(int x,int y,long color)
{
        long offs = umul32(y,CURC->gc_lineoffset) + (x << 1);
        char far *ptr = &CURC->gc_baseaddr[0][offs];
        setup_far_selector(CURC->gc_selector);
        switch(C_OPER(color)) {
            case C_XOR: poke_w_f_xor(ptr,(ushort)color); break;
            case C_OR:  poke_w_f_or( ptr,(ushort)color); break;
            case C_AND: poke_w_f_and(ptr,(ushort)color); break;
            default:    poke_w_f(    ptr,(ushort)color); break;
        }
}

static void drawhline(int x,int y,int w,long color)
{
        long offs = umul32(y,CURC->gc_lineoffset) + (x << 1);
        char far *pp = &CURC->gc_baseaddr[0][offs];
        int  cval = freplicate_w2l((int)color);
        setup_far_selector(CURC->gc_selector);
        switch(C_OPER(color)) {
            case C_XOR: repfill_w_f_xor(pp,cval,w); break;
            case C_OR:  repfill_w_f_or( pp,cval,w); break;
            case C_AND: repfill_w_f_and(pp,cval,w); break;
            default:    repfill_w_f(    pp,cval,w); break;
        }
}

static void drawvline(int x,int y,int h,long color)
{
        uint lwdt = CURC->gc_lineoffset;
        long offs = umul32(y,lwdt) + (x << 1);
        char far *pp = &CURC->gc_baseaddr[0][offs];
        setup_far_selector(CURC->gc_selector);
        switch(C_OPER(color)) {
            case C_XOR: colfill_w_f_xor(pp,lwdt,(int)color,h); break;
            case C_OR:  colfill_w_f_or( pp,lwdt,(int)color,h); break;
            case C_AND: colfill_w_f_and(pp,lwdt,(int)color,h); break;
            default:    colfill_w_f(    pp,lwdt,(int)color,h); break;
        }
}

static void drawblock(int x,int y,int w,int h,long color)
{
        int  skip = CURC->gc_lineoffset;
        char far *ptr = &CURC->gc_baseaddr[0][umul32(y,skip) + (x << 1)];
        int  cval = freplicate_w2l((int)color);
        int  ww;
        char far *pp;

        setup_far_selector(CURC->gc_selector);
        switch (C_OPER(color)) {
          case C_XOR: while (h-- != 0) {
                        ww = w;
                        pp = ptr;
                        repfill_w_f_xor(pp,cval,ww);
                        ptr += skip;
                      }
                      break;
          case C_OR:  while (h-- != 0) {
                        ww = w;
                        pp = ptr;
                        repfill_w_f_or(pp,cval,ww);
                        ptr += skip;
                      }
                      break;
          case C_AND: while (h-- != 0) {
                        ww = w;
                        pp = ptr;
                        repfill_w_f_and(pp,cval,ww);
                        ptr += skip;
                      }
                      break;
          default:    while (h-- != 0) {
                        ww = w;
                        pp = ptr;
                        repfill_w_f(pp,cval,ww);
                        ptr += skip;
                      }
                      break;
        }
}

#if defined(__GNUC__) && defined(__i386__)
static void drawline(int x,int y,int dx,int dy,long color)
{
        struct {
            int errsub;         /* subtract from error term */
            int erradd;         /* add to error term when carry */
            int offset1;        /* add to pointer if no carry on error term */
            int offset2;        /* add to pointer if carry / banking dir */
        } lndata;
        long offs;
        int  npts,error,xstep = 2;
        char far *ptr;

#       ifdef __GNUC__
#       ifdef __i386__
#       define ASM_LINE1(OPC) asm volatile("
            .align 2,0x90
         0: "#OPC"w %6,"I386_GCC_FAR_SELECTOR"(%0)
            subl %7,%2
            jb   1f
            leal -2(%3),%3
            decl %1
            jne  0b
            jmp  2f
            .align 2,0x90
         1: addl 4  + %7,%2
            addl 12 + %7,%3
            decl %1
            jne  0b
         2: "                                              \
         :  "=r" (ptr),         "=r" (npts), "=r" (error)  \
         :  "0"  ((long)(ptr)), "1"  (npts), "2"  (error), \
            "r"  ((short)(color)),     "o"  (lndata)       \
        )
#       define ASM_LINE2(OPC) asm volatile("
            .align 2,0x90
         0: "#OPC"w %6,"I386_GCC_FAR_SELECTOR"(%0)
            subl %7,%2
            jb   1f
            addl 8 + %7,%3
            decl %1
            jne  0b
            jmp  2f
            .align 2,0x90
         1: addl 4  + %7,%2
            addl 12 + %7,%3
            decl %1
            jne  0b
         2: "                                              \
         :  "=r" (ptr),         "=r" (npts), "=r" (error)  \
         :  "0"  ((long)(ptr)), "1"  (npts), "2"  (error), \
            "r"  ((short)(color)),     "o"  (lndata)       \
        )
#       endif
#       endif

        if(dy < 0) {
            y -= (dy = (-dy));
            x -= (dx = (-dx));
        }
        if(dx < 0) {
            xstep = (-2);
            dx    = (-dx);
        }
        offs = umul32(y,CURC->gc_lineoffset) + (x << 1);
        ptr  = &CURC->gc_baseaddr[0][offs];
        setup_far_selector(CURC->gc_selector);
        if(dx > dy) {
            npts  = dx +  1;
            error = dx >> 1;
            lndata.errsub  = dy;
            lndata.erradd  = dx;
            lndata.offset1 = xstep;
            lndata.offset2 = CURC->gc_lineoffset + xstep;
            if(xstep < 0) {
                lndata.offset1 = 1;
                switch(C_OPER(color)) {
                    case C_XOR: ASM_LINE1(xor); break;
                    case C_OR:  ASM_LINE1(or);  break;
                    case C_AND: ASM_LINE1(and); break;
                    default:    ASM_LINE1(mov); break;
                }
                return;
            }
        }
        else {
            npts  = dy +  1;
            error = dy >> 1;
            lndata.errsub  = dx;
            lndata.erradd  = dy;
            lndata.offset1 = CURC->gc_lineoffset;
            lndata.offset2 = CURC->gc_lineoffset + xstep;
        }
        switch(C_OPER(color)) {
            case C_XOR: ASM_LINE2(xor); break;
            case C_OR:  ASM_LINE2(or);  break;
            case C_AND: ASM_LINE2(and); break;
            default:    ASM_LINE2(mov); break;
        }
}
#else
static
#include "fdrivers/generic/line.c"
#endif

static
#include "fdrivers/generic/bitmap.c"

static
#include "fdrivers/generic/pattern.c"

static void bitblt(GrFrame *dst,int dx,int dy,
                   GrFrame *src,int sx,int sy,
                   int w,int h,long op)
{
        if(GrColorMode(op) == GrIMAGE) _GrFrDrvGenericBitBlt(
            dst,dx,dy,
            src,sx,sy,
            w,h,
            op
        );
        else _GrFrDrvPackedBitBltV2V_LFB(
            dst,(dx << 1),dy,
            src,(sx << 1),sy,
            (w << 1),h,
            op
        );
}

static void bltv2r(GrFrame *dst,int dx,int dy,GrFrame *src,int sx,int sy,int w,int h,long op)
{
        if(GrColorMode(op) == GrIMAGE) _GrFrDrvGenericBitBlt(
            dst,dx,dy,
            src,sx,sy,
            w,h,
            op
        );
        else _GrFrDrvPackedBitBltV2R_LFB(
            dst,(dx << 1),dy,
            src,(sx << 1),sy,
            (w << 1),h,
            op
        );
}

static void bltr2v(GrFrame *dst,int dx,int dy,GrFrame *src,int sx,int sy,int w,int h,long op)
{
        if(GrColorMode(op) == GrIMAGE) _GrFrDrvGenericBitBlt(
            dst,dx,dy,
            src,sx,sy,
            w,h,
            op
        );
        else _GrFrDrvPackedBitBltR2V_LFB(
            dst,(dx << 1),dy,
            src,(sx << 1),sy,
            (w << 1),h,
            op
        );
}

GrFrameDriver _GrFrameDriverSVGA16_LFB = {
    GR_frameSVGA16_LFB,         /* frame mode */
    GR_frameRAM16,              /* compatible RAM frame mode */
    TRUE,                       /* onscreen */
    4,                          /* scan line width alignment */
    1,                          /* number of planes */
    16,                         /* bits per pixel */
    16*16*1024L*1024L,          /* max plane size the code can handle */
    NULL,
    readpixel,
    drawpixel,
    drawline,
    drawhline,
    drawvline,
    drawblock,
    drawbitmap,
    drawpattern,
    bitblt,
    bltv2r,
    bltr2v
};

#endif
