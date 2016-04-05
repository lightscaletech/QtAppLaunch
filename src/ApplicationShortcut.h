#ifndef _L_APPLICATION_SHORTCUT_H_
#define _L_APPLICATION_SHORTCUT_H_

#include <QObject>
#include <QString>

class QFileInfo;

class ApplicationShortcut:
public QObject
{
public:
    ApplicationShortcut(const QFileInfo &, QObject * = NULL);
    ~ApplicationShortcut();

    bool hasFailed();
    void run();

    QString & getBaseFileName();
    QString & getApplicationName();
    QString & getExecutable();
    QString & getApplicationIcon();

    bool operator<(ApplicationShortcut *);
    bool operator>(ApplicationShortcut *);

private:
    QString baseFileName;
    QString applicationName;
    QString executable;
    QString applicationIcon;

    bool failed;

    void setFailed(bool = true);
};

#endif
