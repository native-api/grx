/**
 ** scroltst.c ---- test virtual screen set/scroll
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu]
 **
 ** This is a test/demo file of the GRX graphics library.
 ** You can use GRX test/demo files as you want.
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

#include "test.h"

TESTFUNC(scrolltest)
{
        int  wdt = grx_get_screen_x();
        int  hgt = grx_get_screen_y();
        GrxColor nc  = grx_color_info_n_colors();
        int  txh = grx_font_default.h.height + 2;
        for( ; ; ) {
            char buff[100];
            char *l1 = "Screen resolution: %dx%d";
            char *l2 = "Virtual resolution: %dx%d";
            char *l3 = "Current screen start: x=%-4d y=%-4d";
            char *l4 = "Commands: q -- exit program,";
            char *l5 = "w W h H -- shrink/GROW screen width or height,";
            char *l6 = "x X y Y -- decrease/INCREASE screen start position";
            GrxColor bgc = grx_color_info_alloc_color(0,0,128);
            GrxColor fgc = grx_color_info_alloc_color(200,200,0);
            GrxColor txc = grx_color_info_alloc_color(255,0,255);
            int vw = grx_get_virtual_x();
            int vh = grx_get_virtual_y();
            int vx = grx_get_viewport_x();
            int vy = grx_get_viewport_y();
            int x  = (vw / 3) - (strlen(l6) * grx_font_default.h.width / 2);
            int y  = (vh / 3) - (3 * txh);
            grx_clear_screen(bgc);
            drawing(0,0,vw,vh,fgc,bgc);
            sprintf(buff,l1,wdt,hgt); grx_draw_text_xy(x,y,buff,txc,bgc); y += txh;
            sprintf(buff,l2,vw, vh ); grx_draw_text_xy(x,y,buff,txc,bgc); y += txh;
            for( ; ; grx_set_viewport(vx,vy)) {
                int yy = y;
                vx = grx_get_viewport_x();
                vy = grx_get_viewport_y();
                sprintf(buff,l3,vx,vy); grx_draw_text_xy(x,yy,buff,txc,bgc); yy += txh;
                grx_draw_text_xy(x,yy,l4,txc,bgc); yy += txh;
                grx_draw_text_xy(x,yy,l5,txc,bgc); yy += txh;
                grx_draw_text_xy(x,yy,l6,txc,bgc); yy += txh;
                switch(GrKeyRead()) {
                    case 'w': vw -= 8; break;
                    case 'W': vw += 8; break;
                    case 'h': vh -= 8; break;
                    case 'H': vh += 8; break;
                    case 'x': vx--; continue;
                    case 'X': vx++; continue;
                    case 'y': vy--; continue;
                    case 'Y': vy++; continue;
                    case 'q': return;
                    case 'Q': return;
                    default:  continue;
                }
                grx_set_mode(GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM,wdt,hgt,nc,vw,vh);
                break;
            }
        }
}

