#include "GtkIconLoader.h"

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

GtkIconLoader::GtkIconLoader(){}
GtkIconLoader::~GtkIconLoader(){}

unsigned char * GtkIconLoader::getIcon(const QString  & name, int & width)
{
    GtkImage * image = NULL;
    GdkPixbuf * buf = NULL;

    image = (GtkImage *) gtk_image_new_from_icon_name(name.toStdString().c_str(), GTK_ICON_SIZE_DIALOG);
    buf = gtk_image_get_pixbuf(image);

    width = gdk_pixbuf_get_width(buf);

    return gdk_pixbuf_get_pixels(buf);
}
