/**
 ** LIFE.C ---- Conway's life program
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#include "test.h"
#include <malloc.h>
#include <string.h>
#include <time.h>

TESTFUNC(life)
{
        int  W = GrSizeX();
        int  H = GrSizeY();
        char **map[2],**old,**cur;
        int  *xp,*xn,*yp,*yn;
        int  which,x,y,gen;
        long c[2],thresh;
        for(which = 0; which < 2; which++) {
            cur = malloc(H * sizeof(char *));
            if(!cur) return;
            map[which] = cur;
            for(y = 0; y < H; y++) {
                cur[y] = malloc(W);
                if(!cur[y]) return;
            }
        }
        xp = malloc(W * sizeof(int));
        xn = malloc(W * sizeof(int));
        yp = malloc(H * sizeof(int));
        yn = malloc(H * sizeof(int));
        if(!xp || !xn || !yp || !yn) return;
        for(x = 0; x < W; x++) {
            xp[x] = (x + W - 1) % W;
            xn[x] = (x + W + 1) % W;
        }
        for(y = 0; y < H; y++) {
            yp[y] = (y + H - 1) % H;
            yn[y] = (y + H + 1) % H;
        }
        c[0] = GrBlack();
        c[1] = GrWhite();
        which = 0;
        old = map[which];
        cur = map[1 - which];
        srand((int)time(NULL));
        for(y = 0; y < H; y++) {
            for(x = 0; x < W; x++) {
                int ii = RND() % 53;
                while(--ii >= 0) RND();
                old[y][x] = (((RND() % 131) > 107) ? 1 : 0);
                GrPlotNC(x,y,c[(int)old[y][x]]);
            }
        }
        thresh = (((unsigned long)RND() << 16) + RND()) % 1003567UL;
        gen    = (Argc > 0) ? 1 : 0;
        do {
            for(y = 0; y < H; y++) {
                char *prow = old[yp[y]];
                char *crow = old[y];
                char *nrow = old[yn[y]];
                char *curr = cur[y];
                for(x = 0; x < W; x++) {
                    int  xprev = xp[x];
                    int  xnext = xn[x];
                    char live  = prow[xprev] +
                                 prow[x]     +
                                 prow[xnext] +
                                 crow[xprev] +
                                 crow[xnext] +
                                 nrow[xprev] +
                                 nrow[x]     +
                                 nrow[xnext];
                    live = ((live | crow[x]) == 3) ? 1 : 0;
                    if(--thresh <= 0) {
                        live  ^= gen;
                        thresh = (((unsigned long)RND() << 16) + RND()) % 1483567UL;
                    }
                    curr[x] = live;
                }
            }
            for(y = 0; y < H; y++) {
                char *curr = cur[y];
                char *oldr = old[y];
                for(x = 0; x < W; x++) {
                    if(curr[x] != oldr[x]) GrPlotNC(x,y,c[(int)curr[x]]);
                }
            }
            which = 1 - which;
            old = map[which];
            cur = map[1 - which];
        } while(!kbhit());
        while(kbhit()) getch();
}
