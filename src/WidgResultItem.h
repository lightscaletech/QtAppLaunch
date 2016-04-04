#ifndef _L_WIDG_RESULT_ITEM_
#define _L_WIDG_RESULT_ITEM_

#include <QLabel>

class ApplicationShortcut;

class WidgResultItem:
public QLabel
{
public:
    WidgResultItem(QWidget * = NULL);
    ~WidgResultItem();

    void setApp(ApplicationShortcut *);

    ApplicationShortcut * getApp();

private:
    ApplicationShortcut * app;
};

#endif
