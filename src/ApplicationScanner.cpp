#include "ApplicationScanner.h"

ApplicationScanner::ApplicationScanner(QObject * parent):
QObject(parent)
{
	generateList();
}

ApplicationScanner::~ApplicationScanner()
{

}

AppList ApplicationScanner::findApplication(const QString & term)
{

}

void ApplicationScanner::generateList()
{

}