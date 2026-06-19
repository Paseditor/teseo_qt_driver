// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "agnsspage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateTime>
#include <QScrollArea>

AGNSSPage::AGNSSPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    auto *scrollWidget = new QWidget;
    auto *mainLayout = new QVBoxLayout(scrollWidget);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    // Top row: Init + Freq
    auto *topRow = new QHBoxLayout;
    topRow->setSpacing(12);

    // Init card
    auto *initGroup = new QGroupBox("Initialize Position & Time");
    auto *initForm = new QFormLayout;
    initForm->setSpacing(8);
    initForm->setContentsMargins(12, 16, 12, 12);

    auto *latSpin = new QDoubleSpinBox;
    latSpin->setRange(-90, 90); latSpin->setDecimals(6);
    latSpin->setMinimumWidth(140);
    initForm->addRow("Lat:", latSpin);

    auto *latRef = new QComboBox;
    latRef->addItems({"N", "S"});
    initForm->addRow("Ref:", latRef);

    auto *lonSpin = new QDoubleSpinBox;
    lonSpin->setRange(-180, 180); lonSpin->setDecimals(6);
    lonSpin->setMinimumWidth(140);
    initForm->addRow("Lon:", lonSpin);

    auto *lonRef = new QComboBox;
    lonRef->addItems({"E", "W"});
    initForm->addRow("Ref:", lonRef);

    auto *altSpin = new QDoubleSpinBox;
    altSpin->setRange(-1500, 100000);
    initForm->addRow("Alt (m):", altSpin);

    auto *dateEdit = new QDateEdit;
    dateEdit->setDate(QDate::currentDate());
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    initForm->addRow("Date:", dateEdit);

    auto *timeEdit = new QTimeEdit;
    timeEdit->setTime(QTime::currentTime());
    timeEdit->setDisplayFormat("HH:mm:ss");
    initForm->addRow("Time:", timeEdit);

    auto *initGpsBtn = new QPushButton("Init GPS");
    auto *initTimeBtn = new QPushButton("Init Time");
    initForm->addRow(initGpsBtn);
    initForm->addRow(initTimeBtn);

    initGroup->setLayout(initForm);
    topRow->addWidget(initGroup, 1);

    // Freq + ST-AGPS card
    auto *freqGroup = new QGroupBox("Frequency & ST-AGNSS");
    auto *freqGrid = new QGridLayout;
    freqGrid->setSpacing(8);
    freqGrid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    freqGrid->addWidget(new QLabel("Freq Offset (Hz):"), r, 0);
    auto *freqSpin = new QSpinBox;
    freqSpin->setRange(-100000, 100000);
    freqSpin->setMinimumWidth(100);
    freqGrid->addWidget(freqSpin, r, 1, 1, 2);
    auto *freqBtn = new QPushButton("Set");
    freqGrid->addWidget(freqBtn, r, 3);
    r++;

    auto *stagOn = new QPushButton("ST-AGPS ON");
    auto *stagOff = new QPushButton("ST-AGPS OFF");
    auto *stagStatus = new QPushButton("Get Status");
    freqGrid->addWidget(stagOn, r, 0);
    freqGrid->addWidget(stagOff, r, 1, 1, 2);
    freqGrid->addWidget(stagStatus, r, 3);
    r++;

    auto *stagInv = new QPushButton("Invalidate All");
    auto *agpsOn = new QPushButton("AGPS ON");
    auto *agpsOff = new QPushButton("AGPS OFF");
    freqGrid->addWidget(stagInv, r, 0);
    freqGrid->addWidget(agpsOn, r, 1, 1, 2);
    freqGrid->addWidget(agpsOff, r, 3);
    r++;

    // ST-AGPS constellation mask
    freqGrid->addWidget(new QLabel("ST-AGPS Mask:"), r, 0);
    auto *stagMask = new QSpinBox;
    stagMask->setRange(0, 255);
    stagMask->setValue(1);
    stagMask->setToolTip("1=GPS, 2=GLONASS, 8=Galileo, 128=BeiDou");
    freqGrid->addWidget(stagMask, r, 1);
    auto *stagMaskBtn = new QPushButton("Set Mask");
    freqGrid->addWidget(stagMaskBtn, r, 2);

    // Password generation
    freqGrid->addWidget(new QLabel("GPS Time (s):"), r, 3);
    auto *agpsTime = new QSpinBox;
    agpsTime->setRange(0, 999999999);
    freqGrid->addWidget(agpsTime, r, 4);
    r++;

    freqGrid->addWidget(new QLabel("Vendor ID:"), r, 0);
    auto *agpsVendor = new QLineEdit;
    agpsVendor->setPlaceholderText("vendor_id");
    freqGrid->addWidget(agpsVendor, r, 1, 1, 2);
    freqGrid->addWidget(new QLabel("Device ID:"), r, 3);
    auto *agpsDev = new QLineEdit;
    agpsDev->setPlaceholderText("device_id");
    freqGrid->addWidget(agpsDev, r, 4);
    auto *agpsPassBtn = new QPushButton("Gen Password");
    freqGrid->addWidget(agpsPassBtn, r, 5);
    r++;

    freqGrid->setColumnStretch(0, 0);
    freqGrid->setColumnStretch(1, 1);
    freqGrid->setColumnStretch(2, 1);
    freqGrid->setColumnStretch(3, 0);
    freqGrid->setColumnStretch(4, 1);
    freqGrid->setColumnStretch(5, 0);

    freqGroup->setLayout(freqGrid);
    topRow->addWidget(freqGroup, 1);
    mainLayout->addLayout(topRow);

    // Almanac / Ephemeris injection
    auto *injGroup = new QGroupBox("Almanac / Ephemeris Injection");
    auto *injGrid = new QGridLayout;
    injGrid->setSpacing(8);
    injGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    injGrid->addWidget(new QLabel("Sat ID:"), r, 0);
    auto *injSatId = new QSpinBox;
    injSatId->setRange(0, 99);
    injSatId->setMinimumWidth(60);
    injGrid->addWidget(injSatId, r, 1);
    injGrid->addWidget(new QLabel("Hex Data:"), r, 2);
    auto *injData = new QLineEdit;
    injData->setPlaceholderText("Almanac/Ephemeris hex data...");
    injGrid->addWidget(injData, r, 3, 1, 3);
    r++;

    auto *loadAlmBtn = new QPushButton("Load Almanac");
    auto *loadEphBtn = new QPushButton("Load Ephemeris");
    auto *dumpAlm = new QPushButton("Dump Alm");
    auto *clrAlm = new QPushButton("Clear Alm");
    auto *dumpEph = new QPushButton("Dump Eph");
    auto *clrEph = new QPushButton("Clear Eph");
    injGrid->addWidget(loadAlmBtn, r, 0);
    injGrid->addWidget(loadEphBtn, r, 1);
    injGrid->addWidget(dumpAlm, r, 2);
    injGrid->addWidget(clrAlm, r, 3);
    injGrid->addWidget(dumpEph, r, 4);
    injGrid->addWidget(clrEph, r, 5);
    r++;

    injGrid->setColumnStretch(0, 1);
    injGrid->setColumnStretch(1, 1);
    injGrid->setColumnStretch(2, 1);
    injGrid->setColumnStretch(3, 1);
    injGrid->setColumnStretch(4, 1);
    injGrid->setColumnStretch(5, 1);

    injGroup->setLayout(injGrid);
    mainLayout->addWidget(injGroup);

    // Galileo / Ionosphere
    auto *galGroup = new QGroupBox("Galileo GGTO / Ionosphere");
    auto *galGrid = new QGridLayout;
    galGrid->setSpacing(8);
    galGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    galGrid->addWidget(new QLabel("BRD:"), r, 0);
    auto *ggtoBrd = new QSpinBox; ggtoBrd->setRange(0, 1); ggtoBrd->setValue(1);
    galGrid->addWidget(ggtoBrd, r, 1);
    galGrid->addWidget(new QLabel("WN0G:"), r, 2);
    auto *ggtoWn = new QSpinBox; ggtoWn->setRange(0, 999);
    galGrid->addWidget(ggtoWn, r, 3);
    galGrid->addWidget(new QLabel("t0G:"), r, 4);
    auto *ggtoT0 = new QSpinBox; ggtoT0->setRange(0, 99999);
    galGrid->addWidget(ggtoT0, r, 5);
    galGrid->addWidget(new QLabel("A0G:"), r, 6);
    auto *ggtoA0 = new QSpinBox; ggtoA0->setRange(-99999, 99999);
    galGrid->addWidget(ggtoA0, r, 7);
    r++;

    galGrid->addWidget(new QLabel("A1G:"), r, 0);
    auto *ggtoA1 = new QSpinBox; ggtoA1->setRange(-99999, 99999);
    galGrid->addWidget(ggtoA1, r, 1);
    galGrid->addWidget(new QLabel("Validity:"), r, 2);
    auto *ggtoVal = new QCheckBox("Valid");
    galGrid->addWidget(ggtoVal, r, 3);
    auto *ggtoSetBtn = new QPushButton("Set GGTO");
    galGrid->addWidget(ggtoSetBtn, r, 4);
    auto *ggtoDumpBtn = new QPushButton("Dump GGTO");
    galGrid->addWidget(ggtoDumpBtn, r, 5);
    r++;

    // Ionosphere
    galGrid->addWidget(new QLabel("Iono SatType:"), r, 0);
    auto *ionoSat = new QComboBox;
    ionoSat->addItems({"0-GPS", "1-GLONASS", "3-Galileo", "7-BeiDou"});
    galGrid->addWidget(ionoSat, r, 1);
    galGrid->addWidget(new QLabel("Params (comma-sep):"), r, 2);
    auto *ionoParams = new QLineEdit;
    ionoParams->setPlaceholderText("A0,A1,A2,A3,B0,B1,B2,B3");
    galGrid->addWidget(ionoParams, r, 3, 1, 3);
    auto *ionoBtn = new QPushButton("Set Iono");
    galGrid->addWidget(ionoBtn, r, 6);

    for (int i = 0; i < 8; i++)
        galGrid->setColumnStretch(i, 1);

    galGroup->setLayout(galGrid);
    mainLayout->addWidget(galGroup);

    // Log
    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setMaximumHeight(80);
    m_logEdit->setPlaceholderText("AGNSS log...");
    mainLayout->addWidget(m_logEdit);

    scrollArea->setWidget(scrollWidget);
    auto *outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->addWidget(scrollArea);

    // === Connections ===

    connect(initGpsBtn, &QPushButton::clicked, [this, latSpin, latRef, lonSpin, lonRef, altSpin, dateEdit, timeEdit]() {
        m_driver->initGps(latSpin->value(), latRef->currentText().at(0).toLatin1(),
                          lonSpin->value(), lonRef->currentText().at(0).toLatin1(),
                          altSpin->value(), dateEdit->date(), timeEdit->time());
        m_logEdit->append("InitGPS");
    });
    connect(initTimeBtn, &QPushButton::clicked, [this, dateEdit, timeEdit]() {
        m_driver->initTime(dateEdit->date(), timeEdit->time());
        m_logEdit->append("InitTime");
    });
    connect(freqBtn, &QPushButton::clicked, [this, freqSpin]() {
        m_driver->initFrequency(freqSpin->value());
        m_logEdit->append("InitFreq");
    });
    connect(stagOn, &QPushButton::clicked, [this]() { m_driver->stagpsOnOff(true); m_logEdit->append("ST-AGPS ON"); });
    connect(stagOff, &QPushButton::clicked, [this]() { m_driver->stagpsOnOff(false); m_logEdit->append("ST-AGPS OFF"); });
    connect(stagStatus, &QPushButton::clicked, [this]() { m_driver->stagpsGetStatus(); m_logEdit->append("Get Status"); });
    connect(stagInv, &QPushButton::clicked, [this]() { m_driver->stagpsInvalidate(7); m_logEdit->append("Invalidate All"); });
    connect(agpsOn, &QPushButton::clicked, [this]() { m_driver->cfgAgps(true); m_logEdit->append("AGPS ON"); });
    connect(agpsOff, &QPushButton::clicked, [this]() { m_driver->cfgAgps(false); m_logEdit->append("AGPS OFF"); });

    // ST-AGPS constellation mask
    connect(stagMaskBtn, &QPushButton::clicked, [this, stagMask]() {
        m_driver->stagpsSetConstellationMask(stagMask->value());
        m_logEdit->append("ST-AGPS Mask=" + QString::number(stagMask->value()));
    });

    // Password generation
    connect(agpsPassBtn, &QPushButton::clicked, [this, agpsTime, agpsVendor, agpsDev]() {
        m_driver->stagpsGeneratePassword(agpsTime->value(),
            agpsVendor->text().toLatin1(), agpsDev->text().toLatin1());
        m_logEdit->append("Gen Password");
    });

    // Almanac / Ephemeris
    connect(loadAlmBtn, &QPushButton::clicked, [this, injSatId, injData]() {
        m_driver->loadAlmanac(injSatId->value(), injData->text().toLatin1());
        m_logEdit->append("Load Alm sat=" + QString::number(injSatId->value()));
    });
    connect(loadEphBtn, &QPushButton::clicked, [this, injSatId, injData]() {
        m_driver->loadEphemeris(injSatId->value(), injData->text().toLatin1());
        m_logEdit->append("Load Eph sat=" + QString::number(injSatId->value()));
    });
    connect(dumpAlm, &QPushButton::clicked, [this]() { m_driver->dumpAlmanacs(); m_logEdit->append("Dump Alm"); });
    connect(clrAlm, &QPushButton::clicked, [this]() { m_driver->clearAlmanacs(); m_logEdit->append("Clear Alm"); });
    connect(dumpEph, &QPushButton::clicked, [this]() { m_driver->dumpEphemeris(); m_logEdit->append("Dump Eph"); });
    connect(clrEph, &QPushButton::clicked, [this]() { m_driver->clearEphemeris(); m_logEdit->append("Clear Eph"); });

    // Galileo GGTO
    connect(ggtoSetBtn, &QPushButton::clicked, [this, ggtoBrd, ggtoWn, ggtoT0, ggtoA0, ggtoA1, ggtoVal]() {
        m_driver->setGalileoGgto(ggtoBrd->value(), ggtoWn->value(),
            ggtoT0->value(), ggtoA0->value(), ggtoA1->value(), ggtoVal->isChecked());
        m_logEdit->append("Set Galileo GGTO");
    });
    connect(ggtoDumpBtn, &QPushButton::clicked, [this]() {
        m_driver->dumpGalileoGgto();
        m_logEdit->append("Dump Galileo GGTO");
    });

    // Ionosphere
    connect(ionoBtn, &QPushButton::clicked, [this, ionoSat, ionoParams]() {
        QVector<int> params;
        for (const QString &p : ionoParams->text().split(',')) {
            bool ok;
            int v = p.trimmed().toInt(&ok);
            if (ok) params.append(v);
        }
        m_driver->setIonoParams(ionoSat->currentIndex(), params);
        m_logEdit->append("Set Iono params");
    });
}
