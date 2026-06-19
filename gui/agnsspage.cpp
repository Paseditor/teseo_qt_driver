// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "agnsspage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateTime>

AGNSSPage::AGNSSPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    // Top row: Init + Freq
    auto *topRow = new QHBoxLayout;
    topRow->setSpacing(10);

    // Init card
    auto *initGroup = new QGroupBox("Initialize Position & Time");
    auto *initForm = new QFormLayout;
    initForm->setSpacing(6);

    auto *latSpin = new QDoubleSpinBox;
    latSpin->setRange(-90, 90); latSpin->setDecimals(6);
    initForm->addRow("Lat:", latSpin);

    auto *latRef = new QComboBox;
    latRef->addItems({"N", "S"});
    initForm->addRow("Ref:", latRef);

    auto *lonSpin = new QDoubleSpinBox;
    lonSpin->setRange(-180, 180); lonSpin->setDecimals(6);
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
    topRow->addWidget(initGroup);

    // Freq + ST-AGPS card
    auto *freqGroup = new QGroupBox("Frequency & ST-AGNSS");
    auto *freqGrid = new QGridLayout;
    freqGrid->setSpacing(6);
    int r = 0;

    freqGrid->addWidget(new QLabel("Freq Offset (Hz):"), r, 0);
    auto *freqSpin = new QSpinBox;
    freqSpin->setRange(-100000, 100000);
    freqGrid->addWidget(freqSpin, r, 1);
    auto *freqBtn = new QPushButton("Set");
    freqGrid->addWidget(freqBtn, r, 2);
    r++;

    auto *stagOn = new QPushButton("ST-AGPS ON");
    auto *stagOff = new QPushButton("ST-AGPS OFF");
    auto *stagStatus = new QPushButton("Get Status");
    freqGrid->addWidget(stagOn, r, 0);
    freqGrid->addWidget(stagOff, r, 1);
    freqGrid->addWidget(stagStatus, r, 2);
    r++;

    auto *stagInv = new QPushButton("Invalidate All");
    auto *agpsOn = new QPushButton("AGPS ON");
    auto *agpsOff = new QPushButton("AGPS OFF");
    freqGrid->addWidget(stagInv, r, 0);
    freqGrid->addWidget(agpsOn, r, 1);
    freqGrid->addWidget(agpsOff, r, 2);
    r++;

    auto *dumpAlm = new QPushButton("Dump Alm");
    auto *clrAlm = new QPushButton("Clear Alm");
    auto *dumpEph = new QPushButton("Dump Eph");
    auto *clrEph = new QPushButton("Clear Eph");
    freqGrid->addWidget(dumpAlm, r, 0);
    freqGrid->addWidget(clrAlm, r, 1);
    freqGrid->addWidget(dumpEph, r, 2);
    freqGrid->addWidget(clrEph, r, 3);

    freqGroup->setLayout(freqGrid);
    topRow->addWidget(freqGroup);
    mainLayout->addLayout(topRow);

    // Log
    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setMaximumHeight(80);
    m_logEdit->setPlaceholderText("AGNSS log...");
    mainLayout->addWidget(m_logEdit);

    // Connections
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
    connect(freqBtn, &QPushButton::clicked, [this, freqSpin]() { m_driver->initFrequency(freqSpin->value()); m_logEdit->append("InitFreq"); });
    connect(stagOn, &QPushButton::clicked, [this]() { m_driver->stagpsOnOff(true); m_logEdit->append("ST-AGPS ON"); });
    connect(stagOff, &QPushButton::clicked, [this]() { m_driver->stagpsOnOff(false); m_logEdit->append("ST-AGPS OFF"); });
    connect(stagStatus, &QPushButton::clicked, [this]() { m_driver->stagpsGetStatus(); m_logEdit->append("Get Status"); });
    connect(stagInv, &QPushButton::clicked, [this]() { m_driver->stagpsInvalidate(7); m_logEdit->append("Invalidate All"); });
    connect(agpsOn, &QPushButton::clicked, [this]() { m_driver->cfgAgps(true); m_logEdit->append("AGPS ON"); });
    connect(agpsOff, &QPushButton::clicked, [this]() { m_driver->cfgAgps(false); m_logEdit->append("AGPS OFF"); });
    connect(dumpAlm, &QPushButton::clicked, [this]() { m_driver->dumpAlmanacs(); m_logEdit->append("Dump Alm"); });
    connect(clrAlm, &QPushButton::clicked, [this]() { m_driver->clearAlmanacs(); m_logEdit->append("Clear Alm"); });
    connect(dumpEph, &QPushButton::clicked, [this]() { m_driver->dumpEphemeris(); m_logEdit->append("Dump Eph"); });
    connect(clrEph, &QPushButton::clicked, [this]() { m_driver->clearEphemeris(); m_logEdit->append("Clear Eph"); });
}
