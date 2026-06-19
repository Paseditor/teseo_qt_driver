// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>

#include "teseo_driver.h"

class ConnectionPage : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectionPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private slots:
    void onConnectClicked();
    void onRefreshPorts();
    void onConnected();
    void onDisconnected();

private:
    Teseo::TeseoDriver *m_driver;
    QComboBox *m_portCombo;
    QComboBox *m_baudCombo;
    QPushButton *m_connectBtn;
    QPushButton *m_refreshBtn;
    QLabel *m_statusLbl;
};

#endif
