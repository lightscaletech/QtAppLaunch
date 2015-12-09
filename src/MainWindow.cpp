#include "MainWindow.h"

#include "ApplicationScanner.h"
#include "ApplicationShortcut.h"
#include "WidgResults.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProcess>
#include <QDesktopWidget>
#include <QPoint>
#include <QShortcut>

#include <QDebug>

MainWindow::MainWindow(QWidget * parent):
QWidget(parent, Qt::FramelessWindowHint),
textbox(NULL),
apps(NULL)
{
	apps = new ApplicationScanner(this);
	textbox = new QLineEdit(this);
	results = new WidgResults(this);
	QVBoxLayout * vlayout = new QVBoxLayout();
	QHBoxLayout * layout = new QHBoxLayout();
	QPushButton * btnStart = new QPushButton("Run", this);


	// connect enterpressed on textbox 
	connect(textbox, 	&QLineEdit::textChanged,
			this, 		&MainWindow::textChanged);

	QShortcut * shortcut = NULL;
	
	shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
	connect(shortcut, 	&QShortcut::activated,
			results, 	&WidgResults::run);

	shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(shortcut, 	&QShortcut::activated,
			results, 	&WidgResults::run);

	shortcut = new QShortcut(QKeySequence(Qt::Key_Down), this);
	connect(shortcut, 	&QShortcut::activated,
			results, 	&WidgResults::next);

	shortcut = new QShortcut(QKeySequence(Qt::Key_Up), this);
	connect(shortcut, 	&QShortcut::activated,
			results, 	&WidgResults::prev);

	// build layout
	textbox->setMinimumWidth(200);
	this->setLayout(vlayout);

	layout->addWidget(textbox);
	layout->addWidget(btnStart);

	vlayout->addLayout(layout);
	vlayout->addWidget(results);

	// resize
	this->shrink();
	this->centre();
}

MainWindow::~MainWindow(){}

void MainWindow::centre()
{
	QRect rect = this->rect();
	QDesktopWidget dwidg;
	QRect drect = dwidg.availableGeometry();
	QPoint pos;

	pos.setX((drect.width() / 2) - (rect.width() / 2));
	pos.setY((drect.height() / 2) - (rect.height() / 2));

	this->move(pos);
}

void MainWindow::shrink(){ this->resize(this->sizeHint()); }

void MainWindow::textChanged(const QString & text)
{
	if(text.count() < 2)
	{
		results->clear();
		this->updateGeometry();
		this->shrink();
		this->centre();
		return;
	}

	AppList list = apps->find(text);

	results->show(list);
	this->updateGeometry();
	this->shrink();
	this->centre();
}
