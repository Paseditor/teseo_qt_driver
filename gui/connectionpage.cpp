// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "connectionpage.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSerialPortInfo>
#include <QSpacerItem>
#include <QGraphicsDropShadowEffect>

ConnectionPage::ConnectionPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(60, 40, 60, 40);
    mainLayout->setSpacing(24);

    // Header with icon
    auto *headerLayout = new QHBoxLayout;
    headerLayout->setSpacing(16);

    auto *iconLbl = new QLabel(QString::fromUtf8("\xe2\x9a\xa1")); // lightning
    iconLbl->setStyleSheet("font-size: 32px; color: #00d4ff;");
    headerLayout->addWidget(iconLbl);

    auto *headerText = new QVBoxLayout;
    headerText->setSpacing(4);
    auto *headerLbl = new QLabel("Serial Port Connection");
    headerLbl->setStyleSheet("font-size: 22px; font-weight: 700; color: #e0e4f0; letter-spacing: 0.5px;");
    headerText->addWidget(headerLbl);

    auto *subLbl = new QLabel("Connect to Teseo-VIC3 GNSS module via UART");
    subLbl->setStyleSheet("color: #6b7394; font-size: 13px;");
    headerText->addWidget(subLbl);
    headerLayout->addLayout(headerText);
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // Connection card
    auto *connGroup = new QGroupBox(QString::fromUtf8("  \xf0\x9f\x94\x8c  Connection Settings"));
    auto *form = new QFormLayout;
    form->setSpacing(16);
    form->setLabelAlignment(Qt::AlignRight);
    form->setContentsMargins(20, 24, 20, 20);

    m_portCombo = new QComboBox;
    m_portCombo->setMinimumWidth(350);
    m_portCombo->setMinimumHeight(36);
    m_baudCombo = new QComboBox;
    m_baudCombo->addItems({"9600","19200","38400","57600","115200","230400","460800","921600"});
    m_baudCombo->setCurrentText("115200");
    m_baudCombo->setMinimumHeight(36);

    auto *portLbl = new QLabel("Port:");
    portLbl->setStyleSheet("color: #8b93b8; font-weight: 500;");
    auto *baudLbl = new QLabel("Baud Rate:");
    baudLbl->setStyleSheet("color: #8b93b8; font-weight: 500;");

    form->addRow(portLbl, m_portCombo);
    form->addRow(baudLbl, m_baudCombo);

    m_refreshBtn = new QPushButton(QString::fromUtf8("  \xe2\x9f\xb3  Refresh Ports"));
    m_refreshBtn->setMaximumWidth(180);
    m_refreshBtn->setMinimumHeight(34);
    form->addRow("", m_refreshBtn);

    connGroup->setLayout(form);
    mainLayout->addWidget(connGroup);

    // Connect button with shadow
    m_connectBtn = new QPushButton(QString::fromUtf8("  \xe2\x9a\x99  Connect"));
    m_connectBtn->setMinimumHeight(50);
    m_connectBtn->setStyleSheet(
        "QPushButton {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00a8cc, stop:1 #00d4ff);"
        "  color: #0a0e1a; font-size: 15px; font-weight: 700;"
        "  border: none; border-radius: 10px;"
        "  letter-spacing: 0.5px;"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00d4ff, stop:1 #33ddff);"
        "}"
        "QPushButton:pressed {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #0088aa, stop:1 #00a8cc);"
        "}");

    auto *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(30);
    shadow->setColor(QColor(0, 212, 255, 80));
    shadow->setOffset(0, 4);
    m_connectBtn->setGraphicsEffect(shadow);

    mainLayout->addWidget(m_connectBtn);

    // Status indicator
    auto *statusLayout = new QHBoxLayout;
    statusLayout->setAlignment(Qt::AlignCenter);
    statusLayout->setSpacing(10);

    auto *statusDot = new QLabel(QString::fromUtf8("\xe2\x97\x8b")); // circle
    statusDot->setObjectName("statusDot");
    statusDot->setStyleSheet("font-size: 16px; color: #ef4444;");

    m_statusLbl = new QLabel("Disconnected");
    m_statusLbl->setStyleSheet("font-size: 15px; font-weight: 600; color: #ef4444; letter-spacing: 0.3px;");

    statusLayout->addWidget(statusDot);
    statusLayout->addWidget(m_statusLbl);
    mainLayout->addLayout(statusLayout);

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
        m_portCombo->addItem(info.portName() + "  \xe2\x94\x82  " + info.description(), info.portName());
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
    m_connectBtn->setText(QString::fromUtf8("  \xe2\x9a\x99  Disconnect"));
    m_connectBtn->setStyleSheet(
        "QPushButton {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #dc2626, stop:1 #ef4444);"
        "  color: white; font-size: 15px; font-weight: 700;"
        "  border: none; border-radius: 10px;"
        "  letter-spacing: 0.5px;"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ef4444, stop:1 #f87171);"
        "}");

    // Update status dot
    auto *dot = findChild<QLabel*>("statusDot");
    if (dot) dot->setStyleSheet("font-size: 16px; color: #22c55e;");

    m_statusLbl->setText("Connected");
    m_statusLbl->setStyleSheet("font-size: 15px; font-weight: 600; color: #22c55e; letter-spacing: 0.3px;");
    m_portCombo->setEnabled(false);
    m_baudCombo->setEnabled(false);
}

void ConnectionPage::onDisconnected()
{
    m_connectBtn->setText(QString::fromUtf8("  \xe2\x9a\x99  Connect"));
    m_connectBtn->setStyleSheet(
        "QPushButton {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00a8cc, stop:1 #00d4ff);"
        "  color: #0a0e1a; font-size: 15px; font-weight: 700;"
        "  border: none; border-radius: 10px;"
        "  letter-spacing: 0.5px;"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00d4ff, stop:1 #33ddff);"
        "}");

    auto *dot = findChild<QLabel*>("statusDot");
    if (dot) dot->setStyleSheet("font-size: 16px; color: #ef4444;");

    m_statusLbl->setText("Disconnected");
    m_statusLbl->setStyleSheet("font-size: 15px; font-weight: 600; color: #ef4444; letter-spacing: 0.3px;");
    m_portCombo->setEnabled(true);
    m_baudCombo->setEnabled(true);
}
