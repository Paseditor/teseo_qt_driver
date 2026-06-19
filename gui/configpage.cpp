// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "configpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateTime>
#include <QScrollArea>

ConfigPage::ConfigPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    auto *scrollWidget = new QWidget;
    auto *mainLayout = new QVBoxLayout(scrollWidget);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    // Top row: CDB + Quick
    auto *topRow = new QHBoxLayout;
    topRow->setSpacing(12);

    // CDB Parameter card
    auto *parGroup = new QGroupBox("CDB Parameters");
    auto *parForm = new QFormLayout;
    parForm->setSpacing(10);
    parForm->setContentsMargins(12, 16, 12, 12);

    auto *blockCombo = new QComboBox;
    blockCombo->addItems({"1 - Current", "2 - Default", "3 - NVM"});
    blockCombo->setMinimumWidth(120);
    parForm->addRow("Block:", blockCombo);

    auto *idSpin = new QSpinBox;
    idSpin->setRange(0, 999);
    idSpin->setMinimumWidth(100);
    parForm->addRow("ID:", idSpin);

    auto *valueEdit = new QLineEdit;
    valueEdit->setPlaceholderText("Hex value");
    valueEdit->setMinimumWidth(120);
    parForm->addRow("Value:", valueEdit);

    auto *parBtns = new QHBoxLayout;
    parBtns->setSpacing(6);
    auto *getBtn = new QPushButton("GET");
    auto *setBtn = new QPushButton("SET");
    auto *saveBtn = new QPushButton("SAVE");
    auto *restoreBtn = new QPushButton("RESTORE");
    parBtns->addWidget(getBtn);
    parBtns->addWidget(setBtn);
    parBtns->addWidget(saveBtn);
    parBtns->addWidget(restoreBtn);
    parForm->addRow(parBtns);

    parGroup->setLayout(parForm);
    topRow->addWidget(parGroup, 1);

    // Quick config card
    auto *quickGroup = new QGroupBox("Quick Config");
    auto *qGrid = new QGridLayout;
    qGrid->setSpacing(8);
    qGrid->setContentsMargins(12, 16, 12, 12);
    int r = 0;

    qGrid->addWidget(new QLabel("Baud:"), r, 0);
    auto *baudCombo = new QComboBox;
    baudCombo->addItems({"9600","19200","38400","57600","115200","230400","460800","921600"});
    baudCombo->setCurrentText("115200");
    baudCombo->setMinimumWidth(90);
    qGrid->addWidget(baudCombo, r, 1, 1, 2);
    auto *baudBtn = new QPushButton("Set");
    qGrid->addWidget(baudBtn, r, 3);

    qGrid->addWidget(new QLabel("Rate:"), r, 4);
    auto *rateSpin = new QSpinBox;
    rateSpin->setRange(1, 20);
    rateSpin->setMinimumWidth(60);
    qGrid->addWidget(rateSpin, r, 5);
    auto *rateBtn = new QPushButton("Set");
    qGrid->addWidget(rateBtn, r, 6);
    r++;

    qGrid->addWidget(new QLabel("GPS:"), r, 0);
    auto *gpsCombo = new QComboBox;
    gpsCombo->addItems({"Off","Track","Use"});
    gpsCombo->setCurrentIndex(2);
    qGrid->addWidget(gpsCombo, r, 1, 1, 2);

    qGrid->addWidget(new QLabel("GLO:"), r, 3);
    auto *gloCombo = new QComboBox;
    gloCombo->addItems({"Off","Track","Use"});
    gloCombo->setCurrentIndex(2);
    qGrid->addWidget(gloCombo, r, 4, 1, 2);
    r++;

    qGrid->addWidget(new QLabel("GAL:"), r, 0);
    auto *galCombo = new QComboBox;
    galCombo->addItems({"Off","Track","Use"});
    qGrid->addWidget(galCombo, r, 1, 1, 2);

    qGrid->addWidget(new QLabel("BDS:"), r, 3);
    auto *bdsCombo = new QComboBox;
    bdsCombo->addItems({"Off","Track","Use"});
    qGrid->addWidget(bdsCombo, r, 4, 1, 2);
    r++;

    auto *constBtn = new QPushButton("Apply Constellations");
    qGrid->addWidget(constBtn, r, 0, 1, 7);
    r++;

    qGrid->addWidget(new QLabel("Trk CN0:"), r, 0);
    auto *trkCn0 = new QSpinBox; trkCn0->setRange(0, 50);
    qGrid->addWidget(trkCn0, r, 1);
    qGrid->addWidget(new QLabel("Pos CN0:"), r, 2);
    auto *posCn0 = new QSpinBox; posCn0->setRange(0, 50);
    qGrid->addWidget(posCn0, r, 3, 1, 2);
    auto *thrBtn = new QPushButton("Apply Thresholds");
    qGrid->addWidget(thrBtn, r, 5, 1, 2);

    qGrid->setColumnStretch(0, 0);
    qGrid->setColumnStretch(1, 1);
    qGrid->setColumnStretch(2, 0);
    qGrid->setColumnStretch(3, 0);
    qGrid->setColumnStretch(4, 1);
    qGrid->setColumnStretch(5, 1);
    qGrid->setColumnStretch(6, 0);

    quickGroup->setLayout(qGrid);
    topRow->addWidget(quickGroup, 2);
    mainLayout->addLayout(topRow);

    // RTCM row
    auto *rtcmGroup = new QGroupBox("RTCM (Differential Corrections)");
    auto *rtcmGrid = new QGridLayout;
    rtcmGrid->setSpacing(8);
    rtcmGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    rtcmGrid->addWidget(new QLabel("Source:"), r, 0);
    auto *diffCombo = new QComboBox;
    diffCombo->addItems({"0-NONE", "1-SBAS", "2-RTCM", "3-AUTO"});
    diffCombo->setCurrentIndex(3);
    diffCombo->setMinimumWidth(100);
    rtcmGrid->addWidget(diffCombo, r, 1, 1, 2);
    auto *diffBtn = new QPushButton("Apply");
    rtcmGrid->addWidget(diffBtn, r, 3);

    auto *rtcmOn = new QPushButton("RTCM ON");
    auto *rtcmOff = new QPushButton("RTCM OFF");
    rtcmGrid->addWidget(rtcmOn, r, 4);
    rtcmGrid->addWidget(rtcmOff, r, 5);
    r++;

    rtcmGrid->addWidget(new QLabel("Port:"), r, 0);
    auto *rtcmPort = new QSpinBox;
    rtcmPort->setRange(0, 255);
    rtcmPort->setMinimumWidth(60);
    rtcmGrid->addWidget(rtcmPort, r, 1);
    rtcmGrid->addWidget(new QLabel("Baud Code:"), r, 2);
    auto *rtcmBaud = new QSpinBox;
    rtcmBaud->setRange(0, 15);
    rtcmBaud->setValue(11);
    rtcmBaud->setMinimumWidth(60);
    rtcmGrid->addWidget(rtcmBaud, r, 3);
    auto *rtcmPortBtn = new QPushButton("Cfg RTCM Port");
    rtcmGrid->addWidget(rtcmPortBtn, r, 4);
    r++;

    rtcmGrid->addWidget(new QLabel("RTCM Data (hex):"), r, 0);
    auto *rtcmDataEdit = new QLineEdit;
    rtcmDataEdit->setPlaceholderText("Raw RTCM frame hex...");
    rtcmGrid->addWidget(rtcmDataEdit, r, 1, 1, 4);
    auto *rtcmSend = new QPushButton("Send RTCM");
    rtcmGrid->addWidget(rtcmSend, r, 5);

    rtcmGrid->setColumnStretch(0, 0);
    rtcmGrid->setColumnStretch(1, 1);
    rtcmGrid->setColumnStretch(2, 1);
    rtcmGrid->setColumnStretch(3, 0);
    rtcmGrid->setColumnStretch(4, 0);
    rtcmGrid->setColumnStretch(5, 0);

    rtcmGroup->setLayout(rtcmGrid);
    mainLayout->addWidget(rtcmGroup);

    // Port config row
    auto *portGroup = new QGroupBox("Port Configuration");
    auto *portGrid = new QGridLayout;
    portGrid->setSpacing(8);
    portGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    portGrid->addWidget(new QLabel("UART Port:"), r, 0);
    auto *uartPort = new QSpinBox; uartPort->setRange(0, 255);
    uartPort->setMinimumWidth(60);
    portGrid->addWidget(uartPort, r, 1);
    portGrid->addWidget(new QLabel("Baud:"), r, 2);
    auto *uartBaud = new QComboBox;
    uartBaud->addItems({"9600","19200","38400","57600","115200","230400","460800","921600"});
    uartBaud->setMinimumWidth(90);
    portGrid->addWidget(uartBaud, r, 3);
    auto *uartBtn = new QPushButton("Cfg UART");
    portGrid->addWidget(uartBtn, r, 4);

    portGrid->addWidget(new QLabel("I2C Addr (hex):"), r, 5);
    auto *i2cAddr = new QLineEdit; i2cAddr->setText("3A");
    i2cAddr->setMaximumWidth(60);
    portGrid->addWidget(i2cAddr, r, 6);
    auto *i2cBtn = new QPushButton("Cfg I2C");
    portGrid->addWidget(i2cBtn, r, 7);
    r++;

    // Message list
    portGrid->addWidget(new QLabel("MsgList ID:"), r, 0);
    auto *msgListId = new QSpinBox; msgListId->setRange(0, 3);
    msgListId->setMinimumWidth(60);
    portGrid->addWidget(msgListId, r, 1);
    portGrid->addWidget(new QLabel("Rate:"), r, 2);
    auto *msgRate = new QSpinBox; msgRate->setRange(0, 255);
    msgRate->setMinimumWidth(60);
    portGrid->addWidget(msgRate, r, 3);
    portGrid->addWidget(new QLabel("Low (hex):"), r, 4);
    auto *msgLow = new QLineEdit; msgLow->setText("0");
    msgLow->setMaximumWidth(100);
    portGrid->addWidget(msgLow, r, 5);
    portGrid->addWidget(new QLabel("High (hex):"), r, 6);
    auto *msgHigh = new QLineEdit; msgHigh->setText("0");
    msgHigh->setMaximumWidth(100);
    portGrid->addWidget(msgHigh, r, 7);
    auto *msgBtn = new QPushButton("Cfg MsgList");
    portGrid->addWidget(msgBtn, r, 8);

    for (int i = 0; i < 9; i++)
        portGrid->setColumnStretch(i, 1);

    portGroup->setLayout(portGrid);
    mainLayout->addWidget(portGroup);

    // GNSS / SBAS / Geofence config row
    auto *algoGroup = new QGroupBox("GNSS / SBAS / Geofence Configuration");
    auto *algoGrid = new QGridLayout;
    algoGrid->setSpacing(8);
    algoGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    // GNSS algorithm
    algoGrid->addWidget(new QLabel("GNSS Trk CN0:"), r, 0);
    auto *gnssTrkCn0 = new QSpinBox; gnssTrkCn0->setRange(0, 255);
    algoGrid->addWidget(gnssTrkCn0, r, 1);
    algoGrid->addWidget(new QLabel("Pos CN0:"), r, 2);
    auto *gnssPosCn0 = new QSpinBox; gnssPosCn0->setRange(0, 255);
    algoGrid->addWidget(gnssPosCn0, r, 3);
    algoGrid->addWidget(new QLabel("Trk Angle:"), r, 4);
    auto *gnssTrkAngle = new QSpinBox; gnssTrkAngle->setRange(0, 255);
    algoGrid->addWidget(gnssTrkAngle, r, 5);
    algoGrid->addWidget(new QLabel("Pos Angle:"), r, 6);
    auto *gnssPosAngle = new QSpinBox; gnssPosAngle->setRange(0, 255);
    algoGrid->addWidget(gnssPosAngle, r, 7);
    auto *gnssBtn = new QPushButton("Cfg GNSS");
    algoGrid->addWidget(gnssBtn, r, 8);
    r++;

    // SBAS config
    algoGrid->addWidget(new QLabel("SBAS Engine:"), r, 0);
    auto *sbasEn = new QCheckBox("ON");
    algoGrid->addWidget(sbasEn, r, 1);
    algoGrid->addWidget(new QLabel("Report:"), r, 2);
    auto *sbasRep = new QCheckBox("ON");
    algoGrid->addWidget(sbasRep, r, 3);
    algoGrid->addWidget(new QLabel("AutoSearch:"), r, 4);
    auto *sbasAuto = new QCheckBox("ON");
    algoGrid->addWidget(sbasAuto, r, 5);
    algoGrid->addWidget(new QLabel("Service:"), r, 6);
    auto *sbasSvc = new QComboBox;
    sbasSvc->addItems({"0-WAAS","1-EGNOS","2-MSAS","3-GAGAN","4-SDCM","7-OFF","15-AUTO"});
    sbasSvc->setCurrentIndex(6);
    algoGrid->addWidget(sbasSvc, r, 7);
    auto *sbasCfgBtn = new QPushButton("Cfg SBAS");
    algoGrid->addWidget(sbasCfgBtn, r, 8);
    r++;

    // Geofence
    algoGrid->addWidget(new QLabel("Geofence:"), r, 0);
    auto *geoEn = new QCheckBox("Enable");
    algoGrid->addWidget(geoEn, r, 1);
    algoGrid->addWidget(new QLabel("Tolerance:"), r, 2);
    auto *geoTol = new QSpinBox; geoTol->setRange(0, 3);
    algoGrid->addWidget(geoTol, r, 3);
    auto *geoBtn = new QPushButton("Cfg Geofence");
    algoGrid->addWidget(geoBtn, r, 4);

    algoGrid->addWidget(new QLabel("Circle ID:"), r, 5);
    auto *geoCirId = new QSpinBox; geoCirId->setRange(0, 7);
    algoGrid->addWidget(geoCirId, r, 6);
    auto *geoCirBtn = new QPushButton("Cfg Circle");
    algoGrid->addWidget(geoCirBtn, r, 7, 1, 2);
    r++;

    // Geofence circle params
    algoGrid->addWidget(new QLabel("Cir Lat:"), r, 0);
    auto *geoCirLat = new QDoubleSpinBox;
    geoCirLat->setRange(-90, 90); geoCirLat->setDecimals(8);
    algoGrid->addWidget(geoCirLat, r, 1);
    algoGrid->addWidget(new QLabel("Cir Lon:"), r, 2);
    auto *geoCirLon = new QDoubleSpinBox;
    geoCirLon->setRange(-180, 180); geoCirLon->setDecimals(8);
    algoGrid->addWidget(geoCirLon, r, 3);
    algoGrid->addWidget(new QLabel("Radius:"), r, 4);
    auto *geoCirRad = new QDoubleSpinBox;
    geoCirRad->setRange(0, 100000); geoCirRad->setDecimals(1);
    algoGrid->addWidget(geoCirRad, r, 5);
    auto *geoCirEn = new QCheckBox("Enable");
    algoGrid->addWidget(geoCirEn, r, 6);

    for (int i = 0; i < 9; i++)
        algoGrid->setColumnStretch(i, 1);

    algoGroup->setLayout(algoGrid);
    mainLayout->addWidget(algoGroup);

    // PPS / TRAIM / Position Hold / Low Power config
    auto *ppsGroup = new QGroupBox("PPS / TRAIM / Position Hold / Time Config");
    auto *ppsGrid = new QGridLayout;
    ppsGrid->setSpacing(8);
    ppsGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    // PPS general
    ppsGrid->addWidget(new QLabel("PPS Enable:"), r, 0);
    auto *ppsEn = new QCheckBox("ON");
    ppsGrid->addWidget(ppsEn, r, 1);
    ppsGrid->addWidget(new QLabel("Gen Mode:"), r, 2);
    auto *ppsMode = new QComboBox;
    ppsMode->addItems({"0-Every","1-Even","2-Odd"});
    ppsGrid->addWidget(ppsMode, r, 3);
    ppsGrid->addWidget(new QLabel("Clock:"), r, 4);
    auto *ppsClock = new QComboBox;
    ppsClock->addItems({"0-16MHz","1-32MHz","2-64MHz"});
    ppsGrid->addWidget(ppsClock, r, 5);
    ppsGrid->addWidget(new QLabel("RefTime:"), r, 6);
    auto *ppsRef = new QComboBox;
    ppsRef->addItems({"0-UTC","1-GPS","2-GLONASS","3-UTC_SU","4-GPS_FROM_GLO"});
    ppsGrid->addWidget(ppsRef, r, 7);
    auto *ppsGenBtn = new QPushButton("Cfg PPS Gen");
    ppsGrid->addWidget(ppsGenBtn, r, 8);
    r++;

    // PPS satellite
    ppsGrid->addWidget(new QLabel("EnMix:"), r, 0);
    auto *ppsMix = new QSpinBox; ppsMix->setRange(0, 2);
    ppsGrid->addWidget(ppsMix, r, 1);
    ppsGrid->addWidget(new QLabel("FixCond:"), r, 2);
    auto *ppsFix = new QComboBox;
    ppsFix->addItems({"0-NoFix","1-2D","2-3D"});
    ppsGrid->addWidget(ppsFix, r, 3);
    ppsGrid->addWidget(new QLabel("MinSats:"), r, 4);
    auto *ppsMinSat = new QSpinBox; ppsMinSat->setRange(0, 255);
    ppsGrid->addWidget(ppsMinSat, r, 5);
    ppsGrid->addWidget(new QLabel("ElevMask:"), r, 6);
    auto *ppsElev = new QSpinBox; ppsElev->setRange(0, 255);
    ppsGrid->addWidget(ppsElev, r, 7);
    auto *ppsSatBtn = new QPushButton("Cfg PPS Sat");
    ppsGrid->addWidget(ppsSatBtn, r, 8);
    r++;

    // PPS pulse
    ppsGrid->addWidget(new QLabel("Pol Invert:"), r, 0);
    auto *ppsPol = new QCheckBox("ON");
    ppsGrid->addWidget(ppsPol, r, 1);
    ppsGrid->addWidget(new QLabel("Duration (s):"), r, 2);
    auto *ppsDur = new QDoubleSpinBox;
    ppsDur->setRange(0, 10); ppsDur->setDecimals(6);
    ppsGrid->addWidget(ppsDur, r, 3);
    ppsGrid->addWidget(new QLabel("DelayCorr:"), r, 4);
    auto *ppsDelCorr = new QDoubleSpinBox;
    ppsDelCorr->setRange(-1, 1); ppsDelCorr->setDecimals(6);
    ppsGrid->addWidget(ppsDelCorr, r, 5);
    auto *ppsPulBtn = new QPushButton("Cfg PPS Pulse");
    ppsGrid->addWidget(ppsPulBtn, r, 6);

    // TRAIM
    ppsGrid->addWidget(new QLabel("TRAIM:"), r, 7);
    auto *traimEn = new QCheckBox("ON");
    ppsGrid->addWidget(traimEn, r, 8);
    r++;

    ppsGrid->addWidget(new QLabel("TRAIM Alarm (s):"), r, 0);
    auto *traimAlarm = new QDoubleSpinBox;
    traimAlarm->setRange(0, 100); traimAlarm->setDecimals(3);
    ppsGrid->addWidget(traimAlarm, r, 1);
    auto *traimBtn = new QPushButton("Cfg TRAIM");
    ppsGrid->addWidget(traimBtn, r, 2);

    // Position hold config
    ppsGrid->addWidget(new QLabel("PosHold:"), r, 3);
    auto *posHoldEn = new QCheckBox("ON");
    ppsGrid->addWidget(posHoldEn, r, 4);
    ppsGrid->addWidget(new QLabel("Lat:"), r, 5);
    auto *posHoldLat = new QDoubleSpinBox;
    posHoldLat->setRange(-90, 90); posHoldLat->setDecimals(8);
    ppsGrid->addWidget(posHoldLat, r, 6);
    ppsGrid->addWidget(new QLabel("Lon:"), r, 7);
    auto *posHoldLon = new QDoubleSpinBox;
    posHoldLon->setRange(-180, 180); posHoldLon->setDecimals(8);
    ppsGrid->addWidget(posHoldLon, r, 8);
    r++;

    ppsGrid->addWidget(new QLabel("Height:"), r, 0);
    auto *posHoldHei = new QDoubleSpinBox;
    posHoldHei->setRange(-1500, 100000); posHoldHei->setDecimals(4);
    ppsGrid->addWidget(posHoldHei, r, 1);
    auto *posHoldBtn = new QPushButton("Cfg PosHold");
    ppsGrid->addWidget(posHoldBtn, r, 2);

    // Time data config
    ppsGrid->addWidget(new QLabel("GPS MinWeek:"), r, 3);
    auto *timeMinW = new QSpinBox; timeMinW->setRange(0, 9999);
    ppsGrid->addWidget(timeMinW, r, 4);
    ppsGrid->addWidget(new QLabel("MaxWeek:"), r, 5);
    auto *timeMaxW = new QSpinBox; timeMaxW->setRange(0, 9999);
    ppsGrid->addWidget(timeMaxW, r, 6);
    ppsGrid->addWidget(new QLabel("UTC Delta:"), r, 7);
    auto *timeUtc = new QSpinBox; timeUtc->setRange(-100, 100);
    ppsGrid->addWidget(timeUtc, r, 8);
    r++;

    auto *timeBtn = new QPushButton("Cfg Time Data");
    ppsGrid->addWidget(timeBtn, r, 0, 1, 2);

    // Sat compensation
    ppsGrid->addWidget(new QLabel("SatComp Path:"), r, 2);
    auto *satCompPath = new QSpinBox; satCompPath->setRange(0, 1);
    ppsGrid->addWidget(satCompPath, r, 3);
    ppsGrid->addWidget(new QLabel("Comp:"), r, 4);
    auto *satCompVal = new QDoubleSpinBox;
    satCompVal->setRange(-100, 100); satCompVal->setDecimals(3);
    ppsGrid->addWidget(satCompVal, r, 5);
    auto *satCompBtn = new QPushButton("Cfg SatComp");
    ppsGrid->addWidget(satCompBtn, r, 6);

    for (int i = 0; i < 9; i++)
        ppsGrid->setColumnStretch(i, 1);

    ppsGroup->setLayout(ppsGrid);
    mainLayout->addWidget(ppsGroup);

    // Low Power Algorithm config
    auto *lpGroup = new QGroupBox("Low Power Algorithm Configuration");
    auto *lpGrid = new QGridLayout;
    lpGrid->setSpacing(8);
    lpGrid->setContentsMargins(12, 16, 12, 12);
    r = 0;

    lpGrid->addWidget(new QLabel("Enable:"), r, 0);
    auto *lpEn = new QCheckBox("ON");
    lpGrid->addWidget(lpEn, r, 1);
    lpGrid->addWidget(new QLabel("Feat:"), r, 2);
    auto *lpFeat = new QComboBox;
    lpFeat->addItems({"0-Off","1-Active","3-Standby"});
    lpGrid->addWidget(lpFeat, r, 3);
    lpGrid->addWidget(new QLabel("FixPeriod:"), r, 4);
    auto *lpFixP = new QSpinBox; lpFixP->setRange(0, 86400); lpFixP->setValue(10);
    lpGrid->addWidget(lpFixP, r, 5);
    lpGrid->addWidget(new QLabel("FixOnTime:"), r, 6);
    auto *lpFixOn = new QSpinBox; lpFixOn->setRange(0, 99); lpFixOn->setValue(1);
    lpGrid->addWidget(lpFixOn, r, 7);
    r++;

    lpGrid->addWidget(new QLabel("NoFixCnt:"), r, 0);
    auto *lpNoFix = new QSpinBox; lpNoFix->setRange(0, 99); lpNoFix->setValue(8);
    lpGrid->addWidget(lpNoFix, r, 1);
    lpGrid->addWidget(new QLabel("NoFixCnt2:"), r, 2);
    auto *lpNoFix2 = new QSpinBox; lpNoFix2->setRange(0, 99); lpNoFix2->setValue(60);
    lpGrid->addWidget(lpNoFix2, r, 3);
    lpGrid->addWidget(new QLabel("NoFixOff:"), r, 4);
    auto *lpNoFixOff = new QSpinBox; lpNoFixOff->setRange(0, 99); lpNoFixOff->setValue(180);
    lpGrid->addWidget(lpNoFixOff, r, 5);
    lpGrid->addWidget(new QLabel("Adaptive:"), r, 6);
    auto *lpAdapt = new QCheckBox("ON");
    lpGrid->addWidget(lpAdapt, r, 7);
    r++;

    lpGrid->addWidget(new QLabel("DutyCycle:"), r, 0);
    auto *lpDuty = new QCheckBox("ON");
    lpGrid->addWidget(lpDuty, r, 1);
    lpGrid->addWidget(new QLabel("EHPE Th:"), r, 2);
    auto *lpEhpe = new QSpinBox; lpEhpe->setRange(0, 255); lpEhpe->setValue(15);
    lpGrid->addWidget(lpEhpe, r, 3);
    lpGrid->addWidget(new QLabel("NumSat:"), r, 4);
    auto *lpNumSat = new QSpinBox; lpNumSat->setRange(0, 32); lpNumSat->setValue(9);
    lpGrid->addWidget(lpNumSat, r, 5);
    lpGrid->addWidget(new QLabel("DutyOff ms:"), r, 6);
    auto *lpDutyOff = new QSpinBox; lpDutyOff->setRange(100, 740); lpDutyOff->setValue(700);
    lpGrid->addWidget(lpDutyOff, r, 7);
    auto *lpBtn = new QPushButton("Cfg Low Power Alg");
    lpGrid->addWidget(lpBtn, r, 8);

    for (int i = 0; i < 9; i++)
        lpGrid->setColumnStretch(i, 1);

    lpGroup->setLayout(lpGrid);
    mainLayout->addWidget(lpGroup);

    // Results
    m_resultEdit = new QTextEdit;
    m_resultEdit->setReadOnly(true);
    m_resultEdit->setMaximumHeight(80);
    m_resultEdit->setPlaceholderText("Parameter results...");
    mainLayout->addWidget(m_resultEdit);

    scrollArea->setWidget(scrollWidget);
    auto *outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->addWidget(scrollArea);

    // === Connections ===

    connect(getBtn, &QPushButton::clicked, [this, blockCombo, idSpin]() {
        int block = blockCombo->currentIndex() + 1;
        m_driver->getParameter(block, idSpin->value());
        m_resultEdit->append("GET block=" + QString::number(block) + " id=" + QString::number(idSpin->value()));
    });
    connect(setBtn, &QPushButton::clicked, [this, blockCombo, idSpin, valueEdit]() {
        int block = blockCombo->currentIndex() + 1;
        m_driver->setParameter(block, idSpin->value(), valueEdit->text().toLatin1());
        m_resultEdit->append("SET id=" + QString::number(idSpin->value()) + " val=" + valueEdit->text());
    });
    connect(saveBtn, &QPushButton::clicked, [this]() { m_driver->saveParameters(); m_resultEdit->append("SAVE"); });
    connect(restoreBtn, &QPushButton::clicked, [this]() { m_driver->restoreFactoryParameters(); m_resultEdit->append("RESTORE"); });
    connect(baudBtn, &QPushButton::clicked, [this, baudCombo]() { m_driver->setBaudRate(baudCombo->currentText().toInt()); });
    connect(rateBtn, &QPushButton::clicked, [this, rateSpin]() { m_driver->setFixRate(rateSpin->value()); });
    connect(constBtn, &QPushButton::clicked, [this, gpsCombo, gloCombo, galCombo, bdsCombo]() {
        Teseo::ConstellationConfig cfg;
        cfg.gps = gpsCombo->currentIndex() + 1;
        cfg.glonass = gloCombo->currentIndex() + 1;
        cfg.galileo = galCombo->currentIndex() + 1;
        cfg.beidou = bdsCombo->currentIndex() + 1;
        m_driver->cfgConstellations(cfg);
        m_resultEdit->append("Applied constellations");
    });
    connect(thrBtn, &QPushButton::clicked, [this, trkCn0, posCn0]() {
        m_driver->cfgGnssThresholds(trkCn0->value(), posCn0->value(), 0, 0);
        m_resultEdit->append("Applied thresholds");
    });
    connect(diffBtn, &QPushButton::clicked, [this, diffCombo]() {
        m_driver->setDifferentialSource(diffCombo->currentIndex());
        m_resultEdit->append("Diff source: " + diffCombo->currentText());
    });
    connect(rtcmOn, &QPushButton::clicked, [this]() { m_driver->enableRtcm(true); m_resultEdit->append("RTCM ON"); });
    connect(rtcmOff, &QPushButton::clicked, [this]() { m_driver->enableRtcm(false); m_resultEdit->append("RTCM OFF"); });
    connect(rtcmPortBtn, &QPushButton::clicked, [this, rtcmPort, rtcmBaud]() {
        m_driver->cfgRtcmPort(rtcmPort->value());
        m_driver->cfgRtcmBaudRate(rtcmBaud->value());
        m_resultEdit->append("RTCM port=" + QString::number(rtcmPort->value()));
    });
    connect(rtcmSend, &QPushButton::clicked, [this, rtcmDataEdit]() {
        QByteArray data = QByteArray::fromHex(rtcmDataEdit->text().toLatin1());
        m_driver->sendRtcmData(data);
        m_resultEdit->append("Sent RTCM: " + QString::number(data.size()) + " bytes");
    });

    // Port config
    connect(uartBtn, &QPushButton::clicked, [this, uartPort, uartBaud]() {
        m_driver->cfgPortUart(uartPort->value(), uartBaud->currentText().toInt());
        m_resultEdit->append("Cfg UART port=" + QString::number(uartPort->value()));
    });
    connect(i2cBtn, &QPushButton::clicked, [this, i2cAddr]() {
        m_driver->cfgPortI2c(i2cAddr->text().toInt(nullptr, 16));
        m_resultEdit->append("Cfg I2C addr=0x" + i2cAddr->text());
    });
    connect(msgBtn, &QPushButton::clicked, [this, msgListId, msgRate, msgLow, msgHigh]() {
        m_driver->cfgMessageList(msgListId->value(), msgRate->value(),
            msgLow->text().toUInt(nullptr, 16), msgHigh->text().toUInt(nullptr, 16));
        m_resultEdit->append("Cfg MsgList");
    });

    // GNSS algorithm
    connect(gnssBtn, &QPushButton::clicked, [this, gnssTrkCn0, gnssPosCn0, gnssTrkAngle, gnssPosAngle]() {
        m_driver->cfgGnss(gnssTrkCn0->value(), gnssPosCn0->value(),
            gnssTrkAngle->value(), gnssPosAngle->value(), 0, 0, 0);
        m_resultEdit->append("Cfg GNSS algorithm");
    });

    // SBAS config
    connect(sbasCfgBtn, &QPushButton::clicked, [this, sbasEn, sbasRep, sbasAuto, sbasSvc]() {
        Teseo::SBASConfig cfg;
        cfg.engineEnabled = sbasEn->isChecked();
        cfg.reportEnabled = sbasRep->isChecked();
        cfg.autoSearch = sbasAuto->isChecked();
        cfg.service = sbasSvc->currentText().split('-').first().toInt();
        m_driver->cfgSbas(cfg);
        m_resultEdit->append("Cfg SBAS");
    });

    // Geofence
    connect(geoBtn, &QPushButton::clicked, [this, geoEn, geoTol]() {
        m_driver->cfgGeofence(geoEn->isChecked(), geoTol->value());
        m_resultEdit->append("Cfg Geofence");
    });
    connect(geoCirBtn, &QPushButton::clicked, [this, geoCirId, geoCirEn, geoCirLat, geoCirLon, geoCirRad]() {
        m_driver->cfgGeofenceCircle(geoCirId->value(), geoCirEn->isChecked(),
            geoCirLat->value(), geoCirLon->value(), geoCirRad->value());
        m_resultEdit->append("Cfg Geofence Circle " + QString::number(geoCirId->value()));
    });

    // PPS config
    connect(ppsGenBtn, &QPushButton::clicked, [this, ppsEn, ppsMode, ppsClock, ppsRef]() {
        m_driver->cfgPpsGeneral(ppsEn->isChecked(), ppsMode->currentIndex(),
            ppsClock->currentIndex(), ppsRef->currentIndex());
        m_resultEdit->append("Cfg PPS General");
    });
    connect(ppsSatBtn, &QPushButton::clicked, [this, ppsMix, ppsFix, ppsMinSat, ppsElev]() {
        m_driver->cfgPpsSatellite(ppsMix->value(), ppsFix->currentIndex(),
            ppsMinSat->value(), ppsElev->value());
        m_resultEdit->append("Cfg PPS Satellite");
    });
    connect(ppsPulBtn, &QPushButton::clicked, [this, ppsPol, ppsDur, ppsDelCorr]() {
        m_driver->cfgPpsPulse(ppsPol->isChecked(), ppsDur->value(), ppsDelCorr->value());
        m_resultEdit->append("Cfg PPS Pulse");
    });

    // TRAIM
    connect(traimBtn, &QPushButton::clicked, [this, traimEn, traimAlarm]() {
        m_driver->cfgTraim(traimEn->isChecked(), traimAlarm->value());
        m_resultEdit->append("Cfg TRAIM");
    });

    // Position hold
    connect(posHoldBtn, &QPushButton::clicked, [this, posHoldEn, posHoldLat, posHoldLon, posHoldHei]() {
        m_driver->cfgPositionHold(posHoldEn->isChecked(),
            posHoldLat->value(), posHoldLon->value(), posHoldHei->value());
        m_resultEdit->append("Cfg Position Hold");
    });

    // Time data
    connect(timeBtn, &QPushButton::clicked, [this, timeMinW, timeMaxW, rateSpin, timeUtc]() {
        m_driver->cfgTimeData(timeMinW->value(), timeMaxW->value(),
            rateSpin->value(), timeUtc->value());
        m_resultEdit->append("Cfg Time Data");
    });

    // Sat compensation
    connect(satCompBtn, &QPushButton::clicked, [this, satCompPath, satCompVal]() {
        m_driver->cfgSatCompensation(satCompPath->value(), satCompVal->value());
        m_resultEdit->append("Cfg Sat Compensation");
    });

    // Low power algorithm
    connect(lpBtn, &QPushButton::clicked, [this, lpEn, lpFeat, lpFixP, lpFixOn,
            lpNoFix, lpNoFix2, lpNoFixOff, lpAdapt, lpDuty, lpEhpe, lpNumSat, lpDutyOff]() {
        m_driver->cfgLowPowerAlgorithm(
            lpEn->isChecked() ? 1 : 0, lpFeat->currentIndex(),
            lpFixP->value(), lpFixOn->value(),
            lpNoFix->value(), lpNoFix2->value(), lpNoFixOff->value(),
            lpAdapt->isChecked() ? 1 : 0, lpDuty->isChecked() ? 1 : 0,
            lpEhpe->value(), lpNumSat->value(), lpDutyOff->value(), 0);
        m_resultEdit->append("Cfg Low Power Algorithm");
    });

    connect(m_driver, &Teseo::TeseoDriver::parameterReceived,
            this, [this](int id, const QByteArray &value) {
        m_resultEdit->append("Param ID=" + QString::number(id) + " Value=" + value);
    });
}
