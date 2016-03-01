#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T09:29:13
#
#-------------------------------------------------

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
    VERSION
