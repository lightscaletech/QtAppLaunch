#include "MainWindow.h"

#include "ApplicationScanner.h"
#include "ApplicationShortcut.h"
#include "WidgResults.h"

#include <QApplication>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProcess>
#include <QDesktopWidget>
#include <QPoint>
#include <QShortcut>
#include <QTimer>

#ifdef Q_OS_LINUX
#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#endif

MainWindow::MainWindow(QWidget * parent):
    QWidget(parent,
            Qt::Dialog |
            Qt::FramelessWindowHint |
            Qt::WindowStaysOnTopHint /*|
            Qt::BypassWindowManagerHint*/),
    textbox(NULL),
    apps(NULL)
{
    #ifdef Q_OS_LINUX
    {
        unsigned long data = 0xFFFFFFFF;
        XChangeProperty (QX11Info::display(),
                         winId(),
                         XInternAtom(QX11Info::display(), "_NET_WM_DESKTOP", False),
                         XA_CARDINAL,
                         32,
                         PropModeReplace,
                         reinterpret_cast<unsigned char *>(&data), // all desktop
                         1);
    }
    #endif

    apps = new ApplicationScanner(this);
    textbox = new QLineEdit(this);
    results = new WidgResults(this);
    QVBoxLayout * vlayout = new QVBoxLayout();
    QHBoxLayout * layout = new QHBoxLayout();

    QSizePolicy policy =  this->sizePolicy();
    policy.setHorizontalPolicy(QSizePolicy::Minimum);
    policy.setVerticalPolicy(QSizePolicy::Minimum);
    this->setSizePolicy(policy);

    // stop application when focus lost
    connect(QApplication::instance(), &QGuiApplication::applicationStateChanged,
            this, &MainWindow::appStateChanged);

    // connect enter pressed on textbox
    connect(textbox, &QLineEdit::textChanged,
            this, &MainWindow::textChanged);

    this->initShortcuts();

    // build layout
    textbox->setMinimumWidth(275);
    this->setLayout(vlayout);

    layout->addWidget(textbox);

    vlayout->addLayout(layout);
    vlayout->addWidget(results);

    // resize
    this->positionRefresh();

    //show
    this->setEnabled(true);
    this->show();
}

MainWindow::~MainWindow(){}

void MainWindow::appStateChanged(Qt::ApplicationState state)
{

}

void MainWindow::initShortcuts()
{
    QShortcut * shortcut = NULL;

    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::run);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::run);
    shortcut = new QShortcut(QKeySequence("Ctrl+m"), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::run);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Down), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::next);
    shortcut = new QShortcut(QKeySequence("Ctrl+n"), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::next);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Up), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::prev);
    shortcut = new QShortcut(QKeySequence("Ctrl+p"), this);
    connect(shortcut, &QShortcut::activated,
            results, &WidgResults::prev);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(shortcut, &QShortcut::activated,
            QApplication::instance(), &QApplication::quit);
    shortcut = new QShortcut(QKeySequence("Ctrl+g"), this);
    connect(shortcut, &QShortcut::activated,
            QApplication::instance(), &QApplication::quit);

    shortcut = new QShortcut(QKeySequence("Ctrl+f"), this);
    connect(shortcut, &QShortcut::activated,
            this, &MainWindow::cursorForward);

    shortcut = new QShortcut(QKeySequence("Ctrl+b"), this);
    connect(shortcut, &QShortcut::activated,
            this, &MainWindow::cursorBackward);
}

void MainWindow::cursorForward()
{
    textbox->setCursorPosition(textbox->cursorPosition() + 1);
}

void MainWindow::cursorBackward()
{
    textbox->setCursorPosition(textbox->cursorPosition() - 1);
}

void MainWindow::positionRefresh()
{
    QTimer::singleShot(0, this, &MainWindow::shrink);
    QTimer::singleShot(0, this, &MainWindow::centre);
}

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

void MainWindow::shrink(){ this->resize(this->minimumSizeHint()); }

void MainWindow::textChanged(const QString & text)
{
    if(text.count() < 2)
    {
        results->clear();
        this->positionRefresh();
        return;
    }

    AppList list = apps->find(text);

    results->show(list);
    this->positionRefresh();
}
