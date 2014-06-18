#-------------------------------------------------
#
# Project created by QtCreator 2014-06-18T17:58:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Temperaturanzeige
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui
