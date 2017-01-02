#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T13:58:38
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetSE
TEMPLATE = app


SOURCES += main.cpp\
    ordonnanceur.cpp \
    processus.cpp \
    gantt.cpp \
    fenetreacceuil.cpp

HEADERS  += \
    ordonnanceur.h \
    processus.h \
    gantt.h \
    fenetreacceuil.h

FORMS    += fenetreacceuil.ui \
    ordonnanceur.ui \
    processus.ui
