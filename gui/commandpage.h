// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef COMMANDPAGE_H
#define COMMANDPAGE_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QVBoxLayout>

#include "teseo_driver.h"

class CommandPage : public QWidget
{
    Q_OBJECT
public:
    explicit CommandPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private slots:
    void log(const QString &msg);

private:
    void createStartGroup(QVBoxLayout *parent);
    void createControlGroup(QVBoxLayout *parent);
    void createMiscGroup(QVBoxLayout *parent);
    void createCustomGroup(QVBoxLayout *parent);

    Teseo::TeseoDriver *m_driver;
    QTextEdit *m_logEdit;
};

#endif
