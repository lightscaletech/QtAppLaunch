#include "WidgResults.h"

#include "ApplicationShortcut.h"

#include <QVBoxLayout>
#include <QLabel>

WidgResults::WidgResults(QWidget * parent):
QWidget(parent),
layout(NULL)
{
	layout = new QVBoxLayout();
	this->setLayout(layout);
}

WidgResults::~WidgResults(){}

void WidgResults::show(const AppList & list)
{
	clear();
	if(list.empty()) return;

	QLabel * lab = NULL;

	for (auto item : list)
	{
		lab = new QLabel(this);
		lab->setText(item->getApplicationName());

		layout->addWidget(lab);
	}
	QWidget::show();
}

void WidgResults::clear()
{
	foreach (QWidget * w, this->findChildren<QWidget*>()) delete w;
	this->hide();
}