/**
 ** CLIPTEST.C ---- test clipping
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#include "test.h"

TESTFUNC(cliptest)
{
        long delay;
        int x = GrSizeX();
        int y = GrSizeY();
        int ww = (x * 2) / 3;
        int wh = (y * 2) / 3;
        long c;

        c = GrAllocColor(200,100,100);
        GrBox(ww/4-1,wh/4-1,ww/4+ww+1,wh/4+wh+1,GrWhite());
        GrSetClipBox(ww/4,wh/4,ww/4+ww,wh/4+wh);

        drawing(0,0,ww,wh,c,GrBlack());
        getch();

        while(!kbhit()) {
            GrFilledBox(0,0,x,y,GrBlack());
            drawing(-(RND()%(2*ww))+ww/2,
                -(RND()%(2*wh))+wh/2,
                RND()%(3*ww)+10,
                RND()%(3*wh)+10,
                c,
                GrNOCOLOR
            );
            for(delay = 200000L; delay > 0L; delay--);
        }
        getch();
}
