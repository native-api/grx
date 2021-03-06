/*
 * curstest.c ---- test cursors
 *
 * Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 * [e-mail: csaba@vuse.vanderbilt.edu]
 *
 * This is a test/demo file of the GRX graphics library.
 * You can use GRX test/demo files as you want.
 *
 * The GRX graphics library is free software; you can redistribute it
 * and/or modify it under some conditions; see the "copying.grx" file
 * for details.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "../src/include/mouse.h"
#include "test.h"

// clang-format off
static const guint8 p16d[] = {
    0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,
    1,2,1,0,0,0,0,0,0,0,0,1,2,2,1,0,
    1,2,2,1,0,0,0,0,0,0,1,2,0,0,2,1,
    1,2,2,2,1,0,0,0,0,0,1,2,0,0,2,1,
    1,2,2,2,2,1,0,0,0,0,0,1,2,2,1,0,
    1,2,2,2,2,2,1,0,0,0,0,0,1,1,0,0,
    1,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,
    1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,
    1,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
    1,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,
    1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,
    1,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,
    1,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
    1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
// clang-format on

TESTFUNC(cursortest)
{
    GrxColor bgc = grx_color_get(0, 0, 128);
    GrxColor fgc = grx_color_get(255, 255, 0);
    GArray *msc;
    GrxCursor *cur;
    int x, y;

    msc = g_array_sized_new(FALSE, FALSE, sizeof(GrxColor), 3);
    g_array_append_vals(
        msc, (GrxColor[]) { 2, GRX_COLOR_WHITE, grx_color_get(255, 0, 0) }, 3);
    cur = grx_cursor_new(p16d, 16, 16, 16, 1, 1, msc);
    g_array_unref(msc);
    x = grx_get_screen_width() / 2;
    y = grx_get_screen_height() / 2;
    grx_cursor_move(cur, x, y);
    grx_clear_screen(bgc);
    grx_color_cell_set((grx_color_info_n_colors() - 1), 255, 255, 255);
    drawing(0, 0, grx_get_width(), grx_get_height(), fgc, GRX_COLOR_NONE);
    grx_draw_filled_box(0, 0, 320, 120, grx_color_get(0, 255, 255));
    grx_draw_text("ANDmask", 10, 90, black_text);
    grx_draw_text("ORmask", 90, 90, black_text);
    grx_draw_text("Save", 170, 90, black_text);
    grx_draw_text("Work", 250, 90, black_text);
    grx_cursor_show(cur);
    for (;;) {
        grx_bit_blt(10, 10, &cur->work, cur->xwork / 2, 0,
            cur->xwork / 2 + cur->xsize - 1, cur->ysize - 1, GRX_COLOR_MODE_WRITE);
        grx_bit_blt(90, 10, &cur->work, 0, 0, cur->xsize - 1, cur->ysize - 1,
            GRX_COLOR_MODE_WRITE);
        grx_bit_blt(170, 10, &cur->work, 0, cur->ysize, cur->xwork - 1,
            cur->ysize + cur->ywork - 1, GRX_COLOR_MODE_WRITE);
        grx_bit_blt(250, 10, &cur->work, 0, cur->ysize + cur->ywork, cur->xwork - 1,
            cur->ysize + 2 * cur->ywork - 1, GRX_COLOR_MODE_WRITE);
        grx_draw_text(
            "Type u d l r U D L R or q to quit", 0, grx_get_max_y() - 20, white_text);
        switch (run_main_loop_until_key_press()) {
        case 'u':
            y--;
            break;
        case 'd':
            y++;
            break;
        case 'l':
            x--;
            break;
        case 'r':
            x++;
            break;
        case 'U':
            y -= 10;
            break;
        case 'D':
            y += 10;
            break;
        case 'L':
            x -= 10;
            break;
        case 'R':
            x += 10;
            break;
        case 'q':
            return;
        default:
            continue;
        }
        if (x < 0)
            x = 0;
        if (x > grx_get_screen_width())
            x = grx_get_screen_width();
        if (y < 100)
            y = 100;
        if (y > grx_get_screen_height())
            y = grx_get_screen_height();
        grx_cursor_move(cur, x, y);
    }
}
