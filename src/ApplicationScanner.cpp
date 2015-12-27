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
	sort(&results);
	return results;
}

void ApplicationScanner::sort(AppList * list)
{
	int count = list->count();

	for(int i1 = 0; i1 < count - 1; i1++)
	{
		for(int i2 = 0; i2 < count - 1; i2++)
		{
			if(list->at(i2) > list->at(i2 + 1)) 
				list->swap(i2, i2 + 1);
		}
	}

}

bool ApplicationScanner::testItem(const QString & item, const QString & term)
{
	return item.contains(term, Qt::CaseInsensitive);
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