QT       += core

QT       -= gui

TARGET = TestApp
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    timerperformer.cpp \
    threadedperformer.cpp \
    ourthread.cpp

HEADERS += \
    timerperformer.h \
    threadedperformer.h \
    ourthread.h
