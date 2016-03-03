#-------------------------------------------------
# Project Vemoria
#
# Vemoria aims to be an environment for archiving multimedia files.
#
#
# This project is licensed under the EUPL v.1.1 or a later version.
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vemoria
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    version.h

FORMS    += mainwindow.ui

DISTFILES += \
    version.sh \
    VERSION
