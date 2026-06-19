// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TEST_TYPES_H
#define TEST_TYPES_H

#include <QObject>
#include <QtTest>

class TestTypes : public QObject
{
    Q_OBJECT
private slots:
    void positionDecimal();
    void fixQualityEnum();
    void constellationEnum();
};

#endif
