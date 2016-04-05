#include "MainWindow.h"
#include "GtkInit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GtkInit gtk(argc, argv);
    app.setOrganizationName("SamLight");
    app.setApplicationName("AppLauncher");

    MainWindow win;
    win.show();

    return app.exec();
}
