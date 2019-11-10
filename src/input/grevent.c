/**
 ** grevent.c ---- MGRX events
 **
 ** Copyright (C) 2005 Mariano Alvarez Fernandez
 ** [e-mail: malfer@telefonica.net]
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
 ** Contributions by:
 ** 080113 M.Alvarez, intl support
 **
 **/

#include <stdlib.h>
#include <string.h>
#include "libgrx.h"
#include "ninput.h"

#define MAX_EVQUEUE 60

static GrEvent evqueue[MAX_EVQUEUE];
static int num_evqueue = 0;

static int kbsysencoding = GRENC_CP437;

static int genexposeevents = GR_GEN_EXPOSE_NO;

#define MAX_HOOK_FUNCTIONS 10
static int (*hook_event[MAX_HOOK_FUNCTIONS]) (GrEvent *);

static int preproccess_event(GrEvent *ev);

/**
 ** GrEventInit - Initializes the input event queue
 **
 ** Returns  0 on success
 **         -1 on error
 **/

int GrEventInit(void)
{
    int i, ret;

    num_evqueue = 0;
    for (i=0; i<MAX_HOOK_FUNCTIONS; i++)
        hook_event[i] = NULL;
    if (GrMouseDetect()) {
        GrMouseSetSpeed(1, 1);
        GrMouseSetAccel(100, 1);
        GrMouseSetLimits(0, 0, SCRN->gc_xmax, SCRN->gc_ymax);
        GrMouseWarp((SCRN->gc_xmax >> 1), (SCRN->gc_ymax >> 1));
        _GrInitMouseCursor();
        MOUINFO->msstatus = 2;
    }
    ret = _GrEventInit();
    kbsysencoding = _GrGetKbSysEncoding();
    return ret;
}

/**
 ** GrEventUnInit - Ending the input event queue
 **
 **/

void GrEventUnInit(void)
{
    num_evqueue = 0;
    if (MOUINFO->msstatus > 1) MOUINFO->msstatus = 1;
    _GrEventUnInit();
}

/**
 ** GrGetKbSysEncoding - Get kb system encoding
 **
 **/

int GrGetKbSysEncoding(void)
{
    return kbsysencoding;
}

/**
 ** GrEventCheck - Checks if a event is waiting
 **
 ** Returns  1 an event is waiting
 **          0 no events
 **/

int GrEventCheck(void)
{
    if (num_evqueue > 0 || _GrReadInputs()) return 1;
    return 0;
}

/**
 ** GrEventFlush - Empty the input event queue
 **
 **/

void GrEventFlush(void)
{
    while(_GrReadInputs());
    num_evqueue = 0;
}

/**
 ** GrEventRead - Reads an event
 **
 ** It doesn't wait, GREV_NULL is returned if no event is waiting
 **
 ** Arguments:
 **   ev: returns the event
 **/

void GrEventRead(GrEvent * ev)
{
    while (1) {
        if (num_evqueue > 0) {
            num_evqueue--;
            *ev = evqueue[num_evqueue];
            if (preproccess_event(ev)) continue;
            return;
        }
        if (_GrReadInputs()) {
            continue;
        }
        ev->type = GREV_NULL;
        ev->time = GrMsecTime();
        ev->kbstat = 0;
        ev->p1 = 0;
        ev->p2 = 0;
        ev->p3 = 0;
        return;
    }
}

/**
 ** GrEventWait - Waits for an event
 **
 ** Arguments:
 **   ev: returns the event
 **/


void GrEventWait(GrEvent * ev)
{
    while (1) {
        GrEventRead(ev);
        if (ev->type != GREV_NULL) {
            return;
        }
    }
}

/**
 ** GrEventWaitKeyOrClick - Waits for a kay event or a mouse click event
 **
 ** Arguments:
 **   ev: returns the event
 **/


void GrEventWaitKeyOrClick(GrEvent * ev)
{
    while (1) {
        GrEventRead(ev);
        if (ev->type == GREV_KEY)
           return;
        if (ev->type == GREV_MOUSE && ev->p1 == GRMOUSE_LB_RELEASED)
           return;
    }
}

/**
 ** GrEventEnqueue - Enqueues an event
 **
 ** Arguments:
 **   ev: returns the event
 **
 ** Returns  0 on success
 **         -1 on error
 **/

int GrEventEnqueue(GrEvent * ev)
{
    int i;

    ev->time = GrMsecTime();
    if (num_evqueue < MAX_EVQUEUE) {
        for (i=num_evqueue; i>0; i--)
            evqueue[i] = evqueue[i-1];
        evqueue[0] = *ev;
        num_evqueue++;
        return 0;
    }
    return -1;
}

/**
 ** GrEventParEnqueue - Enqueues an event defined by parameters
 **
 ** Arguments:
 **   type: event type
 **   p1, p2, p3, p4: parameters
 **
 ** Returns  0 on success
 **         -1 on error
 **/

int GrEventParEnqueue(int type, long p1, long p2, long p3, long p4)
{
  GrEvent ev;

  ev.type = type;
  ev.p1 = p1;
  ev.p2 = p2;
  ev.p3 = p3;
  ev.p4 = p4;
  return GrEventEnqueue(&ev);
}

/**
 ** GrEventEnqueueFirst - Enqueues an event first
 **
 ** Arguments:
 **   ev: returns the event
 **
 ** Returns  0 on success
 **         -1 on error
 **/

int GrEventEnqueueFirst(GrEvent * ev)
{
    ev->time = GrMsecTime();
    if (num_evqueue < MAX_EVQUEUE) {
        evqueue[num_evqueue] = *ev;
        num_evqueue++;
        return 0;
    }
    return -1;
}

/**
 ** GrEventParEnqueueFirst - Enqueues an event first defined by parameters
 **
 ** Arguments:
 **   type: event type
 **   p1, p2, p3, p4: parameters
 **
 ** Returns  0 on success
 **         -1 on error
 **/

int GrEventParEnqueueFirst(int type, long p1, long p2, long p3, long p4)
{
  GrEvent ev;

  ev.type = type;
  ev.p1 = p1;
  ev.p2 = p2;
  ev.p3 = p3;
  ev.p4 = p4;
  return GrEventEnqueueFirst(&ev);
}

/**
 ** GrEventAddHook - Add a function to hook events
 **
 ** Arguments:
 **   fn: hook funtion pointer
 **
 ** Returns true on succes
 **/

int GrEventAddHook(int (*fn) (GrEvent *))
{
    int i;

    for (i=0; i<MAX_HOOK_FUNCTIONS; i++) {
        if (hook_event[i] == NULL) {
            hook_event[i] = fn;
            return 1;
        }
    }

    return 0;
}

/**
 ** GrEventDeleteHook - Delete a function to hook events
 **
 ** Arguments:
 **   fn: hook funtion pointer
 **
 ** Returns true on succes
 **/

int GrEventDeleteHook(int (*fn) (GrEvent *))
{
    int i;

    for (i=0; i<MAX_HOOK_FUNCTIONS; i++) {
        if (hook_event[i] == fn) {
            hook_event[i] = NULL;
            return 1;
        }
    }

    return 0;
}

/**
 ** GrEventGenExpose - Generate or not Expose eventes
 **
 ** Arguments:
 **   when: GR_GEN_EXPOSE_NO or GR_GEN_EXPOSE_YES
 **/

void GrEventGenExpose(int when)
{
    genexposeevents = when;
#ifdef __XWIN__
    _GrXwinEventGenExpose(when);
#endif
}

/* Internal functions */

static int preproccess_event(GrEvent *ev)
{
    int i, usrenc;

    if (ev->type == GREV_PREKEY) {
        usrenc = GrGetUserEncoding();
        if ((ev->p2 != GRKEY_KEYCODE) && (kbsysencoding != usrenc)) {
          GrRecodeEvent(ev, kbsysencoding, usrenc);
        }
        ev->type = GREV_KEY;
    }

    for ( i=0; i<MAX_HOOK_FUNCTIONS; i++) {
        if (hook_event[i] != NULL)
            if (hook_event[i](ev)) return 1;
    }

    return 0;
}