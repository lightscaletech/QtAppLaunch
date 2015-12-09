#include "ApplicationScanner.h"
#include "ApplicationShortcut.h"

#include <QDirIterator>

#include <QDebug>

ApplicationScanner::ApplicationScanner(QObject * parent):
QObject(parent)
{
	generateList();
}

ApplicationScanner::~ApplicationScanner()
{

}

AppList ApplicationScanner::find(const QString & term)
{
	AppList results;

	for(auto item : list)
	{
		if
		(	
			testItem(item->getApplicationName(), 	term) ||
			testItem(item->getBaseFileName(), 		term) ||
			testItem(item->getExecutable(), 		term)
		) results.append(item);
	}

	return results;
}

bool ApplicationScanner::testItem(const QString & item, const QString & term)
{
	return item.startsWith(term, Qt::CaseInsensitive);
}

void ApplicationScanner::generateList()
{
	QDirIterator dir(APPLICTION_SHOTCUT_PATH, QDir::Files);

	while(dir.hasNext())
	{
		ApplicationShortcut * shortcut = new ApplicationShortcut(dir.fileInfo(), this);
		
		if(!shortcut->hasFailed()) list.append(shortcut);
		else delete shortcut;

		dir.next();
	}
}