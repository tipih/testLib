#-------------------------------------------------
#
# Project created by QtCreator 2014-03-17T19:02:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testLib
TEMPLATE = app
INCLUDEPATH += "C:\mosquitto\devel"

SOURCES += main.cpp\
        testwidget.cpp \
    mymqtt.cpp

HEADERS  += testwidget.h \
    mymqtt.h

FORMS    += testwidget.ui





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../mosquitto/devel/ -lmosquittopp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../mosquitto/devel/ -lmosquittopp

INCLUDEPATH += $$PWD/../../../../mosquitto/devel
DEPENDPATH += $$PWD/../../../../mosquitto/devel
