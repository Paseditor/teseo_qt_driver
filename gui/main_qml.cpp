// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "teseo_driver.h"
#include "teseo_bridge.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Teseo-VIC3 Test Tool");
    app.setApplicationVersion("2.0.0");
    app.setOrganizationName("ArneeCode");

    Teseo::TeseoDriver driver;
    TeseoBridge bridge(&driver);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("bridge", &bridge);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
