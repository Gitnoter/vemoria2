# qmake project file of the main application

# we need these QT libs
QT += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vemoria
TEMPLATE = app

SOURCES += \
    main.cpp \

HEADERS += \

OTHER_FILES += \
    version.sh \

RESOURCES = ../gui/resource.qrc

# tell includes.pri which libs we need to link
DEPENDENCY_LIBRARIES = gui logic repository libqgit2 libgit2
include(../qmake/includes.pri)

win32 {
    # we need the windows socket library for libqgit2/libgit2
    LIBS += -lws2_32
}
