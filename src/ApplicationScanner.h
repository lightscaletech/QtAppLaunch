#ifndef _L_APPLICATION_SCANNER_H_
#define _L_APPLICATION_SCANNER_H_

#include <QObject>
#include <QList>

class ApplicationShortcut;

typedef QList<ApplicationShortcut *> AppList;

class ApplicationScanner:
public QObject
{
	public:
		ApplicationScanner(QObject * = NULL);
		~ApplicationScanner();

		AppList findApplication(const QString &);

	private:
		AppList list;

		void generateList();

};

#endif