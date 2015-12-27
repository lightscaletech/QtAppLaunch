#include "WidgResults.h"

#include "ApplicationShortcut.h"
#include "WidgResultItem.h"

#include <QVBoxLayout>
#include <QPalette>

WidgResults::WidgResults(QWidget * parent):
QWidget(parent),
layout(NULL),
selected(NULL)
{
	layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(layout);
	this->hide();
}

WidgResults::~WidgResults(){}

void WidgResults::clear()
{
	foreach (QWidget * w, this->findChildren<QWidget*>()) delete w;
	this->hide();
	selected = NULL;
	this->update();
}

void WidgResults::show(const AppList & list)
{
	clear();
	if(list.empty()) return;

	WidgResultItem * resItem = NULL;

	for (auto item : list)
	{
		resItem = new WidgResultItem(this);
		resItem->setText(item->getApplicationName());
		resItem->setApp(item);
		resItem->setAutoFillBackground(true);

		layout->addWidget(resItem);
	}	
	next();
	QWidget::show();
}

void WidgResults::select(int index)
{
	QLayoutItem * lItem = layout->itemAt(index);
	if(!lItem) return;
	
	QWidget * widg = lItem->widget();
	if(!widg) return;

	WidgResultItem * item =  static_cast<WidgResultItem *>(widg);

	if(item == selected) return;

	QPalette pal = item->palette();
	pal.setColor(item->backgroundRole(), QColor(0xC0, 0xC0, 0xC0));

	item->setPalette(pal);

	unselect();
	selected = item;
}

void WidgResults::unselect()
{
	if(!selected) return;

	QPalette pal = selected->palette();
	pal.setColor(selected->backgroundRole(), this->palette().color(this->backgroundRole()));


	selected->setPalette(pal);

	selected = NULL;
}

void WidgResults::next()
{
	int index = 0;

	if(selected) index = layout->indexOf(selected) + 1;

	if(index >= layout->count()) index = 0;
	else if(index < 0) index = 0;

	select(index);
}

void WidgResults::prev()
{
	int index = layout->count();

	if(selected) index = layout->indexOf(selected) - 1;

	if(index >= layout->count()) index = layout->count() - 1;
	else if(index < 0) index = layout->count() - 1;

	select(index);
}

void WidgResults::run()
{
	selected->getApp()->run();
}