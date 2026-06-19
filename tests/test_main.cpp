// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include <QCoreApplication>
#include <QtTest>
#include "test_types.h"
#include "test_checksum.h"
#include "test_nmea_parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int status = 0;

    {
        TestTypes test;
        status |= QTest::qExec(&test, argc, argv);
    }
    {
        TestChecksum test;
        status |= QTest::qExec(&test, argc, argv);
    }
    {
        TestNmeaParser test;
        status |= QTest::qExec(&test, argc, argv);
    }

    return status;
}
