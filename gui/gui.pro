# ArneeCode - Teseo-VIC3 Qt Driver
# Copyright (c) 2026 ArneeCode. All rights reserved.

QT       += core serialport widgets

TARGET = teseo_tester
CONFIG += c++11
CONFIG -= console

TEMPLATE = app

INCLUDEPATH += $$PWD/../src

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connectionpage.cpp \
    infopage.cpp \
    commandpage.cpp \
    configpage.cpp \
    agnsspage.cpp \
    deadreckoningpage.cpp \
    logpage.cpp

HEADERS += \
    mainwindow.h \
    connectionpage.h \
    infopage.h \
    commandpage.h \
    configpage.h \
    agnsspage.h \
    deadreckoningpage.h \
    logpage.h \
    splashscreen.h \
    style.h

LIBS += -L$$PWD/../release -lteseo_qt_driver
