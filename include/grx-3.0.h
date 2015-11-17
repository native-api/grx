/**
 ** grx-3.0.h ---- GRX 3.x API functions and data structure declarations
 **
 ** Copyright (c) 2015 David Lechner <david@lechnology.com>
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

#ifndef __GRX_3_0_H_INCLUDED__
#define __GRX_3_0_H_INCLUDED__

#include <glib-2.0/glib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* a couple of forward declarations ... */
typedef struct _GR_frameDriver  GrFrameDriver;
typedef struct _GrxVideoDriver  GrxVideoDriver;
typedef struct _GrxVideoMode    GrxVideoMode;
typedef struct _GrxVideoModeExt GrxVideoModeExt;
typedef struct _GR_frame        GrFrame;
typedef struct _GR_context      GrContext;

/* ================================================================== */
/*                        SYSTEM TYPE DEF's                           */
/* ================================================================== */

/* need unsigned 32 bit integer for color stuff */
typedef guint32 GrxColor;

/* ================================================================== */
/*                           MODE SETTING                             */
/* ================================================================== */

/**
 * GrxGraphicsMode:
 * @GRX_GRAPHICS_MODE_UNKNOWN: Unknown mode / initial state
 * @GRX_GRAPHICS_MODE_TEXT_80X25: Standard 80x25 text mode
 * @GRX_GRAPHICS_MODE_TEXT_DEFAULT: Default text mode
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT: Text mode with parameters int w, int h
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_COLOR: Text mode with parameters int w,
 *     int h, GrxColor nc
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_BPP: Text mode with parameters int w,
 *     int h, int bpp
 * @GRX_GRAPHICS_MODE_GRAPHICS_DEFAULT: Default graphics mode
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT: Graphics mode with parameters
 *     int w, int h
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_COLOR: Graphics mode with parameters
 *     int w, int h, GrxColor nc
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_BPP: Graphics mode with parameters
 *     int w, int h, int bpp
 * @GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM: Graphics mode with parameters
 *     int w, int h, GrxColor nc, int vx, int vy
 * @GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_BPP: Graphics mode with parameters
 *     int w, int h, int bpp, int vx, int vy
 * @GRX_GRAPHICS_MODE_TEXT_80X25_NC: Same as #GRX_GRAPHICS_MODE_TEXT_80X25
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_TEXT_DEFAULT_NC: Same as #GRX_GRAPHICS_MODE_TEXT_DEFAULT
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_NC: Same as #GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_COLOR_NC: Same as #GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_COLOR
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_BPP_NC: Same as #GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_BPP
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_DEFAULT_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_DEFAULT
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_COLOR_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_COLOR
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_BPP_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_BPP
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM
 *     but does not clear video memory
 * @GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_BPP_NC: Same as #GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_BPP
 *     but does not clear video memory
 *
 * available video modes (for 'GrSetMode')
 */
typedef enum {
    GRX_GRAPHICS_MODE_UNKNOWN = (-1),   /* initial state */
    /* ============= modes which clear the video memory ============= */
    GRX_GRAPHICS_MODE_TEXT_80X25 = 0,                 /* Extra parameters for GrSetMode: */
    GRX_GRAPHICS_MODE_TEXT_DEFAULT,
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT,              /* int w,int h */
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_COLOR,        /* int w,int h,GrxColor nc */
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_BPP,          /* int w,int h,int bpp */
    GRX_GRAPHICS_MODE_GRAPHICS_DEFAULT,
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT,          /* int w,int h */
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_COLOR,    /* int w,int h,GrxColor nc */
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_BPP,      /* int w,int h,int bpp */
    GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM,                /* int w,int h,GrxColor nc,int vx,int vy */
    GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_BPP,            /* int w,int h,int bpp,int vx,int vy */
    /* ==== equivalent modes which do not clear the video memory ==== */
    GRX_GRAPHICS_MODE_TEXT_80X25_NC,
    GRX_GRAPHICS_MODE_TEXT_DEFAULT_NC,
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_NC,           /* int w,int h */
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_COLOR_NC,     /* int w,int h,GrxColor nc */
    GRX_GRAPHICS_MODE_TEXT_WIDTH_HEIGHT_BPP_NC,       /* int w,int h,int bpp */
    GRX_GRAPHICS_MODE_GRAPHICS_DEFAULT_NC,
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_NC,       /* int w,int h */
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_COLOR_NC, /* int w,int h,GrxColor nc */
    GRX_GRAPHICS_MODE_GRAPHICS_WIDTH_HEIGHT_BPP_NC,   /* int w,int h,int bpp */
    GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_NC,             /* int w,int h,GrxColor nc,int vx,int vy */
    GRX_GRAPHICS_MODE_GRAPHICS_CUSTOM_BPP_NC          /* int w,int h,int bpp,int vx,int vy */
} GrxGraphicsMode;

/**
 * GrxFrameMode:
 * @GRX_FRAME_MODE_UNDEFINED: Undefined
 * @GRX_FRAME_MODE_TEXT: Text mode
 * @GRX_FRAME_MODE_LFB_MONO01: Linear frame buffer, 1bpp, 0 = white, 1 = black
 * @GRX_FRAME_MODE_LFB_MONO10: Linear frame buffer, 1bpp, 0 = black, 1 = white
 * @GRX_FRAME_MODE_LFB_8BPP: Linear frame buffer, 8bpp, 256 color
 * @GRX_FRAME_MODE_LFB_16BPP: Linear frame buffer, 16bpp, 32768/65536 color
 * @GRX_FRAME_MODE_LFB_24BPP: Linear frame buffer, 24bpp, 16M color
 * @GRX_FRAME_MODE_LFB_32BPP_LOW: Linear frame buffer, 32bpp, 16M color using lower 24 bits
 * @GRX_FRAME_MODE_LFB_32BPP_HIGH: Linear frame buffer, 32bpp, 16M color using upper 24 bits
 * @GRX_FRAME_MODE_RAM_1BPP: RAM frame buffer, 1bpp, monochome
 * @GRX_FRAME_MODE_RAM_4BPP: RAM frame buffer, 4bpp, 16 color
 * @GRX_FRAME_MODE_RAM_8BPP: RAM frame buffer, 8bpp, 256 color
 * @GRX_FRAME_MODE_RAM_16BPP: RAM frame buffer, 16bpp, 32768/65536 color
 * @GRX_FRAME_MODE_RAM_24BPP: RAM frame buffer, 24bpp, 16M color
 * @GRX_FRAME_MODE_RAM_32BPP_LOW: RAM frame buffer, 32bpp, 16M color using lower 24 bits
 * @GRX_FRAME_MODE_RAM_32BPP_HIGH: RAM frame buffer, 32bpp, 16M color using upper 24 bits
 * @GRX_FRAME_MODE_RAM_3X8BPP: RAM frame buffer, 3x8bpp, 16M color in 3 planes
 *
 * Available frame modes (video memory layouts)
 */
typedef enum {
    GRX_FRAME_MODE_UNDEFINED,           /* undefined */
    GRX_FRAME_MODE_TEXT,                /* text modes */
    /* ==== linear frame buffer modes  ====== */
    GRX_FRAME_MODE_LFB_MONO01,          /* mono, 0 = white, 1 = black */
    GRX_FRAME_MODE_LFB_MONO10,          /* mono, 0 = black, 1 = white */
    GRX_FRAME_MODE_LFB_8BPP,            /* (Super) VGA 256 color */
    GRX_FRAME_MODE_LFB_16BPP,           /* Super VGA 32768/65536 color */
    GRX_FRAME_MODE_LFB_24BPP,           /* Super VGA 16M color */
    GRX_FRAME_MODE_LFB_32BPP_LOW,       /* Super VGA 16M color padded #1 */
    GRX_FRAME_MODE_LFB_32BPP_HIGH,      /* Super VGA 16M color padded #2 */
    /* ====== system RAM frame buffer modes ====== */
    GRX_FRAME_MODE_RAM_1BPP,            /* mono */
    GRX_FRAME_MODE_RAM_4BPP,            /* 16 color planar */
    GRX_FRAME_MODE_RAM_8BPP,            /* 256 color */
    GRX_FRAME_MODE_RAM_16BPP,           /* 32768/65536 color */
    GRX_FRAME_MODE_RAM_24BPP,           /* 16M color */
    GRX_FRAME_MODE_RAM_32BPP_LOW,       /* 16M color padded #1 */
    GRX_FRAME_MODE_RAM_32BPP_HIGH,      /* 16M color padded #2 */
    GRX_FRAME_MODE_RAM_3X8BPP,          /* 16M color planar (image mode) */
    /*< private >*/
    /* ====== markers for scanning modes ====== */
    GRX_FRAME_MODE_FIRST_TEXT     = GRX_FRAME_MODE_TEXT,
    GRX_FRAME_MODE_LAST_TEXT      = GRX_FRAME_MODE_TEXT,
    GRX_FRAME_MODE_FIRST_GRAPHICS = GRX_FRAME_MODE_LFB_MONO01,
    GRX_FRAME_MODE_LAST_GRAPHICS  = GRX_FRAME_MODE_LFB_32BPP_HIGH,
    GRX_FRAME_MODE_FIRST_RAM      = GRX_FRAME_MODE_RAM_1BPP,
    GRX_FRAME_MODE_LAST_RAM       = GRX_FRAME_MODE_RAM_3X8BPP
} GrxFrameMode;

/**
 * GrxVideoAdapter:
 * @GRX_VIDEO_ADAPTER_UNKNOWN: Unknown (default state before driver is set)
 * @GRX_VIDEO_ADAPTER_XWIN: X11 adapter
 * @GRX_VIDEO_ADAPTER_WIN32: Windows adapter
 * @GRX_VIDEO_ADAPTER_LINUX_FB: Linux framebuffer
 * @GRX_VIDEO_ADAPTER_SDL: Simple DirectMedia Layer adapter
 * @GRX_VIDEO_ADAPTER_MEMORY: Memory-only adapter
 *
 * supported video adapter types
 */
typedef enum {
    GRX_VIDEO_ADAPTER_UNKNOWN = (-1),  /* not known (before driver set) */
    GRX_VIDEO_ADAPTER_XWIN,            /* X11 driver */
    GRX_VIDEO_ADAPTER_WIN32,           /* WIN32 driver */
    GRX_VIDEO_ADAPTER_LINUX_FB,        /* Linux framebuffer */
    GRX_VIDEO_ADAPTER_SDL,             /* SDL driver */
    GRX_VIDEO_ADAPTER_MEMORY           /* memory only driver */
} GrxVideoAdapter;

/**
 * GrxVideoDriverFlags:
 * @GRX_VIDEO_DRIVER_FLAG_USER_RESOLUTION: Driver supports arbitrary
 *    user-specified resolution.
 *
 * Flags used by #GrxVideoDriver.
 */
typedef enum /*< flags >*/ {
    GRX_VIDEO_DRIVER_FLAG_USER_RESOLUTION = 0x01,
} GrxVideoDriverFlags;

/**
 * GrxVideoDriver:
 * @name: The name of the driver
 * @adapter: The adapter type
 * @inherit: Video modes from this driver will be inherited
 * @modes: Table of supported modes
 * @n_modes: Number of modes in @modes
 * @detect: Function to detect the driver
 * @init: Function to initialize the driver
 * @reset: Function to reset the driver
 * @select_mode: Function to select the video mode of the driver
 * @flags: Driver flags
 *
 * The video driver descriptor structure
 */
struct _GrxVideoDriver {
    gchar *name;                        /* driver name */
    GrxVideoAdapter adapter;            /* adapter type */
    struct _GrxVideoDriver  *inherit;   /* inherit video modes from this */
    GrxVideoMode   *modes;              /* table of supported modes */
    gint    n_modes;                    /* number of modes */
    gint  (*detect)(void);
    gint  (*init)(gchar *options);
    void  (*reset)(void);
    GrxVideoMode *(*select_mode)(GrxVideoDriver *drv, gint w, gint h,
                                 gint bpp, gboolean txt, guint *ep);
    GrxVideoDriverFlags flags;
};

/**
 * GrxVideoMode:
 * @present: Indicates if the video mode is actually present
 * @bpp: Bits per pixel
 * @width: Width in pixels
 * @height: Height in pixels
 * @mode: BIOS mode number (if any)
 * @line_offset: Scan line length
 * @user_data: Can be used by the driver for anything.
 * @extended_info: Extra info (may be shared with other video modes)
 * 
 * Video driver mode descriptor structure
 */
struct _GrxVideoMode {
    gboolean present;                    /* is it really available? */
    guint8   bpp;                        /* log2 of # of colors */
    guint16  width,height;               /* video mode geometry */
    guint16  mode;                       /* BIOS mode number (if any) */
    gint     line_offset;                /* scan line length */
    gint     user_data;                  /* driver can use it for anything */
    GrxVideoModeExt *extended_info;      /* extra info (maybe shared) */
};

/**
 * GrxVideoModeFlags:
 *
 * @GRX_VIDEO_MODE_FLAG_LINEAR: Uses linear memory mapping
 * @GRX_VIDEO_MODE_FLAG_ACCEL: Uses an acellerated video mode
 * @GRX_VIDEO_MODE_FLAG_FAST_SVGA8: Uses faster mixed-planar access
 * @GRX_VIDEO_MODE_FLAG_MEMORY: Uses memory only (virtual screen)
 *
 * Video mode flag bits (in the #GrxVideoModeExt structure)
 */
typedef enum /*< flags >*/ {
    GRX_VIDEO_MODE_FLAG_LINEAR        = 0x01,
    GRX_VIDEO_MODE_FLAG_ACCEL         = 0x02,
    GRX_VIDEO_MODE_FLAG_FAST_SVGA8    = 0x04,
    GRX_VIDEO_MODE_FLAG_MEMORY        = 0x08,
} GrxVideoModeFlags;

/**
 * GrxVideoModeExt:
 * @mode: Frame driver mode for this video mode
 * @drv: Optional frame driver override
 * @frame: Frame buffer address
 * @cprec: Color component precisions
 * @cpos: Color component positions
 * @flags: Video mode flags
 * @setup: Setup function
 * @set_virtual_size: Set virtual size function
 * @scroll: Scroll function
 * @set_bank: Set bank function
 * @set_rw_banks: Set read/write banks function
 * @load_color: Load color pallet function
 * @lfb_selector: Linear frame buffer selector
 *
 * Video driver mode descriptor extension structure. This is a separate
 * structure accessed via a pointer from the main mode descriptor. The
 * reason for this is that frequently several modes can share the same
 * extended info.
 */
struct _GrxVideoModeExt {
    GrxFrameMode mode;                  /* frame driver for this video mode */
    struct _GR_frameDriver *drv;        /* optional frame driver override */
    guint8 *frame;                      /* frame buffer address */
    guint8  cprec[3];                   /* color component precisions */
    guint8  cpos[3];                    /* color component bit positions */
    GrxVideoModeFlags flags;            /* mode flag bits; see "grdriver.h" */
    gboolean (*setup)(GrxVideoMode *md, gboolean no_clear);
    gboolean (*set_virtual_size)(GrxVideoMode *md, guint w, guint h, GrxVideoMode *result);
    gboolean (*scroll)(GrxVideoMode *md, gint x, gint y, gint result[2]);
    void  (*set_bank)(gint bank);
    void  (*set_rw_banks)(gint read_bank, gint write_bank);
    void  (*load_color)(GrxColor c, GrxColor r, GrxColor g, GrxColor b);
    gint    lfb_selector;
};

/*
 * The frame driver descriptor structure.
 */
struct _GR_frameDriver {
    GrxFrameMode mode;                   /* supported frame access mode */
    GrxFrameMode rmode;                  /* matching RAM frame (if video) */
    int      is_video;                   /* video RAM frame driver ? */
    int      row_align;                  /* scan line size alignment */
    int      num_planes;                 /* number of planes */
    int      bits_per_pixel;             /* bits per pixel */
    long     max_plane_size;             /* maximum plane size in bytes */
    int      (*init)(GrxVideoMode *md);
    GrxColor  (*readpixel)(GrFrame *c,int x,int y);
    void     (*drawpixel)(int x,int y,GrxColor c);
    void     (*drawline)(int x,int y,int dx,int dy,GrxColor c);
    void     (*drawhline)(int x,int y,int w,GrxColor c);
    void     (*drawvline)(int x,int y,int h,GrxColor c);
    void     (*drawblock)(int x,int y,int w,int h,GrxColor c);
    void     (*drawbitmap)(int x,int y,int w,int h,char *bmp,int pitch,int start,GrxColor fg,GrxColor bg);
    void     (*drawpattern)(int x,int y,int w,char patt,GrxColor fg,GrxColor bg);
    void     (*bitblt)(GrFrame *dst,int dx,int dy,GrFrame *src,int x,int y,int w,int h,GrxColor op);
    void     (*bltv2r)(GrFrame *dst,int dx,int dy,GrFrame *src,int x,int y,int w,int h,GrxColor op);
    void     (*bltr2v)(GrFrame *dst,int dx,int dy,GrFrame *src,int x,int y,int w,int h,GrxColor op);
    /* new functions in v2.3 */
    GrxColor *(*getindexedscanline)(GrFrame *c,int x, int y, int w, int *indx);
      /* will return an array of pixel values pv[] read from frame   */
      /*    if indx == NULL: pv[i=0..w-1] = readpixel(x+i,y)         */
      /*    else             pv[i=0..w-1] = readpixel(x+indx[i],y)   */
    void     (*putscanline)(int x, int y, int w,const GrxColor *scl, GrxColor op);
      /** will draw scl[i=0..w-1] to frame:                          */
      /*    if (scl[i] != skipcolor) drawpixel(x+i,y,(scl[i] | op))  */
};

/*
 * driver and mode info structure
 */
extern const struct _GR_driverInfo {
        GrxVideoDriver     *vdriver;        /* the current video driver */
        GrxVideoMode       *curmode;        /* current video mode pointer */
        GrxVideoMode        actmode;        /* copy of above, resized if virtual */
        struct _GR_frameDriver   fdriver;   /* frame driver for the current context */
        struct _GR_frameDriver   sdriver;   /* frame driver for the screen */
        struct _GR_frameDriver   tdriver;   /* a dummy driver for text modes */
        GrxGraphicsMode     mcode;          /* code for the current mode */
        int     deftw,defth;                /* default text mode size */
        int     defgw,defgh;                /* default graphics mode size */
        GrxColor deftc,defgc;                /* default text and graphics colors */
        int     vposx,vposy;                /* current virtual viewport position */
        int     errsfatal;                  /* if set, exit upon errors */
        int     moderestore;                /* restore startup video mode if set */
        int     splitbanks;                 /* indicates separate R/W banks */
        int     curbank;                    /* currently mapped bank */
        void  (*mdsethook)(void);           /* callback for mode set */
        void  (*set_bank)(int bk);          /* banking routine */
        void  (*set_rw_banks)(int rb,int wb); /* split banking routine */
} * const GrDriverInfo;

/*
 * setup stuff
 */
int  GrSetDriver(char *drvspec);
int  GrSetMode(GrxGraphicsMode which,...);
int  GrSetViewport(int xpos,int ypos);
void GrSetModeHook(void (*hookfunc)(void));
void GrSetModeRestore(int restoreFlag);
void GrSetErrorHandling(int exitIfError);
void GrSetEGAVGAmonoDrawnPlane(int plane);
void GrSetEGAVGAmonoShownPlane(int plane);

unsigned GrGetLibraryVersion(void);
unsigned GrGetLibrarySystem(void);

/*
 * inquiry stuff ---- many of these are actually macros (see below)
 */
GrxGraphicsMode GrCurrentMode(void);
GrxVideoAdapter GrAdapterType(void);
GrxFrameMode    GrCurrentFrameMode(void);
GrxFrameMode    GrScreenFrameMode(void);
GrxFrameMode    GrCoreFrameMode(void);

const GrxVideoDriver *GrCurrentVideoDriver(void);
const GrxVideoMode   *GrCurrentVideoMode(void);
const GrxVideoMode   *GrVirtualVideoMode(void);
const GrFrameDriver *GrCurrentFrameDriver(void);
const GrFrameDriver *GrScreenFrameDriver(void);
const GrxVideoMode   *GrFirstVideoMode(GrxFrameMode fmode);
const GrxVideoMode   *GrNextVideoMode(const GrxVideoMode *prev);

int  GrScreenX(void);
int  GrScreenY(void);
int  GrVirtualX(void);
int  GrVirtualY(void);
int  GrViewportX(void);
int  GrViewportY(void);

int  GrScreenIsVirtual(void);

/*
 * RAM context geometry and memory allocation inquiry stuff
 */
int  GrFrameNumPlanes(GrxFrameMode md);
int  GrFrameLineOffset(GrxFrameMode md,int width);
long GrFramePlaneSize(GrxFrameMode md,int w,int h);
long GrFrameContextSize(GrxFrameMode md,int w,int h);

int  GrNumPlanes(void);
int  GrLineOffset(int width);
long GrPlaneSize(int w,int h);
long GrContextSize(int w,int h);

/*
 * inline implementation for some of the above
 */
#ifndef GRX_SKIP_INLINES
#define GrAdapterType()         (GrDriverInfo->vdriver ? GrDriverInfo->vdriver->adapter : GRX_VIDEO_ADAPTER_UNKNOWN)
#define GrCurrentMode()         (GrDriverInfo->mcode)
#define GrCurrentFrameMode()    (GrDriverInfo->fdriver.mode)
#define GrScreenFrameMode()     (GrDriverInfo->sdriver.mode)
#define GrCoreFrameMode()       (GrDriverInfo->sdriver.rmode)

#define GrCurrentVideoDriver()  ((const GrxVideoDriver *)( GrDriverInfo->vdriver))
#define GrCurrentVideoMode()    ((const GrxVideoMode   *)( GrDriverInfo->curmode))
#define GrVirtualVideoMode()    ((const GrxVideoMode   *)(&GrDriverInfo->actmode))
#define GrCurrentFrameDriver()  ((const GrFrameDriver *)(&GrDriverInfo->fdriver))
#define GrScreenFrameDriver()   ((const GrFrameDriver *)(&GrDriverInfo->sdriver))

#define GrIsFixedMode()      (!(  GrCurrentVideoDriver()->flags \
                                   & GRX_VIDEO_DRIVER_FLAG_USER_RESOLUTION))

#define GrScreenX()             (GrCurrentVideoMode()->width)
#define GrScreenY()             (GrCurrentVideoMode()->height)
#define GrVirtualX()            (GrVirtualVideoMode()->width)
#define GrVirtualY()            (GrVirtualVideoMode()->height)
#define GrViewportX()           (GrDriverInfo->vposx)
#define GrViewportY()           (GrDriverInfo->vposy)

#define GrScreenIsVirtual()     ((GrScreenX() + GrScreenY()) < (GrVirtualX() + GrVirtualY()))

#define GrNumPlanes()           GrFrameNumPlanes(GrCoreFrameMode())
#define GrLineOffset(w)         GrFrameLineOffset(GrCoreFrameMode(),w)
#define GrPlaneSize(w,h)        GrFramePlaneSize(GrCoreFrameMode(),w,h)
#define GrContextSize(w,h)      GrFrameContextSize(GrCoreFrameMode(),w,h)
#endif  /* GRX_SKIP_INLINES */


/* ================================================================== */
/*              FRAME BUFFER, CONTEXT AND CLIPPING STUFF              */
/* ================================================================== */

struct _GR_frame {
        char    *gf_baseaddr[4];        /* base address of frame memory */
        short   gf_selector;                /* frame memory segment selector */
        char    gf_onscreen;                /* is it in video memory ? */
        char    gf_memflags;                /* memory allocation flags */
        int     gf_lineoffset;              /* offset to next scan line in bytes */
        struct _GR_frameDriver *gf_driver;  /* frame access functions */
};

struct _GR_context {
        struct _GR_frame    gc_frame;       /* frame buffer info */
        struct _GR_context *gc_root;        /* context which owns frame */
        int    gc_xmax;                     /* max X coord (width  - 1) */
        int    gc_ymax;                     /* max Y coord (height - 1) */
        int    gc_xoffset;                  /* X offset from root's base */
        int    gc_yoffset;                  /* Y offset from root's base */
        int    gc_xcliplo;                  /* low X clipping limit */
        int    gc_ycliplo;                  /* low Y clipping limit */
        int    gc_xcliphi;                  /* high X clipping limit */
        int    gc_ycliphi;                  /* high Y clipping limit */
        int    gc_usrxbase;                 /* user window min X coordinate */
        int    gc_usrybase;                 /* user window min Y coordinate */
        int    gc_usrwidth;                 /* user window width  */
        int    gc_usrheight;                /* user window height */
#   define gc_baseaddr                  gc_frame.gf_baseaddr
#   define gc_selector                  gc_frame.gf_selector
#   define gc_onscreen                  gc_frame.gf_onscreen
#   define gc_memflags                  gc_frame.gf_memflags
#   define gc_lineoffset                gc_frame.gf_lineoffset
#   define gc_driver                    gc_frame.gf_driver
};

extern const struct _GR_contextInfo {
        struct _GR_context current;         /* the current context */
        struct _GR_context screen;          /* the screen context */
} * const GrContextInfo;

GrContext *GrCreateContext(int w,int h,char *memory[4],GrContext *where);
GrContext *GrCreateFrameContext(GrxFrameMode md,int w,int h,char *memory[4],GrContext *where);
GrContext *GrCreateSubContext(int x1,int y1,int x2,int y2,const GrContext *parent,GrContext *where);
GrContext *GrSaveContext(GrContext *where);

GrContext *GrCurrentContext(void);
GrContext *GrScreenContext(void);

void  GrDestroyContext(GrContext *context);
void  GrResizeSubContext(GrContext *context,int x1,int y1,int x2,int y2);
void  GrSetContext(const GrContext *context);

void  GrSetClipBox(int x1,int y1,int x2,int y2);
void  GrSetClipBoxC(GrContext *c,int x1,int y1,int x2,int y2);
void  GrGetClipBox(int *x1p,int *y1p,int *x2p,int *y2p);
void  GrGetClipBoxC(const GrContext *c,int *x1p,int *y1p,int *x2p,int *y2p);
void  GrResetClipBox(void);
void  GrResetClipBoxC(GrContext *c);

int   GrMaxX(void);
int   GrMaxY(void);
int   GrSizeX(void);
int   GrSizeY(void);
int   GrLowX(void);
int   GrLowY(void);
int   GrHighX(void);
int   GrHighY(void);

#ifndef GRX_SKIP_INLINES
#define GrCreateContext(w,h,m,c) (GrCreateFrameContext(GrCoreFrameMode(),w,h,m,c))
#define GrCurrentContext()       ((GrContext *)(&GrContextInfo->current))
#define GrScreenContext()        ((GrContext *)(&GrContextInfo->screen))
#define GrMaxX()                 (GrCurrentContext()->gc_xmax)
#define GrMaxY()                 (GrCurrentContext()->gc_ymax)
#define GrSizeX()                (GrMaxX() + 1)
#define GrSizeY()                (GrMaxY() + 1)
#define GrLowX()                 (GrCurrentContext()->gc_xcliplo)
#define GrLowY()                 (GrCurrentContext()->gc_ycliplo)
#define GrHighX()                (GrCurrentContext()->gc_xcliphi)
#define GrHighY()                (GrCurrentContext()->gc_ycliphi)
#define GrGetClipBoxC(C,x1p,y1p,x2p,y2p) do {           \
        *(x1p) = (C)->gc_xcliplo;                           \
        *(y1p) = (C)->gc_ycliplo;                           \
        *(x2p) = (C)->gc_xcliphi;                           \
        *(y2p) = (C)->gc_ycliphi;                           \
} while(0)
#define GrGetClipBox(x1p,y1p,x2p,y2p) do {              \
        *(x1p) = GrLowX();                                  \
        *(y1p) = GrLowY();                                  \
        *(x2p) = GrHighX();                                 \
        *(y2p) = GrHighY();                                 \
} while(0)
#endif  /* GRX_SKIP_INLINES */

/* ================================================================== */
/*                            COLOR STUFF                             */
/* ================================================================== */

/*
 * Flags to 'OR' to colors for various operations
 */
#define GrWRITE         0UL             /* write color */
#define GrXOR           0x01000000UL    /* to "XOR" any color to the screen */
#define GrOR            0x02000000UL    /* to "OR" to the screen */
#define GrAND           0x03000000UL    /* to "AND" to the screen */
#define GrIMAGE         0x04000000UL    /* BLIT: write, except given color */
#define GrCVALUEMASK    0x00ffffffUL    /* color value mask */
#define GrCMODEMASK     0xff000000UL    /* color operation mask */
#define GrNOCOLOR       (GrXOR | 0)     /* GrNOCOLOR is used for "no" color */

GrxColor GrColorValue(GrxColor c);
GrxColor GrColorMode(GrxColor c);
GrxColor GrWriteModeColor(GrxColor c);
GrxColor GrXorModeColor(GrxColor c);
GrxColor GrOrModeColor(GrxColor c);
GrxColor GrAndModeColor(GrxColor c);
GrxColor GrImageModeColor(GrxColor c);

/*
 * color system info structure (all [3] arrays are [r,g,b])
 */
extern const struct _GR_colorInfo {
        GrxColor       ncolors;              /* number of colors */
        GrxColor       nfree;                /* number of unallocated colors */
        GrxColor       black;                /* the black color */
        GrxColor       white;                /* the white color */
        unsigned int  RGBmode;              /* set when RGB mode */
        unsigned int  prec[3];              /* color field precisions */
        unsigned int  pos[3];               /* color field positions */
        unsigned int  mask[3];              /* masks for significant bits */
        unsigned int  round[3];             /* add these for rounding */
        unsigned int  shift[3];             /* shifts for (un)packing color */
        unsigned int  norm;                 /* normalization for (un)packing */
        struct {                            /* color table for non-RGB modes */
                unsigned char r,g,b;            /* loaded components */
                unsigned int  defined:1;        /* r,g,b values are valid if set */
                unsigned int  writable:1;       /* can be changed by 'GrSetColor' */
                unsigned long int nused;        /* usage count */
        } ctable[256];
} * const GrColorInfo;

void    GrResetColors(void);
void    GrSetRGBcolorMode(void);
void    GrRefreshColors(void);

GrxColor GrNumColors(void);
GrxColor GrNumFreeColors(void);

GrxColor GrBlack(void);
GrxColor GrWhite(void);

GrxColor GrBuildRGBcolorT(int r,int g,int b);
GrxColor GrBuildRGBcolorR(int r,int g,int b);
int     GrRGBcolorRed(GrxColor c);
int     GrRGBcolorGreen(GrxColor c);
int     GrRGBcolorBlue(GrxColor c);

GrxColor GrAllocColor(int r,int g,int b);   /* shared, read-only */
GrxColor GrAllocColorID(int r,int g,int b); /* potentially inlined version */
GrxColor GrAllocColor2(long hcolor);        /* shared, read-only, 0xRRGGBB */
GrxColor GrAllocColor2ID(long hcolor);      /* potentially inlined version */
GrxColor GrAllocCell(void);                 /* unshared, read-write */

GrxColor *GrAllocEgaColors(void);           /* shared, read-only standard EGA colors */

void    GrSetColor(GrxColor c,int r,int g,int b);
void    GrFreeColor(GrxColor c);
void    GrFreeCell(GrxColor c);

void    GrQueryColor(GrxColor c,int *r,int *g,int *b);
void    GrQueryColorID(GrxColor c,int *r,int *g,int *b);
void    GrQueryColor2(GrxColor c,long *hcolor);
void    GrQueryColor2ID(GrxColor c,long *hcolor);

int     GrColorSaveBufferSize(void);
void    GrSaveColors(void *buffer);
void    GrRestoreColors(void *buffer);

#ifndef GRX_SKIP_INLINES
#define GrColorValue(c)         ((GrxColor)(c) & GrCVALUEMASK)
#define GrColorMode(c)          ((GrxColor)(c) & GrCMODEMASK)
#define GrWriteModeColor(c)     (GrColorValue(c) | GrWRITE)
#define GrXorModeColor(c)       (GrColorValue(c) | GrXOR)
#define GrOrModeColor(c)        (GrColorValue(c) | GrOR)
#define GrAndModeColor(c)       (GrColorValue(c) | GrAND)
#define GrImageModeColor(c)     (GrColorValue(c) | GrIMAGE)
#define GrNumColors()           (GrColorInfo->ncolors)
#define GrNumFreeColors()       (GrColorInfo->nfree)
#define GrBlack() (                                                            \
        (GrColorInfo->black == GrNOCOLOR) ?                                    \
        (GrBlack)() :                                                          \
        GrColorInfo->black                                                     \
)
#define GrWhite() (                                                            \
        (GrColorInfo->white == GrNOCOLOR) ?                                    \
        (GrWhite)() :                                                          \
        GrColorInfo->white                                                     \
)
#define GrBuildRGBcolorT(r,g,b) ((                                             \
        ((GrxColor)((int)(r) & GrColorInfo->mask[0]) << GrColorInfo->shift[0]) |\
        ((GrxColor)((int)(g) & GrColorInfo->mask[1]) << GrColorInfo->shift[1]) |\
        ((GrxColor)((int)(b) & GrColorInfo->mask[2]) << GrColorInfo->shift[2])  \
        ) >> GrColorInfo->norm                                                 \
)
#define GrBuildRGBcolorR(r,g,b) GrBuildRGBcolorT(                              \
        (((unsigned int)(r)) > GrColorInfo->mask[0]) ? 255 : (unsigned int)(r) + GrColorInfo->round[0], \
        (((unsigned int)(g)) > GrColorInfo->mask[1]) ? 255 : (unsigned int)(g) + GrColorInfo->round[1], \
        (((unsigned int)(b)) > GrColorInfo->mask[2]) ? 255 : (unsigned int)(b) + GrColorInfo->round[2]  \
)
#define GrRGBcolorRed(c) (                                                     \
        (int)(((GrxColor)(c) << GrColorInfo->norm) >> GrColorInfo->shift[0]) &  \
        (GrColorInfo->mask[0])                                                 \
)
#define GrRGBcolorGreen(c) (                                                   \
        (int)(((GrxColor)(c) << GrColorInfo->norm) >> GrColorInfo->shift[1]) &  \
        (GrColorInfo->mask[1])                                                 \
)
#define GrRGBcolorBlue(c) (                                                    \
        (int)(((GrxColor)(c) << GrColorInfo->norm) >> GrColorInfo->shift[2]) &  \
        (GrColorInfo->mask[2])                                                 \
)
#define GrAllocColorID(r,g,b) (GrColorInfo->RGBmode ?                          \
        GrBuildRGBcolorR(r,g,b) :                                              \
        GrAllocColor(r,g,b)                                                    \
)
#define GrAllocColor2(hcolor) (GrAllocColor(                                   \
        ((hcolor & 0xff0000) >> 16),                                           \
        ((hcolor & 0x00ff00) >> 8),                                            \
        (hcolor & 0x0000ff))                                                   \
)
#define GrAllocColor2ID(hcolor) (GrAllocColorID(                               \
        ((hcolor & 0xff0000) >> 16),                                           \
        ((hcolor & 0x00ff00) >> 8),                                            \
        (hcolor & 0x0000ff))                                                   \
)
#define GrQueryColorID(c,r,g,b) do {                                           \
        if(GrColorInfo->RGBmode) {                                             \
        *(r) = GrRGBcolorRed(c);                                               \
        *(g) = GrRGBcolorGreen(c);                                             \
        *(b) = GrRGBcolorBlue(c);                                              \
        break;                                                                 \
        }                                                                      \
        if(((GrxColor)(c) < GrColorInfo->ncolors) &&                            \
           (GrColorInfo->ctable[(GrxColor)(c)].defined)) {                      \
        *(r) = GrColorInfo->ctable[(GrxColor)(c)].r;                            \
        *(g) = GrColorInfo->ctable[(GrxColor)(c)].g;                            \
        *(b) = GrColorInfo->ctable[(GrxColor)(c)].b;                            \
        break;                                                                 \
        }                                                                      \
        *(r) = *(g) = *(b) = 0;                                                \
} while(0)
#define GrQueryColor2ID(c,hcolor) do {                                         \
        if(GrColorInfo->RGBmode) {                                             \
        *(hcolor) = GrRGBcolorRed(c) << 16;                                    \
        *(hcolor) |= GrRGBcolorGreen(c) << 8;                                  \
        *(hcolor) |= GrRGBcolorBlue(c);                                        \
        break;                                                                 \
        }                                                                      \
        if(((GrxColor)(c) < GrColorInfo->ncolors) &&                            \
           (GrColorInfo->ctable[(GrxColor)(c)].defined)) {                      \
        *(hcolor) = GrColorInfo->ctable[(GrxColor)(c)].r;                       \
        *(hcolor) = GrColorInfo->ctable[(GrxColor)(c)].g;                       \
        *(hcolor) = GrColorInfo->ctable[(GrxColor)(c)].b;                       \
        break;                                                                 \
        }                                                                      \
        *(hcolor) = 0;                                                         \
} while(0)
#endif  /* GRX_SKIP_INLINES */

/*
 * color table (for primitives using several colors):
 *   it is an array of colors with the first element being
 *   the number of colors in the table
 */
typedef GrxColor *GrColorTableP;

#define GR_CTABLE_SIZE(table) (                                                \
        (table) ? (unsigned int)((table)[0]) : 0U                              \
)
#define GR_CTABLE_COLOR(table,index) (                                         \
        ((unsigned)(index) < GR_CTABLE_SIZE(table)) ?                          \
        (table)[((unsigned)(index)) + 1] :                                     \
        GrNOCOLOR                                                              \
)
#define GR_CTABLE_ALLOCSIZE(ncolors)    ((ncolors) + 1)

/* ================================================================== */
/*                       GRAPHICS PRIMITIVES                          */
/* ================================================================== */

#define GR_MAX_POLYGON_POINTS   (1000000)
#define GR_MAX_ELLIPSE_POINTS   (1024 + 5)
#define GR_MAX_ANGLE_VALUE      (3600)
#define GR_ARC_STYLE_OPEN       0
#define GR_ARC_STYLE_CLOSE1     1
#define GR_ARC_STYLE_CLOSE2     2

typedef struct {                        /* framed box colors */
        GrxColor fbx_intcolor;
        GrxColor fbx_topcolor;
        GrxColor fbx_rightcolor;
        GrxColor fbx_bottomcolor;
        GrxColor fbx_leftcolor;
} GrFBoxColors;

void GrClearScreen(GrxColor bg);
void GrClearContext(GrxColor bg);
void GrClearContextC(GrContext *ctx, GrxColor bg);
void GrClearClipBox(GrxColor bg);
void GrPlot(int x,int y,GrxColor c);
void GrLine(int x1,int y1,int x2,int y2,GrxColor c);
void GrHLine(int x1,int x2,int y,GrxColor c);
void GrVLine(int x,int y1,int y2,GrxColor c);
void GrBox(int x1,int y1,int x2,int y2,GrxColor c);
void GrFilledBox(int x1,int y1,int x2,int y2,GrxColor c);
void GrFramedBox(int x1,int y1,int x2,int y2,int wdt,const GrFBoxColors *c);
int  GrGenerateEllipse(int xc,int yc,int xa,int ya,int points[GR_MAX_ELLIPSE_POINTS][2]);
int  GrGenerateEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int points[GR_MAX_ELLIPSE_POINTS][2]);
void GrLastArcCoords(int *xs,int *ys,int *xe,int *ye,int *xc,int *yc);
void GrCircle(int xc,int yc,int r,GrxColor c);
void GrEllipse(int xc,int yc,int xa,int ya,GrxColor c);
void GrCircleArc(int xc,int yc,int r,int start,int end,int style,GrxColor c);
void GrEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrxColor c);
void GrFilledCircle(int xc,int yc,int r,GrxColor c);
void GrFilledEllipse(int xc,int yc,int xa,int ya,GrxColor c);
void GrFilledCircleArc(int xc,int yc,int r,int start,int end,int style,GrxColor c);
void GrFilledEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrxColor c);
void GrPolyLine(int numpts,int points[][2],GrxColor c);
void GrPolygon(int numpts,int points[][2],GrxColor c);
void GrFilledConvexPolygon(int numpts,int points[][2],GrxColor c);
void GrFilledPolygon(int numpts,int points[][2],GrxColor c);
void GrBitBlt(GrContext *dst,int x,int y,GrContext *src,int x1,int y1,int x2,int y2,GrxColor op);
void GrBitBlt1bpp(GrContext *dst,int dx,int dy,GrContext *src,int x1,int y1,int x2,int y2,GrxColor fg,GrxColor bg);
void GrFloodFill(int x, int y, GrxColor border, GrxColor c);
void GrFloodSpill(int x1, int y1, int x2, int y2, GrxColor old_c, GrxColor new_c);
void GrFloodSpill2(int x1, int y1, int x2, int y2, GrxColor old_c1, GrxColor new_c1, GrxColor old_c2, GrxColor new_c2);
void GrFloodSpillC(GrContext *ctx, int x1, int y1, int x2, int y2, GrxColor old_c, GrxColor new_c);
void GrFloodSpillC2(GrContext *ctx, int x1, int y1, int x2, int y2, GrxColor old_c1, GrxColor new_c1, GrxColor old_c2, GrxColor new_c2);

GrxColor GrPixel(int x,int y);
GrxColor GrPixelC(GrContext *c,int x,int y);

const GrxColor *GrGetScanline(int x1,int x2,int yy);
const GrxColor *GrGetScanlineC(GrContext *ctx,int x1,int x2,int yy);
/* Input   ctx: source context, if NULL the current context is used */
/*         x1 : first x coordinate read                             */
/*         x2 : last  x coordinate read                             */
/*         yy : y coordinate                                        */
/* Output  NULL     : error / no data (clipping occured)            */
/*         else                                                     */
/*           p[0..w]: pixel values read                             */
/*                      (w = |x2-y1|)                               */
/*           Output data is valid until next GRX call !             */

void GrPutScanline(int x1,int x2,int yy,const GrxColor *c, GrxColor op);
/* Input   x1 : first x coordinate to be set                        */
/*         x2 : last  x coordinate to be set                        */
/*         yy : y coordinate                                        */
/*         c  : c[0..(|x2-x1|] hold the pixel data                  */
/*         op : Operation (GrWRITE/GrXOR/GrOR/GrAND/GrIMAGE)        */
/*                                                                  */
/* Note    c[..] data must fit GrCVALUEMASK otherwise the results   */
/*         are implementation dependend.                            */
/*         => You can't supply operation code with the pixel data!  */


#ifndef GRX_SKIP_INLINES
#define GrGetScanline(x1,x2,yy) \
        GrGetScanlineC(NULL,(x1),(x2),(yy))
#endif

/* ================================================================== */
/*                 NON CLIPPING DRAWING PRIMITIVES                    */
/* ================================================================== */

void GrPlotNC(int x,int y,GrxColor c);
void GrLineNC(int x1,int y1,int x2,int y2,GrxColor c);
void GrHLineNC(int x1,int x2,int y,GrxColor c);
void GrVLineNC(int x,int y1,int y2,GrxColor c);
void GrBoxNC(int x1,int y1,int x2,int y2,GrxColor c);
void GrFilledBoxNC(int x1,int y1,int x2,int y2,GrxColor c);
void GrFramedBoxNC(int x1,int y1,int x2,int y2,int wdt,const GrFBoxColors *c);
void GrBitBltNC(GrContext *dst,int x,int y,GrContext *src,int x1,int y1,int x2,int y2,GrxColor op);

GrxColor GrPixelNC(int x,int y);
GrxColor GrPixelCNC(GrContext *c,int x,int y);

#ifndef GRX_SKIP_INLINES
#define GrPlotNC(x,y,c) (                                                      \
        (*GrCurrentFrameDriver()->drawpixel)(                                  \
        ((x) + GrCurrentContext()->gc_xoffset),                                \
        ((y) + GrCurrentContext()->gc_yoffset),                                \
        ((c))                                                                  \
        )                                                                      \
)
#define GrPixelNC(x,y) (                                                       \
        (*GrCurrentFrameDriver()->readpixel)(                                  \
        (GrFrame *)(&GrCurrentContext()->gc_frame),                            \
        ((x) + GrCurrentContext()->gc_xoffset),                                \
        ((y) + GrCurrentContext()->gc_yoffset)                                 \
        )                                                                      \
)
#define GrPixelCNC(c,x,y) (                                                    \
        (*(c)->gc_driver->readpixel)(                                          \
        (&(c)->gc_frame),                                                      \
        ((x) + (c)->gc_xoffset),                                               \
        ((y) + (c)->gc_yoffset)                                                \
        )                                                                      \
)
#endif  /* GRX_SKIP_INLINES */

/* ================================================================== */
/*                   FONTS AND TEXT PRIMITIVES                        */
/* ================================================================== */

/*
 * text drawing directions
 */
#define GR_TEXT_RIGHT           0       /* normal */
#define GR_TEXT_DOWN            1       /* downward */
#define GR_TEXT_LEFT            2       /* upside down, right to left */
#define GR_TEXT_UP              3       /* upward */
#define GR_TEXT_DEFAULT         GR_TEXT_RIGHT
#define GR_TEXT_IS_VERTICAL(d)  ((d) & 1)

/*
 * text alignment options
 */
#define GR_ALIGN_LEFT           0       /* X only */
#define GR_ALIGN_TOP            0       /* Y only */
#define GR_ALIGN_CENTER         1       /* X, Y   */
#define GR_ALIGN_RIGHT          2       /* X only */
#define GR_ALIGN_BOTTOM         2       /* Y only */
#define GR_ALIGN_BASELINE       3       /* Y only */
#define GR_ALIGN_DEFAULT        GR_ALIGN_LEFT

/*
 * character types in text strings
 */
#define GR_BYTE_TEXT            0       /* one byte per character */
#define GR_WORD_TEXT            1       /* two bytes per character */
#define GR_ATTR_TEXT            2       /* chr w/ PC style attribute byte */

/*
 * macros to access components of various string/character types
 */
#define GR_TEXTCHR_SIZE(ty)     (((ty) == GR_BYTE_TEXT) ? sizeof(char) : sizeof(short))
#define GR_TEXTCHR_CODE(ch,ty)  (((ty) == GR_WORD_TEXT) ? (unsigned short)(ch) : (unsigned char)(ch))
#define GR_TEXTCHR_ATTR(ch,ty)  (((ty) == GR_ATTR_TEXT) ? ((unsigned short)(ch) >> 8) : 0)
#define GR_TEXTSTR_CODE(pt,ty)  (((ty) == GR_WORD_TEXT) ? ((unsigned short *)(pt))[0] : ((unsigned char *)(pt))[0])
#define GR_TEXTSTR_ATTR(pt,ty)  (((ty) == GR_ATTR_TEXT) ? ((unsigned char *)(pt))[1] : 0)

/*
 * text attribute macros for the GR_ATTR_TEXT type
 * _GR_textattrintensevideo drives if the eighth bit is used for
 * underline (false, default) or more background colors (true)
 */
extern int _GR_textattrintensevideo;

#define GR_BUILD_ATTR(fg,bg,ul) (_GR_textattrintensevideo ? \
                                (((fg) & 15) | (((bg) & 15) << 4)) \
                                : \
                                (((fg) & 15) | (((bg) & 7) << 4) | ((ul) ? 128 : 0)) \
                                )
#define GR_ATTR_FGCOLOR(attr)   (((attr)     ) &  15)
#define GR_ATTR_BGCOLOR(attr)   (_GR_textattrintensevideo ? \
                                (((attr) >> 4) &  15) \
                                : \
                                (((attr) >> 4) &   7) \
                                )
#define GR_ATTR_UNDERLINE(attr) (_GR_textattrintensevideo ? \
                                (0) \
                                : \
                                (((attr)     ) & 128) \
                                )

/*
 * OR this to the foreground color value for underlined text when
 * using GR_BYTE_TEXT or GR_WORD_TEXT modes.
 */
#define GR_UNDERLINE_TEXT       (GrXOR << 4)

/*
 * Font conversion flags for 'GrLoadConvertedFont'. OR them as desired.
 */
#define GR_FONTCVT_NONE         0       /* no conversion */
#define GR_FONTCVT_SKIPCHARS    1       /* load only selected characters */
#define GR_FONTCVT_RESIZE       2       /* resize the font */
#define GR_FONTCVT_ITALICIZE    4       /* tilt font for "italic" look */
#define GR_FONTCVT_BOLDIFY      8       /* make a "bold"(er) font  */
#define GR_FONTCVT_FIXIFY       16      /* convert prop. font to fixed wdt */
#define GR_FONTCVT_PROPORTION   32      /* convert fixed font to prop. wdt */

/*
 * font structures
 */
typedef struct _GR_fontHeader {         /* font descriptor */
        char    *name;                      /* font name */
        char    *family;                    /* font family name */
        char     proportional;              /* characters have varying width */
        char     scalable;                  /* derived from a scalable font */
        char     preloaded;                 /* set when linked into program */
        char     modified;                  /* "tweaked" font (resized, etc..) */
        unsigned int  width;                /* width (proportional=>average) */
        unsigned int  height;               /* font height */
        unsigned int  baseline;             /* baseline pixel pos (from top) */
        unsigned int  ulpos;                /* underline pixel pos (from top) */
        unsigned int  ulheight;             /* underline width */
        unsigned int  minchar;              /* lowest character code in font */
        unsigned int  numchars;             /* number of characters in font */
} GrFontHeader;

typedef struct _GR_fontChrInfo {        /* character descriptor */
        unsigned int  width;                /* width of this character */
        unsigned int  offset;               /* offset from start of bitmap */
} GrFontChrInfo;

typedef struct _GR_font {               /* the complete font */
        struct  _GR_fontHeader  h;          /* the font info structure */
        char     *bitmap;                   /* character bitmap array */
        char     *auxmap;                   /* map for rotated & underline chrs */
        unsigned int  minwidth;             /* width of narrowest character */
        unsigned int  maxwidth;             /* width of widest character */
        unsigned int  auxsize;              /* allocated size of auxiliary map */
        unsigned int  auxnext;              /* next free byte in auxiliary map */
        unsigned int  *auxoffs[7];          /* offsets to completed aux chars */
        struct  _GR_fontChrInfo chrinfo[1]; /* character info (not act. size) */
} GrFont;

extern  GrFont          GrFont_PC6x8;
extern  GrFont          GrFont_PC8x8;
extern  GrFont          GrFont_PC8x14;
extern  GrFont          GrFont_PC8x16;
#define GrDefaultFont   GrFont_PC8x14

GrFont *GrLoadFont(char *name);
GrFont *GrLoadConvertedFont(char *name,int cvt,int w,int h,int minch,int maxch);
GrFont *GrBuildConvertedFont(const GrFont *from,int cvt,int w,int h,int minch,int maxch);

void GrUnloadFont(GrFont *font);
void GrDumpFont(const GrFont *f,char *CsymbolName,char *fileName);
void GrDumpFnaFont(const GrFont *f, char *fileName);
void GrSetFontPath(char *path_list);

int  GrFontCharPresent(const GrFont *font,int chr);
int  GrFontCharWidth(const GrFont *font,int chr);
int  GrFontCharHeight(const GrFont *font,int chr);
int  GrFontCharBmpRowSize(const GrFont *font,int chr);
int  GrFontCharBitmapSize(const GrFont *font,int chr);
int  GrFontStringWidth(const GrFont *font,void *text,int len,int type);
int  GrFontStringHeight(const GrFont *font,void *text,int len,int type);
int  GrProportionalTextWidth(const GrFont *font,const void *text,int len,int type);

char *GrBuildAuxiliaryBitmap(GrFont *font,int chr,int dir,int ul);
char *GrFontCharBitmap(const GrFont *font,int chr);
char *GrFontCharAuxBmp(GrFont *font,int chr,int dir,int ul);

typedef union _GR_textColor {           /* text color union */
        GrxColor       v;                    /* color value for "direct" text */
        GrColorTableP p;                    /* color table for attribute text */
} GrTextColor;

typedef struct _GR_textOption {         /* text drawing option structure */
        struct _GR_font     *txo_font;      /* font to be used */
        union  _GR_textColor txo_fgcolor;   /* foreground color */
        union  _GR_textColor txo_bgcolor;   /* background color */
        char    txo_chrtype;                /* character type (see above) */
        char    txo_direct;                 /* direction (see above) */
        char    txo_xalign;                 /* X alignment (see above) */
        char    txo_yalign;                 /* Y alignment (see above) */
} GrTextOption;

typedef struct {                        /* fixed font text window desc. */
        struct _GR_font     *txr_font;      /* font to be used */
        union  _GR_textColor txr_fgcolor;   /* foreground color */
        union  _GR_textColor txr_bgcolor;   /* background color */
        void   *txr_buffer;                 /* pointer to text buffer */
        void   *txr_backup;                 /* optional backup buffer */
        int     txr_width;                  /* width of area in chars */
        int     txr_height;                 /* height of area in chars */
        int     txr_lineoffset;             /* offset in buffer(s) between rows */
        int     txr_xpos;                   /* upper left corner X coordinate */
        int     txr_ypos;                   /* upper left corner Y coordinate */
        char    txr_chrtype;                /* character type (see above) */
} GrTextRegion;

int  GrCharWidth(int chr,const GrTextOption *opt);
int  GrCharHeight(int chr,const GrTextOption *opt);
void GrCharSize(int chr,const GrTextOption *opt,int *w,int *h);
int  GrStringWidth(void *text,int length,const GrTextOption *opt);
int  GrStringHeight(void *text,int length,const GrTextOption *opt);
void GrStringSize(void *text,int length,const GrTextOption *opt,int *w,int *h);

void GrDrawChar(int chr,int x,int y,const GrTextOption *opt);
void GrDrawString(void *text,int length,int x,int y,const GrTextOption *opt);
void GrTextXY(int x,int y,char *text,GrxColor fg,GrxColor bg);

void GrDumpChar(int chr,int col,int row,const GrTextRegion *r);
void GrDumpText(int col,int row,int wdt,int hgt,const GrTextRegion *r);
void GrDumpTextRegion(const GrTextRegion *r);

#ifndef GRX_SKIP_INLINES
#define GrFontCharPresent(f,ch) (                                              \
        ((unsigned int)(ch) - (f)->h.minchar) < (f)->h.numchars                \
)
#define GrFontCharWidth(f,ch) (                                                \
        GrFontCharPresent(f,ch) ?                                              \
        (int)(f)->chrinfo[(unsigned int)(ch) - (f)->h.minchar].width :         \
        (f)->h.width                                                           \
)
#define GrFontCharHeight(f,ch) (                                               \
        (f)->h.height                                                          \
)
#define GrFontCharBmpRowSize(f,ch) (                                           \
        GrFontCharPresent(f,ch) ?                                              \
        (((f)->chrinfo[(unsigned int)(ch) - (f)->h.minchar].width + 7) >> 3) : \
        0                                                                      \
)
#define GrFontCharBitmapSize(f,ch) (                                           \
        GrFontCharBmpRowSize(f,ch) * (f)->h.height                             \
)
#define GrFontStringWidth(f,t,l,tp) (                                          \
        (f)->h.proportional ?                                                  \
        GrProportionalTextWidth((f),(t),(l),(tp)) :                            \
        (f)->h.width * (l)                                                     \
)
#define GrFontStringHeight(f,t,l,tp) (                                         \
        (f)->h.height                                                          \
)
#define GrFontCharBitmap(f,ch) (                                               \
        GrFontCharPresent(f,ch) ?                                              \
        &(f)->bitmap[(f)->chrinfo[(unsigned int)(ch) - (f)->h.minchar].offset]:\
        (char *)0                                                              \
)
#define GrFontCharAuxBmp(f,ch,dir,ul) (                                        \
        (((dir) == GR_TEXT_DEFAULT) && !(ul)) ?                                \
        GrFontCharBitmap(f,ch) :                                               \
        GrBuildAuxiliaryBitmap((f),(ch),(dir),(ul))                            \
)
#define GrCharWidth(c,o) (                                                     \
        GR_TEXT_IS_VERTICAL((o)->txo_direct) ?                                 \
        GrFontCharHeight((o)->txo_font,GR_TEXTCHR_CODE(c,(o)->txo_chrtype)) :  \
        GrFontCharWidth( (o)->txo_font,GR_TEXTCHR_CODE(c,(o)->txo_chrtype))    \
)
#define GrCharHeight(c,o) (                                                    \
        GR_TEXT_IS_VERTICAL((o)->txo_direct) ?                                 \
        GrFontCharWidth( (o)->txo_font,GR_TEXTCHR_CODE(c,(o)->txo_chrtype)) :  \
        GrFontCharHeight((o)->txo_font,GR_TEXTCHR_CODE(c,(o)->txo_chrtype))    \
)
#define GrCharSize(c,o,wp,hp) do {                                             \
        *(wp) = GrCharHeight(c,o);                                             \
        *(hp) = GrCharWidth( c,o);                                             \
} while(0)
#define GrStringWidth(t,l,o) (                                                 \
        GR_TEXT_IS_VERTICAL((o)->txo_direct) ?                                 \
        GrFontStringHeight((o)->txo_font,(t),(l),(o)->txo_chrtype) :           \
        GrFontStringWidth( (o)->txo_font,(t),(l),(o)->txo_chrtype)             \
)
#define GrStringHeight(t,l,o) (                                                \
        GR_TEXT_IS_VERTICAL((o)->txo_direct) ?                                 \
        GrFontStringWidth( (o)->txo_font,(t),(l),(o)->txo_chrtype) :           \
        GrFontStringHeight((o)->txo_font,(t),(l),(o)->txo_chrtype)             \
)
#define GrStringSize(t,l,o,wp,hp) do {                                         \
        *(wp) = GrStringWidth( t,l,o);                                         \
        *(hp) = GrStringHeight(t,l,o);                                         \
} while(0)
#endif /* GRX_SKIP_INLINES */

/* ================================================================== */
/*            THICK AND DASHED LINE DRAWING PRIMITIVES                */
/* ================================================================== */

/*
 * custom line option structure
 *   zero or one dash pattern length means the line is continuous
 *   the dash pattern always begins with a drawn section
 */
typedef struct {
        GrxColor lno_color;                  /* color used to draw line */
        int     lno_width;                  /* width of the line */
        int     lno_pattlen;                /* length of the dash pattern */
        unsigned char *lno_dashpat;         /* draw/nodraw pattern */
} GrLineOption;

void GrCustomLine(int x1,int y1,int x2,int y2,const GrLineOption *o);
void GrCustomBox(int x1,int y1,int x2,int y2,const GrLineOption *o);
void GrCustomCircle(int xc,int yc,int r,const GrLineOption *o);
void GrCustomEllipse(int xc,int yc,int xa,int ya,const GrLineOption *o);
void GrCustomCircleArc(int xc,int yc,int r,int start,int end,int style,const GrLineOption *o);
void GrCustomEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,const GrLineOption *o);
void GrCustomPolyLine(int numpts,int points[][2],const GrLineOption *o);
void GrCustomPolygon(int numpts,int points[][2],const GrLineOption *o);

/* ================================================================== */
/*             PATTERNED DRAWING AND FILLING PRIMITIVES               */
/* ================================================================== */

/*
 * BITMAP: a mode independent way to specify a fill pattern of two
 *   colors. It is always 8 pixels wide (1 byte per scan line), its
 *   height is user-defined. SET THE TYPE FLAG TO ZERO!!!
 */
typedef struct _GR_bitmap {
        int     bmp_ispixmap;               /* type flag for pattern union */
        int     bmp_height;                 /* bitmap height */
        char   *bmp_data;                   /* pointer to the bit pattern */
        GrxColor bmp_fgcolor;                /* foreground color for fill */
        GrxColor bmp_bgcolor;                /* background color for fill */
        int     bmp_memflags;               /* set if dynamically allocated */
} GrBitmap;

/*
 * PIXMAP: a fill pattern stored in a layout identical to the video RAM
 *   for filling using 'bitblt'-s. It is mode dependent, typically one
 *   of the library functions is used to build it. KEEP THE TYPE FLAG
 *   NONZERO!!!
 */
typedef struct _GR_pixmap {
        int     pxp_ispixmap;               /* type flag for pattern union */
        int     pxp_width;                  /* pixmap width (in pixels)  */
        int     pxp_height;                 /* pixmap height (in pixels) */
        GrxColor pxp_oper;                   /* bitblt mode (SET, OR, XOR, AND, IMAGE) */
        struct _GR_frame pxp_source;        /* source context for fill */
} GrPixmap;

/*
 * Fill pattern union -- can either be a bitmap or a pixmap
 */
typedef union _GR_pattern {
        int      gp_ispixmap;               /* nonzero for pixmaps */
        GrBitmap gp_bitmap;                 /* fill bitmap */
        GrPixmap gp_pixmap;                 /* fill pixmap */
} GrPattern;

#define gp_bmp_data                     gp_bitmap.bmp_data
#define gp_bmp_height                   gp_bitmap.bmp_height
#define gp_bmp_fgcolor                  gp_bitmap.bmp_fgcolor
#define gp_bmp_bgcolor                  gp_bitmap.bmp_bgcolor

#define gp_pxp_width                    gp_pixmap.pxp_width
#define gp_pxp_height                   gp_pixmap.pxp_height
#define gp_pxp_oper                     gp_pixmap.pxp_oper
#define gp_pxp_source                   gp_pixmap.pxp_source

/*
 * Draw pattern for line drawings -- specifies both the:
 *   (1) fill pattern, and the
 *   (2) custom line drawing option
 */
typedef struct {
        GrPattern     *lnp_pattern;         /* fill pattern */
        GrLineOption  *lnp_option;          /* width + dash pattern */
} GrLinePattern;

GrPattern *GrBuildPixmap(const char *pixels,int w,int h,const GrColorTableP colors);
GrPattern *GrBuildPixmapFromBits(const char *bits,int w,int h,GrxColor fgc,GrxColor bgc);
GrPattern *GrConvertToPixmap(GrContext *src);

void GrDestroyPattern(GrPattern *p);

void GrPatternedLine(int x1,int y1,int x2,int y2,GrLinePattern *lp);
void GrPatternedBox(int x1,int y1,int x2,int y2,GrLinePattern *lp);
void GrPatternedCircle(int xc,int yc,int r,GrLinePattern *lp);
void GrPatternedEllipse(int xc,int yc,int xa,int ya,GrLinePattern *lp);
void GrPatternedCircleArc(int xc,int yc,int r,int start,int end,int style,GrLinePattern *lp);
void GrPatternedEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrLinePattern *lp);
void GrPatternedPolyLine(int numpts,int points[][2],GrLinePattern *lp);
void GrPatternedPolygon(int numpts,int points[][2],GrLinePattern *lp);

void GrPatternFilledPlot(int x,int y,GrPattern *p);
void GrPatternFilledLine(int x1,int y1,int x2,int y2,GrPattern *p);
void GrPatternFilledBox(int x1,int y1,int x2,int y2,GrPattern *p);
void GrPatternFilledCircle(int xc,int yc,int r,GrPattern *p);
void GrPatternFilledEllipse(int xc,int yc,int xa,int ya,GrPattern *p);
void GrPatternFilledCircleArc(int xc,int yc,int r,int start,int end,int style,GrPattern *p);
void GrPatternFilledEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrPattern *p);
void GrPatternFilledConvexPolygon(int numpts,int points[][2],GrPattern *p);
void GrPatternFilledPolygon(int numpts,int points[][2],GrPattern *p);
void GrPatternFloodFill(int x, int y, GrxColor border, GrPattern *p);

void GrPatternDrawChar(int chr,int x,int y,const GrTextOption *opt,GrPattern *p);
void GrPatternDrawString(void *text,int length,int x,int y,const GrTextOption *opt,GrPattern *p);
void GrPatternDrawStringExt(void *text,int length,int x,int y,const GrTextOption *opt,GrPattern *p);

/* ================================================================== */
/*                      IMAGE MANIPULATION                            */
/* ================================================================== */

/*
 *  by Michal Stencl Copyright (c) 1998 for GRX
 *  <e-mail>    - [stenclpmd@ba.telecom.sk]
 */

#ifndef GrImage
#define GrImage GrPixmap
#endif

/* Flags for GrImageInverse() */

#define GR_IMAGE_INVERSE_LR  0x01  /* inverse left right */
#define GR_IMAGE_INVERSE_TD  0x02  /* inverse top down */

GrImage *GrImageBuild(const char *pixels,int w,int h,const GrColorTableP colors);
void     GrImageDestroy(GrImage *i);
void     GrImageDisplay(int x,int y, GrImage *i);
void     GrImageDisplayExt(int x1,int y1,int x2,int y2, GrImage *i);
void     GrImageFilledBoxAlign(int xo,int yo,int x1,int y1,int x2,int y2,GrImage *p);
void     GrImageHLineAlign(int xo,int yo,int x,int y,int width,GrImage *p);
void     GrImagePlotAlign(int xo,int yo,int x,int y,GrImage *p);

GrImage *GrImageInverse(GrImage *p,int flag);
GrImage *GrImageStretch(GrImage *p,int nwidth,int nheight);

GrImage *GrImageFromPattern(GrPattern *p);
GrImage *GrImageFromContext(GrContext *c);
GrImage *GrImageBuildUsedAsPattern(const char *pixels,int w,int h,const GrColorTableP colors);

GrPattern *GrPatternFromImage(GrImage *p);


#ifndef GRX_SKIP_INLINES
#define GrImageFromPattern(p) \
        (((p) && (p)->gp_ispixmap) ? (&(p)->gp_pixmap) : NULL)
#define GrImageFromContext(c) \
        (GrImage *)GrConvertToPixmap(c)
#define GrPatternFromImage(p) \
        (GrPattern *)(p)
#define GrImageBuildUsedAsPattern(pixels,w,h,colors) \
        (GrImage *)GrBuildPixmap(pixels,w,h,colors);
#define GrImageDestroy(i)   \
          GrDestroyPattern((GrPattern *)(i));
#endif

/* ================================================================== */
/*               DRAWING IN USER WINDOW COORDINATES                   */
/* ================================================================== */

void GrSetUserWindow(int x1,int y1,int x2,int y2);
void GrGetUserWindow(int *x1,int *y1,int *x2,int *y2);
void GrGetScreenCoord(int *x,int *y);
void GrGetUserCoord(int *x,int *y);

void GrUsrPlot(int x,int y,GrxColor c);
void GrUsrLine(int x1,int y1,int x2,int y2,GrxColor c);
void GrUsrHLine(int x1,int x2,int y,GrxColor c);
void GrUsrVLine(int x,int y1,int y2,GrxColor c);
void GrUsrBox(int x1,int y1,int x2,int y2,GrxColor c);
void GrUsrFilledBox(int x1,int y1,int x2,int y2,GrxColor c);
void GrUsrFramedBox(int x1,int y1,int x2,int y2,int wdt,GrFBoxColors *c);
void GrUsrCircle(int xc,int yc,int r,GrxColor c);
void GrUsrEllipse(int xc,int yc,int xa,int ya,GrxColor c);
void GrUsrCircleArc(int xc,int yc,int r,int start,int end,int style,GrxColor c);
void GrUsrEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrxColor c);
void GrUsrFilledCircle(int xc,int yc,int r,GrxColor c);
void GrUsrFilledEllipse(int xc,int yc,int xa,int ya,GrxColor c);
void GrUsrFilledCircleArc(int xc,int yc,int r,int start,int end,int style,GrxColor c);
void GrUsrFilledEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrxColor c);
void GrUsrPolyLine(int numpts,int points[][2],GrxColor c);
void GrUsrPolygon(int numpts,int points[][2],GrxColor c);
void GrUsrFilledConvexPolygon(int numpts,int points[][2],GrxColor c);
void GrUsrFilledPolygon(int numpts,int points[][2],GrxColor c);
void GrUsrFloodFill(int x, int y, GrxColor border, GrxColor c);

GrxColor GrUsrPixel(int x,int y);
GrxColor GrUsrPixelC(GrContext *c,int x,int y);

void GrUsrCustomLine(int x1,int y1,int x2,int y2,const GrLineOption *o);
void GrUsrCustomBox(int x1,int y1,int x2,int y2,const GrLineOption *o);
void GrUsrCustomCircle(int xc,int yc,int r,const GrLineOption *o);
void GrUsrCustomEllipse(int xc,int yc,int xa,int ya,const GrLineOption *o);
void GrUsrCustomCircleArc(int xc,int yc,int r,int start,int end,int style,const GrLineOption *o);
void GrUsrCustomEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,const GrLineOption *o);
void GrUsrCustomPolyLine(int numpts,int points[][2],const GrLineOption *o);
void GrUsrCustomPolygon(int numpts,int points[][2],const GrLineOption *o);

void GrUsrPatternedLine(int x1,int y1,int x2,int y2,GrLinePattern *lp);
void GrUsrPatternedBox(int x1,int y1,int x2,int y2,GrLinePattern *lp);
void GrUsrPatternedCircle(int xc,int yc,int r,GrLinePattern *lp);
void GrUsrPatternedEllipse(int xc,int yc,int xa,int ya,GrLinePattern *lp);
void GrUsrPatternedCircleArc(int xc,int yc,int r,int start,int end,int style,GrLinePattern *lp);
void GrUsrPatternedEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrLinePattern *lp);
void GrUsrPatternedPolyLine(int numpts,int points[][2],GrLinePattern *lp);
void GrUsrPatternedPolygon(int numpts,int points[][2],GrLinePattern *lp);

void GrUsrPatternFilledPlot(int x,int y,GrPattern *p);
void GrUsrPatternFilledLine(int x1,int y1,int x2,int y2,GrPattern *p);
void GrUsrPatternFilledBox(int x1,int y1,int x2,int y2,GrPattern *p);
void GrUsrPatternFilledCircle(int xc,int yc,int r,GrPattern *p);
void GrUsrPatternFilledEllipse(int xc,int yc,int xa,int ya,GrPattern *p);
void GrUsrPatternFilledCircleArc(int xc,int yc,int r,int start,int end,int style,GrPattern *p);
void GrUsrPatternFilledEllipseArc(int xc,int yc,int xa,int ya,int start,int end,int style,GrPattern *p);
void GrUsrPatternFilledConvexPolygon(int numpts,int points[][2],GrPattern *p);
void GrUsrPatternFilledPolygon(int numpts,int points[][2],GrPattern *p);
void GrUsrPatternFloodFill(int x, int y, GrxColor border, GrPattern *p);

void GrUsrDrawChar(int chr,int x,int y,const GrTextOption *opt);
void GrUsrDrawString(char *text,int length,int x,int y,const GrTextOption *opt);
void GrUsrTextXY(int x,int y,char *text,GrxColor fg,GrxColor bg);

/* ================================================================== */
/*                    GRAPHICS CURSOR UTILITIES                       */
/* ================================================================== */

typedef struct _GR_cursor {
        struct _GR_context work;                    /* work areas (4) */
        int     xcord,ycord;                        /* cursor position on screen */
        int     xsize,ysize;                        /* cursor size */
        int     xoffs,yoffs;                        /* LU corner to hot point offset */
        int     xwork,ywork;                        /* save/work area sizes */
        int     xwpos,ywpos;                        /* save/work area position on screen */
        int     displayed;                          /* set if displayed */
} GrCursor;

GrCursor *GrBuildCursor(char *pixels,int pitch,int w,int h,int xo,int yo,const GrColorTableP c);
void GrDestroyCursor(GrCursor *cursor);
void GrDisplayCursor(GrCursor *cursor);
void GrEraseCursor(GrCursor *cursor);
void GrMoveCursor(GrCursor *cursor,int x,int y);

/* ================================================================== */
/*               MOUSE AND KEYBOARD INPUT UTILITIES                   */
/* ================================================================== */

#define GR_M_MOTION         0x001               /* mouse event flag bits */
#define GR_M_LEFT_DOWN      0x002
#define GR_M_LEFT_UP        0x004
#define GR_M_RIGHT_DOWN     0x008
#define GR_M_RIGHT_UP       0x010
#define GR_M_MIDDLE_DOWN    0x020
#define GR_M_MIDDLE_UP      0x040
#define GR_M_P4_DOWN        0x400
#define GR_M_P4_UP          0x800
#define GR_M_P5_DOWN        0x2000
#define GR_M_P5_UP          0x4000
#define GR_M_BUTTON_DOWN    (GR_M_LEFT_DOWN | GR_M_MIDDLE_DOWN | GR_M_RIGHT_DOWN | GR_M_P4_DOWN | GR_M_P5_DOWN)
#define GR_M_BUTTON_UP      (GR_M_LEFT_UP   | GR_M_MIDDLE_UP   | GR_M_RIGHT_UP   | GR_M_P4_UP   | GR_M_P5_UP)
#define GR_M_BUTTON_CHANGE  (GR_M_BUTTON_UP | GR_M_BUTTON_DOWN )

#define GR_M_LEFT           0x01                /* mouse button index bits */
#define GR_M_RIGHT          0x02
#define GR_M_MIDDLE         0x04
#define GR_M_P4             0x08
#define GR_M_P5             0x10

#define GR_M_KEYPRESS       0x080               /* other event flag bits */
#define GR_M_POLL           0x100
#define GR_M_NOPAINT        0x200
#define GR_COMMAND          0x1000
#define GR_M_EVENT          (GR_M_MOTION | GR_M_KEYPRESS | GR_M_BUTTON_CHANGE | GR_COMMAND)

#define GR_KB_RIGHTSHIFT    0x01                /* Keybd states: right shift key depressed */
#define GR_KB_LEFTSHIFT     0x02                /* left shift key depressed */
#define GR_KB_CTRL          0x04                /* CTRL depressed */
#define GR_KB_ALT           0x08                /* ALT depressed */
#define GR_KB_SCROLLOCK     0x10                /* SCROLL LOCK active */
#define GR_KB_NUMLOCK       0x20                /* NUM LOCK active */
#define GR_KB_CAPSLOCK      0x40                /* CAPS LOCK active */
#define GR_KB_INSERT        0x80                /* INSERT state active */
#define GR_KB_SHIFT         (GR_KB_LEFTSHIFT | GR_KB_RIGHTSHIFT)

#define GR_M_CUR_NORMAL     0                   /* MOUSE CURSOR modes: just the cursor */
#define GR_M_CUR_RUBBER     1                   /* rectangular rubber band (XOR-d to the screen) */
#define GR_M_CUR_LINE       2                   /* line attached to the cursor */
#define GR_M_CUR_BOX        3                   /* rectangular box dragged by the cursor */

#define GR_M_QUEUE_SIZE     128                 /* default queue size */

typedef struct _GR_mouseEvent {                 /* mouse event buffer structure */
        int  flags;                                 /* event type flags (see above) */
        int  x,y;                                   /* mouse coordinates */
        int  buttons;                               /* mouse button state */
        int  key;                                   /* key code from keyboard */
        int  kbstat;                                /* keybd status (ALT, CTRL, etc..) */
        long dtime;                                 /* time since last event (msec) */
} GrMouseEvent;

/*
 * mouse status information
 */
extern const struct _GR_mouseInfo {
        int   (*block)(GrContext*,int,int,int,int); /* mouse block function */
        void  (*unblock)(int flags);                /* mouse unblock function */
        void  (*uninit)(void);                      /* mouse cleanupt function */
        struct _GR_cursor     *cursor;              /* the mouse cursor */
        struct _GR_mouseEvent *queue;               /* queue of pending input events */
        int     msstatus;                           /* -1:missing, 0:unknown, 1:present, 2:initted */
        int     displayed;                          /* cursor is (generally) drawn */
        int     blockflag;                          /* cursor temp. erase/block flag */
        int     docheck;                            /* need to check before gr. op. to screen */
        int     cursmode;                           /* mouse cursor draw mode */
        int     x1,y1,x2,y2;                        /* auxiliary params for some cursor draw modes */
        GrxColor curscolor;                          /* color for some cursor draw modes */
        int     owncursor;                          /* auto generated cursor */
        int     xpos,ypos;                          /* current mouse position */
        int     xmin,xmax;                          /* mouse movement X coordinate limits */
        int     ymin,ymax;                          /* mouse movement Y coordinate limits */
        int     spmult,spdiv;                       /* mouse cursor speed factors */
        int     thresh,accel;                       /* mouse acceleration parameters */
        int     moved;                              /* mouse cursor movement flag */
        int     qsize;                              /* max size of the queue */
        int     qlength;                            /* current # of items in the queue */
        int     qread;                              /* read pointer for the queue */
        int     qwrite;                             /* write pointer for the queue */
} * const GrMouseInfo;

int  GrMouseDetect(void);
void GrMouseEventMode(int dummy);
void GrMouseInit(void);
void GrMouseInitN(int queue_size);
void GrMouseUnInit(void);
void GrMouseSetSpeed(int spmult,int spdiv);
void GrMouseSetAccel(int thresh,int accel);
void GrMouseSetLimits(int x1,int y1,int x2,int y2);
void GrMouseGetLimits(int *x1,int *y1,int *x2,int *y2);
void GrMouseWarp(int x,int y);
void GrMouseEventEnable(int enable_kb,int enable_ms);
void GrMouseGetEvent(int flags,GrMouseEvent *event);

void GrMouseGetEventT(int flags,GrMouseEvent *event,long timout_msecs);
/* Note:
**       event->dtime is only valid if any event occured (event->flags !=0)
**       otherwise it's set as -1.
**       Additionally event timing is now real world time. (X11 && Linux
**       used clock(), user process time, up to 2.28f)
*/

int  GrMousePendingEvent(void);

GrCursor *GrMouseGetCursor(void);
void GrMouseSetCursor(GrCursor *cursor);
void GrMouseSetColors(GrxColor fg,GrxColor bg);
void GrMouseSetCursorMode(int mode,...);
void GrMouseDisplayCursor(void);
void GrMouseEraseCursor(void);
void GrMouseUpdateCursor(void);
int  GrMouseCursorIsDisplayed(void);

int  GrMouseBlock(GrContext *c,int x1,int y1,int x2,int y2);
void GrMouseUnBlock(int return_value_from_GrMouseBlock);

#ifndef GRX_SKIP_INLINES
#define GrMouseEventMode(x)         /* nothing! */
#define GrMouseGetCursor()          (GrMouseInfo->cursor)
#define GrMouseCursorIsDisplayed()  (GrMouseInfo->displayed)
#define GrMouseInit()               GrMouseInitN(GR_M_QUEUE_SIZE);
#define GrMouseGetEvent(f,ev)       GrMouseGetEventT((f),(ev),(-1L));
#define GrMousePendingEvent() (                                                \
        GrMouseUpdateCursor(),                                                 \
   (GrMouseInfo->qlength > 0)                                                  \
)
#define GrMouseUnInit() do {                                                   \
        if(GrMouseInfo->uninit) {                                              \
        (*GrMouseInfo->uninit)();                                              \
        }                                                                      \
} while(0)
#define GrMouseGetLimits(x1p,y1p,x2p,y2p) do {                                 \
        *(x1p) = GrMouseInfo->xmin; *(y1p) = GrMouseInfo->ymin;                \
        *(x2p) = GrMouseInfo->xmax; *(y2p) = GrMouseInfo->ymax;                \
} while(0)
#define GrMouseBlock(c,x1,y1,x2,y2) (                                          \
        (((c) ? (const GrContext*)(c) : GrCurrentContext())->gc_onscreen &&    \
         (GrMouseInfo->docheck)) ?                                             \
        (*GrMouseInfo->block)((c),(x1),(y1),(x2),(y2)) :                       \
        0                                                                      \
)
#define GrMouseUnBlock(f) do {                                                 \
        if((f) && GrMouseInfo->displayed) {                                    \
        (*GrMouseInfo->unblock)((f));                                          \
        }                                                                      \
} while(0)
#endif  /* GRX_SKIP_INLINES */

/* ================================================================== */
/*                           PNM FUNCTIONS                            */
/* ================================================================== */

/*
 *  The PNM formats, grx support load/save of
 *  binaries formats (4,5,6) only
 */

#define PLAINPBMFORMAT 1
#define PLAINPGMFORMAT 2
#define PLAINPPMFORMAT 3
#define PBMFORMAT      4
#define PGMFORMAT      5
#define PPMFORMAT      6

/* The PNM functions */

int GrSaveContextToPbm( GrContext *grc, char *pbmfn, char *docn );
int GrSaveContextToPgm( GrContext *grc, char *pgmfn, char *docn );
int GrSaveContextToPpm( GrContext *grc, char *ppmfn, char *docn );
int GrLoadContextFromPnm( GrContext *grc, char *pnmfn );
int GrQueryPnm( char *pnmfn, int *width, int *height, int *maxval );
int GrLoadContextFromPnmBuffer( GrContext *grc, const char *buffer );
int GrQueryPnmBuffer( const char *buffer, int *width, int *height, int *maxval );

/* ================================================================== */
/*                           PNG FUNCTIONS                            */
/*  these functions may not be installed or available on all system   */
/* ================================================================== */

int GrPngSupport( void );
int GrSaveContextToPng( GrContext *grc, char *pngfn );
int GrLoadContextFromPng( GrContext *grc, char *pngfn, int use_alpha );
int GrQueryPng( char *pngfn, int *width, int *height );

/* ================================================================== */
/*                          JPEG FUNCTIONS                            */
/*  these functions may not be installed or available on all system   */
/* ================================================================== */

int GrJpegSupport( void );
int GrLoadContextFromJpeg( GrContext *grc, char *jpegfn, int scale );
int GrQueryJpeg( char *jpegfn, int *width, int *height );
int GrSaveContextToJpeg( GrContext *grc, char *jpegfn, int quality );
int GrSaveContextToGrayJpeg( GrContext *grc, char *jpegfn, int quality );

/* ================================================================== */
/*               MISCELLANEOUS UTILITIY FUNCTIONS                     */
/* ================================================================== */

void GrResizeGrayMap(unsigned char *map,int pitch,int ow,int oh,int nw,int nh);
int  GrMatchString(const char *pattern,const char *strg);
void GrSetWindowTitle(char *title);
void GrSleep(int msec);
void GrFlush(void);
long GrMsecTime(void);        

/* ================================================================== */
/*                        TIFF ADDON FUNCTIONS                        */
/*  these functions may not be installed or available on all system   */
/* ================================================================== */

/*
** SaveContextToTiff - Dump a context in a TIFF file
**
** Arguments:
**   cxt:   Context to be saved (NULL -> use current context)
**   tiffn: Name of tiff file
**   compr: Compression method (see tiff.h), 0: automatic selection
**   docn:  string saved in the tiff file (DOCUMENTNAME tag)
**
**  Returns  0 on success
**          -1 on error
**
** requires tifflib by  Sam Leffler (sam@engr.sgi.com)
**        available at  ftp://ftp.sgi.com/graphics/tiff
*/
int SaveContextToTiff(GrContext *cxt, char *tiffn, unsigned compr, char *docn);

#ifdef __cplusplus
}
#endif
#endif  /* __GRX_3_0_H_INCLUDED__ */
