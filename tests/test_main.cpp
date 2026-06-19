// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include <QCoreApplication>
#include <QtTest>
#include "test_types.h"
#include "test_checksum.h"
#include "test_nmea_parser.h"

#define RUN_TEST(Class) \
    { \
        Class t; \
        int r = QTest::qExec(&t, argc, argv); \
        if (r != 0) return r; \
    }

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    RUN_TEST(TestTypes)
    RUN_TEST(TestChecksum)
    RUN_TEST(TestNmeaParser)

    return 0;
}
