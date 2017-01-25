#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

#include <QObject>
#include <QSettings>
#include <QString>

class Frequency:
public QObject
{
public:
    Frequency(QObject * = NULL);
    ~Frequency();

    bool applicationListed(const QString & name);
    void applicationSelected(const QString & name);
    int applicationRank(const QString & name);

private:
    QString makePath();
    QSettings * settings;
};

#endif
