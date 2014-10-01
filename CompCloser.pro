#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T21:26:25
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CompCloser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    controler.cpp \
    model.cpp

HEADERS  += mainwindow.h \
    view.h \
    controler.h \
    model.h

FORMS    += mainwindow.ui
