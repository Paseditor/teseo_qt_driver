// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "teseo_bridge.h"
#include <QSerialPortInfo>

TeseoBridge::TeseoBridge(Teseo::TeseoDriver *driver, QObject *parent)
    : QObject(parent), m_driver(driver)
{
    connect(m_driver, &Teseo::TeseoDriver::connected, this, [this]() { emit connectedChanged(); });
    connect(m_driver, &Teseo::TeseoDriver::disconnected, this, [this]() { emit connectedChanged(); });
    connect(m_driver, &Teseo::TeseoDriver::fixUpdated, this, [this](const Teseo::GnssData &d) {
        m_data = d; emit fixChanged();
    });
    connect(m_driver, &Teseo::TeseoDriver::nmeaSentenceReceived, this, [this](const QByteArray &s) {
        emit nmeaReceived(QString::fromLatin1(s));
    });
    connect(m_driver, &Teseo::TeseoDriver::pstmMessageReceived, this, [this](const QByteArray &m) {
        emit pstmReceived(QString::fromLatin1(m));
    });
    connect(m_driver, &Teseo::TeseoDriver::responseReceived, this, [this](const QByteArray &r) {
        emit responseReceived(QString::fromLatin1(r));
    });
    connect(m_driver, &Teseo::TeseoDriver::errorOccurred, this, &TeseoBridge::errorOccurred);
    connect(m_driver, &Teseo::TeseoDriver::rtcTimeReceived, this, [this](const Teseo::RTCData &rtc) {
        emit rtcTimeReceived(rtc.time.toString("HH:mm:ss.zzz"), rtc.date.toString("dd.MM.yyyy"), rtc.status);
    });
    connect(m_driver, &Teseo::TeseoDriver::parameterReceived, this, [this](int id, const QByteArray &v) {
        emit parameterReceived(id, QString::fromLatin1(v));
    });
    connect(m_driver, &Teseo::TeseoDriver::softwareVersionReceived, this, [this](const Teseo::SoftwareVersion &v) {
        m_swVersion = v.binaryImage.isEmpty() ? v.gnssLib : v.binaryImage;
        emit swVersionChanged();
    });
    connect(m_driver, &Teseo::TeseoDriver::uniqueCodeReceived, this, [this](const QByteArray &c) {
        m_uniqueCode = QString::fromLatin1(c); emit uniqueCodeChanged();
    });
    connect(m_driver, &Teseo::TeseoDriver::agpsStatusReceived, this, [this](const QByteArray &d) {
        emit agpsStatusReceived(QString::fromLatin1(d));
    });
    connect(m_driver, &Teseo::TeseoDriver::lowPowerReceived, this, [this](const QByteArray &d) {
        emit lowPowerReceived(QString::fromLatin1(d));
    });
}

bool TeseoBridge::isConnected() const { return m_driver->isConnected(); }
double TeseoBridge::latitude() const { return m_data.position.latitudeDecimal(); }
double TeseoBridge::longitude() const { return m_data.position.longitudeDecimal(); }
double TeseoBridge::altitude() const { return m_data.position.altitude; }
double TeseoBridge::speedKmh() const { return m_data.velocity.speedKmh; }
double TeseoBridge::course() const { return m_data.velocity.courseTrue; }
int TeseoBridge::fixQuality() const { return static_cast<int>(m_data.fixQuality); }
int TeseoBridge::satellitesUsed() const { return m_data.satellitesUsed; }
double TeseoBridge::hdop() const { return m_data.dop.hdop; }
double TeseoBridge::pdop() const { return m_data.dop.pdop; }
double TeseoBridge::vdop() const { return m_data.dop.vdop; }
double TeseoBridge::ehpe() const { return m_data.accuracy.ehpe; }
bool TeseoBridge::fixValid() const { return m_data.valid; }
QString TeseoBridge::utcTime() const { return m_data.utcDateTime.isValid() ? m_data.utcDateTime.time().toString("HH:mm:ss.zzz") : "---"; }
QString TeseoBridge::utcDate() const { return m_data.utcDateTime.isValid() ? m_data.utcDateTime.date().toString("dd.MM.yyyy") : "---"; }
QString TeseoBridge::swVersion() const { return m_swVersion; }
QString TeseoBridge::uniqueCode() const { return m_uniqueCode; }

QVariantList TeseoBridge::availablePorts()
{
    QVariantList list;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        list.append(QVariantMap{{"name", info.portName()}, {"desc", info.description()}});
    return list;
}

bool TeseoBridge::connectDevice(const QString &port, int baud) { return m_driver->connectDevice(port, baud); }
void TeseoBridge::disconnectDevice() { m_driver->disconnectDevice(); }

QVariantList TeseoBridge::satellitesModel()
{
    QVariantList list;
    for (const auto &s : m_data.satellitesInView)
        list.append(QVariantMap{{"prn", s.prn}, {"elev", s.elevation}, {"azim", s.azimuth}, {"cn0", s.cn0}, {"used", s.usedInFix}});
    return list;
}

bool TeseoBridge::hotStart() { return m_driver->hotStart(); }
bool TeseoBridge::warmStart() { return m_driver->warmStart(); }
bool TeseoBridge::coldStart(int mask) { return m_driver->coldStart(mask); }
bool TeseoBridge::systemReset() { return m_driver->systemReset(); }
bool TeseoBridge::gnssReset() { return m_driver->gnssReset(); }
bool TeseoBridge::gnssSuspend() { return m_driver->gnssSuspend(); }
bool TeseoBridge::gnssRestart() { return m_driver->gnssRestart(); }
bool TeseoBridge::setConstellationMask(int mask) { return m_driver->setConstellationMask(mask); }
bool TeseoBridge::setNmeaOutput(bool en) { return m_driver->setNmeaOutput(en); }
bool TeseoBridge::invalidateGnssFix(bool inv) { return m_driver->invalidateGnssFix(inv); }
bool TeseoBridge::invalidateRtc() { return m_driver->invalidateRtc(); }
bool TeseoBridge::nvmSwap() { return m_driver->nvmSwap(); }
bool TeseoBridge::toggleSbas() { return m_driver->toggleSbas(); }
bool TeseoBridge::setSbasService(int svc) { return m_driver->setSbasService(svc); }
bool TeseoBridge::setSbasSatellite(int prn) { return m_driver->setSbasSatellite(prn); }
bool TeseoBridge::rfTestOn(int satId) { return m_driver->rfTestOn(satId); }
bool TeseoBridge::rfTestOff() { return m_driver->rfTestOff(); }
bool TeseoBridge::setAlgorithmStatus(int type, bool en) { return m_driver->setAlgorithmStatus(type, en); }
bool TeseoBridge::getAlgorithmStatus(int type) { return m_driver->getAlgorithmStatus(type); }
bool TeseoBridge::imuSelfTest() { return m_driver->imuSelfTest(); }
bool TeseoBridge::getSoftwareVersion(int id) { return m_driver->getSoftwareVersion(id); }
bool TeseoBridge::getAllVersions() { return m_driver->getAllVersions(); }
bool TeseoBridge::getRtcTime() { return m_driver->getRtcTime(); }
bool TeseoBridge::getUniqueCode() { return m_driver->getUniqueCode(); }
bool TeseoBridge::selectDatum(int type) { return m_driver->selectDatum(type); }
bool TeseoBridge::enablePositionHold(bool en) { return m_driver->enablePositionHold(en); }
bool TeseoBridge::setNotchFilter(int satType, int mode) { return m_driver->setNotchFilter(satType, mode); }
bool TeseoBridge::setTrackingThresholds(int cn0, double elev) { return m_driver->setTrackingThresholds(cn0, elev); }
bool TeseoBridge::setPositioningThresholds(int cn0, double elev) { return m_driver->setPositioningThresholds(cn0, elev); }
bool TeseoBridge::cfgLog(int en) { return m_driver->cfgLog(en); }
bool TeseoBridge::forceStandby(int dur) { return m_driver->forceStandby(dur); }
bool TeseoBridge::setStandbyEnable(bool en) { return m_driver->setStandbyEnable(en); }
bool TeseoBridge::getStandbyStatus() { return m_driver->getStandbyStatus(); }
bool TeseoBridge::ppsSetOnOff(bool en) { return m_driver->ppsSetOnOff(en); }
bool TeseoBridge::sendCommand(const QString &cmd) { return m_driver->sendCommand(cmd.toLatin1()); }

bool TeseoBridge::getParameter(int block, int id) { return m_driver->getParameter(block, id); }
bool TeseoBridge::setParameter(int block, int id, const QString &val, int mode) { return m_driver->setParameter(block, id, val.toLatin1(), mode); }
bool TeseoBridge::saveParameters() { return m_driver->saveParameters(); }
bool TeseoBridge::restoreFactoryParameters() { return m_driver->restoreFactoryParameters(); }
bool TeseoBridge::setBaudRate(int baud) { return m_driver->setBaudRate(baud); }
bool TeseoBridge::setFixRate(int hz) { return m_driver->setFixRate(hz); }
bool TeseoBridge::cfgConstellations(int gps, int glo, int gal, int bds) {
    Teseo::ConstellationConfig c; c.gps = gps; c.glonass = glo; c.galileo = gal; c.beidou = bds;
    return m_driver->cfgConstellations(c);
}
bool TeseoBridge::cfgGnssThresholds(int trkCn0, int posCn0, int trkAng, int posAng) { return m_driver->cfgGnssThresholds(trkCn0, posCn0, trkAng, posAng); }
bool TeseoBridge::setDifferentialSource(int src) { return m_driver->setDifferentialSource(src); }
bool TeseoBridge::enableRtcm(bool en) { return m_driver->enableRtcm(en); }
bool TeseoBridge::sendRtcmDataHex(const QString &hex) { return m_driver->sendRtcmData(QByteArray::fromHex(hex.toLatin1())); }
bool TeseoBridge::cfgRtcmPort(int port) { return m_driver->cfgRtcmPort(port); }
bool TeseoBridge::cfgRtcmBaudRate(int code) { return m_driver->cfgRtcmBaudRate(code); }
bool TeseoBridge::cfgPortUart(int port, int baud) { return m_driver->cfgPortUart(port, baud); }
bool TeseoBridge::cfgPortI2c(int addr) { return m_driver->cfgPortI2c(addr); }
bool TeseoBridge::cfgMessageList(int id, int rate, const QString &low, const QString &high) {
    return m_driver->cfgMessageList(id, rate, low.toUInt(nullptr, 16), high.toUInt(nullptr, 16));
}
bool TeseoBridge::cfgGnss(int trkCn0, int posCn0, int trkAng, int posAng, int ncoC, int ncoMin, int ncoMax) {
    return m_driver->cfgGnss(trkCn0, posCn0, trkAng, posAng, ncoC, ncoMin, ncoMax);
}
bool TeseoBridge::cfgSbas(int enEng, int enRep, int enAuto, int svc) {
    Teseo::SBASConfig c; c.engineEnabled = enEng; c.reportEnabled = enRep; c.autoSearch = enAuto; c.service = svc;
    return m_driver->cfgSbas(c);
}
bool TeseoBridge::cfgPpsGeneral(bool en, int mode, int clock, int ref) { return m_driver->cfgPpsGeneral(en, mode, clock, ref); }
bool TeseoBridge::cfgPpsSatellite(int mix, int fix, int minSat, int elev) { return m_driver->cfgPpsSatellite(mix, fix, minSat, elev); }
bool TeseoBridge::cfgPpsPulse(bool inv, double dur, double corr) { return m_driver->cfgPpsPulse(inv, dur, corr); }
bool TeseoBridge::cfgPositionHold(bool en, double lat, double lon, double hei) { return m_driver->cfgPositionHold(en, lat, lon, hei); }
bool TeseoBridge::cfgTraim(bool en, double thr) { return m_driver->cfgTraim(en, thr); }
bool TeseoBridge::cfgSatCompensation(int path, double comp) { return m_driver->cfgSatCompensation(path, comp); }
bool TeseoBridge::cfgLowPowerAlgorithm(int en, int feat, int fixP, int fixOn, int noFix, int noFix2, int noFixOff, int adaptFeat, int adaptDuty, int ehpeTh, int numSat, int dutyOff, int constType) {
    return m_driver->cfgLowPowerAlgorithm(en, feat, fixP, fixOn, noFix, noFix2, noFixOff, adaptFeat, adaptDuty, ehpeTh, numSat, dutyOff, constType);
}
bool TeseoBridge::cfgAgps(bool en) { return m_driver->cfgAgps(en); }
bool TeseoBridge::cfgAntiJamming(int gps, int glo) { return m_driver->cfgAntiJamming(gps, glo); }
bool TeseoBridge::cfgOdometer(bool en, bool msg, int alarm) { return m_driver->cfgOdometer(en, msg, alarm); }
bool TeseoBridge::cfgGeofence(bool en, int tol) { return m_driver->cfgGeofence(en, tol); }
bool TeseoBridge::cfgGeofenceCircle(int id, bool en, double lat, double lon, double rad) { return m_driver->cfgGeofenceCircle(id, en, lat, lon, rad); }
bool TeseoBridge::cfgTimeData(int minW, int maxW, int rate, int utc) { return m_driver->cfgTimeData(minW, maxW, rate, utc); }
bool TeseoBridge::setFrequencyRange(int minHz, int maxHz) { return m_driver->setFrequencyRange(minHz, maxHz); }

bool TeseoBridge::initGps(double lat, const QString &latRef, double lon, const QString &lonRef, double alt, const QDate &date, const QTime &time) {
    return m_driver->initGps(lat, latRef.at(0).toLatin1(), lon, lonRef.at(0).toLatin1(), alt, date, time);
}
bool TeseoBridge::initTime(const QDate &date, const QTime &time) { return m_driver->initTime(date, time); }
bool TeseoBridge::initFrequency(int offset) { return m_driver->initFrequency(offset); }
bool TeseoBridge::stagpsOnOff(bool en) { return m_driver->stagpsOnOff(en); }
bool TeseoBridge::stagpsGetStatus() { return m_driver->stagpsGetStatus(); }
bool TeseoBridge::stagpsInvalidate(int param) { return m_driver->stagpsInvalidate(param); }
bool TeseoBridge::stagpsSetConstellationMask(int mask) { return m_driver->stagpsSetConstellationMask(mask); }
bool TeseoBridge::stagpsGeneratePassword(int time, const QString &vendor, const QString &dev) {
    return m_driver->stagpsGeneratePassword(time, vendor.toLatin1(), dev.toLatin1());
}
bool TeseoBridge::loadAlmanac(int satId, const QString &hex) { return m_driver->loadAlmanac(satId, hex.toLatin1()); }
bool TeseoBridge::loadEphemeris(int satId, const QString &hex) { return m_driver->loadEphemeris(satId, hex.toLatin1()); }
bool TeseoBridge::dumpAlmanacs() { return m_driver->dumpAlmanacs(); }
bool TeseoBridge::clearAlmanacs() { return m_driver->clearAlmanacs(); }
bool TeseoBridge::dumpEphemeris() { return m_driver->dumpEphemeris(); }
bool TeseoBridge::clearEphemeris() { return m_driver->clearEphemeris(); }
bool TeseoBridge::setGalileoGgto(int brd, int wn, int t0, int a0, int a1, bool val) { return m_driver->setGalileoGgto(brd, wn, t0, a0, a1, val); }
bool TeseoBridge::dumpGalileoGgto() { return m_driver->dumpGalileoGgto(); }
bool TeseoBridge::setIonoParams(int satType, const QVariantList &params) {
    QVector<int> p; for (const QVariant &v : params) p.append(v.toInt());
    return m_driver->setIonoParams(satType, p);
}

bool TeseoBridge::sendMapMatchingFeedback(const QString &ts, bool latV, bool lonV, double lat, double lon, double hErr, double lonErr) {
    return m_driver->sendMapMatchingFeedback(ts.toLatin1(), latV, lonV, lat, lon, 0, 0, hErr, lonErr);
}
bool TeseoBridge::sendSensorMessage(int id, int x, int y, int z) { return m_driver->sendSensorMessage(id, {x, y, z}); }
bool TeseoBridge::drCalibrateTilt() { return m_driver->drCalibrateTilt(); }
bool TeseoBridge::drSaveToNvm() { return m_driver->drSaveToNvm(); }
bool TeseoBridge::cfgOdometerSimple(bool en) { return m_driver->cfgOdometer(en, false, 0); }
