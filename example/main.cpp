#include <QCoreApplication>
#include <QSerialPortInfo>
#include <QDebug>

#include "teseo_driver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Teseo::TeseoDriver driver;

    // List available serial ports
    qDebug() << "Available serial ports:";
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        qDebug() << "  " << info.portName() << "-" << info.description();
    }

    // Connect to first available port (or specify port name)
    QString portName;
    if (argc > 1)
        portName = argv[1];
    else if (!QSerialPortInfo::availablePorts().isEmpty())
        portName = QSerialPortInfo::availablePorts().first().portName();

    if (portName.isEmpty()) {
        qDebug() << "No serial port found. Usage: teseo_example <port_name>";
        return 1;
    }

    qDebug() << "Connecting to" << portName << "...";

    // Connect signals
    QObject::connect(&driver, &Teseo::TeseoDriver::connected, []() {
        qDebug() << "Connected!";
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::disconnected, []() {
        qDebug() << "Disconnected.";
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::positionUpdated,
                     [](const Teseo::Position &pos) {
        if (pos.valid) {
            qDebug() << "Position:"
                     << "Lat:" << pos.latitudeDecimal()
                     << "Lon:" << pos.longitudeDecimal()
                     << "Alt:" << pos.altitude << "m";
        }
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::velocityUpdated,
                     [](const Teseo::Velocity &vel) {
        qDebug() << "Speed:" << vel.speedKmh << "km/h"
                 << "Course:" << vel.courseTrue << "deg";
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::satellitesUpdated,
                     [](const QVector<Teseo::Satellite> &sats) {
        int used = 0;
        for (const auto &s : sats) {
            if (s.usedInFix) used++;
        }
        qDebug() << "Satellites in view:" << sats.size()
                 << "Used in fix:" << used;
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::fixUpdated,
                     [](const Teseo::GnssData &data) {
        qDebug() << "Fix quality:" << static_cast<int>(data.fixQuality)
                 << "Sats used:" << data.satellitesUsed
                 << "HDOP:" << data.dop.hdop;
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::nmeaSentenceReceived,
                     [](const QByteArray &sentence) {
        qDebug().noquote() << "NMEA:" << sentence;
    });

    QObject::connect(&driver, &Teseo::TeseoDriver::errorOccurred,
                     [](const QString &error) {
        qWarning() << "Error:" << error;
    });

    // Open connection
    if (!driver.connectDevice(portName, 115200)) {
        qCritical() << "Failed to connect to" << portName;
        return 1;
    }

    // Example commands (uncomment as needed):
    // driver.hotStart();
    // driver.warmStart();
    // driver.coldStart();
    // driver.setConstellationMask(1);  // GPS only
    // driver.setConstellationMask(3);  // GPS + GLONASS
    // driver.enableSbasAuto();  // Auto SBAS

    return app.exec();
}
