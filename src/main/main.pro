# qmake project file of the main application

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vemoria
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    version.h

FORMS    += mainwindow.ui

DISTFILES += \
    version.sh \

# tell includes.pri which libs we need
DEPENDENCY_LIBRARIES = libqgit2 libgit2
include(../qmake/includes.pri)
