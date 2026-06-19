// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TEST_CHECKSUM_H
#define TEST_CHECKSUM_H

#include <QObject>
#include <QtTest>

class TestChecksum : public QObject
{
    Q_OBJECT
private slots:
    void validChecksum();
    void invalidChecksum();
    void computeChecksum();
    void noStarReturnsInvalid();
};

#endif
