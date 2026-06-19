// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QStatusBar>
#include <QLabel>

#include "teseo_driver.h"

class ConnectionPage;
class InfoPage;
class CommandPage;
class ConfigPage;
class AGNSSPage;
class DeadReckoningPage;
class LogPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onConnected();
    void onDisconnected();
    void onError(const QString &error);

private:
    Teseo::TeseoDriver *m_driver;
    QTabWidget *m_tabs;

    ConnectionPage *m_connPage;
    InfoPage *m_infoPage;
    CommandPage *m_cmdPage;
    ConfigPage *m_cfgPage;
    AGNSSPage *m_agnssPage;
    DeadReckoningPage *m_drPage;
    LogPage *m_logPage;

    QLabel *m_statusLabel;
    QLabel *m_versionLabel;
};

#endif // MAINWINDOW_H
