# qmake project file of the vemoria logic layer lib

include(../qmake/common.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logic
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    audio.cpp \
    cache.cpp \
    cachemanager.cpp \
    document.cpp \
    filter.cpp \
    item.cpp \
    itemmanager.cpp \
    mainwindow.cpp \
    picture.cpp \
    popupcollection.cpp \
    undefined.cpp \
    undefinedgui_1.cpp \
    video.cpp \

HEADERS  += \
    audio.h \
    cache.h \
    cachemanager.h \
    document.h \
    filter.h \
    item.h \
    itemmanager.h \
    mainwindow.h \
    picture.h \
    popupcollection.h \
    undefinedgui_1.h \
    undefinedgui_2.h \
    undefined.h \
    video.h \
    version.h \

FORMS += \
    mainwindow.ui \
    popupcollection.ui \

