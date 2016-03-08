# qmake project file of the vemoria logic layer lib

include(../qmake/common.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    mainwindow.cpp \
    popupcollection.cpp \
    undefinedgui_1.cpp \
    undefinedgui_2.cpp \

HEADERS  += \
    mainwindow.h \
    popupcollection.h \
    undefinedgui_1.h \
    undefinedgui_2.h \

FORMS += \
    mainwindow.ui \
    popupcollection.ui \
