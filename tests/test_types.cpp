// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "test_types.h"
#include "teseo_types.h"

void TestTypes::positionDecimal_data()
{
    QTest::addColumn<double>("lat_ddmm");
    QTest::addColumn<char>("lat_dir");
    QTest::addColumn<double>("expected_lat");
    QTest::addColumn<double>("lon_ddmm");
    QTest::addColumn<char>("lon_dir");
    QTest::addColumn<double>("expected_lon");

    QTest::newRow("North-East") << 4811.365 << 'N' << 48.1894167
                                 << 01164.123 << 'E' << 11.0687167;
    QTest::newRow("South-West") << 3352.0 << 'S' << -33.8666667
                                 << 01825.0 << 'W' << -18.4166667;
}

void TestTypes::positionDecimal()
{
    QFETCH(double, lat_ddmm);
    QFETCH(char, lat_dir);
    QFETCH(double, expected_lat);
    QFETCH(double, lon_ddmm);
    QFETCH(char, lon_dir);
    QFETCH(double, expected_lon);

    Teseo::Position pos;
    pos.latitude = lat_ddmm;
    pos.latDirection = lat_dir;
    pos.longitude = lon_ddmm;
    pos.lonDirection = lon_dir;

    QVERIFY(qAbs(pos.latitudeDecimal() - expected_lat) < 0.001);
    QVERIFY(qAbs(pos.longitudeDecimal() - expected_lon) < 0.001);
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
