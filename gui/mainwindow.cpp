// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

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
    setWindowTitle("ArneeCode | Teseo-VIC3 Test Tool");
    resize(1024, 700);
    setMinimumSize(900, 600);

    m_connPage = new ConnectionPage(m_driver, this);
    m_infoPage = new InfoPage(m_driver, this);
    m_cmdPage = new CommandPage(m_driver, this);
    m_cfgPage = new ConfigPage(m_driver, this);
    m_agnssPage = new AGNSSPage(m_driver, this);
    m_drPage = new DeadReckoningPage(m_driver, this);
    m_logPage = new LogPage(m_driver, this);

    m_tabs->addTab(m_connPage, "  Connection  ");
    m_tabs->addTab(m_infoPage, "  GNSS Info  ");
    m_tabs->addTab(m_cmdPage, "  Commands  ");
    m_tabs->addTab(m_cfgPage, "  Configuration  ");
    m_tabs->addTab(m_agnssPage, "  AGNSS  ");
    m_tabs->addTab(m_drPage, "  Dead Reckoning  ");
    m_tabs->addTab(m_logPage, "  Log  ");

    setCentralWidget(m_tabs);

    m_statusLabel->setText("Disconnected");
    m_statusLabel->setStyleSheet("color: #f87171; font-weight: 600; padding: 0 8px;");

    m_versionLabel->setText("ArneeCode v1.0.0");
    m_versionLabel->setStyleSheet("color: #64748b; padding: 0 8px;");

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
    m_statusLabel->setText("Connected");
    m_statusLabel->setStyleSheet("color: #4ade80; font-weight: 600; padding: 0 8px;");
}

void MainWindow::onDisconnected()
{
    m_statusLabel->setText("Disconnected");
    m_statusLabel->setStyleSheet("color: #f87171; font-weight: 600; padding: 0 8px;");
}

void MainWindow::onError(const QString &error)
{
    m_statusLabel->setText("Error: " + error);
    m_statusLabel->setStyleSheet("color: #fbbf24; font-weight: 600; padding: 0 8px;");
}
