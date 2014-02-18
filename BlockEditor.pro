#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T01:27:03
#
#-------------------------------------------------

cache()

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = DragAndDrop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blockmenu.cpp \
    canvas.cpp \
    block.cpp \
    blockfactory.cpp

HEADERS  += mainwindow.h \
    blockmenu.h \
    canvas.h \
    block.h \
    blockfactory.h

FORMS    += mainwindow.ui
