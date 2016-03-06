# qmake project file of vemoria unit tests
#
# these tests will be executed by Jenkins automatically

QT += testlib
QT -= gui
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle    # for Mac users

TARGET = unittest
TEMPLATE = app

HEADERS += \
    AutoTest.h \

SOURCES += \
    testmain.cpp \
    VersionTest.cpp \
    RepositoryTest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
