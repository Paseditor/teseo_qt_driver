# ArneeCode | Teseo-VIC3 Qt Driver

**Copyright (c) 2026 ArneeCode. All rights reserved.**

---

Qt 5.15.2 драйвер для GNSS модуля STMicroelectronics Teseo-VIC3 с поддержкой Dead Reckoning, RTCM дифференциальных коррекций, AGNSS и полным GUI тестером.

Документация на модуль: UM2791 Rev 3 (Teseo-VIC3 software instructions).

---

## Возможности

- **NMEA парсинг**: GGA, RMC, GSA, GSV, VTG, ZDA, GST, GBS, GNS, DTM + все $PSTM проприетарные сообщения
- **RTCM 2.3**: Дифференциальные коррекции (типы 1, 9, 31, 34)
- **Dead Reckoning**: Teseo-DRAW с Map Matching Feedback и Sensors Over UART
- **AGNSS**: ST-AGNSS (автономный), Real-Time AGNSS (серверный)
- **Низкое энергопотребление**: Adaptive, Cyclic, Standby Periodic режимы
- **PPS**: Генерация импульсов с TRAIM
- **Геозоны**: До 8 кругов с настраиваемым допуском
- **I2C**: Альтернативный интерфейс связи

---

## Архитектура

```
teseo_qt_driver/
│
├── src/                              # Статическая библиотека
│   ├── teseo_types.h                 #   Структуры данных (Position, Satellite, GnssData, ...)
│   ├── teseo_driver.h/cpp            #   Основной класс драйвера (70+ методов)
│   ├── nmea_parser.h/cpp             #   Парсер NMEA 0183 + $PSTM ответов
│   └── serial_interface.h/cpp        #   UART через QSerialPort
│
├── gui/                              # GUI тестер (Qt Widgets)
│   ├── splashscreen.h                #   Splash screen с ArneeCode branding
│   ├── style.h                       #   Modern dark theme (slate/cyan палитра)
│   ├── main.cpp                      #   Точка входа + splash
│   ├── mainwindow.h/cpp              #   Главное окно с вкладками
│   ├── connectionpage.h/cpp          #   Вкладка подключения
│   ├── infopage.h/cpp                #   Live GNSS данные + таблица спутников
│   ├── commandpage.h/cpp             #   Команды управления
│   ├── configpage.h/cpp              #   CDB конфигурация + RTCM
│   ├── agnsspage.h/cpp               #   AGNSS инициализация
│   ├── deadreckoningpage.h/cpp       #   Dead Reckoning / MMFB / SoU
│   └── logpage.h/cpp                 #   NMEA лог
│
├── tests/                            # Unit тесты (Qt Test)
│   ├── test_types.h/cpp              #   Тесты типов данных
│   ├── test_checksum.h/cpp           #   Тесты NMEA чексумм
│   ├── test_nmea_parser.h/cpp        #   Тесты парсера (GGA, RMC, GSA, GSV, VTG, ZDA, GST)
│   └── test_main.cpp                 #   Запуск всех тестов
│
├── example/                          # Консольный пример
│   └── main.cpp
│
└── docs/
    └── um2791-*.md                   # Документация STMicroelectronics
```

---

## Сборка

Требования: Qt 5.15.2, MinGW 8.1+ (или MSVC 2019).

```bash
# Настройка PATH (MinGW)
set PATH=C:\Qt\QT5.15\Tools\mingw1120_64\bin;C:\Qt\QT5.15\5.15.2\mingw81_64\bin;%PATH%

# 1. Библиотека
cd teseo_qt_driver
qmake teseo_qt_driver.pro
mingw32-make

# 2. GUI тестер
cd gui
qmake gui.pro
mingw32-make

# 3. Тесты
cd tests
qmake tests.pro
mingw32-make
```

---

## Запуск

```bash
# GUI тестер
gui\release\teseo_tester.exe

# Unit тесты
tests\release\teseo_tests.exe
```

---

## Покрытие команд (все из UM2791)

| Группа | Методы | Описание |
|--------|--------|----------|
| **Старт** | `hotStart()` `warmStart()` `coldStart()` `systemReset()` `gnssReset()` `gnssSuspend()` `gnssRestart()` | Все режимы запуска и сброса |
| **Инициализация** | `initGps()` `initTime()` `initFrequency()` `setFrequencyRange()` | Внедрение позиции/времени/частоты |
| **Нав. данные** | `loadAlmanac()` `clearAlmanacs()` `dumpAlmanacs()` `loadEphemeris()` `clearEphemeris()` `dumpEphemeris()` | Управление алманахами и эфемеридами |
| **Созвездия** | `setConstellationMask()` `cfgConstellations()` | GPS/GLONASS/Galileo/BeiDou/QZSS |
| **SBAS** | `setSbasService()` `setSbasSatellite()` `sendSbasFrame()` `toggleSbas()` `cfgSbas()` | WAAS/EGNOS/MSAS/GAGAN |
| **RTCM** | `sendRtcmData()` `enableRtcm()` `setDifferentialSource()` `cfgRtcmPort()` `cfgRtcmBaudRate()` | Дифференциальные коррекции RTCM 2.3 |
| **PPS** | `ppsSetOnOff()` `ppsSetOutMode()` `ppsSetReferenceTime()` `ppsSetPulseDelay()` `ppsSetPulseDuration()` `ppsSetPulsePolarity()` `ppsSetFixCondition()` `ppsSetSatThreshold()` `ppsSetElevationMask()` `ppsSetConstellationMask()` `ppsSetTimingData()` `ppsSetPositionHoldData()` `ppsSetAutoHoldSamples()` `ppsSetTraim()` | Полное управление PPS |
| **Конфигурация** | `setParameter()` `getParameter()` `saveParameters()` `restoreFactoryParameters()` | CDB параметры |
| **Порты** | `cfgPortUart()` `cfgPortI2c()` `cfgMessageList()` | UART/I2C конфигурация |
| **Алгоритмы** | `cfgGnss()` `cfgGnssThresholds()` `cfgAntiJamming()` `setNotchFilter()` `setTrackingThresholds()` `setPositioningThresholds()` `cfgSatCompensation()` | FDE, ANF, CN0 пороги |
| **Низкое энерго-потребление** | `setLowPowerMode()` `disableLowPowerMode()` `setStandbyEnable()` `getStandbyStatus()` `forceStandby()` `cfgLowPowerAlgorithm()` | Adaptive/Cyclic/Periodic |
| **Позиция** | `enablePositionHold()` `cfgPositionHold()` | Position Hold |
| **Датум** | `selectDatum()` `setDatumParameters()` | WGS84, Tokyo, OSGB, ... |
| **Одометр** | `cfgOdometer()` | Odometer + сообщения |
| **Геозоны** | `cfgGeofence()` `cfgGeofenceCircle()` | До 8 кругов |
| **Dead Reckoning** | `sendMapMatchingFeedback()` `sendSensorMessage()` `drCalibrateTilt()` `drSaveToNvm()` | DRAW MMFB + SoU |
| **AGNSS** | `stagpsOnOff()` `stagpsInvalidate()` `stagpsGetStatus()` `stagpsSetConstellationMask()` `stagpsGeneratePassword()` `cfgAgps()` | ST-AGNSS + Real-Time |
| **Galileo** | `setGalileoGgto()` `dumpGalileoGgto()` | GGTO |
| **IMU/Лог** | `imuSelfTest()` `cfgLog()` | Тест IMU, логирование |
| **Прочее** | `invalidateGnssFix()` `invalidateRtc()` `getSoftwareVersion()` `nvmSwap()` `rfTestOn()` `rfTestOff()` `getAlgorithmStatus()` `setAlgorithmStatus()` `getRtcTime()` `getUniqueCode()` `cfgTimeData()` | Разное |
| **Произвольная** | `sendCommand("$PSTM...")` | Любая команда |

---

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
PASS   : TestChecksum::validChecksum()
PASS   : TestChecksum::invalidChecksum()
PASS   : TestChecksum::computeChecksum()
PASS   : TestChecksum::noStarReturnsInvalid()
PASS   : TestTypes::fixQualityEnum()
PASS   : TestTypes::constellationEnum()
PASS   : TestTypes::positionDecimal()
Totals: 17 passed, 0 failed
```

---

## Использование библиотеки

```cpp
#include "teseo_driver.h"

Teseo::TeseoDriver driver;

// Подключение
driver.connectDevice("COM3", 115200);

// Подключение сигналов
connect(&driver, &Teseo::TeseoDriver::fixUpdated,
        [](const Teseo::GnssData &data) {
    if (data.valid) {
        qDebug() << "Lat:" << data.position.latitudeDecimal()
                 << "Lon:" << data.position.longitudeDecimal()
                 << "Alt:" << data.position.altitude;
    }
});

// Команды
driver.hotStart();
driver.setConstellationMask(3);  // GPS + GLONASS
driver.enableSbasAuto();

// RTCM
driver.enableRtcm(true);
driver.setDifferentialSource(2);  // RTCM
driver.sendRtcmData(rtcmByteArray);

// Dead Reckoning
driver.sendMapMatchingFeedback("120000.000", true, true,
                                55.751244, 37.618423);

// Произвольная команда
driver.sendCommand("$PSTMGETSWVER,255");
```

---

## GUI Тестер

7 вкладок с полным покрытием функциональности:

| Вкладка | Функции |
|---------|---------|
| **Connection** | Выбор COM порта, baud rate, connect/disconnect с индикацией |
| **GNSS Info** | Live координаты, скорость, курс, DOP, EHPE, таблица спутников |
| **Commands** | Hot/Warm/Cold start, созвездия, SBAS, PPS, FDE, RF test, IMU, custom |
| **Configuration** | CDB GET/SET, baud rate, fix rate, constellations, thresholds, RTCM |
| **AGNSS** | Init GPS/Time, частота, ST-AGNSS, dump/clear алманахи/эфемериды |
| **Dead Reckoning** | MMFB, SoU сенсоры, калибровка, одометр, anti-jamming |
| **Log** | Полный NMEA лог с фильтрами, паузой, подсветкой $PSTM |

---

## Дизайн

- **Тема**: Modern dark (slate #0a0e1a + cyan #00d4ff акценты)
- **Splash screen**: ArneeCode branding с GNSS иконкой
- **Иконки**: Unicode символы для навигации
- **Контраст**: Яркие акценты на тёмном фоне
- **Шрифт**: Segoe UI (UI) + Cascadia Code (лог)

---

## Сенсоры для Dead Reckoning (SoU)

| ID | Сенсор | Частота |
|----|--------|---------|
| 1 | Odometer | 5 Hz |
| 2 | Reverse gear | 1 Hz |
| 4 | 1-axis Gyro | 100 Hz |
| 9 | Rear L/R wheel pulses | 5 Hz |
| 14 | Speed | 5 Hz |
| 18 | Rear L/R wheel speeds | 5 Hz |
| 30 | 3-axis Accelerometer | 100 Hz |
| 31 | 3-axis Gyroscope | 100 Hz |
| 32 | Barometer | 1 Hz |

---

## CDB конфигурация (часто используемые)

| CDB ID | Описание | По умолчанию |
|--------|----------|--------------|
| 102 | UART baud rate | 0xA (115200) |
| 120 | Cold start mask | 0xE |
| 122 | NMEA format | 0x0C |
| 125 | Notch filter | 0x0 |
| 128 | Differential source | 0x0 (NONE) |
| 138 | RTCM port | - |
| 139 | RTCM baud rate | - |
| 200 | Application ON/OFF bitmap | - |
| 227 | Application ON/OFF (high) | - |
| 600 | DRAW main setting | - |
| 667 | DRAW algorithm ON/OFF | - |
