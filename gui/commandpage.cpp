// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "commandpage.h"
#include <QGridLayout>
#include <QLabel>
#include <QDateTime>

CommandPage::CommandPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    createStartGroup(mainLayout);
    createControlGroup(mainLayout);
    createMiscGroup(mainLayout);
    createCustomGroup(mainLayout);

    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setMaximumHeight(100);
    m_logEdit->setPlaceholderText("Command log...");
    mainLayout->addWidget(m_logEdit);

    connect(m_driver, &Teseo::TeseoDriver::responseReceived, this, [this](const QByteArray &r) {
        log("TX: " + r);
    });
    connect(m_driver, &Teseo::TeseoDriver::nmeaSentenceReceived, this, [this](const QByteArray &s) {
        if (s.startsWith("$PSTM"))
            log("RX: " + s);
    });
}

void CommandPage::log(const QString &msg)
{
    m_logEdit->append(QDateTime::currentDateTime().toString("HH:mm:ss.zzz") + " " + msg);
}

void CommandPage::createStartGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Start / Reset");
    auto *lay = new QHBoxLayout;
    lay->setSpacing(8);

    auto *hotBtn = new QPushButton("Hot Start");
    auto *warmBtn = new QPushButton("Warm Start");
    auto *coldBtn = new QPushButton("Cold Start");
    auto *resetBtn = new QPushButton("System Reset");
    auto *gnssResetBtn = new QPushButton("GNSS Reset");
    auto *suspendBtn = new QPushButton("Suspend");
    auto *restartBtn = new QPushButton("Restart");

    lay->addWidget(hotBtn);
    lay->addWidget(warmBtn);
    lay->addWidget(coldBtn);
    lay->addWidget(resetBtn);
    lay->addWidget(gnssResetBtn);
    lay->addWidget(suspendBtn);
    lay->addWidget(restartBtn);

    connect(hotBtn, &QPushButton::clicked, [this]() { m_driver->hotStart(); log("Hot Start"); });
    connect(warmBtn, &QPushButton::clicked, [this]() { m_driver->warmStart(); log("Warm Start"); });
    connect(coldBtn, &QPushButton::clicked, [this]() { m_driver->coldStart(); log("Cold Start"); });
    connect(resetBtn, &QPushButton::clicked, [this]() { m_driver->systemReset(); log("System Reset"); });
    connect(gnssResetBtn, &QPushButton::clicked, [this]() { m_driver->gnssReset(); log("GNSS Reset"); });
    connect(suspendBtn, &QPushButton::clicked, [this]() { m_driver->gnssSuspend(); log("Suspend"); });
    connect(restartBtn, &QPushButton::clicked, [this]() { m_driver->gnssRestart(); log("Restart"); });

    grp->setLayout(lay);
    parent->addWidget(grp);
}

void CommandPage::createControlGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Constellation / SBAS / PPS");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    int r = 0;

    grid->addWidget(new QLabel("Constellation mask:"), r, 0);
    auto *constSpin = new QSpinBox;
    constSpin->setRange(0, 255);
    constSpin->setValue(3);
    constSpin->setToolTip("1=GPS, 2=GLONASS, 4=QZSS, 8=Galileo, 128=BeiDou");
    grid->addWidget(constSpin, r, 1);
    auto *constBtn = new QPushButton("Set");
    grid->addWidget(constBtn, r, 2);
    connect(constBtn, &QPushButton::clicked, [this, constSpin]() {
        m_driver->setConstellationMask(constSpin->value());
        log("ConstMask: " + QString::number(constSpin->value()));
    });

    auto *sbasAuto = new QPushButton("SBAS Auto");
    auto *sbasOff = new QPushButton("SBAS OFF");
    grid->addWidget(sbasAuto, r, 3);
    grid->addWidget(sbasOff, r, 4);
    connect(sbasAuto, &QPushButton::clicked, [this]() { m_driver->enableSbasAuto(); log("SBAS Auto"); });
    connect(sbasOff, &QPushButton::clicked, [this]() { m_driver->setSbasService(7); log("SBAS OFF"); });
    r++;

    auto *nmeaOn = new QPushButton("NMEA ON");
    auto *nmeaOff = new QPushButton("NMEA OFF");
    auto *ppsOn = new QPushButton("PPS ON");
    auto *ppsOff = new QPushButton("PPS OFF");
    grid->addWidget(nmeaOn, r, 0);
    grid->addWidget(nmeaOff, r, 1);
    grid->addWidget(ppsOn, r, 2);
    grid->addWidget(ppsOff, r, 3);
    connect(nmeaOn, &QPushButton::clicked, [this]() { m_driver->setNmeaOutput(true); log("NMEA ON"); });
    connect(nmeaOff, &QPushButton::clicked, [this]() { m_driver->setNmeaOutput(false); log("NMEA OFF"); });
    connect(ppsOn, &QPushButton::clicked, [this]() { m_driver->ppsSetOnOff(true); log("PPS ON"); });
    connect(ppsOff, &QPushButton::clicked, [this]() { m_driver->ppsSetOnOff(false); log("PPS OFF"); });
    r++;

    auto *stbyOn = new QPushButton("Standby ON");
    auto *stbyOff = new QPushButton("Standby OFF");
    auto *forceStby = new QPushButton("Force Standby 10s");
    grid->addWidget(stbyOn, r, 0);
    grid->addWidget(stbyOff, r, 1);
    grid->addWidget(forceStby, r, 2);
    connect(stbyOn, &QPushButton::clicked, [this]() { m_driver->setStandbyEnable(true); log("Standby ON"); });
    connect(stbyOff, &QPushButton::clicked, [this]() { m_driver->setStandbyEnable(false); log("Standby OFF"); });
    connect(forceStby, &QPushButton::clicked, [this]() { m_driver->forceStandby(10); log("Force Standby"); });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createMiscGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Algorithms / RF Test / IMU");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    int r = 0;

    auto *fdeOn = new QPushButton("FDE ON");
    auto *fdeOff = new QPushButton("FDE OFF");
    auto *rfOn = new QPushButton("RF Test ON");
    auto *rfOff = new QPushButton("RF Test OFF");
    auto *imuBtn = new QPushButton("IMU Self Test");
    grid->addWidget(fdeOn, r, 0);
    grid->addWidget(fdeOff, r, 1);
    grid->addWidget(rfOn, r, 2);
    grid->addWidget(rfOff, r, 3);
    grid->addWidget(imuBtn, r, 4);

    connect(fdeOn, &QPushButton::clicked, [this]() { m_driver->setAlgorithmStatus(1, true); log("FDE ON"); });
    connect(fdeOff, &QPushButton::clicked, [this]() { m_driver->setAlgorithmStatus(1, false); log("FDE OFF"); });
    connect(rfOn, &QPushButton::clicked, [this]() { m_driver->rfTestOn(24); log("RF Test ON sat=24"); });
    connect(rfOff, &QPushButton::clicked, [this]() { m_driver->rfTestOff(); log("RF Test OFF"); });
    connect(imuBtn, &QPushButton::clicked, [this]() { m_driver->imuSelfTest(); log("IMU Self Test"); });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createCustomGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Custom Command");
    auto *lay = new QHBoxLayout;
    lay->setSpacing(8);

    auto *cmdEdit = new QLineEdit;
    cmdEdit->setPlaceholderText("$PSTM... (without checksum)");
    auto *sendBtn = new QPushButton("Send");

    lay->addWidget(cmdEdit, 1);
    lay->addWidget(sendBtn);
    grp->setLayout(lay);
    parent->addWidget(grp);

    connect(sendBtn, &QPushButton::clicked, [this, cmdEdit]() {
        QByteArray cmd = cmdEdit->text().toLatin1();
        if (!cmd.isEmpty()) {
            m_driver->sendCommand(cmd);
            log("Custom: " + cmd);
        }
    });
    connect(cmdEdit, &QLineEdit::returnPressed, [sendBtn]() { sendBtn->click(); });
}
