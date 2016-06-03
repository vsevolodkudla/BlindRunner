#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T19:30:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlindRunner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    sountobject.cpp \
    game.cpp \
    menu.cpp

HEADERS  += mainwindow.h \
    player.h \
    sountobject.h \
    game.h \
    menu.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

unix|win32: LIBS += -lEFX-Util

unix|win32: LIBS += -lOpenAL32

unix|win32: LIBS += -lOpenAL32


INCLUDEPATH += $$PWD/'../../../../../Program Files (x86)/OpenAL 1.1 SDK/samples/framework/Win32'
DEPENDPATH += $$PWD/'../../../../../Program Files (x86)/OpenAL 1.1 SDK/samples/framework/Win32'
