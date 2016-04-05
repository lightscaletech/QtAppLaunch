#include "GtkInit.h"

#include <gtk/gtk.h>

GtkInit::GtkInit(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
}

GtkInit::~GtkInit(){}
