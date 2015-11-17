#ifndef _L_APPLICATION_SHORTCUT_H_
#define _L_APPLICATION_SHORTCUT_H_

#include <QObject>
#include <QString>

class ApplicationShortcut:
public QObject
{
	public:
		ApplicationShortcut(QObject * = NULL);
		~ApplicationShortcut();

	private:
		QString fileName;
		QString executable;
		QString catagory;
};

#endif