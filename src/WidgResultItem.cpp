#include "WidgResultItem.h"

#include "ApplicationShortcut.h"

WidgResultItem::WidgResultItem(QWidget * parent):
QLabel(parent),
app(NULL)
{

}

WidgResultItem::~WidgResultItem(){}

void WidgResultItem::setApp(ApplicationShortcut * app) { this->app = app; }
ApplicationShortcut * WidgResultItem::getApp() { return app; }
