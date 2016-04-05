#include "GtkIconLoader.h"

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <QDebug>

GtkIconLoader::GtkIconLoader(){}
GtkIconLoader::~GtkIconLoader(){}

unsigned char * GtkIconLoader::getIcon(const QString  & name, int & width)
{
    GdkPixbuf * buf = NULL;
    GError * err = NULL;

    buf = gtk_icon_theme_load_icon(gtk_icon_theme_get_default(),
                                   name.toStdString().c_str(),
                                   GTK_ICON_SIZE_DIALOG,
                                   GTK_ICON_LOOKUP_NO_SVG,
                                   &err);
    if(err)
    {
        qDebug() << err->message;
        return NULL;
    }

    width = gdk_pixbuf_get_width(buf);
    return gdk_pixbuf_get_pixels(buf);
}
