// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#ifndef CONFIGPAGE_H
#define CONFIGPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>

#include "teseo_driver.h"

class ConfigPage : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private:
    Teseo::TeseoDriver *m_driver;
    QTextEdit *m_resultEdit;
};

#endif
