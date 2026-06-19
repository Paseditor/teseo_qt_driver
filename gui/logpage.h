// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef LOGPAGE_H
#define LOGPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>

#include "teseo_driver.h"

class LogPage : public QWidget
{
    Q_OBJECT
public:
    explicit LogPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private:
    Teseo::TeseoDriver *m_driver;
    QTextEdit *m_logEdit;
    QCheckBox *m_autoScroll;
    QCheckBox *m_showNmea;
    bool m_paused = false;
};

#endif
