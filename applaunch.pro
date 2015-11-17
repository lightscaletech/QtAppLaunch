TEMPLATE = app

QT += gui
QT += widgets

CONFIG += c++11

# Output
TARGET = bin/applaunch
OBJECTS_DIR = obj
QMAKE_CXXFLAGS += -ggdb
MOC_DIR = moc

# Input
HEADERS += src/MainWindow.h
SOURCES += src/MainWindow.cpp

SOURCES += src/applaunch.cpp
