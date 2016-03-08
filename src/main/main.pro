# qmake project file of the main application

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vemoria
TEMPLATE = app

SOURCES += \
    main.cpp \

HEADERS += \

OTHER_FILES += \
    version.sh \

# tell includes.pri which libs we need
DEPENDENCY_LIBRARIES = libqgit2 libgit2 repository logic
include(../qmake/includes.pri)

win32 {
    # we need the windows socket library for libqgit2/libgit2
    LIBS += -lws2_32
}
