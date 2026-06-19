QT       += core serialport
QT       -= gui

TARGET = teseo_qt_driver
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

SOURCES += \
    src/teseo_driver.cpp \
    src/nmea_parser.cpp \
    src/serial_interface.cpp

HEADERS += \
    src/teseo_driver.h \
    src/nmea_parser.h \
    src/teseo_types.h \
    src/serial_interface.h
