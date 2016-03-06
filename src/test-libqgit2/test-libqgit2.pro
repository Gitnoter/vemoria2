# qmake project file of libqgit2 examples

QT -= gui
QT += testlib
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle    # for Mac users

TARGET = run-test-libqgit2
TEMPLATE = app

INCLUDEPATH += \
  ../libqgit2/qgit2 \
  ../libgit2/include \

HEADERS += \
  AutoTest.h \
  ../libqgit2/tests/TestHelpers.h \

SOURCES += \
  testmain.cpp \
  ../libqgit2/tests/TestHelpers.cpp \
  ../libqgit2/tests/Init.cpp \
  ../libqgit2/tests/Checkout.cpp \
  ../libqgit2/tests/Clone.cpp \
  ../libqgit2/tests/Diff.cpp \
  ../libqgit2/tests/Fetch.cpp \
  ../libqgit2/tests/Push.cpp \
  ../libqgit2/tests/Rebase.cpp \
  ../libqgit2/tests/Repository.cpp \
  ../libqgit2/tests/Revision.cpp \

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
