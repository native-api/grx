/*
 * pblit_nb.h ---- bitblt routine for packed (8,16,24,32 bpp) modes
 *                 (non banking, source and destination may overlap)
 *
 * Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 * [e-mail: csaba@vuse.vanderbilt.edu].
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
 *
 * Contributions by: (See "doc/credits.doc" for details)
 * Hartmut Schirmer (hsc@techfak.uni-kiel.de)
 * Andrzej Lawa [FidoNet: Andrzej Lawa 2:480/19.77]
 *
 */

#include "colors.h"
#include "libgrx.h"
#include "grdriver.h"
#include "arith.h"
#include "mempeek.h"

#include "pblit.h"

/* WRITE_FAR should be defined as _f if destination is video */
/* READ_FAR should be defined as _f if source is video */

#define __DOCPYF(WF,OP,RF)  fwdcopy##WF##OP##RF(dptr,dptr,sptr,ww)
#define __DOCPYR(WF,OP,RF)  revcopy##WF##OP##RF(dptr,dptr,sptr,ww)

#define __DOIMGCPYF(WF,RF)  DOIMGCOPY(FW,WF,RF,ww)
#define __DOIMGCPYR(WF,RF)  DOIMGCOPY(RV,WF,RF,ww)

/* indirection to resolve WF=WRITE_FAR / RF=READ_FAR macros */
#define DOCPYF(WF,OP,RF)  __DOCPYF(WF,OP,RF)
#define DOCPYR(WF,OP,RF)  __DOCPYR(WF,OP,RF)
#define DOIMGCPYF(WF,RF)  __DOIMGCPYF(WF,RF)
#define DOIMGCPYR(WF,RF)  __DOIMGCPYR(WF,RF)

/* check if forward blit would overwrite source */
#ifdef BLIT_CAN_OVERLAP
#define OVERLAP(dp,sp) ( ((GR_int8 *)dp) > ((GR_int8 *)sp) )
#endif

/* for RAM3x8 support */
#ifndef PLANE_ARG
#define PLANE 0
#endif

#ifdef LOCALFUNC
static
#endif
void BLITFUNC(GrxFrame *dst,int dx,int dy,
              GrxFrame *src,int sx,int sy,
              int w,int h,GrxColor op
#ifdef PLANE_ARG
             ,int PLANE
#endif
              )
{
    char *dptr, *sptr;
    unsigned  dskip, sskip;
    int       oper, ww;
    GR_int8u  cval;

    GRX_ENTER();
    dskip = dst->line_offset - w;
    sskip = src->line_offset - w;
    oper  = C_OPER(op);
    cval  = (GR_int8u)op;

    dptr = &dst->base_address[PLANE][umuladd32(dy,dst->line_offset,dx)];
    sptr = &src->base_address[PLANE][umuladd32(sy,src->line_offset,sx)];

#   ifdef BLITSEL
      setup_far_selector(BLITSEL);
#   endif

#   ifdef BLIT_CAN_OVERLAP
    if(OVERLAP(dptr,sptr)) {
        dptr += umuladd32((h-1),dst->line_offset,w-1);
        sptr += umuladd32((h-1),src->line_offset,w-1);
        do {
            ww = w;
            switch(oper) {
                case C_IMAGE: DOIMGCPYR(WRITE_FAR,READ_FAR);    break;
                case C_XOR:   DOCPYR(WRITE_FAR,_xor,READ_FAR);  break;
                case C_OR:    DOCPYR(WRITE_FAR,_or,READ_FAR);   break;
                case C_AND:   DOCPYR(WRITE_FAR,_and,READ_FAR);  break;
                default:      DOCPYR(WRITE_FAR,_set,READ_FAR);  break;
            }
            dptr -= dskip;
            sptr -= sskip;
        } while(--h != 0);
    } else
#endif /* BLIT_CAN_OVERLAP */
      do {
        ww = w;
        switch(oper) {
            case C_IMAGE: DOIMGCPYF(WRITE_FAR,READ_FAR);      break;
            case C_XOR:   DOCPYF(WRITE_FAR,_xor,READ_FAR);    break;
            case C_OR:    DOCPYF(WRITE_FAR,_or,READ_FAR);     break;
            case C_AND:   DOCPYF(WRITE_FAR,_and,READ_FAR);    break;
            default:      DOCPYF(WRITE_FAR,_set,READ_FAR);    break;
        }
        dptr += dskip;
        sptr += sskip;
      } while(--h != 0);
    GRX_LEAVE();
}

#undef __DOCPYF
#undef __DOCPYR
#undef DOCPYF
#undef DOCPYR
