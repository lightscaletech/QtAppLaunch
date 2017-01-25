#include "Frequency.h"

#include <QApplication>
#include <QIODevice>
#include <QByteArray>
#include <QStandardPaths>
#include <QDir>

#include <QDebug>

bool readCsvFile(QIODevice &device, QSettings::SettingsMap &map)
{
    QByteArray ba = device.readLine();
    while (!ba.isEmpty())
    {
        QString line(ba);
        QStringList items = line.split(", ");
        map.insert(items[0], items[1].toInt());
        ba = device.readLine();
    }

    return true;
}

bool writeCsvFile(QIODevice &device, const QSettings::SettingsMap &map)
{
    QString data = "";
    for(auto app = map.begin(); app != map.end(); app++)
    {
        data += app.key() +
            QString(", ") + app.value().toString() +
            QString("\n");
    }
    qDebug() << data;
    device.write(data.toLatin1());

    return true;
}

const QSettings::Format CsvFormat =
    QSettings::registerFormat("csv", readCsvFile, writeCsvFile);

Frequency::Frequency(QObject * parent):
    QObject(parent)
{
    settings = new QSettings(makePath(), CsvFormat, this);
    makePath();
}

Frequency::~Frequency(){}

QString Frequency::makePath()
{
    QString sep = QString("/");
    QString path =
        QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    path += sep + QApplication::applicationName();
    if(!QDir(path).exists())
    {
        QDir().mkdir(path);
    }
    path += sep + "usage.csv";

    return path;
}

bool Frequency::applicationListed(const QString & name)
{
    return settings->contains(name);
}

void Frequency::applicationSelected(const QString & name)
{
    if(applicationListed(name))
    {
        int runs = settings->value(name).toInt();
        settings->setValue(name, ++runs);
    }
    else settings->setValue(name, 1);
    settings->sync();
}

int Frequency::applicationRank(const QString & name)
{
    if(applicationListed(name))
        return settings->value(name).toInt();
    return 0;
}
