// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <QObject>
#include <QByteArray>
#include <QHash>
#include <functional>

#include "teseo_types.h"

namespace Teseo {

class NmeaParser : public QObject
{
    Q_OBJECT

public:
    explicit NmeaParser(QObject *parent = nullptr);

    void processData(const QByteArray &data);
    void processSentence(const QByteArray &sentence);

    static bool validateChecksum(const QByteArray &sentence);
    static QByteArray computeChecksum(const QByteArray &payload);

    GnssData currentData() const { return m_data; }

signals:
    void positionUpdated(const Teseo::Position &position);
    void velocityUpdated(const Teseo::Velocity &velocity);
    void satellitesUpdated(const QVector<Teseo::Satellite> &satellites);
    void dopUpdated(const Teseo::DOP &dop);
    void accuracyUpdated(const Teseo::Accuracy &accuracy);
    void fixUpdated(const Teseo::GnssData &data);
    void nmeaSentenceReceived(const QByteArray &sentence);
    void pstmMessageReceived(const QByteArray &message);

    void rtcTimeReceived(const Teseo::RTCData &rtc);
    void softwareVersionReceived(const Teseo::SoftwareVersion &ver);
    void ppsStatusReceived(const Teseo::PPSStatus &pps);
    void traimStatusReceived(const Teseo::TRAIMStatus &traim);
    void standbyStatusReceived(bool enabled);
    void lowPowerReceived(const QByteArray &data);
    void agpsStatusReceived(const QByteArray &data);
    void parameterReceived(int id, const QByteArray &value);
    void uniqueCodeReceived(const QByteArray &code);

private:
    using SentenceHandler = std::function<void(const QVector<QByteArray> &)>;

    void registerHandlers();
    void parseGGA(const QVector<QByteArray> &fields);
    void parseRMC(const QVector<QByteArray> &fields);
    void parseGSA(const QVector<QByteArray> &fields);
    void parseGSV(const QVector<QByteArray> &fields);
    void parseVTG(const QVector<QByteArray> &fields);
    void parseZDA(const QVector<QByteArray> &fields);
    void parseGST(const QVector<QByteArray> &fields);
    void parseGBS(const QVector<QByteArray> &fields);
    void parseGNS(const QVector<QByteArray> &fields);
    void parseDTM(const QVector<QByteArray> &fields);
    void parseGLL(const QVector<QByteArray> &fields);
    void parsePSTM(const QByteArray &sentence);

    void parsePSTMVER(const QVector<QByteArray> &fields);
    void parsePSTMGETRTCTIME(const QVector<QByteArray> &fields);
    void parsePSTMPPS(const QVector<QByteArray> &fields);
    void parsePSTMSTANDBYENABLE(const QVector<QByteArray> &fields);
    void parsePSTMSET(const QVector<QByteArray> &fields);
    void parsePSTMLOWPOWERON(const QVector<QByteArray> &fields);
    void parsePSTMAGPSSTATUS(const QVector<QByteArray> &fields);
    void parsePSTMGETUCODEOK(const QVector<QByteArray> &fields);

    QVector<QByteArray> splitSentence(const QByteArray &sentence);
    Constellation constellationFromTalker(const QByteArray &talker) const;

    QByteArray m_buffer;
    GnssData m_data;
    QHash<QByteArray, SentenceHandler> m_handlers;
    QVector<Satellite> m_pendingGSV;
    int m_expectedGSVCount = 0;
    int m_receivedGSVCount = 0;
    SoftwareVersion m_swVersion;
};

} // namespace Teseo

#endif // NMEA_PARSER_H
