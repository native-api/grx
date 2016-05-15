/**
 ** bldcurs.c ---- create and destroy cursor data structures
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu]
 **
 ** This file is part of the GRX graphics library.
 **
 ** The GRX graphics library is free software; you can redistribute it
 ** and/or modify it under some conditions; see the "copying.grx" file
 ** for details.
 **
 ** This library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 **
 **/

#include "libgrx.h"
#include "allocate.h"
#include "memfill.h"

GrCursor *GrBuildCursor(char *pixels,int pitch,int w,int h,int xo,int yo,const GrxColorTable C)
{
        GrCursor  *curs;
        GrxContext  save;
        int  wrkw2 = (w + 7) & ~7;
        int  workw = wrkw2 << 1;
        int  workh = ((h + 7) & ~7) << 1;
        int  xx,yy;
        curs = malloc(sizeof(GrCursor));
        if(!curs) return(NULL);
        sttzero(curs);
        if(!grx_context_create(workw,((workh << 1) + h),NULL,&curs->work)) {
            free(curs);
            return(NULL);
        }
        curs->xsize = w;
        curs->ysize = h;
        curs->xoffs = xo;
        curs->yoffs = yo;
        curs->xwork = workw;
        curs->ywork = workh;
        grx_context_save(&save);
        grx_context_set_current(&curs->work);
        grx_draw_filled_box_nc(0,0,(workw - 1),(h - 1),0L);
        for(yy = 0; yy < h; yy++) {
            unsigned char *p = (unsigned char *)pixels + (yy * pitch);
            for(xx = 0; xx < w; xx++,p++) {
                if(*p) grx_draw_point_nc(xx,yy,grx_color_get_value(GRX_COLOR_TABLE_GET_COLOR(C,(*p - 1))));
                else   grx_draw_point_nc((xx + wrkw2),yy,grx_color_get_value(-1L));
            }
        }
        grx_context_set_current(&save);
        return(curs);
}

void GrDestroyCursor(GrCursor *cursor)
{
        if(cursor && (cursor != MOUINFO->cursor)) {
            GrEraseCursor(cursor);
            grx_context_unref(&cursor->work);
            free(cursor);
        }
}
