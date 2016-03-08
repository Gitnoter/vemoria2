# qmake project file of the main application

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vemoria
TEMPLATE = app

INCLUDEPATH += \
  ../libqgit2/qgit2 \
  ../libgit2/include \
  ../unittest \

SOURCES += \
    main.cpp \
    audio.cpp \
    cache.cpp \
    cachemanager.cpp \
    collection.cpp \
    collectionmanager.cpp \
    collections.cpp \
    document.cpp \
    filter.cpp \
    item.cpp \
    itemmanager.cpp \
    mainwindow.cpp \
    picture.cpp \
    undefined.cpp \
    undefinedgui_1.cpp \
    video.cpp \

HEADERS  += \
    audio.h \
    cache.h \
    cachemanager.h \
    collection.h \
    collectionmanager.h \
    collections.h \
    document.h \
    filter.h \
    item.h \
    itemmanager.h \
    mainwindow.h \
    picture.h \
    undefinedgui_1.h \
    undefinedgui_2.h \
    undefined.h \
    video.h \
    version.h \

FORMS += \
    mainwindow.ui \

OTHER_FILES += \
    version.sh \

# tell includes.pri which libs we need
DEPENDENCY_LIBRARIES = libqgit2 libgit2 repository
include(../qmake/includes.pri)

win32 {
    # currently we use a static libqgit2 library, so avoid declspec for dllimport/dllexport
    # just define an empty LIBQGIT2_EXPORT, see libgit2_config.h
    DEFINES += LIBQGIT2_EXPORT=""

    # additionally, we need the windows socket library
    LIBS += -lws2_32
}
