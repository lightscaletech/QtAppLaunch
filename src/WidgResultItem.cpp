#include "WidgResultItem.h"

#include "ApplicationShortcut.h"
#include "GtkIconLoader.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QImage>

WidgResultItem::WidgResultItem(QWidget * parent):
QWidget(parent),
app(NULL)
{
    labAppIcon = new QLabel(this);
    labAppName = new QLabel(this);

    QHBoxLayout * layout = new QHBoxLayout();

    layout->addWidget(labAppIcon);
    layout->addWidget(labAppName);

    this->setLayout(layout);
    this->setAutoFillBackground(true);
}

WidgResultItem::~WidgResultItem(){}

void WidgResultItem::setApp(ApplicationShortcut * app)
{
    this->app = app;
    labAppName->setText(app->getApplicationName());
    this->setIcon();
}
ApplicationShortcut * WidgResultItem::getApp() { return app; }

void WidgResultItem::setIcon()
{
    int labelSize = 18;
    GtkIconLoader icon;
    int iconWidth = 0;
    unsigned char * iconData = icon.getIcon(app->getApplicationIcon(),
                                            iconWidth);
    if(iconData)
    {
        QImage image(iconData, iconWidth, iconWidth,
                     QImage::Format_RGBA8888);
        QPixmap pixmap = QPixmap::fromImage(image);
        labAppIcon->setPixmap(pixmap.scaledToWidth(labelSize,
                                                   Qt::SmoothTransformation));
    }

    labAppIcon->setSizePolicy(QSizePolicy(QSizePolicy::Minimum,
                                          QSizePolicy::Minimum));
    labAppIcon->setMinimumSize(0, 0);
    labAppIcon->setMaximumSize(labelSize, labelSize);
    labAppIcon->updateGeometry();
}
