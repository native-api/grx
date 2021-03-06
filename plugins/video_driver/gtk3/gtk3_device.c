/*
 * gtk3_device.c
 *
 * Copyright (c) 2016 David Lechner <david@lechnology.com>
 * This file is part of the GRX graphics library.
 *
 * The GRX graphics library is free software; you can redistribute it
 * and/or modify it under some conditions; see the "copying.grx" file
 * for details.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#define GDK_VERSION_MIN_REQUIRED (GDK_VERSION_3_18)

#include <gio/gio.h>
#include <glib-object.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <gtk/gtk.h>

#include <grx/device.h>

#include "gtk3_device.h"

struct _GrxGtk3Device {
    GrxDevice parent_instance;
    GdkDevice *gdk_device;
};

G_DEFINE_TYPE(GrxGtk3Device, grx_gtk3_device, GRX_TYPE_DEVICE)

/* Properties */

enum {
    PROP_0,
    PROP_NAME,
    PROP_HAS_KEYBOARD,
    PROP_HAS_POINTER,
    PROP_HAS_TOUCH,
    N_PROPERTIES
};

static void set_property(
    GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id) {
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void get_property(
    GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GrxGtk3Device *self = GRX_GTK3_DEVICE(object);

    switch (property_id) {
    case PROP_NAME:
        g_value_set_string(value, gdk_device_get_name(self->gdk_device));
        break;
    case PROP_HAS_KEYBOARD:
        g_value_set_boolean(
            value, gdk_device_get_source(self->gdk_device) == GDK_SOURCE_KEYBOARD);
        break;
    case PROP_HAS_POINTER:
        g_value_set_boolean(
            value, gdk_device_get_source(self->gdk_device) == GDK_SOURCE_MOUSE);
        break;
    case PROP_HAS_TOUCH:
        g_value_set_boolean(
            value, gdk_device_get_source(self->gdk_device) == GDK_SOURCE_TOUCHSCREEN);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

/* class implementation */

static void finalize(GObject *object)
{
    GrxGtk3Device *self = GRX_GTK3_DEVICE(object);

    G_OBJECT_CLASS(grx_gtk3_device_parent_class)->finalize(object);

    g_object_unref(G_OBJECT(self->gdk_device));
}

static void grx_gtk3_device_class_init(GrxGtk3DeviceClass *klass)
{
    G_OBJECT_CLASS(klass)->set_property = set_property;
    G_OBJECT_CLASS(klass)->get_property = get_property;
    G_OBJECT_CLASS(klass)->finalize = finalize;

    g_object_class_override_property(G_OBJECT_CLASS(klass), PROP_NAME, "name");
    g_object_class_override_property(
        G_OBJECT_CLASS(klass), PROP_HAS_KEYBOARD, "has-keyboard");
    g_object_class_override_property(
        G_OBJECT_CLASS(klass), PROP_HAS_POINTER, "has-pointer");
    g_object_class_override_property(
        G_OBJECT_CLASS(klass), PROP_HAS_TOUCH, "has-touch");
}

static void grx_gtk3_device_init(GrxGtk3Device *self) { }

/* constructors */

/**
 * grx_gtk3_device_new:
 * @device: the libinput device
 *
 * Creates a new instance of #GrxGtk3Device
 *
 * Returns: the new instance
 */
GrxGtk3Device *grx_gtk3_device_new(GdkDevice *device)
{
    GrxGtk3Device *instance = g_object_new(GRX_TYPE_GTK3_DEVICE, NULL);

    g_return_val_if_fail(device != NULL, NULL);

    instance->gdk_device = GDK_DEVICE(g_object_ref(G_OBJECT(device)));

    return instance;
}
