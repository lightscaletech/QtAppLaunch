#ifndef _L_GTK_ICON_LOADER_H_
#define _L_GTK_ICON_LOADER_H_

#include <QString>

class GtkIconLoader
{
public:
    GtkIconLoader();
    ~GtkIconLoader();

    unsigned char * getIcon(const QString &, int &);
};

#endif
