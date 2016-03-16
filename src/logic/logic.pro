# qmake project file of the vemoria logic layer lib

include(../qmake/common.pri)

QT       += core gui xml

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
    picture.cpp \
    undefined.cpp \
    video.cpp \
    uiservices.cpp
    xmlhandler.cpp \

HEADERS  += \
    audio.h \
    cache.h \
    cachemanager.h \
    document.h \
    filter.h \
    item.h \
    itemmanager.h \
    picture.h \
    undefined.h \
    video.h \
    uiservices.h \
    version.h \
    xmlhandler.h

