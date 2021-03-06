/*
 * generic/block.c ---- generic (=slow) rectangle fill routine
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
 */

#include <grx/color.h>

#include "libgrx.h"

static void drawblock(int x, int y, int w, int h, GrxColor c)
{
    GRX_ENTER();
    h += y;
    do {
        drawhline(x, y, w, c);
    } while (++y != h);
    GRX_LEAVE();
}
