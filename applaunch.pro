TEMPLATE = app

QT += gui
QT += widgets
QT += x11extras

CONFIG += c++11
CONFIG += link_pkgconfig

PKGCONFIG += gtk+-3.0

unix:!macx {
LIBS += -lX11
}

# Output
TARGET = bin/applaunch
OBJECTS_DIR = obj
QMAKE_CXXFLAGS += -ggdb
MOC_DIR = moc

# Input
HEADERS += src/RunGuard.h
SOURCES += src/RunGuard.cpp

HEADERS += src/Frequency.h
SOURCES += src/Frequency.cpp

HEADERS += src/GtkInit.h
SOURCES += src/GtkInit.cpp

HEADERS += src/GtkIconLoader.h
SOURCES += src/GtkIconLoader.cpp

HEADERS += src/ApplicationShortcut.h
SOURCES += src/ApplicationShortcut.cpp

HEADERS += src/ApplicationScanner.h
SOURCES += src/ApplicationScanner.cpp

HEADERS += src/WidgResults.h
SOURCES += src/WidgResults.cpp

HEADERS += src/WidgResultItem.h
SOURCES += src/WidgResultItem.cpp

HEADERS += src/MainWindow.h
SOURCES += src/MainWindow.cpp

SOURCES += src/applaunch.cpp

target.path = /usr/local/bin

INSTALLS += target
