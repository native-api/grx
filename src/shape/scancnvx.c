/*
 * scancnvx.c ---- scan fill a convex polygon
 *
 * Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 * [e-mail: csaba@vuse.vanderbilt.edu]
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

#include <grx/draw.h>

#include "arith.h"
#include "clipping.h"
#include "globals.h"
#include "libgrx.h"
#include "mouse.h"
#include "polyedge.h"
#include "shapes.h"

typedef struct {
    unsigned int dir;   /* which direction to go for next point */
    unsigned int index; /* index of the current point */
    polyedge e;
} edge;

#define next_edge(ed, n, pt)                              \
    {                                                     \
        ed.index = (ed.index + ed.dir) % (unsigned int)n; \
        ed.e.x = ed.e.xlast;                              \
        ed.e.y = ed.e.ylast;                              \
        ed.e.xlast = pt[ed.index].x;                      \
        ed.e.ylast = pt[ed.index].y;                      \
    }

void _GrScanConvexPoly(int n, const GrxPoint *pt, GrFiller *f, GrFillArg c)
{
    edge L, R;
    int xmin, xmax;
    int ymin, ymax;
    int ypos, i;
    if ((n > 1) && (pt[0].x == pt[n - 1].x) && (pt[0].y == pt[n - 1].y)) {
        n--;
    }
    if (n < 1) {
        return;
    }
    xmin = xmax = pt[0].x;
    ymin = ymax = pt[0].y;
    ypos = 0;
    for (i = 1; i < n; i++) {
        GrxPoint ppt = pt[i];
        if (ymin > ppt.y)
            ymin = ppt.y, ypos = i;
        if (ymax < ppt.y)
            ymax = ppt.y;
        if (xmin > ppt.x)
            xmin = ppt.x;
        if (xmax < ppt.x)
            xmax = ppt.x;
    }
    clip_ordbox(CURC, xmin, ymin, xmax, ymax);
    mouse_block(CURC, xmin, ymin, xmax, ymax);
    L.dir = 1;
    R.dir = n - 1;
    L.index = R.index = ypos;
    L.e.xlast = R.e.xlast = pt[ypos].x;
    L.e.ylast = R.e.ylast = pt[ypos].y;
    for (;;) {
        next_edge(L, n, pt);
        if (L.e.ylast >= ymin) {
            clip_line_ymin(CURC, L.e.x, L.e.y, L.e.xlast, L.e.ylast);
            setup_edge(&L.e);
            break;
        }
    }
    for (;;) {
        next_edge(R, n, pt);
        if (R.e.ylast >= ymin) {
            clip_line_ymin(CURC, R.e.x, R.e.y, R.e.xlast, R.e.ylast);
            setup_edge(&R.e);
            break;
        }
    }
    for (ypos = ymin; ypos <= ymax; ypos++) {
        xmin = L.e.x;
        xmax = L.e.x;
        if (ypos == L.e.ylast) {
            xmin = MIN(xmin, L.e.xlast);
            xmax = MAX(xmax, L.e.xlast);
            if (ypos < ymax)
                for (;;) {
                    next_edge(L, n, pt);
                    if (L.e.ylast > ypos) {
                        setup_edge(&L.e);
                        break;
                    }
                    xmin = MIN(xmin, L.e.xlast);
                    xmax = MAX(xmax, L.e.xlast);
                }
        }
        if (ypos != ymax) {
            if (L.e.xmajor) {
                xstep_edge(&L.e);
                xmin = MIN(xmin, L.e.x - L.e.xstep);
                xmax = MAX(xmax, L.e.x - L.e.xstep);
            }
            else {
                ystep_edge(&L.e);
            }
        }
        xmin = MIN(xmin, R.e.x);
        xmax = MAX(xmax, R.e.x);
        if (ypos == R.e.ylast) {
            xmin = MIN(xmin, R.e.xlast);
            xmax = MAX(xmax, R.e.xlast);
            if (ypos < ymax)
                for (;;) {
                    next_edge(R, n, pt);
                    if (R.e.ylast > ypos) {
                        setup_edge(&R.e);
                        break;
                    }
                    xmin = MIN(xmin, R.e.xlast);
                    xmax = MAX(xmax, R.e.xlast);
                }
        }
        if (ypos != ymax) {
            if (R.e.xmajor) {
                xstep_edge(&R.e);
                xmin = MIN(xmin, R.e.x - R.e.xstep);
                xmax = MAX(xmax, R.e.x - R.e.xstep);
            }
            else {
                ystep_edge(&R.e);
            }
        }
        clip_ordxrange_(CURC, xmin, xmax, continue, CLIP_EMPTY_MACRO_ARG);
        (*f->scan)(
            (xmin + CURC->x_offset), (ypos + CURC->y_offset), (xmax - xmin + 1), c);
    }
    mouse_unblock();
}
