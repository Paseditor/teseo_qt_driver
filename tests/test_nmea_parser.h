// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TEST_NMEA_PARSER_H
#define TEST_NMEA_PARSER_H

#include <QObject>
#include <QtTest>

class TestNmeaParser : public QObject
{
    Q_OBJECT
private slots:
    void parseGGA();
    void parseRMC();
    void parseGSA();
    void parseGSV();
    void parseVTG();
    void parseZDA();
    void parseGST();
    void parseMultiple();
    void invalidChecksumIgnored();
    void partialDataBuffered();
};

#endif
