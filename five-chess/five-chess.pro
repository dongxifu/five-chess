#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T18:45:40
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia
RC_FILE = log.rc
LIBS+=ws2_32.lib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = five-chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    ip.cpp \
    pminin.cpp \
    place.cpp \
    client-server.cpp

HEADERS  += mainwindow.h \
    login.h \
    ip.h \
    pminin.h \
    extern.h \
    place.h \
    client-server.h

FORMS    += mainwindow.ui \
    login.ui \
    ip.ui

RESOURCES += \
    pic.qrc
