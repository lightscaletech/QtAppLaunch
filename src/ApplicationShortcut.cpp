#include "ApplicationShortcut.h"

#include <QFileInfo>
#include <QSettings>
#include <QProcess>
#include <QApplication>

#include <QDebug>

ApplicationShortcut::ApplicationShortcut(const QFileInfo & file, QObject * parent):
QObject(parent),
failed(false)
{
	QSettings settings(file.absoluteFilePath(), QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");

	baseFileName = file.baseName();

	applicationName = settings.value("Name").value<QString>();
	if(applicationName.isEmpty())
	{
		setFailed();
		return;
	}

	executable = settings.value("Exec").value<QString>();
	if(applicationName.isEmpty())
	{
		setFailed();
		return;
	}
}

ApplicationShortcut::~ApplicationShortcut(){}
void ApplicationShortcut::setFailed(bool failed) { this->failed = failed; }
bool ApplicationShortcut::hasFailed() { return failed; }

void ApplicationShortcut::run()
{
	executable.remove(QRegExp(" \\%[A-Za-z0-9]"));
	QProcess::startDetached(executable);
	QApplication::exit();
}

QString & ApplicationShortcut::getBaseFileName(){ return baseFileName; }
QString & ApplicationShortcut::getApplicationName(){ return applicationName; }
QString & ApplicationShortcut::getExecutable(){ return executable; }


bool ApplicationShortcut::operator<(ApplicationShortcut * app)
{
	return applicationName < app->getApplicationName();
}

bool ApplicationShortcut::operator>(ApplicationShortcut * app)
{
	return applicationName > app->getApplicationName();
}