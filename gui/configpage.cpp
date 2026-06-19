// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "configpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateTime>

ConfigPage::ConfigPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    // Top row: CDB + Quick
    auto *topRow = new QHBoxLayout;
    topRow->setSpacing(12);

    // CDB Parameter card
    auto *parGroup = new QGroupBox("CDB Parameters");
    auto *parForm = new QFormLayout;
    parForm->setSpacing(10);
    parForm->setContentsMargins(12, 16, 12, 12);

    auto *blockCombo = new QComboBox;
    blockCombo->addItems({"1 - Current", "2 - Default", "3 - NVM"});
    blockCombo->setMinimumWidth(120);
    parForm->addRow("Block:", blockCombo);

    auto *idSpin = new QSpinBox;
    idSpin->setRange(0, 999);
    idSpin->setMinimumWidth(100);
    parForm->addRow("ID:", idSpin);

    auto *valueEdit = new QLineEdit;
    valueEdit->setPlaceholderText("Hex value");
    valueEdit->setMinimumWidth(120);
    parForm->addRow("Value:", valueEdit);

    auto *parBtns = new QHBoxLayout;
    parBtns->setSpacing(6);
    auto *getBtn = new QPushButton("GET");
    auto *setBtn = new QPushButton("SET");
    auto *saveBtn = new QPushButton("SAVE");
    auto *restoreBtn = new QPushButton("RESTORE");
    parBtns->addWidget(getBtn);
    parBtns->addWidget(setBtn);
    parBtns->addWidget(saveBtn);
    parBtns->addWidget(restoreBtn);
    parForm->addRow(parBtns);

    parGroup->setLayout(parForm);
    topRow->addWidget(parGroup, 1);

    // Quick config card
    auto *quickGroup = new QGroupBox("Quick Config");
    auto *qGrid = new QGridLayout;
    qGrid->setSpacing(8);
    qGrid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    qGrid->addWidget(new QLabel("Baud:"), r, 0);
    auto *baudCombo = new QComboBox;
    baudCombo->addItems({"9600","19200","38400","57600","115200","230400","460800","921600"});
    baudCombo->setCurrentText("115200");
    baudCombo->setMinimumWidth(90);
    qGrid->addWidget(baudCombo, r, 1, 1, 2);
    auto *baudBtn = new QPushButton("Set");
    qGrid->addWidget(baudBtn, r, 3);

    qGrid->addWidget(new QLabel("Rate:"), r, 4);
    auto *rateSpin = new QSpinBox;
    rateSpin->setRange(1, 20);
    rateSpin->setMinimumWidth(60);
    qGrid->addWidget(rateSpin, r, 5);
    auto *rateBtn = new QPushButton("Set");
    qGrid->addWidget(rateBtn, r, 6);
    r++;

    qGrid->addWidget(new QLabel("GPS:"), r, 0);
    auto *gpsCombo = new QComboBox;
    gpsCombo->addItems({"Off","Track","Use"});
    gpsCombo->setCurrentIndex(2);
    qGrid->addWidget(gpsCombo, r, 1, 1, 2);

    qGrid->addWidget(new QLabel("GLO:"), r, 3);
    auto *gloCombo = new QComboBox;
    gloCombo->addItems({"Off","Track","Use"});
    gloCombo->setCurrentIndex(2);
    qGrid->addWidget(gloCombo, r, 4, 1, 2);
    r++;

    qGrid->addWidget(new QLabel("GAL:"), r, 0);
    auto *galCombo = new QComboBox;
    galCombo->addItems({"Off","Track","Use"});
    qGrid->addWidget(galCombo, r, 1, 1, 2);

    qGrid->addWidget(new QLabel("BDS:"), r, 3);
    auto *bdsCombo = new QComboBox;
    bdsCombo->addItems({"Off","Track","Use"});
    qGrid->addWidget(bdsCombo, r, 4, 1, 2);
    r++;

    auto *constBtn = new QPushButton("Apply Constellations");
    qGrid->addWidget(constBtn, r, 0, 1, 7);
    r++;

    qGrid->addWidget(new QLabel("Trk CN0:"), r, 0);
    auto *trkCn0 = new QSpinBox; trkCn0->setRange(0, 50);
    qGrid->addWidget(trkCn0, r, 1);
    qGrid->addWidget(new QLabel("Pos CN0:"), r, 2);
    auto *posCn0 = new QSpinBox; posCn0->setRange(0, 50);
    qGrid->addWidget(posCn0, r, 3, 1, 2);
    auto *thrBtn = new QPushButton("Apply Thresholds");
    qGrid->addWidget(thrBtn, r, 5, 1, 2);

    // Column stretch
    qGrid->setColumnStretch(0, 0);
    qGrid->setColumnStretch(1, 1);
    qGrid->setColumnStretch(2, 0);
    qGrid->setColumnStretch(3, 0);
    qGrid->setColumnStretch(4, 1);
    qGrid->setColumnStretch(5, 1);
    qGrid->setColumnStretch(6, 0);

    quickGroup->setLayout(qGrid);
    topRow->addWidget(quickGroup, 2);
    mainLayout->addLayout(topRow);

    // RTCM row
    auto *rtcmGroup = new QGroupBox("RTCM (Differential Corrections)");
    auto *rtcmGrid = new QGridLayout;
    rtcmGrid->setSpacing(8);
    rtcmGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    rtcmGrid->addWidget(new QLabel("Source:"), r, 0);
    auto *diffCombo = new QComboBox;
    diffCombo->addItems({"0-NONE", "1-SBAS", "2-RTCM", "3-AUTO"});
    diffCombo->setCurrentIndex(3);
    diffCombo->setMinimumWidth(100);
    rtcmGrid->addWidget(diffCombo, r, 1, 1, 2);
    auto *diffBtn = new QPushButton("Apply");
    rtcmGrid->addWidget(diffBtn, r, 3);

    auto *rtcmOn = new QPushButton("RTCM ON");
    auto *rtcmOff = new QPushButton("RTCM OFF");
    rtcmGrid->addWidget(rtcmOn, r, 4);
    rtcmGrid->addWidget(rtcmOff, r, 5);
    r++;

    rtcmGrid->addWidget(new QLabel("RTCM Data (hex):"), r, 0);
    auto *rtcmDataEdit = new QLineEdit;
    rtcmDataEdit->setPlaceholderText("Raw RTCM frame hex...");
    rtcmGrid->addWidget(rtcmDataEdit, r, 1, 1, 4);
    auto *rtcmSend = new QPushButton("Send RTCM");
    rtcmGrid->addWidget(rtcmSend, r, 5);

    rtcmGrid->setColumnStretch(0, 0);
    rtcmGrid->setColumnStretch(1, 1);
    rtcmGrid->setColumnStretch(2, 1);
    rtcmGrid->setColumnStretch(3, 0);
    rtcmGrid->setColumnStretch(4, 0);
    rtcmGrid->setColumnStretch(5, 0);

    rtcmGroup->setLayout(rtcmGrid);
    mainLayout->addWidget(rtcmGroup);

    // Results
    m_resultEdit = new QTextEdit;
    m_resultEdit->setReadOnly(true);
    m_resultEdit->setMaximumHeight(80);
    m_resultEdit->setPlaceholderText("Parameter results...");
    mainLayout->addWidget(m_resultEdit);

    // Connections
    connect(getBtn, &QPushButton::clicked, [this, blockCombo, idSpin]() {
        int block = blockCombo->currentIndex() + 1;
        m_driver->getParameter(block, idSpin->value());
        m_resultEdit->append("GET block=" + QString::number(block) + " id=" + QString::number(idSpin->value()));
    });
    connect(setBtn, &QPushButton::clicked, [this, blockCombo, idSpin, valueEdit]() {
        int block = blockCombo->currentIndex() + 1;
        m_driver->setParameter(block, idSpin->value(), valueEdit->text().toLatin1());
        m_resultEdit->append("SET id=" + QString::number(idSpin->value()) + " val=" + valueEdit->text());
    });
    connect(saveBtn, &QPushButton::clicked, [this]() { m_driver->saveParameters(); m_resultEdit->append("SAVE"); });
    connect(restoreBtn, &QPushButton::clicked, [this]() { m_driver->restoreFactoryParameters(); m_resultEdit->append("RESTORE"); });
    connect(baudBtn, &QPushButton::clicked, [this, baudCombo]() { m_driver->setBaudRate(baudCombo->currentText().toInt()); });
    connect(rateBtn, &QPushButton::clicked, [this, rateSpin]() { m_driver->setFixRate(rateSpin->value()); });
    connect(constBtn, &QPushButton::clicked, [this, gpsCombo, gloCombo, galCombo, bdsCombo]() {
        Teseo::ConstellationConfig cfg;
        cfg.gps = gpsCombo->currentIndex() + 1;
        cfg.glonass = gloCombo->currentIndex() + 1;
        cfg.galileo = galCombo->currentIndex() + 1;
        cfg.beidou = bdsCombo->currentIndex() + 1;
        m_driver->cfgConstellations(cfg);
        m_resultEdit->append("Applied constellations");
    });
    connect(thrBtn, &QPushButton::clicked, [this, trkCn0, posCn0]() {
        m_driver->cfgGnssThresholds(trkCn0->value(), posCn0->value(), 0, 0);
        m_resultEdit->append("Applied thresholds");
    });
    connect(diffBtn, &QPushButton::clicked, [this, diffCombo]() {
        m_driver->setDifferentialSource(diffCombo->currentIndex());
        m_resultEdit->append("Diff source: " + diffCombo->currentText());
    });
    connect(rtcmOn, &QPushButton::clicked, [this]() { m_driver->enableRtcm(true); m_resultEdit->append("RTCM ON"); });
    connect(rtcmOff, &QPushButton::clicked, [this]() { m_driver->enableRtcm(false); m_resultEdit->append("RTCM OFF"); });
    connect(rtcmSend, &QPushButton::clicked, [this, rtcmDataEdit]() {
        QByteArray data = QByteArray::fromHex(rtcmDataEdit->text().toLatin1());
        m_driver->sendRtcmData(data);
        m_resultEdit->append("Sent RTCM: " + QString::number(data.size()) + " bytes");
    });

    connect(m_driver, &Teseo::TeseoDriver::parameterReceived,
            this, [this](int id, const QByteArray &value) {
        m_resultEdit->append("Param ID=" + QString::number(id) + " Value=" + value);
    });
}
