/**
 ** WINTEST.C ---- test window (context) mapping
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#include "test.h"

TESTFUNC(wintest)
{
        int  x = GrSizeX();
        int  y = GrSizeY();
        int  ww = (x / 2) - 10;
        int  wh = (y / 2) - 10;
        long c;
        GrContext *w1 = GrCreateSubContext(5,5,ww+4,wh+4,NULL,NULL);
        GrContext *w2 = GrCreateSubContext(15+ww,5,ww+ww+14,wh+4,NULL,NULL);
        GrContext *w3 = GrCreateSubContext(5,15+wh,ww+4,wh+wh+14,NULL,NULL);
        GrContext *w4 = GrCreateSubContext(15+ww,15+wh,ww+ww+14,wh+wh+14,NULL,NULL);

        GrSetContext(w1);
        c = GrAllocColor(200,100,100);
        drawing(0,0,ww,wh,c,GrBlack());
        GrBox(0,0,ww-1,wh-1,c);

        GrSetContext(w2);
        c = GrAllocColor(100,200,200);
        drawing(0,0,ww,wh,c,GrBlack());
        GrBox(0,0,ww-1,wh-1,c);

        GrSetContext(w3);
        c = GrAllocColor(200,200,0);
        drawing(0,0,ww,wh,c,GrBlack());
        GrBox(0,0,ww-1,wh-1,c);

        GrSetContext(w4);
        c = GrAllocColor(0,100,200);
        drawing(0,0,ww,wh,c,GrBlack());
        GrBox(0,0,ww-1,wh-1,c);

        getch();
}

