// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "infopage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>

InfoPage::InfoPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(12);

    // Left panel
    auto *leftLayout = new QVBoxLayout;
    leftLayout->setSpacing(10);

    // Position card
    auto *posGroup = new QGroupBox("Position");
    auto *posGrid = new QGridLayout;
    posGrid->setSpacing(6);
    int r = 0;

    auto makeRow = [&](const QString &label, QLabel *&val) {
        auto *lbl = new QLabel(label);
        lbl->setStyleSheet("color: #94a3b8; font-size: 11px;");
        val = new QLabel("---");
        val->setStyleSheet("color: #e2e8f0; font-size: 12px; font-weight: 500;");
        posGrid->addWidget(lbl, r, 0);
        posGrid->addWidget(val, r++, 1);
    };

    makeRow("Latitude:", m_latLbl);
    makeRow("Longitude:", m_lonLbl);
    makeRow("Altitude:", m_altLbl);
    makeRow("Speed:", m_speedLbl);
    makeRow("Course:", m_courseLbl);
    makeRow("Fix Quality:", m_fixLbl);
    makeRow("Sats Used:", m_satsLbl);

    posGroup->setLayout(posGrid);
    leftLayout->addWidget(posGroup);

    // DOP card
    auto *dopGroup = new QGroupBox("DOP / Accuracy");
    auto *dopGrid = new QGridLayout;
    dopGrid->setSpacing(6);
    r = 0;

    auto makeDopRow = [&](const QString &label, QLabel *&val) {
        auto *lbl = new QLabel(label);
        lbl->setStyleSheet("color: #94a3b8; font-size: 11px;");
        val = new QLabel("---");
        val->setStyleSheet("color: #e2e8f0; font-size: 12px; font-weight: 500;");
        dopGrid->addWidget(lbl, r, 0);
        dopGrid->addWidget(val, r++, 1);
    };

    makeDopRow("HDOP:", m_hdopLbl);
    makeDopRow("PDOP:", m_pdopLbl);
    makeDopRow("VDOP:", m_vdopLbl);
    makeDopRow("EHPE:", m_ehpeLbl);
    makeDopRow("UTC Time:", m_timeLbl);
    makeDopRow("UTC Date:", m_dateLbl);

    dopGroup->setLayout(dopGrid);
    leftLayout->addWidget(dopGroup);
    leftLayout->addStretch();

    // Right panel - satellites
    auto *satGroup = new QGroupBox("Satellites in View");
    auto *satLayout = new QVBoxLayout;
    satLayout->setContentsMargins(8, 12, 8, 8);
    m_satTable = new QTableWidget;
    m_satTable->setColumnCount(5);
    m_satTable->setHorizontalHeaderLabels({"PRN", "Elev", "Azim", "CN0", "Used"});
    m_satTable->horizontalHeader()->setStretchLastSection(true);
    m_satTable->setEditTriggers(QTableWidget::NoEditTriggers);
    m_satTable->setSelectionBehavior(QTableWidget::SelectRows);
    m_satTable->verticalHeader()->setVisible(false);
    m_satTable->setShowGrid(false);
    m_satTable->setAlternatingRowColors(true);
    satLayout->addWidget(m_satTable);
    satGroup->setLayout(satLayout);

    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addWidget(satGroup, 2);

    connect(m_driver, &Teseo::TeseoDriver::fixUpdated,
            this, &InfoPage::onFixUpdated);
    connect(m_driver, &Teseo::TeseoDriver::satellitesUpdated,
            this, &InfoPage::onSatellitesUpdated);
    connect(m_driver, &Teseo::TeseoDriver::accuracyUpdated,
            this, &InfoPage::onAccuracyUpdated);
}

void InfoPage::onFixUpdated(const Teseo::GnssData &data)
{
    m_latLbl->setText(QString::number(data.position.latitudeDecimal(), 'f', 7) +
                      " " + QChar(data.position.latDirection));
    m_lonLbl->setText(QString::number(data.position.longitudeDecimal(), 'f', 7) +
                      " " + QChar(data.position.lonDirection));
    m_altLbl->setText(QString::number(data.position.altitude, 'f', 2) + " m");
    m_speedLbl->setText(QString::number(data.velocity.speedKmh, 'f', 1) + " km/h");
    m_courseLbl->setText(QString::number(data.velocity.courseTrue, 'f', 1) + " deg");
    m_satsLbl->setText(QString::number(data.satellitesUsed));

    QString fixStr;
    switch (data.fixQuality) {
    case Teseo::FixQuality::Invalid: fixStr = "No Fix"; break;
    case Teseo::FixQuality::GPS: fixStr = "GPS SPS"; break;
    case Teseo::FixQuality::DGPS: fixStr = "DGPS"; break;
    case Teseo::FixQuality::Estimated: fixStr = "Estimated (DR)"; break;
    }
    m_fixLbl->setText(fixStr);
    m_fixLbl->setStyleSheet(data.valid ?
        "color: #4ade80; font-size: 12px; font-weight: 600;" :
        "color: #f87171; font-size: 12px; font-weight: 600;");

    m_hdopLbl->setText(QString::number(data.dop.hdop, 'f', 1));
    m_pdopLbl->setText(QString::number(data.dop.pdop, 'f', 1));
    m_vdopLbl->setText(QString::number(data.dop.vdop, 'f', 1));

    if (data.utcDateTime.isValid()) {
        m_timeLbl->setText(data.utcDateTime.time().toString("HH:mm:ss.zzz"));
        m_dateLbl->setText(data.utcDateTime.date().toString("dd.MM.yyyy"));
    }
}

void InfoPage::onSatellitesUpdated(const QVector<Teseo::Satellite> &sats)
{
    m_satTable->setRowCount(sats.size());
    for (int i = 0; i < sats.size(); ++i) {
        const auto &s = sats[i];
        m_satTable->setItem(i, 0, new QTableWidgetItem(QString::number(s.prn)));
        m_satTable->setItem(i, 1, new QTableWidgetItem(QString::number(s.elevation)));
        m_satTable->setItem(i, 2, new QTableWidgetItem(QString::number(s.azimuth)));
        m_satTable->setItem(i, 3, new QTableWidgetItem(QString::number(s.cn0)));
        auto *usedItem = new QTableWidgetItem(s.usedInFix ? "Yes" : "No");
        usedItem->setForeground(s.usedInFix ? QColor("#4ade80") : QColor("#64748b"));
        m_satTable->setItem(i, 4, usedItem);
    }
}

void InfoPage::onAccuracyUpdated(const Teseo::Accuracy &acc)
{
    m_ehpeLbl->setText(QString::number(acc.ehpe, 'f', 1) + " m");
}
