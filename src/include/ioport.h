/**
 ** IOPORT.H ---- port input/output macros
 **
 ** Copyright (c) 1995 Csaba Biegl, 820 Stirrup Dr, Nashville, TN 37221
 ** [e-mail: csaba@vuse.vanderbilt.edu] See "doc/copying.cb" for details.
 **
 ** Intel CPU specific input/output instructions. This file
 ** supports i386 GCC and Turbo C.
 **/
#ifndef __IOPORT_H_INCLUDED__
#define __IOPORT_H_INCLUDED__

#ifdef __TURBOC__
/* prototype for __emit__() */
#include <dos.h>
#endif

#ifdef  SLOW_DOWN_IO
#ifndef SLOW_DOWN_IO_PORT
#define SLOW_DOWN_IO_PORT   0x80
#endif
#ifdef  __GNUC__
#ifdef  __i386__
#define __INLINE_SLOW_IO_ONCE__  ({         \
    __asm__ volatile(                       \
    "outb %%al,%0"                          \
    : /* no outputs */                      \
    : "n" (SLOW_DOWN_IO_PORT)               \
    );                                      \
})
#endif
#endif
#ifdef  __TURBOC__
#define __INLINE_SLOW_IO_ONCE__  (                      \
    __emit__((char)(0xe6)),   /* outb to const port */  \
    __emit__((char)(SLOW_DOWN_IO_PORT))                 \
)
#endif
#if (SLOW_DOWN_IO - 0) <= 1
#define __INLINE_SLOW_DOWN_IO__             \
    __INLINE_SLOW_IO_ONCE__
#elif   (SLOW_DOWN_IO - 0) == 2
#define __INLINE_SLOW_DOWN_IO__             \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__
#elif   (SLOW_DOWN_IO - 0) == 3
#define __INLINE_SLOW_DOWN_IO__             \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__
#else
#define __INLINE_SLOW_DOWN_IO__             \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__,                \
    __INLINE_SLOW_IO_ONCE__
#endif
#define __INLINE_SLOW_DWN_IOC__ __INLINE_SLOW_DOWN_IO__,
#else   /* SLOW_DOWN_IO */
#define __INLINE_SLOW_DOWN_IO__
#define __INLINE_SLOW_DWN_IOC__
#endif

#ifdef  __GNUC__
#ifdef  __i386__
#define __INLINE_LOW_PORT_TEST__(P)  (          \
    (__builtin_constant_p((P))) &&              \
    ((unsigned)(P) < 0x100U)                    \
)
#define __INLINE_INPORT__(P,SIZE,T) ({                  \
    register T _value;                                  \
    if(__INLINE_LOW_PORT_TEST__(P)) __asm__ volatile(   \
    "in"#SIZE" %1,%0"                                   \
    : "=a"  (_value)                                    \
    : "n"   ((unsigned short)(P))                       \
    );                                                  \
    else __asm__ volatile(                              \
    "in"#SIZE" %1,%0"                                   \
    : "=a"  (_value)                                    \
    : "d"   ((unsigned short)(P))                       \
    );                                                  \
    __INLINE_SLOW_DOWN_IO__;                            \
    _value;                                             \
})
#define __INLINE_OUTPORT__(P,V,SIZE,T) ({               \
    if(__INLINE_LOW_PORT_TEST__(P)) __asm__ volatile(   \
    "out"#SIZE" %0,%1"                                  \
    : /* no outputs */                                  \
    : "a" ((unsigned T)(V)),                            \
      "n" ((unsigned short)(P))                         \
    );                                                  \
    else __asm__ volatile(                              \
    "out"#SIZE" %0,%1"                                  \
    : /* no outputs */                                  \
    : "a" ((unsigned T)(V)),                            \
      "d" ((unsigned short)(P))                         \
    );                                                  \
    __INLINE_SLOW_DOWN_IO__;                            \
})
#ifndef SLOW_DOWN_IO
#define __INLINE_INPORTS__(P,B,C,SIZE,T) ({             \
    register void *_inportptr = ((void *)(B));          \
    register int   _inportcnt = ((int)(C));             \
    __asm__ volatile(                                   \
    "cld; "                                             \
    "rep; ins"#SIZE""                                   \
    : "=D" (_inportptr), "=c" (_inportcnt)              \
    : "0"  (_inportptr), "1"  (_inportcnt),             \
      "d"  ((unsigned short)(P))                        \
    );                                                  \
})
#define __INLINE_OUTPORTS__(P,B,C,SIZE,T) ({            \
    register void *_outportptr = ((void *)(B));         \
    register int   _outportcnt = ((int)(C));            \
    __asm__ volatile(                                   \
    "cld; "                                             \
    "rep; outs"#SIZE""                                  \
    : "=S" (_outportptr), "=c" (_outportcnt)            \
    : "0"  (_outportptr), "1"  (_outportcnt),           \
      "d"  ((unsigned short)(P))                        \
    );                                                  \
})
#else   /* SLOW_DOWN_IO */
#define __INLINE_INPORTS__(P,B,C,SIZE,T) ({             \
    register T  *_inportptr = ((T *)(B));               \
    register int _inportcnt = ((int)(C));               \
    register int _inportadr = ((int)(P));               \
    do *_inportptr++ = inport_##SIZE(_inportadr);       \
    while(--_inportcnt);                                \
})
#define __INLINE_OUTPORTS__(P,B,C,SIZE,T) ({            \
    register T  *_outportptr = ((T *)(B));              \
    register int _outportcnt = ((int)(C));              \
    register int _outportadr = ((int)(P));              \
    do outport_##SIZE(_outportadr,*_outportptr++);      \
    while(--_outportcnt);                               \
})
#endif  /* SLOW_DOWN_IO */
#endif  /* __i386__ */
#endif  /* __GNUC__ */

#ifdef  __TURBOC__
/* void    __emit__(); */
#define __INLINE_INPORT__(P,SIZE,T) (                   \
    _DX = ((unsigned short)(P)),                        \
    __emit__((char)(0xec+sizeof(T)-1)), /* inB|W  */    \
    __INLINE_SLOW_DWN_IOC__                             \
    (unsigned T)_AX                                     \
)
#define __INLINE_OUTPORT__(P,V,SIZE,T) do {             \
    _AX = ((unsigned short)(V));                        \
    _DX = ((unsigned short)(P));                        \
    __emit__((char)(0xee+sizeof(T)-1)); /* outB|W */    \
    __INLINE_SLOW_DOWN_IO__;                            \
} while(0)
#ifndef SLOW_DOWN_IO
#define __INLINE_INPORTS__(P,B,C,SIZE,T) do {           \
    _ES = (unsigned)(void _seg *)(void far *)(B);       \
    _DI = (unsigned)(void near *)(B);                   \
    _CX = ((unsigned short)(C));                        \
    _DX = ((unsigned short)(P));                        \
    __emit__((char)(0xfc));     /* cld    */            \
    __emit__((char)(0xf3));     /* rep    */            \
    __emit__((char)(0x6c+sizeof(T)-1)); /* insB|W */    \
} while(0)
#define __INLINE_OUTPORTS__(P,B,C,SIZE,T) do {          \
    _ES = (unsigned)(void _seg *)(void far *)(B);       \
    _SI = (unsigned)(void near *)(B);                   \
    _CX = ((unsigned short)(C));                        \
    _DX = ((unsigned short)(P));                        \
    __emit__((char)(0xfc));     /* cld     */           \
    __emit__((char)(0x26));     /* seg es  */           \
    __emit__((char)(0xf3));     /* rep     */           \
    __emit__((char)(0x6e+sizeof(T)-1)); /* outsB|W */   \
} while(0)
#else   /* SLOW_DOWN_IO */
#define __INLINE_INPORTS__(P,B,C,SIZE,T) do {       \
    _ES = (unsigned)(void _seg *)(void far *)(B);   \
    _BX = (unsigned)(void near *)(B);               \
    _CX = ((unsigned short)(C));                    \
    _DX = ((unsigned short)(P));                    \
    do {                                            \
    __emit__((char)(0xec+sizeof(T)-1)); /* inB|W */ \
    __INLINE_SLOW_DOWN_IO__;                        \
    *((T _seg *)_ES + (T near *)_BX) = (T)_AX;      \
    _BX += sizeof(T);                               \
    _CX--;                                          \
    } while(_CX);                                   \
} while(0)
#define __INLINE_OUTPORTS__(P,B,C,SIZE,T) do {      \
    _ES = (unsigned)(void _seg *)(void far *)(B);   \
    _BX = (unsigned)(void near *)(B);               \
    _CX = ((unsigned short)(C));                    \
    _DX = ((unsigned short)(P));                    \
    do {                                            \
    (T)_AX = *((T _seg *)_ES + (T near *)_BX);      \
    __emit__((char)(0xee+sizeof(T)-1)); /* outB|W */\
    __INLINE_SLOW_DOWN_IO__;                        \
    _BX += sizeof(T);                               \
    _CX--;                                          \
    } while(_CX);                                   \
} while(0)
#endif  /* SLOW_DOWN_IO */
#endif  /* __TURBOC__ */

#define inport_b(port)          __INLINE_INPORT__(port,b,char)
#define inport_w(port)          __INLINE_INPORT__(port,w,short)
#define inport_l(port)          __INLINE_INPORT__(port,l,long)

#define outport_b(port,val)     __INLINE_OUTPORT__(port,val,b,char)
#define outport_w(port,val)     __INLINE_OUTPORT__(port,val,w,short)
#define outport_l(port,val)     __INLINE_OUTPORT__(port,val,l,long)

#define inport_b_s(port,buf,cnt)    __INLINE_INPORTS__(port,buf,cnt,b,char)
#define inport_w_s(port,buf,cnt)    __INLINE_INPORTS__(port,buf,cnt,w,short)
#define inport_l_s(port,buf,cnt)    __INLINE_INPORTS__(port,buf,cnt,l,long)

#define outport_b_s(port,buf,cnt)   __INLINE_OUTPORTS__(port,buf,cnt,b,char)
#define outport_w_s(port,buf,cnt)   __INLINE_OUTPORTS__(port,buf,cnt,w,short)
#define outport_l_s(port,buf,cnt)   __INLINE_OUTPORTS__(port,buf,cnt,l,long)

#ifdef  __GNUC__
#ifdef  __i386__
#ifdef  __MSDOS__
#define int_disable()           ({ __asm__ volatile("cli"); })
#define int_enable()            ({ __asm__ volatile("sti"); })
#else
#define int_disable()
#define int_enable()
#endif
#endif
#endif

#ifdef  __TURBOC__
#define int_disable()           __emit__((char)(0xfa))
#define int_enable()            __emit__((char)(0xfb))
#endif

#ifdef  __TURBOC__
/*
 * These are not really here!
 */
#undef  inport_l
#undef  outport_l
#undef  inport_l_s
#undef  outport_l_s
#endif

#endif  /* whole file */
