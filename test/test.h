/**
 ** TEST.H ---- common declarations for test programs
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **/

#ifndef __TEST_H_INCLUDED__
#define __TEST_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef  __TURBOC__
#include <conio.h>
#endif

#ifdef  __GNUC__
extern  int getch(void);
extern  int kbhit(void);
#endif

#include "grx20.h"
#include "drawing.h"

extern void (*testfunc)(void);
char   exit_message[2000] = { "" };
int    Argc;
char **Argv;

#define TESTFUNC(name)                \
void name(void);                \
void (*testfunc)(void) = name;  \
void name(void)

int main(int argc,char **argv)
{
        int  x = 0;
        int  y = 0;
        long c = 0;

        Argc = argc - 1;
        Argv = argv + 1;
        if((Argc >= 2) &&
           (sscanf(Argv[0],"%d",&x) == 1) && (x >= 320) &&
           (sscanf(Argv[1],"%d",&y) == 1) && (y >= 200)) {
            Argc -= 2;
            Argv += 2;
            if((Argc > 0) && (sscanf(Argv[0],"%ld",&c) == 1) && (c >= 2)) {
                Argc--;
                Argv++;
            }
        }
        if(c >= 2)
            GrSetMode(GR_width_height_color_graphics,x,y,c);
        else if((x >= 320) && (y >= 200))
            GrSetMode(GR_width_height_graphics,x,y);
        else GrSetMode(GR_default_graphics);
        (*testfunc)();
        GrSetMode(GR_default_text);
        if(strlen(exit_message) > 0) {
            puts(exit_message);
            getch();
        }
        return(0);
}

#endif /* _TEST_H_ */

