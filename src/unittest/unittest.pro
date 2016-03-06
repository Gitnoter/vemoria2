QT += testlib
QT -= gui


TARGET = unittest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    tests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
