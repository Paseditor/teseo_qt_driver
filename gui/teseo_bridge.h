// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef TEO_BRIDGE_H
#define TEO_BRIDGE_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>
#include <QSerialPortInfo>
#include "teseo_driver.h"

class TeseoBridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectedChanged)
    Q_PROPERTY(double latitude READ latitude NOTIFY fixChanged)
    Q_PROPERTY(double longitude READ longitude NOTIFY fixChanged)
    Q_PROPERTY(double altitude READ altitude NOTIFY fixChanged)
    Q_PROPERTY(double speedKmh READ speedKmh NOTIFY fixChanged)
    Q_PROPERTY(double course READ course NOTIFY fixChanged)
    Q_PROPERTY(int fixQuality READ fixQuality NOTIFY fixChanged)
    Q_PROPERTY(int satellitesUsed READ satellitesUsed NOTIFY fixChanged)
    Q_PROPERTY(double hdop READ hdop NOTIFY fixChanged)
    Q_PROPERTY(double pdop READ pdop NOTIFY fixChanged)
    Q_PROPERTY(double vdop READ vdop NOTIFY fixChanged)
    Q_PROPERTY(double ehpe READ ehpe NOTIFY fixChanged)
    Q_PROPERTY(bool fixValid READ fixValid NOTIFY fixChanged)
    Q_PROPERTY(QString utcTime READ utcTime NOTIFY fixChanged)
    Q_PROPERTY(QString utcDate READ utcDate NOTIFY fixChanged)
    Q_PROPERTY(QString swVersion READ swVersion NOTIFY swVersionChanged)
    Q_PROPERTY(QString uniqueCode READ uniqueCode NOTIFY uniqueCodeChanged)

public:
    explicit TeseoBridge(Teseo::TeseoDriver *driver, QObject *parent = nullptr);

    bool isConnected() const;
    double latitude() const;
    double longitude() const;
    double altitude() const;
    double speedKmh() const;
    double course() const;
    int fixQuality() const;
    int satellitesUsed() const;
    double hdop() const;
    double pdop() const;
    double vdop() const;
    double ehpe() const;
    bool fixValid() const;
    QString utcTime() const;
    QString utcDate() const;
    QString swVersion() const;
    QString uniqueCode() const;

    Q_INVOKABLE QVariantList availablePorts();
    Q_INVOKABLE bool connectDevice(const QString &port, int baud);
    Q_INVOKABLE void disconnectDevice();
    Q_INVOKABLE QVariantList satellitesModel();

    Q_INVOKABLE bool hotStart();
    Q_INVOKABLE bool warmStart();
    Q_INVOKABLE bool coldStart(int mask = 0xE);
    Q_INVOKABLE bool systemReset();
    Q_INVOKABLE bool gnssReset();
    Q_INVOKABLE bool gnssSuspend();
    Q_INVOKABLE bool gnssRestart();
    Q_INVOKABLE bool setConstellationMask(int mask);
    Q_INVOKABLE bool setNmeaOutput(bool enable);
    Q_INVOKABLE bool invalidateGnssFix(bool inv);
    Q_INVOKABLE bool invalidateRtc();
    Q_INVOKABLE bool nvmSwap();
    Q_INVOKABLE bool toggleSbas();
    Q_INVOKABLE bool setSbasService(int svc);
    Q_INVOKABLE bool setSbasSatellite(int prn);
    Q_INVOKABLE bool rfTestOn(int satId);
    Q_INVOKABLE bool rfTestOff();
    Q_INVOKABLE bool setAlgorithmStatus(int type, bool en);
    Q_INVOKABLE bool getAlgorithmStatus(int type);
    Q_INVOKABLE bool imuSelfTest();
    Q_INVOKABLE bool getSoftwareVersion(int id = 255);
    Q_INVOKABLE bool getAllVersions();
    Q_INVOKABLE bool getRtcTime();
    Q_INVOKABLE bool getUniqueCode();
    Q_INVOKABLE bool selectDatum(int type);
    Q_INVOKABLE bool enablePositionHold(bool en);
    Q_INVOKABLE bool setNotchFilter(int satType, int mode);
    Q_INVOKABLE bool setTrackingThresholds(int cn0, double elev);
    Q_INVOKABLE bool setPositioningThresholds(int cn0, double elev);
    Q_INVOKABLE bool cfgLog(int en);
    Q_INVOKABLE bool forceStandby(int dur);
    Q_INVOKABLE bool setStandbyEnable(bool en);
    Q_INVOKABLE bool getStandbyStatus();
    Q_INVOKABLE bool ppsSetOnOff(bool en);
    Q_INVOKABLE bool sendCommand(const QString &cmd);

    Q_INVOKABLE bool getParameter(int block, int id);
    Q_INVOKABLE bool setParameter(int block, int id, const QString &val, int mode = 0);
    Q_INVOKABLE bool saveParameters();
    Q_INVOKABLE bool restoreFactoryParameters();
    Q_INVOKABLE bool setBaudRate(int baud);
    Q_INVOKABLE bool setFixRate(int hz);
    Q_INVOKABLE bool cfgConstellations(int gps, int glo, int gal, int bds);
    Q_INVOKABLE bool cfgGnssThresholds(int trkCn0, int posCn0, int trkAng, int posAng);
    Q_INVOKABLE bool setDifferentialSource(int src);
    Q_INVOKABLE bool enableRtcm(bool en);
    Q_INVOKABLE bool sendRtcmDataHex(const QString &hex);
    Q_INVOKABLE bool cfgRtcmPort(int port);
    Q_INVOKABLE bool cfgRtcmBaudRate(int code);
    Q_INVOKABLE bool cfgPortUart(int port, int baud);
    Q_INVOKABLE bool cfgPortI2c(int addr);
    Q_INVOKABLE bool cfgMessageList(int id, int rate, const QString &low, const QString &high);
    Q_INVOKABLE bool cfgGnss(int trkCn0, int posCn0, int trkAng, int posAng, int ncoC, int ncoMin, int ncoMax);
    Q_INVOKABLE bool cfgSbas(int enEng, int enRep, int enAuto, int svc);
    Q_INVOKABLE bool cfgPpsGeneral(bool en, int mode, int clock, int ref);
    Q_INVOKABLE bool cfgPpsSatellite(int mix, int fix, int minSat, int elev);
    Q_INVOKABLE bool cfgPpsPulse(bool inv, double dur, double corr);
    Q_INVOKABLE bool cfgPositionHold(bool en, double lat, double lon, double hei);
    Q_INVOKABLE bool cfgTraim(bool en, double thr);
    Q_INVOKABLE bool cfgSatCompensation(int path, double comp);
    Q_INVOKABLE bool cfgLowPowerAlgorithm(int en, int feat, int fixP, int fixOn, int noFix, int noFix2, int noFixOff, int adaptFeat, int adaptDuty, int ehpeTh, int numSat, int dutyOff, int constType);
    Q_INVOKABLE bool cfgAgps(bool en);
    Q_INVOKABLE bool cfgAntiJamming(int gps, int glo);
    Q_INVOKABLE bool cfgOdometer(bool en, bool msg, int alarm);
    Q_INVOKABLE bool cfgGeofence(bool en, int tol);
    Q_INVOKABLE bool cfgGeofenceCircle(int id, bool en, double lat, double lon, double rad);
    Q_INVOKABLE bool cfgTimeData(int minW, int maxW, int rate, int utc);
    Q_INVOKABLE bool setFrequencyRange(int minHz, int maxHz);

    Q_INVOKABLE bool initGps(double lat, const QString &latRef, double lon, const QString &lonRef, double alt, const QDate &date, const QTime &time);
    Q_INVOKABLE bool initTime(const QDate &date, const QTime &time);
    Q_INVOKABLE bool initFrequency(int offset);
    Q_INVOKABLE bool stagpsOnOff(bool en);
    Q_INVOKABLE bool stagpsGetStatus();
    Q_INVOKABLE bool stagpsInvalidate(int param);
    Q_INVOKABLE bool stagpsSetConstellationMask(int mask);
    Q_INVOKABLE bool stagpsGeneratePassword(int time, const QString &vendor, const QString &dev);
    Q_INVOKABLE bool loadAlmanac(int satId, const QString &hex);
    Q_INVOKABLE bool loadEphemeris(int satId, const QString &hex);
    Q_INVOKABLE bool dumpAlmanacs();
    Q_INVOKABLE bool clearAlmanacs();
    Q_INVOKABLE bool dumpEphemeris();
    Q_INVOKABLE bool clearEphemeris();
    Q_INVOKABLE bool setGalileoGgto(int brd, int wn, int t0, int a0, int a1, bool val);
    Q_INVOKABLE bool dumpGalileoGgto();
    Q_INVOKABLE bool setIonoParams(int satType, const QVariantList &params);

    Q_INVOKABLE bool sendMapMatchingFeedback(const QString &ts, bool latV, bool lonV, double lat, double lon, double hErr, double lonErr);
    Q_INVOKABLE bool sendSensorMessage(int id, int x, int y, int z);
    Q_INVOKABLE bool drCalibrateTilt();
    Q_INVOKABLE bool drSaveToNvm();
    Q_INVOKABLE bool cfgOdometerSimple(bool en);

signals:
    void connectedChanged();
    void fixChanged();
    void swVersionChanged();
    void uniqueCodeChanged();
    void nmeaReceived(const QString &sentence);
    void pstmReceived(const QString &message);
    void responseReceived(const QString &response);
    void errorOccurred(const QString &error);
    void rtcTimeReceived(const QString &time, const QString &date, int status);
    void parameterReceived(int id, const QString &value);
    void agpsStatusReceived(const QString &data);
    void lowPowerReceived(const QString &data);

private:
    Teseo::TeseoDriver *m_driver;
    Teseo::GnssData m_data;
    QString m_swVersion;
    QString m_uniqueCode;
};

#endif
