// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "test_checksum.h"
#include "nmea_parser.h"

void TestChecksum::validChecksum()
{
    QByteArray payload = "GPGGA,183417.000,04814.03970,N,01128.52205,E,0,00,99.0,495.53,M,47.6,M";
    QByteArray cs = Teseo::NmeaParser::computeChecksum(payload);
    QByteArray sentence = "$" + payload + "*" + cs;
    QVERIFY(Teseo::NmeaParser::validateChecksum(sentence));
}

void TestChecksum::invalidChecksum()
{
    QByteArray sentence = "$GPGGA,183417.000,04814.03970,N,01128.52205,E,0,00,99.0,495.53,M,47.6,M*00";
    QVERIFY(!Teseo::NmeaParser::validateChecksum(sentence));
}

void TestChecksum::computeChecksum()
{
    QByteArray payload = "GPGGA,183417.000,04814.03970,N,01128.52205,E,0,00,99.0,495.53,M,47.6,M";
    QByteArray checksum = Teseo::NmeaParser::computeChecksum(payload);
    QCOMPARE(checksum.size(), 2);
    QVERIFY(checksum == "60");
}

void TestChecksum::noStarReturnsInvalid()
{
    QByteArray sentence = "$GPGGA,183417.000";
    QVERIFY(!Teseo::NmeaParser::validateChecksum(sentence));
}
