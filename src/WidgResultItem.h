#ifndef _L_WIDG_RESULT_ITEM_
#define _L_WIDG_RESULT_ITEM_

#include <QWidget>

class ApplicationShortcut;
class QLabel;

class WidgResultItem:
public QWidget
{
public:
    WidgResultItem(QWidget * = NULL);
    ~WidgResultItem();

    void setApp(ApplicationShortcut *);

    ApplicationShortcut * getApp();

private:
    void setIcon();
    ApplicationShortcut * app;
    QLabel * labAppIcon;
    QLabel * labAppName;
};

#endif
