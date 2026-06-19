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
    createStatusGroup(mainLayout);
    createInvalidationGroup(mainLayout);
    createAdvancedGroup(mainLayout);
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
    lay->setContentsMargins(12, 16, 12, 12);

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
    grid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    grid->addWidget(new QLabel("Mask:"), r, 0);
    auto *constSpin = new QSpinBox;
    constSpin->setRange(0, 255);
    constSpin->setValue(3);
    constSpin->setMinimumWidth(70);
    constSpin->setToolTip("1=GPS, 2=GLONASS, 4=QZSS, 8=Galileo, 128=BeiDou");
    grid->addWidget(constSpin, r, 1);
    auto *constBtn = new QPushButton("Set");
    grid->addWidget(constBtn, r, 2);

    auto *sbasAuto = new QPushButton("SBAS Auto");
    auto *sbasOff = new QPushButton("SBAS OFF");
    auto *sbasToggle = new QPushButton("SBAS Toggle");
    grid->addWidget(sbasAuto, r, 3);
    grid->addWidget(sbasOff, r, 4);
    grid->addWidget(sbasToggle, r, 5);

    auto *nmeaOn = new QPushButton("NMEA ON");
    auto *nmeaOff = new QPushButton("NMEA OFF");
    grid->addWidget(nmeaOn, r, 6);
    grid->addWidget(nmeaOff, r, 7);
    r++;

    auto *ppsOn = new QPushButton("PPS ON");
    auto *ppsOff = new QPushButton("PPS OFF");
    auto *stbyOn = new QPushButton("Standby ON");
    auto *stbyOff = new QPushButton("Standby OFF");
    auto *forceStby = new QPushButton("Force Standby 10s");
    auto *getStby = new QPushButton("Get Standby");
    grid->addWidget(ppsOn, r, 0);
    grid->addWidget(ppsOff, r, 1);
    grid->addWidget(stbyOn, r, 2);
    grid->addWidget(stbyOff, r, 3);
    grid->addWidget(forceStby, r, 4, 1, 2);
    grid->addWidget(getStby, r, 6, 1, 2);
    r++;

    // SBAS satellite
    grid->addWidget(new QLabel("SBAS PRN:"), r, 0);
    auto *sbasPrn = new QSpinBox;
    sbasPrn->setRange(120, 140);
    sbasPrn->setValue(120);
    sbasPrn->setMinimumWidth(70);
    grid->addWidget(sbasPrn, r, 1);
    auto *sbasSatBtn = new QPushButton("Set SBAS Sat");
    grid->addWidget(sbasSatBtn, r, 2);

    // Column stretch
    for (int i = 0; i < 8; i++)
        grid->setColumnStretch(i, 1);

    connect(constBtn, &QPushButton::clicked, [this, constSpin]() {
        m_driver->setConstellationMask(constSpin->value());
        log("ConstMask: " + QString::number(constSpin->value()));
    });
    connect(sbasAuto, &QPushButton::clicked, [this]() { m_driver->enableSbasAuto(); log("SBAS Auto"); });
    connect(sbasOff, &QPushButton::clicked, [this]() { m_driver->setSbasService(7); log("SBAS OFF"); });
    connect(sbasToggle, &QPushButton::clicked, [this]() { m_driver->toggleSbas(); log("SBAS Toggle"); });
    connect(nmeaOn, &QPushButton::clicked, [this]() { m_driver->setNmeaOutput(true); log("NMEA ON"); });
    connect(nmeaOff, &QPushButton::clicked, [this]() { m_driver->setNmeaOutput(false); log("NMEA OFF"); });
    connect(ppsOn, &QPushButton::clicked, [this]() { m_driver->ppsSetOnOff(true); log("PPS ON"); });
    connect(ppsOff, &QPushButton::clicked, [this]() { m_driver->ppsSetOnOff(false); log("PPS OFF"); });
    connect(stbyOn, &QPushButton::clicked, [this]() { m_driver->setStandbyEnable(true); log("Standby ON"); });
    connect(stbyOff, &QPushButton::clicked, [this]() { m_driver->setStandbyEnable(false); log("Standby OFF"); });
    connect(forceStby, &QPushButton::clicked, [this]() { m_driver->forceStandby(10); log("Force Standby"); });
    connect(getStby, &QPushButton::clicked, [this]() { m_driver->getStandbyStatus(); log("Get Standby Status"); });
    connect(sbasSatBtn, &QPushButton::clicked, [this, sbasPrn]() {
        m_driver->setSbasSatellite(sbasPrn->value());
        log("SBAS Sat PRN=" + QString::number(sbasPrn->value()));
    });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createMiscGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Algorithms / RF Test / IMU");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    grid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    auto *fdeOn = new QPushButton("FDE ON");
    auto *fdeOff = new QPushButton("FDE OFF");
    auto *fdeGet = new QPushButton("Get FDE");
    auto *rfOn = new QPushButton("RF Test ON");
    auto *rfOff = new QPushButton("RF Test OFF");
    auto *imuBtn = new QPushButton("IMU Self Test");
    grid->addWidget(fdeOn, r, 0);
    grid->addWidget(fdeOff, r, 1);
    grid->addWidget(fdeGet, r, 2);
    grid->addWidget(rfOn, r, 3);
    grid->addWidget(rfOff, r, 4);
    grid->addWidget(imuBtn, r, 5);

    for (int i = 0; i < 6; i++)
        grid->setColumnStretch(i, 1);

    connect(fdeOn, &QPushButton::clicked, [this]() { m_driver->setAlgorithmStatus(1, true); log("FDE ON"); });
    connect(fdeOff, &QPushButton::clicked, [this]() { m_driver->setAlgorithmStatus(1, false); log("FDE OFF"); });
    connect(fdeGet, &QPushButton::clicked, [this]() { m_driver->getAlgorithmStatus(1); log("Get FDE"); });
    connect(rfOn, &QPushButton::clicked, [this]() { m_driver->rfTestOn(24); log("RF Test ON sat=24"); });
    connect(rfOff, &QPushButton::clicked, [this]() { m_driver->rfTestOff(); log("RF Test OFF"); });
    connect(imuBtn, &QPushButton::clicked, [this]() { m_driver->imuSelfTest(); log("IMU Self Test"); });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createStatusGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Status Queries");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    grid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    auto *verAll = new QPushButton("Get All Versions");
    auto *verBtn = new QPushButton("Get SW Ver");
    auto *rtcBtn = new QPushButton("Get RTC Time");
    auto *uidBtn = new QPushButton("Get Unique Code");
    grid->addWidget(verAll, r, 0, 1, 2);
    grid->addWidget(verBtn, r, 2);
    grid->addWidget(rtcBtn, r, 3);
    grid->addWidget(uidBtn, r, 4);

    for (int i = 0; i < 5; i++)
        grid->setColumnStretch(i, 1);

    connect(verAll, &QPushButton::clicked, [this]() { m_driver->getAllVersions(); log("Get All Versions"); });
    connect(verBtn, &QPushButton::clicked, [this]() { m_driver->getSoftwareVersion(255); log("Get SW Version"); });
    connect(rtcBtn, &QPushButton::clicked, [this]() { m_driver->getRtcTime(); log("Get RTC Time"); });
    connect(uidBtn, &QPushButton::clicked, [this]() { m_driver->getUniqueCode(); log("Get Unique Code"); });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createInvalidationGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Invalidation / NVM / Datum / Position Hold");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    grid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    auto *invFix = new QPushButton("Invalidate GNSS Fix");
    auto *invFixR = new QPushButton("Restore Fix");
    auto *invRtc = new QPushButton("Invalidate RTC");
    auto *nvmSwap = new QPushButton("NVM Swap");
    auto *logEn = new QPushButton("Log ON");
    auto *logDis = new QPushButton("Log OFF");
    grid->addWidget(invFix, r, 0);
    grid->addWidget(invFixR, r, 1);
    grid->addWidget(invRtc, r, 2);
    grid->addWidget(nvmSwap, r, 3);
    grid->addWidget(logEn, r, 4);
    grid->addWidget(logDis, r, 5);
    r++;

    // Datum
    grid->addWidget(new QLabel("Datum:"), r, 0);
    auto *datumCombo = new QComboBox;
    datumCombo->addItems({"0-WGS84", "1-TOKYO", "2-OSGB"});
    datumCombo->setMinimumWidth(100);
    grid->addWidget(datumCombo, r, 1);
    auto *datumBtn = new QPushButton("Select Datum");
    grid->addWidget(datumBtn, r, 2);

    // Position hold
    auto *posHoldOn = new QPushButton("PosHold ON");
    auto *posHoldOff = new QPushButton("PosHold OFF");
    grid->addWidget(posHoldOn, r, 3);
    grid->addWidget(posHoldOff, r, 4);

    for (int i = 0; i < 6; i++)
        grid->setColumnStretch(i, 1);

    connect(invFix, &QPushButton::clicked, [this]() { m_driver->invalidateGnssFix(true); log("Invalidate GNSS Fix"); });
    connect(invFixR, &QPushButton::clicked, [this]() { m_driver->invalidateGnssFix(false); log("Restore GNSS Fix"); });
    connect(invRtc, &QPushButton::clicked, [this]() { m_driver->invalidateRtc(); log("Invalidate RTC"); });
    connect(nvmSwap, &QPushButton::clicked, [this]() { m_driver->nvmSwap(); log("NVM Swap"); });
    connect(logEn, &QPushButton::clicked, [this]() { m_driver->cfgLog(1); log("Log ON"); });
    connect(logDis, &QPushButton::clicked, [this]() { m_driver->cfgLog(0); log("Log OFF"); });
    connect(datumBtn, &QPushButton::clicked, [this, datumCombo]() {
        m_driver->selectDatum(datumCombo->currentIndex());
        log("Datum: " + datumCombo->currentText());
    });
    connect(posHoldOn, &QPushButton::clicked, [this]() {
        m_driver->enablePositionHold(true);
        log("Position Hold ON");
    });
    connect(posHoldOff, &QPushButton::clicked, [this]() {
        m_driver->enablePositionHold(false);
        log("Position Hold OFF");
    });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createAdvancedGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Notch Filter / Thresholds / Low Power");
    auto *grid = new QGridLayout;
    grid->setSpacing(8);
    grid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    // Notch filter
    grid->addWidget(new QLabel("Notch:"), r, 0);
    auto *notchSat = new QComboBox;
    notchSat->addItems({"0-GPS", "1-GLONASS"});
    notchSat->setMinimumWidth(90);
    grid->addWidget(notchSat, r, 1);
    auto *notchMode = new QComboBox;
    notchMode->addItems({"0-Off", "1-Always", "2-Auto"});
    notchMode->setCurrentIndex(2);
    notchMode->setMinimumWidth(90);
    grid->addWidget(notchMode, r, 2);
    auto *notchBtn = new QPushButton("Apply Notch");
    grid->addWidget(notchBtn, r, 3);

    // Thresholds
    grid->addWidget(new QLabel("Trk CN0:"), r, 4);
    auto *trkCn0 = new QSpinBox; trkCn0->setRange(0, 50);
    trkCn0->setMinimumWidth(60);
    grid->addWidget(trkCn0, r, 5);
    r++;

    grid->addWidget(new QLabel("Trk Elev:"), r, 0);
    auto *trkElev = new QDoubleSpinBox;
    trkElev->setRange(0, 90); trkElev->setDecimals(1);
    trkElev->setMinimumWidth(70);
    grid->addWidget(trkElev, r, 1);
    auto *trkBtn = new QPushButton("Set Trk Thresh");
    grid->addWidget(trkBtn, r, 2);

    grid->addWidget(new QLabel("Pos CN0:"), r, 3);
    auto *posCn0 = new QSpinBox; posCn0->setRange(0, 50);
    posCn0->setMinimumWidth(60);
    grid->addWidget(posCn0, r, 4);
    grid->addWidget(new QLabel("Pos Elev:"), r, 5);
    auto *posElev = new QDoubleSpinBox;
    posElev->setRange(0, 90); posElev->setDecimals(1);
    posElev->setMinimumWidth(70);
    grid->addWidget(posElev, r, 6);
    auto *posBtn = new QPushButton("Set Pos Thresh");
    grid->addWidget(posBtn, r, 7);
    r++;

    // Low power
    auto *lpOn = new QPushButton("LP Mode ON");
    auto *lpOff = new QPushButton("LP Mode OFF");
    grid->addWidget(lpOn, r, 0, 1, 2);
    grid->addWidget(lpOff, r, 2, 1, 2);

    // Frequency range
    grid->addWidget(new QLabel("Freq Min:"), r, 4);
    auto *freqMin = new QSpinBox;
    freqMin->setRange(-100000, 100000);
    freqMin->setMinimumWidth(80);
    grid->addWidget(freqMin, r, 5);
    grid->addWidget(new QLabel("Max:"), r, 6);
    auto *freqMax = new QSpinBox;
    freqMax->setRange(-100000, 100000);
    freqMax->setMinimumWidth(80);
    grid->addWidget(freqMax, r, 7);

    for (int i = 0; i < 8; i++)
        grid->setColumnStretch(i, 1);

    connect(notchBtn, &QPushButton::clicked, [this, notchSat, notchMode]() {
        m_driver->setNotchFilter(notchSat->currentIndex(), notchMode->currentIndex());
        log("Notch " + notchSat->currentText() + " " + notchMode->currentText());
    });
    connect(trkBtn, &QPushButton::clicked, [this, trkCn0, trkElev]() {
        m_driver->setTrackingThresholds(trkCn0->value(), trkElev->value());
        log("Trk thresh CN0=" + QString::number(trkCn0->value()));
    });
    connect(posBtn, &QPushButton::clicked, [this, posCn0, posElev]() {
        m_driver->setPositioningThresholds(posCn0->value(), posElev->value());
        log("Pos thresh CN0=" + QString::number(posCn0->value()));
    });
    connect(lpOn, &QPushButton::clicked, [this]() {
        Teseo::LowPowerConfig cfg;
        cfg.enabled = true;
        cfg.switchConstellation = true;
        cfg.dutyCycleEnabled = true;
        m_driver->setLowPowerMode(cfg);
        log("Low Power ON");
    });
    connect(lpOff, &QPushButton::clicked, [this]() {
        m_driver->disableLowPowerMode();
        log("Low Power OFF");
    });

    grp->setLayout(grid);
    parent->addWidget(grp);
}

void CommandPage::createCustomGroup(QVBoxLayout *parent)
{
    auto *grp = new QGroupBox("Custom Command");
    auto *lay = new QHBoxLayout;
    lay->setSpacing(8);
    lay->setContentsMargins(12, 16, 12, 12);

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
