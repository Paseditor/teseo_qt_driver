// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "serial_interface.h"

namespace Teseo {

SerialInterface::SerialInterface(QObject *parent)
    : QObject(parent)
    , m_port(new QSerialPort(this))
{
    connect(m_port, &QSerialPort::readyRead, this, &SerialInterface::onReadyRead);
    connect(m_port, &QSerialPort::errorOccurred, this, &SerialInterface::onError);
}

SerialInterface::~SerialInterface()
{
    close();
}

bool SerialInterface::open(const QString &portName, qint32 baudRate)
{
    if (m_port->isOpen())
        m_port->close();

    m_port->setPortName(portName);
    m_port->setBaudRate(baudRate);
    m_port->setDataBits(QSerialPort::Data8);
    m_port->setParity(QSerialPort::NoParity);
    m_port->setStopBits(QSerialPort::OneStop);
    m_port->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_port->open(QIODevice::ReadWrite)) {
        emit errorOccurred(m_port->errorString());
        return false;
    }

    emit connected();
    return true;
}

void SerialInterface::close()
{
    if (m_port->isOpen()) {
        m_port->close();
        emit disconnected();
    }
}

bool SerialInterface::isOpen() const
{
    return m_port->isOpen();
}

bool SerialInterface::sendCommand(const QByteArray &command)
{
    QByteArray frame = command;
    if (!frame.startsWith('$'))
        frame.prepend('$');

    if (!frame.contains('*')) {
        QByteArray payload = frame.mid(1);
        QByteArray checksum = QByteArray::number(
            [&]() -> quint8 {
                quint8 cs = 0;
                for (char c : payload) cs ^= static_cast<quint8>(c);
                return cs;
            }(), 16).rightJustified(2, '0').toUpper();
        frame.append('*');
        frame.append(checksum);
    }

    frame.append("\r\n");
    return sendRaw(frame);
}

bool SerialInterface::sendRaw(const QByteArray &data)
{
    if (!m_port->isOpen()) {
        emit errorOccurred(tr("Port is not open"));
        return false;
    }

    qint64 written = m_port->write(data);
    if (written != data.size()) {
        emit errorOccurred(m_port->errorString());
        return false;
    }

    m_port->flush();
    return true;
}

QString SerialInterface::portName() const
{
    return m_port->portName();
}

qint32 SerialInterface::baudRate() const
{
    return m_port->baudRate();
}

void SerialInterface::setDtr(bool state)
{
    m_port->setDataTerminalReady(state);
}

void SerialInterface::setRts(bool state)
{
    m_port->setRequestToSend(state);
}

void SerialInterface::onReadyRead()
{
    QByteArray data = m_port->readAll();
    if (!data.isEmpty())
        emit dataReceived(data);
}

void SerialInterface::onError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
        return;
    emit errorOccurred(m_port->errorString());
}

} // namespace Teseo
