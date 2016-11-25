#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T08:17:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autovoiture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systeme.cpp \
    addvehiculedialog.cpp \
    vehicule.cpp \
    addchauffeurdialog.cpp \
    chauffeur.cpp

HEADERS  += mainwindow.h \
    systeme.h \
    addvehiculedialog.h \
    vehicule.h \
    addchauffeurdialog.h \
    chauffeur.h

FORMS    += mainwindow.ui \
    addvehiculedialog.ui \
    addchauffeurdialog.ui
