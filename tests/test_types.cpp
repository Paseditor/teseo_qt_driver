// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "test_types.h"
#include "teseo_types.h"

void TestTypes::positionDecimal()
{
    Teseo::Position pos;
    pos.latitude = 4811.365;
    pos.latDirection = 'N';
    pos.longitude = 1164.123;
    pos.lonDirection = 'E';

    QVERIFY(qAbs(pos.latitudeDecimal() - 48.1894167) < 0.001);
    QVERIFY(qAbs(pos.longitudeDecimal() - 12.0687167) < 0.001);

    pos.latDirection = 'S';
    pos.lonDirection = 'W';
    QVERIFY(pos.latitudeDecimal() < 0);
    QVERIFY(pos.longitudeDecimal() < 0);
}

void TestTypes::fixQualityEnum()
{
    QCOMPARE(static_cast<int>(Teseo::FixQuality::Invalid), 0);
    QCOMPARE(static_cast<int>(Teseo::FixQuality::GPS), 1);
    QCOMPARE(static_cast<int>(Teseo::FixQuality::DGPS), 2);
    QCOMPARE(static_cast<int>(Teseo::FixQuality::Estimated), 6);
}

void TestTypes::constellationEnum()
{
    QCOMPARE(static_cast<int>(Teseo::Constellation::GPS), 0);
    QCOMPARE(static_cast<int>(Teseo::Constellation::GLONASS), 1);
    QCOMPARE(static_cast<int>(Teseo::Constellation::Galileo), 2);
    QCOMPARE(static_cast<int>(Teseo::Constellation::BeiDou), 3);
    QCOMPARE(static_cast<int>(Teseo::Constellation::QZSS), 4);
}
