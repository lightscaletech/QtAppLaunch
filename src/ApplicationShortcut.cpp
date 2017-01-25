#include "ApplicationShortcut.h"

#include "Frequency.h"

#include <QFileInfo>
#include <QSettings>
#include <QProcess>
#include <QApplication>

#include <QDebug>

ApplicationShortcut::ApplicationShortcut(const QFileInfo & file, QObject * parent):
    QObject(parent),
    failed(false),
    rank(0)
{
    QSettings settings(file.absoluteFilePath(), QSettings::IniFormat);
    Frequency freq;
    settings.beginGroup("Desktop Entry");

    baseFileName = file.baseName();

    applicationName = settings.value("Name").value<QString>();
    if(applicationName.isEmpty())
    {
        setFailed();
        return;
    }

    rank = freq.applicationRank(applicationName);

    executable = settings.value("Exec").value<QString>();
    if(applicationName.isEmpty())
    {
        setFailed();
        return;
    }

    applicationIcon = settings.value("Icon").value<QString>();
    if(applicationIcon.isEmpty())
    {
        setFailed();
    }
}

ApplicationShortcut::~ApplicationShortcut(){}
void ApplicationShortcut::setFailed(bool failed) { this->failed = failed; }
bool ApplicationShortcut::hasFailed() { return failed; }

void ApplicationShortcut::run()
{
    Frequency freq;
    executable.remove(QRegExp(" \\%[A-Za-z0-9]"));
    QProcess::startDetached(executable);
    freq.applicationSelected(applicationName);
    QApplication::exit();
}

QString & ApplicationShortcut::getBaseFileName(){ return baseFileName; }
QString & ApplicationShortcut::getApplicationName(){ return applicationName; }
QString & ApplicationShortcut::getExecutable(){ return executable; }
QString & ApplicationShortcut::getApplicationIcon(){ return applicationIcon; }
int ApplicationShortcut::getRank(){ return rank; }

bool ApplicationShortcut::operator<(ApplicationShortcut * app)
{
    return rank == app->getRank() ? applicationName < app->getApplicationName()
                                   : rank < app->getRank();
}

bool ApplicationShortcut::operator>(ApplicationShortcut * app)
{
    return rank == app->getRank() ? applicationName > app->getApplicationName()
        : rank > app->getRank();
}
