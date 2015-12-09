#ifndef _L_WIDG_RESULTS_H_
#define _L_WIDG_RESULTS_H_

#include "ApplicationScanner.h"

#include <QWidget>

class QVBoxLayout;
class WidgResultItem;

class WidgResults:
public QWidget
{
	Q_OBJECT
	public:
		WidgResults(QWidget * = NULL);
		~WidgResults();

		void show(const AppList &);
		void clear();
		
		void select(int);
		void unselect();

	public slots:

		void next();
		void prev();
		void run();

	private:
		QVBoxLayout * layout;
		WidgResultItem * selected;
};

#endif