// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "infopage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QDateTime>

InfoPage::InfoPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(12);

    // Left panel
    auto *leftLayout = new QVBoxLayout;
    leftLayout->setSpacing(10);

    auto makeRow = [](QGridLayout *grid, int &r, const QString &label, QLabel *&val) {
        auto *lbl = new QLabel(label);
        lbl->setStyleSheet("color: #94a3b8; font-size: 11px;");
        val = new QLabel("---");
        val->setStyleSheet("color: #e2e8f0; font-size: 12px; font-weight: 500;");
        grid->addWidget(lbl, r, 0);
        grid->addWidget(val, r++, 1);
    };

    // Position card
    auto *posGroup = new QGroupBox("Position");
    auto *posGrid = new QGridLayout;
    posGrid->setSpacing(6);
    int r = 0;
    makeRow(posGrid, r, "Latitude:", m_latLbl);
    makeRow(posGrid, r, "Longitude:", m_lonLbl);
    makeRow(posGrid, r, "Altitude:", m_altLbl);
    makeRow(posGrid, r, "Speed:", m_speedLbl);
    makeRow(posGrid, r, "Course:", m_courseLbl);
    makeRow(posGrid, r, "Fix Quality:", m_fixLbl);
    makeRow(posGrid, r, "Sats Used:", m_satsLbl);
    posGroup->setLayout(posGrid);
    leftLayout->addWidget(posGroup);

    // DOP card
    auto *dopGroup = new QGroupBox("DOP / Accuracy");
    auto *dopGrid = new QGridLayout;
    dopGrid->setSpacing(6);
    r = 0;
    makeRow(dopGrid, r, "HDOP:", m_hdopLbl);
    makeRow(dopGrid, r, "PDOP:", m_pdopLbl);
    makeRow(dopGrid, r, "VDOP:", m_vdopLbl);
    makeRow(dopGrid, r, "EHPE:", m_ehpeLbl);
    makeRow(dopGrid, r, "UTC Time:", m_timeLbl);
    makeRow(dopGrid, r, "UTC Date:", m_dateLbl);
    dopGroup->setLayout(dopGrid);
    leftLayout->addWidget(dopGroup);

    // RTC card
    auto *rtcGroup = new QGroupBox("RTC Time");
    auto *rtcGrid = new QGridLayout;
    rtcGrid->setSpacing(6);
    r = 0;
    makeRow(rtcGrid, r, "RTC Time:", m_rtcTimeLbl);
    makeRow(rtcGrid, r, "RTC Date:", m_rtcDateLbl);
    makeRow(rtcGrid, r, "RTC Status:", m_rtcStatusLbl);
    rtcGroup->setLayout(rtcGrid);
    leftLayout->addWidget(rtcGroup);

    // Version / Status card
    auto *verGroup = new QGroupBox("Device Info");
    auto *verGrid = new QGridLayout;
    verGrid->setSpacing(6);
    r = 0;
    makeRow(verGrid, r, "SW Version:", m_swVerLbl);
    makeRow(verGrid, r, "Unique Code:", m_uniqueCodeLbl);
    makeRow(verGrid, r, "Standby:", m_standbyLbl);
    verGroup->setLayout(verGrid);
    leftLayout->addWidget(verGroup);

    // PPS / TRAIM card
    auto *ppsGroup = new QGroupBox("PPS / TRAIM");
    auto *ppsGrid = new QGridLayout;
    ppsGrid->setSpacing(6);
    r = 0;
    makeRow(ppsGrid, r, "PPS On:", m_ppsOnLbl);
    makeRow(ppsGrid, r, "PPS Valid:", m_ppsValidLbl);
    makeRow(ppsGrid, r, "PPS Mode:", m_ppsModeLbl);
    makeRow(ppsGrid, r, "TRAIM:", m_traimLbl);
    makeRow(ppsGrid, r, "TRAIM Error:", m_traimErrLbl);
    ppsGroup->setLayout(ppsGrid);
    leftLayout->addWidget(ppsGroup);

    leftLayout->addStretch();

    // Middle panel - satellites
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

    // Right panel - event log
    auto *evtGroup = new QGroupBox("Events");
    auto *evtLayout = new QVBoxLayout;
    evtLayout->setContentsMargins(8, 12, 8, 8);
    m_eventLog = new QTextEdit;
    m_eventLog->setReadOnly(true);
    m_eventLog->setFontFamily("Cascadia Code");
    m_eventLog->setFontPointSize(9);
    m_eventLog->setPlaceholderText("Signal events...");
    evtLayout->addWidget(m_eventLog);
    evtGroup->setLayout(evtLayout);

    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addWidget(satGroup, 3);
    mainLayout->addWidget(evtGroup, 2);

    // === Signal connections ===

    connect(m_driver, &Teseo::TeseoDriver::fixUpdated,
            this, &InfoPage::onFixUpdated);
    connect(m_driver, &Teseo::TeseoDriver::satellitesUpdated,
            this, &InfoPage::onSatellitesUpdated);
    connect(m_driver, &Teseo::TeseoDriver::accuracyUpdated,
            this, &InfoPage::onAccuracyUpdated);

    connect(m_driver, &Teseo::TeseoDriver::rtcTimeReceived,
            this, [this](const Teseo::RTCData &rtc) {
        m_rtcTimeLbl->setText(rtc.time.toString("HH:mm:ss.zzz"));
        m_rtcDateLbl->setText(rtc.date.toString("dd.MM.yyyy"));
        QString status;
        switch (rtc.status) {
        case 0: status = "Invalid"; break;
        case 1: status = "Stored"; break;
        case 2: status = "Approximate"; break;
        default: status = QString::number(rtc.status);
        }
        m_rtcStatusLbl->setText(status);
        m_eventLog->append(QString("<span style='color:#38bdf8'>%1 RTC: %2 %3</span>")
            .arg(QDateTime::currentDateTime().toString("HH:mm:ss"),
                 rtc.time.toString(), rtc.date.toString()));
    });

    connect(m_driver, &Teseo::TeseoDriver::softwareVersionReceived,
            this, [this](const Teseo::SoftwareVersion &ver) {
        QString v;
        if (!ver.binaryImage.isEmpty()) v = ver.binaryImage;
        else if (!ver.gnssLib.isEmpty()) v = ver.gnssLib;
        else if (!ver.gpsApp.isEmpty()) v = ver.gpsApp;
        m_swVerLbl->setText(v);
        m_eventLog->append(QString("<span style='color:#a78bfa'>%1 VER: %2</span>")
            .arg(QDateTime::currentDateTime().toString("HH:mm:ss"), v));
    });

    connect(m_driver, &Teseo::TeseoDriver::ppsStatusReceived,
            this, [this](const Teseo::PPSStatus &pps) {
        m_ppsOnLbl->setText(pps.on ? "ON" : "OFF");
        m_ppsValidLbl->setText(pps.valid ? "Valid" : "Invalid");
        m_ppsValidLbl->setStyleSheet(pps.valid ?
            "color: #4ade80; font-size: 12px; font-weight: 500;" :
            "color: #f87171; font-size: 12px; font-weight: 500;");
        QString mode;
        switch (pps.outMode) {
        case 0: mode = "Always"; break;
        case 1: mode = "Even"; break;
        case 2: mode = "Odd"; break;
        default: mode = QString::number(pps.outMode);
        }
        m_ppsModeLbl->setText(mode);
    });

    connect(m_driver, &Teseo::TeseoDriver::traimStatusReceived,
            this, [this](const Teseo::TRAIMStatus &traim) {
        QString sol;
        switch (traim.solution) {
        case 0: sol = "Under Alarm"; break;
        case 1: sol = "Over Alarm"; break;
        default: sol = "Unknown";
        }
        m_traimLbl->setText(sol + (traim.enabled ? " (ON)" : " (OFF)"));
        m_traimErrLbl->setText(QString::number(traim.averageError, 'f', 1) + " ns");
    });

    connect(m_driver, &Teseo::TeseoDriver::standbyStatusReceived,
            this, [this](bool enabled) {
        m_standbyLbl->setText(enabled ? "Standby Allowed" : "Active Periodic");
    });

    connect(m_driver, &Teseo::TeseoDriver::uniqueCodeReceived,
            this, [this](const QByteArray &code) {
        m_uniqueCodeLbl->setText(QString::fromLatin1(code));
        m_eventLog->append(QString("<span style='color:#fbbf24'>%1 UID: %2</span>")
            .arg(QDateTime::currentDateTime().toString("HH:mm:ss"),
                 QString::fromLatin1(code)));
    });

    connect(m_driver, &Teseo::TeseoDriver::lowPowerReceived,
            this, [this](const QByteArray &data) {
        m_eventLog->append(QString("<span style='color:#4ade80'>%1 LP: %2</span>")
            .arg(QDateTime::currentDateTime().toString("HH:mm:ss"),
                 QString::fromLatin1(data)));
    });

    connect(m_driver, &Teseo::TeseoDriver::agpsStatusReceived,
            this, [this](const QByteArray &data) {
        m_eventLog->append(QString("<span style='color:#fb923c'>%1 AGPS: %2</span>")
            .arg(QDateTime::currentDateTime().toString("HH:mm:ss"),
                 QString::fromLatin1(data)));
    });

    connect(m_driver, &Teseo::TeseoDriver::pstmMessageReceived,
            this, [this](const QByteArray &msg) {
        if (m_eventLog->document()->blockCount() > 500) {
            QTextCursor c = m_eventLog->textCursor();
            c.movePosition(QTextCursor::Start);
            c.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor, 100);
            c.removeSelectedText();
        }
    });
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
