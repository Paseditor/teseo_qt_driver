# ArneeCode | Teseo-VIC3 Qt Driver

**Copyright (c) 2024 ArneeCode. All rights reserved.**

Qt 5.15.2 драйвер для GNSS модуля STMicroelectronics Teseo-VIC3 (UM2791 Rev 3).

## Структура

```
teseo_qt_driver/
├── src/                          # Библиотека (staticlib)
│   ├── teseo_types.h             # Все структуры данных
│   ├── teseo_driver.h/cpp        # Драйвер с ВСЕМИ командами
│   ├── nmea_parser.h/cpp         # Парсер NMEA + $PSTM
│   └── serial_interface.h/cpp    # UART (QSerialPort)
├── gui/                          # GUI тестер
│   ├── splashscreen.h            # Splash screen ArneeCode
│   ├── style.h                   # Modern dark theme
│   ├── mainwindow.h/cpp          # Главное окно
│   ├── connectionpage.h/cpp      # Подключение
│   ├── infopage.h/cpp            # Live GNSS данные
│   ├── commandpage.h/cpp         # Команды
│   ├── configpage.h/cpp          # Конфигурация + RTCM
│   ├── agnsspage.h/cpp           # AGNSS
│   ├── deadreckoningpage.h/cpp   # Dead Reckoning
│   └── logpage.h/cpp             # Лог
├── tests/                        # Unit тесты
│   ├── test_types.cpp            # Тесты типов данных
│   ├── test_checksum.cpp         # Тесты чексумм
│   └── test_nmea_parser.cpp      # Тесты парсера NMEA
└── docs/
    └── um2791-*.md               # Документация
```

## Сборка

```bash
set PATH=C:\Qt\QT5.15\Tools\mingw1120_64\bin;C:\Qt\QT5.15\5.15.2\mingw81_64\bin;%PATH%

# Библиотека
cd teseo_qt_driver && qmake && mingw32-make

# GUI тестер
cd gui && qmake && mingw32-make

# Тесты
cd tests && qmake && mingw32-make
```

## Запуск

```bash
# GUI
gui\release\teseo_tester.exe

# Тесты
tests\release\teseo_tests.exe
```

## Покрытие команд

| Группа | Команды |
|--------|---------|
| Старт/Сброс | hotStart, warmStart, coldStart, systemReset, gnssReset, gnssSuspend, gnssRestart |
| Инициализация | initGps, initTime, initFrequency, setFrequencyRange |
| Навигационные данные | loadAlmanac, clearAlmanacs, dumpAlmanacs, loadEphemeris, clearEphemeris, dumpEphemeris |
| Созвездия | setConstellationMask, cfgConstellations |
| SBAS | setSbasService, setSbasSatellite, sendSbasFrame, toggleSbas, cfgSbas |
| RTCM | sendRtcmData, enableRtcm, setDifferentialSource, cfgRtcmPort, cfgRtcmBaudRate |
| PPS | ppsSet/Get (on/off, outMode, refTime, pulseDelay, duration, polarity, fixCond, satTh, elevMask, constMask, timingData, posHold, autoHold, traim, rfDelay) |
| Конфигурация | setParameter, getParameter, saveParameters, restoreFactoryParameters |
| Порты | cfgPortUart, cfgPortI2c, cfgMessageList |
| Алгоритмы | cfgGnss, cfgGnssThresholds, cfgAntiJamming, setNotchFilter |
| Низкое энергопотр. | setLowPowerMode, disableLowPowerMode, setStandbyEnable, getStandbyStatus, forceStandby |
| PPS конфиг | cfgPpsGeneral, cfgPpsSatellite, cfgPpsPulse, cfgTraim |
| Позиция | enablePositionHold, cfgPositionHold |
| Датум | selectDatum, setDatumParameters |
| Одометр/Геозона | cfgOdometer, cfgGeofence, cfgGeofenceCircle |
| Dead Reckoning | sendMapMatchingFeedback, sendSensorMessage, drCalibrateTilt, drSaveToNvm |
| AGNSS | stagpsOnOff, stagpsInvalidate, stagpsGetStatus, stagpsSetConstellationMask, cfgAgps |
| Galileo | setGalileoGgto, dumpGalileoGgto |
| IMU/Логирование | imuSelfTest, cfgLog |
| Прочее | invalidateGnssFix, invalidateRtc, getSoftwareVersion, nvmSwap, rfTestOn/Off, getAlgorithmStatus, setAlgorithmStatus, getRtcTime, getUniqueCode, cfgTimeData |
| Произвольная | sendCommand("$PSTM...") |

## Тесты

```
********* Start testing of TestNmeaParser *********
PASS   : TestNmeaParser::parseGGA()
PASS   : TestNmeaParser::parseRMC()
PASS   : TestNmeaParser::parseGSA()
PASS   : TestNmeaParser::parseGSV()
PASS   : TestNmeaParser::parseVTG()
PASS   : TestNmeaParser::parseZDA()
PASS   : TestNmeaParser::parseGST()
PASS   : TestNmeaParser::parseMultiple()
PASS   : TestNmeaParser::invalidChecksumIgnored()
PASS   : TestNmeaParser::partialDataBuffered()
Totals: 12 passed, 0 failed
```
