// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "deadreckoningpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateTime>

DeadReckoningPage::DeadReckoningPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    // Top row: MMFB + SoU
    auto *topRow = new QHBoxLayout;
    topRow->setSpacing(10);

    // MMFB card
    auto *mmfbGroup = new QGroupBox("Map Matching Feedback");
    auto *mmfbForm = new QFormLayout;
    mmfbForm->setSpacing(6);

    auto *mmfbTime = new QLineEdit;
    mmfbTime->setText("120000.000");
    mmfbForm->addRow("Timestamp:", mmfbTime);

    auto *mmfbLatValid = new QCheckBox("Lat Valid");
    mmfbLatValid->setChecked(true);
    mmfbForm->addRow(mmfbLatValid);

    auto *mmfbLonValid = new QCheckBox("Lon Valid");
    mmfbLonValid->setChecked(true);
    mmfbForm->addRow(mmfbLonValid);

    auto *mmfbLat = new QDoubleSpinBox;
    mmfbLat->setRange(-90, 90); mmfbLat->setDecimals(7);
    mmfbForm->addRow("Latitude:", mmfbLat);

    auto *mmfbLon = new QDoubleSpinBox;
    mmfbLon->setRange(-180, 180); mmfbLon->setDecimals(7);
    mmfbForm->addRow("Longitude:", mmfbLon);

    auto *mmfbLatErr = new QDoubleSpinBox;
    mmfbLatErr->setRange(0, 1000); mmfbLatErr->setDecimals(1);
    mmfbForm->addRow("Lat Err (m):", mmfbLatErr);

    auto *mmfbLonErr = new QDoubleSpinBox;
    mmfbLonErr->setRange(0, 1000); mmfbLonErr->setDecimals(1);
    mmfbForm->addRow("Lon Err (m):", mmfbLonErr);

    auto *mmfbBtn = new QPushButton("Send MMFB");
    mmfbForm->addRow(mmfbBtn);

    mmfbGroup->setLayout(mmfbForm);
    topRow->addWidget(mmfbGroup);

    // SoU + DR card
    auto *souGroup = new QGroupBox("Sensors & DR Control");
    auto *souGrid = new QGridLayout;
    souGrid->setSpacing(6);
    int r = 0;

    souGrid->addWidget(new QLabel("Sensor ID:"), r, 0);
    auto *sensorId = new QSpinBox;
    sensorId->setRange(0, 99);
    sensorId->setValue(31);
    sensorId->setToolTip("1=Odo, 2=Reverse, 4=1-axis Gyro, 14=Speed, 30=3-axis Acc, 31=3-axis Gyro");
    souGrid->addWidget(sensorId, r, 1);
    r++;

    souGrid->addWidget(new QLabel("X:"), r, 0);
    auto *vx = new QSpinBox; vx->setRange(-99999, 99999);
    souGrid->addWidget(vx, r, 1);
    souGrid->addWidget(new QLabel("Y:"), r, 2);
    auto *vy = new QSpinBox; vy->setRange(-99999, 99999);
    souGrid->addWidget(vy, r, 3);
    souGrid->addWidget(new QLabel("Z:"), r, 4);
    auto *vz = new QSpinBox; vz->setRange(-99999, 99999);
    souGrid->addWidget(vz, r, 5);
    r++;

    auto *souBtn = new QPushButton("Send Sensor");
    souGrid->addWidget(souBtn, r, 0, 1, 2);
    auto *tiltBtn = new QPushButton("Calibrate Tilt");
    souGrid->addWidget(tiltBtn, r, 2, 1, 2);
    auto *nvmBtn = new QPushButton("Save DR NVM");
    souGrid->addWidget(nvmBtn, r, 4, 1, 2);
    r++;

    // Odometer
    souGrid->addWidget(new QLabel("Odometer:"), r, 0);
    auto *odoEn = new QCheckBox("Enable");
    souGrid->addWidget(odoEn, r, 1);
    auto *odoBtn = new QPushButton("Apply");
    souGrid->addWidget(odoBtn, r, 2);
    r++;

    // Anti-jamming
    souGrid->addWidget(new QLabel("AJM GPS:"), r, 0);
    auto *ajmGps = new QSpinBox; ajmGps->setRange(0, 2);
    souGrid->addWidget(ajmGps, r, 1);
    souGrid->addWidget(new QLabel("AJM GLO:"), r, 2);
    auto *ajmGlo = new QSpinBox; ajmGlo->setRange(0, 2);
    souGrid->addWidget(ajmGlo, r, 3);
    auto *ajmBtn = new QPushButton("Apply AJM");
    souGrid->addWidget(ajmBtn, r, 4, 1, 2);

    souGroup->setLayout(souGrid);
    topRow->addWidget(souGroup);
    mainLayout->addLayout(topRow);

    // Log
    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setMaximumHeight(60);
    m_logEdit->setPlaceholderText("DR log...");
    mainLayout->addWidget(m_logEdit);

    // Connections
    connect(mmfbBtn, &QPushButton::clicked, [this, mmfbTime, mmfbLatValid, mmfbLonValid, mmfbLat, mmfbLon, mmfbLatErr, mmfbLonErr]() {
        m_driver->sendMapMatchingFeedback(mmfbTime->text().toLatin1(),
            mmfbLatValid->isChecked(), mmfbLonValid->isChecked(),
            mmfbLat->value(), mmfbLon->value(), 0, 0,
            mmfbLatErr->value(), mmfbLonErr->value());
        m_logEdit->append("MMFB sent");
    });
    connect(souBtn, &QPushButton::clicked, [this, sensorId, vx, vy, vz]() {
        m_driver->sendSensorMessage(sensorId->value(), {vx->value(), vy->value(), vz->value()});
        m_logEdit->append("Sensor ID=" + QString::number(sensorId->value()));
    });
    connect(tiltBtn, &QPushButton::clicked, [this]() { m_driver->drCalibrateTilt(); m_logEdit->append("Tilt cal"); });
    connect(nvmBtn, &QPushButton::clicked, [this]() { m_driver->drSaveToNvm(); m_logEdit->append("DR NVM save"); });
    connect(odoBtn, &QPushButton::clicked, [this, odoEn]() { m_driver->cfgOdometer(odoEn->isChecked(), false, 0); m_logEdit->append("Odometer"); });
    connect(ajmBtn, &QPushButton::clicked, [this, ajmGps, ajmGlo]() {
        m_driver->cfgAntiJamming(ajmGps->value(), ajmGlo->value());
        m_logEdit->append("AJM applied");
    });
}
