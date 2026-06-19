// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#ifndef AGNSSPAGE_H
#define AGNSSPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <QComboBox>
#include <QLabel>

#include "teseo_driver.h"

class AGNSSPage : public QWidget
{
    Q_OBJECT
public:
    explicit AGNSSPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private:
    Teseo::TeseoDriver *m_driver;
    QTextEdit *m_logEdit;
};

#endif
