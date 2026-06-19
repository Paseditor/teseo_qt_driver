// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef DEADRECKONINGPAGE_H
#define DEADRECKONINGPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

#include "teseo_driver.h"

class DeadReckoningPage : public QWidget
{
    Q_OBJECT
public:
    explicit DeadReckoningPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private:
    Teseo::TeseoDriver *m_driver;
    QTextEdit *m_logEdit;
};

#endif
