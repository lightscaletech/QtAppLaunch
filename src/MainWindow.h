#ifndef _L_MAINWINDOW_H_
#define _L_MAINWINDOW_H_

#include <QWidget>

class QLineEdit;

class MainWindow:
public QWidget
{
	Q_OBJECT
	public:
		MainWindow(QWidget * = NULL);
		~MainWindow();

	public slots:
		void buttonClicked();

	private:
		QLineEdit * textbox;
};

#endif