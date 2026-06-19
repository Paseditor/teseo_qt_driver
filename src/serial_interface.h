// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>

namespace Teseo {

class SerialInterface : public QObject
{
    Q_OBJECT

public:
    explicit SerialInterface(QObject *parent = nullptr);
    ~SerialInterface();

    bool open(const QString &portName, qint32 baudRate = 115200);
    void close();
    bool isOpen() const;

    bool sendCommand(const QByteArray &command);
    bool sendRaw(const QByteArray &data);

    QString portName() const;
    qint32 baudRate() const;

    void setDtr(bool state);
    void setRts(bool state);

signals:
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QString &errorString);
    void connected();
    void disconnected();

private slots:
    void onReadyRead();
    void onError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_port;
};

} // namespace Teseo

#endif // SERIAL_INTERFACE_H
