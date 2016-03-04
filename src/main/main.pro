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
        mainwindow.cpp \
    cachemanager.cpp \
    collection.cpp \
    collections.cpp \
    filter.cpp \
    item.cpp \
    cache.cpp \
    collectionmanager.cpp \
    itemmanager.cpp \
    picture.cpp \
    video.cpp \
    document.cpp \
    audio.cpp \
    undefined.cpp \
    undefinedgui_1.cpp \
    undefinedgui_2.cpp

HEADERS  += mainwindow.h \
    cachemanager.h \
    collection.h \
    collections.h \
    filter.h \
    item.h \
    cache.h \
    collectionmanager.h \
    itemmanager.h \
    picture.h \
    video.h \
    document.h \
    audio.h \
    undefined.h \
    undefinedgui_1.h \
    undefinedgui_2.h

FORMS    += mainwindow.ui

DISTFILES += \
    version.sh \
    VERSION
