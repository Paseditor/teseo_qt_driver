// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "teseo_driver.h"

namespace Teseo {

TeseoDriver::TeseoDriver(QObject *parent)
    : QObject(parent)
    , m_serial(new SerialInterface(this))
    , m_parser(new NmeaParser(this))
{
    connect(m_serial, &SerialInterface::dataReceived,
            this, &TeseoDriver::onDataReceived);
    connect(m_serial, &SerialInterface::errorOccurred,
            this, &TeseoDriver::onSerialError);
    connect(m_serial, &SerialInterface::connected,
            this, &TeseoDriver::connected);
    connect(m_serial, &SerialInterface::disconnected,
            this, &TeseoDriver::disconnected);

    connect(m_parser, &NmeaParser::positionUpdated,
            this, &TeseoDriver::positionUpdated);
    connect(m_parser, &NmeaParser::velocityUpdated,
            this, &TeseoDriver::velocityUpdated);
    connect(m_parser, &NmeaParser::satellitesUpdated,
            this, &TeseoDriver::satellitesUpdated);
    connect(m_parser, &NmeaParser::dopUpdated,
            this, &TeseoDriver::dopUpdated);
    connect(m_parser, &NmeaParser::accuracyUpdated,
            this, &TeseoDriver::accuracyUpdated);
    connect(m_parser, &NmeaParser::fixUpdated,
            this, [this](const GnssData &data) {
                m_lastData = data;
                emit fixUpdated(data);
            });
    connect(m_parser, &NmeaParser::nmeaSentenceReceived,
            this, &TeseoDriver::nmeaSentenceReceived);
    connect(m_parser, &NmeaParser::pstmMessageReceived,
            this, &TeseoDriver::pstmMessageReceived);
    connect(m_parser, &NmeaParser::rtcTimeReceived,
            this, &TeseoDriver::rtcTimeReceived);
    connect(m_parser, &NmeaParser::softwareVersionReceived,
            this, &TeseoDriver::softwareVersionReceived);
    connect(m_parser, &NmeaParser::ppsStatusReceived,
            this, &TeseoDriver::ppsStatusReceived);
    connect(m_parser, &NmeaParser::traimStatusReceived,
            this, &TeseoDriver::traimStatusReceived);
    connect(m_parser, &NmeaParser::standbyStatusReceived,
            this, &TeseoDriver::standbyStatusReceived);
    connect(m_parser, &NmeaParser::lowPowerReceived,
            this, &TeseoDriver::lowPowerReceived);
    connect(m_parser, &NmeaParser::agpsStatusReceived,
            this, &TeseoDriver::agpsStatusReceived);
    connect(m_parser, &NmeaParser::parameterReceived,
            this, &TeseoDriver::parameterReceived);
    connect(m_parser, &NmeaParser::uniqueCodeReceived,
            this, &TeseoDriver::uniqueCodeReceived);
}

TeseoDriver::~TeseoDriver()
{
    disconnectDevice();
}

bool TeseoDriver::connectDevice(const QString &portName, qint32 baudRate)
{
    return m_serial->open(portName, baudRate);
}

void TeseoDriver::disconnectDevice()
{
    m_serial->close();
}

bool TeseoDriver::isConnected() const
{
    return m_serial->isOpen();
}

GnssData TeseoDriver::currentData() const
{
    return m_lastData;
}

QVector<Satellite> TeseoDriver::satellites() const
{
    return m_lastData.satellitesInView;
}

// =====================================================
// 10.1 ST NMEA command specifications
// =====================================================

bool TeseoDriver::initGps(double lat, char latRef, double lon, char lonRef,
                           double alt, const QDate &date, const QTime &time)
{
    QByteArray cmd = "$PSTMINITGPS,";
    cmd += QByteArray::number(lat, 'f', 3);
    cmd += ',';
    cmd += latRef;
    cmd += ',';
    cmd += QByteArray::number(lon, 'f', 3);
    cmd += ',';
    cmd += lonRef;
    cmd += ',';
    cmd += QByteArray::number(static_cast<int>(alt));
    cmd += ',';
    cmd += QByteArray::number(date.day()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(date.month()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(date.year());
    cmd += ',';
    cmd += QByteArray::number(time.hour()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(time.minute()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(time.second()).rightJustified(2, '0');
    return sendCommand(cmd);
}

bool TeseoDriver::initTime(const QDate &date, const QTime &time)
{
    QByteArray cmd = "$PSTMINITTIME,";
    cmd += QByteArray::number(date.day()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(date.month()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(date.year());
    cmd += ',';
    cmd += QByteArray::number(time.hour()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(time.minute()).rightJustified(2, '0');
    cmd += ',';
    cmd += QByteArray::number(time.second()).rightJustified(2, '0');
    return sendCommand(cmd);
}

bool TeseoDriver::initFrequency(int offsetHz)
{
    return sendCommand("$PSTMINITFRQ," + QByteArray::number(offsetHz));
}

bool TeseoDriver::setFrequencyRange(int minHz, int maxHz)
{
    return sendCommand("$PSTMSETRANGE," + QByteArray::number(minHz) +
                       "," + QByteArray::number(maxHz));
}

bool TeseoDriver::loadAlmanac(int satId, const QByteArray &hexData)
{
    int byteCount = hexData.size() / 2;
    return sendCommand("$PSTMALMANAC," + QByteArray::number(satId) + "," +
                       QByteArray::number(byteCount) + "," + hexData);
}

bool TeseoDriver::clearAlmanacs()
{
    return sendCommand("$PSTMCLRALMS");
}

bool TeseoDriver::dumpAlmanacs()
{
    return sendCommand("$PSTMDUMPALMANAC");
}

bool TeseoDriver::loadEphemeris(int satId, const QByteArray &hexData)
{
    int byteCount = hexData.size() / 2;
    return sendCommand("$PSTMEPHEM," + QByteArray::number(satId) + "," +
                       QByteArray::number(byteCount) + "," + hexData);
}

bool TeseoDriver::clearEphemeris()
{
    return sendCommand("$PSTMCLREPHS");
}

bool TeseoDriver::dumpEphemeris()
{
    return sendCommand("$PSTMDUMPEPHEMS");
}

bool TeseoDriver::systemReset()
{
    return sendCommand("$PSTMSRR");
}

bool TeseoDriver::gnssReset()
{
    return sendCommand("$PSTMGPSRESET");
}

bool TeseoDriver::gnssSuspend()
{
    return sendCommand("$PSTMGPSSUSPEND");
}

bool TeseoDriver::gnssRestart()
{
    return sendCommand("$PSTMGPSRESTART");
}

bool TeseoDriver::coldStart(int mask)
{
    return sendCommand("$PSTMCOLD," + QByteArray::number(mask));
}

bool TeseoDriver::warmStart()
{
    return sendCommand("$PSTMWARM");
}

bool TeseoDriver::hotStart()
{
    return sendCommand("$PSTMHOT");
}

bool TeseoDriver::setNmeaOutput(bool enable)
{
    return sendCommand("$PSTMNMEAONOFF," + QByteArray::number(enable ? 1 : 0));
}

bool TeseoDriver::invalidateGnssFix(bool invalidate)
{
    return sendCommand("$PSTMGNSSINV," + QByteArray::number(invalidate ? 1 : 0));
}

bool TeseoDriver::invalidateRtc()
{
    return sendCommand("$PSTMTIMEINV");
}

bool TeseoDriver::getSoftwareVersion(int id)
{
    return sendCommand("$PSTMGETSWVER," + QByteArray::number(id));
}

bool TeseoDriver::nvmSwap()
{
    return sendCommand("$PSTMNVMSWAP");
}

bool TeseoDriver::toggleSbas()
{
    return sendCommand("$PSTMSBASONOFF");
}

bool TeseoDriver::setSbasService(int service)
{
    return sendCommand("$PSTMSBASSERVICE," + QByteArray::number(service));
}

bool TeseoDriver::setSbasSatellite(int prn)
{
    return sendCommand("$PSTMSBASSAT," + QByteArray::number(prn));
}

bool TeseoDriver::sendSbasFrame(int prn, const QByteArray &frame)
{
    return sendCommand("$PSTMSBASM," + QByteArray::number(prn) + "," + frame);
}

bool TeseoDriver::rfTestOn(int satId)
{
    return sendCommand("$PSTMRFTESTON," + QByteArray::number(satId));
}

bool TeseoDriver::rfTestOff()
{
    return sendCommand("$PSTMRFTESTOFF");
}

bool TeseoDriver::getAlgorithmStatus(int algoType)
{
    return sendCommand("$PSTMGETALGO," + QByteArray::number(algoType));
}

bool TeseoDriver::setAlgorithmStatus(int algoType, bool enabled)
{
    return sendCommand("$PSTMSETALGO," + QByteArray::number(algoType) + "," +
                       QByteArray::number(enabled ? 1 : 0));
}

bool TeseoDriver::getRtcTime()
{
    return sendCommand("$PSTMGETRTCTIME");
}

bool TeseoDriver::selectDatum(int datumType)
{
    return sendCommand("$PSTMDATUMSELECT," + QByteArray::number(datumType));
}

bool TeseoDriver::setDatumParameters(double dx, double dy, double dz, double da, double df)
{
    QByteArray cmd = "$PSTMDATUMSETPARAM,";
    cmd += QByteArray::number(dx, 'f', 0) + ",";
    cmd += QByteArray::number(dy, 'f', 0) + ",";
    cmd += QByteArray::number(dz, 'f', 0) + ",";
    cmd += QByteArray::number(da, 'f', 1) + ",";
    cmd += QByteArray::number(df, 'f', 10);
    return sendCommand(cmd);
}

bool TeseoDriver::enablePositionHold(bool enable, double lat, char latRef,
                                      double lon, char lonRef, double alt)
{
    QByteArray cmd = "$PSTMENABLEPOSITIONHOLD,";
    cmd += QByteArray::number(enable ? 1 : 0);
    if (enable) {
        cmd += ",";
        cmd += QByteArray::number(lat, 'f', 3);
        cmd += ",";
        cmd += latRef;
        cmd += ",";
        cmd += QByteArray::number(lon, 'f', 3);
        cmd += ",";
        cmd += lonRef;
        cmd += ",";
        cmd += QByteArray::number(alt, 'f', 1);
    }
    return sendCommand(cmd);
}

bool TeseoDriver::setConstellationMask(int mask)
{
    return sendCommand("$PSTMSETCONSTMASK," + QByteArray::number(mask));
}

bool TeseoDriver::setNotchFilter(int satType, int mode, int frequency,
                                  int kbwGross, int kbwFine, int threshold)
{
    QByteArray cmd = "$PSTMNOTCH," + QByteArray::number(satType) + "," +
                     QByteArray::number(mode);
    if (frequency > 0) {
        cmd += "," + QByteArray::number(frequency);
        if (kbwGross > 0) {
            cmd += "," + QByteArray::number(kbwGross);
            cmd += "," + QByteArray::number(kbwFine);
            cmd += "," + QByteArray::number(threshold);
        }
    }
    return sendCommand(cmd);
}

// PPS Get commands
bool TeseoDriver::ppsGetPulseData()
{
    return sendCommand("$PSTMPPS,1,7");
}

bool TeseoDriver::ppsGetTimingData()
{
    return sendCommand("$PSTMPPS,1,12");
}

bool TeseoDriver::ppsGetPositionHoldData()
{
    return sendCommand("$PSTMPPS,1,13");
}

bool TeseoDriver::ppsGetTraimStatus()
{
    return sendCommand("$PSTMPPS,1,15");
}

bool TeseoDriver::ppsGetTraimUsed()
{
    return sendCommand("$PSTMPPS,1,16");
}

bool TeseoDriver::ppsGetTraimResiduals()
{
    return sendCommand("$PSTMPPS,1,17");
}

bool TeseoDriver::ppsGetTraimRemoved()
{
    return sendCommand("$PSTMPPS,1,18");
}

// PPS Set commands
bool TeseoDriver::ppsSetOnOff(bool enable)
{
    return sendCommand("$PSTMPPS,2,1," + QByteArray::number(enable ? 1 : 0));
}

bool TeseoDriver::ppsSetOutMode(int mode)
{
    return sendCommand("$PSTMPPS,2,2," + QByteArray::number(mode));
}

bool TeseoDriver::ppsSetReferenceTime(int refTime)
{
    return sendCommand("$PSTMPPS,2,19," + QByteArray::number(refTime));
}

bool TeseoDriver::ppsSetPulseDelay(int delayNs)
{
    return sendCommand("$PSTMPPS,2,4," + QByteArray::number(delayNs));
}

bool TeseoDriver::ppsSetPulseDuration(double durationS)
{
    return sendCommand("$PSTMPPS,2,5," + QByteArray::number(durationS, 'f', 6));
}

bool TeseoDriver::ppsSetPulsePolarity(int polarity)
{
    return sendCommand("$PSTMPPS,2,6," + QByteArray::number(polarity));
}

bool TeseoDriver::ppsSetPulseData(int outMode, int refTime, int delayNs,
                                   double durationS, int polarity)
{
    QByteArray cmd = "$PSTMPPS,2,7,";
    cmd += QByteArray::number(outMode) + ",";
    cmd += QByteArray::number(refTime) + ",";
    cmd += QByteArray::number(delayNs) + ",";
    cmd += QByteArray::number(durationS, 'f', 6) + ",";
    cmd += QByteArray::number(polarity);
    return sendCommand(cmd);
}

bool TeseoDriver::ppsSetFixCondition(int fixCondition)
{
    return sendCommand("$PSTMPPS,2,8," + QByteArray::number(fixCondition));
}

bool TeseoDriver::ppsSetSatThreshold(int threshold)
{
    return sendCommand("$PSTMPPS,2,9," + QByteArray::number(threshold));
}

bool TeseoDriver::ppsSetElevationMask(int mask)
{
    return sendCommand("$PSTMPPS,2,10," + QByteArray::number(mask));
}

bool TeseoDriver::ppsSetConstellationMask(int mask)
{
    return sendCommand("$PSTMPPS,2,11," + QByteArray::number(mask));
}

bool TeseoDriver::ppsSetTimingData(int fixCond, int satTh, int elevMask, int constMask)
{
    QByteArray cmd = "$PSTMPPS,2,12,";
    cmd += QByteArray::number(fixCond) + ",";
    cmd += QByteArray::number(satTh) + ",";
    cmd += QByteArray::number(elevMask) + ",";
    cmd += QByteArray::number(constMask);
    return sendCommand(cmd);
}

bool TeseoDriver::ppsSetPositionHoldData(bool enable, double lat, char latDir,
                                          double lon, char lonDir, double hMsl)
{
    QByteArray cmd = "$PSTMPPS,2,13,";
    cmd += QByteArray::number(enable ? 1 : 0) + ",";
    cmd += QByteArray::number(lat, 'f', 5) + ",";
    cmd += latDir + ",";
    cmd += QByteArray::number(lon, 'f', 5) + ",";
    cmd += lonDir + ",";
    cmd += QByteArray::number(hMsl, 'f', 1);
    return sendCommand(cmd);
}

bool TeseoDriver::ppsSetAutoHoldSamples(int samples)
{
    return sendCommand("$PSTMPPS,2,14," + QByteArray::number(samples));
}

bool TeseoDriver::ppsSetTraim(bool enable, double alarmS)
{
    return sendCommand("$PSTMPPS,2,15," + QByteArray::number(enable ? 1 : 0) +
                       "," + QByteArray::number(alarmS, 'g', 3));
}

bool TeseoDriver::ppsSetConstellationRfDelay(int satType, int delayNs)
{
    return sendCommand("$PSTMPPS,2,20," + QByteArray::number(satType) +
                       "," + QByteArray::number(delayNs));
}

bool TeseoDriver::setLowPowerMode(const LowPowerConfig &config)
{
    QByteArray cmd = "$PSTMLOWPOWERONOFF,";
    cmd += QByteArray::number(config.enabled ? 1 : 0) + ",";
    cmd += QByteArray::number(config.constellationMask) + ",";
    cmd += QByteArray::number(config.ehpeThreshold) + ",";
    cmd += QByteArray::number(config.maxTrackedSats) + ",";
    cmd += QByteArray::number(config.switchConstellation ? 1 : 0) + ",";
    cmd += QByteArray::number(config.dutyCycleEnabled ? 1 : 0) + ",";
    cmd += QByteArray::number(config.dutyCycleMsOff) + ",";
    cmd += QByteArray::number(config.periodicMode) + ",";
    cmd += QByteArray::number(config.fixPeriod) + ",";
    cmd += QByteArray::number(config.fixOnTime) + ",";
    cmd += QByteArray::number(config.ephemerisRefresh ? 1 : 0) + ",";
    cmd += QByteArray::number(config.rtcCalibration ? 1 : 0) + ",";
    cmd += QByteArray::number(config.noFixCnt) + ",";
    cmd += QByteArray::number(config.noFixOff);
    return sendCommand(cmd);
}

bool TeseoDriver::disableLowPowerMode()
{
    return sendCommand("$PSTMLOWPOWERONOFF,0,0");
}

bool TeseoDriver::setStandbyEnable(bool enable)
{
    return sendCommand("$PSTMSTANDBYENABLE," + QByteArray::number(enable ? 1 : 0));
}

bool TeseoDriver::getStandbyStatus()
{
    return sendCommand("$PSTMSTANDBYENABLE");
}

bool TeseoDriver::forceStandby(int durationS)
{
    return sendCommand("$PSTMFORCESTANDBY," + QByteArray::number(durationS));
}

bool TeseoDriver::requestNmeaMessages(quint32 msgListLow, quint32 msgListHigh)
{
    QByteArray cmd = "$PSTMNMEAREQUEST,";
    cmd += QByteArray::number(msgListLow, 16) + ",";
    cmd += QByteArray::number(msgListHigh, 16);
    return sendCommand(cmd);
}

bool TeseoDriver::setIonoParams(int satType, const QVector<int> &params)
{
    QByteArray cmd = "$PSTMIONOPARAMS," + QByteArray::number(satType) + ",1";
    for (int p : params)
        cmd += "," + QByteArray::number(p);
    return sendCommand(cmd);
}

bool TeseoDriver::setGalileoGgto(int brd, int wn0g, int t0g, int a0g, int a1g, bool validity)
{
    QByteArray cmd = "$PSTMGALILEOGGTO,";
    cmd += QByteArray::number(brd) + ",";
    cmd += QByteArray::number(wn0g) + ",";
    cmd += QByteArray::number(t0g) + ",";
    cmd += QByteArray::number(a0g) + ",";
    cmd += QByteArray::number(a1g) + ",";
    cmd += QByteArray::number(validity ? 1 : 0);
    return sendCommand(cmd);
}

bool TeseoDriver::dumpGalileoGgto()
{
    return sendCommand("$PSTMGALILEODUMPGGTO");
}

bool TeseoDriver::setTrackingThresholds(int cn0, double elevationDeg)
{
    return sendCommand("$PSTMSETTHTRK," + QByteArray::number(cn0) + "," +
                       QByteArray::number(elevationDeg, 'f', 1));
}

bool TeseoDriver::setPositioningThresholds(int cn0, double elevationDeg)
{
    return sendCommand("$PSTMSETTHPOS," + QByteArray::number(cn0) + "," +
                       QByteArray::number(elevationDeg, 'f', 1));
}

bool TeseoDriver::getUniqueCode()
{
    return sendCommand("$PSTMGETUCODE");
}

// =====================================================
// 10.2 System configuration
// =====================================================

bool TeseoDriver::setParameter(int configBlock, int id, const QByteArray &value, int mode)
{
    QByteArray cmd = "$PSTMSETPAR,";
    cmd += QByteArray::number(configBlock);
    cmd += QByteArray::number(id).rightJustified(3, '0');
    cmd += ",";
    cmd += value;
    if (mode != 0)
        cmd += "," + QByteArray::number(mode);
    return sendCommand(cmd);
}

bool TeseoDriver::getParameter(int configBlock, int id)
{
    QByteArray cmd = "$PSTMGETPAR,";
    cmd += QByteArray::number(configBlock);
    cmd += QByteArray::number(id).rightJustified(3, '0');
    return sendCommand(cmd);
}

bool TeseoDriver::saveParameters()
{
    return sendCommand("$PSTMSAVEPAR");
}

bool TeseoDriver::restoreFactoryParameters()
{
    return sendCommand("$PSTMRESTOREPAR");
}

bool TeseoDriver::cfgPortUart(int portNumb, int baudRate)
{
    return sendCommand("$PSTMCFGPORT,0,0," + QByteArray::number(portNumb) +
                       "," + QByteArray::number(baudRate));
}

bool TeseoDriver::cfgPortI2c(int slaveAddr, int mode)
{
    return sendCommand("$PSTMCFGPORT,1,0," + QByteArray::number(slaveAddr, 16) +
                       "," + QByteArray::number(mode));
}

bool TeseoDriver::cfgMessageList(int listId, int rate, quint32 listLow, quint32 listHigh)
{
    QByteArray cmd = "$PSTMCFGMSGL,";
    cmd += QByteArray::number(listId) + ",";
    cmd += QByteArray::number(rate) + ",";
    cmd += QByteArray::number(listLow, 16) + ",";
    cmd += QByteArray::number(listHigh, 16);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgGnss(int trkCn0, int posCn0, int trkMaskAngle, int posMaskAngle,
                           int ncoCenter, int ncoMin, int ncoMax)
{
    QByteArray cmd = "$PSTMCFGGNSS,";
    cmd += QByteArray::number(trkCn0) + ",";
    cmd += QByteArray::number(posCn0) + ",";
    cmd += QByteArray::number(trkMaskAngle) + ",";
    cmd += QByteArray::number(posMaskAngle) + ",";
    cmd += QByteArray::number(ncoCenter) + ",";
    cmd += QByteArray::number(ncoMin) + ",";
    cmd += QByteArray::number(ncoMax);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgSbas(const SBASConfig &config)
{
    QByteArray cmd = "$PSTMCFGSBAS,";
    cmd += QByteArray::number(config.engineEnabled ? 1 : 0) + ",";
    cmd += QByteArray::number(config.reportEnabled ? 1 : 0) + ",";
    cmd += QByteArray::number(config.autoSearch ? 1 : 0) + ",";
    cmd += QByteArray::number(config.service);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgPpsGeneral(bool enable, int genMode, int ppsClock, int refTime)
{
    QByteArray cmd = "$PSTMCFGPPSGEN,";
    cmd += QByteArray::number(enable ? 1 : 0) + ",";
    cmd += QByteArray::number(genMode) + ",";
    cmd += QByteArray::number(ppsClock) + ",";
    cmd += QByteArray::number(refTime);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgPpsSatellite(int enMix, int fixCond, int minSatNum, int satElevMask)
{
    QByteArray cmd = "$PSTMCFGPPSSAT,";
    cmd += QByteArray::number(enMix) + ",";
    cmd += QByteArray::number(fixCond) + ",";
    cmd += QByteArray::number(minSatNum) + ",";
    cmd += QByteArray::number(satElevMask);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgPpsPulse(bool polarityInvert, double pulseDuration, double delayCorr)
{
    QByteArray cmd = "$PSTMCFGPPSPUL,";
    cmd += QByteArray::number(polarityInvert ? 1 : 0) + ",";
    cmd += QByteArray::number(pulseDuration, 'f', 6) + ",";
    cmd += QByteArray::number(delayCorr, 'f', 6);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgPositionHold(bool enable, double lat, double lon, double hei)
{
    QByteArray cmd = "$PSTMCFGPOSHOLD,";
    cmd += QByteArray::number(enable ? 1 : 0);
    if (enable) {
        cmd += "," + QByteArray::number(lat, 'f', 8);
        cmd += "," + QByteArray::number(lon, 'f', 8);
        cmd += "," + QByteArray::number(hei, 'f', 4);
    }
    return sendCommand(cmd);
}

bool TeseoDriver::cfgTraim(bool enable, double threshold)
{
    return sendCommand("$PSTMCFGTRAIM," + QByteArray::number(enable ? 1 : 0) +
                       "," + QByteArray::number(threshold, 'g', 3));
}

bool TeseoDriver::cfgSatCompensation(int pathId, double compensation)
{
    return sendCommand("$PSTMCFGSATCOMP,1," + QByteArray::number(pathId) +
                       "," + QByteArray::number(compensation, 'f', 3));
}

bool TeseoDriver::cfgLowPowerAlgorithm(int enable, int feat, int fixPeriod, int fixOnTime,
                                         int noFixCnt, int noFixCnt2, int noFixOff,
                                         int adaptiveFeat, int adaptiveDutyCycle,
                                         int ehpeTh, int numSat, int dutyOff, int constType)
{
    QByteArray cmd = "$PSTMCFGLPA,";
    cmd += QByteArray::number(enable) + ",";
    cmd += QByteArray::number(feat) + ",";
    cmd += QByteArray::number(fixPeriod) + ",";
    cmd += QByteArray::number(fixOnTime) + ",";
    cmd += QByteArray::number(noFixCnt) + ",";
    cmd += QByteArray::number(noFixCnt2) + ",";
    cmd += QByteArray::number(noFixOff) + ",";
    cmd += QByteArray::number(adaptiveFeat) + ",";
    cmd += QByteArray::number(adaptiveDutyCycle) + ",";
    cmd += QByteArray::number(ehpeTh) + ",";
    cmd += QByteArray::number(numSat) + ",";
    cmd += QByteArray::number(dutyOff) + ",";
    cmd += QByteArray::number(constType);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgAgps(bool enable)
{
    return sendCommand("$PSTMCFGAGPS," + QByteArray::number(enable ? 1 : 0));
}

bool TeseoDriver::cfgAntiJamming(int gpsMode, int glonassMode)
{
    return sendCommand("$PSTMCFGAJM," + QByteArray::number(gpsMode) +
                       "," + QByteArray::number(glonassMode));
}

bool TeseoDriver::cfgOdometer(bool enable, bool messages, int alarm)
{
    return sendCommand("$PSTMCFGODO," + QByteArray::number(enable ? 1 : 0) +
                       "," + QByteArray::number(messages ? 1 : 0) +
                       "," + QByteArray::number(alarm));
}

bool TeseoDriver::cfgGeofence(bool enable, int tolerance)
{
    return sendCommand("$PSTMCFGGEOFENCE," + QByteArray::number(enable ? 1 : 0) +
                       "," + QByteArray::number(tolerance));
}

bool TeseoDriver::cfgGeofenceCircle(int circleId, bool enable, double lat,
                                     double lon, double radius)
{
    QByteArray cmd = "$PSTMCFGGEOCIR,";
    cmd += QByteArray::number(circleId) + ",";
    cmd += QByteArray::number(enable ? 1 : 0) + ",";
    cmd += QByteArray::number(lat, 'f', 8) + ",";
    cmd += QByteArray::number(lon, 'f', 8) + ",";
    cmd += QByteArray::number(radius, 'f', 1);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgConstellations(const ConstellationConfig &config)
{
    QByteArray cmd = "$PSTMCFGCONST,";
    cmd += QByteArray::number(config.gps) + ",";
    cmd += QByteArray::number(config.glonass) + ",";
    cmd += QByteArray::number(config.galileo) + ",";
    cmd += QByteArray::number(config.qzss) + ",";
    cmd += QByteArray::number(config.beidou);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgGnssThresholds(int trkCn0, int posCn0, int trkMaskAngle, int posMaskAngle)
{
    QByteArray cmd = "$PSTMCFGTHGNSS,";
    cmd += QByteArray::number(trkCn0) + ",";
    cmd += QByteArray::number(posCn0) + ",";
    cmd += QByteArray::number(trkMaskAngle) + ",";
    cmd += QByteArray::number(posMaskAngle);
    return sendCommand(cmd);
}

bool TeseoDriver::cfgTimeData(int gpsMinWeek, int gpsMaxWeek, int fixRate, int utcDelta)
{
    QByteArray cmd = "$PSTMCFGTDATA,";
    cmd += QByteArray::number(gpsMinWeek) + ",";
    cmd += QByteArray::number(gpsMaxWeek) + ",";
    cmd += QByteArray::number(fixRate) + ",";
    cmd += QByteArray::number(utcDelta);
    return sendCommand(cmd);
}

// =====================================================
// 10.3 AGNSS
// =====================================================

bool TeseoDriver::stagpsOnOff(bool enable)
{
    return sendCommand("$PSTMSTAGPSONOFF," + QByteArray::number(enable ? 1 : 0));
}

bool TeseoDriver::stagpsInvalidate(int param)
{
    return sendCommand("$PSTMSTAGPSINVALIDATE," + QByteArray::number(param));
}

bool TeseoDriver::stagpsGetStatus()
{
    return sendCommand("$PSTMGETAGPSSTATUS");
}

bool TeseoDriver::stagpsSetConstellationMask(int mask)
{
    return sendCommand("$PSTMSTAGPSSETCONSTMASK," + QByteArray::number(mask));
}

bool TeseoDriver::stagpsGeneratePassword(int gpsTimeSeconds, const QByteArray &vendorId,
                                          const QByteArray &deviceId)
{
    return sendCommand("$PSTMSTAGPS8PASSGEN," + QByteArray::number(gpsTimeSeconds) +
                       "," + vendorId + "," + deviceId);
}

// =====================================================
// 10.5 Dead Reckoning
// =====================================================

bool TeseoDriver::sendMapMatchingFeedback(const QByteArray &timestamp,
                                           bool latValid, bool lonValid,
                                           double lat, double lon,
                                           double height, double heading,
                                           double latErr, double lonErr,
                                           double heightErr, double headingErr)
{
    QByteArray cmd = "$PSTMDRMMFB,";
    cmd += timestamp + ",";
    cmd += QByteArray::number(latValid ? 1 : 0) + ",";
    cmd += QByteArray::number(lonValid ? 1 : 0) + ",0,0,";
    cmd += QByteArray::number(lat, 'f', 7) + ",";
    cmd += QByteArray::number(lon, 'f', 7) + ",";
    cmd += QByteArray::number(height, 'f', 1) + ",";
    cmd += QByteArray::number(heading, 'f', 1) + ",";
    cmd += QByteArray::number(latErr, 'f', 1) + ",";
    cmd += QByteArray::number(lonErr, 'f', 1) + ",";
    cmd += QByteArray::number(heightErr, 'f', 1) + ",";
    cmd += QByteArray::number(headingErr, 'f', 1);
    return sendCommand(cmd);
}

bool TeseoDriver::drCalibrateTilt()
{
    return sendCommand("$PSTMDRCALCTLT");
}

bool TeseoDriver::drSaveToNvm()
{
    return sendCommand("$PSTMDRNVMSAVE");
}

bool TeseoDriver::sendSensorMessage(int sensorId, const QVector<int> &values)
{
    QByteArray cmd = "$PSTMDRSENMSG," + QByteArray::number(sensorId) + ",0";
    for (int v : values)
        cmd += "," + QByteArray::number(v);
    return sendCommand(cmd);
}

// =====================================================
// RTCM protocol support (Section 4.2)
// =====================================================

bool TeseoDriver::sendRtcmData(const QByteArray &rtcmData)
{
    return m_serial->sendRaw(rtcmData);
}

bool TeseoDriver::enableRtcm(bool enable)
{
    // CDB 200 bit 11 (0x800) controls RTCM
    if (enable)
        return setParameter(1, 200, "800", 1); // OR mask
    else
        return setParameter(1, 200, "800", 2); // AND NOT mask
}

bool TeseoDriver::setDifferentialSource(int sourceType)
{
    // CDB 128: 0=NONE, 1=SBAS, 2=RTCM, 3=AUTO
    return setParameter(1, 128, QByteArray::number(sourceType));
}

bool TeseoDriver::cfgRtcmPort(int portNumber)
{
    return setParameter(1, 138, QByteArray::number(portNumber));
}

bool TeseoDriver::cfgRtcmBaudRate(int baudRateCode)
{
    return setParameter(1, 139, QByteArray::number(baudRateCode));
}

bool TeseoDriver::cfgRtcmOnPort(int portType, int portParam, int baudRate)
{
    bool ok = cfgPortUart(portParam, baudRate);
    if (ok) ok = cfgRtcmPort(portParam);
    if (ok) ok = enableRtcm(true);
    if (ok) ok = setDifferentialSource(2); // RTCM
    if (ok) ok = saveParameters();
    if (ok) ok = systemReset();
    return ok;
}

// =====================================================
// Missing commands
// =====================================================

bool TeseoDriver::cfgLog(int enable)
{
    return sendCommand("$PSTMCFGLOG," + QByteArray::number(enable));
}

bool TeseoDriver::imuSelfTest()
{
    return sendCommand("$PSTMIMUSELFTESTCMD");
}

// =====================================================
// Convenience
// =====================================================

bool TeseoDriver::setBaudRate(qint32 baudRate)
{
    int code = 0;
    switch (baudRate) {
    case 9600:   code = 0x5; break;
    case 19200:  code = 0x7; break;
    case 38400:  code = 0x9; break;
    case 57600:  code = 0xA; break;
    case 115200: code = 0xB; break;
    case 230400: code = 0xC; break;
    case 460800: code = 0xD; break;
    case 921600: code = 0xE; break;
    default: return false;
    }
    bool ok = setParameter(1, 3102, QByteArray::number(code, 16));
    if (ok) ok = saveParameters();
    if (ok) ok = systemReset();
    return ok;
}

bool TeseoDriver::setFixRate(int hz)
{
    return setParameter(1, 600, QByteArray::number(hz));
}

bool TeseoDriver::enableSbasAuto()
{
    return setSbasService(15);
}

bool TeseoDriver::getAllVersions()
{
    return getSoftwareVersion(255);
}

bool TeseoDriver::sendCommand(const QByteArray &command)
{
    bool ok = m_serial->sendCommand(command);
    if (ok)
        emit responseReceived(command);
    return ok;
}

void TeseoDriver::onDataReceived(const QByteArray &data)
{
    m_parser->processData(data);
}

void TeseoDriver::onSerialError(const QString &errorString)
{
    emit errorOccurred(errorString);
}

} // namespace Teseo
