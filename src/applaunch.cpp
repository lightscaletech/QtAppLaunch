#include "MainWindow.h"
#include "GtkInit.h"
#include "RunGuard.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    RunGuard guard("some_random_key");
    if (!guard.tryToRun())
        return 0;

    QApplication app(argc, argv);
    app.setOrganizationName("SamLight");
    app.setApplicationName("AppLauncher");

    QMainWindow parent;
    MainWindow win(&parent);
    win.show();
    GtkInit gtk(argc, argv);

    return app.exec();
}
