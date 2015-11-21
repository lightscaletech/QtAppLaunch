#ifndef _L_MAINWINDOW_H_
#define _L_MAINWINDOW_H_

#include <QWidget>

class QLineEdit;

class ApplicationScanner;
class WidgResults;

class MainWindow:
public QWidget
{
	Q_OBJECT
	public:
		MainWindow(QWidget * = NULL);
		~MainWindow();

	public slots:
		void buttonClicked();
		void textChanged(const QString &);
		void center();

	private:
		QLineEdit * textbox;
		ApplicationScanner * apps;
		WidgResults * results;
};

#endif