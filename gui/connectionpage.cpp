// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "connectionpage.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSerialPortInfo>
#include <QSpacerItem>

ConnectionPage::ConnectionPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 30, 40, 30);
    mainLayout->setSpacing(20);

    // Header
    auto *headerLbl = new QLabel("Serial Port Connection");
    headerLbl->setStyleSheet("font-size: 18px; font-weight: 700; color: #e2e8f0; margin-bottom: 8px;");
    mainLayout->addWidget(headerLbl);

    auto *subLbl = new QLabel("Select a COM port and baud rate to connect to the Teseo-VIC3 module.");
    subLbl->setStyleSheet("color: #94a3b8; font-size: 12px; margin-bottom: 16px;");
    subLbl->setWordWrap(true);
    mainLayout->addWidget(subLbl);

    // Connection card
    auto *connGroup = new QGroupBox("Connection Settings");
    auto *form = new QFormLayout;
    form->setSpacing(12);
    form->setLabelAlignment(Qt::AlignRight);

    m_portCombo = new QComboBox;
    m_portCombo->setMinimumWidth(300);
    m_baudCombo = new QComboBox;
    m_baudCombo->addItems({"9600","19200","38400","57600","115200","230400","460800","921600"});
    m_baudCombo->setCurrentText("115200");

    form->addRow("Port:", m_portCombo);
    form->addRow("Baud rate:", m_baudCombo);

    m_refreshBtn = new QPushButton("  Refresh Ports");
    m_refreshBtn->setMaximumWidth(160);
    form->addRow("", m_refreshBtn);

    connGroup->setLayout(form);
    mainLayout->addWidget(connGroup);

    // Connect button
    m_connectBtn = new QPushButton("  Connect");
    m_connectBtn->setMinimumHeight(44);
    m_connectBtn->setStyleSheet(
        "QPushButton { background-color: #0ea5e9; color: white; font-size: 14px; font-weight: 600; "
        "border: none; border-radius: 8px; }"
        "QPushButton:hover { background-color: #38bdf8; }"
        "QPushButton:pressed { background-color: #0284c7; }");
    mainLayout->addWidget(m_connectBtn);

    // Status
    m_statusLbl = new QLabel("Disconnected");
    m_statusLbl->setStyleSheet("font-size: 14px; font-weight: 600; color: #f87171; padding: 8px 0;");
    m_statusLbl->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_statusLbl);

    mainLayout->addStretch();

    connect(m_refreshBtn, &QPushButton::clicked, this, &ConnectionPage::onRefreshPorts);
    connect(m_connectBtn, &QPushButton::clicked, this, &ConnectionPage::onConnectClicked);
    connect(m_driver, &Teseo::TeseoDriver::connected, this, &ConnectionPage::onConnected);
    connect(m_driver, &Teseo::TeseoDriver::disconnected, this, &ConnectionPage::onDisconnected);

    onRefreshPorts();
}

void ConnectionPage::onRefreshPorts()
{
    m_portCombo->clear();
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        m_portCombo->addItem(info.portName() + " - " + info.description(), info.portName());
}

void ConnectionPage::onConnectClicked()
{
    if (m_driver->isConnected()) {
        m_driver->disconnectDevice();
    } else {
        QString port = m_portCombo->currentData().toString();
        qint32 baud = m_baudCombo->currentText().toInt();
        if (!m_driver->connectDevice(port, baud))
            m_statusLbl->setText("Failed to open " + port);
    }
}

void ConnectionPage::onConnected()
{
    m_connectBtn->setText("  Disconnect");
    m_connectBtn->setStyleSheet(
        "QPushButton { background-color: #ef4444; color: white; font-size: 14px; font-weight: 600; "
        "border: none; border-radius: 8px; }"
        "QPushButton:hover { background-color: #f87171; }");
    m_statusLbl->setText("Connected");
    m_statusLbl->setStyleSheet("font-size: 14px; font-weight: 600; color: #4ade80; padding: 8px 0;");
    m_portCombo->setEnabled(false);
    m_baudCombo->setEnabled(false);
}

void ConnectionPage::onDisconnected()
{
    m_connectBtn->setText("  Connect");
    m_connectBtn->setStyleSheet(
        "QPushButton { background-color: #0ea5e9; color: white; font-size: 14px; font-weight: 600; "
        "border: none; border-radius: 8px; }"
        "QPushButton:hover { background-color: #38bdf8; }"
        "QPushButton:pressed { background-color: #0284c7; }");
    m_statusLbl->setText("Disconnected");
    m_statusLbl->setStyleSheet("font-size: 14px; font-weight: 600; color: #f87171; padding: 8px 0;");
    m_portCombo->setEnabled(true);
    m_baudCombo->setEnabled(true);
}
