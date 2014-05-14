#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T20:56:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimCity
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cstructure.cpp \
    ccoordinates.cpp \
    cgraphic.cpp \
    ccity.cpp \
    croadsandbridges.cpp \
    cdirections.cpp \
    croad.cpp \
    cstructureforpeople.cpp \
    cgreenterrain.cpp \
    cbuilding.cpp \
    cutilitiesglobal.cpp

HEADERS  += mainwindow.h \
    cstructure.h \
    ccoordinates.h \
    enumerators.h \
    cgraphic.h \
    ccity.h \
    croadsandbridges.h \
    cdirections.h \
    croad.h \
    cstructureforpeople.h \
    cgreenterrain.h \
    cbuilding.h \
    cutilitiesglobal.h

FORMS    += mainwindow.ui
