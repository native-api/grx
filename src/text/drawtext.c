/**
 ** DRAWTEXT.C ---- draw a character string with the default font
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#include <string.h>
#include "libgrx.h"

void GrTextXY(int x,int y,char *text,long fg,long bg)
{
        GrTextOption opt;
        opt.txo_font          = &GrDefaultFont;
        opt.txo_fgcolor.v = fg;
        opt.txo_bgcolor.v = bg;
        opt.txo_chrtype          = GR_BYTE_TEXT;
        opt.txo_direct          = GR_TEXT_RIGHT;
        opt.txo_xalign          = GR_ALIGN_LEFT;
        opt.txo_yalign          = GR_ALIGN_TOP;
        GrDrawString(text,strlen(text),x,y,&opt);
}

