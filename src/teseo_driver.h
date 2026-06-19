// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TESEO_DRIVER_H
#define TESEO_DRIVER_H

#include <QObject>
#include <QTimer>

#include "teseo_types.h"
#include "serial_interface.h"
#include "nmea_parser.h"

namespace Teseo {

class TeseoDriver : public QObject
{
    Q_OBJECT

public:
    explicit TeseoDriver(QObject *parent = nullptr);
    ~TeseoDriver();

    bool connectDevice(const QString &portName, qint32 baudRate = 115200);
    void disconnectDevice();
    bool isConnected() const;

    GnssData currentData() const;
    QVector<Satellite> satellites() const;

    // =====================================================
    // 10.1 ST NMEA command specifications
    // =====================================================

    // $PSTMINITGPS - Initialize position and time
    bool initGps(double lat, char latRef, double lon, char lonRef,
                 double alt, const QDate &date, const QTime &time);

    // $PSTMINITTIME - Initialize GPS time
    bool initTime(const QDate &date, const QTime &time);

    // $PSTMINITFRQ - Initialize centre frequency offset
    bool initFrequency(int offsetHz);

    // $PSTMSETRANGE - Set frequency range for satellite searching
    bool setFrequencyRange(int minHz, int maxHz);

    // $PSTMALMANAC - Load almanac data
    bool loadAlmanac(int satId, const QByteArray &hexData);

    // $PSTMCLRALMS - Erase all almanacs in NVM
    bool clearAlmanacs();

    // $PSTMDUMPALMANAC - Dump all almanacs from NVM
    bool dumpAlmanacs();

    // $PSTMEPHEM - Load ephemeris data
    bool loadEphemeris(int satId, const QByteArray &hexData);

    // $PSTMCLREPHS - Clear all ephemeris in NVM
    bool clearEphemeris();

    // $PSTMDUMPEPHEMS - Dump all ephemeris from NVM
    bool dumpEphemeris();

    // $PSTMSRR - System reset (firmware reboot)
    bool systemReset();

    // $PSTMGPSRESET - Reset GNSS engine (no reboot)
    bool gnssReset();

    // $PSTMGPSSUSPEND - Suspend GNSS engine
    bool gnssSuspend();

    // $PSTMGPSRESTART - Restart GNSS engine
    bool gnssRestart();

    // $PSTMCOLD - Cold start
    bool coldStart(int mask = 0xE);

    // $PSTMWARM - Warm start
    bool warmStart();

    // $PSTMHOT - Hot start
    bool hotStart();

    // $PSTMNMEAONOFF - Toggle NMEA output
    bool setNmeaOutput(bool enable);

    // $PSTMGNSSINV - Invalidate GNSS fix status
    bool invalidateGnssFix(bool invalidate);

    // $PSTMTIMEINV - Invalidate RTC
    bool invalidateRtc();

    // $PSTMGETSWVER - Get software version
    bool getSoftwareVersion(int id = 255);

    // $PSTMNVMSWAP - NVM bank swap
    bool nvmSwap();

    // $PSTMSBASONOFF - Toggle SBAS on/off
    bool toggleSbas();

    // $PSTMSBASSERVICE - Change SBAS service
    bool setSbasService(int service);

    // $PSTMSBASSAT - Change SBAS satellite
    bool setSbasSatellite(int prn);

    // $PSTMSBASM - Send SBAS frame
    bool sendSbasFrame(int prn, const QByteArray &frame);

    // $PSTMRFTESTON - Enable RF test mode
    bool rfTestOn(int satId);

    // $PSTMRFTESTOFF - Disable RF test mode
    bool rfTestOff();

    // $PSTMGETALGO - Get FDE algorithm status
    bool getAlgorithmStatus(int algoType);

    // $PSTMSETALGO - Set FDE algorithm
    bool setAlgorithmStatus(int algoType, bool enabled);

    // $PSTMGETRTCTIME - Get RTC time
    bool getRtcTime();

    // $PSTMDATUMSELECT - Select geodetic datum
    bool selectDatum(int datumType);

    // $PSTMDATUMSETPARAM - Set datum transformation parameters
    bool setDatumParameters(double dx, double dy, double dz, double da, double df);

    // $PSTMENABLEPOSITIONHOLD - Enable/disable position hold
    bool enablePositionHold(bool enable, double lat = 0, char latRef = 'N',
                            double lon = 0, char lonRef = 'E', double alt = 0);

    // $PSTMSETCONSTMASK - Set constellation mask
    bool setConstellationMask(int mask);

    // $PSTMNOTCH - Set Adaptive Notch Filter mode
    bool setNotchFilter(int satType, int mode, int frequency = 0,
                        int kbwGross = 0, int kbwFine = 0, int threshold = 0);

    // $PSTMPPS - PPS management (GET)
    bool ppsGetPulseData();
    bool ppsGetTimingData();
    bool ppsGetPositionHoldData();
    bool ppsGetTraimStatus();
    bool ppsGetTraimUsed();
    bool ppsGetTraimResiduals();
    bool ppsGetTraimRemoved();

    // $PSTMPPS - PPS management (SET)
    bool ppsSetOnOff(bool enable);
    bool ppsSetOutMode(int mode);
    bool ppsSetReferenceTime(int refTime);
    bool ppsSetPulseDelay(int delayNs);
    bool ppsSetPulseDuration(double durationS);
    bool ppsSetPulsePolarity(int polarity);
    bool ppsSetPulseData(int outMode, int refTime, int delayNs,
                         double durationS, int polarity);
    bool ppsSetFixCondition(int fixCondition);
    bool ppsSetSatThreshold(int threshold);
    bool ppsSetElevationMask(int mask);
    bool ppsSetConstellationMask(int mask);
    bool ppsSetTimingData(int fixCond, int satTh, int elevMask, int constMask);
    bool ppsSetPositionHoldData(bool enable, double lat, char latDir,
                                double lon, char lonDir, double hMsl);
    bool ppsSetAutoHoldSamples(int samples);
    bool ppsSetTraim(bool enable, double alarmS);
    bool ppsSetConstellationRfDelay(int satType, int delayNs);

    // $PSTMLOWPOWERONOFF - Low power mode
    bool setLowPowerMode(const LowPowerConfig &config);
    bool disableLowPowerMode();

    // $PSTMSTANDBYENABLE - Enable/disable standby
    bool setStandbyEnable(bool enable);
    bool getStandbyStatus();

    // $PSTMFORCESTANDBY - Force standby
    bool forceStandby(int durationS);

    // $PSTMNMEAREQUEST - Request NMEA message set
    bool requestNmeaMessages(quint32 msgListLow, quint32 msgListHigh);

    // $PSTMIONOPARAMS - Upload ionosphere parameters
    bool setIonoParams(int satType, const QVector<int> &params);

    // $PSTMGALILEOGGTO - Program Galileo GGTO
    bool setGalileoGgto(int brd, int wn0g, int t0g, int a0g, int a1g, bool validity);

    // $PSTMGALILEODUMPGGTO - Dump Galileo GGTO
    bool dumpGalileoGgto();

    // $PSTMSETTHTRK - Set tracking CN0 and elevation thresholds
    bool setTrackingThresholds(int cn0, double elevationDeg);

    // $PSTMSETTHPOS - Set positioning CN0 and elevation thresholds
    bool setPositioningThresholds(int cn0, double elevationDeg);

    // $PSTMGETUCODE - Read unique code from flash
    bool getUniqueCode();

    // =====================================================
    // 10.2 STM system configuration commands
    // =====================================================

    // $PSTMSETPAR - Set configuration parameter
    bool setParameter(int configBlock, int id, const QByteArray &value, int mode = 0);

    // $PSTMGETPAR - Get configuration parameter
    bool getParameter(int configBlock, int id);

    // $PSTMSAVEPAR - Save current configuration to NVM
    bool saveParameters();

    // $PSTMRESTOREPAR - Restore factory settings
    bool restoreFactoryParameters();

    // $PSTMCFGPORT - Configure communication port
    bool cfgPortUart(int portNumb, int baudRate);
    bool cfgPortI2c(int slaveAddr, int mode = 0);

    // $PSTMCFGMSGL - Configure message list
    bool cfgMessageList(int listId, int rate, quint32 listLow, quint32 listHigh);

    // $PSTMCFGGNSS - Configure GNSS algorithm
    bool cfgGnss(int trkCn0, int posCn0, int trkMaskAngle, int posMaskAngle,
                 int ncoCenter, int ncoMin, int ncoMax);

    // $PSTMCFGSBAS - Configure SBAS algorithm
    bool cfgSbas(const SBASConfig &config);

    // $PSTMCFGPPSGEN - Configure PPS general settings
    bool cfgPpsGeneral(bool enable, int genMode, int ppsClock, int refTime);

    // $PSTMCFGPPSSAT - Configure PPS satellite settings
    bool cfgPpsSatellite(int enMix, int fixCond, int minSatNum, int satElevMask);

    // $PSTMCFGPPSPUL - Configure PPS pulse settings
    bool cfgPpsPulse(bool polarityInvert, double pulseDuration, double delayCorr);

    // $PSTMCFGPOSHOLD - Configure position hold
    bool cfgPositionHold(bool enable, double lat = 0, double lon = 0, double hei = 0);

    // $PSTMCFGTRAIM - Configure TRAIM
    bool cfgTraim(bool enable, double threshold);

    // $PSTMCFGSATCOMP - Configure satellite compensation
    bool cfgSatCompensation(int pathId, double compensation);

    // $PSTMCFGLPA - Configure low power algorithm
    bool cfgLowPowerAlgorithm(int enable, int feat, int fixPeriod, int fixOnTime,
                               int noFixCnt, int noFixCnt2, int noFixOff,
                               int adaptiveFeat, int adaptiveDutyCycle,
                               int ehpeTh, int numSat, int dutyOff, int constType);

    // $PSTMCFGAGPS - Configure assisted GNSS
    bool cfgAgps(bool enable);

    // $PSTMCFGAJM - Configure anti-jamming
    bool cfgAntiJamming(int gpsMode, int glonassMode);

    // $PSTMCFGODO - Configure odometer
    bool cfgOdometer(bool enable, bool messages, int alarm);

    // $PSTMCFGGEOFENCE - Configure geofencing
    bool cfgGeofence(bool enable, int tolerance);

    // $PSTMCFGGEOCIR - Configure geofencing circle
    bool cfgGeofenceCircle(int circleId, bool enable, double lat, double lon, double radius);

    // $PSTMCFGCONST - Configure constellations
    bool cfgConstellations(const ConstellationConfig &config);

    // $PSTMCFGTHGNSS - Configure GNSS thresholds
    bool cfgGnssThresholds(int trkCn0, int posCn0, int trkMaskAngle, int posMaskAngle);

    // $PSTMCFGTDATA - Configure time data
    bool cfgTimeData(int gpsMinWeek, int gpsMaxWeek, int fixRate, int utcDelta);

    // =====================================================
    // 10.3 Autonomous AGNSS commands
    // =====================================================

    // $PSTMSTAGPSONOFF - ST-AGNSS engine on/off
    bool stagpsOnOff(bool enable);

    // $PSTMSTAGPSINVALIDATE - Clear ST-AGNSS databases
    bool stagpsInvalidate(int param);

    // $PSTMGETAGPSSTATUS - Get ST-AGNSS status
    bool stagpsGetStatus();

    // $PSTMSTAGPSSETCONSTMASK - Set ST-AGNSS constellation mask
    bool stagpsSetConstellationMask(int mask);

    // =====================================================
    // 10.4 Real Time AGNSS commands
    // =====================================================

    // $PSTMSTAGPS8PASSGEN - Generate AGNSS password
    bool stagpsGeneratePassword(int gpsTimeSeconds, const QByteArray &vendorId,
                                const QByteArray &deviceId);

    // $PSTMINITTIME (for AGNSS) - Inject current time
    // (already covered by initTime)

    // $PSTMINITGPS (for AGNSS) - Inject position and time
    // (already covered by initGps)

    // $PSTMEPHEM (for AGNSS) - Inject ephemeris
    // (already covered by loadEphemeris)

    // $PSTMALMANAC (for AGNSS) - Inject almanac
    // (already covered by loadAlmanac)

    // =====================================================
    // 10.5 Dead Reckoning commands
    // =====================================================

    // $PSTMDRMMFB - Map Matching Feedback
    bool sendMapMatchingFeedback(const QByteArray &timestamp,
                                 bool latValid, bool lonValid,
                                 double lat, double lon,
                                 double height = 0, double heading = 0,
                                 double latErr = 0, double lonErr = 0,
                                 double heightErr = 0, double headingErr = 0);

    // $PSTMDRCALCTLT - Start tilt calibration
    bool drCalibrateTilt();

    // $PSTMDRNVMSAVE - Save DR status to NVM
    bool drSaveToNvm();

    // $PSTMDRSENMSG - Send sensor data (SoU)
    bool sendSensorMessage(int sensorId, const QVector<int> &values);

    // =====================================================
    // RTCM protocol support (Section 4.2)
    // =====================================================

    // Send raw RTCM data to module (module parses it automatically)
    bool sendRtcmData(const QByteArray &rtcmData);

    // Enable/disable RTCM processing (CDB 200 bit 11)
    bool enableRtcm(bool enable);

    // Set differential source type (CDB 128): 0=NONE, 1=SBAS, 2=RTCM, 3=AUTO
    bool setDifferentialSource(int sourceType);

    // Configure RTCM port (CDB 138)
    bool cfgRtcmPort(int portNumber);

    // Configure RTCM baud rate (CDB 139)
    bool cfgRtcmBaudRate(int baudRateCode);

    // Configure RTCM on a dedicated port
    bool cfgRtcmOnPort(int portType, int portParam, int baudRate);

    // =====================================================
    // Missing commands
    // =====================================================

    // $PSTMCFGLOG - Configure logging
    bool cfgLog(int enable);

    // $PSTMIMUSELFTESTCMD - IMU self test
    bool imuSelfTest();

    // $PSTMCFGGEOFENCE (already exists)

    // =====================================================
    // Convenience methods
    // =====================================================

    // Set UART baud rate (sets param, saves, reboots)
    bool setBaudRate(qint32 baudRate);

    // Set fix rate Hz
    bool setFixRate(int hz);

    // Enable SBAS auto
    bool enableSbasAuto();

    // Get all versions
    bool getAllVersions();

    // Send raw command
    bool sendCommand(const QByteArray &command);

signals:
    void connected();
    void disconnected();

    // Parsed GNSS data
    void positionUpdated(const Teseo::Position &position);
    void velocityUpdated(const Teseo::Velocity &velocity);
    void satellitesUpdated(const QVector<Teseo::Satellite> &satellites);
    void dopUpdated(const Teseo::DOP &dop);
    void accuracyUpdated(const Teseo::Accuracy &accuracy);
    void fixUpdated(const Teseo::GnssData &data);

    // NMEA / PSTM
    void nmeaSentenceReceived(const QByteArray &sentence);
    void pstmMessageReceived(const QByteArray &message);

    // Command responses
    void responseReceived(const QByteArray &response);
    void errorOccurred(const QString &error);

    // Specific response signals
    void rtcTimeReceived(const Teseo::RTCData &rtc);
    void softwareVersionReceived(const Teseo::SoftwareVersion &ver);
    void ppsStatusReceived(const Teseo::PPSStatus &pps);
    void traimStatusReceived(const Teseo::TRAIMStatus &traim);
    void standbyStatusReceived(bool enabled);
    void lowPowerReceived(const QByteArray &data);
    void agpsStatusReceived(const QByteArray &data);
    void parameterReceived(int id, const QByteArray &value);
    void uniqueCodeReceived(const QByteArray &code);

private slots:
    void onDataReceived(const QByteArray &data);
    void onSerialError(const QString &errorString);

private:
    SerialInterface *m_serial;
    NmeaParser *m_parser;
    GnssData m_lastData;
};

} // namespace Teseo

#endif // TESEO_DRIVER_H
