#include "MainWindow.h"

#include "ApplicationScanner.h"
#include "ApplicationShortcut.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProcess>

#include <QDebug>

MainWindow::MainWindow(QWidget * parent):
QWidget(parent),
textbox(NULL),
apps(NULL)
{
	apps = new ApplicationScanner(this);
	QHBoxLayout * layout = new QHBoxLayout();
	textbox = new QLineEdit(this);
	QPushButton * btnStart = new QPushButton("Run", this);

	// connect button
	connect(btnStart, 	&QPushButton::clicked,
			this,		&MainWindow::buttonClicked);

	// connect enterpressed on textbox 
	connect(textbox, 	&QLineEdit::returnPressed,
			this, 		&MainWindow::buttonClicked);

	// connect enterpressed on textbox 
	connect(textbox, 	&QLineEdit::textChanged,
			this, 		&MainWindow::textChanged);

	// build layout
	this->setLayout(layout);
	layout->addWidget(textbox);
	layout->addWidget(btnStart);

	// resize
	this->resize(this->sizeHint());
}

MainWindow::~MainWindow(){}

void MainWindow::textChanged(const QString & text)
{
	if(text.count() < 2) return;

	AppList list = apps->find(text);

	for(auto item : list)
	{
		qDebug() << item->getApplicationName();
	}
}

void MainWindow::buttonClicked()
{
	QString command = textbox->text();
	QProcess::startDetached(command);
	QApplication::exit();
}