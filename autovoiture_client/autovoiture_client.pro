#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T21:11:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autovoiture_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    systeme.cpp \
    inscriptiondialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    systeme.h \
    inscriptiondialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    inscriptiondialog.ui
