/**
 ** POLYTEST.C ---- test polygon rendering
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#include <string.h>
#include <stdio.h>
#include <time.h>

#ifndef  CLK_TCK
#define  CLK_TCK    CLOCKS_PER_SEC
#endif

#include "test.h"

static long black = 0L;
static long red          = 1L;
static long blue  = (1L ^ 3L);
static long white = 3L;

static void testpoly(int n,int points[][2],int convex)
{
        GrClearScreen(black);
        GrPolygon(n,points,white);
        GrFilledPolygon(n,points,(red | GrXOR));
        getch();
        if(convex || (n <= 3)) {
            GrClearScreen(black);
            GrFilledPolygon(n,points,white);
            GrFilledConvexPolygon(n,points,(red | GrXOR));
            getch();
        }
}

static void speedtest(void)
{
        int pts[4][2];
        int ww = GrSizeX() / 10;
        int hh = GrSizeY() / 10;
        int sx = (GrSizeX() - 2*ww) / 32;
        int sy = (GrSizeY() - 2*hh) / 32;
        int  ii,jj;
        long color;
        long t1,t2,t3;

        GrClearScreen(black);
        t1 = clock();
        pts[0][1] = 0;
        pts[1][1] = hh;
        pts[2][1] = 2*hh;
        pts[3][1] = hh;
        color = 0;
        for(ii = 0; ii < 32; ii++) {
            pts[0][0] = ww;
            pts[1][0] = 2*ww;
            pts[2][0] = ww;
            pts[3][0] = 0;
            for(jj = 0; jj < 32; jj++) {
                GrFilledPolygon(4,pts,color | GrXOR);
                color = (color + 1) & 15;
                pts[0][0] += sx;
                pts[1][0] += sx;
                pts[2][0] += sx;
                pts[3][0] += sx;
            }
            pts[0][1] += sy;
            pts[1][1] += sy;
            pts[2][1] += sy;
            pts[3][1] += sy;
        }
        t2 = clock();
        pts[0][1] = 0;
        pts[1][1] = hh;
        pts[2][1] = 2*hh;
        pts[3][1] = hh;
        color = 0;
        for(ii = 0; ii < 32; ii++) {
            pts[0][0] = ww;
            pts[1][0] = 2*ww;
            pts[2][0] = ww;
            pts[3][0] = 0;
            for(jj = 0; jj < 32; jj++) {
                GrFilledConvexPolygon(4,pts,color | GrXOR);
                color = (color + 1) & 15;
                pts[0][0] += sx;
                pts[1][0] += sx;
                pts[2][0] += sx;
                pts[3][0] += sx;
            }
            pts[0][1] += sy;
            pts[1][1] += sy;
            pts[2][1] += sy;
            pts[3][1] += sy;
        }
        t3 = clock();
        sprintf(exit_message,
            "Times to scan 1024 polygons\n"
            "   with 'GrFilledPolygon': %.2f (s)\n"
            "   with 'GrFilledConvexPolygon': %.2f (s)\n",
            (double)(t2 - t1) / (double)CLK_TCK,
            (double)(t3 - t2) / (double)CLK_TCK
        );
}

TESTFUNC(ptest)
{
        char buff[300];
        int  pts[300][2];
        int  ii,collect;
        int  convex;
        FILE *fp;

        fp = fopen("polytest.dat","r");
        if(fp == NULL) return;
        ii  = collect = convex = 0;
        GrSetColor(black,0,0,0);
        GrSetColor(red,255,0,0);
        GrSetColor(blue,0,0,255);
        GrSetColor(white,255,255,255);
        while(fgets(buff,299,fp) != NULL) {
            if(!collect) {
                if(strncmp(buff,"begin",5) == 0) {
                    convex  = (buff[5] == 'c');
                    collect = 1;
                    ii            = 0;
                }
                continue;
            }
            if(strncmp(buff,"end",3) == 0) {
                testpoly(ii,pts,convex);
                collect = 0;
                continue;
            }
            if(sscanf(buff,"%d %d",&pts[ii][0],&pts[ii][1]) == 2) ii++;
        }
        fclose(fp);
        speedtest();
}
