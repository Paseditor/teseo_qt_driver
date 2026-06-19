// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef INFOPAGE_H
#define INFOPAGE_H

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QTextEdit>

#include "teseo_driver.h"

class InfoPage : public QWidget
{
    Q_OBJECT
public:
    explicit InfoPage(Teseo::TeseoDriver *driver, QWidget *parent = nullptr);

private slots:
    void onFixUpdated(const Teseo::GnssData &data);
    void onSatellitesUpdated(const QVector<Teseo::Satellite> &sats);
    void onAccuracyUpdated(const Teseo::Accuracy &acc);

private:
    Teseo::TeseoDriver *m_driver;
    QLabel *m_latLbl, *m_lonLbl, *m_altLbl;
    QLabel *m_speedLbl, *m_courseLbl, *m_fixLbl, *m_satsLbl;
    QLabel *m_hdopLbl, *m_pdopLbl, *m_vdopLbl, *m_ehpeLbl;
    QLabel *m_timeLbl, *m_dateLbl;
    QLabel *m_rtcTimeLbl, *m_rtcDateLbl, *m_rtcStatusLbl;
    QLabel *m_swVerLbl;
    QLabel *m_ppsOnLbl, *m_ppsValidLbl, *m_ppsModeLbl;
    QLabel *m_traimLbl, *m_traimErrLbl;
    QLabel *m_standbyLbl;
    QLabel *m_uniqueCodeLbl;
    QTableWidget *m_satTable;
    QTextEdit *m_eventLog;
};

#endif
