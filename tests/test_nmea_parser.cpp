// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "test_nmea_parser.h"
#include "nmea_parser.h"
#include "teseo_types.h"

static QByteArray makeValidSentence(const QByteArray &payload)
{
    quint8 cs = 0;
    for (char c : payload) cs ^= static_cast<quint8>(c);
    QByteArray hex = QByteArray::number(cs, 16).rightJustified(2, '0').toUpper();
    return "$" + payload + "*" + hex + "\r\n";
}

void TestNmeaParser::parseGGA()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::fixUpdated);

    QByteArray sentence = makeValidSentence("GPGGA,183417.000,4814.03970,N,01128.52205,E,1,08,1.2,495.53,M,47.6,M,,");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    Teseo::GnssData data = spy.at(0).at(0).value<Teseo::GnssData>();
    QCOMPARE(data.fixQuality, Teseo::FixQuality::GPS);
    QCOMPARE(data.satellitesUsed, 8);
    QVERIFY(qAbs(data.dop.hdop - 1.2) < 0.01);
    QVERIFY(qAbs(data.position.altitude - 495.53) < 0.01);
    QVERIFY(data.position.valid);
}

void TestNmeaParser::parseRMC()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::velocityUpdated);

    QByteArray sentence = makeValidSentence("GPRMC,183417.000,A,4814.040,N,01128.522,E,0.5,90.0,170907,,,A");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    Teseo::Velocity vel = spy.at(0).at(0).value<Teseo::Velocity>();
    QVERIFY(qAbs(vel.speedKnots - 0.5) < 0.01);
    QVERIFY(qAbs(vel.courseTrue - 90.0) < 0.01);
}

void TestNmeaParser::parseGSA()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::dopUpdated);

    QByteArray sentence = makeValidSentence("GPGSA,A,3,05,21,07,24,30,16,12,,,,,,2.4,1.9,1.5");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    Teseo::DOP dop = spy.at(0).at(0).value<Teseo::DOP>();
    QVERIFY(qAbs(dop.pdop - 2.4) < 0.01);
    QVERIFY(qAbs(dop.hdop - 1.9) < 0.01);
    QVERIFY(qAbs(dop.vdop - 1.5) < 0.01);
}

void TestNmeaParser::parseGSV()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::satellitesUpdated);

    QByteArray sentence = makeValidSentence("GPGSV,1,1,04,02,04,037,30,05,27,125,44,06,78,051,23,07,83,021,30");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    QVector<Teseo::Satellite> sats = spy.at(0).at(0).value<QVector<Teseo::Satellite>>();
    QCOMPARE(sats.size(), 4);
    QCOMPARE(sats[0].prn, 2);
    QCOMPARE(sats[0].elevation, 4);
    QCOMPARE(sats[0].azimuth, 37);
    QCOMPARE(sats[0].cn0, 30);
}

void TestNmeaParser::parseVTG()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::velocityUpdated);

    QByteArray sentence = makeValidSentence("GPVTG,73.2,T,,M,0.2,N,0.4,K,D");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    Teseo::Velocity vel = spy.at(0).at(0).value<Teseo::Velocity>();
    QVERIFY(qAbs(vel.courseTrue - 73.2) < 0.01);
    QVERIFY(qAbs(vel.speedKnots - 0.2) < 0.01);
    QVERIFY(qAbs(vel.speedKmh - 0.4) < 0.01);
}

void TestNmeaParser::parseZDA()
{
    Teseo::NmeaParser parser;

    QByteArray sentence = makeValidSentence("GPZDA,110505.00,25,01,2013,00,00");
    parser.processData(sentence);

    Teseo::GnssData data = parser.currentData();
    QCOMPARE(data.utcDateTime.date(), QDate(2013, 1, 25));
    QCOMPARE(data.utcDateTime.time(), QTime(11, 5, 5, 0));
}

void TestNmeaParser::parseGST()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::accuracyUpdated);

    QByteArray sentence = makeValidSentence("GPGST,101429.000,0.0,3.5,3.1,89.4,3.2,3.4,3.4");
    parser.processData(sentence);

    QCOMPARE(spy.count(), 1);
    Teseo::Accuracy acc = spy.at(0).at(0).value<Teseo::Accuracy>();
    QVERIFY(qAbs(acc.ehpe - 0.0) < 0.01);
    QVERIFY(qAbs(acc.semiMajor - 3.5) < 0.01);
    QVERIFY(qAbs(acc.latErr - 3.2) < 0.01);
}

void TestNmeaParser::parseMultiple()
{
    Teseo::NmeaParser parser;
    QSignalSpy fixSpy(&parser, &Teseo::NmeaParser::fixUpdated);
    QSignalSpy velSpy(&parser, &Teseo::NmeaParser::velocityUpdated);

    QByteArray data =
        makeValidSentence("GPGGA,183417.000,4814.03970,N,01128.52205,E,1,08,1.2,495.53,M,47.6,M,,") +
        makeValidSentence("GPRMC,183417.000,A,4814.040,N,01128.522,E,0.5,90.0,170907,,,A");

    parser.processData(data);

    QCOMPARE(fixSpy.count(), 1);
    QCOMPARE(velSpy.count(), 1);
}

void TestNmeaParser::invalidChecksumIgnored()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::fixUpdated);

    QByteArray sentence = "$GPGGA,183417.000,4814.03970,N,01128.52205,E,1,08,1.2,495.53,M,47.6,M,,*00\r\n";
    parser.processData(sentence);

    QCOMPARE(spy.count(), 0);
}

void TestNmeaParser::partialDataBuffered()
{
    Teseo::NmeaParser parser;
    QSignalSpy spy(&parser, &Teseo::NmeaParser::fixUpdated);

    QByteArray full = makeValidSentence("GPGGA,183417.000,4814.03970,N,01128.52205,E,1,08,1.2,495.53,M,47.6,M,,");
    QByteArray part1 = full.left(full.size() - 1);
    QByteArray part2 = full.right(1);

    parser.processData(part1);
    QCOMPARE(spy.count(), 0);

    parser.processData(part2);
    QCOMPARE(spy.count(), 1);
}
