// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TESEO_TYPES_H
#define TESEO_TYPES_H

#include <QString>
#include <QVector>
#include <QDateTime>

namespace Teseo {

enum class FixQuality {
    Invalid = 0,
    GPS = 1,
    DGPS = 2,
    Estimated = 6
};

enum class Constellation {
    GPS = 0,
    GLONASS = 1,
    Galileo = 2,
    BeiDou = 3,
    QZSS = 4,
    Unknown = 255
};

struct Satellite {
    int prn = 0;
    int elevation = 0;
    int azimuth = 0;
    int cn0 = 0;
    Constellation constellation = Constellation::Unknown;
    bool usedInFix = false;
};

struct Position {
    double latitude = 0.0;   // DDMM.MMMMM
    double longitude = 0.0;  // DDDMM.MMMMM
    double altitude = 0.0;
    double geoidSeparation = 0.0;
    char latDirection = 'N';
    char lonDirection = 'E';
    bool valid = false;

    double latitudeDecimal() const {
        double deg = static_cast<int>(latitude / 100);
        double min = latitude - deg * 100;
        double dec = deg + min / 60.0;
        return (latDirection == 'S') ? -dec : dec;
    }

    double longitudeDecimal() const {
        double deg = static_cast<int>(longitude / 100);
        double min = longitude - deg * 100;
        double dec = deg + min / 60.0;
        return (lonDirection == 'W') ? -dec : dec;
    }
};

struct Velocity {
    double speedKnots = 0.0;
    double speedKmh = 0.0;
    double courseTrue = 0.0;
    double courseMagnetic = 0.0;
};

struct DOP {
    double pdop = 99.0;
    double hdop = 99.0;
    double vdop = 99.0;
};

struct Accuracy {
    double ehpe = 0.0;
    double semiMajor = 0.0;
    double semiMinor = 0.0;
    double angle = 0.0;
    double latErr = 0.0;
    double lonErr = 0.0;
    double altErr = 0.0;
};

struct GnssData {
    Position position;
    Velocity velocity;
    DOP dop;
    Accuracy accuracy;
    QDateTime utcDateTime;
    FixQuality fixQuality = FixQuality::Invalid;
    int satellitesUsed = 0;
    QVector<Satellite> satellitesInView;
    QVector<int> usedSatPRNs;
    bool valid = false;
};

struct LowPowerConfig {
    bool enabled = false;
    int constellationMask = 0;
    int ehpeThreshold = 15;
    int maxTrackedSats = 9;
    bool switchConstellation = false;
    bool dutyCycleEnabled = false;
    int dutyCycleMsOff = 700;
    int periodicMode = 0; // 0=off, 3=standby
    int fixPeriod = 10;
    int fixOnTime = 1;
    bool ephemerisRefresh = true;
    bool rtcCalibration = true;
    int noFixCnt = 8;
    int noFixOff = 180;
};

struct PPSConfig {
    bool enabled = false;
    int outMode = 0;        // 0=always, 1=even, 2=odd
    int referenceTime = 0;  // 0=UTC, 1=GPS, 2=GLONASS, ...
    int pulseDelayNs = 0;
    double pulseDurationS = 0.0;
    int pulsePolarity = 0;  // 0=normal, 1=inverted
    int fixCondition = 3;   // 1=noFix, 2=2D, 3=3D
    int satThreshold = 4;
    int elevationMask = 5;
    int constellationMask = 0;
};

struct PPSStatus {
    bool on = false;
    bool valid = false;
    bool synchValid = false;
    int outMode = 0;
    int refTime = 0;
    int refConstellation = 0;
    double pulseDuration = 0.0;
    int pulseDelay = 0;
    int fixStatus = 0;
    int usedSats = 0;
};

struct TRAIMStatus {
    bool enabled = false;
    int solution = 0;  // 0=under alarm, 1=over, 2=unknown
    double averageError = 0.0;
    int usedSats = 0;
    int removedSats = 0;
};

struct GeofenceCircle {
    int id = 0;
    bool enabled = false;
    double latitude = 0.0;
    double longitude = 0.0;
    double radius = 0.0;
};

struct RTCData {
    QTime time;
    QDate date;
    int status = 0;       // 0=invalid, 1=stored, 2=approximate
    int timeValidity = 0; // 0=no_time ... 8=position_time
};

struct SoftwareVersion {
    QString gnssLib;
    QString os20Lib;
    QString gpsApp;
    QString binaryImage;
    QString swConfig;
    QString chipVersion;
    QString productId;
};

struct OdometerConfig {
    bool enabled = false;
    bool messagesEnabled = false;
    int alarmDistance = 0;
};

struct AntiJammingConfig {
    int gpsMode = 0;     // 0=off, 1=normal, 2=auto
    int glonassMode = 0;
};

struct SBASConfig {
    bool engineEnabled = false;
    bool reportEnabled = false;
    bool autoSearch = false;
    int service = 15; // 0=WAAS, 1=EGNOS, 2=MSAS, 3=GAGAN, 4=SDCM, 7=OFF, 15=AUTO
};

struct ConstellationConfig {
    int gps = 3;     // 1=off, 2=track, 3=use
    int glonass = 3;
    int galileo = 1;
    int qzss = 1;
    int beidou = 1;
};

struct GNSSThresholds {
    int trkCn0 = 0;
    int posCn0 = 0;
    int trkMaskAngle = 0;
    int posMaskAngle = 0;
};

} // namespace Teseo

Q_DECLARE_METATYPE(Teseo::GnssData)
Q_DECLARE_METATYPE(Teseo::Position)
Q_DECLARE_METATYPE(Teseo::Satellite)
Q_DECLARE_METATYPE(Teseo::Velocity)
Q_DECLARE_METATYPE(Teseo::DOP)
Q_DECLARE_METATYPE(Teseo::Accuracy)
Q_DECLARE_METATYPE(Teseo::RTCData)
Q_DECLARE_METATYPE(Teseo::SoftwareVersion)

#endif // TESEO_TYPES_H
