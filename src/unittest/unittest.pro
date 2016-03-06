# qmake project file of vemoria unit tests
#
# these tests will be executed by Jenkins automatically

QT += testlib
QT -= gui
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle    # for Mac users

TARGET = run-unittest
TEMPLATE = app

HEADERS += \
    AutoTest.h \

SOURCES += \
    testmain.cpp \
    VersionTest.cpp \
    LibqgitTest.cpp \
    RepositoryTest.cpp \

DEFINES += SRCDIR=\\\"$$PWD/\\\"

# tell includes.pri which libs we need
DEPENDENCY_LIBRARIES = libqgit2 libgit2
include(../qmake/includes.pri)

win32 {
    # currently we use a static libqgit2 library, so avoid declspec for dllimport/dllexport
    # just define an empty LIBQGIT2_EXPORT, see libgit2_config.h
    DEFINES += LIBQGIT2_EXPORT=""

    # additionally, we need the windows socket library
    LIBS += -lws2_32
}
