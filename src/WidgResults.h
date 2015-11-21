#ifndef _L_WIDG_RESULTS_H_
#define _L_WIDG_RESULTS_H_

#include "ApplicationScanner.h"

#include <QWidget>

class QVBoxLayout;

class WidgResults:
public QWidget
{
	public:
		WidgResults(QWidget * = NULL);
		~WidgResults();

		void show(const AppList &);
		void clear();
	private:
		QVBoxLayout * layout;
};

#endif