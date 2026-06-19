# ArneeCode - Teseo-VIC3 Qt Driver
# Copyright (c) 2026 ArneeCode. All rights reserved.

QT       += core serialport quick qml

TARGET = teseo_tester_qml
CONFIG += c++11
CONFIG -= console

TEMPLATE = app

INCLUDEPATH += $$PWD/../src

SOURCES += \
    main_qml.cpp \
    teseo_bridge.cpp

HEADERS += \
    teseo_bridge.h

LIBS += -L$$PWD/../release -lteseo_qt_driver

RESOURCES += qml.qrc
