QT       += core serialport
QT       -= gui

TARGET = teseo_example
CONFIG += console
CONFIG -= app_bundle

CONFIG += c++11

TEMPLATE = app

INCLUDEPATH += ../src

SOURCES += main.cpp

LIBS += -L../ -lteseo_qt_driver
