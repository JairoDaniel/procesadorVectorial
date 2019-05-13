#-------------------------------------------------
#
# Project created by QtCreator 2019-05-12T13:35:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adder.cpp \
    alu.cpp \
    bus8.cpp \
    bus32.cpp \
    bus64.cpp \
    clock.cpp \
    decoder.cpp \
    loadStoreUnit.cpp \
    memoryD.cpp \
    memoryI.cpp \
    mux21.cpp \
    mux218b.cpp \
    pc.cpp \
    registerE.cpp \
    registerV.cpp

HEADERS  += mainwindow.h \
    constants.h

FORMS    += mainwindow.ui

DISTFILES += \
    shiftCode.txt \
    SRCode.txt \
    xorCode.txt

CONFIG += link_pkgconfig
PKGCONFIG += opencv

CONFIG  +=  c++14

QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp
