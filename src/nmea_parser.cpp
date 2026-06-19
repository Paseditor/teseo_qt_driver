// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#include "nmea_parser.h"
#include <QDateTime>

namespace Teseo {

NmeaParser::NmeaParser(QObject *parent)
    : QObject(parent)
{
    registerHandlers();
}

void NmeaParser::registerHandlers()
{
    m_handlers["GGA"] = [this](const QVector<QByteArray> &f) { parseGGA(f); };
    m_handlers["RMC"] = [this](const QVector<QByteArray> &f) { parseRMC(f); };
    m_handlers["GSA"] = [this](const QVector<QByteArray> &f) { parseGSA(f); };
    m_handlers["GSV"] = [this](const QVector<QByteArray> &f) { parseGSV(f); };
    m_handlers["VTG"] = [this](const QVector<QByteArray> &f) { parseVTG(f); };
    m_handlers["ZDA"] = [this](const QVector<QByteArray> &f) { parseZDA(f); };
    m_handlers["GST"] = [this](const QVector<QByteArray> &f) { parseGST(f); };
}

void NmeaParser::processData(const QByteArray &data)
{
    m_buffer.append(data);

    while (true) {
        int start = m_buffer.indexOf('$');
        if (start < 0) {
            m_buffer.clear();
            break;
        }

        int end = m_buffer.indexOf("\r\n", start);
        if (end < 0) {
            if (start > 0)
                m_buffer = m_buffer.mid(start);
            break;
        }

        QByteArray sentence = m_buffer.mid(start, end - start);
        m_buffer = m_buffer.mid(end + 2);

        if (!sentence.isEmpty())
            processSentence(sentence);
    }
}

void NmeaParser::processSentence(const QByteArray &sentence)
{
    emit nmeaSentenceReceived(sentence);

    if (!validateChecksum(sentence))
        return;

    if (sentence.startsWith("$PSTM")) {
        parsePSTM(sentence);
        return;
    }

    QVector<QByteArray> fields = splitSentence(sentence);
    if (fields.size() < 2)
        return;

    QByteArray id = fields[0];
    if (id.size() < 3)
        return;

    QByteArray suffix = id.mid(id.size() - 3);
    auto it = m_handlers.find(suffix);
    if (it != m_handlers.end())
        it.value()(fields);
}

bool NmeaParser::validateChecksum(const QByteArray &sentence)
{
    int starPos = sentence.indexOf('*');
    if (starPos < 0 || starPos + 3 > sentence.size())
        return false;

    QByteArray payload = sentence.mid(1, starPos - 1);
    QByteArray expected = sentence.mid(starPos + 1, 2).toUpper();

    quint8 checksum = 0;
    for (char c : payload)
        checksum ^= static_cast<quint8>(c);

    QByteArray computed = QByteArray::number(checksum, 16).rightJustified(2, '0').toUpper();
    return computed == expected;
}

QByteArray NmeaParser::computeChecksum(const QByteArray &payload)
{
    quint8 checksum = 0;
    for (char c : payload)
        checksum ^= static_cast<quint8>(c);
    return QByteArray::number(checksum, 16).rightJustified(2, '0').toUpper();
}

QVector<QByteArray> NmeaParser::splitSentence(const QByteArray &sentence)
{
    QByteArray body;
    int starPos = sentence.indexOf('*');
    if (starPos >= 0)
        body = sentence.mid(1, starPos - 1);
    else
        body = sentence.mid(1);

    QList<QByteArray> list = body.split(',');
    return QVector<QByteArray>(list.begin(), list.end());
}

Constellation NmeaParser::constellationFromTalker(const QByteArray &talker) const
{
    if (talker == "GP") return Constellation::GPS;
    if (talker == "GL") return Constellation::GLONASS;
    if (talker == "GA") return Constellation::Galileo;
    if (talker == "BD") return Constellation::BeiDou;
    if (talker == "QZ") return Constellation::QZSS;
    return Constellation::GPS;
}

// =====================================================
// Standard NMEA parsers
// =====================================================

void NmeaParser::parseGGA(const QVector<QByteArray> &fields)
{
    if (fields.size() < 15) return;

    QByteArray ts = fields[1];
    if (ts.size() >= 6) {
        int h = ts.mid(0, 2).toInt();
        int m = ts.mid(2, 2).toInt();
        int s = ts.mid(4, 2).toInt();
        int ms = (ts.size() > 7) ? ts.mid(7).leftJustified(3, '0').left(3).toInt() : 0;
        QTime time(h, m, s, ms);
        if (m_data.utcDateTime.date().isValid())
            m_data.utcDateTime.setTime(time);
        else
            m_data.utcDateTime = QDateTime(QDate::currentDate(), time);
    }

    if (!fields[2].isEmpty()) {
        m_data.position.latitude = fields[2].toDouble();
        m_data.position.latDirection = fields[3].isEmpty() ? 'N' : fields[3][0];
    }
    if (!fields[4].isEmpty()) {
        m_data.position.longitude = fields[4].toDouble();
        m_data.position.lonDirection = fields[5].isEmpty() ? 'E' : fields[5][0];
    }

    m_data.fixQuality = static_cast<FixQuality>(fields[6].toInt());
    m_data.satellitesUsed = fields[7].toInt();
    m_data.dop.hdop = fields[8].toDouble();
    m_data.position.altitude = fields[9].toDouble();
    m_data.position.geoidSeparation = fields[11].toDouble();
    m_data.position.valid = (m_data.fixQuality != FixQuality::Invalid);
    m_data.valid = m_data.position.valid;

    emit fixUpdated(m_data);
    emit positionUpdated(m_data.position);
}

void NmeaParser::parseRMC(const QVector<QByteArray> &fields)
{
    if (fields.size() < 13) return;

    QByteArray ts = fields[1];
    if (ts.size() >= 6) {
        int h = ts.mid(0, 2).toInt();
        int m = ts.mid(2, 2).toInt();
        int s = ts.mid(4, 2).toInt();
        int ms = (ts.size() > 7) ? ts.mid(7).leftJustified(3, '0').left(3).toInt() : 0;
        m_data.utcDateTime.setTime(QTime(h, m, s, ms));
    }

    QByteArray dateStr = fields[9];
    if (dateStr.size() >= 6) {
        int day = dateStr.mid(0, 2).toInt();
        int month = dateStr.mid(2, 2).toInt();
        int year = 2000 + dateStr.mid(4, 2).toInt();
        m_data.utcDateTime.setDate(QDate(year, month, day));
    }

    if (!fields[3].isEmpty()) {
        m_data.position.latitude = fields[3].toDouble();
        m_data.position.latDirection = fields[4].isEmpty() ? 'N' : fields[4][0];
    }
    if (!fields[5].isEmpty()) {
        m_data.position.longitude = fields[5].toDouble();
        m_data.position.lonDirection = fields[6].isEmpty() ? 'E' : fields[6][0];
    }

    m_data.velocity.speedKnots = fields[7].toDouble();
    m_data.velocity.speedKmh = m_data.velocity.speedKnots * 1.852;
    m_data.velocity.courseTrue = fields[8].toDouble();

    if (fields[2] == "A") m_data.valid = true;

    emit velocityUpdated(m_data.velocity);
}

void NmeaParser::parseGSA(const QVector<QByteArray> &fields)
{
    if (fields.size() < 18) return;

    m_data.usedSatPRNs.clear();
    for (int i = 3; i <= 14; ++i) {
        if (!fields[i].isEmpty()) {
            int prn = fields[i].toInt();
            if (prn > 0) m_data.usedSatPRNs.append(prn);
        }
    }

    m_data.dop.pdop = fields[15].toDouble();
    m_data.dop.hdop = fields[16].toDouble();
    m_data.dop.vdop = fields[17].toDouble();

    emit dopUpdated(m_data.dop);

    for (auto &sat : m_data.satellitesInView)
        sat.usedInFix = m_data.usedSatPRNs.contains(sat.prn);
}

void NmeaParser::parseGSV(const QVector<QByteArray> &fields)
{
    if (fields.size() < 4) return;

    int totalMessages = fields[1].toInt();
    int msgNumber = fields[2].toInt();

    if (msgNumber == 1) {
        m_pendingGSV.clear();
        m_expectedGSVCount = totalMessages;
        m_receivedGSVCount = 0;
    }

    QByteArray talker = fields[0].mid(1, 2);
    Constellation c = constellationFromTalker(talker);

    int satCount = (fields.size() - 4) / 4;
    for (int i = 0; i < satCount; ++i) {
        int base = 4 + i * 4;
        if (base + 3 >= fields.size()) break;
        Satellite sat;
        sat.prn = fields[base].toInt();
        sat.elevation = fields[base + 1].toInt();
        sat.azimuth = fields[base + 2].toInt();
        sat.cn0 = fields[base + 3].toInt();
        sat.constellation = c;
        sat.usedInFix = m_data.usedSatPRNs.contains(sat.prn);
        if (sat.prn > 0) m_pendingGSV.append(sat);
    }

    m_receivedGSVCount++;
    if (m_receivedGSVCount >= m_expectedGSVCount) {
        QVector<Satellite> merged;
        for (const auto &s : m_data.satellitesInView)
            if (s.constellation != c) merged.append(s);
        merged.append(m_pendingGSV);
        m_data.satellitesInView = merged;
        emit satellitesUpdated(m_data.satellitesInView);
    }
}

void NmeaParser::parseVTG(const QVector<QByteArray> &fields)
{
    if (fields.size() < 10) return;
    m_data.velocity.courseTrue = fields[1].toDouble();
    m_data.velocity.courseMagnetic = fields[3].toDouble();
    m_data.velocity.speedKnots = fields[5].toDouble();
    m_data.velocity.speedKmh = fields[7].toDouble();
    emit velocityUpdated(m_data.velocity);
}

void NmeaParser::parseZDA(const QVector<QByteArray> &fields)
{
    if (fields.size() < 5) return;
    QByteArray ts = fields[1];
    if (ts.size() >= 6) {
        int h = ts.mid(0, 2).toInt();
        int m = ts.mid(2, 2).toInt();
        int s = ts.mid(4, 2).toInt();
        int ms = (ts.size() > 7) ? ts.mid(7).leftJustified(3, '0').left(3).toInt() : 0;
        m_data.utcDateTime.setTime(QTime(h, m, s, ms));
    }
    int day = fields[2].toInt();
    int month = fields[3].toInt();
    int year = fields[4].toInt();
    if (day > 0 && month > 0 && year > 0)
        m_data.utcDateTime.setDate(QDate(year, month, day));
}

void NmeaParser::parseGST(const QVector<QByteArray> &fields)
{
    if (fields.size() < 9) return;
    m_data.accuracy.ehpe = fields[2].toDouble();
    m_data.accuracy.semiMajor = fields[3].toDouble();
    m_data.accuracy.semiMinor = fields[4].toDouble();
    m_data.accuracy.angle = fields[5].toDouble();
    m_data.accuracy.latErr = fields[6].toDouble();
    m_data.accuracy.lonErr = fields[7].toDouble();
    m_data.accuracy.altErr = fields[8].toDouble();
    emit accuracyUpdated(m_data.accuracy);
}

// =====================================================
// PSTM proprietary message parser
// =====================================================

void NmeaParser::parsePSTM(const QByteArray &sentence)
{
    emit pstmMessageReceived(sentence);

    QVector<QByteArray> fields = splitSentence(sentence);
    if (fields.isEmpty()) return;

    QByteArray cmd = fields[0];

    if (cmd == "$PSTMVER") {
        parsePSTMVER(fields);
    } else if (cmd == "$PSTMGETRTCTIME") {
        parsePSTMGETRTCTIME(fields);
    } else if (cmd == "$PSTMPPS" && fields.size() > 1 && fields[1] == "1") {
        parsePSTMPPS(fields);
    } else if (cmd == "$PSTMSTANDBYENABLE") {
        parsePSTMSTANDBYENABLE(fields);
    } else if (cmd == "$PSTMSET") {
        parsePSTMSET(fields);
    } else if (cmd == "$PSTMLOWPOWERON") {
        parsePSTMLOWPOWERON(fields);
    } else if (cmd == "$PSTMAGPSSTATUS") {
        parsePSTMAGPSSTATUS(fields);
    } else if (cmd == "$PSTMGETUCODEOK") {
        parsePSTMGETUCODEOK(fields);
    }
}

void NmeaParser::parsePSTMVER(const QVector<QByteArray> &fields)
{
    if (fields.size() < 2) return;
    QString ver = QString::fromLatin1(fields[1]);

    if (ver.contains("GNSSLIB")) m_swVersion.gnssLib = ver;
    else if (ver.contains("OS20LIB")) m_swVersion.os20Lib = ver;
    else if (ver.contains("GPSAPP")) m_swVersion.gpsApp = ver;
    else if (ver.contains("BINIMG")) m_swVersion.binaryImage = ver;
    else if (ver.contains("SWCFG")) m_swVersion.swConfig = ver;
    else if (ver.contains("STA80")) m_swVersion.chipVersion = ver;
    else if (ver.contains("PID")) m_swVersion.productId = ver;

    emit softwareVersionReceived(m_swVersion);
}

void NmeaParser::parsePSTMGETRTCTIME(const QVector<QByteArray> &fields)
{
    if (fields.size() < 5) return;

    RTCData rtc;

    QByteArray ts = fields[1];
    if (ts.size() >= 6) {
        int h = ts.mid(0, 2).toInt();
        int m = ts.mid(2, 2).toInt();
        int s = ts.mid(4, 2).toInt();
        int ms = (ts.size() > 7) ? ts.mid(7).leftJustified(3, '0').left(3).toInt() : 0;
        rtc.time = QTime(h, m, s, ms);
    }

    QByteArray ds = fields[2];
    if (ds.size() >= 6) {
        int day = ds.mid(0, 2).toInt();
        int month = ds.mid(2, 2).toInt();
        int year = 2000 + ds.mid(4, 2).toInt();
        rtc.date = QDate(year, month, day);
    }

    rtc.status = fields[3].toInt();
    rtc.timeValidity = fields[4].toInt();

    emit rtcTimeReceived(rtc);
}

void NmeaParser::parsePSTMPPS(const QVector<QByteArray> &fields)
{
    if (fields.size() < 7) return;

    PPSStatus pps;
    // cmd_type = fields[2]
    // params start at fields[3]
    if (fields.size() > 3) pps.on = (fields[3].toInt() != 0);
    if (fields.size() > 4) pps.valid = (fields[4].toInt() != 0);
    if (fields.size() > 5) pps.synchValid = (fields[5].toInt() != 0);
    if (fields.size() > 6) pps.outMode = fields[6].toInt();

    emit ppsStatusReceived(pps);
}

void NmeaParser::parsePSTMSTANDBYENABLE(const QVector<QByteArray> &fields)
{
    if (fields.size() >= 2)
        emit standbyStatusReceived(fields[1].toInt() != 0);
}

void NmeaParser::parsePSTMSET(const QVector<QByteArray> &fields)
{
    if (fields.size() < 3) return;
    // $PSTMSET,<id>,<value>
    int id = fields[1].toInt();
    QByteArray value = fields[2];
    for (int i = 3; i < fields.size(); ++i)
        value += "," + fields[i];
    emit parameterReceived(id, value);
}

void NmeaParser::parsePSTMLOWPOWERON(const QVector<QByteArray> &fields)
{
    Q_UNUSED(fields);
    emit lowPowerReceived("$PSTMLOWPOWERON");
}

void NmeaParser::parsePSTMAGPSSTATUS(const QVector<QByteArray> &fields)
{
    Q_UNUSED(fields);
    emit agpsStatusReceived("$PSTMAGPSSTATUS");
}

void NmeaParser::parsePSTMGETUCODEOK(const QVector<QByteArray> &fields)
{
    if (fields.size() >= 2)
        emit uniqueCodeReceived(fields[1]);
}

} // namespace Teseo
