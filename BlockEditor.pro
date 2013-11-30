#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T01:27:03
#
#-------------------------------------------------

cache()

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DragAndDrop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blockmenu.cpp \
    canvas.cpp \
    block.cpp

HEADERS  += mainwindow.h \
    blockmenu.h \
    canvas.h \
    block.h

FORMS    += mainwindow.ui
