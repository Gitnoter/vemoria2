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
    copydialog.cpp \
    timer.cpp \
    selectcollection.cpp

HEADERS  += \
    mainwindow.h \
    popupcollection.h \
    undefinedgui_1.h \
    undefinedgui_2.h \
    copydialog.h \
    timer.h \
    selectcollection.h

FORMS += \
    mainwindow.ui \
    popupcollection.ui \
    copydialog.ui \
    selectcollection.ui

RESOURCES += \
    resource.qrc

