/**
 ** PATFCIRC.C
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **
 **  Copyright (C) 1992, Csaba Biegl
 **    820 Stirrup Dr, Nashville, TN, 37221
 **    csaba@vuse.vanderbilt.edu
 **
 **  This file is distributed under the terms listed in the document
 **  "copying.cb", available from the author at the address above.
 **  A copy of "copying.cb" should accompany this file; if not, a copy
 **  should be available from where this file was obtained.  This file
 **  may not be distributed without a verbatim copy of "copying.cb".
 **  You should also have received a copy of the GNU General Public
 **  License along with this program (it is in the file "copying");
 **  if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 **  Cambridge, MA 02139, USA.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **/

#include "libgrx.h"
#include "clipping.h"
#include "shapes.h"

void GrPatternFilledEllipse(int xc,int yc,int xa,int ya,GrPattern *p)
{
        GrFiller *grf = (GrFiller *)malloc(sizeof(GrFiller));
        GrFillArg fa;

        grf->pixel = _GrDrawPatternedPixel;
        grf->line  = _GrDrawPatternedLine;
        grf->scan  = _GrFillPatternedScanLine;
        fa.p = p;
        _GrScanEllipse(xc,yc,xa,ya,grf,fa,TRUE);
        free(grf);
}

void GrPatternFilledEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrPattern *p)
{
        int points[GR_MAX_ELLIPSE_POINTS+1][2];
        int numpts = GrGenerateEllipseArc(xc,yc,xa,ya,start,end,points);
        GrFiller *grf = (GrFiller *)malloc(sizeof(GrFiller));
        GrFillArg fa;

        if (style == GR_ARC_STYLE_CLOSE2) {
                points[numpts][0] = xc;
                points[numpts][1] = yc;
                numpts++;
        }
        grf->pixel = _GrDrawPatternedPixel;
        grf->line  = _GrDrawPatternedLine;
        grf->scan  = _GrFillPatternedScanLine;
        fa.p = p;
        if(numpts < 0) _GrScanConvexPoly((-numpts),points,grf,fa);
        else _GrScanPolygon(numpts,points,grf,fa);
        free(grf);
}

void GrPatternFilledCircle(int xc,int yc,int r,GrPattern *p)
{
        GrPatternFilledEllipse(xc,yc,r,r,p);
}


void GrPatternFilledCircleArc(int xc,int yc,int r,int start,int end,int style,GrPattern *p)
{
        GrPatternFilledEllipseArc(xc,yc,r,r,start,end,style,p);
}
