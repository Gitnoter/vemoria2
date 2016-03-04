QT -= gui
QT += testlib
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle    # for Mac users

TARGET = test-libqgit2-init
TEMPLATE = app

INCLUDEPATH += \
  ../libqgit2 \
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

LIBS += ../libqgit2/libqgit2.a ../libgit2/libgit2.a
