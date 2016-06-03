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
    sountobject.cpp

HEADERS  += mainwindow.h \
    player.h \
    sountobject.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

