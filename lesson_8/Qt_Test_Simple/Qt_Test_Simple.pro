#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T21:58:57
#
#-------------------------------------------------

QT       += core testlib # testlib - библиотека для модульного тестирования

QT       -= gui

TARGET = Qt_Test_Simple
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sum.cpp

HEADERS += \
    tests.h \
    sum.h
