#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T21:01:47
#
#-------------------------------------------------

QT       += core gui

# Автоматические тесты
QT       += testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRegExp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qregexptest.cpp

HEADERS  += mainwindow.h \
    qregexptest.h

FORMS    += mainwindow.ui
