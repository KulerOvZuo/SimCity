#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T20:56:37
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimCity
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    cstructure.cpp \
    ccoordinates.cpp \
    ccity.cpp \
    croadsandbridges.cpp \
    cdirections.cpp \
    croad.cpp \
    cstructureforpeople.cpp \
    cgreenterrain.cpp \
    cbuilding.cpp \
    cutilitiesglobal.cpp \
    cpeopleneeds.cpp \
    cliving.cpp \
    cpeople.cpp \
    clearningpeople.cpp \
    cpeopleearnings.cpp \
    cschool.cpp \
    cworking.cpp \
    ctaxes.cpp \
    cproductionbuilding.cpp \
    cfoodproduction.cpp \
    cfactory.cpp \
    cpublicutilitybuilding.cpp \
    cservicebuilding.cpp \
    crecreationbuilding.cpp \
    cshop.cpp \
    cmarket.cpp \
    csocietyindicators.cpp \
    cmapofstructures.cpp \
    ctrafficengine.cpp \
    cgraphictaxes.cpp \
    cgraphicmainview.cpp \
    cgraphicgametile.cpp \
    cgraphicbuildingtile.cpp \
    idisplayinginterface.cpp \
    cstartingwindow.cpp

HEADERS  += mainwindow.h \
    cstructure.h \
    ccoordinates.h \
    enumerators.h \
    ccity.h \
    croadsandbridges.h \
    cdirections.h \
    croad.h \
    cstructureforpeople.h \
    cgreenterrain.h \
    cbuilding.h \
    cutilitiesglobal.h \
    cpeopleneeds.h \
    cliving.h \
    cpeople.h \
    clearningpeople.h \
    cpeopleearnings.h \
    cschool.h \
    cworking.h \
    ctaxes.h \
    cproductionbuilding.h \
    cfoodproduction.h \
    cfactory.h \
    cpublicutilitybuilding.h \
    cservicebuilding.h \
    crecreationbuilding.h \
    cshop.h \
    cmarket.h \
    csocietyindicators.h \
    cmapofstructures.h \
    ctrafficengine.h \
    cgraphictaxes.h \
    cgraphicmainview.h \
    cgraphicgametile.h \
    cgraphicbuildingtile.h \
    idisplayinginterface.h \
    cstartingwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    drawing.qrc
