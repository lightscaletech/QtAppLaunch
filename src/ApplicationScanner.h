#ifndef _L_APPLICATION_SCANNER_H_
#define _L_APPLICATION_SCANNER_H_

#include <QObject>
#include <QList>

#define APPLICTION_SHOTCUT_PATH "/usr/share/applications"

class ApplicationShortcut;

typedef QList<ApplicationShortcut *> AppList;

class ApplicationScanner:
public QObject
{
public:
    ApplicationScanner(QObject * = NULL);
    ~ApplicationScanner();

    AppList find(const QString &);

private:
    AppList list;

    void sort(AppList *);

    bool testItem(const QString &, const QString &);
    void generateList();

};

#endif
