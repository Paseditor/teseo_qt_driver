// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include <QApplication>
#include <QTimer>
#include "mainwindow.h"
#include "splashscreen.h"
#include "style.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Teseo-VIC3 Test Tool");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("ArneeCode");

    app.setStyleSheet(Style::global());

    SplashScreen splash;
    splash.show();
    app.processEvents();

    splash.showProgress("Loading modules...");
    QThread::msleep(400);

    splash.showProgress("Initializing NMEA parser...");
    QThread::msleep(300);

    splash.showProgress("Preparing interface...");
    QThread::msleep(300);

    MainWindow w;
    splash.finish(&w);
    w.show();

    return app.exec();
}
