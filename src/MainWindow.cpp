#include "MainWindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProcess>

MainWindow::MainWindow(QWidget * parent):
QWidget(parent),
textbox(NULL)
{
	QHBoxLayout * layout = new QHBoxLayout();
	textbox = new QLineEdit(this);
	QPushButton * btnStart = new QPushButton("Run", this);

	// connect button
	connect(btnStart, 	&QPushButton::clicked,
			this,		&MainWindow::buttonClicked);

	// connect enterpressed on textbox 
	connect(textbox, 	&QLineEdit::returnPressed,
			this, 		&MainWindow::buttonClicked);

	// build layout
	this->setLayout(layout);
	layout->addWidget(textbox);
	layout->addWidget(btnStart);

	// resize
	this->resize(this->sizeHint());
}

MainWindow::~MainWindow(){}

void MainWindow::buttonClicked()
{
	QString command = textbox->text();
	QProcess::startDetached(command);
	QApplication::exit();
}