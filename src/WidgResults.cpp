#include "WidgResults.h"

#include <QVBoxLayout>

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
	if(list.empty()) return;


}

void WidgResults::clear()
{

}