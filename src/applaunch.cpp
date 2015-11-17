#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setOrganizationName("SamLight");
	app.setApplicationName("AppLauncher");

	MainWindow win;
	win.show();

	return app.exec();
}