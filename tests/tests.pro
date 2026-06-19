QT       += testlib serialport
QT       -= gui widgets

TARGET = teseo_tests
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += ../src

SOURCES += \
    test_main.cpp \
    test_nmea_parser.cpp \
    test_types.cpp \
    test_checksum.cpp

HEADERS += \
    test_nmea_parser.h \
    test_types.h \
    test_checksum.h

LIBS += -L../release -lteseo_qt_driver
