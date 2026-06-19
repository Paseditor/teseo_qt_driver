// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "mainwindow.h"
#include "connectionpage.h"
#include "infopage.h"
#include "commandpage.h"
#include "configpage.h"
#include "agnsspage.h"
#include "deadreckoningpage.h"
#include "logpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_driver(new Teseo::TeseoDriver(this))
    , m_tabs(new QTabWidget(this))
    , m_statusLabel(new QLabel(this))
    , m_versionLabel(new QLabel(this))
{
    setWindowTitle("ArneeCode  |  Teseo-VIC3 GNSS Test Tool");
    resize(1100, 720);
    setMinimumSize(960, 640);

    m_connPage = new ConnectionPage(m_driver, this);
    m_infoPage = new InfoPage(m_driver, this);
    m_cmdPage = new CommandPage(m_driver, this);
    m_cfgPage = new ConfigPage(m_driver, this);
    m_agnssPage = new AGNSSPage(m_driver, this);
    m_drPage = new DeadReckoningPage(m_driver, this);
    m_logPage = new LogPage(m_driver, this);

    m_tabs->addTab(m_connPage, QString::fromUtf8("  \xe2\x9a\x99  Connection  "));
    m_tabs->addTab(m_infoPage, QString::fromUtf8("  \xf0\x9f\x93\xa1  GNSS Info  "));
    m_tabs->addTab(m_cmdPage, QString::fromUtf8("  \xe2\x9a\xa1  Commands  "));
    m_tabs->addTab(m_cfgPage, QString::fromUtf8("  \xf0\x9f\x94\xa7  Configuration  "));
    m_tabs->addTab(m_agnssPage, QString::fromUtf8("  \xf0\x9f\x9b\xb0  AGNSS  "));
    m_tabs->addTab(m_drPage, QString::fromUtf8("  \xf0\x9f\x9a\x97  Dead Reckoning  "));
    m_tabs->addTab(m_logPage, QString::fromUtf8("  \xf0\x9f\x93\x8b  Log  "));

    setCentralWidget(m_tabs);

    m_statusLabel->setText(QString::fromUtf8("\xe2\x97\x8b  Disconnected"));
    m_statusLabel->setStyleSheet("color: #ef4444; font-weight: 600; padding: 0 10px; font-size: 12px;");

    m_versionLabel->setText("ArneeCode  v1.0.0  |  2026");
    m_versionLabel->setStyleSheet("color: #3d4466; padding: 0 10px; font-size: 11px; letter-spacing: 0.3px;");

    statusBar()->addPermanentWidget(m_statusLabel);
    statusBar()->addPermanentWidget(m_versionLabel);

    connect(m_driver, &Teseo::TeseoDriver::connected,
            this, &MainWindow::onConnected);
    connect(m_driver, &Teseo::TeseoDriver::disconnected,
            this, &MainWindow::onDisconnected);
    connect(m_driver, &Teseo::TeseoDriver::errorOccurred,
            this, &MainWindow::onError);
}

MainWindow::~MainWindow() {}

void MainWindow::onConnected()
{
    m_statusLabel->setText(QString::fromUtf8("\xe2\x9f\xb5  Connected"));
    m_statusLabel->setStyleSheet("color: #22c55e; font-weight: 600; padding: 0 10px; font-size: 12px;");
}

void MainWindow::onDisconnected()
{
    m_statusLabel->setText(QString::fromUtf8("\xe2\x97\x8b  Disconnected"));
    m_statusLabel->setStyleSheet("color: #ef4444; font-weight: 600; padding: 0 10px; font-size: 12px;");
}

void MainWindow::onError(const QString &error)
{
    m_statusLabel->setText(QString::fromUtf8("\xe2\x9a\xa0  Error: ") + error);
    m_statusLabel->setStyleSheet("color: #f59e0b; font-weight: 600; padding: 0 10px; font-size: 12px;");
}
