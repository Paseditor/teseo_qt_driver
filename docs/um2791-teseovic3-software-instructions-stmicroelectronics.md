**UM2791** 

User manual 

**==> picture [135 x 36] intentionally omitted <==**

## Teseo-VIC3 software instructions 

## **Introduction** 

The Teseo-VIC3 modules are easy to use dead-reckoning global navigation satellite system (GNSS) stand-alone module, embedding Teseo III single die stand-alone positioning receiver IC working on multiple constellations (GPS/Galileo/Glonass/ BeiDou/QZSS) and ST 3D IMU sensors to support Teseo dead reckoning automotive way (Teseo-DRAW) or Teseo dead reckoning unplugged mode (Teseo-DRUM). 

Teseo-VIC3 modules are designed for top performance in a minimal space and it has been optimized for cost sensitive applications without quality compromise. They allow, at competitive costs, an easy integration and migration from existing designs of products. 

Within their 16x12.2 mm compact size, they are offering superior accuracy, a reduced time to first fix (TTFF) and deadreckoning capability. The devices are offered with a complete dead reckoning GNSS firmware which performs all GNSS operations including acquisition, tracking, sensors fusion and navigation and data output with no need of external memories. 

**Table 1. ST GNSS Teseo-VIC3x supported devices** 

|**Device Type**|**Firmware version**|**Device grade**|
|---|---|---|
|Teseo-VIC3DA|Teseo-DRAW|Automotive grade|
|Teseo-VIC3D|Teseo-DRAW|Industrial grade|



**UM2791** - **Rev 3** - **July 2023** For further information contact your local STMicroelectronics sales office. 

www.st.com 

**UM2791 Document management** 

## **1 Document management** 

## **1.1 Acronyms and definitions** 

**Table 2. Acronyms** 

|**Keyword**|**Definition**|
|---|---|
|Accuracy|Deviation of a GPS-based calculated position from the true position|
|ADC|Analogue to Digital Converter|
|Almanac|Contains the information about all available satellites, their orbit data and time of their<br>clocks.|
|ANF|Adaptive Notch Filter|
|Azim|Azimuth - Angular distance from a reference|
|Bank Swap|Exchanging two memory banks for storage of data|
|BAUD rate|Transmission Rate Measure for the effective transmission of data content. (may differ from<br>Bits/sec).|
|BeiDou|China’s regional navigation satellite system|
|Checksum|Calculated from the transmitted characters of a message by “ex-OR”ing the 8 bit character<br>values excluding delimiters $ and *|
|CN0|Carrier to Noise Ratio - Identifies the quality of a received signal|
|Cold Start|Start Condition for a GPS system having no position nor time. Almanac and Ephemeris is<br>not available, too.|
|BeiDou|China’s global navigation satellite system (also known as Beidou-2, BD2)|
|Dead Reckoning|Sensor based process to determine the movement of a mobile unit, utilizing Gyro,<br>Odometer and Wheel Pulses.|
|Delimiter<br>(within NMEA 0183)|ASCII “$” to indicate Address Field<br>ASCII “,” to indicate Data Field<br>ASCII “*” to indicate Checksum Field|
|DGPS|Differential GPS - GPS Augmentation System providing the accurate location of a<br>Reference Station to reduce system errors.|
|EGNOS|European Geostationary Navigation Overlay System|
|Elev|Elevation - Angle between a high level or non-earth bound point and the horizontal plane<br>of the viewer.|
|Ephemeris|Ephemeris Data is transmitted by each satellite and contains current and predicted<br>satellite position.|
|FDA|Failure Detection Algorithm - Specific Algorithm to detect failures in position calculation|
|FDE|False Detection Exclusion|
|GALILEO|Europe’s global navigation satellite system|
|GDOP|Geometric Dilution Of Position - Quality value representing all geometry based error<br>factors in a system.|
|GNSS|Global Navigation Satellite System - Satellite based system to calculate the position of the<br>Teseo on the earth surface.|
|GPS|Global Positioning System - United States Satellite Navigation System|
|GPS Library|STMicroelectronics C-Library containing all GPS relevant Functions|
|Gyro|Gyroscope - Sensor to determine rotational movements|



**UM2791** - **Rev 3** 

**page 2/241** 

**UM2791 Acronyms and definitions** 

|**Keyword**|**Definition**|
|---|---|
|HDOP|Horizontal Dilution Of Precision - Quality value representing all 2D plane geometry based<br>error factors in a system.|
|Hot Start|Start Condition for a GPS System having position, time, Almanac and Ephemeris already<br>available. High time accuracy is required.|
|IMU|Inertial Measurement Unit|
|Lat|Lattitude - Angular difference of a given position to the Equator. Values include 0°-90°<br>either North or South|
|Lat-Ref|Lattitude Reference - Reference if a Latitude value is North or South|
|Long|Longitude - Angular difference to a “reference” Longitude indicated as “000”. Values<br>include 0°… 180° either West or East.|
|Long-Ref|Longitude Reference - Reference if a Longitude value is East or West of the “000”<br>Meridian.|
|NMEA|National Marine Electronics Association - United States Standards Organisation For<br>Marine Equipment|
|NMEA 0183|National Marine Electronics Association - Standard for Interfacing Marine Electronics<br>Devices|
|NVM|Non Volatile Memory - Any type of memory that conserves data in the absence of regular<br>supply voltage (includes battery buffered memories)|
|Proprietary Message|Messages within the scope of NMEA0183 which are not standardized. They start with $P<br>and a 3 character identifier.|
|PRN|Pseudo Random Number - Satellite Specific 1023 Bit Number used for Spread Spectrum<br>Modulation|
|RAIM|Teseo Autonomous Integrity Monitoring|
|RF|Radio Frequency - High Frequency for Reception with a RF-Teseo|
|RS232|IEEE Standard - Physical Layer Standard for Data Transmission|
|Sat-ID|Satellite Identifier - Satellite specific Number used to generate the corresponding PRN<br>code|
|SBAS|Satellite Based Augmentation System - GPS enhancement system based on<br>geostationary satellites.|
|SPS|Standard Positioning Service|
|Static Position Filtering|Algorithm to detect that the GPS Teseo doesn´t move and position output is kept stable.|
|UTC|Universal Time Coordinated|
|WAAS|Wide Area Augmentation System - American GPS Augmentation System delivering<br>accurate Ionosphere Data|
|Warm Start|Start Condition for a GPS system having current Almanac, position and time availability.<br>Ephemeris are not available. Time needs to be available with reasonable accuracy (some<br>seconds).|
|2D Fix|Fix based on the use of 3 satellites|
|3D Fix|Fix based on the use of 4 satellites|



**UM2791** - **Rev 3** 

**page 3/241** 

**UM2791 Teseo-VIC3 binary introduction** 

## **2 Teseo-VIC3 binary introduction** 

The Teseo-Module embeds a pre-builded and configured Teseo dead-reckoning automotive way (Teseo-DRAW) software or Teseo dead-reckoning unplugged mode (Teseo-DRUM) running able to provide a complete PVTdead-reckoning platform solution. 

## **2.1** 

## **Binary configuration** 

The Teseo-Module binary image supports the firmware configuration facility. It allows changing some application parameters in order to address most of the specific customer’s constraints and/or the final product functionality requirements. 

The firmware configuration management supports the “factory setting”, embedded in the binary code, and the “customized setting”, stored in the Teseo-Module backup memory (NVM). The “factory setting” can be changed and saved at run-time using specific NMEA commands. 

Teseo-Module binary image software is released with the ST defined default setting (factory setting). 

## **2.1.1** 

## **Configuration concept** 

All configuration parameters are grouped in a data block. Each field is addressed by a unique ID. The IDs are made by three digits: the most significant one represents the parameter type and the others are used to identify different parameters of the same type. 

Default setting of configuration data block is hard coded into the binary image file. 

When the system is running, it could be possible to have up to three different configuration blocks as shown in the following figure. 

- _Current configuration_ : it is placed in RAM memory and it includes the current configuration of each parameter. At start-up, the current configuration block is loaded from NVM (if a stored data block is available) or it is loaded from the default one embedded in the code (factory settings). 

- _Default configuration_ : it is generally placed in the flash/rom memory. It includes the factory setting for each parameter. This configuration is used at system startup if there is no configuration data into the NVM memory. 

- _NVM stored configuration_ : it is available in the NVM backup. It includes all parameters modified and stored by the user. At system startup the SW configuration management checks if a valid configuration block is available in the NVM backup memory. In case the stored configuration is available, it will be used for system configuration. If not available the default setting will be used. 

**Figure 1. Binary configuration data block** 

**UM2791** - **Rev 3** 

**page 4/241** 

**UM2791 Binary version** 

Teseo-Module always uses only the current configuration. 

Current configuration will be lost when there is: 

- a power cycle 

- an hardware reset 

- a software reset 

The current configuration can be made permanent (stored in a non-volatile memory) by saving it to the " _NVM stored configuration_ ". 

On NMEA protocol the run-time configuration parameters can be read, changed and stored (in NVM) using the system configuration commands: $PSTMSETPAR, $PSTMGETPAR and $PSTMSAVEPAR. There is also a command to restore the factory setting parameters: $PSTMRESTOREPAR. 

For example if the UART baud rate could be changed the following commands should be sent by the host: 

## `1. $PSTMSETPAR,3102,0x9` 

`2. $PSTMSAVEPAR` 

`3. $PSTMSRR` 

Where: 

1. `$PSTMSETPAR changes the UART’s baud rate;` 

2. `$PSTMSAVEPAR saves the whole configuration;` 

3. `$PSTMSRR restarts the Teseo-VIC3 to guarantee that the change made are effectives;` 

## **2.2** 

## **Binary version** 

The binary firmware version defines which set of messages the Teseo-Module is able to manage. The command $PSTMGETSWVER returns the firmware and all software versions in string format. 

While booting the Teseo-Module reports on the serial port the current configuration as showed in the following figure: Teseo-Module booting message from UART. 

**Figure 2. Teseo-Module booting message from UART** 

Each entry of Teseo-Module firmware subsystem version identifies a specific binary firmware subsystem version. 

**UM2791** - **Rev 3** 

**page 5/241** 

**UM2791 Firmware update algorithm protocol** 

**Table 3. Teseo-Module firmware subsystem version** 

|**Entry**|**Description**|
|---|---|
|PSTMVER,GNSSLIB_8.4.14.21_ARM|GNSS Library Version|
|PSTMVER,OS20LIB_4.3.0_ARM|OS20 Version|
|PSTMVER,GPSAPP_2.8_ARM|GPS App Version|
|PSTMVER,BINIMG_4_x_12VERSIONE_SUFFIX_ARM|Binary Image Version|
|PSTMVER,SWCFG_81065329|Sw configuration Version|
|PSTMVER,STAGPSLIB_6.0.0_ARM|AGPS Library Version|
|PSTMVER,STA8090_622bc043|Chip Version|
|GPTXT,(C)2000-2018 ST Microelectronics|Log message|
|GPTXT, DEFAULT CONFIGURATION|Log message|



The _Binary Image Version_ covers all the firmware subsystem, therefore on every firmware subsystem update the binary image version updates as well. 

## **2.3 Firmware update algorithm protocol** 

Teseo-Module supports the firmware upgrade on field. 

## **2.3.1 Firmware update on reset** 

The firmware update procedure on reset can be triggered from the host only on a Power-On/Reset (POR); after a POR, Teseo-Module executes sequentially three actions as indicated in the following figure. 

1. Teseo-Module initializes its-self (ROM booting windows) 

2. Teseo-Module enters (firmware update windows) in polling mode on all the port interfaces to check if the host wants to trigger a firmware update procedure 

3. If the timeout in step 2 fires the Teseo-Module will enter in the normal mode; while if in step 2 a requestfirmware-update is detected, on an interface port, the Teseo-Module will enter in firmware update mode 

## **Figure 3. Teseo-Module operations from Power-on/reset** 

The host has to manage two kind of reset depending on the elapse time the host has to wait from POR to operate with Teseo-Module: 

- **Standard reset** : this is a normal reset required when the host wants Teseo-Module resetted and again up and running. In this case the host has to wait from PoR 500 ms before it can operate with Teseo-Module. No command has to be sent on the Teseo-Module’s interface until the _Standard-reset-timing_ elapses. 

**UM2791** - **Rev 3** 

**page 6/241** 

**UM2791** 

**Firmware update algorithm protocol** 

- **Firmware update reset** : this is the reset required when the host wants trigger a firmware update procedure, in this case host has to wait from PoR 100 ms (ROM booting windows) and during the firmware update windows it has to send the request firmware command 

Both the host and Teseo-Module have to follow a well-defined protocol. 

**Caution:** Take care that during the whole firmware upgrade procedure the voltage VCC and VBAT must remain applied and stable; a power outage, during the firmware upgrade procedure, could force the Teseo-Module in an unrecoverable state. 

Firmware upgrade has a preliminary phase to synchronize the Host and the Teseo-Module. 

Just after the synchronization with the device, the host must send the binary image options (the same as firmware update over NMEA). 

The firmware upgrade procedure on reset is shown below. 

**UM2791** - **Rev 3** 

**page 7/241** 

**UM2791** 

**Firmware update algorithm protocol** 

**Figure 4. Teseo-Module firmware upgrade procedure on reset** 

Firmware upgrade on reset procedure, on Teseo-Module, uses the constants shown in the following table: 

**UM2791** - **Rev 3** 

**page 8/241** 

**UM2791 Firmware update algorithm protocol** 

**Table 4. Firmware upgrade on reset constants** 

|**Constants**|**Value**|
|---|---|
|TESEO_FLASHER_IDENTIFIER|0xBCD501F4|
|TESEO_FLASHER_SYNC|0x83984073|
|DEVICE_START_COMMUNICATION|0xA3|
|FLASHER_READY|0x4A|
|ACK|0xCC|
|NAK|0xDD|
|NVM_FLASH_OFFSET|0x00100000|
|NVM_FLASH_ERASE_SIZE|0x00100000|



**UM2791** - **Rev 3** 

**page 9/241** 

**UM2791 Communication channels** 

## **3 Communication channels** 

Teseo-Module has several independent communication channels. 

Each channel can operate with a specific protocol (see protocol specification) 

Users can select the channel based on their needs. 

Teseo-Module receiver supports the following communication channels: 

- UART channel; 

- I2C channel 

**Figure 5. Teseo-Module protocol routing over the available ports** 

## **3.1 Communication over UART port** 

Teseo-Module receiver and Host are connected by serial port. Communication parameters are shown in the following table. 

**Table 5. Default UART configuration** 

|**Data bits**|**Parity**|**Stop bit**|**Baud-rate**|
|---|---|---|---|
|8|None|1|115200|



In both directions, communication is based on the frames described in next sections. 

From Teseo-Module receiver to Host frames can be: 

- _Unsolicited_ : For instance, periodical frame reporting position 

- _Data Responses_ : Teseo-Module receiver returns data requested by host 

- _ACK_ : in case no data need to be returned to host (e.g. on a reset request), simple ACK is sent 

- _NACK_ : if request contains wrong parameters, NACK is returned to host. 

From Host to Teseo-Module receiver frames can be: 

- Read requests; 

- Write reset, initialization requests 

## **3.2** 

## **Communication over I2C port** 

I2C is a two-wire communication interface invented by Philips Semiconductor unlike all other interfaces, I2C is not able to communicate in full-duplex mode; it uses only two bidirectional open-drain lines, serial data line (SDA) and serial clock line (SCL), pulled up with resistors. 

**UM2791** - **Rev 3** 

**page 10/241** 

**UM2791 Communication over I2C port** 

Teseo-Module always acts as slave and it cannot initiate data on the bus; Host has to periodically pull the receiver to check about data availability. Default I2C slave address is 0x3A. 

The CDB that can be used to configure I2C specific parameters is CDB-ID 263 – NMEA over I2C configuration 

## **3.2.1** 

## **I2C read access** 

When the host wants to read NMEA sentences from I2C, it must start a read operation over I2C, providing configured slave address. 

After the acknowledge bit, a stream of bytes will be sent by Teseo-Module up to the stop/repeated start condition. 

**Figure 6. Read operation description** 

The format of the bytes is ASCII. When Teseo-Module does not have any character to send, a dummy 0xFF byte is sent. 

The host can parse the data received as defined in the messages. 

## **3.2.2** 

## **I2C write access** 

When the Host wants to send commands to Teseo-Module through I2C, it must start a write operation over I2C, providing configured slave address. After the acknowledge bit, Teseo-Module will receive any character coming from the host up to the stop/repeated start condition. 

**Figure 7. I2C write operation description** 

## **3.2.3 I2C communication channel** 

On I2C communication channel Teseo-Module allows 256 addressable registers. 

Each register is 32 bits wide and it can be addressed to support read or write operations. On write operation: 

- the first data byte is the register index while the following bytes are the register value; 

- every write operation with less than 5 bytes is discarded; 

- write operation with more than 5 bytes. All the extra bytes not required are discarded; 

**UM2791** - **Rev 3** 

**page 11/241** 

**UM2791 Communication over I2C port** 

**Figure 8. I2C register write operation** 

On read operation: 

- the register index is the last one indexed in a write operation; 

- Teseo-Module will send the 4 bytes register values; 

- if the Host does not close the i2c-read-transaction after 4 bytes, extra bytes will be filled with 0x0 (zero) by the Teseo-Module; 

**Figure 9. I2C register read operation** 

Teseo-Module does not support auto-increment register index. This means, each register has to be addressed by the host to access. 

Registers from 0x0 to 0xFE are currently reserved for future use, every read or write operation on these registers can provide unpredictable operation on Teseo-Module. 

Teseo-Module has a special register, the register 0xFF reports, as it is, the NMEA stream where the host can perform read and write operations as a standard UART port. 

On PowerOrReset the default register index value is 0xFF. In this way every Host can read the NMEA stream directly just raising a simple i2c-read-operation on Teseo-Module. 

**Table 6. I2C register map** 

|**Register id**<br>~~ES~~|**Operation**<br>~~ES~~|**Size**<br>~~ES~~|**Description**<br>~~ES~~|
|---|---|---|---|
|0x00|-|32 bits|Reserved|
|…|-|-|-|
|0xFE|||Reserved|
|0xFF|R/W|No-Limit|NMEA stream|



**UM2791** - **Rev 3** 

**page 12/241** 

**UM2791 Protocol specification** 

## **4 Protocol specification** 

The receivers come with a highly flexible communication interface. 

Teseo-Module supports the following protocols: 

- NMEA Protocol based on NMEA 0183 Version 3.1; 

- NMEA Protocol based on NMEA 0183 Version 4.10; 

- RTCM protocol based on RTCM Version 2.3 

## **4.1** 

## **NMEA protocol** 

NMEA messages sent by the Teseo-Module are based on NMEA 0183 Version 3.1 or based on NMEA 0183 Version 4.1. 

NMEA (National Marine Electronics Association) is a non-profit association of manufacturers, distributors, dealers, educational institutions, and others interested in peripheral marine electronics occupations. The NMEA 0183 standard defines an electrical interface and data protocol for communications between marine instrumentation. 

## **4.1.1 Communication interface** 

Communication between a Host processor and the Teseo-Module can be established in different ways, depending on the platform implementation. 

For simplicity reasons this document will refer to the UART interface. 

## **4.1.2** 

## **Commands** 

A Command is a defined Data Packet which is sent from a Host processor to the Teseo-Module in order to control the system behavior. The regular structure of a command is: 

```
$command-ID,<parameters>*<checksum><cr><lf>
```

Once the command is executed the device replies with messages according to what specified in this document, after the message the command is sent back to the Host as a final confirmation of the execution. 

## **4.1.3 Messages** 

A message is a defined set of data sent from the Teseo-Module to a host processor using the same interface which is used to transfer commands to the system. Messages may not be enabled by default but can be switched on and off using a command at run-time. The basic structure of a message is: 

```
$message-ID,<parameters>*<checksum><cr><lf>
```

## **4.2 RTCM protocol** 

RTCM (Radio Technical Commission for Maritime Services) is an international standards organization. RTCM protocol is an unidirectional protocol to supply, to Teseo-Module, real-time differential correction data. 

Teseo-Module is compliant with RTCM 2.3 and it supports the messages described in the following table. 

**Table 7. RTCM message type supported** 

|**Message type**|**Description**|
|---|---|
|1|Differential GPS Corrections|
|9|GPS Partial Correction Set|
|31|Differential GLONASS Corrections|
|34|GLONASS Partial Correction Set|



On Teseo-Module RTCM does not need any configuration; when enabled the RTCM input stream is parsed and used in the DGPS algorithm. 

The RTCM protocol can be enabled/disabled on CDB-ID 200. 

**UM2791** - **Rev 3** 

**page 13/241** 

**UM2791 Communication interface** 

## **5 Communication interface** 

Communication between a host processor and the Teseo-Module can be established in different ways. For simplicity reasons this document will refer to “Stand-alone Processors” only and the interface described in the examples is a UART. 

All information contained in this document is related to the “NMEA port” of the Teseo-Module may contain an additional “Debug port” but the data exchanged on the “Debug Port” is not within the scope of this document. 

## **5.1** 

## **Commands** 

A Command is a defined Data Packet which is sent from a host processor to the Teseo-Module in order to control the system behaviour. The regular structure of a command is: 

```
$command-ID,<parameters>*<checksum><cr><lf>
```

In order to receive the commands, the Teseo-Module is connected to the host via the NMEA port (make sure that the serial cable is the right one, sometimes it is necessary to use a cross-cable). The user interaction can be achieved through the use of a PC terminal emulator that is connected to the appropriate COM port with settings in Table 8. Default UART port configuration. 

**Table 8. Default UART port configuration** 

|**Baudrate**|**Parity bits**|**Stop Bit**|**Data bits**|
|---|---|---|---|
|115200|0|1|8|



The NMEA default value baud rate is automatically set at the system start-up. 

It can be modified at system runtime using the appropriate command. 

The simplest way to send a command to the device is to write the command string in a text file and send it using the “send file” capability of the terminal emulator. For this reason, it is required that the terminal emulator (or production test program) running on the PC is capable of sending text files down the RS232 link to the TeseoModule. 

Once the command is executed the device reply with messages according to what specify in this document, after the message the command is sent back to the host as final confirmation of the execution. 

## **5.2 Messages** 

A message is a defined set of data sent from the Teseo-VIC3 to a host processor using the same interface which is used to transfer commands to the system. Messages may not be enabled by default but can be switched on and off using a command at run-time. The basic structure of a message is: 

```
$message-ID,<parameters>*<checksum><cr><lf>
```

There are two basic sets of messages implemented. 

## **5.2.1 Standard NMEA message** 

Standard NMEA Messages are defined in the “NMEA 0183” Standard, issued from the “National Marine Electronics Association”. The latest issue is Rev. 4.10 dated August 2012. NMEA0183 refers to it as Sentences (single line message) and Messages (multiple line messages). 

By default, Standard NMEA Messages are compliant with the “NMEA 0183” Standard Rev. 3.1 dated January 2002. Anyway, it is possible to change their format to be compliant with Rev. 4.10, issued from the “National Marine Electronics Association” in the August 2012. 

To get an overview please refer to Standard NMEA messages specification in this document. Standard NMEA messages start the “message-ID” with: 

**UM2791** - **Rev 3** 

**page 14/241** 

**UM2791 Messages** 

## `$<TalkerID>` 

Supported talker IDs are: “GP”, “GL”, “GA”, “BD”, “QZ” and “GN” for standard NMEA sentences. 

_Note: The set of supported talker IDs depends by supported constellations. It is strictly related to the hardware platform and software revision._ 

## **5.2.2** 

## **Proprietary messages** 

Teseo-Module can provide additional messages with more detailed data content. This is required to transmit Teseo-Module and System information content which is not defined in the NMEA standard output. Proprietary messages from STMicroelectronics start with: 

## `$PSTM…` 

To get an overview on the proprietary messages defined by STMicroelectronics please refer to ST NMEA messages specification chapter in this document. 

**UM2791** - **Rev 3** 

**page 15/241** 

**UM2791 Dead Reckoning** ~~wo~~ 

## **6 Dead Reckoning** 

Teseo-Module embeds the Teseo-DRAW firmware. 

Teseo Dead Reckoning solution (both Teseo-DRAW and Teseo-DRUM), also known as Teseo DR, is a technology combining inertial sensors together with GNSS, providing seamless fusion of satellite measurements, angular rate and acceleration data. It is designed to provide improved accuracy, availability and integrity of positioning data, in particular in environments where GNSS is absent or corrupted. 

Teseo-DRAW is a FW which is fed by both inertial sensor (such like gyroscope and accelerometer) and vehicle sensors (such like speed signal and reverse indicator). Since DRAW requires electrical connection to vehicle speed signal, it is a solution, which is typically targeting OEM automotive customers. It provides a premium performance level, with cutting edge position accuracy even during extended periods of GNSS absence. 

Teseo-DRUM is a FW which is fed by inertial sensor (such like gyroscope and accelerometer). Since DRUM do not require electrical connection to vehicle speed signal, it is a solution, which is typically targeting Industrial customers. 

## **6.1 Map matching feedback** 

## **6.1.1 Overview** 

In applications where a map matching system is available (e.g. in an in dash navigation system) Teseo-Module can receive the map matched position to improve the quality of PV output. This feature is called Map Matching Feedback (MMFB). The mentioned feature and the way it should be used shall be described in detail in this section, along with examples of results. 

An overview of the components of a typical Teseo-Module based navigation system are reported in Figure 10. Navigation system feat. MMFB on Teseo-Module. Host processor is running the Map Matching SW – that is an IP matching the position provided by DR on a map database (which can be local or remote). MMFB Interface is the method used by Map Matching SW to send data to Teseo-Module. MMFB operation can be effective only in presence of such communication link. 

**Figure 10. Navigation system feat. MMFB on Teseo-Module** 

**UM2791** - **Rev 3** 

**page 16/241** 

**UM2791 Map matching feedback** 

**Figure 11. Navigation system feat. MMFB on Teseo-VIC3O** 

The core of feature is the algorithm, i.e. a sensor fusion engine that at each second of operation it compares the contribution of different sources of data, attempting to take the better of each one to guarantee continuous smart fusion of GNSS, sensors and map, for optimal accuracy and smoothness. A Weight (referred as R in figure) is used to modulate map contribution to output solution. 

**Figure 12. MMFB fusion engine** 

## **6.1.2 Acceptance conditions** 

In order to allow map data to enter the filter and influence Teseo DR output conditions need to be verified. Such conditions are reported in the following figure. 

First of all, MMFB feature should be enabled in FW configuration CDB 667 (it is enabled by default). Sensors calibration phase needs to be completed. Moreover, MMFB dataset should be indicated as valid by the host; ST MMFB interface features a field allowing host to declare the validity status of sent data. 

**UM2791** - **Rev 3** 

**page 17/241** 

**UM2791 Map matching feedback** 

## **Figure 13. Map data acceptance conditions** 

There are indeed time constraints that must be met. In practice, after receiving a set of fix data from TeseoModule, the time elapsed by host to process map data and send them back to Teseo-Module should not exceed 1 second. 

MMFB approach is based on the statement that, in case GNSS fix is believed to be reliable (good signal conditions) its accuracy shall be in general better than map matching. For this reason, MMFB contribution is neglected in such benign reception scenario. 

It is worth to underline that the fact that MMFB data is accepted and used into Kalman Filter does not necessarily mean that the user will see its influence in DR output. In fact, once accepted, the map will be subjected to the weighting logic previously mentioned. If the weight decided by the logic is very low (e.g. if the information coming from the map is inaccurate) its effect output shall be null or almost. 

## **6.1.3** 

## **Interface** 

The interface is implemented by the $PSTMDRMMFB NMEA command aimed to allow an external module to input last mapped data point into Teseo-Module. Such $PSTMDRMMFB command must be sent via UART. If command format is accepted, MMFB data will be injected into Teseo DR algorithm and the command will be echoed on NMEA communication channel. 

The typical MMFB command which shall be sent to Teseo-Module has the following aspect: 

`$PSTMDRMMFB,<time_stamp>,<lat_val>,<lon_val>,<height_val>,<heading_val>,<lat>, <lon>,<height>,<heading>,<lat_err>,<lon_err>,<height_err>,<heading_err>*<checksum><cr><lf>` 

## **Example** 

`$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30` 

Parameters requested by $PSTMDRMMFB command are listed in detail in $PSTMDRMMFB command description. The command is composed by four categories of data: 

- Time 

- Map data validity flags 

- Map data values 

- Map data estimated errors 

Each category is described more in deep in the following sub-sections, which also feature important suggestions about how to set the parameters. 

**UM2791** - **Rev 3** 

**page 18/241** 

**UM2791 Map matching feedback** 

## **Time stamp** 

It is expressed in UTC format; it defines the epoch of provided dataset. It is used to ensure the correct synchronization between MMFB algorithm and map matching engine; for this reason, it must exactly match the UTC time of a recent GxGGA message. The map-match information is assumed to be the position/heading estimate at the time of that GxGGA message. The latency in delivery should be less than 1 second. 

Figure 14. Usage of MMFB interface with correct timing shows an example where the sending time is correct. It can be seen that Teseo DRAW is calculating its fix output at a given time, called FixUTC(n-1). Once the host receives related fix data, it has to match them on the map database and transmit back to Teseo-Module that matched point, i.e. MMFBUTC(n-1). The time needed to fulfill these actions is called Δtmmfb. In the meantime, DRAW process is continuing on Teseo-Module side, yielding the calculation of a new fix called FixUTC(n), which is 1 second after FixUTC(n-1). In order to MMFB to be correctly used by DRAW, MMFBUTC(n-1) should be sent to DRAW before FixUTC(n); in other words Δtmmfb should be less than one second. 

Figure 15. Usage of MMFB interface with incorrect timing is instead representing a case in which the timing is not correct. In this case MMFBUTC(n-1) has been sent to DRAW after FixUTC(n); i.e. Δtmmfb is more than one second. In this condition map info shall be discarded by ST FW synchronization checks. 

One important point to keep under attention is about selected fix rate. All the considerations above apply to the case in which DRAW is configured to provide 1 Hz fix rate. In case of fix rate > 1 Hz, only the GxGGA featuring hhmmss.000 UTC time needs to be fed back to DRAW. In this way the FW is allowed to treat this use case similarly way to 1 Hz. 

## **Example** 

For a 5 Hz system, the fix at UTC 163024.000 should be considered by map matching engine to be sent to DR. Instead the fixes at UTCs 163024.200, 163024.400, 163024.600 and 163024.800 should not be sent. Fix at 163025.000 should be sent. 

The following command is correct: 

`$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30<cr><lf>` 

While the following command is not correct: 

`$PSTMDRMMFB,085347.200,1,1,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30<cr><lf>` 

**Figure 14. Usage of MMFB interface with correct timing** 

**UM2791** - **Rev 3** 

**page 19/241** 

**UM2791 Map matching feedback** 

## **Figure 15. Usage of MMFB interface with incorrect timing** 

## **Data validity** 

Each validity flag asserts the respective data field validity. In case of validity flag set to ‘0’ MMFB algorithm will ignore the data field. This feature allows the host processor to invalidate selectively a part of the MMFB information (or eventually the whole dataset). This should happen for example if matched data field is not available or believed wrong 

E.g., a valid MMFB command to ensure that position data is accepted by Teseo DR is the following: 

`$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30` 

While the following command should be used in case position data should be rejected: 

`$PSTMDRMMFB,085347.000,0,0,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30` 

It is important to underline that only latitude and longitude validity flags should be manipulated by customer. Heading and height are reserved fields and must always be declared invalid, as showed in both examples. Height map feedback is currently not supported; heading feedback instead is not needed because it shall be automatically estimated from latitude and longitude. 

## **Data values** 

Latitude and longitude must be expressed according to WGS84 reference ellipsoid datum. The whole concept assumes that map position is accurate. The filter is designed to be able to reject /mitigate the contribution of inaccurate map position, in order to avoid it to jeopardize filter stability and sensors’ calibration. Nevertheless, for optimal fusion performance, ST recommends customer to ensure the data provided by the map matching engine are reliable, and in case they aren’t to invalidate them through the validity flags. 

_Note: Height and heading fields, although reserved, are not supported currently in Teseo-DRAW and Teseo-DRUM. Related fields should be set to 0._ 

**UM2791** - **Rev 3** 

**page 20/241** 

**UM2791 Map matching feedback** 

## **Estimated errors** 

Estimated error (aka accuracy) fields allow the host processor to inform Teseo-Module about reliability of the provided map matched data. Teseo-Module will base its output on this number. In this case navigation performance shall depend on estimated error choice. 

## **Estimated error equals zero** 

Estimated error information is often not available at the map matching engine side; moreover, not all host owners need or want to set them as this implies to spend effort and time for testing in different scenarios to find the specific tuning for their specific case. 

Consequently, setting it is not standard option for Teseo DR nor mandatory; by default, such error fields must be set to 0.0. In this way Teseo-Module shall ignore them, calculating autonomously its own weighting based on internal likelihood algorithms. Goal of such procedures is to maximize the employment of the map when it’s good, and discard when it’s bad (e.g. when the map point is matched on a wrong road). 

Such default standard method has demonstrated to be optimal choice for applications featuring accurate and reliable map information, i.e. not interpolated. Nevertheless, it is still very important that, on host side, any known bad map point is flagged by ‘0’ in validity fields. 

## **Estimated error greater than zero** 

When non-zero value is specified, host shall take the control deciding how much MMFB data modify TeseoModule output PV. One limitation is that this control shall happen only if the MMFB data has been accepted by Teseo-Module, i.e. it fulfills conditions described in Figure 3. Teseo-Module operations from Power-on/reset. Looking at it, it is important to underline that MMFB data is accepted only when GNSS is deemed as “not acceptable” by Teseo DR internal logics. 

Inside a tunnel GNSS shall be not received; hence never declared acceptable; hence MMFB data shall be always used by Teseo-Module. 

In open sky, GNSS is almost always declared acceptable; so MMFB data shall rarely be considered. So, in case a customer is testing in open sky and does not see influence of the map on Teseo-Module position, that’s normal and expected, as in open sky GNSS is believed to be the most reliable absolute positioning source, better than map. 

In urban canyon GNSS acceptance depends on actual signal quality, i.e. by multipath severity. In this case map data will be declared usable in areas where GNSS signal is most corrupted and not usable in areas where GNSS is better. 

Since these fields are defined as “errors” they are expressing a concept of uncertainty of map data; so the lower is the value, the more map is trusted; the higher is value, the less map is trusted. 

The maximum faith shall be obtained putting values in the range 0 < error < 5 m. Sending such value, the user should see Teseo-Module output to blindly follow map data in tunnel. 

For values larger than 5 m, the larger is the value, the less is the faith Teseo-Module is putting in map data. It is not possible to describe in a table the precise effects of a given error value on output position, because, being the algorithm a Kalman Filter, the effect of the weight is strictly depending on current filter status. Nevertheless, very high values (e.g. 500 m) will result in Teseo-Module to completely ignore the map; but it is important to underline that if this is the intention of the user, the correct way to achieve this is to declare the data not valid, as described in section Data Validity. 

Understanding and choosing intermediate values (5 m < error < 500 m) requires the skilled user to spend effort for testing, qualify and find the most suitable tuning depending on the working of his matching algorithm and the quality of its maps. For example, if the vehicle is near a junction, it could be useful to tell the system to reduce the trust in map, as the map system itself cannot be able to choose the correct road, while Teseo-Module gyroscope is. 

The following table summarizes the above discussion. 

**Table 9. Effects of different MMFB estimated error settings on Teseo-Module output** 

||**Map error**|**Range**|**Effect on DRAW PV**|
|---|---|---|---|
||Lat_err|0m|Map weight self-computed|
|||0 < lat_err <= 5m|Map trusted with maximum faith|
|||lat_err > 5m|The larger value, the less is the faith in map|
||Lon_err|0m|Map weight self-computed|
|||0 < lon_err <= 5m|Map trusted with maximum faith|
|||lon_err > 5m|The larger value, the less is the faith in map|
|||||
|**UM2791**-**Rev 3**|~~Height err~~|~~Always ignored~~|~~No effect~~<br>**page 21/241**|
|||||



**UM2791 High dead-reckoning fix rate** 

## **Example 1** 

Errors are left to zero. Standard suggested setting. Desired effect is that Teseo DR calculates his own weighting internally, in order to automatically decide how much trust map. 

```
$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,0.0,0.0,0.0,0.0*30
```

## **Example 2** 

Errors are set at minimum value i.e. 5 m. Desired effect is that Teseo DR 100% trusts map (if usable), with its output totally matching with it. 

```
$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,5.0,5.0,0.0,0.0*30
```

## **Example 3** 

Errors are set below the minimum value and > 0 m. The behavior shall be identical to Example 2. 

```
$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,1.0,1.0,0.0,0.0*30
```

## **Example 4** 

Errors are set at maximum value. Desired effect is that Teseo DR ignores map data. Independently from error value, the validity flags should be set to 0. 

```
$PSTMDRMMFB,085347.000,0,0,0,0,51.0314194,6.9349778,0.0,0.0,1000.0,1000.0,0.0,0.0*30
```

## **Example 5** 

Errors are set at intermediate value defined by user (in this case 70 m, but could be any > 5 m). Desired effect is that Teseo DR partially trusts map data. How much they will influence Teseo-Module output cannot be defined a priori, since it depends on internal KF status. It shall be task of integrator to spend effort to implement, test and qualify best values for its application depending on scenario and map variables. 

```
$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,0.0,0.0,70.0,70.0,0.0,0.0*30
```

Estimated error command is supported only for latitude and longitude. Any error applied to heading or height fields shall be ignored, and ST recommendation is let those fields at zero, as per examples above. E.g. 

```
$PSTMDRMMFB,085347.000,1,1,0,0,51.0314194,6.9349778,70.0,70.0,0.0,0.0*30
```

## **6.2** 

## **High dead-reckoning fix rate** 

While on Teseo-Module the GNSS Fix rate is 1 Hz with the Teseo DR firmware embedded in Teseo-Module it’s possible to achieve a Dead-reckoning fix rate up to 20 Hz. 

GNSS data and sensors fusion are used to propagate and generate Dead-Reckoning Fix between two consecutive GNSS fixes. 

Dead-reckoning fix rate can be configured using CDB-ID 600 – DRAW main setting. 

## **6.3** 

## **Sensors over UART** 

A special case of NMEA command is the command containing sensor data. In fact, Teseo DRAW FW can receive sensor data from an external device(for example, main host processor)through UART communication channel. This feature is referred as sensor over UART (SOU); it is particularly useful for device architectures where sensors are not managed directly by Teseo III but rather by a dedicated processor that is in charge to get data from them (for example,implementing sensors drivers) and to send them to Teseo. 

_Note:_ 

_SoU capability is only available for Teseo DRAW products. The feature is not supported in Teseo DRUM._ 

**UM2791** - **Rev 3** 

**page 22/241** 

**UM2791 Sensors over UART** 

## **6.3.1 Typical architecture** 

## **Figure 16. Typical host-based DR architecture** 

A typical example of host-based architecture is depicted in the figure above. The host processor can acquire data either from the vehicle's CAN bus (in which case it also has the task of decoding it from the automaker's proprietary payload) or from a classic MEMS IMU via standard I²C or SPI interfaces. 

Then it has to build ASCII sentences according to STMicroelectronics sensor protocol and send them to Teseo via UART. If the syntax of the message is correct, Teseo accepts the data, uses it for navigation and finally returns it on its UART output, marking it with the CPU time stamp in which it was received. 

It is worth to underline that in an architecture of this type the host application is responsible for timing correctness of sensor data. 

_Note:_ 

_Host SW processing needs to minimize the time from data generation on sensor to sending to Teseo. In other words, the latency (absolute delay) and the jitter (noise on sampling time) must be minimized and in any case complies with STMicroelectronics guidelines. That are: latency less than 40 ms, jitter less than 5 ms._ 

Another important point that the host programmer managing IMU must consider is that both DRAW and DRUM expect IMU data configured with default sensor full scale values. For example, if the sensor used is ASM330LHH (or LSM6DSR) expected full scale is 2g for accelerometer and 125 dps for gyroscope. 

## **6.3.2** 

## **Message format** 

ST defines a dedicated format for input sensor messages, which is the same as output data messages; for example pertaining to the $PSTMDRSENMSG messages class. Full format for all the messages belonging to this class is specified in sections 9.5 and 9.6. For example, in case the host processor needs to send data from a digital 3 axis gyroscope the dedicated message should be used: 

`$PSTMDRSENMSG,31,0,46,-2,-41*21*<checksum><cr><lf>` 

The message contains the sensor ID (31 is 3 axis gyro), and the data for x y z angular rates (46, -2, -41 respectively). 

_Note: The 2nd field of each sensor message (the “0” in example above), representing the CPU time must be always left to 0 when writing an input message._ 

_Note: Each message must be sent without checksum (for example $PSTMDRSENMSG,31,0,46, -2,-41*15 is wrong format and won’t be accepted by Teseo)._ 

## **6.3.3** 

## **Required messages** 

The minimum set of sensors needed to allow Teseo DRAW working depends on selected operating mode. The following table reports sensors and related message IDs host must send depending on selected operating mode. Minimum message rates to obtain a sustainable SoU functionality are also reported in this table. 

**Table 10. SoU equired sensors vs operating mode** 

|**Operating mode**|**Required sensors**|**Required**|**Minimum input message**|
|---|---|---|---|
|||**$PSTMDRSENMSG IDs**|**rates**|
||3 axes gyro|31|100 Hz|
||3 axes acc|30|100 Hz|
|0x3||||
||Odometer|1|5 Hz|
||Reverse gear|2|1 Hz|
|0x5|3 axes gyro|31|100 Hz|



**UM2791** - **Rev 3** 

**page 23/241** 

**UM2791 Enabling messages in configuration** 

|**Operating mode**|**Required sensors**|**Required**|**Minimum input message**|
|---|---|---|---|
|||**$PSTMDRSENMSG IDs**|**rates**|
||3 axes acc|30|100 Hz|
|0x5|Speed|14|5 Hz|
||Reverse gear|2|1 HZ|
||1 axes gyro|4|100 Hz|
|0x3|Odometer|1|5 Hz|
||Reverse gear|2|1 HZ|
||1 axes gyro|4|100 Hz|
|0x4|Speed|14|5 Hz|
||Reverse gear|2|1 HZ|
||Rear L/R wheel pulses|9|5 Hz|
|0x8||||
||Reverse gear|2|1 Hz|
||1 axes gyro|4|100 Hz|
|0xF|Rear L/R wheel pulses|9|5 Hz|
||Reverse gear|2|1 HZ|
||1 axes gyro|4|100 Hz|
|0x10|Rear L/R Wheel speeds|18|5 Hz|
||Reverse gear|2|1 HZ|
||3 axes gyro|31|100 Hz|
||3 axes acc|30|100 Hz|
|0x15||||
||Rear L/R wheel speeds|18|5 Hz|
||Reverse gear|2|1 Hz|



_Note:_ 

_For Teseo DRAW applications, accelerometer (msg ID 30) is required for 3D DR and tilt compensation. In case 3D DR is not requested by application and the board is either flat or at known / configurable installation, the sensor can be considered optional._ 

_It is worth to note that given an operating mode, the important point is that all the sensors are available, independently from the input IF. For example, considering the classic operating mode odo plus 3 axis gyroscope (0x3) solutions can be either:_ 

- _All sensors read by host and sent via UART or_ 

- _IMU data read from on board devices directly connected to Teseo while odometer pulses and reverse status received via UART or_ 

- _IMU connected to host processor with data sent over UART while odometer pulses and reverse status connected directly to Teseo’s GPIOs._ 

## **6.4** 

## **Enabling messages in configuration** 

The proprietary ST messages described in this section can be enabled / disabled in NMEA output by configuring NMEA message lists (CDBs 228, 229 or 230). Each message list is essentially an array of bits, each one representing a different NMEA message (or set of messages); for each bit, 0 disables related messages set, 1 enables it. 

A summary overview of the available message lists and related configuration method is reported in Section  5.2.1  Standard NMEA message. For a more comprehensive explanation about Teseo III FW configuration refer to Section  2.3  Firmware update algorithm protocol). 

**UM2791** - **Rev 3** 

**page 24/241** 

**UM2791 Assisted GNSS** 

## **7 Assisted GNSS** 

Teseo-Module needs accurate satellite position data from at least 4 satellites to produce a position fix (FIX). Accurate satellite data -ephemeris data- is valid for 4 hrs only for GPS and 30 min only GLONASS. After that time a Teseo-Module must download new ephemeris data. 

Ephemeris download can take from dozens of seconds to several minutes, hours or can fail. 

Assisted-GNSS is a mechanism to provide ephemeris assistance from external source; this reduces considerably the time to get a FIX especially in critical environments when the ephemeris download time could be very long. Teseo-Module supports the following types of assisted GNSS: 

- ST - AGNSS 

- Predictive AGNSS 

- Real-time GNSS 

## **7.1** 

## **ST - AGNSS** 

The ST-AGNSS library is able to provide predicted ephemerides to the Teseo-Module in a time frame less than the usual time (about 30 seconds) needed to download real ephemeris from the sky. This reduces considerably the time to get a FIX especially in critical environments when the ephemeris download time could be very long. 

ST-AGNSS autonomous solution works using the past real ephemeris (downloaded from the sky and stored in its internal database) to extrapolate the parameter of future ephemeris (up to 5 days of prediction). For these reasons, the ST-AGNSS autonomous performances (in terms of position accuracy using predicted ephemeris) are strictly dependent on the real ephemeris database content. In normal usage of ST-AGNSS autonomous, the system automatically uploads the real ephemeris into its database as soon as new ephemerides are downloaded from the sky. This means that the global content of the real ephemeris input database is determined by the history of device running periods in the past. 

**Table 11. ST-AGNSS NMEA interface** 

|**Syntax**|**Description**|
|---|---|
|$PSTMSTAGPSONOFF|Turns ON/OFF the STAGNSS engine|
|$PSTMSTAGPSINVALIDATE|Clears data stored in the STAGNSS internal database|
|$PSTMGETAGPSSTATUS|Returns the status of the STAGNSS internal processing|
|$PSTMSTAGPSSETCONSTMASK|Switches among the ST-AGNSS constellation|
|$PSTMAGPS|Message with the same syntax as standard NMEA GSA Message|
|$PSTMAGLO|Message with the same syntax as standard NMEA GSA Message|
|$PSTMPOLSTARTED|Message in response to $PSTMSTAGPSONOFF|
|$PSTMPOLSUSPENDED|Message in response to $PSTMSTAGPSONOFF|
|$PSTMPOLONOFFERROR|Message in response to $PSTMSTAGPSONOFF|
|$PSTMSTAGPSINVALIDATEOK|Message in response to $PSTMSTAGPSINVALIDATE|
|$PSTMSTAGPSINVALIDATEERROR|Message in response to $PSTMSTAGPSINVALIDATE|
|$PSTMAGPSSTATUS|Message in response to $PSTMGETAGPSSTATUS|



## **7.2** 

## **Real-Time AGNSS** 

The Real-Time AGNSS is able to provide the approximate current time, the ephemerides, the almanacs and optionally the approximate position to the Teseo-Module in a time frame less than the usual time (about 30 seconds) needed to download real ephemeris from the sky. This reduces considerably the time to get fix especially in critical environments when the ephemeris download time could be very long. 

**UM2791** - **Rev 3** 

**page 25/241** 

**UM2791 Real-Time AGNSS** 

Real-time AGNSS requires a network connection to download assistance data from the server. Assistance data include the current time (if not available, for instance, from RTC), the ephemerides, the almanacs and optionally the rough position. 

All the assistance data can be injected into the device backup memory using a few NMEA commands. 

Follow the Application note "AN5160: RxNetworks Assisted GNSS Server Interface Specification" to access the RxNetwork Service. 

The first thing to do is to inject the current time into the device (if the device has no RTC, or if it is set to a wrong time). This can be done either using the $PSTMINITTIME command or, if also the approximate position is available, then both current time and position can be injected using the $PSTMINITGPS command. 

Then the ephemerides can be injected into the device using the $PSTMEPHEM command for each satellite (between two consecutive commands there must be at least a 20 millisecond delay). 

Then the almanacs can be injected into the device using the $PSTMALMANAC command for each satellite (between two consecutive commands there must be at least a 20 millisecond delay). 

Now the device will be capable of achieving the fix very quickly, if enough satellites are in view. 

## **7.2.1** 

## **Password generation - details** 

As mentioned in the previous section, in order to access the RxNetworks server, the user has to provide a set of parameters, which are used in generating the HTTP request. These parameters are used to generate a password string (up to 41 characters in length) that is required by the HTTP request string. 

Teseo-Module provides the $PSTMSTAGPS8PASSGEN NMEA command that performs the password generation. The user must supply three parameters to this command that it will use to generate a unique password. 

In order to generate the password the user must pass in the following parameters. 

- _The vendor id string._ 

- _The current time expressed as GPS seconds (i.e. the number of seconds since midnight 06-Jan-1980)._ 

The vendor id and device id strings are provided in Section  Appendix B  RxNetworks Teseo-Module credential. The current time will need to be calculated by the software creating the HTTP request string. 

## **7.2.2 Real-Time assistance data uploading procedure** 

The real-time AGNSS performances depend on the availability of a network connection in order to download assistance data, which include: 

1. the current time (if not available, from instance, from RTC), 

2. the ephemerides, 

3. the almanacs 

4. the rough position (optional) 

Once those data have been downloaded from the server, the first thing to do is to inject the current time into the device (if the device has no RTC, or if it is set to a wrong time). This can be done either using the $PSTMINITTIME command or, if also the approximate position is available, then both current time and position can be injected using the $PSTMINITGPS command. 

Then the ephemerides can be injected into the device using the $PSTMEPHEM command for each satellite (between two consecutive commands there must be at least 20 millisecond delay). 

Then the almanac can be injected into the device using the $PSTMALMANAC command for each satellite (between two consecutive commands there must be at least 20 millisecond delay). 

Now the device will be capable of achieving the fix very quickly, if enough satellites are in view. 

**UM2791** - **Rev 3** 

**page 26/241** 

**UM2791 Low power modes** 

## **8 Low power modes** 

The low power management library implements different modes including the functionalities below: 

- Adaptive low power mode: 

   - Change the constellation used by the system (dynamic constellation switch) 

   - Update the number of GPS satellites used (active channel management) 

- Cyclic low power mode: 

   - Change the duty cycle of every channels. 

- Active and standby periodic low power mode: 

   - Report a fix at a given periodicity 

   - Autonomous periodic ephemeris refresh 

   - RTC calibration capability 

   - Optional use of ST-AGNSS (Standby mode only) 

   - Different hardware power state between fixes are possible 

- Fix on demand low power mode (Standby mode only): 

   - Report a fix on demand triggered by an hardware pin 

   - Autonomous periodic ephemeris refresh 

   - RTC calibration capability 

Adaptive and cyclic modes can be mixed together. They are designed to save power while limiting the degradation of the sensitivity and accuracy. List of satellites and reception duration can be adjusted as long as the estimated error is above a threshold. 

Adaptive and cyclic modes cannot be mixed with the periodic mode. 

The periodic mode saves power when a fix is needed more than every 5 seconds and when accuracy degradation is acceptable. Two cases are depicted, corresponding to different hardware states between the fix activities. There is the active case and the standby case (maximum power saving). The usage of ST-AGNSS feature allows reducing the energy spent in the ephemeris refresh periods. 

The choice between the different modes are driven by the required fix periodicity. 

**Table 12. Suggested power mode against the fix periodicity** 

|**Fix Periodicity**|**Appropriate mode**|
|---|---|
|0.1s-1s|None|
|1s – 10s|Adaptive and Cyclic modes|
|5s-24H|Standby Periodic mode<br>+ optional ST-AGNSS|
|Asynchronous|Fix On Demand|



## **8.1 Adaptive and cyclic mode state diagram** 

The library, using the estimated horizontal position error (EHPE), implements a dynamic constellation switch. In this way the device is able to optimize the usage of multi-constellation satellites allowing the customer to select the proper compromise between accuracy performance and power consumption. 

EHPE is a measure of the error in a GNSS position on the horizontal plane. This value can be monitored in the NMEA sentences $GPGST. 

The following figure shows the algorithm’s state diagram: 

**UM2791** - **Rev 3** 

**page 27/241** 

**UM2791 Adaptive and cyclic mode state diagram** 

## **Figure 17. Adaptive and cyclic mode state diagram** 

The adaptive and cyclic low power algorithm is scheduled every second. 

Initial state is achieved only after the steady state is reached. The steady state in GNSS mode is a particular condition in which the software turns off the acquisition engine. 

This condition is reached when all the following conditions are taken (true): 

- the system is in position accurate condition (position fix available); 

- ephemeris available (4 for GPS, 4 for GLONASS); 

- almanac completely downloaded. 

Generally, at first start up (full cold mode) this condition, in full sky is reached in 12.5 minutes. 

**Table 13. Algorithm finite states machine descriptions** 

|**State**|**Description**|**Next state**|
|---|---|---|
|INITIAL_STATE||•<br>FULL_CONST only when all the three<br>condition are taken:<br>•<br>position fix available<br>•<br>almanac completely downloaded<br>•<br>ephemeris available (4 for GPS, 4 for<br>GLONASS);|
|FULL_CONST|•<br>All the GNSS constellation enabled in the<br>firmware-configuration are active during<br>the runtime|•<br>LOW_POWER_STATE only if EHPE<br>average is less than EHPE threshold (good<br>sky condition)|
|LOW_POWER|Only one GNSS constellation is available<br>(Dynamic constellation ON/OFF) and only the<br>first N GPS/GLONASS satellites (with higher<br>elevation) are used for the position calculation<br>(Active channel management), duty cycle for<br>every channels enabled.<br>Turn-on the ephemeris-refresh timer|•<br>FULL_CONST only if EHPE average is<br>greater than EHPE threshold (bad sky<br>condition)|
|||•<br>EPHEMERIS_REFRESH only if the<br>ephemeris-refresh timeout fires (30 minutes<br>timeout)|
|EPHEMERIS_REFRESH|Turn on all constellation until the ephemeris are<br>available|•<br>LOW_POWER_STATE only when the<br>ephemeris are downloaded|



The Adaptive low power management can operate even in the case in which the constellation enabled is GPS only and GLONASS only. In this case, the low power state only consists in reducing the GPS/GLONASS used satellites. 

**UM2791** - **Rev 3** 

**page 28/241** 

**UM2791 Periodic mode** 

**Table 14. Adaptive low power mode** 

||**LOW POWER MODE**|**Features**|
|---|---|---|
|1|Dynamic Constellation<br>ON/OFF|Constellation switch (GPS only enabled) based on estimated<br>EHPE / Duty Cycle enable / ephemeris refresh / ability to<br>reduce the tracked satellites (better elevation) / ability to<br>disable the duty cycle based on estimated EHPE|
|2|Dynamic Constellation<br>ON/OFF<br>(standard mode)|Constellation switch (GPS only enabled) based on estimated<br>EHPE / ephemeris refresh / ability to reduce the tracked<br>satellites (better elevation)|
|3|Only Duty Cycle mode|Duty Cycle enable / ephemeris refresh / ability to disable the<br>duty cycle based on estimated EHPE|
|4|Duty Cycle mode with<br>reduced satellites (better<br>elevation)|Duty Cycle enable / ephemeris refresh / ability to disable the<br>duty cycle based on estimated EHPE / ability to reduce the<br>tracked satellites|



## **8.2** 

## **Periodic mode** 

The periodic mode has different settings to control the FIX reporting, and other settings to control the low power hardware state. 

The periodic mode can have two different hardware states between FIX activities: 

- Wait for interrupt state used in active periodic mode, where the system clock is set to the RING oscillator (a low power oscillator) 

- Standby state used in standby periodic mode, where only Always ON domain is alive 

Although the Wait For Interrupt hardware state ensure continuity of software execution and maintain data, the Standby hardware state is a reset and ARM core state and on-board memories except backup RAM are lost. 

## **8.2.1** 

## **State machine** 

The periodic mode has basically two parts in its state machine – one to handle the fix (left) and one to handle the case of no fix (right). The transitions between both in case of fix loss or recovery is done according to the steady state condition. The steady state is the combination of the following information: 

- The system is in position accurate condition (position fix available); 

- Ephemeris available (5 each activated constellations); 

- Almanac, ephemeris or health information collected for all satellites. 

Generally, at first start up (full cold mode) this condition, in full sky is reached in 12.5 minutes for GPS constellation. 

**UM2791** - **Rev 3** 

**page 29/241** 

**UM2791 Periodic mode** 

## **Figure 18. Low power periodic mode state diagram** 

**UM2791** - **Rev 3** 

**page 30/241** 

**UM2791 Periodic mode** 

The following table details the different states: 

**Table 15. Periodic mode finite state machine description** 

|**State**|**Description**|**Next state**|
|---|---|---|
|SUSPEND|GNSS system sleeping.<br>CPU in idle.<br>System running at low<br>frequency.<br>Three timers running:<br>•<br>_FixPeriod_timer<br>•<br>_EphRefresh_timer<br>•<br>_RTC_clb_timer|FIX when FixPeriod timer fires|
|||EPH_REFRESH when EphRefresh timer fires (32 minutes<br>timer)|
|||RTC_CALIB when RTC_clb timer fires (5 minutes timer)|
|FIX|GNSS system running to<br>acquire a series of N fixes.<br>CPU running<br>Three timers running:<br>•<br>–<br>◦<br>_NoFixCnt_<br>timer<br>•<br>_NoFixCnt2_timer<br>•<br>_EphRefresh_timer|SUSPEND when the N fixes are acquired|
|||NOFIX_SUS when the N fixes serie can not be completed<br>and NoFixCnt timers fire (in HOT conditions)|
|||•<br>NOFIX_SUS when the N fixes serie can not be<br>completed and NoFixCnt2 timer fire<br>•<br>(in NOT-HOT conditions)|
|||•<br>EPH_REFRESH when EphRefresh timer fires (32<br>minutes timer)|
|EPH_REFRESH|GNSS system running for<br>40/60s to download new<br>ephemeris.<br>CPU running<br>Two timers running:<br>•<br>_NoFixCnt_timer<br>•<br>_NoFixCnt2_timer|•<br>SUSPEND when ephemeris download completes|
|||•<br>NOFIX_SUS when ephemeris download doesn’t<br>complete and NoFixCnt timers fire (in HOT conditions)|
|||•<br>NOFIX_SUS when ephemeris download doesn’t<br>complete and NoFixCnt2 timer fire<br>•<br>(in NOT-HOT conditions)|
|NOFIX_SUS|GNSS system sleeping due to<br>No satellites signal or no fix<br>acquired<br>CPU in idle.<br>System running at low<br>frequency.<br>Three timers running:<br>•<br>_EphRefresh_timer<br>•<br>_NoFixCnt_timer<br>•<br>_NoFixCnt2_timer|<br>EPH_REFRESH when EphRefresh timer fires (32 minutes<br>timer)|
|||NOFIX when NoFixCnt timer fires (in HOT conditions)|
|||NOFIX when NoFixCnt2 timer fires (in NOT-HOT conditions)|
|NOFIX|GNSS system running but<br>unable to acquire a fix.<br>Two timers running:<br>•<br>_NoFixCnt_timer<br>•<br>_NoFixCnt2_timer|FIX if a fix is acquired|
|||NOFIX_SUS when fix is not acquired and NoFixCnt timer fires<br>(in HOT conditions)|
|||NOFIX_SUS when fix is not acquired and NoFixCnt2 timer<br>fires (in NOT-HOT conditions)|
|RTC Calibration|GNSS system sleeping.<br>CPU running for<br>rtc_calibration; calibration is<br>performed at higher<br>frequency settings|SUSPEND when calibration completes|



HOT conditions: number of ephemeris and RTC are OK. NOT-HOT conditions: start-up cases, obsolete ephemeris. 

**UM2791** - **Rev 3** 

**page 31/241** 

**UM2791 Periodic mode** 

## **8.2.2 Good GNSS coverage sequences** 

**Figure 19. GNSS good coverage sequences** 

All sequences begin with an acquisition phase where all visible satellite ephemeris and almanacs are downloaded. The position of the first fix after the first low power period is approximate, but all next periods are regularly placed every “Fix Period”. 

Sequence 3: example of an ephemeris download period among the fixes. 

Sequence 4: example of the RTC calibration among the fixes. 

**UM2791** - **Rev 3** 

**page 32/241** 

**UM2791 Shutdown** 

## **8.2.3 Poor GNSS coverage sequences** 

## **Figure 20. GNSS poor coverage sequences** 

In all sequences, the acquisition phase is ok and all ephemeris and almanacs are downloaded. The steady state is entered, but a loss of coverage occurs during the Low Power period. 

Sequence 1: _NoFixCnt_ = 0 means we don’t alternate fix activities and low power periods. On the GNSS activation, the loss of coverage is detected and the Teseo-Module will remain active until the recovery of the fix. 

Sequence 2: As _NoFixCnt_ is different from 0, the GNSS solution will remain active during N seconds and go back to low power state during M seconds. It will alternate this way until the fix is recovered. 

Sequence 3: Despite the loss of coverage, the GNSS solution will try to decode the satellites when the ephemeris refresh activity is due. Instead of lasting 40 to 60s, the trial period will be only N seconds. 

## **8.3** 

## **Shutdown** 

Safer shutdown procedure avoiding interrupted NVM driver operations can be implemented using the NMEA command $PSTMGPSSUSPEND. 

When the Teseo-Module shutdown procedure is completed the Teseo-Module replies with a NMEA message $PSTMGPSSUSPENDED. 

When the NMEA message $PSTMGPSSUSPENDED is received the Teseo-Module can be switched-OFF. 

**UM2791** - **Rev 3** 

**page 33/241** 

**UM2791 Low latency interface** 

## **9 Low latency interface** 

Low Latency Inteface (LLI) implements a different mode of sending PVT data. 

If LLI is disabled, when the new FIX is computed the GNSS-lib generates a FIX-Event and on that the NMEA process generates the message (i.e.: $xxGGA) with the PVT data and sends it to UART. This processing leads to delay jittering in the output messages. 

If the LLI mode is enabled, the PVT data are interpolated by propagating the latest PTV values up to the UTC time-stamp of the NMEA message and then sent regularly without waiting for the fix event. Propagation is carried out using a faster algorithm therefore there is no jittering. 

The propagation mode is always the same: hypothesis of uniform rectilinear motion starting from the last known point. 

LLI can be enabled/disabled in the Application-CDB, moreover LLI rate can be configured in the CDB-ID 300 – Low Latency Interface rate 

LLI is supported only on the message-list-2. 

**UM2791** - **Rev 3** 

**page 34/241** 

**UM2791 NMEA command specification** 

## **10 NMEA command specification** 

## **10.1 ST NMEA command specifications** 

## **10.1.1 $PSTMINITGPS** 

Initialize GNSS position and time using UTC format. This command must be issued after a cold reset or it fails. The date issued with parameters day, month and year must be later than January 2015. This threshold can be changed using the configuration options. 

## **Synopsis:** 

```
$PSTMINITGPS,<Lat>,<LatRef>,<Lon>,<LonRef>,<Alt>,<Day>,<Month>,<Year>,<Hour>,<Minute>,
<Second>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 16. $PSTMINITGPS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Lat|DDMM.MMM|Latitude (Degree-Minute.Minute decimals)|
|LatRef|‘N’ or ‘S’|Latitude direction (North or South)|
|Lon|DDDMM.MMM|Longitude (Degree-Minute.Minute decimals)|
|LonRef|‘E’ or ‘W’|Longitude Direction (East or West)|
|Alt|dddd – Decimal,4 digits|Altitude in meters (-1500 to 100000)|
|Day|dd – Decimal, 2 digits|Day of month (01 to 31)|
|Month|mm – Decimal, 2 digits|Month (01 to 12)|
|Year|YYYY – Decimal, 4 digits|Year (2015 - …)|
|Hour|HH – Decimal, 2 digits|Hour (00 to 23)|
|Minute|MM – Decimal, 2 digits|Minute (00 to 59)|
|Second|SS – Decimal, 2 digits|Second (00 to 59)|



## **Results:** 

- The position and time will be initialized 

- In case of no errors, the $PSTMINITGPSOK message is returned 

- In case of errors, the error message $PSTMINITGPSERROR is returned 

## **Example:** 

```
$PSTMINITGPS,4811.365,N,01164.123,E,0530,23,02,2015,09,44,12
```

## **10.1.2** 

## **$PSTMINITTIME** 

Initialize GPS time using UTC format. The date issued with parameters day, month and year must be later than January 2015. This threshold can be changed using the configuration options. 

## **Synopsis:** 

```
$PSTMINITTIME,<Day>,<Month>,<Year>,<Hour>,<Minute>,<Second>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 35/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 17. $PSTMINITTIME field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Day|dd – Decimal, 2 digits|Day of month (01 to 31)|
|Month|mm – Decimal, 2 digits|Month (01 to 12)|
|Year|YYYY – Decimal, 4 digits|Year (2015 - …)|
|Hour|HH – Decimal, 2 digits|Hour (00 to 23)|
|Minute|MM – Decimal, 2 digits|Minute (00 to 59)|
|Second|SS – Decimal, 2 digits|Second (00 to 59)|



## **Results:** 

- The position and time will be initialized 

- In case of no errors, the $PSTMINITTIMEOK message is returned 

- In case of errors, the $PSTMINITTIMEERROR error message is returned 

## **Example:** 

```
$PSTMINITTIME,23,02,2015,09,44,12
```

## **10.1.3** 

## **$PSTMINITFRQ** 

Initialize the centre frequency. This command can be used to set the local oscillator frequency offset. 

## **Synopsis:** 

```
$PSTMINITFRQ,<offset>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 18. $PSTMINITFRQ field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|offset|Decimal, 6 digits|Frequency offset in Hz|



## **Results:** 

- The centre frequency will be initialized 

## **Example:** 

```
$PSTMINITFRQ,-47000*<checksum><cr><lf>
```

## **10.1.4 $PSTMSETRANGE** 

Set the frequency range for satellite searching. The “min.” and “max.” values are used as offsets versus the centre frequency. 

## **Synopsis:** 

```
$PSTMSETRANGE,<min>,<max>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 36/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 19. $PSTMSETRANGE field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|min|Decimal, 6 digits|Lower limit range in Hz|
|max|Decimal, 6 digits|Upper limit range in Hz|



## **Results:** 

- In case of no errors, the $PSTMSETRANGEOK message is returned 

- In case of errors, the $PSTMSETRANGEERROR error message is returned 

## **Example:** 

```
$PSTMSETRANGE,-57000,-37000*<checksum><cr><lf>
```

## **10.1.5 $PSTMALMANAC** 

Load almanacs data. This command allows the user to load the almanacs data into NVM memory. 

## **Synopsis:** 

```
$PSTMALMANAC,<sat_id>,<N>,<byte1>,…..,<byteN>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 20. $PSTMALMANAC field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_id|Decimal, 2 digits|Satellite number|
|N|Decimal, 1 digit|Number of the almanac data bytes|
|byte1|Hexadecimal, 2 digits|First byte of the almanac data|
|byteN|Hexadecimal, 2 digits|Last byte of the almanac data|
|checksum|Hexadecimal, 2 digits|Checksum of the message bytes without<br>*<checksum><cr><lf> characters.|



The N Bytes that are in the parameters are the dump of a structures that contain all the information of the almanac. 

Data format are constellation dependant. 

**UM2791** - **Rev 3** 

**page 37/241** 

**UM2791 ST NMEA command specifications** 

**Table 21. $PSTMALMANAC field description for GPS constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|8|satid|The satellite number|
|16|week|The week number for the epoch|
|8|toa|Reference time almanac.|
|16|e|Eccentricity.|
|16|delta_i|Rate of inclination angle.|
|16|omega_dot|Rate of right ascension.|
|24|root_A|Square root of semi-major axis.|
|24|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|24|perigee|Argument of perigee.|
|24|mean_anomaly|Mean anomaly at reference time.|
|11|af0|Constant clock correction.|
|11|af1|First order clock correction.|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|
|1|available|Contains 1 if almanac is available 0 if not.|



**Table 22. $PSTMALMANAC field description for GLONASS constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|8|satid|The satellite number.|
|16|week|The week number for the epoch.|
|8|toa|Reference time almanac.|
|5|n_A|Slot number (1…24).|
|5|H_n_A|Carrier frequency channel number.|
|2|M_n_A|Type of satellite 00=GLONASS 01=GLONASS-M.|
|10|tau_n_A|Satellite clock correction.|
|15|epsilon_n_A|Eccentricity.|
|21|t_lambda_n_A|Time of the first ascending node passage.|
|21|lambda_n_A|Longitude of ascending node of orbit plane at almanac<br>epoch.|
|18|delta_i_n_A|Inclination angle correction to nominal value.|
|7|delta_T_n_dot_A|Draconian period rate of change.|
|22|delta_T_n_A|Draconian period correction.|
|16|omega_n_A|Argument of perigee.|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|
|1|available|Contains 1 if almanac is available 0 if not.|
|32|Tau_c||
|11|NA||
|5|N4||
|16|Spare||



**UM2791** - **Rev 3** 

**page 38/241** 

**UM2791 ST NMEA command specifications** 

**Table 23. $PSTMALMANAC field description for Galileo constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|16|satid|The satellite number|
|6|svid|Space Vehicle Identificator|
|16|week|The week number for the epoch|
|20|toa|Reference time almanac.|
|13|delta_a|Delta of semi-major axis.|
|11|e|Eccentricity.|
|16|perigee|Argument of perigee.|
|11|delta_i|Rate of inclination angle.|
|16|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|11|omega_dot|Rate of right ascension.|
|16|mean_anomaly|Mean anomaly at reference time.|
|16|af0|Constant clock correction.|
|13|af1|First order clock correction.|
|2|E5b_HS|E5 Signal Health Status|
|2|E1B_HS|E1-B Signal Health Status|
|4|ioda_1|Issue of data Almanac 1|
|4|ioda_2|Issue of data Almanac 2|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|
|2|RESERVED|RESERVED for use by GNSS library|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|1|available|Contains 1 if almanac is available 0 if not.|



**Table 24. $PSTMALMANAC field description for BeiDou constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|8|prn|PRN number of the corresponding almanac data|
|16|week|Almanac reference week number|
|8|toa|Almanac reference time|
|17|eccentricity|Eccentricity|
|11|af0|Satellite clock time bias correction coefficient|
|1|is_geo|Satellite orbit type|
|1|WNa_valid||
|2|spare0||
|17|omega_dot|Rate of right ascension|
|11|af1|Satellite clock time drift correction coefficient|
|4|Spare1||
|24|root_a|Square root of semi-major axis|
|8|Spare2||
|24|omega_zero|Longitude of ascending node of orbital plane at weekly<br>epoch|
|8|Spare3||



**UM2791** - **Rev 3** 

**page 39/241** 

**UM2791 ST NMEA command specifications** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|24|Perigee|Argument of perigee|
|8|Spare4||
|24|mean_anomaly|Mean anomaly at reference time|
|8|Spare5||
|16|delta_i|Correction of inclination angle at reference time|
|1|Health|Satellite health information|
|1|available|Contains 1 if almanac is available 0 if not.|
|8|last_received_toa||
|6|spare6||



## **Results:** 

- The almanac will stored into backup memory 

- In case of no errors the message $PSTMALMANACOK is returned 

- In case of errors, the $PSTMALMANACERROR error message is returned 

## **Example:** 

```
$PSTMALMANAC,12,32,0c1a06907c1a971160fd0800fa0da141ae9f0600d912e90075669700490f8000*75
```

## **10.1.6 $PSTMCLRALMS** 

This command erases all the almanacs stored in the NVM backup memory. 

## **Synopsis:** 

```
$PSTMCLRALMS*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- All almanacs, stored in the non-volatile backup memory, will be deleted. 

- No message will be sent as reply. 

## **Example:** 

```
$PSTMCLRALMS*<checksum><cr><lf>
```

## **10.1.7 $PSTMDUMPALMANAC** 

Dump almanac data. This command sends out all almanacs stored in the backup memory. **Synopsis:** 

## `$PSTMDUMPALMANAC*<checksum><cr><lf>` 

## **Arguments:** 

None. 

## **Results:** 

- Teseo-Module replies with the $PSTMALMANAC messages 

**UM2791** - **Rev 3** 

**page 40/241** 

**UM2791 ST NMEA command specifications** 

## **Example:** 

```
$PSTMDUMPALMANAC
$PSTMALMANAC,1,32,011a06903f1f9f0d58fd0800d90ca1418713060099ee260034024200b4ffff00*1a
$PSTMALMANAC,2,32,021a0690944b78fe37fd0800770da141ef0c5b0060487700989bd800d8088000*1a
$PSTMALMANAC,3,32,031a06904f68a2f540fd0800f60ca141922a2c003cae27009496cf00020a8000*15
$PSTMALMANAC,4,32,041a0690a94aeffd36fd0800390ca141afc95b00de7a1700dfc74e004ddebf00*13
$PSTMALMANAC,5,32,051a0690940eee0b5efd0800900ca141582b8600d3000b0060641200e40f8000*14
```

## **10.1.8 $PSTMEPHEM** 

This command allows the user to load the ephemeris data into NVM memory. 

The commands need to be issued, between two consecutive commands there must be at least a 20 millisecond delay. 

## **Synopsis:** 

```
$PSTMEPHEM,<sat_id>,<N>,<byte1>,…..,<byteN>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 25. $PSTMEPHEM field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_id|Decimal, 2 digits|Satellite number|
|N|Decimal, 1 digit|Number of the ephemeris data bytes|
|byte1|Hexadecimal, 2 digits|First byte of the ephemeris data|
|byteN|Hexadecimal, 2 digits|Last byte of the ephemeris data|



The N Bytes that are in the parameters are the dump of structures that contain all the information of the ephemeris. 

## **Results:** 

- The ephemeris will be stored into backup RAM 

- In case of no errors, the $PSTMEPHEMOK message is returned 

- In case of errors, the $PSTMEPHEMERROR error message is returned 

Data format are constellation dependant. 

**Table 26. $PSTMEPHEM field description for GPS constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data|
|16|toe|Time of week for ephemeris epoch|
|16|toc|Time of week for clock epoch|
|8|iode1|Issue of data 1|
|8|iode2|Issue of data 2|
|10|iodc|Issue of data clock|
|14|i_dot|Rate of inclination angle.|
|8|RESERVED||
|24|omega_dot|Rate of right ascension.|
|8|RESERVED|Must be 0.|
|16|crs|Amplitude of the sine harmonic correction to the orbit radius.|



**UM2791** - **Rev 3** 

**page 41/241** 

**UM2791 ST NMEA command specifications** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|16|crc|Amplitude of the cosine harmonic correction to the orbit<br>radius.|
|16|cus|Amplitude of the sine harmonic correction to the argument of<br>latitude.|
|16|cuc|Amplitude of the cosine harmonic correction to the argument<br>of latitude.|
|16|cis|Amplitude of the sine harmonic correction to the angle of<br>inclination.|
|16|cic|Amplitude of the cosine harmonic correction to the angle of<br>inclination.|
|16|motion_difference|Mean motion difference from computed value|
|16|RESERVED|Must be 0.|
|32|inclination|Inclination angle at reference time|
|32|e|Eccentricity.|
|32|root_A|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|8|time_group_delay|Estimated group delay differential.|
|8|af2|Second order clock correction.|
|16|af1|First order clock correction.|
|22|af0|Constant clock correction.|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|1|RESERVED|Must be 0.|
|4|accuracy|Accuracy|



**Table 27. $PSTMEPHEM field description for GLONASS constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data.|
|16|toe|Time of week for ephemeris epoch.|
|4|toe_lsb|Time of week for ephemeris epoch (LBS).|
|11|NA|Calendar day number within the four-year period since the<br>beginning of last leap year (almanac).|
|7|tb|Time of ephemeris index.|
|2|M|Type of satellite 00=GLONASS 01=GLONASS-M .|
|2|P1|Time interval between two adjacent tb parameters.|
|1|P3|Number of satellites for which almanac is transmitted within<br>this frame 0=4 1=5.|
|1|P2|Flag of oddness ("1") or evenness ("0") of the value of tb|



**UM2791** - **Rev 3** 

**page 42/241** 

**UM2791 ST NMEA command specifications** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|1|P4|Flag to show that ephemeris parameters are present.|
|2|KP|Notification on forthcoming leap second correction of UTC|
|1|RESERVED||
|27|xn|Satellite PZ-90 x coordinate at epoch tb.|
|5|xn_dot_dot|Satellite PZ-90 x velocity at epoch tb.|
|24|xn_dot|Satellite PZ-90 x acceleration component at epoch tb.|
|5|n|Slot number (1…24).|
|3|Bn|Healthy flags.|
|27|yn|Satellite PZ-90 y coordinate at epoch tb.|
|5|yn_dot_dot|Satellite PZ-90 y acceleration component at epoch tb.|
|24|yn_dot|Satellite PZ-90 y velocity at epoch tb.|
|8|age_h|Age of predicted ephemeris (hours)|
|27|zn|Satellite PZ-90 z coordinate at epoch tb.|
|5|zn_dot_dot|Satellite PZ-90 z acceleration component at epoch tb.|
|24|zn_dot|Satellite PZ-90 z velocity at epoch tb.|
|8|RESERVED|Must be 0.|
|11|gamma_n|Satellite clock frequency drift at epoch tb.|
|5|E_n|Age of the ephemeris information.|
|4|freq_id|Frequency ID|
|12|RESERVED||
|22|tau_n|Satellite clock correction at epoch tb.|
|10|RESERVED|Must be 0.|
|32|tau_c|GLONASS to UTC(SU) time correction.|
|22|tau_GPS|GLONASS to GPS system time correction.|
|10|RESERVED||
|11|NT|Calendar day number of ephemeris within the four-year<br>period since the beginning of last leap year.|
|5|N4|Four-year interval number starting from 1996.|
|12|tk|Satellite time referenced to the beginning of the frame.|
|4|FT|Predicted satellite user range accuracy<br>at time tb|
|32|RESERVED||
|5|m_available|Must be 0x1F|
|1|nvm_reliable|Must be 1.|
|26|spare||
|25|RESERVED||
|1|available|Contains 1 if ephemeris is available, 0 if not.|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy.|
|1|RESERVED|Must be 0.|
|4|RESERVED||



**UM2791** - **Rev 3** 

**page 43/241** 

**UM2791 ST NMEA command specifications** 

**Table 28. $PSTMEPHEM field description for Galileo constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data|
|14|toe|Time of week for ephemeris epoch|
|2|RESERVED||
|16|toc|Time of week for clock epoch|
|10|iod_nav|Issue of data|
|8|SISA|Signal In Space Accuracy|
|10|RESERVED|Must be 0.|
|10|BGD_E1_E5a|E1-E5a Broadcast Group Delay|
|10|BGD_E1_E5b|E1-E5b Broadcast Group Delay|
|2|E1BHS|E1-B Signal Health Status|
|32|inclination|Inclination angle at reference time|
|32|eccentricity|Eccentricity.|
|32|root_a|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|14|i_dot|Rate of inclination angle.|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|16|motion_difference|Mean motion difference from computed value|
|16|crs|Amplitude of the sine harmonic correction to the orbit radius.|
|16|crc|Amplitude of the cosine harmonic correction to the orbit<br>radius.|
|16|cus|Amplitude of the sine harmonic correction to the argument of<br>latitude.|
|16|cuc|Amplitude of the cosine harmonic correction to the argument<br>of latitude.|
|16|cis|Amplitude of the sine harmonic correction to the angle of<br>inclination.|
|16|cic|Amplitude of the cosine harmonic correction to the angle of<br>inclination.|
|24|omega_dot|Rate of right ascension.|
|6|SVID|Satellite Identification.|
|1|E1BDVS|E1-B Data Validity Status|
|1|RESERVED|Must be 0.|
|8|RESERVED|Must be 0.|
|16|RESERVED|Must be 0.|
|6|af2|Second order clock correction.|
|21|af1|First order clock correction.|
|5|word_available|Must be 0x1F.|
|31|af0|Constant clock correction.|
|1|RESERVED||



**UM2791** - **Rev 3** 

**page 44/241** 

**UM2791 ST NMEA command specifications** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|6|RESERVED|Must be 0|
|26|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|Must be 0.|



**Table 29. $PSTMEPHEM field description for BeiDou constellation** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|32|inclination|Inclination angle at reference time|
|32|eccentricity|Eccentricity.|
|32|root_a|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|17|toe|Time of week for ephemeris epoch|
|10|time_group_delay|Estimated group delay differential.|
|5|aode|Issue of data, ephemeris|
|24|omega_dot|Rate of right ascension.|
|8|A0|Ionospheric Delay Model Parameter α0|
|24|af0|Constant clock correction.|
|8|A1|Ionospheric Delay Model Parameter α1|
|20|sow|Seconds of week|
|11|af2|Second order clock correction.|
|1|is_geo|1 for Geostationary satellites, otherwise 0|
|22|af1|First order clock correction.|
|10|subframe_avail|Must be 0x3FF.|
|16|motion_difference|Mean motion difference from computed value|
|8|A2|Ionospheric Delay Model Parameter α2|
|8|A3|Ionospheric Delay Model Parameter α3|
|18|crs|Amplitude of the sine harmonic correction to the orbit radius.|
|8|B2|Ionospheric Delay Model Parameter β2|
|4|urai|User range accuracy index|
|2|RESERVED|Must be 0.|
|18|crc|Amplitude of the cosine harmonic correction to the orbit<br>radius.|
|8|B3|Ionospheric Delay Model Parameter β3|
|5|aodc|Issue of data, clock|
|1|spare||
|18|cus|Amplitude of the sine harmonic correction to the argument of<br>latitude.|
|14|i_dot|Rate of inclination angle.|
|18|cuc|Amplitude of the cosine harmonic correction to the argument<br>of latitude.|
|8|B0|Ionospheric Delay Model Parameter β0|



**UM2791** - **Rev 3** 

**page 45/241** 

**UM2791 ST NMEA command specifications** 

|**Bits**|**Structure member**|**Description**|
|---|---|---|
|6|spare||
|18|cis|Amplitude of the sine harmonic correction to the angle of<br>inclination.|
|8|B1|Ionospheric Delay Model Parameter β1|
|6|RESERVED|Must be 0.|
|18|cic|Amplitude of the cosine harmonic correction to the angle of<br>inclination.|
|1|nvm_reliable|Must be 1.|
|11|RESERVED|Must be 0.|
|2|spare||
|17|toc|Time of week for clock epoch|
|13|week|Week number of the Issue of Data|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|



## **Example:** 

```
$PSTMEPHEM,12,64,
0f06bc34bc3437373790f40045a7ff00fcf5d522480b4bf71b00fbff8931000096126f271f869101c3870ca107
afce79a763e13e360a1ce8e7003100380ff903*36
```

## **10.1.9** 

## **$PSTMCLREPHS** 

Clear all ephemeris. This command erases all the ephemeris stored in the NVM memory. **Synopsis:** 

```
$PSTMCLREPHS*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- All ephemeris, stored in the non-volatile backup memory will be deleted. 

- No message will be sent as reply. 

## **Example:** 

```
$PSTMCLREPHS*<checksum><cr><lf>
```

## **10.1.10** 

## **$PSTMDUMPEPHEMS** 

This command sends out all ephemeris stored in the backup memory. 

## **Synopsis:** 

```
$PSTMDUMPEPHEMS*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Teseo-Module replies with the $PSTMEPHEM messages 

**UM2791** - **Rev 3** 

**page 46/241** 

**UM2791 ST NMEA command specifications** 

## **Example:** 

```
$PSTMDUMPEPHEMS
$PSTMEPHEM,1,64,
0f06bc34bc345f5f5f84f400dea4ff00f9f63c239f0a35f81400fbff
33420000ee632f27698ef001afa50da16cfcfa22e0b65a3e7a3cee27d700f7ffc616fe03
*57
$PSTMEPHEM,2,64
0f06bc34bc344f4f4f78110019a5ff00b004fa1d1e0e3f04c8ffcaff
1937000033515726556ba9048eae0da1b6c346bd8f985c93ade10c76db001d00f8c7c503
*58
$PSTMEPHEM,4,64,
0f06bb34bb344b4b4b98050038a4ff000005351e110eea041b00b8ff
d037000020b84e26b5138b0425580ca16b211030e68b1a949cac9615f30066ffea92f603
*06
$PSTMEPHEM,9,64,
0f06bc34bc341818189c0a0069aaff005f06eb249a09ca0477ff6c00
f72e00005131d827592b950a91010da1c7af88538e7ca1122fb9be3df4001300c4a0c203
*52
```

## **10.1.11** 

## **$PSTMSRR** 

Executes a system reset. The GNSS firmware is rebooted. 

## **Synopsis:** 

```
$PSTMSRR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The GNSS firmware reboots. 

- No message will be sent as reply. 

## **Example:** 

```
$PSTMSRR*<checksum><cr><lf>
```

## **10.1.12 $PSTMGPSRESET** 

Reset the GNSS Teseo-Module engine. **Synopsis:** 

```
$PSTMGPSRESET*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The Teseo-Module engine will be reset 

- No message will be sent as reply. 

Note: using this command the GNSS module won’t reboot. 

## **Example:** 

```
$PSTMGPSRESET*<checksum><cr><lf>
```

## **10.1.13 $PSTMGPSSUSPEND** 

Suspend the GNSS Teseo-Module engine. 

**Synopsis:** 

**UM2791** - **Rev 3** 

**page 47/241** 

**UM2791** 

**ST NMEA command specifications** 

```
$PSTMGPSSUSPEND*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- the $PSTMGPSSUSPENDED message will be sent when Teseo-Module engine is suspended 

## **Example:** 

```
$PSTMGPSSUSPEND*<checksum><cr><lf>
```

## **10.1.14 $PSTMGPSRESTART** 

Restart the GNSS Teseo-Module engine. 

## **Synopsis:** 

## `$PSTMGPSRESTART*<checksum><cr><lf>` 

## **Arguments:** 

None. 

## **Results:** 

- The GNSS Teseo-Module engine will be restarted 

- No message will be sent as reply. 

## **Example:** 

```
$PSTMGPSRESTART*<checksum><cr><lf>
```

## **10.1.15 $PSTMCOLD** 

Perform a COLD start. 

## **Synopsis:** 

## `$PSTMCOLD,<Mask>*<checksum><cr><lf>` 

## **Arguments:** 

**Table 30. $PSTMCOLD field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Mask|Integer|Optional parameter to invalidate time,<br>position, ephemeris and almanac :<br>0x1 – clear almanac<br>0x2 – clear ephemeris<br>0x4 – clear position<br>0x8 – clear time|



## **Results:** 

- Coldstart initialization and system restart. 

- If Mask parameter is used, only the selected GPS data is invalidated for this actual Coldstart. Multiple selects are supported (i.e. 0xD). 

- If Mask parameter is not used, default is 0xE (clear ephemeris, time and position). 

## **Example:** 

```
$PSTMCOLD,6
```

**UM2791** - **Rev 3** 

**page 48/241** 

**UM2791 ST NMEA command specifications** 

_Note: The GNSS engine will be reset. It is not a system reboot._ **10.1.16 $PSTMWARM** Perform a WARM start. **Synopsis:** `$PSTMWARM*<checksum><cr><lf>` **Arguments:** None. **Results:** • Warm start initialization and system restart. **Example:** `$PSTMWARM*<checksum><cr><lf>` 

_Note: The GNSS engine will be reset. It is not a system reboot._ 

## **10.1.17 $PSTMHOT** 

Perform an HOT start. 

## **Synopsis:** 

## `$PSTMHOT*<checksum><cr><lf>` **Arguments:** None. **Results:** • The system restart. **Example:** 

```
$PSTMHOT*<checksum><cr><lf>
```

_Note: The GNSS engine will be reset. It is not a system reboot._ 

## **10.1.18 $PSTMNMEAONOFF** 

Toggle NMEA output. This command switches ON or OFF the output NMEA messages. **Synopsis:** 

```
$PSTMNMEAONOFF,<on_off>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 31. $PSTMNMEAONOFF field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Integer|0 = NMEA output is turned OFF<br>1 = NMEA output is turned ON|



## **Results:** 

- NMEA output message is started or stopped according the ‘on_off’ field value. 

## **Example:** 

```
$PSTMNMEAONOFF,0*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 49/241** 

**UM2791** 

**ST NMEA command specifications** 

## **10.1.19 $PSTMGNSSINV** 

Invalidate the GNSS Fix Status. 

## **Synopsis:** 

```
$PSTMGNSSINV,<invalid>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 32. $PSTMGNSSINV field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|invalid|Integer|Invalid flag allowing to change the GNSS Fix status<br>1: GNSS Fix status is set to NO_FIX<br>0: GNSS Fix Status unchanged|



## **Results:** 

- `$PSTMGNSSINV,1` invalidates the GNSS Fix Status. A NO FIX status is so simulated. 

- `$PSTMGNSSINV,0` allows to restore the real GNSS Fix status. 

## **Example:** 

```
$PSTMGNSSINV,1*<checksum><cr><lf>
```

## **10.1.20 $PSTMTIMEINV** 

Invalidate the Real Time Clock (RTC). 

## **Synopsis:** 

```
$PSTMTIMEINV*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The RTC time will be invalidated. 

## **Example:** 

```
$PSTMTIMEINV*<checksum><cr><lf>
```

## **10.1.21 $PSTMGETSWVER** 

Get the version string of the libraries embedded in the software application. 

## **Synopsis:** 

```
$PSTMGETSWVER,<id>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 33. $PSTMGETSWVER field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|id|Integer|Depending on the value of the <lib_id> parameter, the<br>following version numbering is delivered by the command:<br>0 = GNSS Library Version<br>1 = OS20 Version|



**UM2791** - **Rev 3** 

**page 50/241** 

**UM2791** 

**ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||2 = SDK App Version<br>6 = Binary Image Version<br>7 = STA8089 HW version<br>11 = SW configuration ID<br>12 = Product ID<br>254 = configuration data block<br>255 = all versions strings (as reported at the NMEA startup).|



## **Results:** 

- GNSS replies with $PSTMVER messages 

## **10.1.22** 

## **$PSTMNVMSWAP** 

Execute a bank swap on the NVM memory. 

## **Synopsis:** 

```
$PSTMNVMSWAP*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The non-volatile backup memory banks will be swapped 

## **Example:** 

```
$PSTMNVMSWAP*<checksum><cr><lf>
```

## **10.1.23 $PSTMSBASONOFF** 

Suspend / resume the SBAS software execution. 

## **Synopsis:** 

```
$PSTMSBASONOFF*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- If SBAS was running it will be suspended, if it was suspended it will start to run. 

## **Example:** 

```
$PSTMSBASONOFF*<checksum><cr><lf>
```

## **10.1.24 $PSTMSBASSERVICE** 

Change the SBAS service. 

## **Synopsis:** 

```
$PSTMSBASSERVICE,<service>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 51/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 34. $PSTMBASSERVICE field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|service|Integer|SBAS service<br>0 = WAAS<br>1 = EGNOS<br>2 = MSAS<br>3 = GAGAN<br>4 = SDCM<br>7 = OFF<br>15 = AUTO|



## **Results:** 

- The SBAS engine will put in tracker all the satellites, which correspond to the specified service. 

- With SBAS service OFF, no satellites are put in tracker. In that case, SBAS frames are to be provided to the SBAS engine through the $PSTMSBASM command 

- With SBAS AUTO, the SBAS engines automatically selects the appropriate SBAS service based on the computed user position latitude and longitude. 

- In case of no errors, the $PSTMSBASSERVICEOK message is returned 

- In case of errors, the $PSTMSBASSERVICEERROR error message is returned 

## **Example:** 

```
$PSTMSBASSERVICE,15*<checksum><cr><lf>
```

## **10.1.25 $PSTMSBASSAT** 

Change the SBAS satellite. 

## **Synopsis:** 

```
$PSTMSBASSAT,<prn>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 35. $PSTMSBASSAT field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|prn|Decimal, 3 digit|Satellite PRN (range: from 120 to 140)|



## **Results:** 

- Kept for compatibility. Set SBAS service AUTO. 

- The preferred NMEA command is $PSTMSBASSERVICE. 

## **Example:** 

```
$PSTMSBASSAT,120*<checksum><cr><lf>
```

## **10.1.26** 

## **$PSTMSBASM** 

Send a SBAS frame to the SBAS engine. 

## **Synopsis:** 

**UM2791** - **Rev 3** 

**page 52/241** 

**UM2791 ST NMEA command specifications** 

```
$PSTMSBASM,<prn><sbas_frame>*<checksum><cr><lf>
```

**Arguments:** 

**Table 36. $PSTMSBASM field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|prn|Decimal, 3 digits|Satellite PRN (Range: from 120 to 140)|
|sbas_frame|Hexadecimal, 64 digits|SBAS frame (250 bits + 6 padding)|



## **Results:** 

- Sends the SBAS frame to the SBAS engine. 

- Note: The SBAS service has to be set to OFF before sending SBAS frames so that no SBAS satellites are put in tracking. 

- In case of no errors, the $PSTMSBASMOK message is returned 

- In case of errors, the $PSTMSBASMERROR error message is returned 

## **Example:** 

```
$PSTMSBASM,123,536A481B40D8063829C12E08704B82DFFDFFEFFF7FFBFFDFFEF06E803
7EFB440*6D
```

## **10.1.27 $PSTMRFTESTON** 

Enable the RF test mode for production line tests. 

## **Synopsis:** 

```
$PSTMRFTESTON,<sat_id>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 37. $PSTMRFTESTON field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_id|Decimal, 2 digits|Satellite number|



## **Results:** 

- The GNSS engine will restart in the RF test modality. This RF test forces the GNSS acquiring process only on the provided satellite’s id. It could be useful to reduce the RF testing time in the production line where generally a single channel simulator is present 

## **Example:** 

```
$PSTMRFTESTON,24*<checksum><cr><lf>
```

## **10.1.28 $PSTMRFTESTOFF** 

Disable the RF test mode for production line tests. 

## **Synopsis:** 

```
$PSTMRFTESTOFF*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The RF test modality will be disabled and the GNSS engine will be restarted. 

**UM2791** - **Rev 3** 

**page 53/241** 

**UM2791** 

**ST NMEA command specifications** 

_Note: the RF test mode can be disabled also resetting the Teseo-Module._ 

## **Example:** 

```
$PSTMRFTESTOFF*<checksum><cr><lf>
```

## **10.1.29 $PSTMGETALGO** 

Get False Detection and Exclusion (FDE) algorithm ON/OFF status. 

## **Synopsis:** 

```
$PSTMGETALGO,<algo_type>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 38. $PSTMGETALGO field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|algo_type|Decimal, 1 digit|1 = FDE algorithm on/off status is returned.|



## **Results:** 

- In case of no errors, the $PSTMGETALGOOK message is returned 

- In case of errors, the $PSTMGETALGOERROR error message is returned 

## **Example:** 

```
$PSTMGETALGO,1*<checksum><cr><lf>
```

## **10.1.30 $PSTMSETALGO** 

Set false detection and exclusion (FDE) algorithm ON/OFF status. 

## **Synopsis:** 

```
$PSTMSETALGO,<algo_type>,<algo_status>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 39. $PSTMSETALGO field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|algo_type|Decimal, 1 digit|1 = FDE algorithm on/off status is returned.|
|algo_status|Decimal, 1 digit|0 = the algorithm is disabled.<br>1 = the algorithm is enabled.|



## **Results:** 

- In case of no errors, the $PSTMSETALGOOK message is returned 

- In case of errors, the $PSTMSETALGOERROR error message is returned 

## **Example:** 

```
$PSTMSETALGO,1,0*<checksum><cr><lf>
```

## **10.1.31** 

## **$PSTMGETRTCTIME** 

Get the current RTC time. 

## **Synopsis:** 

**UM2791** - **Rev 3** 

**page 54/241** 

**UM2791** 

**ST NMEA command specifications** 

```
$PSTMGETRTCTIME*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- System will send $PSTMGETRTCTIME message 

## **Example:** 

```
$PSTMGETRTCTIME
```

## **10.1.32** 

## **$PSTMDATUMSELECT** 

Set a local geodetic datum different from WGS84 (default). **Synopsis:** 

```
$PSTMDATUMSELECT,<datum_type>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 40. $PSTMDATUMSELECT field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|datum_type|Integer|The following datum are selectable:<br>0 : WGS84<br>1: TOKYO MEAN<br>2: OSGB|



## **Results:** 

- In case of no errors, the $PSTMDATUMSELECTOK message is returned 

- In case of errors, the $PSTMDATUMSELECTERROR error message is returned 

## **Example:** 

```
$PSTMSELETDATUM,1*<checksum><cr><lf>
```

## **10.1.33** 

## **$PSTMDATUMSETPARAM** 

Set parameters to local geodetic to WGS84 datum transformations. **Synopsis:** 

```
$PSTMDATUMSETPARAM,<d_x>,<d_y>,<d_z>,<d_a>,<d_f>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 41. $PSTMDATUMSETPARAM field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|d_x<br>d_y<br>d_z|Decimal|shifts between centres of the local geodetic datum and<br>WGS84 Ellipsoid|
|d_a|Decimal|differences between the semi-major axis of the local<br>geodetic datum ellipsoid and the WGS 84 ellipsoid,<br>respectively (WGS 84 minus Local)|
|d_f|Decimal|differences between flattening of the|



**UM2791** - **Rev 3** 

**page 55/241** 

**UM2791** 

**ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||local geodetic datum ellipsoid and the WGS 84 ellipsoid,<br>respectively (WGS 84 minus Local)|



## **Results:** 

- In case of no errors, the $PSTMDATUMSETPARAMOK message is returned 

- In case of errors, the $PSTMDATUMSETPARAMERROR error message is returned 

## **Example:** 

```
$PSTMDATUMSETPARAM,-375,111,-431,-573.60, -0.000011960023
```

## **10.1.34 $PSTMENABLEPOSITIONHOLD** 

Enable/disable and set position for the Position Hold feature. 

## **Synopsis:** 

```
$PSTMENABLEPOSITIONHOLD,<on_off>,<Lat>,<LatRef>,<Lon>,<LonRef>,
<Alt>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 42. $PSTMENABLEPOSITIONHOLD field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|Set the position hold enable/disable status:<br>0: disabled.<br>1: enabled.|
|Lat|DDMM.MMMMM|Latitude (Degree-Minute.Minute decimals)|
|LatRef|‘N’ or ‘S’|Latitude direction (North or South)|
|Lon|DDDMM.MMMMM|Longitude (Degree-Minute.Minute decimals)|
|LonRef|‘E’ or ‘W’|Longitude Direction (East or West)|
|Alt|dddddd.dddd|Altitude in meters (-1500 to 100000)|



## **Results:** 

- In case of no errors, and position hold is enabled the $PSTMPOSITIONHOLDENABLED message is returned 

- In case of no errors, and position hold is disabled the $PSTMPOSITIONHOLDDISABLED message is returned 

- In case of error the $PSTMENABLEPOSITIONHOLDERROR error message is sent: 

## **Example:** 

```
$PSTMENABLEPOSITIONHOLD,1,4811.365,N,01164.123,E,0530.0
```

_Note:_ 

_The altitude value must be reported without any geoid correction. It means that if the altitude value is retrieved by the $GPGGA message it must be added to the geoid correction before using it in the $PSTMENABLEPOSITIONHOLD command. This limitation may be removed in the future releases._ 

## **10.1.35** 

## **$PSTMSETCONSTMASK** 

Set the GNSS constellation mask. It allows switching the GNSS constellation at run-time. **Synopsis:** 

```
$PSTMSETCONSTMASK,<constellation_mask>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 56/241** 

**UM2791** 

**ST NMEA command specifications** 

## **Arguments:** 

**Table 43. $PSTMSETCONSTMASK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|constellation_mask|Decimal, 1 digit|It is a bit mask where each bit enable/disable a specific<br>constellation independently by the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 2: QZSS constellation enabling/disabling<br>bit 3: GALILELO constellation enabling/disabling<br>bit 7: BEIDOU constellation enabling/disabling|



## **Results:** 

- In case of no errors, the $PSTMSETCONSTMASKOK message is returned 

- In case of errors, the $PSTMSETCONSTMASKERROR error message is returned 

## **Examples:** 

Enabling GPS only: 

```
$PSTMSETCONSTMASK,1*<checksum><cr><lf>
```

Enabling GLONASS only: 

```
$PSTMSETCONSTMASK,2*<checksum><cr><lf>
```

Enabling GPS and GLONASS: 

```
$PSTMSETCONSTMASK,3*<checksum><cr><lf>
```

## **10.1.36** 

## **$PSTMNOTCH** 

This command set the Adaptive Notch Filter (ANF) operation mode 

## **Synopsis:** 

```
$PSTMNOTCH,<Sat_type>,<Mode>,<Frequency>,<kbw_gross>,<kbw_fine>,
<threshold>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 44. $PSTMNOTCH field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Sat_type|Decimal, 1 digits [Mandatory]|Sat type ANF path [0 -> GPS; 1->GLONASS]|
|Mode|Decimal, 1 digits<br>[Mandatory]|ANF operation mode<br>[0, disable, 1always on, 2 Auto (suggested)]|
|Frequency|Decimal, 8 digits<br>[Optional]|IF Frequency, at which Notch search starts<br>0-8MHz range GPS / 0-16MHz Range Glonass path.|
|kbw_gross|Decimal, 1 digit<br>[Optional]|Scan Speed [4,5,6 are supported values, the bigger the<br>slower]. 5 is defauly|
|kbw_fine|Decimal, 1 digit<br>[Optional]|Bandwidth Removed [4,5,6 are supported values, the<br>smaller the bigger]. 6 is default|



**UM2791** - **Rev 3** 

**page 57/241** 

**UM2791** 

**ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|threshold|Decimal, 5 digits<br>[Optional]|Detection threshold to lock the Notch at a given frequency<br>[Default values_3010 (GPS)/3556(GLONASS)_]|



The command can be issued in the following form: 

## **Standard configuration (2 parameters only):** 

```
$PSTMNOTCH,<sat_type>,<mode>*<checksum><cr><lf>
```

## **Enhanced configuration (3 parameters):** 

```
$PSTMNOTCH,<sat_type>,<mode>,<frequency>*<checksum><cr><lf>
```

that accepts more the frequency parameter to start search for RFI. 

## **Full configuration(6 parameters):** 

```
$PSTMNOTCH,Sat_type,Mode,Frequency,kbw_gross,kbw_fine,threshold*<checksum><cr><lf>
```

That allows completely tuning filter behaviour (speed / bandwidth / detection threshold). 

Other configurations, with a different number of parameters and/or values out of specs are not supported and can result in not predictable behaviours. 

## **Results:** 

- This command set the ANF operation mode. 

## **Example:** 

## **Standard configuration** 

```
$PSTMNOTCH,0,0 [GPS path, ANF disabled]
$PSTMNOTCH,0,1 [GPS path, ANF set in always ON mode]
[For Int. usage only]
$PSTMNOTCH,0,2
[GPS path, auto insertion mode, Initial Scan Frequency is set @ 4f0][Default]
$PSTMNOTCH,1,0 [GLONASS path, ANF disabled]
$PSTMNOTCH,1,1 [GLONASS path, always ON mode]
[For Int.usage only]
$PSTMNOTCH,1,2
[GLONASS path, auto insertion mode, Initial Scan Frequency is set @ 8f0] [Default]
```

Extra supported usages 

```
$PSTMNOTCH,0,2,frequency
[GPS path, auto insertion mode, Initial Frequency is frequency (Hz)]
$PSTMNOTCH,1,2,frequency
[GLONASS path, auto insertion mode, Initial Frequency is frequency (Hz)]
$PSTMNOTCH,0,2,frequency, kbw_gross, kbw_fine, threshold
[GPS path, auto insertion mode, Initial Scan Frequency (Hz), kbw_gross, kbw_fine, threshold
$PSTMNOTCH,1,2,frequency, kbw_gross, kbw_fine, threshold
[GLONASS path, auto insertion mode, Initial Frequency (Hz), kbw_gross, kbw_fine, threshold]
```

Usage note: 

By default the 

- **`$PSTMNOTCH,0,2`** command (notch enabled in Auto mode on GPS branch) corresponds to the explicit – _PSTMNOTCH,0,2,4092000,5,6, 3010_ 

- **`$PSTMNOTCH,1,2`** command (Notch enabled in Auto mode on Glonass Branch) corresponds to the explicit – _PSTMNOTCH,1,2,8184000,5,6, 3556_ 

## **10.1.37** 

## **$PSTMPPS** 

Allow interfacing all parameters for Pulse-Per-Second management. This is a parametric command. 

**UM2791** - **Rev 3** 

**page 58/241** 

**UM2791 ST NMEA command specifications** 

## **Synopsis:** 

```
$PSTMPPS,<cmd_mode>,<cmd_type>,<par_1>,…,<par_N>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 45. $PSTMPPS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cmd_mode|Decimal, 1 digit|Select the command operation mode:<br>1 = GET operation (to get data from PPS manager)<br>2 = SET operation (to set data into PPS manager)|
|cmd_type|Decimal, 1 digit|1 = PPS_IF_ON_OFF_CMD<br>2 = PPS_IF_OUT_MODE_CMD<br>3 = PPS_IF_REFERENCE_CONSTELLATION_CMD<br>4 = PPS_IF_PULSE_DELAY_CMD<br>5 = PPS_IF_PULSE_DURATION_CMD<br>6 = PPS_IF_PULSE_POLARITY_CMD<br>7 = PPS_IF_PULSE_DATA_CMD<br>8 = PPS_IF_FIX_CONDITION_CMD<br>9 = PPS_IF_SAT_TRHESHOLD_CMD<br>10 = PPS_IF_ELEVATION_MASK_CMD<br>11 = PPS_IF_COSTELLATION_MASK_CMD<br>12 = PPS_IF_TIMING_DATA_CMD<br>13 = PPS_IF_POSITION_HOLD_DATA_CMD<br>14 = PPS_IF_AUTO_HOLD_SAMPLES_CMD<br>15 = PPS_IF_TRAIM_CMD<br>16 = PPS_IF_TRAIM_USED_CMD<br>17 = PPS_IF_TRAIM_RES_CMD<br>18 = PPS_IF_TRAIM_REMOVED_CMD<br>19 = PPS_IF_REFERENCE_TIME_CMD<br>20 = PPS_IF_CONSTELLATION_RF_DELAY_CMD|
|par_1 … par_N||Parameters list according to the command type specification<br>(see below).|



## **Results:** 

- In case of errors, the $PSTMPPSERROR error message is returned 

## **PPS Get PPS_IF_PULSE_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,7
```

## **PPS Get PPS_IF_TIMING_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,12
```

**UM2791** - **Rev 3** 

**page 59/241** 

**UM2791 ST NMEA command specifications** 

## **PPS Get PPS_IF_POSITION_HOLD_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,13
```

## **PPS Get PPS_IF_TRAIM_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,15*<checksum><cr><lf>
```

## **PPS Get PPS_IF_TRAIM_USED_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,16*<checksum><cr><lf>
```

## **PPS Get PPS_IF_TRAIM_RES_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,17*<checksum><cr><lf>
```

## **PPS Get PPS_IF_TRAIM_REMOVED_CMD** 

## **Synopsis:** 

```
$PSTMPPS,1,18*<checksum><cr><lf>
```

## **PPS Set PPS_IF_ON_OFF_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,1,<on_off>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 46. $PSTMPPS field description on PPS_IF_ON_OFF_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|0 = PPS disabled.<br>1 = PPS enabled.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_OUT_MODE_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,2,<out_mode>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 60/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 47. $PSTMPPS field description on PPS_IF_OUT_MODE_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|out_mode|Decimal, 1 digit|0 = PPS always generated.<br>1 = PPS generated on even seconds.<br>2 = PPS generated on odd seconds.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_REFERENCE_TIME_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,19,<reference_time>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 48. $PSTMPPS field description on PPS_IF_REFERENCE_TIME_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|reference_time|Decimal, 1 digit|0 = UTC<br>1 = GPS_UTC.<br>2 = GLONASS_UTC.<br>3 = UTC_SU<br>4 = GPS_UTC_FROM_GLONASS<br>5 =BEIDOU_UTC<br>6 = UTC_NTSC<br>7 = GST<br>8 = UTC_GST<br>9 = GPS_FROM_GST<br>NOTES:<br>UTC(SU) is the Soviet Union UTC, it is derived from<br>GLONASS time applying the UTC delta time downloaded<br>from GLONASS satellites.<br>GPS_UTC_FROM_GLONASS is the GPS time derived from<br>GLONASS time applying the GPS delta time downloaded<br>from GLONASS satellites.<br>If the software is configured to work in GLONASS only<br>mode, UTC(SU) is identical to UTC and<br>GPS_UTC_FROM_GLONASS is identical to GPS_UTC.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_PULSE_DELAY_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,4,<pulse_delay>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 61/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 49. $PSTMPPS field description on PPS_IF_PULSE_DELAY_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|pulse_delay|Decimal|Pulse delay [ns]|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_CONSTELLATION_RF_DELAY_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,20,<sat_type><time_delay>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 50. $PSTMPPS field description on PPS_IF_CONSTELLATION_RF_DELAY_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_type|Decimal|Satellite constellation type:<br>0 = GPS<br>1 = GLONASS<br>3 = Galileo<br>7 = BEIDOU|
|time_delay|Decimal|Time delay [ns]|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_PULSE_DURATION_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,5,<pulse_duration>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 51.  $PSTMPPS field description on PPS_IF_PULSE_DURATION_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|pulse_duration|Double|Pulse duration [s]|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_PULSE_POLARITY_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,6,<pulse_polarity>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 62/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 52. $PSTMPPS field description on PPS_IF_PULSE_POLAROTY_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|pulse_polarity|Decimal, 1 digit|0 = not inverted.<br>1 = inverted.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_PULSE_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,7,<out_mode>,<reference_time>,<pulse_delay>,<pulse_duration>,
<pulse_polarity>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 53. $PSTMPPS field description on PPS_IF_PULSE_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|out_mode|Decimal, 1 digit|0 = PPS always generated.<br>1 = PPS generated on even seconds.<br>2 = PPS generated on odd seconds.|
|reference_time|Decimal, 1 digit|0 = UTC<br>1 = GPS_UTC<br>2 = GLONASS_UTC<br>3 = UTC_SU<br>4 = GPS_UTC_FROM_GLONASS|
|pulse_delay|Decimal|Pulse delay [ns]|
|pulse_duration|Double|Pulse duration [s]|
|pulse_polarity|Decimal, 1 digit|0 = not inverted.<br>1 = inverted.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_FIX_CONDITION_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,8,<fix_condition>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 54. $PSTMPPS field description on PPS_IF_FIX_CONDITION_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|fix_condition|Decimal, 1 digit|1 = NOFIX.|



**UM2791** - **Rev 3** 

**page 63/241** 

**UM2791 ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||2 = 2DFIX.<br>3 = 3DFIX.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_SAT_TRHESHOLD_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,9,<sat_th>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 55. $PSTMPPS field description on PPS_IF_SAT_TRHESHOLD_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_th|Decimal|Minimum number of satellites for the PPS generation.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_ELEVATION_MASK_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,10,<elevation_mask>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 56. $PSTMPPS field description on PPS_IF_ELEVATION_MASK_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|elevation_mask|Decimal|Minimum satellite elevation for satellite usage in timing<br>filtering.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_CONSTELLATION_MASK_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,11,<constellation_mask>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 57. $PSTMPPS field description on PPS_IF_CONSTELLATION_MASK_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|constellation_mask|Decimal (bit mask)|Satellite constellation selection for usage in timing filtering.<br>bit0 = GPS|



**UM2791** - **Rev 3** 

**page 64/241** 

**UM2791 ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||bit1 = GLONASS<br>NOTES:<br>This parameter enables the usage of mixed constellations<br>satellites in the timing filtering. If bit0 is enabled GPS<br>satellites are used to correct the GLONASS reference time<br>together with GLONASS satellites. If bit1 is enabled,<br>GLONASS satellites are used to correct the GPS reference<br>time together with the GPS satellites. When constellation<br>mask is zero (default) only GPS sats are used to correct the<br>GPS reference time and only GLONASS sats are used to<br>correct the GLONASS reference time.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_TIMING_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,12,<fix_condition>,<sat_th>,<elevation_mask>,
<constellation_mask>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 58. $PSTMPPS field description on PPS_IF_TIMING_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|fix_condition|Decimal, 1 digit|1 = NOFIX.<br>2 = 2DFIX.<br>3 = 3DFIX.|
|sat_th|Decimal|Minimum number of satellites for the PPS generation.|
|elevation_mask|Decimal|Minimum satellite elevation for satellite usage in timing<br>filtering.|
|constellation_mask|Decimal (bit mask)|Satellite constellation selection for usage in timing filtering.<br>bit0 = GPS<br>bit1 = GLONASS|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_POSITION_HOLD_DATA_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,13,<on_off>,<lat>,<lat_dir>,<lon>,<lon_dir>,<h_msl>*<checksum>
<cr><lf>
```

## **Arguments:** 

**Table 59. $PSTMPPS field description on PPS_IF_POSITION_HOLD_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|0 = Position Hold disabled.|



**UM2791** - **Rev 3** 

**page 65/241** 

**UM2791 ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||1 = Position Hold enabled.|
|lat|DDmm.mmmmm|Position Hold position latitude.|
|lat_dir|“N” or “S”|North or South direction.|
|lon|DDDmm.mmmmm|Position Hold position longitude.|
|lon_dir|“E” or “W”|East or West direction.|
|h_msl|Double|Position Hold mean see level altitude.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_AUTO_HOLD_SAMPLES_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,14,<auto_ph_samples>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 60. $PSTMPPS field description on PPS_IF_AUTO_HOLD_SAMPLES_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|auto_ph_samples|Decimal, 1 digit|Number of position samples for the auto position algorithm. If<br>the number of samples is set to “0” the auto position hold<br>feature is disabled.<br>The position average evaluation is restarted every time the<br>command is executed.|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **PPS Set PPS_IF_TRAIM_CMD** 

## **Synopsis:** 

```
$PSTMPPS,2,15,<on_off>,<alarm>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 61. $PSTMPPS field description on PPS_IF_TRAIM_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|0 = TRAIM disabled.<br>1 = TRAIM enabled.|
|alarm|Double|TRAIM alarm [s] – scientific notation is allowed|



## **Results:** 

- According to the operation mode and to the command type, data is set into the PPS manager or it is retrieved from the PPS manager. 

## **10.1.38 $PSTMLOWPOWERONOFF** 

Allow setting the low power algorithm parameters at run-time. 

**UM2791** - **Rev 3** 

**page 66/241** 

**UM2791 ST NMEA command specifications** 

## **Synopsis** : 

```
$PSTMLOWPOWERONOFF,<low power enable/disable>,<constellation mask>,
<EHPE threshold>,<Max tracked sats>,<Switch constellation features >,
<Duty Cycle enable/disable>,<Duty Cycle ms signal off>,<Periodic mode>,
<Fix period>,<Number of fix>,<Ephemeris refresh>,<RTC refresh>,
<No Fix timeout>,<No Fix timeout Off duration>*<checksum><cr><lf>
```

## **Synopsys to Disable low power mode:** 

```
$PSTMLOWPOWERONOFF,0,<constellation mask>*<checksum><cr><lf>
```

## **Synopsys to enable adaptive/cycling mode:** 

```
$PSTMLOWPOWERONOFF,1,<constellation mask>,<EHPE threshold>,
<Max tracked sats>,<Switch constellation features>,
<DutyCycle_enable/disable>,<Duty Cycle fix period>,
0,0,0,0,0,0,0*<checksum><cr><lf>
```

## **Synopsys to enable periodic mode** : 

```
$PSTMLOWPOWERONOFF,1,0,0,0,0,0,0,<Periodic mode>,<Fixperiod>,<Number of fix>,<Ephemeris
refresh>,<RTC refresh>,<No Fix timeout>,<No Fix timeout Off
duration>*<checksum><cr><lf>
```

**Arguments** : 

**Table 62. $PSTMLOWPOWERONOFF field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|low power enable/<br>disable|Decimal, 1 digit|General Low Power features Enable/Disable<br>0: OFF, 1: ON|
|**Adaptive mode settings**|||
|Constellation mask|Decimal, 1 digit|It is a bit mask where each bit enable/disable a specific<br>constellation independently by the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 2: QZSS constellation enabling/disabling<br>bit 3: GALILEO constellation enabling/disabling<br>bit 7: BEIDOU constellation enabling/disabling|
|EHPE threshold|Decimal, 3 digits|EHPE average threshold [m]|
|Max tracked sats|Decimal, 2 digits|first N satellites (with higher elevation) used for the position<br>calculation (<br>Active channel management) in LOW POWER<br>STATE|
|Switch constellation<br>features|Decimal, 1 digit|Switch constellation features (enable it only for GNSS<br>constellation case)|
|**Cyclic mode settings**|||
|Duty Cycle enable/<br>disable|Decimal, 1 digit|Duty Cycle features enable/disable|
|Duty Cycle ms signal<br>off|Decimal, 3 digits|Estimated Horizontal Position Error Average|
|**Periodic mode settings**|||
|Periodic mode|Decimal, 1 digit|Setup Active or Standby periodic mode<br>0: OFF|



**UM2791** - **Rev 3** 

**page 67/241** 

**UM2791 ST NMEA command specifications** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||3: Standby Periodic mode|
|FixPeriod|Decimal, 5 digits|Interval between two fixes [s]|
|FixOnTime|Decimal, 2 digits|Number of fixes reported for each interval|
|Ephemeris refresh|Decimal, 1 digit|Enable/Disable the refresh of ephemeris data<br>0: OFF, 1: ON|
|RTC calibration|Decimal, 1 digit|Enable/Disable the RTC calibration<br>0: OFF, 1: ON|
|NoFixCnt|Decimal, 2 digits|Time to declare fix loss [s] in HOT conditions|
|NoFixOff|Decimal, 2 digits|Period of off period after a fix loss [s]|



## **Results:** 

- In case of no errors, the $PSTMLOWPOWERON message is returned 

- In case of errors, the $PSTMLOWPOWERERROR error message is returned 

## **10.1.39** 

## **$PSTMSTANDBYENABLE** 

When the periodic mode is configured with PSTMLOWPOWERONOFF, this command allows/disallows the Teseo-Module to go in Standby mode between the fixes. 

## **Synopsis without argument:** 

```
$PSTMSTANDBYENABLE*<checksum><cr><lf>
```

## **Synopsis with argument** 

```
$PSTMSTANDBYENABLE,<on_off>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 63. $PSTMSTANDBYENABLE command field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Without parameter||Request the internal status|
|on_off|Decimal, 1 digits|Set the standby enable status<br>0: Active Periodic mode<br>1: Periodic mode, standby allowed|



## **Results without parameter:** 

- The $PSTMSTANDBYENABLE message is sent back to report the internal status 

## **Results with parameter:** 

- In case of no errors, the $PSTMSTANDBYENABLEOK message is returned 

- In case of errors, the $PSTMSTANDBYENABLEERROR error message is returned 

## **10.1.40** 

## **$PSTMFORCESTANDBY** 

Force the platform to go in standby mode. 

## **Synopsis:** 

```
$PSTMFORCESTANDBY,<duration>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 68/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 64. $PSTMFORCESTANDBY field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|duration|Decimal, 5 digits|Duration of the standby time in seconds:<br>•<br>zero means standby forever<br>•<br>65535 is max value|



## **Results:** 

- In case of no errors, the $PSTMFORCESTANDBYOK message is returned 

- In case of errors, the $PSTMFORCESTANDBYERROR error message is returned 

## **10.1.41** 

## **$PSTMNMEAREQUEST** 

Send a set of NMEA messages according to the input message list. 

## **Synopsis:** 

```
$PSTMNMEAREQUEST,<msglist_l>,<msglist_h>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 65. $PSTMNMEAREQUEST field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|msglist_l|Hexadecimal, 1 Digit|First 32 bits of 64 bits message list (low).<br>Each bit is used to enable/disable a specific message.<br>0 = disabled<br>1 = enabled|
|msglist_h|Hexadecimal, 1 Digit|Second 32 bits of 64 bits message list (high).<br>Each bit is used to enable/disable a specific message.<br>0 = disabled<br>1 = enabled|



## **Results:** 

- A set of NMEA messages is sent according to the input message list. 

_Note:_ 

## **10.1.42** 

_the order of NMEA messages in the message list is the same as for the periodic NMEA output messages._ 

## **$PSTMIONOPARAMS** 

Uploads a specific iono packet into the Teseo-Module NVM. The uploaded iono packet will be retained until a new iono packet for the same constellation is successfully uploaded or downloaded from the navigation message. **Synopsis: when sat_type = 0** 

```
$PSTMIONOPARAMS,<sat_type=0>,1,<A0>,<A1>,<A2>,<A3>,<B0>,<B1>,<B2>,<B3>*<checksum><cr><lf>
```

## **Synopsis: when sat_type = 1** 

```
$PSTMIONOPARAMS,<sat_type=1>,1,<ai0>,<ai1>,<ai2>,<Region1>,<Region2>,
<Region3>,<Region4>,<Region5>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 69/241** 

**UM2791 ST NMEA command specifications** 

## **Arguments:** 

**Table 66. $PSTMIONOPARAMS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_type|Decimal, 1 digits|1 is for GPS<br>3 is for Galileo<br>7 for BeiDou|
|A0,A1,A2,A3|Decimal, 3 digits|These parameters are used only if`sat_type=1 or 7`<br>Iono parameters, raw integer values as from Navigation<br>Messages.|
|B0,B1,B2,B3|Decimal, 3 digits|These parameters are used only if`sat_type=1 or 7`<br>Iono parameters, raw integer values as from Navigation<br>Messages.|
|ai0,ai1,ai2|Decimal, 3 digits|These parameters are used only if`sat_type=3`<br>Iono parameters, raw integer values as from Navigation<br>Messages.|
|Region1, Region2,<br>Region3 ,Region4,<br>Region5|Binary|These parameters are used only if`sat_type=3`<br>Galileo iono regions|



**Results:** None 

## **10.1.43 $PSTMGALILEOGGTO** 

This command programs the Galileo broadcast GGTO. 

## **Synopsis:** 

```
$PSTMGALILEOGGTO,<brd>,<WN0G>,<t0G>,<A0G>,<A1G>,<validity>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 67. $PSTMGALILEOGGTO field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|brd|Decimal, 1 digits|1=broadcast GGTO|
|WN0G|Decimal, 3 digits|Value for WN0G|
|t0G|Decimal, 5 digits|Value for t0G|
|A0G|Decimal, 5 digits|Value for A0G|
|A1G|Decimal, 5 digits|Value for A1G|
|validity|binary|0=not valid, 1=valid|



## **10.1.44** 

## **$PSTMGALILEODUMPGGTO** 

This command dumps the broadcast GGTO. 

## **Synopsis:** 

```
$PSTMGALILEODUMPGGTO*<checksum><cr><lf>
```

**Arguments:** 

None. **Results:** 

**UM2791** - **Rev 3** 

**page 70/241** 

**UM2791 ST NMEA command specifications** 

- If the command is executed the with $PSTMGALILEODUMPGGTO message is sent. 

## **10.1.45** 

## **$PSTMSETTHTRK** 

Configures the CN0 and Angle Elevation Mask thresholds for tracking. This command changes these parameters at run-time and no reset is required. In case of reset tracking CN0 and Angle Elevation Mask are restored to default value. 

## **Synopsis:** 

```
$PSTMSETTHTRK,<cn0>,<el>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 68. $PSTMCFGSETTHTRK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cn0|Decimal|Tracking CN0 threshold as dB|
|el|Double|Tracking elevation mask angle as degree|



## **Results:** 

- In case of no errors, the $PSTMSETTHTRKOK message is returned 

- In case of errors, the $PSTMSETTHTRKERROR error message is returned 

## **10.1.46 $PSTMSETTHPOS** 

Configures the CN0 and angle elevation mask thresholds for positioning. This command changes these parameters at run-time and no reset is required. In case of reset positioning CN0 and angle elevation mask are restored to default value. 

## **Synopsis:** 

```
$PSTMSETTHPOS,<cn0>,<el>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 69. $PSTMCFGSETTHPOS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cn0|Decimal|Positioning CN0 threshold as dB|
|el|Double|Positioning elevation mask angle as degree|



## **Results:** 

- In case of no errors, the $PSTMSETTHPOSOK message is returned 

- In case of errors, the $PSTMSETTHPOSERROR error message is returned 

## **10.1.47 $PSTMGETUCODE** 

This command reads the unique code from the secondary boot flash memory partition. 

## **Synopsis:** 

```
$PSTMGETUCODE*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

- In case of no error the $PSTMGETUCODEOK message is sent 

- In case of error the $PSTMGETUCODEERROR error message is sent 

**UM2791** - **Rev 3** 

**page 71/241** 

**UM2791 STM system configuration commands** 

## **10.2 STM system configuration commands** 

The Teseo-Module Software utilizes a “Configuration Data Block” that holds the working parameters for the system. The parameters can be set, read or store (in NVM) using the system configuration commands: $PSTMSETPAR, $PSTMGETPAR and $PSTMSAVEPAR. There is also a command to restore the factory setting parameters: $PSTMRESTOREPAR. 

At run-time it could be possible to have up to three different configuration blocks: 

- Current configuration: it is placed in RAM memory and it includes the current configuration of each parameter. This configuration block can be modified with the $PSTMSETPAR command. The $PSTMSAVEPAR command stores the current configuration data block into the NVM memory. At startup the current configuration block is loaded from NVM (if a stored data block is available) or it is loaded from default one embedded in the code (factory settings). 

- Default configuration: it is generally placed in the flash/rom memory. It includes the factory setting for each parameter. This configuration is used at system startup if there is no configuration data into the NVM memory. 

- NVM stored configuration: it is available in the NVM backup memory as soon as the $PSTMSAVEPAR command is executed. It includes all parameters modified and stored by the user. At system startup the SW configuration managements checks if a valid configuration block is available in the NVM backup memory. In case the stored configuration is available, it will be used for system configuration. If not available the default setting will be used. 

_Note:_ 

_Other “Configuration Data Block” parameters not documented in this manual must be considered as RESERVED and must not be modified. Modifying any other parameter intentionally or unintentionally may stop the system from working and/or degrade the system performance._ 

## **10.2.1 $PSTMSETPAR** 

This command sets the defined parameter (indicated by “ID”) to the value provided as “param_value” in the commands parameter. 

## **Synopsis:** 

```
$PSTMSETPAR,<ConfigBlock><ID>,<param_value>[,<mode>]*<checksum><cr><lf>
```

## **Arguments:** 

**Table 70. $PSTMSETPAR field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ConfigBlock|Decimal,1 digit|Indicates one of configuration blocks:<br>1 =Current Configuration,<br>2 = Default Configuration,<br>3 = NVM Stored configuration.|
|ID|Decimal, 3 digits|ID - Identifier|
|param_value|1 up to 80 bytes|Parameter to be set.|
|mode|Decimal, 1 digit|This parameter is optional. It allows to perform bit-to-bit “OR”<br>or “AND” operations between the selected parameter in the<br>configuration block and the param_value in input.<br>It has the following meaning:<br>0: the parameter in the configuration block is overwritten by<br>the param_value. This is the default action as in the case<br>mode is omitted.<br>1: the parameter in the configuration block is the result of bit-<br>to-bit “OR” between old value and the param_value.This is<br>useful for bit mask setting.<br>2: the parameter in the configuration block is the result of bit-<br>to-bit “AND” between old value and NOT(param_value). This<br>is useful for bit mask resetting.|



**UM2791** - **Rev 3** 

**page 72/241** 

**UM2791 STM system configuration commands** 

## **Results:** 

- In case of no errors, the $PSTMSETPAROK message is returned 

- In case of errors, the $PSTMSETPARERROR error message is returned 

## **Example:** 

Issuing the command: 

```
$PSTMSETPAR,1121,10*<checksum><cr><lf>
```

You could have this answer: 

```
$PSTMSETPAROK,1121*<checksum><cr><lf>
```

_Note:_ 

_The configuration block parameter is ignored by the “SET” command because only the current configuration, stored in the RAM memory, can be written. It is used only to keep same syntax as for the “GET” command. The configuration block stored in NVM will be overwritten by current configuration after the $PSTMSAVEPAR command._ 

_There is no comma and no space between ConfigBlock and ID parameters._ 

_The input param_value must be expressed in hexadecimal format without “0x” prefix for any integer value except DOP configuration. It must be decimal for any not integer value and DOP setting._ 

## **10.2.2 $PSTMGETPAR** 

This command reads the defined parameter (indicated by “ID”) from the “Configuration Data Block” and returns it as a specific message. 

## **Synopsis:** 

```
$PSTMGETPAR,<ConfigBlock><ID>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 71. $PSTMGETPAR field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ConfigBlock|Decima1, 1 digit|Indicates one of the configuration blocks:<br>1 = Current Configuration,<br>2 = Default Configuration,<br>3 = NVM Stored configuration.|
|ID|Decimal, 3 digits|ID - Identifier|



## **Results:** 

- In case of no errors, $PSTMSETPAR message is sent 

- In case of errors, the $PSTMGETPARERROR error message is returned 

## **Example:** 

Issuing the command: 

```
$PSTMGETPAR,1403*<checksum><cr><lf>
```

You could have this answer: 

```
$PSTMSET,1403,15,12,12,18*<checksum><cr><lf>
```

_Note:_ 

_There is no comma and no space between ConfigBlock and ID parameters._ 

_In case of no errors the answer is deliberately $PSTMSET and not $PSTMGET._ 

_If the parameter ID is “000” all the configuration block is printed out using one message for each parameter. The message syntax is the same as reported above._ 

**UM2791** - **Rev 3** 

**page 73/241** 

**UM2791 STM system configuration commands** 

## **10.2.3 $PSTMSAVEPAR** 

Save current configuration data block into the backup memory. 

## **Synopsis:** 

```
$PSTMSAVEPAR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The current configuration data block, including changed parameters, will be stored into the backup memory (NVM). 

- In case of no errors, the $PSTMSAVEPAROK message is returned 

- In case of errors, the $PSTMSAVEPARERROR error message is returned 

Note: the factory setting parameters can be restored using the $PSTMRESTOREPAR command. 

## **Example:** 

```
$PSTMSAVEPAR*<checksum><cr><lf>
```

## **10.2.4 $PSTMRESTOREPAR** 

Restore the factory setting parameters. The configuration data block stored in NVM, if present, will be invalidated. Any changed parameter will be lost. 

## **Synopsis:** 

```
$PSTMRESTOREPAR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- The factory setting parameters will be restored and the configuration block in the backup memory will be lost. A system reboot is needed to complete the factory reset restoring ad to get system working with default setting. 

- In case of no errors, the $PSTMRESTOREPAROK message is returned 

- In case of errors, the $PSTMRESTOREPARERROR error message is returned 

## **Example:** 

```
$PSTMRESTOREPAR*<checksum><cr><lf>
```

## **10.2.5 $PSTMCFGPORT** 

Configure a general-purpose port for NMEA, or RTCM purpose. 

## **Synopsis:** 

```
$PSTMCFGPORT,<port_type>,<protocol_type>,<par_1>,<par_2>,…,
<par_N>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 72. $PSTMCFGPORT field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|port_type|Decimal, 1 Digit|Select the port type:<br>0 = UART<br>1 = I2C|



**UM2791** - **Rev 3** 

**page 74/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|protocol_type|Decimal, 1 Digit|Select the protocol type:<br>0 = NMEA<br>1 = Reserved<br>2 = Reserved<br>3 = RTCM|
|par_1 … par_N|Integer|Parameters list according to the command type<br>Specification (see below).|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGPORTOK message is returned 

- In case of errors, the $PSTMCFGPORTERROR error message is returned 

## **10.2.6 $PSTMCFGPORT on UART** 

## **Arguments:** 

**Table 73. $PSTMCFGPORT field description when port_type is UART** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|portnumb|From 0 to 255|UART ID (Linearly addressed)|
|baudrate|Integer|The port baud rate. Allowed values are:<br>300,<br>600,<br>1200,<br>2400,<br>4800,<br>9600,<br>14400,<br>19200,<br>38400,<br>57600,<br>115200,<br>230400,<br>460800,<br>921600|



## **10.2.7 $PSTMCFGPORT on I2C** 

## **Arguments:** 

**Table 74. $PSTMCFGPORT field description when port_type is I2C** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|slaveaddr|Hexadecimal, 2Bytes|The I2C slave address|
|mode|Decimal, 1 digit|Reserved|



**UM2791** - **Rev 3** 

**page 75/241** 

**UM2791 STM system configuration commands** 

## **10.2.8 $PSTMCFGMSGL** 

Configure the message list. 

## **Synopsis:** 

```
$PSTMCFGMSGL,<listid>,<rate>,<listlow>,<listhigh>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 75. $PSTMCFGMSGL field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|listid|Decimal, 1 digit|List selector:<br>0 = NMEA list on UART port<br>3 = NMEA on I2C port|
|rate|From 0 to 255|Message list rate scaler|
|listlow|Hexadecimal, 8 digits|Please refer to CDB 201 table in case of NMEA or 240 in<br>case of STBin|
|listhigh|Hexadecimal, 8 digits|Please refer to CDB 228 table in case of NMEA or 241 in<br>case of STBin|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGMSGLOK message is returned 

- In case of errors, the $PSTMCFGMSGLERROR error message is returned 

## **10.2.9 $PSTMCFGGNSS** 

Configure the GNSS parameters algorithm. 

## **Synopsis:** 

```
$PSTMCFGGNSS,<trkcn0>,<poscn0>,<trkmskang>,<posmskang>,
<NCOcntr>,<NCOmin>,<NCOmax>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 76. $PSTMCFGGNSS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|trkcn0|From 0 to 255|Minimum CN0 [dB] at which satellite can be tracked|
|poscn0|From 0 to 255|Minimum CN0 [dB] at which satellite can be tracked for<br>positioning solution|
|trkmskang|From 0 to 255|Minimum elevation angle at which satellite can be tracked|
|posmskang|From 0 to 255|Minimum elevation angle at which satellite can be tracked for<br>positioning solution|
|NCOcntr|From 0 to 255|NCO center value|
|NCOmin|From 0 to 255|NCO range minimum value|
|NCOmax|From 0 to 255|NCO range maximum value|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGGNSSOK message is returned 

**UM2791** - **Rev 3** 

**page 76/241** 

**UM2791 STM system configuration commands** 

- In case of errors, the $PSTMCFGGNSSERROR error message is returned 

## **10.2.10 $PSTMCFGSBAS** 

Configure the SBAS algorithm. 

## **Synopsis:** 

```
$PSTMCFGSBAS,<enengine>,<enreport>,<enautosearch>,<numofsats>,<sat_1prnid>,
<sat_1long>,<sat_1longsens>,<sat_1sbasserv>,<sat_1default>,…,>,<sat_Mprnid>,<sat_Mlong>,
<sat_Mlongsens>,<sat_Msbasserv>,<sat_Mdefault>,<par_1>,<par_2>,…,<par_N>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 77. $PSTMCFGSBAS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|enengine|Decimal, 1 digit|Enable SBAS engine switch:<br>0 = Disabled<br>1 = Enabled|
|enreport|Decimal, 1 digit|Enable satellite report in GSV message:<br>0 = Disabled<br>1 = Enabled|
|enautosearch|Decimal, 1 digit|Enable autosearch switch:<br>0 = Disabled<br>1 = Enabled|
|autosearchmask|Hexadecimal, 8 digits|Allow enabling/disabling the SBAS satellites to be searched<br>by the auto search procedure|
|dectimeout|From 0 to 255|The time the autosearch waits to try to decode the current<br>PRN<br>Note: expressed in seconds. This value is ignored if<br>`enautosearch`is 0|
|diftimeout|From 0 to 255|The time the autosearch waits<br>before to change the prn when the current SBAS sat is not<br>more<br>decoded<br>Note: expressed in seconds. This value is ignored if<br>`enautosearch`is 0|
|nextsattimeout|From 0 to 255|The time the autosearch waits to try to acquire and tracking<br>new SBAS satellite using the searching channel<br>Note: expressed in seconds. This value is ignored if<br>`enautosearch`is 0|
|nextsesstimeout|From 0 to 255|The time the autosearch waits before to start a new<br>searching session using the searching channel<br>Note: expressed in seconds. This value is ignored if<br>`enautosearch`is 0|
|numofsats (N)|From 0 to 255|Number of SBAS satellites.<br>Note that following configuration settings will be repeated<br>“numofsat” times|
|satN_prnid|Integer|SBAS PRN configuration for satellite 1|
|satN_long|From 0 to 255|Longitude for satellite 1|
|satN_longsens|Decimal, 1 digit|Longitude sense for satellite 1|



**UM2791** - **Rev 3** 

**page 77/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||0 = EAST<br>1 = WEST|
|satN_sbasserv|Decimal, 1 digit|SBAS service for satellite 1<br>0 = WAAS<br>1 = EGNOS<br>2 = MSAS<br>3 = GAGAN|
|satN_default|Decimal, 1 digit|Select if satellite 1 is default or not<br>0 = Not default<br>1 = Default|



_Note:_ 

_Last five parameters will be repeated N times, where N is the number of satellites user has chosen._ 

## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGSBASOK message is returned 

- In case of errors, the $PSTMCFGSBASERROR error message is returned 

Parameters when auto-search is enabled. 

**Table 78.  $PSTMCFGSBAS field description when auto-search is enabled** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Satellite-Enable-<br>mask|Integer|Enable/disable satellites to be searched by the autosearch<br>procedure.|
|Autosearch-<br>decoding-timeout|Integer|Set the timeout the autosearch waits to try to decode the<br>current PRN|
|Autosearch-<br>differentialtimeout|Integer|Set the timeout the autosearch waits<br>before to change the PRN when the current<br>SBAS satellite is no more decoded|
|Autosearch-searching-<br>timeout-next-satellite|Integer|Set the timeout the auto-search waits to try to acquire and<br>tracking new SBAS<br>satellite using the searching channel|
|Autosearch-searching-<br>timeout-next-session|Integer|Set the timeout the auto-search waits<br>before to start a new searching session<br>using the searching channel|



## **10.2.11 $PSTMCFGPPSGEN** 

Configure the PPS with general settings. 

## **Synopsis:** 

```
$PSTMCFGPPSGEN,<enpps>,<genmode>,<ppsclock>,<reftime>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 78/241** 

**UM2791 STM system configuration commands** 

## **Arguments:** 

**Table 79. $PSTMCFGPPSGEN field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|enpps|Decimal, 1 digit|Enable PPS engine switch<br>0 = Disabled<br>1 = Enabled|
|genmode|Decimal, 1 digit|Generation mode<br>0 = Every second<br>1 = Even seconds<br>2 = Odd seconds|
|ppsclock|Decimal, 1 digit|PPS clock<br>0 = 16 MHz<br>1 = 32 MHz<br>2 = 64 MHz|
|reftime|Decimal, 1 digit|Reference time<br>0 = UTC<br>1 = GPS time<br>2 = GLONASS time<br>3 = UTC (SU)<br>4 = GPS time from GLONASS time reference|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGPPSGENOK message is returned 

- In case of errors, the $PSTMCFGPPSGENERROR error message is returned 

## **10.2.12** 

## **$PSTMCFGPPSSAT** 

Configure the PPS with satellite related configurations settings. 

## **Synopsis:** 

```
$PSTMCFGPPSSAT,<enmix>,<fixcond>,<minsatnum>,<satelevmask>*<checksum><cr>
<lf>
```

## **Arguments:** 

**Table 80. $$PSTMCFGPPSSAT field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|enmix|Decimal, 1 digit|Enable Mixing<br>0 = Disabled<br>1 = GPS satellite enabled for GLONASS correction<br>2 = GLONASS satellite enabled for GPS correction|
|fixcond|Decimal, 1 digit|Fix condition<br>0 = No fix<br>1 = 2D fix|



**UM2791** - **Rev 3** 

**page 79/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||2 = 3D fix|
|minsatnum|From 0 to 255|Minimum number of satellites used for timing correction|
|satelevmask|From 0 to 255|Satellite elevation mask for time correction. It is the minimum<br>satellite elevation angle to use the satellite for time<br>correction|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGPPSSATOK message is returned 

- In case of errors, the $PSTMCFGPPSSATERROR error message is returned 

## **10.2.13 $PSTMCFGPPSPUL** 

Configure the PPS with pulse related settings. 

## **Synopsis:** 

```
$PSTMCFGPPSPUL,<enpolinv>,<pulsedur>,<delcorr>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 81. $PSTMCFGPPSPUL field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|enpolinv|Decimal, 1 digit|Enable polarity inversion switch<br>0 = Disabled<br>1 = Enabled|
|pulsedur|Double|Allow setting the pulse duration of the PPS signal|
|delcorr|Double|Allow setting a time correction to<br>compensate any delay introduced on the<br>Pulse Per Second (PPS) signal by cables and/or RF chain|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGPPSPULOK message is returned 

- In case of errors, the $PSTMCFGPPSPULERROR error message is returned 

## **10.2.14** 

## **$PSTMCFGPOSHOLD** 

Configure the position hold. 

## **Synopsis:** 

```
$PSTMCFGPOSHOLD,<poshold>,<poshlat>,<poshlon>,<poshhei>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 82. $PSTMCFGPOSHOLD field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|poshold|Decimal, 1 digit|Enable position hold switch<br>0 = Disabled|



**UM2791** - **Rev 3** 

**page 80/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||1 = Enabled<br>Next parameter will be ignored when poshold is Disabled.|
|poshlat|Double|Set the position hold latitude|
|poshlon|Double|Set the position hold longitude|
|poshhei|Double|Set the position hold height|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGPOSHOLDOK message is returned 

## **10.2.15** 

## **$PSTMCFGTRAIM** 

Configure the PPS with general settings. 

## **Synopsis:** 

```
$PSTMCFGTRAIM,<entraim>,<threshold>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 83. $PSTMCFGTRAIM field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|entraim|Decimal, 1 digit|Enable TRAIM switch<br>0 = Disabled<br>1 = Enabled|
|threshold|Double|Time error threshold for the satellites<br>exclusion in the TRAIM algorithm|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGTRAIMOK message is returned 

## **10.2.16** 

## **$PSTMCFGSATCOMP** 

Configure the PPS with general settings. 

## **Synopsis:** 

```
$PSTMCFGSATCOMP,<numofcomp>,<pathid1>,<comp1>,<pathid2>,<comp2>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 84. $PSTMCFGSATCOMP field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|numofcomp|Decimal|Number of RF path to compensate. Note that this affect next<br>parameters.<br>Next fields will be repeated “numofcomp” times|
|pathid|Decimal,1 Digit|Select the ID of the RF path to compensate<br>0 = GPS|



**UM2791** - **Rev 3** 

**page 81/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||1 = GLONASS|
|comp|Double|Time compensation value|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGSATCOMPOK message is returned 

- In case of errors, the $PSTMCFGSATCOMERROR error message is returned 

## **10.2.17 $PSTMCFGLPA** 

Configure the low power algorithm. 

## **Synopsis:** 

```
$PSTMCFGLPA,<en_lpa>,<feat>,<fix_period>,<fix_on_time>,<no_fix_cnt>,
<no_fix_cnt2>,<no_fix_off>,<adaptive_feat>,<adaptive_duty_cicle>,<ehpe_th>,<num_of_sat>,
<duty_off>,<const_type>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 85. $PSTMCFGLPA field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|en_lpa|unsigned, 1 bytes|Enable Low Power Algorithm<br>0 = LPA Disabled<br>1 = LPA Enabled.|
|feat|unsigned, 1 bytes|Low Power Algorithm feature<br>0 = Periodic mode disabled<br>1 = Active Periodic mode<br>2 = RESERVED<br>3 = Standby Periodic mode|
|fix_period|From 0 to 86400|Fix period in seconds. 0 means the Fix will be given only on<br>WAKEUP pin activation. Value 0 is only valid in Standby<br>Periodic mode.<br>Default is 10.|
|fix_on_time|unsigned, 2 bytes|Number of fix reported every Fix wakeup.<br>Default is 1|
|no_fix_cnt|unsigned, 2 bytes|Number of no-fixes in hot conditions, before to signal a fix<br>loss event.<br>Default is 8|
|no_fix_cnt2|unsigned, 2 bytes|Number of no-fixes in non-hot conditions, before to signal a<br>fix loss event.<br>Default is 60|
|no_fix_off|unsigned, 2 bytes|Off duration time after a fix loss event.<br>Default is 180|
|adaptive_feat|unsigned, 1 bytes|Enable disable adaptive multi-constellation algorithm.<br>0 = Adaptive Algorithm Disabled<br>1 = Adaptive Algorithm Enabled|



**UM2791** - **Rev 3** 

**page 82/241** 

**UM2791 STM system configuration commands** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||Default is 0|
|adaptive_duty_cicle|unsigned, 1 bytes|Enable disable trimming of correlation time for each cycle.<br>0 = Adaptive Duty Cycle Disabled<br>1 = Adaptive Duty Cycle Enabled<br>Default is 0|
|ehpe_th|unsigned, 1 bytes|EHPE average threshold.<br>Default is 15|
|num_of_sat|unsigned, 1 bytes<br>0 to 32|Number of satellite used in Adaptive mode (first N with<br>higher elevation)<br>Default is 9|
|duty_off|unsigned, 2 bytes<br>100 to 740|Duty cycle OFF period length in ms;<br>Default is 700|
|const_type|unsigned, 1 bytes|RESERVED, set it as 0|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGLPAOK message is returned 

- In case of errors, the $PSTMCFGLPAERROR error message is returned 

## **10.2.18** 

## **$PSTMCFGAGPS** 

Configure the assisted GNSS. 

## **Synopsis:** 

```
$PSTMCFGAGPS,<en_agps>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 86. $PSTMCFGAGPS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|en_agps|Decimal|Enable/Disable AGNSS engine<br>0 = AGNSS Disables<br>1 = AGNSS Enabled|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGAGPSOK message is returned 

## **10.2.19** 

## **$PSTMCFGAJM** 

Configure the Anti-Jamming algorithm. 

## **Synopsis:** 

```
$PSTMCFGAJM,<gpsmode>,<glonassmode>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 83/241** 

**UM2791 STM system configuration commands** 

## **Arguments:** 

**Table 87. $PSTMCFGAJM field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|gpsmode|Decimal, 1 digit|Notch filter on GPS path:<br>0 = Disabled<br>1 = Normal Mode<br>2 = Auto Mode|
|glonassmode|Decimal, 1 digit|Notch filter on GLONASS path:<br>0 = Disabled<br>1 = Normal Mode<br>2 = Auto Mode|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGAJMOK message is returned 

- In case of errors, the $PSTMCFGAJMERROR error message is returned 

## **10.2.20** 

## **$PSTMCFGODO** 

Configure the odometer. 

## **Synopsis:** 

```
$PSTMCFGODO,<en>,<enmsg>,<alarm>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 88. $PSTMCFGODO field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|en|Decimal, 1 digit|Enable/Disable the odometer:<br>0 = Odometer disabled<br>1 = Odometer enabled|
|enmsg|Decimal, 1 digit|Enable/Disable odometer related periodic messages:<br>0 = Periodic message disabled<br>1 = Periodic message enabled|
|alarm|0 to 65535|Distance travelled between two NMEA messages|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGODOOK message is returned 

- In case of errors, the $PSTMCFGODOERROR error message is returned 

## **10.2.21** 

## **$PSTMCFGGEOFENCE** 

Allows to configure Geofencing feature enabling circles and choosing tolerance. 

## **Synopsis:** 

```
$PSTMCFGGEOFENCE,<en>,<tol>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 84/241** 

**UM2791 STM system configuration commands** 

## **Arguments:** 

**Table 89. $PSTMCFGGEOFENCE field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|en|Decimal, 1 digit|Enable/Disable the geo fencing:<br>0 = Geo fencing disabled<br>1 = Geo fencing enabled|
|tol|Decimal, 1 digit|Tolerance:<br>0 = none<br>1 = level 1<br>2 = level 2<br>3 = level 3|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGGEOFENCEOK message is returned 

- In case of errors, the $PSTMCFGGEOFENCEERROR error message is returned 

## **10.2.22** 

## **$PSTMCFGGEOCIR** 

Allows to configure a circle of geofencing feature. 

## **Synopsis:** 

```
$PSTMCFGGEOCIR,<circleid>,<en>,<lat>,<lon>,<rad>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 90. $PSTMCFGGEOCIR field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|circleid|Decimal, 1 digit|The circle ID<br>From 0 to 7|
|en|Boolean|Enable disable the circle<br>0 = Disable,<br>1 = Enable|
|lat|Double|N-th circle latitude|
|lon|Double|N-th circle longitude|
|rad|Double|N-th circle radius|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters. In case of no errors, the following message is returned 

- In case of no errors, the $PSTMCFGGEOCIROK message is returned 

- In case of errors, the $PSTMCFGGEOCIRERROR error message is returned 

## **10.2.23** 

## **$PSTMCFGCONST** 

Allow enable/disable all the GNSS constellations. 

**UM2791** - **Rev 3** 

**page 85/241** 

**UM2791 STM system configuration commands** 

## **Synopsis:** 

```
$PSTMCFGCONST,<gps>,<glonass>,<galileo>,<qzss>,<beidou<*<checksumn><cr><lf>
```

## **Arguments:** 

**Table 91. $PSTMCFGCONST field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Gps|Decimal, 1 digit|Allowed values:<br>1.<br>Constellation disabled<br>2.<br>Constellation satellites only tracked<br>3.<br>Satellites constellation used in position evaluation|
|Gloanss|Decimal, 1 digit|Allowed values:<br>1.<br>Constellation disabled<br>2.<br>Constellation satellites only tracked<br>3.<br>Satellites constellation used in position evaluation|
|Galileo|Decimal, 1 digit|Allowed values:<br>1.<br>Constellation disabled<br>2.<br>Constellation satellites only tracked<br>3.<br>Satellites constellation used in position evaluation|
|Qzss|Decimal, 1 digit|Allowed values:<br>1.<br>Constellation disabled<br>2.<br>Constellation satellites only tracked<br>3.<br>Satellites constellation used in position evaluation|
|Beidou|Decimal, 1 digit|Allowed values:<br>1.<br>Constellation disabled<br>2.<br>Constellation satellites only tracked<br>3.<br>Satellites constellation used in position evaluation|



## **Results:** 

- One or more parameters of swconfig are set according to the command parameters 

- In case of no errors, the $PSTMCFGCONSTOK message is returned 

- In case of errors, the $PSTMCFGCONSTERROR error message is returned 

## **10.2.24 $PSTMCFGTHGNSS** 

Configures threshold related to GNSS algorithm. 

## **Synopsis** : 

```
$PSTMCFGTHGNSS,<trkcn0>,<poscn0>,<trkmaskangle>,<posmaskangle>*<checksum><cr><lf>
```

**Arguments** : 

**Table 92. $PSTMCFGTHGNSS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|trkcn0|Unsigned|Minimum CN0 for tracking purposes|
|poscn0|Unsigned|Minimum CN0 for positioning purposes|
|trkmaskangle|Unsigned|Minimum angle for tracking purposes|
|posmaskangle|Unsigned|Minimum angle for positioning purposes|



**Results** : 

**UM2791** - **Rev 3** 

**page 86/241** 

**UM2791 Autonomous AGNSS NMEA commands** 

- If the command syntax is correct and parameter are correctly set the device return the following confirmation $PSTMCFGTHGNSSOK message: 

- In case of errors, the $PSTMCFGTHGNSSERROR error message is returned 

## **10.2.25 $PSTMCFGTDATA** 

Configures data and time related parameters. 

## **Synopsis** : 

```
$PSTMCFGTDATA,<gpsminweek>,<gps_max_week>,<fix_rate>,<utcdelta>*<checksum><cr><lf>
```

## **Arguments** : 

**Table 93. $PSTMCFGTDATA field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|trkcn0|Unsigned|Minimum CN0 for tracking purposes|
|poscn0|Unsigned|Minimum CN0 for positioning purposes|
|trkmaskangle|Unsigned|Minimum angle for tracking purposes|
|posmaskangle|Unsigned|Minimum angle for positioning purposes|



## **Results** : 

- If the command syntax is correct and parameter are correctly set the device return the $PSTMCFGTDATAOK confirmation message 

- In case of errors, the $PSTMCFGTDATAERROR error message is returned 

## **10.3 Autonomous AGNSS NMEA commands** 

## **10.3.1 $PSTMSTAGPSONOFF** 

The command turns ON/OFF the ST-AGNSS engine; it affects both autonomous and server based solutions. **Synopsis:** 

```
$PSTMSTAGPSONOFF,<param>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 94. $PSTMSTAGPSPONOFF field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|param|Decimal, 1 digits|ON/OFF status :<br>0: the ST-AGNSS engine is suspended.<br>1: the ST-AGNSS engine is started|



## **Results:** 

According to the command parameter, the ST-AGNSS engine is started or suspended. One of the following messages is sent: 

- $PSTMPOLSTARTED if the engine has been started ; 

- $PSTMPOLSUSPENDED if the engine has been suspended; 

- $PSTMPOLONOFFERROR in case of error 

**UM2791** - **Rev 3** 

**page 87/241** 

**UM2791 Autonomous AGNSS NMEA commands** 

## **10.3.2 $PSTMSTAGPSINVALIDATE** 

The command clears data stored in the ST-AGNSS internal database. The input parameter allows selection of data to be cleared. 

## **Synopsis:** 

```
$PSTMSTAGPSINVALIDATE,<param>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 95. $PSTMSTAGPSINVALIDATE field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|param|Decimal, 1 digits|Selects which database should be erased:<br>1: Clear the real ephemeris database (only autonomous).<br>2: Clear the satellite seeds database (autonomous and<br>server based)<br>4: Clear the satellite polys database (autonomous and server<br>based)<br>7: Clear all databases|



## **Results:** 

According to the command parameter, the internal ST-AGNSS databases will be erased. 

The input parameter should be considered as a mask where the first three bits select the database to be cleared (e.g. using 3 as input parameter the real ephemeris and seed databases will be cleared). 

At the end of operation ST-AGNSS subsystem sends the message end of a successful invalidation process the message: 

- $PSTMSTAGPSINVALIDATEOK in case of successful; 

- $PSTMSTAGPSINVALIDATEERROR in case of errors; 

## **10.3.3 $PSTMGETAGPSSTATUS** 

The command returns the status of the ST-AGNSS internal processing. 

## **Synopsis:** 

```
$PSTMGETAGPSSTATUS*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

- The system sends back the ST-AGNSS status in the $PSTMAGPSSTATUS message. 

## **10.3.4 $PSTMSTAGPSSETCONSTMASK** 

The command sets the ST-AGNSS constellation mask. It allows switching the ST-AGNSS constellation at runtime. All previous ST-AGNSS data will be erased 

## **Synopsis:** 

```
$PSTMSTAGPSSETCONSTMASK,<constellation_mask>*<checksum><cr><lf>
```

## **Arguments:** 

**UM2791** - **Rev 3** 

**page 88/241** 

**UM2791 Real Time AGNSS NMEA commands** 

**Table 96. $PSTMSTAGPSSETCONSTMASK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Constellation_mask|Decimal, 3 digits|It is a bit mask where each bit enable/disable a specific<br>constellation independently by the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 3: GALILEO constellation enabling/disabling<br>bit 7: BEIDOU constellation enabling/disabling|



## **Results:** 

According to the command parameter one of the following messages is sent: 

   - $PSTMSTAGPSSETCONSTMASKOK in case of success; 

   - $PSTMSTAGPSSETCONSTMASKERROR in case of error; 

- _Note: GALILEO and BEIDOU support is still experimental and should not be used in production environment._ 

## **10.4 Real Time AGNSS NMEA commands** 

## **10.4.1 $PSTMSTAGPS8PASSGEN** 

Request the generation of a password to access the Real-Time AGNSS server to the device. 

## **Synopsis:** 

```
$PSTMSTAGPS8PASSGEN,<time>,<Vendor_ID>,<Dev_id>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 97. $PSTMSTAGPS8PASSGEN field description** 

|**Parameter**|**Description**|
|---|---|
|_<time>_|GPS time in seconds.|
|_<Vendor_ID>_|Unique Vendor ID|
|_<Dev_ID>_|Unique Device ID|



## **Results:** 

- Teseo-Module returns the password in the message $PSTMSTAGPS8PASSRTN 

## **10.5 Dead Reckoning NMEA Commands** 

## **10.5.1 $PSTMDRMMFB** 

Input Map Match Data. 

If Map Matching is used, host has to send this command each second. If for some reason MMFB data are believed to be unreliable, the command has to be sent anyway with its validity flags set to zero. 

NMEA message list bitmask (64 bits): 0200 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRMMFB,<time_stamp>,<lat_val>,<lon_val>,<height_val>,<heading_val>,<lat>,<lon>,<height>,
<heading>,<lat_err>,<lon_err>,<height_err>,<heading_err>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 89/241** 

**UM2791 Dead Reckoning NMEA Commands** 

## **Arguments:** 

**Table 98. $PSTMDRMMFB command field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|time_stamp|hhmmss.sss|UTC Time of map matched position.<br>•<br>hh hours<br>•<br>mm minutes<br>•<br>ss seconds<br>•<br>.sss fraction of seconds|
|lat_val|Decimal, 1 digit|Latitude validity flag:<br>•<br>1 Valid<br>•<br>0 Not valid|
|lon_val|Decimal, 1 digit|Longitude validity flag:<br>•<br>1 Valid<br>•<br>0 Not valid|
|height_val|Decimal, 1 digit|Height validity flag:<br>•<br>1 Valid<br>•<br>0 Not valid|
|heading_val|Decimal, 1 digit|Heading validity flag:<br>•<br>1 Valid<br>•<br>0 Not valid|
|lat|Double, 7 fractional digits|Latitude in signed decimal degrees|
|lon|Double, 7 fractional digits|Longitude in signed decimal degrees|
|height|Double, 1 fractional digit|Height in m|
|heading|Double, 1 fractional digit|Heading in signed decimal degrees [0,360]|
|lat_err|Double, 1 fractional digit|Latitude error (accuracy) in m|
|lon_err|Double, 1 fractional digit|Longitude error (accuracy) in m|
|height_err|Double, 1 fractional digit|Height error (accuracy) in m|
|heading_err|Double, 1 fractional digit|Heading error (accuracy )in signed decimal degrees|



## **Results:** 

- A MMFB data will be injected into Dead Reckoning process engine 

- If successful (command format is accepted) the Teseo-Module responds with a message $PSTMDRMMFBKF 

## **Example:** 

```
$PSTMDRMMFB,160836.000,1,1,1,1,45.4567890,9.4567890,180.5,90.0,10.1,10.2,4.7,0.3*
```

## **10.5.2 $PSTMDRCALCTLT** 

Start the tilt installation angles procedure. The procedure is effective only in case of no accelerometer is available. **Synopsis:** 

```
$PSTMDRCALCTLT*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

- if successful the message $PSTMDRCALCTLTOK is sent: 

- in case of $PSTMDRCALCTLTERROR error the message is sent: 

**UM2791** - **Rev 3** 

**page 90/241** 

**UM2791** 

**Dead Reckoning NMEA Commands** 

## **10.5.3 $PSTMDRNVMSAVE** 

Save the Dead Reckoning Status in NVM When the DRAW Status is saved, $PSTMDRNVM_WRITE occurs. 

## **Synopsis:** 

```
$PSTMDRNVMSAVE*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

- if successful the $PSTMDRNVMSAVEOK message is sent 

- in case of error the $PSTMDRNVMSAVEERROR error message is sent 

**UM2791** - **Rev 3** 

**page 91/241** 

**UM2791 Messages** 

## **11 Messages** 

This section contains both the standard NMEA messages and the proprietary messages delivered from TeseoModule. Additionally, it contains messages which result from a specific command input. 

## **11.1** 

## **Standard NMEA messages list** 

The type and number of messages outputted by receiver is completely configurable through dedicated CDBs. The complete list of messages is defined by 64 bits, divided in two CDBs. First 32 bits [0-31] are defined as low section of the list; the following ones [32-63] are defined as high section of the list. For each bit, 0 means that correspondent message is disabled in NMEA out, 1 means that it is enabled. The complete matching between bit number and message is provided by the following tables. 

For each port, three different message lists exist, and user can configure them acting on specific data blocks. Depending on required navigation rate one or more of them must be configured in order to indicate which messages are delivered in output and at which rate. Table below reports a summary of available, messages list, their purpose and related CDBs. 

**Table 99. UART- message-list** 

|**List-ID**|**Purpose**|**CDB Low [bits 0-31]**|**CDB High [bits 32-63]**|
|---|---|---|---|
|0|Defines Messages to be sent at low rate (1 Hz)|201|228|
|1|Defines Messages to be sent at high rate (> 1 Hz)|210|229|
|2|Defines Messages to be sent at high rate and low latency (> 1 Hz)|211|230|



**Table 100. I2C- message-list** 

|**List-ID**|**Purpose**|**CDB Low [bits 0-31]**|**CDB High [bits 32-63]**|
|---|---|---|---|
|0|Defines Messages to be sent at low rate (1 Hz)|231|232|
|1|Defines Messages to be sent at high rate (> 1 Hz)|233|234|
|2|Defines Messages to be sent at high rate and low latency (> 1 Hz)|235|236|



## **11.2 ST NMEA messages list** 

**Table 101. ST NMEA messages list** 

|**Syntax**|**Default**|**Description**|
|---|---|---|
|$PSTMDIFF|OFF|ST: Differential Correction Data|
|$PSTMPRES|OFF|ST: Position Residuals|
|$PSTMVRES|OFF|ST: Velocity Residuals|
|$PSTMPA|OFF|ST: Position Algorithm|
|$PSTMRF|OFF|ST: Radio Frequency|
|$PSTMSAT|OFF|ST: Satellite Information|
|$PSTMSBAS|ON|ST: Augmentation System|
|PSTMSBASM|OFF|ST; Augmentation System Message|
|$PSTMTIM|OFF|ST: System Time|
|$PSTMTG|OFF|ST: Time and Number of used Satellites|



**UM2791** - **Rev 3** 

**page 92/241** 

**UM2791 Changing standard NMEA messages format** 

|**Syntax**|**Default**|**Description**|
|---|---|---|
|$PSTMTS|OFF|ST: Tracked Satellite Data|
|$PSTMKFCOV|OFF|ST: Standard Deviation and Covariance|
|$PSTMAGPS`[1]`|OFF|ST: STAGPS predicted ephemeris information|
|$PSTMNOTCHSTATUS|OFF|ST: Reports the Notch filter status.|
|$PSTMCPU|ON|ST: Reports the CPU usage and CPU speed setting.|
|$PSTMPOSNHOLD|OFF|ST: Reports the status and position of Position Hold.|
|$PSTMPPSDATA|OFF|ST: Reports the Pulse Per Second data.|
|$PSTMTRAIMSTATUS|OFF|ST: Reports the TRAIM status data.|
|$PSTMTRAIMUSED|OFF|ST: Reports the satellites used for timing correction.|
|$PSTMTRAIMRES|OFF|ST: Reports the residuals for used satellites.|
|$PSTMTRAIMREMOVED|OFF|ST: Reports the satellites removed by timing correction algorithm.|
|$PSTMLOWPOWERDATA|OFF|ST: Reports the status of low power algorithm|
|$PSTMGALILEOGGTO|OFF|ST: Reports the Galileo broadcast GGTO|



## **11.3 Changing standard NMEA messages format** 

By default, Standard NMEA Messages are compliant with the “NMEA 0183” Standard Rev. 3.1 dated January 2002. To change format to Rev. 4.10, issued from the “National Marine Electronics Association” in the August 2012 some system configuration commands should be issued. 

It is required to change the value of Configuration Data Block 122 from the default value to “4”. 

```
$PSTMSETPAR,1122,4
$PSTMSAVEPAR
$PSTMSRR
```

It is possible to go back to default configuration restoring parameters or setting CDB 122 as 0xC 

```
$PSTMSETPAR,1122,C
$PSTMSAVEPAR
$PSTMSRR
```

## **11.4 Preliminary notes about satellites’ PRN ranges** 

The satellite PRN is an ID used to identify satellites. In NMEA 0183 Rev 3.1, PRN was not described for new constellation. Starting from Rev 4.10 more constraint about this info have been added. Thus, PRN ranges depends on NMEA revision in use. 

**Table 102. Satellite PRNs for each NMEA version** 

||**GPS**|**SBAS**|**GLONASS**|**BAIDEU**|**QZSS**|**GALILEO**|
|---|---|---|---|---|---|---|
|NMEA 3.10|from 1 to 32|from 33 to 51|from 65 to 92|from 141 to 172|from 183 to 197|from 301 to 330|
|NMEA 4.10|from 1 to 32|from 33 to 64|from 65 to 99|from 1 to 32|from 1 to 32|from 1 to 36|



## **11.5 Standard NMEA messages specification** 

## **11.5.1 $--GGA** 

Global Positioning System Fixed data 

NMEA message list bitmask (64 bits): 0000 0000 0000 0002 

**UM2791** - **Rev 3** 

**page 93/241** 

**UM2791 Standard NMEA messages specification** 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGGA,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<GPSQual>,<Sats>,<HDOP>,
<Alt>,<AltVal>,<GeoSep>,<GeoVal>,<DGPSAge>,<DGPSRef>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>GGA,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<GPSQual>,
<Sats>,<HDOP>,<Alt>,<AltVal>,<GeoSep>,<GeoVal>,<DGPSAge>,<DGPSRef>*
<checksum><cr><lf>
```

## **Arguments:** 

**Table 103. $--GGA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than 1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Lat|DDMM.MMMMM|Latitude as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|N/S|“N” or “S”|Latitude direction: North or South<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Long|DDMM.MMMMM|Longitude as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|E/W|“E” or “W”|Longitude direction: East or West<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|GPSQual|Decimal, 1digit|0 = Fix not available or invalid<br>1 = GPS, SPS Mode, fix valid<br>2 = Differential GPS, SPS Mode, fix valid<br>6 = Estimated (dead reckoning) mode|



**UM2791** - **Rev 3** 

**page 94/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Sats|Decimal, 2 digits|Satellites in use: example: 8|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, max: 99.0|
|Alt|Decimal, 6 digits|Height above mean sea level, max: 100000m|
|AltVal|“M”|Reference Unit for Altitude (“M” = meters)|
|GeoSep|Decimal, 4 digits|Geoidal Separation measure in “M” = meters|
|GeoVal|“M”|Reference Unit for GeoSep (“M” = meters)|
|DGPSAge|Empty|Not supported|
|DGPSRef|Empty|Not supported|



## **Example:** 

```
$GPGGA,183417.000,04814.03970,N,01128.52205,E,0,00,99.0,495.53,M,47.6,M*53
```

## **11.5.2 $--GLL** 

Geographic Positioning Latitude / Longitude 

NMEA message list bitmask (64 bits): 0000 0000 0010 0000 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGLL,<Lat>,<N/S>,<Long>,<E/W>,<Timestamp>,<Status>,<mode indicator>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>GLL,<Lat>,<N/S>,<Long>,<E/W>,<Timestamp>,<Status>,<mode
indicator>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 104. $--GLL message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Lat|DDMM.MMMMM|Latitute as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|N/S|“N” or “S”|Latitude direction: North or South<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Long|DDMM.MMMMM|Longitude as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)|



**UM2791** - **Rev 3** 

**page 95/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||Note that for Rev 4.10 this field is empty in case of invalid value|
|E/W|“E” or “W”|Longitude direction: East or West<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Timestamp|hhmmss.sss|UTC Time of GGL Sample, example: 160836<br>“.sss” is the fraction of seconds; it assumes non zero values when the fix rate is bigger<br>than 1Hz.|
|Status|“A” or “V”|Validity of Data: “A” = valid, “V” = invalid|
|Mode indicator|“D”, “A”, “N” or “E”|Positioning system Mode Indicator:<br>“D” = Differential mode<br>“A” = Autonomous mode<br>“N” = data not valid<br>“E” = Estimated (dead reckoning) mode|



## **Example:** 

```
$GPGLL,4055.04673,N,01416.54941,E,110505.000,A,A*54
```

## **11.5.3 $--GSA** 

GNSS DOP and Active Satellites. Satellites from different constellations are sent on separate messages. In case of multi-constellation mode, the talker ID is always GN. If NMEA is set as Rev 3.1, it is possible to force the talker ID as GN also acting on CDB-ID 200. (See STA8089-90 Firmware Configuration document). 

When NMEA is set as Rev. 4.10 the talker ID could not be forced and is managed internally to be compliant with the standard. See parameter table for info about Talker ID available values. 

NMEA message list bitmask (64 bits): 0000 0000 0000 0004 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$--GSA,<Mode>,<CurrentMode>,<SatPRN1>,...,<SatPRNN>,<PDOP>,<HDOP>,
<VDOP>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$--GSA,<Mode>,<CurrentMode>,<SatPRN1>,...,<SatPRNN>,<PDOP>,<HDOP>,
<VDOP>,<SystemID>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 105. $--GSA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|CurrentMode|Decimal, 1 digit|Current Mode:<br>1 = Fix not available or invalid<br>2 = GPS, SPS Mode, fix valid<br>3 = Differential GPS, SPS Mode, fix valid|



**UM2791** - **Rev 3** 

**page 96/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|SatPRN(1 to 12)|Decimal, 2 or 3 digits|Satellites list used for positioning. See Chapter 6.5 for more info about available<br>values.|
|PDOP|Decimal, 3 digits|Position Dilution of Precision, max: 99.0|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, max: 99.0|
|VDOP|Decimal, 3 digits|Vertical Dilution of Precision, max: 99.0|
|SystemID|Hexadecimal, 1 digit|The system ID of this message:<br>1 = GPS<br>2 = GLONASS<br>3 = GALILEO<br>4 = BEIDOU<br>5 = QZSS|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGSA,A,3,05,21,07,24,30,16,12,,,,,,2.4,1.9,1.5*38
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNGSA,A,3,23,03,22,09,01,19,17,06,31,11,,,1.1,0.6,0.9,1*3E
$GNGSA,A,3,67,66,81,65,88,75,82,74,,,,, 1.1,0.6,0.9,2*3D
```

```
$GNGSA,A,3,03,05,22,08,30,16,12,,,,,, 1.1,0.6,0.9,3*32
```

## **11.5.4** 

## **$--GSV** 

GNSS Satellites in View. 

Usually GSV messages are organised per constellation and each message carries information about up to 4 satellites in view. Thus, in certain cases, to describe all the satellites in view from a constellation more than a message is needed. This set of message is printed once per each constellation with talker ID related to described constellation. 

Prior to NMEA Revision 3.1 it is possible to force the “GN” talker ID acting on CDB-ID 200 Bit 19. In such case a single set of messages is sent. 

With NMEA Rev 4.10 the “GN” talker ID is forbidden in order to be compliant with the standard. Thus the module will print a set of messages for each constellation. 

NMEA message list bitmask (64 bits): 0000 0000 0008 0000 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$--GSV,<GSVAmount>,<GSVNumber>,<TotSats>,<Sat1PRN>,<Sat1Elev>,
<Sat1Azim>,<Sat1CN0>,…,<Sat4PRN>,<Sat4Elev>,<Sat4Azim>,<Sat4CN0>*
<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$--GSV,<GSVAmount>,<GSVNumber>,<TotSats>,<Sat1PRN>,<Sat1Elev>,
<Sat1Azim>,<Sat1CN0>,…,<Sat4PRN>,<Sat4Elev>,<Sat4Azim>,<Sat4CN0>,
<SignalID>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 106. $--GSV message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode|



**UM2791** - **Rev 3** 

**page 97/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|GSVAmount|Decimal, 1 digit|Total amount of GSV messages, max. 3|
|GSVNumber|Decimal, 1 digit|Continued GSV number of this message|
|TotSats|Decimal, 2 digits|Total Number of Satellites in view, max. 12|
|SatxPRN|Decimal, 2 digits|Satellites list used for positioning. See Chapter 6.5 for more info about available values.|
|SatxElev|Decimal, 2 digits|Elevation of satellite x in Degree,<br>0 … 90|
|SatxAzim|Decimal, 3 digits|Azimuth of satellite x in degree, ref. “North”,<br>000 … 359|
|SatxCN0|Decimal, 2 digits|Carrier to Noise Ratio for satellite x in dB,<br>00 … 99|
|SignalID|Decimal, 1 digits|An identifier to indicate the signal in use. Currently it is 1 for GPS, GLONASS, 2 for<br>BEIDOU and QZSS 6 for GALILEO|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGSV,3,1,12,02,04,037,,05,27,125,44,06,78,051,23,07,83,021,30*7C
$GPGSV,3,2,12,10,16,067,30,12,11,119,36,16,24,301,41,21,44,175,50*73
$GPGSV,3,3,12,23,06,326,28,24,61,118,40,30,45,122,43,31,52,253,37*7C
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GPGSV,3,1,09,30,68,039,49,05,61,266,50,28,52,137,47,07,38,052,48,01*5C
$GPGSV,3,2,09,13,37,301,45,09,17,105,43,15,07,297,40,08,06,056,41,01*56
```

```
$GPGSV,3,3,09,20,,,41,,,,,,,,,,,,,01*5A
```

```
$GLGSV,2,1,06,68,86,031,43,78,78,013,46,79,51,226,43,69,33,325,38,01*43
$GLGSV,2,2,06,67,33,139,41,77,26,035,36,,,,,,,,,01*46
$GAGSV,2,1,05,08,76,129,44,02,65,057,46,30,56,205,45,07,48,311,44,06*4F
$GAGSV,2,2,05,03,22,129,40,,,,,,,,,,,,,06*7D
```

## **11.5.5** 

## **$--RMC** 

Recommended Minimum Specific GPS/Transit data. Time, date, position and speed data provided by the TeseoModule. This sentence is transmitted at intervals not exceeding 2 seconds and is always accompanied by RMB when destination waypoint is active. 

NMEA message list bitmask (64 bits): 0000 0000 0000 0040 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPRMC,<Timestamp>,<Status>,<Lat>,<N/S>,<Long>,<E/W>,<Speed>,
<Trackgood>,<Date>,<MagVar>,<MagVarDir>,<mode>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>RMC,<Timestamp>,<Status>,<Lat>,<N/S>,<Long>,<E/W>,<Speed>,
<Trackgood>,<Date>,<MagVar>,<MagVarDir>,<mode>,
<Nav_status>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 98/241** 

**UM2791 Standard NMEA messages specification** 

## **Arguments:** 

**Table 107. $--RMC message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than 1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Status|“A” or “V”|Teseo warning: “A” = valid, “V” = Warning<br>NOTE: “V” is reported in NO FIX conditions and “A” is reported in 2D and 3D fix conditions.|
|Lat|DDMM.MMMMM|Latitude as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|N/S|“N” or “S”|Latitude direction: North or South<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Long|DDDMM.MMMMM|Longitude as degrees:<br>DD: Degree (Fixed three digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|E/W|“E” or “W”|Longitude direction: East or West<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Speed|ddd.d|Speed over ground in knots|
|Trackgood|Decimal, 4 digits|Course made good, max. 999.9|
|Date|Decimal, 6 digits|Date of Fix : ddmmyy|
|MagVar|Decimal, 4 digits|Magnetic Variation, max.: 090.0|
|MagVarDir|“E” or “W”|Magnetic Variation Direction|
|Mode|“D”, “A”, “N” or “E”|Positioning system Mode Indicator:<br>“D” = Differential mode<br>“A” = Autonomous mode<br>“N” = data not valid<br>“E” = Estimated (dead reckoning) mode|



**UM2791** - **Rev 3** 

**page 99/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Nav_status|“S”, “C”, “U” or “V”|Navigational status indicator:<br>“S” = Safe<br>“C” = Caution<br>“U” = Unsafe<br>“V” = Not valid|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPRMC,183417.000,V,4814.040,N,01128.522,E,0.0,0.0,170907,0.0,W*6C
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNRMC,,V,,,,,,,,,,N,V*37
```

or `$GNRMC,202340.000,A,4045.53297,N,01447.20361,E,0.2,0.0,291117,,,A,C*18` 

## **11.5.6 $--VTG** 

Course over ground and ground speed, this message provides the actual course and speed relative to ground. NMEA message list bitmask (64 bits): 0000 0000 0000 0010 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPVTG,<TMGT>,T,<TMGM>,M,<SoGN>,N,<SoGK>,K,D*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>VTG,<TMGT>,T,<TMGM>,M,<SoGN>,N,<SoGK>,K,D*<checksum><cr><lf>
```

## **Arguments:** 

**Table 108. $--VTG message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|TMGT|ddd.d in degrees|Track in reference to “true” earth poles|
|T||Indicates “terrestrial”|
|TMGM|ddd.d in degrees|Track in reference to “magnetic” earth poles|
|M||Indicates “magnetic”|
|SoGN|ddd.d in knots|Speed over Ground in knots|
|N||Indicates “knots”|
|SoGK|ddd.d in km/h|Speed over Ground in kilometers per hour|
|K||Indicates “kilometres”|
|D|char|Mode indicator:<br>A = Autonoumus mode<br>D = Differential mode|



**UM2791** - **Rev 3** 

**page 100/241** 

**UM2791** 

**Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||E = Estimated mode|



## **Example:** 

```
$GPVTG,73.2,T,,M,0.2,N,0.4,K,D*50
```

## **11.5.7 $--ZDA** 

UTC, day, month and year. 

NMEA message list bitmask (64 bits): 0000 0000 0100 0000 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPZDA,<Timestamp>,<Day>,<Month>,<Year>,00,00*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>ZDA,<Timestamp>,<Day>,<Month>,<Year>,,*<checksum><cr><lf>
```

## **Arguments:** 

**Table 109. $--ZDA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than 1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Day|Decimal, 2 digits|Day of month (01 to 31)|
|Month|Decimal, 2 digits|Month (01 to 12)|
|Year|Decimal, 4 digits|Year (1994 - …)|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPZDA,110505.00,25,01,2013,00,00*60
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNZDA,204409.000,29,11,2017,,*4C
```

## **11.5.8** 

## **$--GST** 

Global Positioning System Pseudorange Noise Statistics. NMEA message list bitmask (64 bits): 0000 0000 0000 0008 

**UM2791** - **Rev 3** 

**page 101/241** 

**UM2791 Standard NMEA messages specification** 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGST,<Timestamp>,<EHPE>,<Semi-major>,<Semi-minor>,<Angle>,<LatErr>,
<LonErr>,<Alt Err Dev>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>GST,<Timestamp>,<EHPE>,<Semi-major>,<Semi-minor>,
<Angle>,<LatErr>,<LonErr>,<Alt Err Dev>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 110. $--GST message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than 1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|EHPE|dd.d in m|Equivalent Horizontal Position Error|
|Semi-major|dd.d in m|Standard deviation (meters) of semi-major axis of error ellipse|
|Semi-minor|dd.d in m|Standard deviation (meters) of semi-minor axis of error ellipse|
|Angle|dd.d in degree|Orientation of semi-major axis of error ellipse (true north degrees)|
|LatErr|dd.d in m|Standard deviation (meters) of latitude error|
|LonErr|dd.d in m|Standard deviation (meters) of longitude error|
|AltErr|dd.d in m|Standard deviation (meters) of altitude error|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGST,101429.000,0.0,3.5,3.1,89.4,3.2,3.4,3.4*58
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNGST,205512.000,16.5,5.6,4.5,0.8,5.0,5.0,6.7*41
```

or `$GAGST,,,,,,,,*46` 

## **11.5.9 $--GBS** 

GNSS Satellite Fault Detection 

NMEA message list bitmask (64 bits): 0000 2000 0000 0000 

**UM2791** - **Rev 3** 

**page 102/241** 

**UM2791 Standard NMEA messages specification** 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPGBS,<Timestamp>,<LatErr>,<LonErr>,<AltErr>,<SatPRN>,<Prob>,
<Res>,<StdDev>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>GBS,<Timestamp>,<LatErr>,<LonErr>,<AltErr>,<SatPRN>,<Prob>,
<Res>,<StdDev>,<SystemID>,<SignalID>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 111.  $--GBS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than 1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|LatErr|dd.d in m|Standard deviation (meters) of latitude error|
|LonErr|dd.d in m|Standard deviation (meters) of longitude error|
|AltErr|dd.d in m|Standard deviation (meters) of altitude error|
|SatPRN|Decimal, 2 digits|PRN Number of most likely failed satellite.<br>This satellite is excluded by RAIM or FDE algorithm.|
|Prob|Empty|Probability of missed detection for most likely failed satellite<br>Not supported|
|Res|dd.d in m|Range residual of most likely failed satellite|
|StdDev|Empty|Standard Deviation of bias estimate<br>Not supported|
|SystemID|Hexadecimal, 1 digit|The system ID of this message:<br>1 = GPS<br>2 = GLONASS<br>3 = GALILEO<br>4 = BEIDOU<br>5 = QZSS|
|SignalID|Decimal, 1 digits|An identifier to indicate the signal in use. Currently it is 1 for GPS, GLONASS, 2 for<br>BEIDOU and QZSS 6 for GALILEO|



**Example for NMEA 0183 Rev 3.1 (Default):** 

**UM2791** - **Rev 3** 

**page 103/241** 

**UM2791 Standard NMEA messages specification** 

```
$GPGBS,033037.000,10.7,12.0,14.1,08,,-51.7,*7C
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNGBS,211120.000,7.6,9.6,10.8,,,,,,*59
```

## **11.5.10 $--GNS** 

Fix data for single or combined satellite navigation system (GNSS). NMEA message list bitmask (64 bits): 0000 0000 0000 0001 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$<TalkerID>GNS,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<Mode>,
<Sats>,<HDOP>,<AltVal>,<GEOVal>,<DGPSAge>,<DGPSRef>*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>GNS,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<Mode>,
<Sats>,<HDOP>,<AltVal>,<GEOVal>,<DGPSAge>,<DGPSRef>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 112. $--GNS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample:<br>hh: hours (Fixed two digits)<br>mm: minutes (Fixed two digits)<br>ss: seconds (Fixed two digits)<br>.sss: decimal fraction of seconds (Variable length)<br>Note that decimal fraction assumes non zero values when the fix rate is bigger than<br>1Hz.<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Lat|DDMM.MMMMM|Latitude as degrees:<br>DD: Degree (Fixed two digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|N/S|“N” or “S”|Latitude direction: North or South<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Long|DDDMM.MMMMM|Longitude as degrees:<br>DD: Degree (Fixed three digits)<br>MM: Minutes (Fixed two digits)<br>.MMMMM: Decimal fraction of minutes (Variable)<br>Note that for Rev 4.10 this field is empty in case of invalid value|



**UM2791** - **Rev 3** 

**page 104/241** 

**UM2791 Standard NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|E/W|“E” or “W”|Longitude direction: East or West<br>Note that for Rev 4.10 this field is empty in case of invalid value|
|Mode Indicator|Char or String|In case of single constellation this is a character which can assume these values:<br>N = NO Fix<br>A = Autonomous<br>D = Differential GPS<br>E = Estimated (dead reckoning mode)<br>In multi-constellation mode this is a 5 letter string where each letter is the mode<br>indicator of each constellation in this order: GPS, GLONASS, GALILEO, BEIDOU,<br>QZSS|
|Sats|Decimal, 2 digits|Satellites in use: example: 8|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, max: 99.0|
|Alt|Decimal, 6 digits|Height above WGS84 Elipsoid, max: 100000m|
|GEOSep|Decimal, 4 digits|Geoidal separation, meter|
|DGNSSAge|Empty field|Not supported|
|DGNSSRef|Empty field|Not supported|



_Note: In case of single constellation setup the mode indicator consists in one character and the information about the constellation is given by talker id._ 

## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GNGNS,091233.000,4055.04824,N,01416.55600,E,AAANN,19,0.7,0078.1,42.9,,*17
```

or 

```
$GPGNS,083423.000,4055.04781,N,01416.55528,E,A,10,0.9,0092.0,42.9,,*06
```

## **Example for NMEA 0183 Rev 4.10:** 

`$GPGNS,211803.000,4045.53340,N,01447.19988,E,A,04,2.2,0240.1,42.0,,*08` Or 

```
$GAGNS,,,,,,N,00,99.0,0282.1,0.0,,*35
```

## **11.5.11** 

## **$--DTM** 

Local geodetic datum and datum offsets from a reference datum. This sentence is used to define the datum to which a position location, and geographic locations in subsequent sentences, is referenced. If enabled, this message is sent for every position fix as first NMEA message in the list. 

NMEA message list bitmask (64 bits): 0000 0080 0000 0000 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$GPDTM,<Local_datum_code>,<local_datum_code_id>,<Lat_offset>,<N/S>,
<Long_offest>,<E/W>,<Alt_offset>,<Reference_datum_code>
*<checksum><cr><lf>
```

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>DTM,<Local_datum_code>,<local_datum_code_id>,<Lat_offset>,
<N/S>,<Long_offest>,<E/W>,<Alt_offset>,<Reference_datum_code>
*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 105/241** 

**UM2791 Standard NMEA messages specification** 

## **Arguments:** 

**Table 113. $--DTM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If system works in GPS only mode<br>GL: If system works in GLONASS only mode<br>GA: If system works in GALILEO only mode<br>BD: If system works in BEIDOU only mode<br>QZ: If system works in QZSS only mode<br>GN: If system works in multi-constellation mode.|
|Local_datum_code|ccc|Local datum code (three characters):<br>W84 = WGS84<br>P90 = PZ90<br>999 = User Defined Datum<br>IHO = Datum reported in the International Hydrographic Organization<br>Publication S-60 Appendices B and C.<br>Note: all supported datum are listed in the Appendix A at the end of this<br>document.|
|local_datum_code_id|ddd|In case the local datum code is W84 or 999 (User Defined) this field is left<br>empty. In all other cases this field reports the local datum code ID (three<br>numeric digits) as reported in Appendix A at the end of this document. The<br>local datum code ID is the same number used to identify the datum code in the<br>firmware configuration (CDB-ID)|
|Lat_offset|mmm.mmmmm|Latitude offset in minutes|
|N/S|“N” or “S”|Lat Direction: North or South|
|Long_offest|mmm.mmmmm|Longitude offset in minutes|
|E/W|“E” or “W”|Long Direction: East or West|
|Alt_offset|aaa.aaaaaa|Altitude offset in meters|
|Reference_datum_code|ccc|Reference datum code (three characters):<br>W84 = WGS84|



## **Example for NMEA 0183 Rev 3.1 (Default):** 

```
$GPDTM,W84,,000.00000,N,000.00000,E,0.000000,W84*5F
$GPDTM,P90,253,000.00005,S,000.00266,E,0.000000,W84*73
$GPDTM,999,,000.18907,N,000.05146,W,0.000000,W84*2E
$GPDTM,IHO,037,000.11581,N,000.01822,W,0.000000,W84*69
```

## **Example for NMEA 0183 Rev 4.10:** 

```
$GNDTM,W84,,2445.54843,N,887.20838,E,0.000000,W84*7E
```

## **11.5.12 $--RLM** 

Return Link Message data. 

NMEA message list bitmask (64 bits): 8000 0000 0000 0000. 

## **Synopsis for NMEA 0183 Rev 3.1 (Default):** 

```
$<TalkerID>RLM,<BeaconID>,<TimeOfReception>,<MessageCode>,<MessageBody>
*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 106/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis for NMEA 0183 Rev 4.10:** 

```
$<TalkerID>RLM,<BeaconID>,<TimeOfReception>,<MessageCode>,<MessageBody>*
<checksum><cr><lf>
```

**Arguments** : 

**Table 114. $--RLM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|TalkerID|String, 2 characters|The talker ID (Fixed two characters).<br>GP: If the RLM has been received on a GPS satellite<br>GL: If the RLM has been received on a GLO satellite<br>GA: If the RLM has been received on a GAL satellite<br>BD: If the RLM has been received on a BDS satellite<br>QZ: If the RLM has been received on a QZS satellite<br>**Note:**Currently only GALILEO supports RLM|
|BeaconID|Hexadecimal, 15 digits|Beacon intended to receive the message|
|TimeOfReception|hhmmss.ss|UTC Time of RLM (time of reception of the last 20 bit packet of the RLM):<br>•<br>hh: hours (Fixed two digits)<br>•<br>mm: minutes (Fixed two digits)<br>•<br>ss: seconds (Fixed two digits)<br>•<br>.ss: decimal fraction of seconds (Fixed two digits)|
|MessageCode|Hexadecimal, 1 digit|Type of RLM Message Service:<br>•<br>0: Reserved<br>•<br>1: Acknowledgment Service RLM<br>•<br>2: Command Service RLM<br>•<br>3: Message Service RLM<br>•<br>4-E: Reserved<br>•<br>F: Test Service RLM|
|MessageBody|Hexadecimal, up to 24<br>digits|Variable field length encapsulating the data parameters into hexadecimal format.<br>•<br>GALILEO Short Message: 4 hexadecimal digits<br>•<br>GALILEO Long Message: 24 hexadecimal digits|



**Results** : None. **Example** : GALILEO Short RLM `$GARLM,A5A5A123213C3C3,220151.00,1,CAFE*0E` GALILEO Long RLM `$GARLM,00CAFE11DECAF00,221909.00,1,1F0F1ABCDE2F0F2123453F0F*0C` 

## **11.6 ST NMEA messages specification** 

In order to provide further data and information from the Teseo-Module, which are not provided by the standard NMEA messages, STMicroelectronics provides “proprietary messages”. Any proprietary message on the NMEA port starts with “$PSTM…” where “STM” indicate that it is a ST proprietary message ($PSTMxxx…) 

There are two sorts of “proprietary messages” within a Teseo-Module. They are either send repeatedly with a defined or definable reporting rate or they are send only once as a reaction to a command. 

## **11.6.1 $PSTMINITGPSOK** 

Message sent in response of command $PSTMINITGPS 

**UM2791** - **Rev 3** 

**page 107/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis:** 

```
$PSTMINITGPSOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.6.2** 

## **$PSTMINITGPSERROR** 

Message sent in response of command $PSTMINITGPS 

## **Synopsis:** 

```
$PSTMINITGPSERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.6.3** 

## **$PSTMINITTIMEOK** 

Message sent in response of command $PSTMINITTIME 

## **Synopsis:** 

```
$PSTMINITTIME OK*<checksum><cr><lf>
```

## **Arguments:** 

None. **Results:** 

- Message sent in case of successful operation. 

## **11.6.4 $PSTMINITTIMEERROR** 

Message sent in response of command $PSTMINITTIME 

## **Synopsis:** 

```
$PSTMINITTIMEERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.6.5 $PSTMSETRANGEOK** 

Message sent in response of command $PSTMSETRANGE 

## **Synopsis:** 

```
$PSTMSETRANGEOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

**UM2791** - **Rev 3** 

**page 108/241** 

**UM2791 ST NMEA messages specification** 

|**11.6.6**|**$PSTMSETRANGEERROR**|
|---|---|
||Message sent in response of command $PSTMSETRANGE|
||**Synopsis:**|
||`$PSTMSETRANGEERROR*<checksum><cr><lf>`|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of error.|
|**11.6.7**|**$PSTMSBASSERVICEOK**|
||Message sent in response of command $PSTMSBASSERVICE|
||**Synopsis:**|
||`$PSTMSBASSERVICEOK*<checksum><cr><lf>`|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of successful operation.|
|**11.6.8**|**$PSTMSBASSERVICEERROR**|
||Message sent in response of command $PSTMSBASSERVICE|
||**Synopsis:**|
||`$PSTMSBASSERVICEERROR*<checksum><cr><lf>`|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of error.|
|**11.6.9**|**$PSTMSBASMOK**|
||Message sent in response of command $PSTMSBASM|
||**Synopsis:**|
||`$PSTMSBASMOK*<checksum><cr><lf>`|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of successful operation.|
|**11.6.10**|**$PSTMSBASMERROR**|
||Message sent in response of command $PSTMSBASM|



## **Synopsis:** 

```
$PSTMSBASMERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**UM2791** - **Rev 3** 

**page 109/241** 

**UM2791 ST NMEA messages specification** 

## **Results:** 

- Message sent in case of error. 

## **11.6.11** 

## **$PSTMGETALGOOK** 

Message sent in response of command $PSTMGETALGO 

## **Synopsis:** 

```
$PSTMGETALGOOK,<algo_type>,<algo_status>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 115. $PSTMGETALGOOK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|algo_type|Decimal, 1 digit|1 = FDE algorithm on/off status is returned.|
|algo_status|Decimal, 1 digit|0 = the algorithm is disabled.<br>1 = the algorithm is enabled.|



## **Results:** 

- Message sent in case of successful operation. 

## **11.6.12** 

## **$PSTMGETALGOERROR** 

Message sent in response of command $PSTMGETALGO 

## **Synopsis:** 

## `$PSTMGETALGOERROR*<checksum><cr><lf>` 

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of error. 

## **11.6.13** 

## **$PSTMSETALGOOK** 

Message sent in response of command $PSTMSETALGO 

## **Synopsis:** 

```
$PSTMSETALGOOK,<algo_type>,<algo_status>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 116. $PSTMSETALGOOK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|algo_type|Decimal, 1 digit|1 = FDE algorithm on/off status is returned.|
|algo_status|Decimal, 1 digit|0 = the algorithm is disabled.<br>1 = the algorithm is enabled.|



## **Results:** 

- Message sent in case of successful operation. 

## **11.6.14 $PSTMSETALGOERROR** 

Message sent in response of command $PSTMSETALGO 

**UM2791** - **Rev 3** 

**page 110/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis:** 

```
$PSTMGETALGOERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of error. 

## **11.6.15** 

## **$PSTMGETRTCTIME** 

Message sent in response of command $PSTMGETRTCTIME 

## **Synopsis:** 

```
$PSTMGETRTCTIME,<time>,<date>,<rtc_status>,<time_validity>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 117. $PSTMGETRTCTIME message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|time|hhmmss.mms|Current time read on RTC.|
|date|ddmmyy|Current date read on RTC.|
|rtc_status|Decimal, 1 digit|Status:<br>0 - RTC_STATUS_INVALID<br>1 - RTC_STATUS_STORED<br>2 - RTC_STATUS_APPROXIMATE|
|time_validity|Decimal, 1 digit|Validity:<br>0 - NO_TIME<br>1 - FLASH_TIME<br>2 - USER_TIME<br>3 - USER_RTC_TIME<br>4 - RTC_TIME<br>5 - RTC_TIME_ACCURATE<br>6 - APPROX_TIME<br>7 - POSITION_TIME<br>8 - EPHEMERIS_TIME|



## **Results:** 

None 

## **11.6.16 $PSTMDATUMSELECTOK** 

Message sent in response of command $PSTMDATUMSELECT **Synopsis:** 

```
$PSTMDATUMSELECTOK,<datum_type>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 111/241** 

**UM2791 ST NMEA messages specification** 

## **Arguments:** 

**Table 118. $PSTMDATUMSELECTOK field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|datum_type|Integer|0 : WGS84<br>1: TOKYO MEAN<br>2: OSGB|



## **Results:** 

- Message sent in case of successful operation. 

## **11.6.17 $PSTMDATUMSELECTERROR Synopsis: Arguments:** None **Result:** None **11.6.18 $PSTMDATUMSETPARAMOK** 

Message sent in response of command $PSTMDATUMSELECT 

`$PSTMSELECTDATUMERROR*<checksum><cr><lf>` **Arguments:** None **Result:** None 

Message sent in response of command $PSTMDATUMSETPARAM 

## **Synopsis:** 

```
$PSTMDATUMSETPARAMOK*<checksum><cr><lf>
```

**Arguments:** None **Result:** 

- Message sent in case of successful operation. 

## **11.6.19 $PSTMDATUMSETPARAMERROR** 

Message sent in response of command $PSTMDATUMSETPARAM 

## **Synopsis:** 

`$PSTMDATUMSETPARAMERROR*<checksum><cr><lf>` **Arguments:** None **Result:** None 

## **11.6.20** 

## **$PSTMPOSITIONHOLDENABLED** 

Message sent in response of command $PSTMENABLEPOSITIONHOLD 

## **Synopsis:** 

```
$PSTMPOSITIONHOLDENABLED*<checksum><cr><lf>
```

**Arguments:** None 

**UM2791** - **Rev 3** 

**page 112/241** 

**UM2791 ST NMEA messages specification** 

## **Results:** 

None 

## **11.6.21 $PSTMPOSITIONHOLDDISABLED** 

Message sent in response of command $PSTMENABLEPOSITIONHOLD **Synopsis:** 

```
$PSTMPOSITIONHOLDDISABLED*<checksum><cr><lf>
```

**Arguments:** 

None **Results:** 

None 

## **11.6.22** 

## **$PSTMENABLEPOSITIONHOLDERROR** 

Message sent in response of command $PSTMENABLEPOSITIONHOLD **Synopsis:** 

```
$PSTMENABLEPOSITIONHOLDERROR*<checksum><cr><lf>
```

## **Arguments:** 

None **Results:** 

None 

## **11.6.23 $PSTMSETCONSTMASKOK** 

Message sent in response of command $PSTMSETCONSTMASK **Synopsis:** 

```
$PSTMSETCONSTMASKOK,<constellation_mask>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 119. $PSTMSETCONSTMASKOK message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|constellation_mask|Decimal, 1<br>digit|It is a bit mask where each bit enable/disable a specific constellation independently by<br>the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 2: QZSS constellation enabling/disabling<br>bit 3: GALILELO constellation enabling/disabling<br>bit 7: BEIDOU constellation enabling/disabling|



## **Results:** 

- Message sent in case of successful operation. 

## **11.6.24** 

## **$PSTMSETCONSTMASKERROR** 

Message sent in response of command $PSTMSETCONSTMASK **Synopsis:** 

```
$PSTMSETCONSTMASKERROR*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 113/241** 

**UM2791 ST NMEA messages specification** 

**Arguments:** None. **Results:** 

- Message sent in case of error. 

## **11.6.25 $PSTMALMANAC** 

Almanac Data Dump. 

This message is sent as a reply to a $PSTMDUMPALMANAC command. 

**Synopsis:** 

```
$PSTMALMANAC,<sat_id>,<N>,<byte1>,…..,<byteN>*<checksum><cr><lf>
```

**Arguments:** 

**Table 120. $PSTMALMANAC message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_id|Decimal, 2 digits|Satellite number|
|N|Decimal, 1 digit|Number of the almanac data bytes|
|byte1|Hexadecimal, 2 digits|First byte of the almanac data|
|byteN|Hexadecimal, 2 digits|Last byte of the almanac data|



The N Bytes that are in the message are the dump of a structures that contain all the information of the almanac. Data format are constellation dependant. 

**Table 121. $PSTMALMANAC message field description for GPS constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|8|satid|The satellite number|
|16|week|The week number for the epoch|
|8|toa|Reference time almanac.|
|16|e|Eccentricity.|
|16|delta_i|Rate of inclination angle.|
|16|omega_dot|Rate of right ascension.|
|24|root_A|Square root of semi-major axis.|
|24|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|24|perigee|Argument of perigee.|
|24|mean_anomaly|Mean anomaly at reference time.|
|11|af0|Constant clock correction.|
|11|af1|First order clock correction.|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|
|1|available|Contains 1 if almanac is available 0 if not.|



**Table 122. $PSTMALMANAC field description for GLONASS constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|8|satid|The satellite number.|



**UM2791** - **Rev 3** 

**page 114/241** 

**UM2791 ST NMEA messages specification** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|16|week|The week number for the epoch.|
|8|toa|Reference time almanac.|
|5|n_A|Slot number (1…24).|
|5|H_n_A|Carrier frequency channel number.|
|2|M_n_A|Type of satellite 00=GLONASS 01=GLONASS-M.|
|10|tau_n_A|Satellite clock correction.|
|15|epsilon_n_A|Eccentricity.|
|21|t_lambda_n_A|Time of the first ascending node passage.|
|21|lambda_n_A|Longitude of ascending node of orbit plane at almanac epoch.|
|18|delta_i_n_A|Inclination angle correction to nominal value.|
|7|delta_T_n_dot_A|Draconian period rate of change.|
|22|delta_T_n_A|Draconian period correction.|
|16|omega_n_A|Argument of perigee.|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|
|1|available|Contains 1 if almanac is available 0 if not.|
|32|Tau_c||
|11|NA||
|5|N4||
|16|Spare||



**Table 123. $ PSTMALMANAC field description for Galileo constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|16|satid|The satellite number|
|6|svid|Space Vehicle Identificator|
|16|week|The week number for the epoch|
|20|toa|Reference time almanac.|
|13|delta_a|Delta of semi-major axis.|
|11|e|Eccentricity.|
|16|perigee|Argument of perigee.|
|11|delta_i|Rate of inclination angle.|
|16|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|11|omega_dot|Rate of right ascension.|
|16|mean_anomaly|Mean anomaly at reference time.|
|16|af0|Constant clock correction.|
|13|af1|First order clock correction.|
|2|E5b_HS|E5 Signal Health Status|
|2|E1B_HS|E1-B Signal Health Status|
|4|ioda_1|Issue of data Almanac 1|
|4|ioda_2|Issue of data Almanac 2|
|1|health|Contains 1 if the satellite is unhealthy 0 if healthy.|



**UM2791** - **Rev 3** 

**page 115/241** 

**UM2791 ST NMEA messages specification** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|2|RESERVED|RESERVED for use by GNSS library|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|1|available|Contains 1 if almanac is available 0 if not.|



## **11.6.26** 

## **$PSTMALMANACOK** 

Message sent in response of command $PSTMALMANAC 

## **Synopsis:** 

```
$PSTMALMANACOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of successful operation. 

## **11.6.27 $PSTMALMANACERROR** 

Message sent in response of command $PSTMALMANAC 

## **Synopsis:** 

```
$PSTMALMANACERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of errors. 

## **11.6.28 $PSTMEPHEM** 

Ephemeris Data Dump. 

This message is sent as a reply to a $PSTMDUMPEPHEMS command. 

## **Synopsis:** 

```
$PSTMEPHEM,<sat_id>,<N>,<byte1>,…..,<byteN>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 124. $PSTMEPHEM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|sat_id|Decimal, 2 digits|Satellite number|
|N|Decimal, 1 Digit|Number of the ephemeris data bytes|
|byte1|Hexadecimal, 2 digits|First byte of the ephemeris data|
|byteN|Hexadecimal, 2 digits|Last byte of the ephemeris data|



The N Bytes that are in the message are the dump of a structures that contain all the information of the ephemeris. 

Data format are constellation dependant. 

**UM2791** - **Rev 3** 

**page 116/241** 

**UM2791 ST NMEA messages specification** 

**Table 125. $PSTMEPHEM message field description for GPS constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data|
|16|toe|Time of week for ephemeris epoch|
|16|toc|Time of week for clock epoch|
|8|iode1|Issue of data 1|
|8|iode2|Issue of data 2|
|10|iodc|Issue of data clock|
|14|i_dot|Rate of inclination angle.|
|8|RESERVED||
|24|omega_dot|Rate of right ascension.|
|8|RESERVED|Must be 0.|
|16|crs|Amplitude of the sine harmonic correction to the orbit radius.|
|16|crc|Amplitude of the cosine harmonic correction to the orbit radius.|
|16|cus|Amplitude of the sine harmonic correction to the argument of latitude.|
|16|cuc|Amplitude of the cosine harmonic correction to the argument of latitude.|
|16|cis|Amplitude of the sine harmonic correction to the angle of inclination.|
|16|cic|Amplitude of the cosine harmonic correction to the angle of inclination.|
|16|motion_difference|Mean motion difference from computed value|
|16|RESERVED|Must be 0.|
|32|inclination|Inclination angle at reference time|
|32|e|Eccentricity.|
|32|root_A|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|8|time_group_delay|Estimated group delay differential.|
|8|af2|Second order clock correction.|
|16|af1|First order clock correction.|
|22|af0|Constant clock correction.|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|1|RESERVED|Must be 0.|
|4|accuracy|Accuracy|



**Table 126. $PSTMEPHEM message field description for GLONASS constellation** 

|**Bits **|**Structure Member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data.|



**UM2791** - **Rev 3** 

**page 117/241** 

**UM2791 ST NMEA messages specification** 

|**Bits **|**Structure Member**|**Description**|
|---|---|---|
|16|toe|Time of week for ephemeris epoch.|
|4|toe_lsb|Time of week for ephemeris epoch (LBS).|
|11|NA|Calendar day number within the four-year period since the beginning of last leap year (almanac).|
|7|tb|Time of ephemeris index.|
|2|M|Type of satellite 00=GLONASS 01=GLONASS-M .|
|2|P1|Time interval between two adjacent tb parameters.|
|1|P3|Number of satellites for which almanac is transmitted within this frame 0=4 1=5.|
|1|P2|Flag of oddness ("1") or evenness ("0") of the value of tb|
|1|P4|Flag to show that ephemeris parameters are present.|
|2|KP|Notification on forthcoming leap second correction of UTC|
|1|RESERVED||
|27|xn|Satellite PZ-90 x coordinate at epoch tb.|
|5|xn_dot_dot|Satellite PZ-90 x velocity at epoch tb.|
|24|xn_dot|Satellite PZ-90 x acceleration component at epoch tb.|
|5|n|Slot number (1…24).|
|3|Bn|Healthy flags.|
|27|yn|Satellite PZ-90 y coordinate at epoch tb.|
|5|yn_dot_dot|Satellite PZ-90 y acceleration component at epoch tb.|
|24|yn_dot|Satellite PZ-90 y velocity at epoch tb.|
|8|age_h|Age of predicted ephemeris (hours)|
|27|zn|Satellite PZ-90 z coordinate at epoch tb.|
|5|zn_dot_dot|Satellite PZ-90 z acceleration component at epoch tb.|
|24|zn_dot|Satellite PZ-90 z velocity at epoch tb.|
|8|RESERVED|Must be 0.|
|11|gamma_n|Satellite clock frequency drift at epoch tb.|
|5|E_n|Age of the ephemeris information.|
|4|freq_id|Frequency ID|
|12|RESERVED||
|22|tau_n|Satellite clock correction at epoch tb.|
|10|RESERVED|Must be 0.|
|32|tau_c|GLONASS to UTC(SU) time correction.|
|22|tau_GPS|GLONASS to GPS system time correction.|
|10|RESERVED||
|11|NT|Calendar day number of ephemeris within the four-year period since the beginning of last leap<br>year.|
|5|N4|Four-year interval number starting from 1996.|
|12|tk|Satellite time referenced to the beginning of the frame.|
|4|FT|Predicted satellite user range accuracy<br>at time tb|
|32|RESERVED||
|5|m_available|Must be 0x1F|



**UM2791** - **Rev 3** 

**page 118/241** 

**UM2791 ST NMEA messages specification** 

|**Bits **|**Structure Member**|**Description**|
|---|---|---|
|1|nvm_reliable|Must be 1.|
|26|spare||
|25|RESERVED||
|1|available|Contains 1 if ephemeris is available, 0 if not.|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy.|
|1|RESERVED|Must be 0.|
|4|RESERVED||



**Table 127. $PSTMEPHEM message field description for Galileo constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|16|week|Week number of the Issue of Data|
|14|toe|Time of week for ephemeris epoch|
|2|RESERVED||
|16|toc|Time of week for clock epoch|
|10|iod_nav|Issue of data|
|8|SISA|Signal In Space Accuracy|
|10|RESERVED|Must be 0.|
|10|BGD_E1_E5a|E1-E5a Broadcast Group Delay|
|10|BGD_E1_E5b|E1-E5b Broadcast Group Delay|
|2|E1BHS|E1-B Signal Health Status|
|32|inclination|Inclination angle at reference time|
|32|eccentricity|Eccentricity.|
|32|root_a|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|14|i_dot|Rate of inclination angle.|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|
|16|motion_difference|Mean motion difference from computed value|
|16|crs|Amplitude of the sine harmonic correction to the orbit radius.|
|16|crc|Amplitude of the cosine harmonic correction to the orbit radius.|
|16|cus|Amplitude of the sine harmonic correction to the argument of latitude.|
|16|cuc|Amplitude of the cosine harmonic correction to the argument of latitude.|
|16|cis|Amplitude of the sine harmonic correction to the angle of inclination.|
|16|cic|Amplitude of the cosine harmonic correction to the angle of inclination.|
|24|omega_dot|Rate of right ascension.|
|6|SVID|Satellite Identification.|
|1|E1BDVS|E1-B Data Validity Status|
|1|RESERVED|Must be 0.|



**UM2791** - **Rev 3** 

**page 119/241** 

**UM2791 ST NMEA messages specification** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|8|RESERVED|Must be 0.|
|16|RESERVED|Must be 0.|
|6|af2|Second order clock correction.|
|21|af1|First order clock correction.|
|5|word_available|Must be 0x1F.|
|31|af0|Constant clock correction.|
|1|RESERVED||
|6|RESERVED|Must be 0|
|26|RESERVED|RESERVED for use by GNSS library – must be 1|
|1|RESERVED|Must be 0.|



**Table 128. $PSTMEPHEM message field description for BEIDOU constellation** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|32|inclination|Inclination angle at reference time|
|32|eccentricity|Eccentricity.|
|32|root_a|Square root of major axis.|
|32|mean_anomaly|Mean anomaly at reference time.|
|32|omega_zero|Longitude of ascending node of orbit plane at weekly epoch.|
|32|perigee|Argument of perigee.|
|17|toe|Time of week for ephemeris epoch|
|10|time_group_delay|Estimated group delay differential.|
|5|aode|Issue of data, ephemeris|
|24|omega_dot|Rate of right ascension.|
|8|A0|Ionospheric Delay Model Parameter α0|
|24|af0|Constant clock correction.|
|8|A1|Ionospheric Delay Model Parameter α1|
|20|sow|Seconds of week|
|11|af2|Second order clock correction.|
|1|is_geo|1 for Geostationary satellites, otherwise 0|
|22|af1|First order clock correction.|
|10|subframe_avail|Must be 0x3FF.|
|16|motion_difference|Mean motion difference from computed value|
|8|A2|Ionospheric Delay Model Parameter α2|
|8|A3|Ionospheric Delay Model Parameter α3|
|18|crs|Amplitude of the sine harmonic correction to the orbit radius.|
|8|B2|Ionospheric Delay Model Parameter β2|
|4|urai|User range accuracy index|
|2|RESERVED|Must be 0.|
|18|crc|Amplitude of the cosine harmonic correction to the orbit radius.|
|8|B3|Ionospheric Delay Model Parameter β3|



**UM2791** - **Rev 3** 

**page 120/241** 

**UM2791 ST NMEA messages specification** 

|**Bits**|**Structure Member**|**Description**|
|---|---|---|
|5|aodc|Issue of data, clock|
|1|spare||
|18|cus|Amplitude of the sine harmonic correction to the argument of latitude.|
|14|i_dot|Rate of inclination angle.|
|18|cuc|Amplitude of the cosine harmonic correction to the argument of latitude.|
|8|B0|Ionospheric Delay Model Parameter β0|
|6|spare||
|18|cis|Amplitude of the sine harmonic correction to the angle of inclination.|
|8|B1|Ionospheric Delay Model Parameter β1|
|6|RESERVED|Must be 0.|
|18|cic|Amplitude of the cosine harmonic correction to the angle of inclination.|
|1|nvm_reliable|Must be 1.|
|11|RESERVED|Must be 0.|
|2|spare||
|17|toc|Time of week for clock epoch|
|13|week|Week number of the Issue of Data|
|1|available|Contains 1 if ephemeris is available, 0 if not|
|1|health|Contains 1 if the satellite is unhealthy, 0 if healthy|



## **11.6.29 $PSTMEPHEMOK** 

Message sent in response of command $PSTMEPHEM. 

## **Synopsis:** 

```
$PSTMEPHEMOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of successful operation. 

## **11.6.30** 

## **$PSTMEPHEMERROR** 

Message sent in response of command $PSTMEPHEM. 

## **Synopsis:** 

```
$PSTMEPHEMERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of errors. 

## **11.6.31** 

## **$PSTMLOWPOWERON** 

Message sent in response of command $PSTMLOWPOWERONOFF 

**UM2791** - **Rev 3** 

**page 121/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis:** 

```
$PSTMLOWPOWERON,<EHPE_threshold>,
<Max_tracked_sats>,<Switch_constellation_features>,
<Duty_Cycle_enable>, <Duty_Cycle_fix_period>,
<Periodic_mode>,<Fix_period>,<Number_of_fix>,
<Ephemeris_refresh>,<RTC_refresh>,
<No_Fix_timeout>,<No_Fix_timeout_Off_duration>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 129. $PSTMLOWPOWERON field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Adaptive mode settings|||
|EHPE threshold|Decimal, 3 digits|EHPE average threshold [m]|
|Max tracked sats|Decimal, 2 digits|first N satellites (with higher elevation) used for the position calculation<br>(<br>Active channel management) in LOW POWER STATE|
|Switch constellation features|Decimal, 1 digit|Switch constellation features|
|Cyclic mode settings|||
|Duty Cycle enable/disable|Decimal, 1 digit|Duty Cycle features enable/disable|
|Duty Cycle ms signal off|Decimal, 3 digits|Estimated Horizontal Position Error Average|
|Periodic mode settings|||
|Periodic mode|Decimal, 1 digit|Setup Active or Standby periodic mode<br>0: OFF<br>3: Standby Periodic mode|
|FixPeriod|Decimal, 5 digits|Interval between two fixes [s]|
|FixOnTime|Decimal, 2 digits|Number of fixes reported for each interval|
|Ephemeris refresh|Decimal, 1 digit|Enable/Disable the refresh of ephemeris data<br>0: OFF, 1: ON|
|RTC calibration|Decimal, 1 digit|Enable/Disable the RTC calibration<br>0: OFF, 1: ON|
|NoFixCnt|Decimal, 2 digits|Time to declare fix loss [s] in HOT conditions|
|NoFixOff|Decimal, 2 digits|Period of off period after a fix loss [s]|



## **Results:** 

Message sent in case of successful operation. 

## **11.6.32 $PSTMLOWPOWERERROR** 

Message sent in response of command $PSTMLOWPOWERONOFF. 

## **Synopsis:** 

```
$PSTMLOWPOWERERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

**UM2791** - **Rev 3** 

**page 122/241** 

**UM2791 ST NMEA messages specification** 

## **11.6.33 $PSTMPPS** 

Message sent in response of command $PSTMPPS 

## **Synopsis:** 

```
$PSTMPPS,1,<cmd_type>,<par_1>,…,<par_N>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 130. $PSTMPPS field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|1|Decimal, 1 digit|1 = GET operation (to get data from PPS manager)|
|cmd_type|Decimal, 1 digit|1 = PPS_IF_ON_OFF_CMD<br>2 = PPS_IF_OUT_MODE_CMD<br>3 = PPS_IF_REFERENCE_CONSTELLATION_CMD<br>4 = PPS_IF_PULSE_DELAY_CMD<br>5 = PPS_IF_PULSE_DURATION_CMD<br>6 = PPS_IF_PULSE_POLARITY_CMD<br>7 = PPS_IF_PULSE_DATA_CMD<br>8 = PPS_IF_FIX_CONDITION_CMD<br>9 = PPS_IF_SAT_TRHESHOLD_CMD<br>10 = PPS_IF_ELEVATION_MASK_CMD<br>11 = PPS_IF_COSTELLATION_MASK_CMD<br>12 = PPS_IF_TIMING_DATA_CMD<br>13 = PPS_IF_POSITION_HOLD_DATA_CMD<br>14 = PPS_IF_AUTO_HOLD_SAMPLES_CMD<br>15 = PPS_IF_TRAIM_CMD<br>16 = PPS_IF_TRAIM_USED_CMD<br>17 = PPS_IF_TRAIM_RES_CMD<br>18 = PPS_IF_TRAIM_REMOVED_CMD<br>19 = PPS_IF_REFERENCE_TIME_CMD<br>20 = PPS_IF_CONSTELLATION_RF_DELAY_CMD|
|par_1 … par_N||Parameters list according to the command type specification (see below).|



## _**11.6.33.1 PPS Get PPS_IF_PULSE_DATA_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,7,<out_mode>,<reference_time>,<pulse_delay>,<pulse_duration>,
<pulse_polarity>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 131. $PSTMPPS field description on PPS_IF_PULSE_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|out_mode|Decimal, 1<br>digit|0 = PPS always generated.<br>1 = PPS generated on even seconds.<br>2 = PPS generated on odd seconds.|



**UM2791** - **Rev 3** 

**page 123/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|reference_time|Decimal, 1<br>digit|0 = UTC<br>1 = GPS_UTC.<br>2 = GLONASS_UTC.<br>3 = UTC_SU<br>4 = GPS_UTC_FROM_GLONASS<br>5 =BeiDou_UTC<br>6 = UTC_NTSC<br>7 = GST<br>8 = UTC_GST<br>9 = GPS_FROM_GST<br>NOTES:<br>UTC(SU) is the Soviet Union UTC, it is derived from GLONASS time applying the UTC delta<br>time downloaded from GLONASS satellites.<br>GPS_UTC_FROM_GLONASS is the GPS time derived from GLONASS time applying the<br>GPS delta time downloaded from GLONASS satellites.<br>If the software is configured to work in GLONASS only mode, UTC(SU) is identical to UTC<br>and GPS_UTC_FROM_GLONASS is identical to GPS_UTC.|
|pulse_delay|Decimal|Pulse delay [ns]|
|pulse_duration|Double|Pulse duration [s]|
|pulse_polarity|Decimal, 1<br>digit|0 = not inverted.<br>1 = inverted.|



## _**11.6.33.2 PPS Get PPS_IF_TIMING_DATA_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,12,<fix_condition>,<sat_th>,<elevation_mask>,<constellation_mask>,<gps_rf_delay>,
<glonass_rf_delay>*<checksum><cr><lf>
```

## **Arguments:** 

## **Table 132. $PSTMPPS field description on PPS_IF_TIMING_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|fix_condition|Decimal, 1 digit|1 = NOFIX.<br>2 = 2DFIX.<br>3 = 3DFIX.|
|sat_th|Decimal|Minimum number of satellites for the PPS generation.|
|elevation_mask|Decimal|Minimum satellite elevation for satellite usage in timing filtering.|
|constellation_mask|Decimal (bit mask)|Satellite constellation selection for usage in timing filtering.<br>bit0 = GPS<br>bit1 = GLONASS<br>bit3 = BeiDou<br>bit7 = Galileo|
|gps_rf_delay|Decimal|GPS path RF delay [ns]|
|glonass_rf_delay|Decimal|GLONASS path RF delay [ns]|



**UM2791** - **Rev 3** 

**page 124/241** 

**UM2791 ST NMEA messages specification** 

## _**11.6.33.3 PPS Get PPS_IF_POSITION_HOLD_DATA_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,13,<on_off>,<lat>,<lat_dir>,<lon>,<lon_dir>,<h_msl>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 133. $PSTMPPS field description on PPS_IF_POSITION_HOLD_DATA_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|0 = Position Hold disabled.<br>1 = Position Hold enabled.|
|lat|DDmm.mmmmm|Position Hold position latitude.|
|lat_dir|“N” or “S”|North or South direction.|
|lon|DDDmm.mmmmm|Position Hold position longitude.|
|lon_dir|“E” or “W”|East or West direction.|
|h_msl|Double|Position Hold mean see level altitude.|



## _**11.6.33.4 PPS_Get_PPS_IF_TRAIM_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,15,<traim_enabled>,<traim_solution>,<ave_error>
,<used_sats>,<removed_sats>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 134. $PSTMPPS field description on PPS_IF_TRAIM_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|traim_enabled|Decimal, 1 digit|TRAIM ON/OFF status<br>0 = OFF<br>1 = ON|
|traim_solution|Decimal, 1 digit|TRAIM Algorithm status:<br>0 = UNDER Alarm<br>1 = OVER Alarm<br>2 = UNKNOWN|
|ave_error|Decimal|Average time error [ns]|
|used_sats|Decimal|Number of satellite used for timing correction.|
|removed_sats|Decimal|Number of satellites removed by the timing correction.|



## _**11.6.33.5 PPS Get PPS_IF_TRAIM_RES_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,17,<traim_enabled>,<used_sats>,<res1>,..,<resN>*<checksum><cr><lf>
```

## **Arguments:** 

**UM2791** - **Rev 3** 

**page 125/241** 

**UM2791 ST NMEA messages specification** 

## **Table 135. $PSTMPPS field description on PPS_IF_TRAIM_RES_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|traim_enabled|Decimal, 1 digit|TRAIM ON/OFF status<br>0 = OFF<br>1 = ON|
|used_sats|Decimal|Number of satellite used for timing correction.|
|res1..resN|Decimal|List of satellites residuals [ns].<br>Each residual corresponds to the satellite in the used sat list at the same message position.|



## _**11.6.33.6 PPS Get PPS_IF_TRAIM_REMOVED_CMD**_ **Synopsis:** 

```
$PSTMPPS,1,18,<traim_enabled>,<rem_sats>,<sat1>,..,<satN>*<checksum><cr><lf>
```

**Arguments:** 

**Table 136. $PSTMPPS field description on PPS_IF_TRAIM_REMOVED_CMD** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|traim_enabled|Decimal, 1 digit|TRAIM ON/OFF status<br>0 = OFF<br>1 = ON|
|rem_sats|Decimal|Number of satellite removed by timing correction.|
|sat1..satN|Decimal|List of satellites IDs|



## **11.6.34 $PSTMPPSERROR** 

Message sent in response of command $PSTMPPS **Synopsis:** 

```
$PSTMPPSERROR*<checksum><cr><lf>
```

## **Arguments:** 

None **Result:** 

- Message will be sent in case of error 

## **11.6.35 $PSTMFORCESTANDBYOK** 

Message sent in response of command $PSTMFORCESTANDBY 

**Synopsis:** 

```
$PSTMFORCESTANDBYOK*<checksum><cr><lf>
```

**Arguments:** None **Results:** 

Message sent in case of successful operation. 

## **11.6.36 $PSTMFORCESTANDBYERROR** 

Message sent in response of command $PSTMFORCESTANDBY 

**UM2791** - **Rev 3** 

**page 126/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis:** 

```
$PSTMFORCESTANDBYERROR*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

Message is sent in case of error. 

## **11.6.37 $PSTMGALILEODUMPGGTO** 

Message sent in response of command $PSTMGALILEODUMPGGTO **Synopsis:** 

```
$PSTMGALILEOGGTO,<brd>,<WN0G>,<t0G>,<A0G>,<A1G>,<validity>*
<checksum><cr><lf>
```

## **Arguments:** 

**Table 137. $PSTMGALILEODUMPGGTO message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|brd|Decimal, 1 digits|1=broadcast GGTO|
|WN0G|Decimal, 3 digits|Value for WN0G|
|t0G|Decimal, 5 digits|Value for t0G|
|A0G|Decimal, 5 digits|Value for A0G|
|A1G|Decimal, 5 digits|Value for A1G|
|validity|binary|0=not valid, 1=valid|



## **Results:** 

None 

## **11.6.38 $PSTMSETTHTRKOK** 

Message sent in response of command $PSTMSETTHTRK 

## **Synopsis:** 

```
$PSTMSETTHTRKOK*<checksum><cr><lf>
```

## **Arguments:** 

None 

**Results:** 

Message sent in case of successful operation. 

## **11.6.39** 

## **$PSTMSETTHTRKERROR** 

Message sent in response of command $PSTMSETTHTRK 

## **Synopsis:** 

```
$PSTMSETTHTRKERROR*<checksum><cr><lf>
```

**Arguments:** 

None **Results:** 

Message sent in case of error 

**UM2791** - **Rev 3** 

**page 127/241** 

**UM2791 ST NMEA messages specification** 

## **11.6.40 $PSTMSETTHPOSOK** 

Message sent in response of command $PSTMSETTHPOS 

## **Synopsis:** 

## `$PSTMSETTHPOSOK*<checksum><cr><lf>` 

## **Arguments:** 

None 

**Results:** 

Message sent in case of successful operation. 

## **11.6.41 $PSTMSETTHPOSERROR** 

Message sent in response of command $PSTMSETTHPOS 

## **Synopsis:** 

```
$PSTMSETTHPOSERROR*<checksum><cr><lf>
```

## **Arguments:** 

None **Results:** 

- Message sent in in case of errors 

## **11.6.42 $PSTMVER** 

Message sent in response of command $PSTMGETSWVER **Synopsis:** 

```
$PSTMVER,<Lib>_<Ver>_<Type>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 138. $PSTMVER field specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Lib|Text, fixed|Text String identifying the Library that the command is requiring the version:<br>GNSSLIB if type = 0<br>OS20LIB if type = 1<br>GPSAPP if type = 2<br>BINIMG if type = 6<br>SWCFG if type = 11<br>PID if type = 12|
|Ver|x.x.x.x|GNSS Library Version: example 7.1.1.15|
|Type|ARM, GNU|Compiler Type: ARM or GNU|



## **Example:** 

```
$PSTMGETSWVER,0*<checksum><cr><lf>
```

_Note:_ 

_if any id is passed as parameter to the command, its output act as in the id = 0 case_ 

_Note: when id is 255 consecutive messages are sent reporting the library version string on each line following the above message syntax._ 

**UM2791** - **Rev 3** 

**page 128/241** 

**UM2791 ST NMEA messages specification** 

_Note:_ 

_when id is 254 the entire configuration block is printed on several lines using the following syntax:_ 

```
$PSTMSWCONFIG,<config_source>,<msg_n>,<msg_tot><data>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 139. $PSTMSWCONFIG field specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|config_source|Decimal, 1 digit|Configuration block data source:<br>1 = Current Configuration (RAM)<br>2 = Default Configuration (ROM)<br>3 = Saved Configuration (FLASH)|
|msg_n|Decimal, 1 digit|Current message number|
|msg_tot|Decimal, 1 digit|Total number of messages|
|data|String|64 Bytes per line printing each byte in HEX format.|



_Note: The HW version has the following syntax:_ 

```
$PSTMVER,STA80XX_<HW_SIGNATURE_STRING>*<checksum><cr><lf>
```

**Table 140. HW version field specification** 

|**HW_SIGNATURE_STRING**|**STA8089 HW**|
|---|---|
|0x622BC043|BD Mask|



## **11.6.43 $PSTMRF** 

Provides “satellite signal data” for each tracked satellite. Single message contains the relevant fields for max 3 satellites. For all satellites the message is repeated with the data of the other satellites. 

## **Synopsis:** 

```
$PSTMRF,<MessgAmount>,<MessgIndex>,<used_sats>,
 [<Sat1ID>,<Sat1PhN>,<Sat1Freq>,<Sat1CN0>],
 [<Sat2ID>,<Sat2PhN>,<Sat2Freq>,<Sat2CN0>],
 [<Sat3ID>,<Sat3PhN>,<Sat3Freq>,<Sat3CN0>],
 *<checksum><cr><lf>
```

## **Arguments:** 

**Table 141. $PSTMRF message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|MessgAmount|Decimal, 1 digit|Number of consecutive $PSTMRF messages|
|MessgIndex|Decimal, 1 digit|Current number in the sequence of messages|
|used_sats|Decimal, 2 digits|Number of satellites used in the fix|
|SatxID|Decimal, 2 digits|Satellite x Number (PRN)|
|SatxPhN|Decimal, 5 digits|Satellite x Phase Noise|
|SatxFreq|Decimal, 6 digits|Satellite x Frequency|
|SatxCN0|Decimal, 2 digits|Satellite x Carrier to Noise Ratio ( in dB )|



## **Results:** 

**UM2791** - **Rev 3** 

**page 129/241** 

**UM2791 ST NMEA messages specification** 

## None 

## **11.6.44 $PSTMTESTRF** 

Specific message containing information on just one satellite for RF testing purposes. 

## **Synopsis:** 

```
$PSTMTESTRF,<Sat-ID>,<Sat-Freq>,<Sat-PhN><Sat-CN0>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 142. $PSTMTESTRF message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Sat-ID|Decimal, 2 digits|Satellite Number (PRN)|
|Sat-Freq|Decimal, 5 digits|Satellite Frequency|
|Sat-PhN|Decimal, 5 digits|Satellite Phase Noise|
|Sat-CN0|Decimal, 2 digits|Satellite Carrier to Noise Ratio ( in dB )|



## **Results:** 

None 

## **11.6.45** 

## **$PSTMTG** 

Time and Satellites Information **Synopsis:** 

```
$PSTMTG,<Week>,<TOW>,<TotSat>,<CPUTime><Timevalid><NCO>
<kf_config_status><constellation_mask><time_best_sat_type><time_master_sat_type>
<time_master_week_n><time_master_tow><time_master_validity><time_aux_week_n><time_aux_tow>
<time_aux_validity>*
```

## **Arguments:** 

**Table 143. $PSTMTG message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Week|Decimal, 4 digits|Week Number|
|TOW|Decimal, 10 digits|Time of Week|
|Tot-Sat|Decimal, 2 digits|Total Number of satellites used for fix|
|CPU-Time|Decimal, 10 digits|CPU Time|
|Timevalid|Decimal, 2 digits|0 = no time<br>1 = time read from flash<br>2 = time set by user<br>3 = time set user RTC<br>4 = RTC time<br>5 = RTC time, accurate<br>6 = time approximate<br>7 = “not used”<br>8 = time accurate<br>9 = position time<br>10 = Ephemeris time|



**UM2791** - **Rev 3** 

**page 130/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|NCO|Decimal, 9 digits|NCO value|
|kf_config_status|Hexadecimal, 2 digits|Kalman Filter Configuration<br>For each bit:<br>· 0 means feature disabled<br>· 1 means feature enabled|
|constellation_mask|Decimal, 3 digits max|It is a bit mask where each bit enable/disable a specific constellation<br>independently by the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 2: QZSS constellation enabling/disabling<br>bit 3: GALILELO constellation enabling/disabling<br>bit 7: BAIDEU constellation enabling/disabling|
|time_best_sat_type|Decimal|selected best time satellite type|
|time_master_sat_type|Decimal|master time satellite type|
|time_aux_sat_type|Decimal|auxiliary time satellite type|
|time_master_week_n|Decimal|master time week number|
|time_master_tow|Floating|master time TOW|
|time_master_validity|Decimal|master week number time validity|
|time_aux_week_n|Decimal|auxiliary time|
|time_aux_tow|Floating|auxiliary time TOW|
|time_aux_validity|Decimal|auxiliary time validity|



**Table 144. kf_config_status bit configuration** 

|**Bit**|**Configuration**|
|---|---|
|0|Walking mode ON|
|1|Stop Detection ON|
|2|Frequency Ramp On (only Xtal mode)|
|3|Velocity estimator model:<br>· 1 means MULTIPLE MODEL<br>· 0 means SINGLE MODEL|
|4|Velocity estimator filter:<br>· 1 means SLOW<br>· 0 means FAST|
|5|FDE Status ON|



## **Results:** 

None 

## **11.6.46 $PSTMTS** 

This message is repeated for each satellite tracked and used for the calculation of a fix 

**UM2791** - **Rev 3** 

**page 131/241** 

**UM2791 ST NMEA messages specification** 

## **Synopsis:** 

```
$PSTMTS,<dsp-dat>,<SatID>,<PsR>,<Freq>,<plf>,<CN0>,<ttim>,<Satdat>,
 <Satx>,<Saty>,<Satz>,<Velx>,<Vely>,<Velz>,<src>,<ac>,
 <difdat>,<drc>,<drrc><predavl>,<predage>,<predeph>,<predtd>
 *<checksum><cr><lf>
```

## **Arguments:** 

**Table 145. $PSTMTS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|dsp-dat|Decimal, 1 digit|DSP data available:<br>0 = satellite not tracked<br>1 = satellite tracked|
|Sat-ID|Decimal, 2 digits|Satellite Number (PRN)|
|PsR|Decimal, 10 digits|Pseudo range|
|Freq|Decimal, 8 digits|Satellite tracking frequency offset|
|Plf|Decimal, 1 digit|Preamble Lock Flag<br>0 = Navigation data stream preamble not locked<br>1 = Navigation data stream preamble locked|
|CN0|Decimal, 3 digits|Satellite Carrier to Noise Ratio ( in dB )|
|Ttim|Decimal, 6 digits|Track Time of Satellite ( in seconds )|
|Satdat|Decimal, 1 digit|Satellite Data available Flag<br>0 = Sat. Ephemeris not available or unhealthy Sat.<br>1 = Sat. Ephemeris available and healthy Satellite|
|Satx|Decimal, 10 digits|Satellite Position , X-Coordinate|
|Saty|Decimal, 10 digits|Satellite Position , Y-Coordinate|
|Satz|Decimal, 10 digits|Satellite Position , Z-Coordinate|
|Velx|Decimal, 8 digits|Satellite Velocity , X-Coordinate|
|Vely|Decimal, 8 digits|Satellite Velocity , Y-Coordinate|
|Velz|Decimal, 8 digits|Satellite Velocity , Z-Coordinate|
|Src|Decimal, 6 Digits|Satellite Range Correction|
|Ac|Decimal, 3 Digits|Atmospheric Correction|
|Difdat|Decimal, 1 digit|Differential Data available Flag<br>0 = Differential Corrections not available<br>1 = Differential Corrections available|
|Drc|Decimal, 3 digits|Differential Range Correction (from DGPS Station)|
|Drrc|Decimal, 3 digits|Differential Range Rate Correction (from DGPS Stat.)|
|predavl|Decimal, 1 digit|Prediction available Flag<br>0 = Predicted Ephemeris not available<br>1 = Predicted Ephemeris available|
|predage|Decimal, 1 digit|Age of predicted Ephemeris (in hours)|
|predeph|Decimal, 1 digit|Number of satellites ussed for prediction (1 or 2)|
|predtd|Decimal, 1 digit|Time distance of Ephemeris calculated from 2 Sats.<br>Only valid if <pred-eph> = 2|



**UM2791** - **Rev 3** 

**page 132/241** 

**UM2791 ST NMEA messages specification** 

_Note:_ 

_<pred-xxx> fields are only included within the message if the AGPS software module has been included._ **Results:** 

None 

## **Example:** 

```
$PSTMTS,1,05,15748178.41,30992.22,1,44,306150,1,16278399.26,20504574.30,
4653136.69,38.03,703.04,-3046.01,141169.29,11.45,1,-12.75,0.00,
$PSTMTS,1,31,14242886.83,-28462.15,1,37,304775,1,20641723.13,
-8713847.54,14517949.66,1788.86,311.39,-2382.23,1804.01,7.09,1,
-5.74,0.00,
$PSTMTS,1,21,14885540.17,-25018.74,1,50,301653,1,25482227.75,
6629457.30,5528104.33,-699.61,220.74,2983.68,23248.85,8.12,1,
-2.84,0.00,
$PSTMTS,1,07,13337296.04,-27966.11,1,31,296621,1,15777659.46,
4155044.35,21301094.71,-1287.52,2301.27,509.20,-15394.31,5.65,1,
-3.83,0.00,
$PSTMTS,1,06,1216319.39,-28367.75,0,23,40492,1,14595868.85,
6511991.60,21397698.91,-1394.03,2294.91,251.81,70766.81,5.72,1,
-3.28,0.00,
$PSTMTS,1,24,13629659.89,-27176.62,1,40,298187,1,17698708.17,
12886703.95,15024752.78,-1901.12,-1.00,2298.33,11530.25,6.39,1,
-9.27,0.00,
$PSTMTS,1,30,14421546.48,-30401.97,1,44,298264,1,17539544.73,
16864817.03,10440026.12,394.97,1346.12,-2741.16,14708.79,7.87,1,
-9.96,0.00,
$PSTMTS,1,16,16177492.44,-24593.30,1,40,298572,1,6202032.13,
-17659074.51,18852818.90,1139.40,2098.88,1613.11,35896.88,12.03,1,
-4.54,0.00,
$PSTMTS,1,10,16728325.63,-26663.46,1,30,124750,1,-2057875.88,
21248945.17,15476302.66,-1018.51,-1731.48,2256.47,
-32564.02,15.33,1,-12.86,0.00,
$PSTMTS,1,12,17539958.05,-31018.23,1,35,10528,1,11788804.59,
23841922.01,245355.77,-236.27,137.48,-3173.58,-103404.01,20.66,1,
-19.21,0.00,
$PSTMTS,1,23,17770191.78,-27801.14,1,28,196026,1,-6131001.55,
-15740405.01,20363733.86,1549.10,-2097.11,-1173.09,89981.45,
27.98,0,0.00,0.00,
```

## **11.6.47 $PSTMPA** 

Position Algorithm **Synopsis:** 

```
$PSTMPA,<PosA>,<Dur>*<checksum><cr><lf>
```

**Arguments:** 

**Table 146. $PSTMPA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|PosA|Char, 2|Position Algorithm Indicator<br>Empty = none<br>LS = LMS<br>KF = Kalman Filter|
|Dur|Decimal, 3 digits|Time period in which the position has been stationary (count in seconds)|



## **Results:** 

None **Example:** 

**UM2791** - **Rev 3** 

**page 133/241** 

**UM2791 ST NMEA messages specification** 

```
$PSTMPA,KF,433*<checksum><cr><lf>
$PSTMPA, ,00*<checksum><cr><lf>
```

## **11.6.48 $PSTMSAT** 

This message is repeated for each satellite tracked and used for the calculation of a fix. The information contained in this message is a subset of the $PSTMTS message. 

## **Synopsis:** 

```
$PSTMSAT,<SatID>,<PsR>,<Freq>,<Satx>,<Saty>,<Satz>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 147. $PSTMSAT message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|SatID|Decimal, 2 digits|Satellite Number (PRN)|
|PsR|Decimal, 10 digits|Pseudo Range|
|Freq|Decimal, 8 digits|Tracking Frequency of Satellite|
|Satx|Decimal, 10 digits|Satellite Position, X-Coordinate|
|Saty|Decimal, 10 digits|Satellite Position, Y-Coordinate|
|Satz|Decimal, 10 digits|Satellite Position, Z-Coordinate|



## **Results:** 

None 

## **11.6.49 $PSTMPRES** 

Position Residual 

_Note:_ 

_$PSTMPRES and $PSTMVRES are always enabled together._ **Synopsis:** 

```
$PSTMPRES,<RMSpos>,<res1>,...,<resN>*<checksum><cr><lf>
```

N = number of tracked satellites **Arguments:** 

**Table 148. $PSTMPRES message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|RMSpos|dd.d|position “rms” residual for the fix|
|resx|dd.d|Residual of tracked satellite x<br>(Corresponds to x satellite in $GPGSA Message)|



## **Results:** 

None 

**Example:** 

```
$PSTMPRES,8.1,-0.2,-0.2,-0.1,-0.3,-0.3,-0.4,,,,,,,*2D
 $PSTMPRES,0.0,,,,,,,,,,,,,*20
```

## **11.6.50 $PSTMVRES** 

Velocity Residual 

**UM2791** - **Rev 3** 

**page 134/241** 

**UM2791 ST NMEA messages specification** 

_Note: $PSTMPRES and $PSTMVRES are always enabled together._ **Synopsis:** 

```
$PSTMPRES,<RMSvel>,<vres1>,...,<vresN>*<checksum><cr><lf>
```

N = number of tracked satellites 

**Arguments:** 

**Table 149. $PSTMVRES message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|RMSvel|dd.d|velocity “rms” residual for the fix|
|vresx|dd.d|Residual of tracked satellite x<br>(Corresponds to x satellite in $GPGSA Message)|



## **Results:** 

None 

**Example:** 

```
$PSTMVRES,0.0,0.0,0.0,0.0,,,,,,,,,,*26
```

## **11.6.51 $PSTMNOISE** 

This message contains the raw noise floor estimation for GPS and GLONASS **Synopsis:** 

```
$PSTMNOISE,<GPS_raw_NF>,<GLONASS_raw_NF>*<checksum><cr><lf>
```

**Arguments:** 

**Table 150. $PSTMNOISE message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|GPS_raw_NF|integer|Noise floor raw estimation for GPS.|
|GLONASS_raw_NF|integer|Noise floor raw estimation for GLONASS.|



**Results:** None 

## **11.6.52 $PSTMCPU** 

This message contains the real time CPU usage and the CPU speed setting. **Synopsis:** 

```
$PSTMCPU,<CPU_Usage>,-1,<CPU_Speed>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 151. $PSTMCPU message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|CPU_Usage|ddd.dd|CPU usage %|
|CPU_Speed|Decimal, 1 digit|CPU clock frequency: 52, 104, 156, 208 MHz.|



**UM2791** - **Rev 3** 

**page 135/241** 

**UM2791 ST NMEA messages specification** 

## **Results:** 

None 

## **11.6.53 $PSTMPPSDATA** 

Reports the Pulse Per Second data **Synopsis:** 

```
$PSTMPPSDATA,<on_off>,<pps_valid>,<synch_valid>,<out_mode>,<ref_time>,
<ref_constellation>,<pulse_duration>,<pulse_delay>,<gps_delay>,<glo_delay>,<bei_delay>,
<gal_delay>,<inverted_polarity>,<fix_cond>,<sat_th>,<elev_mask>,<const_mask>,<ref_sec>,
<fix_status>,<used_sats>,<gps_utc_delta_s>,<gps_utc_delta_ns>,<glonass_utc_delta_ns>,
<galileo_utc_delta_ns>,<quantization_error>,<pps_clock_freq>,
<tcxo_clock_freq>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 152. $PSTMPPSDATA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|PPS signal ON/OFF status<br>0: OFF<br>1: ON|
|pps_valid|Decimal, 1 digit|Global PPS validity flag<br>0: PPS not valid<br>1: PPS valid|
|synch_valid|Decimal, 1 digit|PPS synchronization validity<br>0: Not Valid<br>1: Valid|
|out_mode|Decimal, 1 digit|0 = PPS_OUT_MODE_ALWAYS<br>1 = PPS_OUT_MODE_ON_EVEN_SECONDS<br>2 = PPS_OUT_MODE_ON_ODD_SECONDS|
|ref_time|Decimal, 1 digit|0 = UTC<br>1 = GPS_UTC (GPS Time)<br>2 = GLONASS_UTC (GLONASS Time)<br>3 = UTC_SU<br>4 = GPS_UTC_FROM_GLONASS<br>NOTES:<br>UTC(SU) is the Soviet Union UTC, it is derived from GLONASS time applying the<br>UTC delta time downloaded from GLONASS satellites.<br>GPS_UTC_FROM_GLONASS is the GPS time derived from GLONASS time<br>applying the GPS delta time downloaded from GLONASS satellites.<br>If the software is configured to work in GLONASS only mode, UTC(SU) is identical<br>to UTC and GPS_UTC_FROM_GLONASS is identical to GPS_UTC.|
|ref_constellation|Decimal, 1 digit|0 = GPS<br>1 = GLONASS<br>NOTE: the reference constellation reports which reference time has been used for<br>the PPS generation.|
|pulse_duration|Double|Pulse duration [s]|
|pulse_delay|Decimal|Pulse delay [ns]|
|gps_delay|Decimal|GPS path RF delay [ns]|



**UM2791** - **Rev 3** 

**page 136/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|glo_delay|Decimal|GLONASS path RF delay [ns]|
|bei_delay|Decimal|BEIDOU path RF delay [ns]<br>NOTE: this parameter is always zero if Beidou constellation is not supported by the<br>hardware platform.|
|gal_delay|Decimal|GALILEO path RF delay [ns]|
|inverted_polarity|Decimal, 1 digit|Pulse polarity inversion:<br>0 = not inverted<br>1 = inverted|
|fix_cond|Decimal, 1 digit|Selected GNSS fix condition for PPS signal generation:<br>1 = NO_FIX<br>2 = 2D_FIX<br>3 = 3D_FIX|
|sat_th|Decimal|Selected minimum number of satellites for PPS signal generation.|
|elev_mask|Decimal|Selected minimum satellite elevation for time correction.|
|const_mask|Decimal|Selected constellations for time correction.|
|ref_sec|Decimal, 2 digits|Second at which the reported PPS data is applied. According to the reference time<br>configuration it could be a UTC or a GPS or a GLONASS time second.|
|fix_status|Decimal, 1 digit|GNSS position fix status when the time has been corrected.|
|used_sats|Decimal|Used satellites for time correction.|
|gps_utc_delta_s|Decimal|UTC leap seconds [s]|
|gps_utc_delta_ns|Decimal|UTC – GPS delta time [ns]|
|glonass_utc_delta_ns|Decimal|UTC – GLONASS delta time [ns]|
|galileo_utc_delat_ns|Decimal|UTC – GALILEO delta time [ns]|
|quantization_error|Double<br>(scientific<br>notation format)|Quantization error [s].|
|pps_clock_freq|Double, 2<br>fractional digits|PPS clock frequency [Hz]|
|tcxo_clock_freq|Double, 2<br>fractional digits|TCXO clock frequency [Hz]|



## **Results:** 

None 

## **11.6.54 $PSTMPOSHOLD** 

Reports the Position Hold status and position. 

## **Synopsis:** 

```
$PSTMPOSHOLD,<on_off>,<Lat>,<N/S>,<Long>,<E/W>,<Alt>*<checksum><cr><lf>
```

**Arguments:** 

## **Table 153. $PSTMPOSHOLD message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|On_off|Decimal, 1 digit|Position Hold enabling/disabling status<br>0: disabled|



**UM2791** - **Rev 3** 

**page 137/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||1: enabled|
|Lat|DDMM.MMMMM|Lat in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|N/S|“N” or “S”|Lat Direction: North or South|
|Long|DDMM.MMMMM|Long in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|E/W|“E” or “W”|Long Direction: East or West|
|Alt|Decimal, 8 digits|Height above WGS84 Elipsoid, max: 100000|



**Results:** 

None 

## **11.6.55 $PSTMTRAIMSTATUS** 

Reports the TRAIM algorithm status. 

_Note: All TRAIM related messages are enabled/disabled all together by the same mask._ **Synopsis:** 

```
$PSTMTRAIMSTATUS,<on_off>,<traim_solution>,<alarm>,<ave_error>
,<used_sats>,<removed_sats>,<ref_second>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 154. $PSTMTRAIMSTATUS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|TRAIM ON/OFF status<br>0: OFF<br>1: ON|
|traim_solution|Decimal, 1 digit|TRAIM algorithm status:<br>0 = UNDER Alarm<br>1 = OVER Alarm<br>2 = UNKNOWN|
|alarm|Decimal|Time error threshold [ns]|
|ave_error|Decimal|Average time error [ns]|
|used_sats|Decimal|Number of used satellites.|
|removed_sats|Decimal|Number of removed satellites.|
|ref_second|Decimal|Second at which the PPS signal is generated based on reported TRAIM status.|



## **Results:** 

None 

## **11.6.56 $PSTMTRAIMUSED** 

Reports the satellite used for timing correction. 

**UM2791** - **Rev 3** 

**page 138/241** 

**UM2791 ST NMEA messages specification** 

_Note: All TRAIM related messages are enabled/disabled all together by the same mask._ **Synopsis:** 

```
$PSTMTRAIMUSED,<on_off>,<used_sats>,<sat1>,…,<satN>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 155. $PSTMTRAIMUSED message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|TRAIM ON/OFF status<br>0: OFF<br>1: ON|
|used_sats|Decimal|Number of used satellites.|
|Sat1..satN|Decimal|Used satellites list.|



## **11.6.57 $PSTMTRAIMRES** 

Reports the time error residuals for satellites used for timing correction. 

_Note: All TRAIM related messages are enabled/disabled all together by the same mask._ **Synopsis:** 

```
$PSTMTRAIMRES,<on_off>,<used_sats>,<res1>,…,<resN>*<checksum><cr><lf>
```

## **Arguments:** 

## **Table 156. $PSTMTRAIMRES message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|TRAIM ON/OFF status<br>0: OFF<br>1: ON|
|used_sats|Decimal|Number of used satellites.|
|res1..resN|Decimal|Time error residuals for satellites reported in the TRAIMUSED message. Each residual refer to<br>the satellite in the same message position.|



## **11.6.58 $PSTMTRAIMREMOVED** 

Reports the satellite removed by the timing correction algorithm. 

_Note: All TRAIM related messages are enabled/disabled all together by the same mask._ 

## **Synopsis:** 

```
$PSTMTRAIMUSED,<on_off>,<removed_sats>,<sat1>,…,<satN>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 157. $PSTMTRAIMREMOVED message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|on_off|Decimal, 1 digit|TRAIM ON/OFF status<br>0: OFF<br>1: ON|



**UM2791** - **Rev 3** 

**page 139/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|removed_sats|Decimal|Number of removed satellites.|
|Sat1..satN|Decimal|Removed satellites list.|



## **11.6.59 $PSTMNAVM** 

Navigation Data Frame. 

**Synopsis:** 

```
$PSTMNAVM,<msg_id>,<prn>,<nav_frame>*<checksum><cr><lf>
```

**Arguments:** 

**Table 158. $PSTMNAVM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|msg_id|Decimal, 1 digits|Message ID (GPS = 0, GLONASS = 1, GALILEO = 3, BEIDOU = 7)|
|prn|Decimal, 3 digits|Satellite PRN (Range: depending on the constellation)|
|nav_frame|Hexadecimal, up to 80 digits|Navigation data frame (length: depending on the constellation)|



## **Details:** 

The navigation frame parameter depends on the constellation. The following table describe its meaning (see each constellation ICD document for details): 

**Table 159. Navigation frame data types** 

|**Constellation**|**Type**|**Length (bits)**|**Length (bytes)**|**Note**|
|---|---|---|---|---|
|GPS|Sub-frame|300|40 (10 words)|For each 32 bit word 30 bits are used (the 2 msb are ignored)|
|GLONASS|1 or 2 strings|85 or<br>170<br>(85+85)|11 or<br>22 (11+11 bytes)|One string for each message for strings from 1 to 5.<br>Two strings for each message for strings from 6 to 15.<br>For the first byte of each string the 3 msb are ignored and the<br>4th is always zero. The payload is 84 bits long|
|GALILEO|payload|128|16 (4 words)|Each message contains the payload from I/NAV message<br>(see Note for details)|
|BEIDOU|Sub-frame|300|40 (10 words)|For each 32 bit word 30 bits are used (the 2 msb are ignored)|



_Note:_ 

_in the above table, “word” means a 32-bit little endian encoded word, while “msb” means most significant bit(s). It means that, in a little endian architecture system, the navigation frame (converted to binary format) can be directly copied into a C 32 bit unsigned integer words array. In other words:_ 

- For GPS, the navigation frame can be copied into a C language variable defined according to the following type definition: 

## `typedef tU32 gps_subframe_t [10];` 

- For GLONASS, the navigation frame can be copied into a C language variable defined according to the following type definition: 

## `typedef tU08 glo_subframe_t [22];` 

_Note:_ 

_for strings for #1 to #5 just the first 11 bytes will be used, while for strings from #6 to #15 all 22 bytes will be used by storing two consecutive strings (e.g. strings #7 and #6). In this latter case the first sting (e.g. string #n) will be stored in the second part of the array (i.e. from byte #12 to #22), and the second string (e.g. string #n+1) will be stored in the first part of the array (i.e. from byte #1 to #11)._ 

**UM2791** - **Rev 3** 

**page 140/241** 

**UM2791 ST NMEA messages specification** 

- For GALILEO, the navigation frame can be copied in a C language variable defined according to the following type definition: 

```
typedef tU32 gal_subframe_t [4];
```

|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|•<br>Note: the GALILEO navigation frame contains the message payload, encoded according to the following<br>table:<br>**Table 160.Galileo payload, 128[bit], 32-bit packing**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|`0`|Data k 0-31 (112 bit)||||||||||||||||||||||||||||||||
|`1`|Data k 32-63 (112 bit)||||||||||||||||||||||||||||||||
|`2`|Data k 64-95 (112 bit)||||||||||||||||||||||||||||||||
|`3`|Data k 96-111 (112 bit)||||||||||||||||Data j (16 bit)||||||||||||||||



- For BEIDOU, the navigation frame can be copied in a C language variable defined according to the following type definition: 

```
typedef tU32 bds_subframe_t [10];
```

where _tU32_ is a 32 bit unsigned integer type and _tU08_ is a 8 bit unsigned integer type. 

## **Example:** 

```
$PSTMNAVM,0,4,00AFC32268A9BD26337FF43AC40B60D1B8B80018C8EE0B0330BDA238AF
711D185E1000C088790781*23
```

## **11.6.60** 

## **$PSTMKFCOV** 

This message contains the Standard Deviations for position and velocity and their split into north, east and vertical components. 

## **Synopsis:** 

```
$PSTMKFCOV,<PosStd>,<PosNcov>,<PosEcov>,<PosVcov>,
 <VelStd>,<VelNcov><VelEcov>,<VelVcov>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 161. $PSTMKFCOV message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|PosStd|ddd.d|Standard Deviation of Position in meters|
|PosNcov|ddd.d|Covariance (North/South) in m² (from Kalman Filter)|
|PosEcov|ddd.d|Covariance (East/West) in m² (from Kalman Filter)|
|PosVcov|ddd.d|Covariance (Vertical) in m² (from Kalman Filter)|
|VelStd|ddd.d|Standard Deviation of Velocity in meter/second|
|VelNcov|ddd.d|Covariance (North/South) in m²/s (from Kalman Filter)|
|VelEcov|ddd.d|Covariance (East/West) in m²/s (from Kalman Filter)|
|VelVcov|ddd.d|Covariance (Vertical) in m²/s (from Kalman Filter)|



## **Example:** 

**UM2791** - **Rev 3** 

**page 141/241** 

**UM2791 ST NMEA messages specification** 

```
 $PSTMKFCOV,8.7,50.9,25.4,150.7,0.4,0.1,0.0,0.2*49
```

## **11.6.61 $PSTMTIM** 

Time Validity. **Synopsis:** 

```
$PSTMTIM,<Tvalid>,<curr-CPU-Time>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 162. $PSTMTIM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Tvalid|ASCII|“RTC” = time read from RTC<br>“VALID” = time downloaded from satellite or corrected using position<br>“INVALID” = time is not valid|
|curr-CPU-Time|Decimal|Current CPU Time, i.e. the number of ticks since the system started to run|



## **11.6.62** 

## **$PSTMDIFF** 

Time Validity. 

## **Synopsis:** 

```
$PSTMDIFF,<ListSize>,<NCS>,
[<Sat1ID>,<Corr1Avl>,]
...
 [<SatNID>,<CorrNAvl>,]
 *<checksum><cr><lf>
```

N = number of tracked satellites 

**Arguments:** 

**Table 163. $PSTMDIFF message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ListSize|Decimal, 2 digits|Amount of visible satellites in this message (n)|
|NCS|Decimal, 2 digits|Number of corrected satellites|
|SatxID|Decimal, 2 digits|Satellite x ID (PRN)|
|CorrxAvl|Decimal|Correction available for Satellite x|



## **11.6.63 $PSTMSBAS** 

SBAS Satellite Data. 

## **Synopsis:** 

```
$PSTMSBAS,<Status>,<SatTrk>,<SatID>,<Elev>,<Azim>,
<Sig>*<checksum><cr><lf>
```

N = number of tracked satellites 

**Arguments:** 

**UM2791** - **Rev 3** 

**page 142/241** 

**UM2791 ST NMEA messages specification** 

## **Table 164. $PSTMSBAS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Status|Decimal, 1 digit|SBAS Status<br>0 = no SBAS used<br>1 = SBAS used|
|SatTrk|Decimal, 1 digit|SBAS Satellite tracked<br>0 = SBAS Satellite not tracked<br>1 = SBAS Satellite tracked, decoding is ongoing<br>2 = SBAS Satellite tracked and decoded. Differential Mode ON|
|SatID|Decimal, 3 digits|SBAS Satellite ID|
|Elev|Decimal, 2 digits|SBAS Satellite Elevation (in degrees)|
|Azim|Decimal, 3 digits|SBAS Satellite Azimuth (in degrees)|
|Sig|Decimal, 2 digits|SBAS Satellite Signal Strength CN0 (in dB)|



## **Example:** 

```
$PSTMSBAS,1,0,124,65,090,00*09
```

## **11.6.64 $PSTMSBASM** 

SBAS Frame. **Synopsis:** 

```
$PSTMSBASM,<prn><sbas_frame>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 165. $PSTMSBASM message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|prn|Decimal, 3 digits|Satellite PRN (Range: from 120 to 140)|
|sbas_frame|Hexadecimal, 64 digits|SBAS frame (250 bits + 6 padding)|



## **Example:** 

```
$PSTMSBASM,123,536A481B40D8063829C12E08704B82DFFDFFEFFF7FFBFFDFFEF06E803
7EFB440*6D
```

## **11.6.65 $PSTMNOTCHSTATUS** 

This message provide information on the Adaptive Notch Filter (ANF) status. **Synopsis:** 

```
$PSTMNOTCHSTATUS,<kfreq_now_Hz_gps>,<lock_en_gps>,<pwr_gps>,
<ovfs_gps>,<mode_gps>,<kfreq_now_Hz_gln>,<lock_en_gln>,<pwr_gln>, <ovfs_gln>,
<mode_gln>*<checksum><cr><lf>
```

## **Arguments:** 

**UM2791** - **Rev 3** 

**page 143/241** 

**UM2791 ST NMEA messages specification** 

## **Table 166. $PSTMNOTCHSTATUS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|kfreq_now_Hz_gps|Decimal, 7 digits|`Notch   frequency estimation actual value [Hz] (GPS path)`|
|lock_en_gps|Decimal, 1 digits|`Frequency   lock flag (GPS path)`|
|pwr_gps|Decimal, 5 digits|Band Pass Filter internal power estimation (GPS path)<br>[dimensionless quantity]|
|ovfs_gps|Decimal, 4 digits|Internal mask output as:<br>1000 * Notch_Removing_jammer (1/0,TRUE/FALSE)<br>+ overflow flags status (3 digits).<br>E.g: “1000” means Block enabled, with no internal overflows detected|
|mode_gps|Decimal, 1 digits|ANF mode operation (GPS path) [0 → ANF disabled;<br>1 → Always ON(Internal Use only);<br>2 → Auto insertion mode (suggested);]|
|kfreq_now_Hz_gln|Decimal, 7 digits|Notch frequency estimation actual value [Hz] (GLONASS path)|
|lock_en_gln|Decimal, 1 digits|Frequency lock flag (GLONASS path)|
|pwr_gln|Decimal, 24 digits|Band Pass Filter internal power estimation (GLONASS path) [dimensionless quantity]|
|ovfs_gln|Decimal, 4 digits|Internal mask output as:<br>1000 * Notch_Removing_jammer (1/0,TRUE/FALSE)<br>+ overflow flags status (3 digits).<br>E.g: “1000” means Block enabled, with no internal overflows detected|
|mode_gln|Decimal, 1 digits|ANF mode operation (GLONASS path) [0 → ANF disabled;<br>1 → Always ON (Internal Use only);<br>2 → Auto insertion mode(suggested);]|



## **Results:** 

- This message provides the ANF status. 

- When ANF is disabled all parameters are set to zero 

Frequency / Power values are meaningful only when Notch is locked. 

## **11.6.66 $PSTMLOWPOWERDATA** 

Reports the status of adaptive low power algorithm. 

## **Synopsis:** 

```
$PSTMLOWPOWERDATA,<low power state>,<steady state>,<RESERVED>,
```

```
<RESERVED>,<ehpe>,<RESERVED>,<ehpe_average>,<RESERVED>, <RESERVED>,
```

```
< eph const mask>,<switch constellation>,<duty cycle enable>,<duty cycle ms off>,<duty cycle
state>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 167. $PSTMLOWPOWERDATA message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|low power state|Decimal, 1 digits|Low power state indicator:<br>[0 → FULL CONST; 1 → LOW POWER STATE; 2 → EPH REFRESH]|
|steady state|Decimal, 1 digits|Steady state reached indicator|
|RESERVED|||



**UM2791** - **Rev 3** 

**page 144/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|RESERVED|||
|ehpe|dd.d [m]|Estimated Horizontal Position Error [m]|
|RESERVED|||
|ehpe_average|dd.d [m]|Estimated Horizontal Position Error Average [m]|
|RESERVED|||
|RESERVED|||
|eph const mask|Decimal, 2 digits|Bitfield of completed ephemeris download|
|switch constellation|Decimal, 1 digits|Switch constellation features indicator|
|duty cycle enable|Decimal, 1 digits|Duty cycle enable indicator|
|duty cycle ms off|Decimal, 3 digits|Duty cycle ms signal off|
|duty cycle state|Decimal, 1 digits|Duty cycle state indicator|



## **Results:** 

This message provides the adaptive low power status. In the case of dynamic low power disabled, all parameters are set to zero. 

## **11.6.67 $PSTMSTANDBYENABLE** 

Message sent in response of command $PSTMSTANDBYENABLE. 

## **Synopsis:** 

```
$PSTMSTANDBYENABLE,<status>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 168. $PSTMSTANDBYENABLE message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|status|Decimal, 1 digits|Set the standby enable status<br>0: Active Periodic mode<br>1: Periodic mode, standby allowed|



## **Result:** 

- Message sent in case of successful operation. 

## **11.6.68 $PSTMSTANDBYENABLEOK** 

Message sent in response of command $PSTMSTANDBYENABLE. 

## **Synopsis:** 

```
$PSTMSTANDBYENABLEOK*<checksum><cr><lf>
```

## **Arguments:** 

None **Result:** 

- Message sent in case of successful operation. 

## **11.6.69 $PSTMSTANDBYENABLEERROR** 

Message sent in response of command $PSTMSTANDBYENABLE. 

## **Synopsis:** 

**UM2791** - **Rev 3** 

**page 145/241** 

**UM2791 ST NMEA messages specification** 

```
$PSTMSTANDBYENABLEERROR*<checksum><cr><lf>
```

## **Arguments:** 

None 

**Result:** 

- Message sent in case of error. 

## **11.6.70 $PSTMPV** 

Provides position (Latitude, Longitude, Height), velocity (North, East, Vertical) and root square of covariance matrix values for position and velocity. 

## **Synopsis:** 

```
$PSTMPV,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<Alt>,<AltVal>,<Vel_N>,<Vel_E>,<Vel_V>,
<P_cov_N>,<P_cov_NE>,<P_cov_NV>,<P_cov_E>,<P_cov_EV>,<P_cov_V>,<V_cov_N>,<V_cov_NE>,<V_cov_NV>,
<V_cov_E>,<V_cov_EV>,<V_cov_V>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 169. $PSTMPV message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample, example: 160836.000<br>“.sss” is the fraction of seconds; it assumes non zero values when the fix rate is bigger than<br>1Hz.|
|Lat|DDMM.MMMMM|Lat in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|N/S|“N” or “S”|Lat Direction: North or South|
|Long|DDMM.MMMMM|Long in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|E/W|“E” or “W”|Long Direction: East or West|
|Alt|Decimal, 6 digits|Height above mean sea level, max: 100000m|
|Alt-Val|“M”|Height measure in “M” = meters|
|Vel_N|ddd.d|Velocity North component [m/s]|
|Vel_E|ddd.d|Velocity East component [m/s]|
|Vel_V|ddd.d|Velocity Vertical component [m/s]|
|P_cov_N|ddd.d|Position North covariance [m]|
|P_cov_NE|ddd.d|Position North-East covariance [m]|
|P_cov_NV|ddd.d|Position North-Vertical covariance [m]|
|P_cov_E|ddd.d|Position East covariance [m]|
|P_cov_EV|ddd.d|Position East-Vertical covariance [m]|
|P_cov_V|ddd.d|Position Vertical covariance [m]|
|V_cov_N|ddd.d|Velocity North covariance [m/s]|
|V_cov_NE|ddd.d|Velocity North-East covariance [m/s]|
|V_cov_NV|ddd.d|Velocity North-Vertical covariance [m/s]|



**UM2791** - **Rev 3** 

**page 146/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|V_cov_E|ddd.d|Velocity East covariance [m/s]|
|V_cov_EV|ddd.d|Velocity East-Vertical covariance [m/s]|
|V_cov_V|ddd.d|Velocity Vertical covariance [m/s]|



## **Example:** 

```
$PSTMPV,160635.000,4055.10928,N,01416.56027,E,026.96,M,0.2,0.0,0.1,22.6,
12.8,5.8,17.2,10.9,18.8,5.5,4.1,1.7,4.6,0.0,2.7*70
```

## **11.6.71 $PSTMPVRAW** 

Provides not filtered position (Latitude, Longitude, Height), not filtered velocity (North, East, Vertical) and LMS fix related info 

## **Synopsis:** 

```
$PSTMPVRAW,<Timestamp>,<Lat>,<N/S>,<Long>,<E/W>,<GPSQual>,<Sats>,<HDOP>,<Alt>,
<AltVal>,<GeoSep>,<GeoVal>,<Vel_N>,<Vel_E>,<Vel_V>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 170. $PSTMPVRAW message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Timestamp|hhmmss.sss|UTC Time of GPS Sample, example: 160836.000<br>“.sss” is the fraction of seconds; it assumes non zero values when the fix rate is bigger than<br>1Hz.|
|Lat|DDMM.MMMMM|Lat in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|N/S|“N” or “S”|Lat Direction: North or South|
|Long|DDMM.MMMMM|Long in degree:<br>DD: Degree<br>MM: Minutes<br>.MMMMM: partsMinutes|
|E/W|“E” or “W”|Long Direction: East or West|
|GPSQual|Decimal, 1digit|0 = invalid<br>1 = GPS<br>2 = DGPS|
|Sats|Decimal, 2 digits|Satellites in use: example: 8|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, max: 99.0|
|Alt|Decimal, 6 digits|Height above mean sea level, max: 100000m|
|AltVal|“M”|Reference Unit for Altitude (“M” = meters)|
|GeoSep|Decimal, 4 digits|Geoidal Separation measure in “M” = meters|
|GeoVal|“M”|Reference Unit for GeoSep (“M” = meters)|
|Vel_N|ddd.d|Velocity North component [m/s]|
|Vel_E|ddd.d|Velocity East component [m/s]|



**UM2791** - **Rev 3** 

**page 147/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Vel_V|ddd.d|Velocity Vertical component [m/s]|



## **Example:** 

```
 $PSTMPVRAW,144056.000,5131.12414,N,00005.31484,W,2,09,1.2,043.31,M,47.0,
M,-0.6,0.1,0.6*58
```

## **11.6.72** 

## **$PSTMPVQ** 

Provides position and velocity processing noise matrix values. **Synopsis:** 

```
$PSTMPVQ,<P_Q_N>,<P_Q_E>,<P_Q_V>,<Q_CLKO>,<Q_GLPD>,<V_Q_N>,<V_Q_E>,<V_Q_V>,<Q_CLKD>,
<RESERVED>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 171. $PSTMPVQ message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|P_Q_N|ddd.d|Position North processing noise [m]|
|P_Q_E|ddd.d|Position East processing noise [m]|
|P_Q_V|ddd.d|Position Vertical processing noise [m]|
|Q_CLKO|ddd.d|Clock offset processing noise [m]|
|Q_GLPD|ddd.d|Glonass path delay [m]|
|V_Q_N|ddd.d|Velocity North processing noise [m/s]|
|V_Q_E|ddd.d|Velocity East processing noise [m/s]|
|V_Q_V|ddd.d|Velocity Vertical processing noise [m/s]|
|Q_CLKD|ddd.d|Clock drift processing noise [m/s]|
|RESERVED|-|RESERVED for future use|



## **Example:** 

```
$PSTMPVQ,0.0,0.0,0.0,0.0,4.0,3.0,3.0,0.0,3.0,0.0*4A
```

## **11.6.73** 

## **$PSTMUTC** 

This message reports the UTC time, date and time offset parameters. **Synopsis:** 

```
$PSTMUTC,<utc_time>,<utc_date>,<utc_timestamp>,
<utc_offset>,<utc_offset_validity>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 172. $PSTMUTC message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|utc_time|hhmmss.sss|UTC Time of Fix, example: 160836.000<br>“.sss” is the fraction of seconds; it assumes non zero values when the fix rate is bigger<br>than 1Hz.|



**UM2791** - **Rev 3** 

**page 148/241** 

**UM2791 ST NMEA messages specification** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|utc_date|ddmmyyyy|Date of Fix : ddmmyyyy|
|utc_timestamp|Decimal|UTC time expressed as number of seconds since January 6th 1980|
|utc_offset|Decimal, 2 digits|UTC to GPS time offset [s]|
|utc_offset_validity|Decimal, 1 digit|UTC to GPS time offset validity<br>0 = NOT Valid<br>1 = Read From NVM<br>2 = Valid (downloaded from sky)|



## **Example:** 

```
$PSTMUTC,161344.000,19062012,1024157624,15,2*52
```

## **11.6.74** 

## **$PSTMERRORMSG** 

This message reports an error, its location as well as additional (and optional) parameters helpful to understand the error cause. 

## **Synopsis:** 

```
$PSTMERRORMSG,<error_code>,<param1>,…,<param6>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 173. $PSTMERRORMSG message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|error_code|Hexadecimal, 8 digits|Indicates where does the error comes from.|
|Param1 up to param6|Hexadecimal, 8 digits|Optional parameters used to understand the error. There can be 0 additional<br>parameter.|



## **Example:** 

```
$PSTMERRORMSG,01900001,11111111,11111111,cccccccc,0000dddd,eeeeeeee*26
$PSTMERRORMSG,01920003*2E
```

## **11.6.75** 

## **$PSTMGNSSINTEGRITY** 

This message is sent from Teseo-Module to the host periodically it is enabled in the message list. 

## **Synopsis:** 

```
$PSTMGNSSINTEGRITY,<type>,<pos_const_mask>,<pos_err_AtoB>,<pos_err_AtoC>,
<pos_err_BtoC>,<time_const_mask>,<time_err_AtoB>,<time_err_AtoC>,
<time_err_BtoC>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 174. $PSTMGNSSINTEGRITY message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|type|Decimal|Integrity message type (currently always 0)|
|pos_const_mask|Decimal|Position related constellation mask|
|pos_err_AtoB|Double|Position error of second active constellation in comparison to the first one as meters|
|pos_err_AtoC|Double|Position error of third active constellation in comparison to the first one as meters|



**UM2791** - **Rev 3** 

**page 149/241** 

**UM2791 ST system configuration messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|pos_err_BtoC|Double|Position error of third active constellation in comparison to the second one as meters|
|time_const_mask|Decimal|Time related constellation mask|
|time_err_AtoB|Double|Time error of second active constellation in comparison to the first one as nanoseconds|
|time_err_AtoC|Double|Time error of third active constellation in comparison to the first one as nanoseconds|
|time_err_BtoC|Double|Time error of third active constellation in comparison to the second one as nanoseconds|



## **11.6.76** 

## **$PSTMGPSSUSPENDED** 

Message sent in response of command $PSTMGPSSUSPEND 

## **Synopsis:** 

```
$PSTMGPSSUSPENDED*<checksum><cr><lf>
```

## **Arguments:** 

None. 

## **Results:** 

- Message sent in case of no error. 

## **11.6.77 $PSTMGETUCODEOK** 

Message sent in response of command $PSTMGETUCODE 

## **Synopsis:** 

```
$PSTMGETUCODEOK,<unique_code>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 175. $PSTMGETUCODEOK message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|unique_code|Char, 32 bytes|The Unique ID written in the secondary boots|



## **Results:** 

- Message sent in case of successful operation. 

## **11.6.78** 

## **$PSTMGETUCODEERROR** 

Message sent in response of command **Error! Reference source not found.** 

## **Synopsis:** 

```
$PSTMSETUCODEERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of errors. 

## **11.7 ST system configuration messages** 

## **11.7.1 $PSTMSETPAROK** 

Message sent in response of command $PSTMSETPAR 

## **Synopsis:** 

**UM2791** - **Rev 3** 

**page 150/241** 

**UM2791** 

**ST system configuration messages** 

```
$PSTMSETPAROK ,<ConfigBlock><ID>*<checksum><cr><lf>
```

**Arguments:** 

**Table 176. $PSTMSETPAROK message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ConfigBlock|Decima1,1 digit|Indicates one of configuration blocks:<br>1=Current Configuration,<br>2 = Default Configuration,<br>3 = NVM Stored configuration.|
|ID|Decimal, 3 digits|ID - Identifier|



## **Results:** 

- Message sent in case of successful operation. 

## **11.7.2** 

## **$PSTMSETPARERROR** 

Message sent in response of command $PSTMSETPAR 

## **Synopsis:** 

```
$PSTMSETPARERROR*<checksum><cr><lf>
```

**Argument:** None **Results:** 

- Message sent in case of error. 

## **11.7.3 $PSTMRESTOREPAROK** 

Message sent in response of command $PSTMRESTOREPAR 

## **Synopsis:** 

```
$PSTMRESTOREPAROK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

Message sent in case of successful operation. 

## **11.7.4 $PSTMRESTOREPARERROR** 

Message sent in response of command $PSTMRESTOREPAR 

## **Synopsis:** 

```
$PSTMRESTOREPARERROR*<checksum><cr><lf>
```

**Arguments:** 

None. 

**Results:** 

Message sent in case of error. 

## **11.7.5 $PSTMSAVEPAROK** 

Message sent in response of command $PSTMSAVEPAR 

**Synopsis:** 

**UM2791** - **Rev 3** 

**page 151/241** 

**UM2791** 

**ST system configuration messages** 

```
$PSTMSAVEPAROK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.6** 

## **$PSTMSAVEPARERROR** 

Message sent in response of command $PSTMSAVEPAR 

## **Synopsis:** 

```
$PSTMSAVEPARERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.7.7** 

## **$PSTMSETPAR** 

Message sent in response of command $PSTMGETPAR **Synopsis:** 

```
$PSTMSETPAR,<ConfigBlock><ID>,<value>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 177. $PSTMSETPAR message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ConfigBlock|Decima1, 1 digit|Indicates one of configuration blocks:<br>1 = Current Configuration,<br>2 = Default Configuration,<br>3 = NVM Stored configuration.|
|ID|Decimal, 3 digits|ID - Identifier|
|value|Hexadecimal or Decimal|The value of returned parameter. According to the parameter type it could be<br>expressed in hexadecimal format (in case parameter is integer) or decimal format (in<br>case the parameter is floating).|



## **11.7.8 $PSTMGETPARERROR** 

Message sent in response of command $PSTMGETPAR 

## **Synopsis:** 

```
$PSTMGETPARERROR*<checksum><cr><lf>
```

**Arguments:** 

None. 

**Results:** 

In case of errors, the error message is returned. 

## **11.7.9** 

## **$PSTMCFGPORTOK** 

Message sent in response of command $PSTMCFGPORT 

## **Synopsis:** 

**UM2791** - **Rev 3** 

**page 152/241** 

**UM2791** 

**ST system configuration messages** 

```
$PSTMCFGPORTOK*<checksum><cr><lf>
```

**Arguments:** 

None. 

**Results:** 

Message sent in case of successful operation. 

## **11.7.10** 

## **$PSTMCFGPORTERROR** 

Message sent in response of command $PSTMCFGPORT 

## **Synopsis:** 

## `$PSTMCFGPORTERROR*<checksum><cr><lf>` 

**Arguments:** 

None. 

**Results:** 

Message sent in case of error. 

## **11.7.11** 

## **$PSTMCFGMSGLOK** 

Message sent in response of command $PSTMCFGMSGL 

## **Synopsis:** 

```
$PSTMCFGMSGLOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.12 $PSTMCFGMSGLERROR** 

Message sent in response of command $PSTMCFGMSGL 

## **Synopsis:** 

```
$PSTMCFGMSGLERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. **Results:** 

- Message sent in case of error. 

## **11.7.13 $PSTMCFGGNSSOK** 

Message sent in response of command $PSTMCFGGNSS 

## **Synopsis:** 

```
$PSTMCFGGNSSOKOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.14 $PSTMCFGGNSSERROR** 

Message sent in response of command $PSTMCFGGNSS 

**UM2791** - **Rev 3** 

**page 153/241** 

**UM2791 ST system configuration messages** 

## **Synopsis:** 

```
$PSTMCFGGNSSERROR*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

- Message sent in case of error. 

## **11.7.15** 

## **$PSTMCFGSBASOK** 

Message sent in response of command $PSTMCFGSBAS 

## **Synopsis:** 

```
$PSTMCFGSBASOK*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

- Message sent in case of successful operation. 

## **11.7.16** 

## **$PSTMCFGSBASERROR** 

Message sent in response of command $PSTMCFGSBAS 

## **Synopsis:** 

```
$PSTMCFGSBASERROR*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

- Message sent in case of error. 

## **11.7.17** 

## **$PSTMCFGPPSGENOK** 

Message sent in response of command $PSTMCFGPPSGEN 

## **Synopsis:** 

```
$PSTMCFGPPSGENOK*<checksum><cr><lf>
```

## **Arguments:** 

None. **Results:** 

- Message sent in case of successful operation. 

## **11.7.18 $PSTMCFGPPSGENERROR** 

Message sent in response of command $PSTMCFGPPSGEN 

## **Synopsis:** 

```
$PSTMCFGPPSGENERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

**UM2791** - **Rev 3** 

**page 154/241** 

**UM2791 ST system configuration messages** 

## **11.7.19 $PSTMCFGPPSSATOK** Message sent in response of command $PSTMCFGPPSSAT **Synopsis:** 

## `$PSTMCFGPPSSATOK*<checksum><cr><lf>` **Arguments:** None. **Results:** Message sent in case of successful operation. 

## **11.7.20 $PSTMCFGPPSSATERROR** Message sent in response of command $$PSTMCFGPPSSAT **Synopsis:** `$PSTMCFGPPSSATERROR*<checksum><cr><lf>` **Arguments:** None. **Results:** • Message sent in case of error. **11.7.21 $PSTMCFGPPSPULOK** Message sent in response of command $PSTMCFGPPSPUL **Synopsis:** `$PSTMCFGPPSPULOK*<checksum><cr><lf>` **Arguments:** None. **Results:** • Message sent in case of successful operation. **11.7.22 $PSTMCFGPPSPULERROR** Message sent in response of command $PSTMCFGPPSPUL 

## **Synopsis:** 

```
$PSTMCFGPPSPULERROR*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

- Message sent in case of error. 

## **11.7.23 $PSTMCFGPOSHOLDOK** 

Message sent in response of command $PSTMCFGPOSHOLD 

## **Synopsis:** 

```
$PSTMCFGPOSHOLDOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

**UM2791** - **Rev 3** 

**page 155/241** 

**UM2791** 

**ST system configuration messages** 

- Message sent in case of successful operation. 

## **11.7.24 $PSTMCFGPOSHOLDERROR** 

Message sent in response of command $PSTMCFGPOSHOLD 

## **Synopsis:** 

```
$PSTMCFGPOSHOLDERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

Message sent in case of error. 

## **11.7.25 $PSTMCFGTRAIMOK** 

Message sent in response of command $PSTMCFGTRAIM 

## **Synopsis:** 

```
$PSTMCFGTRAIMOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

Message sent in case of successful operation. 

## **11.7.26 $PSTMCFGTRAIMERROR** 

Message sent in response of command $PSTMCFGTRAIM 

## **Synopsis:** 

```
$PSTMCFGTRAIMERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

Message sent in case of error. 

## **11.7.27 $PSTMCFGSATCOMPOK** 

Message sent in response of command $PSTMCFGSATCOMP 

## **Synopsis:** 

```
$PSTMCFGSATCOMPOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.28 $PSTMCFGSATCOMERROR** 

Message sent in response of command $PSTMCFGSATCOMP 

## **Synopsis:** 

```
$PSTMCFGSATCOMPERROR*<checksum><cr><lf>
```

**Arguments:** 

**UM2791** - **Rev 3** 

**page 156/241** 

**UM2791 ST system configuration messages** 

None. 

## **Results:** 

Message sent in case of error. 

## **11.7.29** 

## **$PSTMCFGLPAOK** 

Message sent in response of command $PSTMCFGLPA 

## **Synopsis:** 

```
$PSTMCFGLPAOK*<checksum><cr><lf>
```

## **Arguments:** 

## **Results:** 

- Message sent in case of successful operation. 

## **11.7.30 $PSTMCFGLPAERROR** 

Message sent in response of command $PSTMCFGLPA 

## **Synopsis:** 

```
$PSTMCFGLPAERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.7.31 $PSTMCFGAGPSOK** 

Message sent in response of command $PSTMCFGAGPS 

## **Synopsis:** 

```
$PSTMCFGAGPSOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

Message sent in case of successful operation. 

## **11.7.32 $PSTMCFGAGPSERROR** 

Message sent in response of command $PSTMCFGAGPS 

## **Synopsis:** 

```
$PSTMCFGAGPSERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.7.33 $PSTMCFGAJMOK** 

Message sent in response of command $PSTMCFGAJM 

## **Synopsis:** 

```
$PSTMCFGAJMOK*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 157/241** 

**UM2791 ST system configuration messages** 

**Arguments:** None. 

**Results:** 

Message sent in case of successful operation. 

## **11.7.34 $PSTMCFGAJMERROR** 

Message sent in response of command $PSTMCFGAJM 

## **Synopsis:** 

```
$PSTMCFGAJMERROR*<checksum><cr><lf>
```

**Arguments:** None. 

**Results:** 

- Message sent in case of error. 

## **11.7.35 $PSTMCFGODOOK** 

Message sent in response of command $PSTMCFGODO 

## **Synopsis:** 

```
$PSTMCFGODOOK*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

Message sent in case of successful operation. 

## **11.7.36 $PSTMCFGODOERROR** 

Message sent in response of command $PSTMCFGODO 

## **Synopsis:** 

```
$PSTMCFGODOERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. **Results:** 

- Message sent in case of error. 

## **11.7.37 $PSTMCFGLOGOK** 

Message sent in response of command $PSTMCFGLOG 

## **Synopsis:** 

```
$PSTMCFGLOGOK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.38 $PSTMCFGLOGERROR** 

Message sent in response of command $PSTMCFGLOG 

**Synopsis:** 

**UM2791** - **Rev 3** 

**page 158/241** 

**UM2791** 

**ST system configuration messages** 

```
$PSTMCFGLOGERROR*<checksum><cr><lf>
```

**Arguments:** None. 

**Results:** 

Message sent in case of error. 

## **11.7.39 $PSTMCFGGEOFENCEOK** 

Message sent in response of command $PSTMCFGGEOFENCE 

## **Synopsis:** 

```
$PSTMCFGGEOFENCEOK*<checksum><cr><lf>
```

**Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.40 $PSTMCFGGEOFENCEERROR** 

Message sent in response of command $PSTMCFGGEOFENCE 

## **Synopsis:** 

```
$PSTMCFGGEOFENCEERROR*<checksum><cr><lf>
```

**Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.7.41 $PSTMCFGGEOCIROK** 

Message sent in response of command $PSTMCFGGEOCIR 

## **Synopsis:** 

```
$PSTMCFGGEOCIROK*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of successful operation. 

## **11.7.42 $PSTMCFGGEOCIRERROR** 

Message sent in response of command $PSTMCFGGEOCIR 

## **Synopsis:** 

```
$PSTMCFGGEOCIRERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of error. 

## **11.7.43 $PSTMCFGCONSTOK** 

Message sent in response of command $PSTMCFGCONST 

**UM2791** - **Rev 3** 

**page 159/241** 

**UM2791 ST system configuration messages** 

||**Synopsis:**|
|---|---|
||`$PSTMCFGCONSTOK*<checksum><cr><lf>`|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of successful operation.|
|**11.7.44**|**$PSTMCFGCONSTERROR**|
||Message sent in response of command $PSTMCFGCONST|
||**Synopsis:**|
||$PSTMCFGCONSTERROR*<checksum><cr><lf>|
||**Arguments:**|
||None.|
||**Results:**|
||•<br>Message sent in case of error.|
|**11.7.45**|**$PSTMCFGTHGNSSOK**|
||Message sent in response of command $PSTMCFGTHGNSS|
||**Synopsis**:|
||`$PSTMCFGTHGNSSOK*<checksum><cr><lf>`|
||**Arguments**:|
||None.|
||**Results**:|
||•<br>Message sent in case of successful operation.|
|**11.7.46**|**$PSTMCFGTHGNSSERROR**|
||Message sent in response of command $PSTMCFGTHGNSS|
||**Synopsis**:|
||`$PSTMCFGTDATAOK*<checksum><cr><lf>`|
||**Arguments**:|
||None.|
||**Results**:|
||Message sent in case of error.|
|**11.7.47**|**$PSTMCFGTDATAOK**|
||Message sent in response of command $PSTMCFGTDATA|
||**Synopsis**:|



`$PSTMCFGTDATAOK*<checksum><cr><lf>` **Arguments** : None. **Results** : Message sent in case of successful operation. 

**UM2791** - **Rev 3** 

**page 160/241** 

**UM2791 Autonomous AGNSS NMEA messages** 

## **11.7.48 $PSTMCFGTDATAERROR** 

Message sent in response of command $PSTMCFGTDATA 

**Synopsis** : 

## `$PSTMCFGTDATAERROR*<checksum><cr><lf>` 

**Arguments** : None. 

**Results** : 

Message sent in case of error. 

## **11.8 Autonomous AGNSS NMEA messages** 

## **11.8.1 $PSTMPOLSTARTED** 

Message sent in response to commands $PSTMSTAGPSONOFF 

**Synopsis:** 

```
$PSTMPOLSTARTED*<checksum><cr><lf>
```

**Arguments:** None 

**Results:** 

- Message sent if the engine has been started 

**11.8.2 $PSTMPOLSUSPENDED** 

Message sent in response to commands $PSTMSTAGPSONOFF 

## **Synopsis:** 

```
$PSTMTPOLSUSPENDED*<checksum><cr><lf>
```

**Arguments:** 

None 

## **Results:** 

- Message sent if the engine has been suspended 

## **11.8.3 $PSTMPOLONOFFERROR** 

Message sent in response to commands $PSTMSTAGPSONOFF 

## **Synopsis:** 

```
$PSTMTPOLONOFFERROR*<checksum><cr><lf>
```

## **Arguments:** 

None 

**Results:** 

- Message sent in case of error 

## **11.8.4 $PSTMSTAGPSINVALIDATEOK** 

Message sent in response to commands $PSTMSTAGPSINVALIDATE 

## **Synopsis:** 

```
$PSTMSTAGPSINVALIDATEOK*<checksum><cr><lf>
```

**Arguments:** 

**UM2791** - **Rev 3** 

**page 161/241** 

**UM2791 Autonomous AGNSS NMEA messages** 

None 

## **Results:** 

Message sent in case of successful operation. 

## **11.8.5 $PSTMSTAGPSINVALIDATEERROR** 

Message sent in response to commands $PSTMSTAGPSINVALIDATE 

## **Synopsis:** 

## `$PSTMSTAGPSINVALIDATEERROR*<checksum><cr><lf>` 

## **Arguments:** 

None 

## **Results:** 

- Message sent in case of error 

## **11.8.6 $PSTMAGPSSTATUS** 

Message sent in response to commands $PSTMGETAGPSSTATUS 

## **Synopsis:** 

```
$PSTMGETAGPSSTATUS,<status>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 178. $PSTMAGPSSSTATUS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|status|Decimal, 1 digits|0 = the ST-AGNSS processing is completed.<br>Any number different from zero on means that the ST-AGNSS processing is ongoing and so<br>the ephemeris prediction data has been not completely generated.|



## **Results:** 

- Message return the ST-AGNSS status 

## **11.8.7 $PSTMSTAGPSSETCONSTMASKOK** 

Message sent in response to commands $PSTMSTAGPSSETCONSTMASK **Synopsis:** 

```
$PSTMSTAGPSSETCONSTMASKOK,<constellation_mask>*<checksum><cr><lf>
```

**Arguments:** 

**Table 179. $PSTMSTAGPSSETCONSTMASKOK message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Constellation_mask|Decimal, 1<br>digits|It is a bit mask where each bit enable/disable a specific constellation independently by<br>the others:<br>bit 0: GPS constellation enabling/disabling<br>bit 1: GLONASS constellation enabling/disabling<br>bit 3: GALILEO constellation enabling/disabling<br>bit 7: BEIDOU constellation enabling/disabling|



## **Results:** 

**UM2791** - **Rev 3** 

**page 162/241** 

**UM2791 Autonomous AGNSS NMEA messages** 

- Message sent in case of successful operation 

## **11.8.8** 

## **$PSTMSTAGPSSETCONSTMASKERROR** 

Message sent in response to commands $PSTMSTAGPSSETCONSTMASK 

## **Synopsis:** 

```
$PSTMSTAGPSSETCONSTMASKERROR*<checksum><cr><lf>
```

## **Arguments:** 

None 

## **Results:** 

- Message sent in case of error 

## **11.8.9 $PSTMAGPS** 

This message has the same syntax as standard NMEA GSA message. Each parameter in the satellites PRN fields is an integer number that reports the satellite PRN and, in case a satellite is using a predicted ephemeris, it also reports the age of predicted ephemeris available for that satellite. 

They are generated using the formula: 

## `satID + 32 * STAGPS_AGE_DAYS` 

where `STAGPS_AGE_DAYS` is the number of days from current time back to the most recent ephemeris used for ST-AGNSS predictions. If a satellite has no predicted ephemeris (STAGPS_AGE_DAYS = 0) the satellite parameter, reported in the sentence, is exactly the satellite PRN. 

**Table 180. $PSTMAGPS ephemeris aging description** 

|**`STAGPS_AGE_DAYS`**|**Ephemeris aging description**|
|---|---|
|1|Latest ephemeris has been downloaded from 0 up to 24 hours in the past|
|2|Latest ephemeris has been downloaded from 24 up to 48 hours in the past|
|3|Latest ephemeris has been downloaded from 48 up to 72 hours in the past|
|4|Latest ephemeris has been downloaded from 72 up to 96 hours in the past|
|5|Latest ephemeris has been downloaded from 96 up to 120 hours in the past|



This message could be used to replace the standard GSA when ST-AGNSS is enabled. If ST-AGNSS is not enabled, it behaves in the same way as NMEA GSA message. 

NMEA message list bitmask: 0x10000000 – This message is not enabled by default 

## **Synopsis:** 

```
$PSTMAGPS,<Mode>,<CurrentMode>,[<SatPRN1>],...,[<SatPRNN>],<PDOP>,<HDOP>,
<VDOP>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 181. $PSTMAGPS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Mode|“M” or “A”|Operating Mode: M = Manual, A = Auto (2D/3D)|
|CurrentMode|Decimal, 1 digit|Current Mode:<br>1 = no FIX available<br>2 = 2D FIX<br>3 = 3D FIX|
|SatPRN1...N|Decimal, 2 digits|Satellites list used in position FIX (max N 12)|



**UM2791** - **Rev 3** 

**page 163/241** 

**UM2791 Autonomous AGNSS NMEA messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|PDOP|Decimal, 3 digits|Position Dilution of Precision, from 0.0 to 99.0|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, from 0.0 to 99.0|
|VDOP|Decimal, 3 digits|Vertical Dilution of Precision, from 0.0 to 99.0|



## **11.8.10 $PSTMAGLO** 

This message has the same syntax as standard NMEA GSA message. Each parameter in the satellites PRN fields is an integer number that reports the satellite PRN and, in case a satellite is using a predicted ephemeris, it also reports the age of predicted ephemeris available for that satellite. They are generated using the formula: `satID + 32 * STAGPS_AGE_DAYS` 

where `STAGPS_AGE_DAYS` is the number of days from current time back to the most recent ephemeris used for ST-AGNSS predictions. If a satellite has no predicted ephemeris (STAGPS_AGE_DAYS = 0) the satellite parameter, reported in the sentence, is exactly the satellite PRN. 

**Table 182. $PSTMAGLO ephemeris aging description** 

|**`STAGPS_AGE_DAYS`**|**Ephemeris aging description**|
|---|---|
|1|Latest ephemeris has been downloaded from 0 up to 24 hours in the past|
|2|Latest ephemeris has been downloaded from 24 up to 48 hours in the past|
|3|Latest ephemeris has been downloaded from 48 up to 72 hours in the past|
|4|Latest ephemeris has been downloaded from 72 up to 96 hours in the past|
|5|Latest ephemeris has been downloaded from 96 up to 120 hours in the past|



This message could be used to replace the standard GSA when ST-AGNSS is enabled. If ST-AGNSS is not enabled, it behaves in the same way as NMEA GSA message. 

NMEA message list bitmask: 0x10000000 – This message is not enabled by default 

## **Synopsis:** 

```
$PSTMAGLO,<Mode>,<CurrentMode>,[<SatPRN1>],...,[<SatPRNN>],<PDOP>,<HDOP>,
<VDOP>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 183. $PSTMAGLO message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Mode|“M” or “A”|Operating Mode: M = Manual, A = Auto (2D/3D)|
|CurrentMode|Decimal, 1 digit|Current Mode:<br>1 = no FIX available<br>2 = 2D FIX<br>3 = 3D FIX|
|SatPRN1...N|Decimal, 2 digits|Satellites list used in position FIX (max N 12)|
|PDOP|Decimal, 3 digits|Position Dilution of Precision, from 0.0 to 99.0|
|HDOP|Decimal, 3 digits|Horizontal Dilution of Precision, from 0.0 to 99.0|
|VDOP|Decimal, 3 digits|Vertical Dilution of Precision, from 0.0 to 99.0|



**UM2791** - **Rev 3** 

**page 164/241** 

**UM2791 Real Time AGNSS NMEA messages** 

## **11.9 Real Time AGNSS NMEA messages** 

## **11.9.1 $PSTMSTAGPS8PASSRTN** 

Message sent in response of command $PSTMSTAGPS8PASSGEN. 

## **Synopsis:** 

```
$PSTMSTAGPS8PASSRTN,<DevID>,<Password>*<checksum><cr><lf>
```

**Arguments:** 

**Table 184. $PSTMSTAGPS8PASSRTN message field description** 

|**Parameter**|**Description**|
|---|---|
|_<DevID>_|Unique Device ID|
|_<Password>_|41-character ASCII password.|
|**Results:**<br>None||



## **11.10 Dead reckoning NMEA Messages 11.10.1 $PSTMDRCALCTLTOK** Message sent in response of command $PSTMDRCALCTLT **Synopsis:** `$PSTMDRCALCTLTOK*<checksum><cr><lf>` **Arguments:** None. **Results:** • Message sent in case of successful operation. **11.10.2 $PSTMDRCALCTLTERROR** Message sent in response of command $PSTMDRCALCTLT 

## **Synopsis:** 

```
$PSTMDRCALCTLTERROR*<checksum><cr><lf>
```

## **Arguments:** None. **Results:** 

- Message sent in case of error. 

## **11.10.3 $PSTMDRNVMSAVEOK** 

Message sent in response of command $PSTMDRNVMSAVE 

## **Synopsis:** 

## `$PSTMDRNVMSAVEOK*<checksum><cr><lf>` 

**Arguments:** None. **Results:** 

**UM2791** - **Rev 3** 

**page 165/241** 

**UM2791 Dead reckoning NMEA Messages** 

Message sent in case of successful operation. 

## **11.10.4 $PSTMDRNVMSAVEERROR** 

Message sent in response of command $PSTMDRNVMSAVE 

## **Synopsis:** 

```
$PSTMDRNVMSAVEERROR*<checksum><cr><lf>
```

**Arguments:** None. **Results:** 

- Message sent in case of error. 

## **$PSTMIMUSELFTESTCMDOK** 

## **11.10.5 $PSTMIMUSELFTESTCMDOK** Message sent in response of command $PSTMIMUSELFTESTCMD **Synopsis:** `$PSTMIMUSELFTESTCMDOK*<checksum><cr><lf>` **Arguments:** None. **Results:** • Message sent in case of successful operation. **11.10.6 $PSTMIMUSELFTESTCMDKO** 

Message sent in response of command $PSTMIMUSELFTESTCMD 

## **Synopsis:** 

```
$PSTMIMUSELFTESTCMDKO*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of failing operation. 

## **11.10.7 $PSTMIMUSELFTESTCMDERROR** 

Message sent in response of command $PSTMIMUSELFTESTCMD 

## **Synopsis:** 

```
$PSTMIMUSELFTESTCMDERROR*<checksum><cr><lf>
```

## **Arguments:** 

None. 

**Results:** 

- Message sent in case of command error or system not ready. 

## **11.10.8 $PSTMDRSENMSG** 

This is a family of messages reporting sensor data. Depending on the specific ID, the message can contain information related to a specific sensor. 

NMEA message list bitmask (64 bits): 1000 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRSENMSG,<message_id>,<data…>*<checksum><cr><lf>
```

**UM2791** - **Rev 3** 

**page 166/241** 

**UM2791 Dead reckoning NMEA Messages** 

## **Arguments:** 

**Table 185. $PSTMDRSENMSG message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Message_id|Decimal, 2 digits|Specify the message id|
|data||Data dependent on message_id|



## **Results:** 

- This message provides Dead Reckoning sensor data at the Dead Reckoning sampling rate. 

## **$PSTMDRSENMSG,1** 

## **Synopsis:** 

```
$PSTMDRSENMSG,1,<cpu timestamp><odometer>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 186. $PSTMDRSENMSG message field description when ID = 1** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Message id|Decimal, 2 digits|data type|
|cpu timestamp|Decimal, 10 digits|microseconds|
|odometer|Decimal, 5 digits|unsigned odometer count|



## **$PSTMDRSENMSG,2** 

## **Synopsis:** 

```
$PSTMDRSENMSG,2,<cpu timestamp>,<reverse>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 187. $PSTMDRSENMSG message field description when ID = 2** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Message id|Decimal, 2 digits|data type|
|cpu timestamp|Decimal, 10 digits|microseconds|
|reverse|Enum|•<br>0: forward<br>•<br>1: reverse|



## **$PSTMDRSENMSG,14** 

## **Synopsis:** 

```
$PSTMDRSENMSG,14,<cpu timestamp>,<vehicle speed>*<checksum><cr><lf>
```

**Arguments:** 

**Table 188. $PSTMDRSENMSG message field description when ID = 14** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Message id|Decimal, 2 digits|data type|



**UM2791** - **Rev 3** 

**page 167/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cpu timestamp|Decimal, 10 digits|microseconds|
|Vehicle speed|Decimal, 5 digits|1 Kph resolution|



## **$PSTMDRSENMSG,3** 

Odometer and reverse data (only on Teseo-ModuleDA) 

## **Synopsis:** 

```
$PSTMDRSENMSG,3,<cpu timestamp>,<odometer>,<reverse>
*<checksum><cr><lf>
```

## **Arguments:** 

**Table 189. $PSTMDRSENMSG message field description when ID = 3** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Message id|Decimal, 2 digits|data type|
|cpu timestamp|Decimal, 10 digits|microseconds|
|odometer|Decimal, 5 digits|Unsigned odometer count|
|reverse|Enum|•<br>0: forward<br>•<br>1: reverse|



## **$PSTMDRSENMSG,30** 

Accelerations from 3 digital axes accelerometer. 

## **Synopsis:** 

```
$PSTMDRSENMSG,30,<cpu timestamp>,<raw_x>,<raw_y>,<raw_z>
*<checksum><cr><lf>
```

## **Arguments:** 

**Table 190. $PSTMDRSENMSG message field description when ID = 30** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cpu timestamp|Decimal, 10 digits|microseconds|
|raw_x|Decimal, 5 digits|Raw signed 16 bit X-axis acceleration|
|raw_y|Decimal, 5 digits|Raw signed 16 bit Y-axis acceleration|
|raw_z|Decimal, 5 digits|Raw signed 16 bit Z-axis acceleration|



## **$PSTMDRSENMSG,31** 

Angular rates from 3 digital axes gyroscopes. **Synopsis:** 

```
$PSTMDRSENMSG,31,<cpu timestamp>,<raw_x>,<raw_y>,<raw_z>
*<checksum><cr><lf>
```

## **Arguments:** 

**UM2791** - **Rev 3** 

**page 168/241** 

**UM2791 Dead reckoning NMEA Messages** 

**Table 191. $PSTMDRSENMSG message field description when ID = 31** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cpu timestamp|Decimal, 10 digits|microseconds|
|raw_x|Decimal, 5 digits|Raw signed 16 bit X-axis angular rate|
|raw_y|Decimal, 5 digits|Raw signed 16 bit Y-axis angular rate|
|raw_z|Decimal, 5 digits|Raw signed 16 bit Z-axis angular rate|



## **$PSTMDRSENMSG,32** 

Air pressure from 3 digital barometer. 

## **Synopsis:** 

```
$PSTMDRSENMSG,32,<cpu timestamp>,<raw_pressure>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 192. $PSTMDRSENMSG message field description when ID = 32** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cpu timestamp|Decimal, 10 digits|microseconds|
|raw_pressure|Decimal, 10 digits|Raw unsigned 32 bit.<br>This is the pressure value (hPa) * 4096|



## **11.10.9 $PSTMDRSTATE** 

Reports the current relevant values for Dead Reckoning navigation and calibration estimates. NMEA message list bitmask (64 bits): 0400 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRSTATE,<cpu timestamp>,<lat>,<lon>,<heading>,<speed>,
<gyro_offset>,<gyro_gain>,<odo_scale>,<gyro_ovst>,<acc_offset>,<height>*
<checksum><cr><lf>
```

## **Arguments:** 

**Table 193. $PSTMDRSTATE message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|cpu timestamp|Decimal, 10 digits|microseconds|
|lat|Double, 5 significant digits|Decimal degrees|
|lon|Double, 5 significant digits|Decimal degrees|
|heading|Double, 5 digits|Degrees, -180 to +180|
|speed|Double, 5 digits|Meters/second|
|gyro_offset|Double, 4 significant digits|Volts|
|gyro_gain|Double, 4 significant digits|(Radians/s)/Volt|
|odo_scale|Double, 5 significant digits|Meters/pulse|
|gyro_ovst|Double, 6 significant digits|Volt/°C|
|acc_offset|Double, 6 significant digits|g|
|height|Double, 1 significant digits|Meters|



**UM2791** - **Rev 3** 

**page 169/241** 

**UM2791 Dead reckoning NMEA Messages** 

## **Results:** 

This message is provided at 1 Hz. 

## **11.10.10 $PSTMDRGPS** 

Reports GNSS fix and quality metrics. 

NMEA message list bitmask (64 bits): 0100 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRGPS,<lat>,<lon>,<vn>,<ve>,<pdop>,<hdop>,<vdop>,
<rms_pos_residual>,<rms_vel_residual>,<vv>,<height>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 194. $PSTMDRGPS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|lat|Double, 9 significant digits|Decimal degrees|
|lon|Double, 9 significant digits|Decimal degrees|
|vn|Double, 5 significant digits|Velocity’s north vector component, in meters/second|
|ve|Double, 5 significant digits|Velocity’s east vector component, in meters/second|
|pdop|Double, 5 significant digits|Position dilution of precision|
|hdop|Double, 5 significant digits|Horizontal dilution of precision|
|vdop|Double, 5 significant digits|Vertical dilution of precision|
|Rms_pos_residual|Double, 5 significant digits|Meters|
|Rms_vel_residual|Double, 5 significant digits|Meters|
|vv|Double, 5 significant digits|Velocity’s vertical vector component, in meters/second|
|height|Double, 1 significant digits|Meters|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.11 $PSTMDRSTEP** 

Reports integrated values and averages for Dead Reckoning sensors’ samples between two consecutive GNSS fixes, essentially for that last 1 second. This is useful for assessing the odometer count incremented as expected during that second, the sample count is as expected, the sample delta times added up to approximately 1 second, and the average gyro voltage is reasonable. 

NMEA message list bitmask (64 bits): 0100 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRSTEP,<sample_count>,<ave_gyro_volts>,<gyro_noise>,<tot_odo_step>,
<delta odo_count>,<delta cputime>,<delta cputime2>,
<valid_odo>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 195. $PSTMDRSTEP message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Sample_count|Decimal, 2 digits|Should be 15, when sampling at 15Hz|
|Ave_gyro_volts|Double, 5 significant digits|Volts|



**UM2791** - **Rev 3** 

**page 170/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Gyro noise|Double, 5 significant digits|Gyro voltage variation|
|Tot_odo_step|Decimal, 5 digits|Total odo count delta for that 1 second|
|Delta odo_count|Decimal, 5 digits|Total odo count delta for that 1 second|
|Delta cpu_time|Double, 3 significant digits|In seconds, of time between 1stand last Dead Reckoning sample taken<br>between the last 2 GNSS fixes|
|Delta cpu_time|Double, 3 significant digits|In seconds, of time between 1stand last Dead Reckoning sample taken<br>between the last 2 GNSS fixes|
|Valid_odo|Boolean|1 = valid odometer|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.12 $PSTMDRCONFID** 

Reports standard deviations for navigation and calibration parameters.. NMEA message list bitmask (64 bits): 4000 0000 0000 0000 

## **Synopsis:** 

## $PSTMDRCONFID 

```
<lat_std_dev>,<lon_std_dev>,<heading_std_dev>,gyro_gain_std_dev>,
<gyro_offset_std_dev>,<odo_scale_std_dev>,<gyro_ovst_std_dev>,<acc_offset_std_dev>,
<height_std_dev>,<major_axis>,<minor_axis>,<angle>,<speed_std_dev>*
<checksum><cr><lf>
```

## **Arguments:** 

**Table 196. $PSTMDRCONFID message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Lat std dev|Double, 5 significant digits|Decimal degrees|
|Lon std dev|Double, 5 significant digits|Decimal degrees|
|Heading std dev|Double, 4 significant digits|Degrees, -180 to +180|
|Gyro_gain std dev|Double, 4 significant digits|(Radians/s)/millivolt|
|Gyro_offset std dev|Double, 4 significant digits|millivolts|
|Odo_scale std dev|Double, 4 significant digits|millimeters/pulse|
|gyro_ovst std dev|Double, 6 significant digits|volt/°C|
|acc_offset_std_dev|Double, 6 significant digits|g|
|height_std_dev|Double, 4 significant digits|meters|
|Major_axis|Double, 3 significant digits|Standard deviation (meters) of semi-major axis of error ellipse|
|Semi-minor Dev|Double, 3 significant digits|Standard deviation (meters) of semi-minor axis of error ellipse|
|angle|Double, 3 significant digits|Speed standard deviation (m/s)|
|Speed_std_dev|Double, 3 significant digits|EMPTY?[NMP1]|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.13 $PSTMDRUPD** 

It reports the value by which the Teseo Dead Reckoning Kalman state variables changed during the update computation during the previous second. 

**UM2791** - **Rev 3** 

**page 171/241** 

**UM2791 Dead reckoning NMEA Messages** 

NMEA message list bitmask (64 bits): 0200 0000 0000 0000 **Synopsis:** 

```
$PSTMDRUPD
<lat>,<lon>,<heading>,<gyro_offset>,<gyro_gain>,<odo_scale>,<gyro_ovst>,
<acc_offset>,<height>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 197. $PSTMDRUPD message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|lat|Double, 5 significant digits|Decimal degrees|
|lon|Double, 5 significant digits|Decimal degrees|
|heading|Double, 4 significant digits|Degrees, -180 to +180|
|gyro_gain|Double, 4 significant digits|(Radians/s)/millivolt|
|gyro_offset|Double, 4 significant digits|millivolts|
|odo_scale|Double, 4 significant digits|millimeters/pulse|
|gyro_ovst|Double, 6 significant digits|volt/°C|
|acc_offset|Double, 6 significant digits|g|
|height|Double, 1 significant digits|meters|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.14 $PSTMDRTUNNEL** 

Reports various Dead Reckoning metrics calculated during the last GNSS outage. Note, these may be approximate, due to the condition by which the algorithm determines tunnel start and stop not being absolute. NMEA message list bitmask (64 bits): 0200 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRTUNNEL
<exit>,<duration>,<length>,<heading_error>,<yaw_rate_error>,<calib_error>,
<pos_error_DR>,<pos_error_percent>,<noise_error>
*<checksum><cr><lf>
```

## **Arguments:** 

**Table 198. $PSTMDRTUNNEL message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|exit|boolean|1 means the GNSS Kalman filter has deemed that second the point at which<br>the tunnel was exited.|
|duration|Decimal, 5 digits|Seconds<br>the GNSS Kalman considered it to have been traveling in a tunnel.|
|length|Double, 4 significant digits|Approximated tunnel length in meters|
|Heading_error|Double, 4 significant digits|Approximated heading error at tunnel exit in degrees|
|Yaw_rate_error|Double, 4 significant digits|Approximated yaw rate error at tunnel exit in degrees/second|
|Calib_error|Double, 4 significant digits|Approximated gyro gain error at tunnel exit in millivolts|
|Pos_error_DR|Double, 4 significant digits|Approximated position error at tunnel exit in meters|



**UM2791** - **Rev 3** 

**page 172/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Pos_error_percent|Double, 4 significant digits|Approximated position error at tunnel exit as a percent of approximated<br>tunnel length|
|Noise Error|Double, 4 significant digits|Calculated gyro noise error in degrees|



## **Results:** 

This message is only provided when the corresponding event occurs. 

## **11.10.15 $PSTMDRSTYPE** 

Reports Dead Reckoning sensor configuration (combination) type. NMEA message list bitmask (64 bits): 0200 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRSTYPE,<sensor_type>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 199. $PSTMDRSTYPE message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Sensor_type|Decimal, 1 digit|3: GYRO3, meaning yaw is calculated from a 3D MEMS gyro.|



## **Results:** 

- This message is provided at 1 Hz. 

## **11.10.16 $PSTMDRCAL** 

Reports the calibration status of the Dead Reckoning calibration parameters. NMEA message list bitmask (64 bits): 0100 0000 0000 00000 **Synopsis:** 

```
$PSTMDRCAL
<dr_is_calib>,<odo_is_calib>,<gyro_gain_is_calib>,<gyro_offset_is_calib>,
<imu_flag>,<gyro_integrity_flag>,<acc_integrity>,<dr_calib_status>
*<checksum><cr><lf>
```

## **Arguments:** 

**Table 200. $PSTMDRCAL message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Dr_is_calib|boolean|1: Dead Reckoning is fully calibrated|
|odo_is_calib|boolean|1: Odo scale is calibrated (on Teseo-Module)|
|Gyro_gain_is_calib|boolean|1: gyro gain is calibrated|
|Gyro_offset_is_calib|boolean|1: gyro offset is calibrated|
|imu_flag|Hexadecimal, 2 digits|IMU calibration status flags:<br>1: Calibrated<br>0: Not calibrated<br>Bit fields:<br>Bit 0: Gyro z axis<br>Bit 1: Gyro y axis<br>Bit 2: Gyro x axis|



**UM2791** - **Rev 3** 

**page 173/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||Bit 3: Acc z axis<br>Bit 4 : Acc y axis<br>Bit 5 : Acc x axis<br>IMU installation status flags:<br>1: Self-detected<br>0: Not self-detected<br>Bit fields:<br>Bit 6: Roll installation angle<br>Bit 7: Pitch installation angle[NMP1]|
|gyro_integrity_flag|boolean|•<br>1: gyro signal is healthy<br>•<br>0: gyro signal is faulty|
|acc_integrity_flag|boolean|•<br>1: acc signal is healthy<br>•<br>0: acc signal is faulty|
|dr_calib_status|“N”, “L” or “F”|•<br>N: calibration Not available<br>•<br>L: Light calibration<br>•<br>C: Full calibration|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.17 $PSTMDRAHRS** 

Reports the attitude heading reference system data NMEA message list bitmask (64 bits): 2000 0000 0000 0000 **Synopsis:** 

```
$PSTMDRAHRS<inst_pitch>,<inst_roll>,<inst_yaw>,<slope>,<slope_acc>,
res>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 201. $PSTMDRAHRS message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|inst_pitch|double|Sensor frame vs vehicle frame pitch angle [deg]|
|inst_roll|double|Sensor frame vs vehicle frame roll angle [deg]|
|inst_yaw|double|Sensor frame vs vehicle frame yaw angle [deg]|
|slope|double|Estimated slope [deg]|
|slope_acc|double|Estimated slope accuracy [deg]. Set to 0 if not available|
|res|none|Reserved|



## **Results:** 

This message is provided at 1 Hz. 

## **11.10.18 $PSTMDREPE** 

Reports the Draw estimated position error. NMEA message list bitmask (64 bits): 0200 0000 0000 0000 **Synopsis:** 

**UM2791** - **Rev 3** 

**page 174/241** 

**UM2791 Dead reckoning NMEA Messages** 

```
$PSTMDREPE,<ehpe>,<reserved>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 202. $PSTMDREPE message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|ehpe|double|Dead Reckoning estimated horizontal position error [m]|
|reserved|double|-1.00<br>Reserved for future use.|



## **Results:** 

- This message is provided at 1Hz. 

## **Example:** 

```
$PSTMDREPE,141.2,-1.00*72
```

## **11.10.19 $PSTMDRMMFBKF** 

MMFB acceptance and usage in Dead Reckoning. This message is only reported after the reception of a $PSTMDRMMFB command. 

NMEA message list bitmask (64 bits): 0200 0000 0000 0000 

## **Synopsis:** 

```
$PSTMDRMMFBKF,<cpu time>,<elapsed time>,<UTC Delta seconds>,<UTC Delta ms>,
<Pos Accepted>,<Pos Innovation lat>,<Pos Innovation lon>,<Pos Measurement Noise lat>,<Pos
Measurement Noise lon>,<Pos Update lat>,<Pos Update lon>,<Heading Accepted>,
<Heading Innovation>,<Heading Measurement Noise>,<Heading Update>*<checksum><cr><lf>
```

## **Arguments:** 

**Table 203. $PSTMDRMMFBKF message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|Cpu time|Decimal, 10 digits|Unit: microseconds<br>Cpu time at which the $PSTMDRMMFB command is received.|
|Elapsed time|Decimal, 10 digit|Unit: microseconds<br>Time difference between cpu time and the current GNSS fix cpu time (e.g.<br>timestamp contained in last $PSTMTG message)|
|UTC Delta seconds|Decimal, 2 digits|Unit: seconds<br>Difference between current GNSS UTC time and UTC time reported by host<br>in $PSTMDRMMFB command.|
|UTC Delta ms|Decimal, 3 digits|Unit: microseconds<br>If UTC Delta seconds is null, the difference between current GNSS UTC time<br>and UTC time in $PSTMDRMMFB command is reported in UTC Delta ms.|
|Pos Accepted|Decimal, 1 digit|Flag indicating if the position reported in $PSTMDRMMFB command is<br>accepted or not:<br>•<br>1: Accepted<br>•<br>0: Not accepted|
|Pos Innovation lat|Double, 2 fractional<br>digits|Latitude in m.<br>Difference between current Dead Reckoning position and MMFB position<br>reported by host.|
|Pos Innovation lon|Double, 2 fractional<br>digits|Longitude in m.|



**UM2791** - **Rev 3** 

**page 175/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||Difference between current Dead Reckoning position and MMFB position<br>reported by host.|
|Pos Measurement<br>Noise lat|Double, 2 fractional<br>digits|Latitude in m.<br>Position Measurement noise used by Dead Reckoning (either auto-<br>calculated or reported by host).|
|Pos Measurement<br>Noise lat|Double, 2 fractional<br>digits|Longitude in m.<br>Position Measurement noise used by Dead Reckoning (either auto-<br>calculated or reported by host).|
|Pos Update lat|Double, 2 fractional<br>digits|Latitude in m.<br>New position computed by Dead Reckoning with innovation and<br>measurement noise.|
|Pos Update lon|Double, 2 fractional<br>digits|Longitude in m.<br>New position computed by Dead Reckoning with innovation and<br>measurement noise.|
|Heading Accepted|Decimal, 1 digit|Flag indicating if the heading reported in $PSTMDRMMFB command is<br>accepted or not:<br>•<br>1: Accepted<br>•<br>0: Not accepted|
|Heading Innovation|Double, 2 fractional<br>digits|Heading in degrees.<br>Difference between current Dead Reckoning heading and MMFB heading<br>reported by host.|
|Heading Measurement<br>Noise|Double, 2 fractional<br>digits|Heading in degrees.<br>Heading Measurement noise used by Dead Reckoning (either auto-<br>calculated or reported by host).|
|Heading Update|Double, 2 fractional<br>digits|Heading in degrees.<br>New heading computed by Dead Reckoning with innovation and<br>measurement noise.|



## **Results:** 

This message is provided at 1Hz if MMFB feature is enabled and $PSTMDRMMFB command is received. 

## **11.10.20 $PSTMDRSENCONFIG** 

Reports the sensors internal configuration. 

## **Synopsis:** 

```
$PSTMDRSENCONFIG,<IMU Type>,<sensor name>,<Full Scale>,<Sensitivity>,
<Output Data Rate>,<Low Pass Filter Bandwidth>,<Temperature Compensation>*
<checksum><cr><lf>
```

## **Arguments:** 

**Table 204. $PSTMDRSENCONFIG message field description** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|IMU Type|String|IMU ACC:accelerometer internal configuration<br>IMU GYRO: gyroscope internal configuration|
|Sensor name|String, max 10 char|"ASM330LHH",|
|Full Scale|Decimal, 3 digits|IMU ACC:<br>Unit: g<br>IMU GYRO:|



**UM2791** - **Rev 3** 

**page 176/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||Unit: dps|
|Sensitivity|Decimal, 4 digits|IMU ACC:<br>Unit: micro g/LSB<br>IMU GYRO:<br>Unit: micro dps/LSB|
|Output Data Rate|Decimal, 4 digits|Output Data Rate in Hz|
|Low Pass Filter Bandwidth|Double, 1 fractional digits|Low Pass Filter bandwidth in Hz|
|Temperature Compensation|Decimal, 1 digit|Present in case of IMU GYRO only<br>•<br>0: Internal Temperature Compensation Disabled<br>•<br>1: Internal Temperature Compensation Enabled.|



## **Results:** 

- This message is provided at initialization. 

## **11.10.21 $PSTMDR1** 

This message reports at 1 Hz data that allow to understand details about DRAW&DRUM alignment angles, bias, and sensitivity values for gyroscope& accelerometer. 

## _**Synopsys**_ 

```
$PSTMDR1,<m_pitch>,<m_roll>,<m_yaw>,<gsz>,<gbx>,<gby>,<gbz>,<abx>,<aby>
,<abz>,<odometer_scale>,<res1_baro>,<res2_baro>*<checksum><cr><lf>
```

**Table 205. $PSTMDR1 fields explanation** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|`M pitch`|Double, 6 digits|`Misalignment sensor vs.`<br>`vehicle frame saved in`<br>`memory – Pitch angle [deg]`|
|`M roll`|Double, 6 digits|`Misalignment sensor vs.`<br>`vehicle frame saved in`<br>`memory – Roll angle [deg]`|
|`M yaw`|Double, 6 digits|`Misalignment sensor vs.`<br>`vehicle frame saved in`<br>`memory – Yaw angle [deg]`|
|`gsz`|Double, 6 digits|`Gyroz axis sensitivity`<br>`[adimensional]`|
|`gbx`|Double, 6 digits|`Gyrox axis bias [dps]`|
|`gby`|Double, 6 digits|`Gyroy axis bias [dps]`|
|`gbz`|Double, 6 digits|`Gyroz axis bias [dps]`|
|`abx`|Double, 6 digits|`Accelerometerx axis bias`<br>`[m/s^2]`|
|`aby`|Double, 6 digits|`Accelerometery axis bias`<br>`[m/s^2]`|
|`abz`|Double, 6 digits|`Accelerometerz axis bias`<br>`[m/s^2]`|
|`odometer scale`|Double, 6 digits|`Meters/pulse`|
|`Res1_baro`|Double, 6 digits|`Reserved for barometer`|



**UM2791** - **Rev 3** 

**page 177/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|`Res2_baro`|Double, 6 digits|`Reserved for barometer`|



## _**Example**_ 

```
$PSTMDR1,18.940617,-2.572014,12.749996,0.996465,-
0.126606,0.855293,0.072350,-
0.083809,0.118225,0.133587,0.021461,0.000000,0.000000*25
```

## **11.10.22 $PSTMDR2** 

This message reports at 1 Hz data that allow to understand details about DRAW&DRUM calibration status and availability. 

## _**Synopsys**_ 

```
$PSTMDR2,<IMU_cal>,<AS_cal>,<motion_status>,<err_code>,<sr>,<cross_tra
ck_error>,<along_track_error>,<sa>,<vro_ws>,<vro_st>*<checksum><cr><lf
>
```

## **Table 206. $PSTMDROL fields explanation** 

|**Parameter**|**Format**|**Format**|**Description**|
|---|---|---|---|
|`IMU cal`|String, characters|2|`6-axesIMU`<br>`calibration status.`<br>`Char#1:`<br>`accelerometer`<br>`char#2: gyroscope`<br>`A:Not Available`<br>`(sensor not`<br>`supported) N: Not`<br>`calibrated`<br>`C:`**`C`**`alibrated`|
|`AS cal`|String, characters|N|`Additionalsensors`<br>`calibration status.`<br>`A: Not Available`<br>`(sensor not`<br>`supported) N: Not`<br>`calibrated`<br>`C:Calibrated`|
|`Motion status`|Decimal|-|`Motionstatus`<br>`indicator. 0:`<br>`Unclassified1:Stopp`<br>`ed2:Straight3:No`<br>`straight no turn 4:`<br>`Turning5:Accelerati`<br>`ng6:Braking7:Revers`<br>`e`|



**UM2791** - **Rev 3** 

**page 178/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Format**|**Description**|
|---|---|---|---|
|`Err code`|Decimal, digits|2|`FWerror code. 00:`<br>`No Error01:Gyro`<br>`Failure02:Accelerom`<br>`eter`<br>`Failure03:Odometer`<br>`failure04:GNSS`<br>`Failure05:Pressure`<br>`Sensor Failure 06:`<br>`Magnetometer`<br>`Failure07:Misalignm`<br>`ent Failure 08: Acc`<br>`KF Failure09:Gyro`<br>`KF Failure 10:`<br>`Generic SW Failure`|
|`sr`|Decimal||`SystemReady`<br>`Flag.0:System not`<br>`ready (GNSS-only`<br>`PVT out)1:System`<br>`ready (PVT is GNSS`<br>`sensors fusion)`|
|`Cross_track_error`|Decimal, digits|2|`Crosstrack error vs`<br>`GNSS [m]`|
|`Along_track_error`|Decimal, digits|2|`Alongtrack error vs`<br>`GNSS [m]`|
|`sa`|Decimal|-|System aligned Flag:<br>0: System not aligned (The<br>Full Free Mounted procedure<br>is not finished)<br>1: System aligned (The Full<br>Free Mounted procedure<br>complete|
|`vro_ws`|Decimal, digits|3|`Vehicletire`<br>`circumference`<br>`estimated [m]`|
|`vro_st`|Decimal|-|`VROFlag.`<br>`0:Not started`<br>`1:Search ongoing`<br>`2:Speed available`<br>`3:Speed not`<br>`available for weak`<br>`signal`|
|`checksum`|Hexadecimal, 2 digits||`Checksumof the`<br>`message`|



## _**Example**_ 

```
$PSTMDR2,CC,AA,2,0,1,-0.26,-0.35,1,1.982,2*3E
```

## **11.10.23 $PSTMDRPVASD** 

This message reports at 1 Hz the standard deviation of DR estimates for position, velocity and attitude. 

**UM2791** - **Rev 3** 

**page 179/241** 

**UM2791 Dead reckoning NMEA Messages** 

## _**Synopsys**_ 

```
$PSTMDRPVASD,<Timestamp>,<CPU_time>,<latitude_sd>,<longitude_sd>,<heig
ht_sd>,<v_north_sd>,<v_east_sd>,<v_up_sd>,<pitch_sd>,<roll_sd>,<headin
g_sd>,<p_ne_sd>,<p_nu_sd>,<p_eu_sd>,<v_ne_sd>,<v_nu_sd>,<v_eu_sd>*<che cksum><cr><lf>
```

**Table 207. $PSTMDROL fields explanation** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|`Timestamp`|hhmmss.ss s|`Fixtimestamp in UTC`<br>`hh:hours (Fixed two`<br>`digits) mm: minutes (Fixed`<br>`two digits) ss: seconds`<br>`(Fixed two digits)`<br>`.sss:decimal fraction of`<br>`seconds`|
|`CPU time`|Floating|`Timeof DR estimation [CPU`<br>`ticks]`|
|`Latitude sd`|Double, 1 digit|`DRlatitude standard`<br>`deviation [m]`|
|`Longitude sd`|Double, 1 digit|`DRlatitude standard`<br>`deviation [m]`|
|`Height sd`|Double, 1 digit|`DRheight standard`<br>`deviation [m]`|
|`V north sd`|Double, 2 digit|`DRvelocity north component`<br>`standard deviation [m/s]`|
|`V east sd`|Double, 2 digit|`DRvelocity east component`<br>`standard deviation [m/s]`|
|`V up sd`|Double, 2 digit|`DRvelocity up component`<br>`standard deviation [m/s]`|
|`Pitch sd`|Double, 2 digit|`DRpitch angle standard`<br>`deviation [deg]`|
|`Roll sd`|Double, 2 digit|`DRroll angle standard`<br>`deviation [deg]`|
|`Roll sd`|Double, 2 digit|`DR heading angle standard`<br>`deviation [deg]`|
|`Heading sd`|Double, 2 digit|`DR position north east`<br>`standard deviation [m]`|
|`P_ne_sd`|Double, 1 digit|`DRposition north up`<br>`standard deviation [m]`|
|`P_nu_sd`|Double, 1 digit|`DRposition north up`<br>`standard deviation [m]`|
|`P_eu_sd`|Double, 1 digit|`DR position east up`<br>`standard deviation [m]`|
|`V_ne_sd`|Double, 2 digit|`DRvelocity north up`<br>`standard deviation [m]`|
|`V_nu_sd`|Double, 2 digit|`DR velocity north up`<br>`standard deviation [m]`|
|`V_eu_sd`|Double, 2 digit|`DR velocity east up`<br>`standard deviation [m]`|



**UM2791** - **Rev 3** 

**page 180/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|`checksum`|Hexadecim al, 2 digits|`Checksum of the message`|



## **11.10.24 $PSTMDRSINT** 

This message reports at 1 Hz the result for sensors’ integration samples between two consecutive GNSS epochs, that is, across 1 second. The values for angular rates and accelerations are in degrees per second and expressed in vehicle frame not compensated with the bias. Subtracting bias found in PSTDR1 allow to derive vehicle frame data. To toggle on/off this message in configuration, bit mask in CDB228needs to be set as follows (refer to [4] for more information on FW configuration). 

## _**Synopsys**_ 

```
$PSTMDRSINT,<gyro_sample_count>,<acc_sample_count>,<pres_sample_count>
,<odometer_count>,<gyro_int_time>,<acc_int_time>,<pressure_int_time>,<
gyro_x_avg>,<gyro_y_avg>,
<gyro_z_avg>,<acc_x_avg>,<acc_y_avg>,<acc_z_avg>,<pres_avg>,*<checksum
><cr><lf>
```

**Table 208.  $PSTMDRSINT fields explanation** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|`gyro sample count`|Int, 2 digits|`Number of gyro samples received`|
|`acc samplecount`|Int, 2 digits|`Number of acc samples received`|
|`pressure samplecount`|Int, 2 digits|`Number of pressure samples received`|
|`Odometer count`|Int, 2 digits|`Numberof odometer pulses received`|
|`gyro int time`|Dbl, 3 digits|`Time elapsed between 1standlast gyro sample`<br>`received [s]`|
|`axl int time`|Dbl, 3 digits|`Time elapsed between 1standlast acc sample`<br>`received [s]`|
|`pressure int time`|Dbl, 3 digits|`Time elapsed between 1standlast pressure`<br>`sample received [s]`|
|`gyro x avg`|Dbl, 2 digits|`Average of x gyro samples received in last`<br>`second, expressed in vehicle frame [dps].`<br>`positive value for a clockwise rotation.`|
|`gyro y avg`|Dbl, 2 digits|`Average of y gyro samples received in last`<br>`second, expressed in vehicle frame [dps].`<br>`positive value for a clockwise rotation.`|
|`gyro z avg`|Dbl, 2 digits|`Average of z gyro samples received in last`<br>`second, expressed in vehicle frame [dps].`<br>`positive value for a clockwise rotation.`|
|`acc x avg`|Dbl, 2 digits|`Average of x acc samples received in last`<br>`second, expressed in vehicle frame [m/s^2]`|
|`acc y avg`|Dbl, 2 digits|`Average of y acc samples received in last`<br>`second, expressed in vehicle frame [m/s^2]`|
|`acc z avg`|Dbl, 2 digits|`Average of z acc samples received in last`<br>`second, expressed in vehicle frame [m/s^2]`|
|`pressure avg`|Dbl, 2 digits|`Average of pressure samples received [hPa]`|
|`checksum`|Hexadecimal, 2 digits|`Check sum of the message`|



**UM2791** - **Rev 3** 

**page 181/241** 

**UM2791 Dead reckoning NMEA Messages** 

## **11.10.25 $PSTMDRNVM_WRITE** 

Reports the DR Kalman state variables and there corresponding standard deviations that have just been copied to NVM. 

NMEA message list bitmask (64 bits): 0800 0000 0000 0000. 

## **11.10.26 $PSTM_KALMAN_INIT** 

Reports what the DR Kalman state variables being used are when the DR is initialized and there corresponding standard deviations. 

NMEA message list bitmask (64 bits): 0800 0000 0000 0000. 

## **11.10.27 $PSTMDRNVM_READ** 

Reports the DR Kalman state variables and there corresponding standard deviations that are currently stored in NVM. 

NMEA message list bitmask (64 bits): 0800 0000 0000 0000. 

## **Format:** 

```
$PSTMDRNVM_WRITE or $PSTM_KALMAN_INIT or $PSTMDRNVM_READ
<lat>,<lon>,<heading>,<gyro_offset>,<gyro_gain>,<odo_scale>
<lat_std_dev>,<lon_std_dev>,<heading_std_dev>,<gyro_offset_std_dev>
<gyro_gain_std_dev>,<odo_scale_std_dev>,<gyro_ovst>,<gyro_ovst_std_dev>,
<temperature>,<pitch>,<roll>,<yaw>,<cal_flag>,<imu_axes>,<imu_flag>,
<acc_x_offset>,<acc_y_offset>,<acc_z_offset>,<height>,
<acc_offset_std_dev>,<height_std_dev>*<checksum><cr><lf>
```

**Table 209. $PSTMDRNVM_READ fields explanation** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|lat|Double, 5 significant digits|`Decimal`<br>`degrees`|
|lon|Double, 5 significant digits|`Decimal`<br>`degrees`|
|heading|Double, 5 digits|`Degrees, -180 to`<br>`+180`|
|Gyro_offset|Double, 4 significant digits|`Volts`|
|Gyro_gain|Double, 4 significant digits|`(Radians/s)/Volt`|
|Odo_scale|Double, 5 significant digits|`Meters/pulse`|
|Lat_std_dev|Double, 5 significant digits|`Decimal`<br>`degrees`|
|Lon_std_dev|Double, 5 significant digits|`Decimal`<br>`degrees`|
|Heading_std_dev|Double, 5 digits|`Degrees, -180 to`<br>`+180`|
|Gyro_offset_std_dev|Double, 4 significant digits|`Volts`|
|Gyro_gain_std_dev|Double, 4 significant digits|`(Radians/s)/Volt`|
|Odo_scale_std_dev|Double, 5 significant digits|`Meters/pulse`|
|gyro_ovst|Double, 6 significant digits|`Volt/°C`|
|gyro_ovst std dev|Double, 6 significant digits|`Volt/°C`|



**UM2791** - **Rev 3** 

**page 182/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|temperature|Decimal|`Gyro sensor temperature`<br>`1°C/LSB`|
|pitch|Double, 1 significant digits|`Sensor frame vs`<br>`vehicle`<br>`frame pitch angle`|
|roll|Double, 1 significant digits|`Sensor frame vs`<br>`vehicle`<br>`frame roll angle`|
|yaw|Double, 1 significant digits|`Sensor frame vs`<br>`vehicle`<br>`frame yaw angle`|
|cal_flag|Hexadecimal, 1 digits|`Calibration status flags:`<br>`1:`<br>`Calibrated`<br>`0: Not`<br>`calibrated`<br>`Bit`<br>`fields:`<br>`Bit 0:`<br>`Odo scale`<br>`Bit 1:`<br>`Gyro gain`<br>`Bit 2:`<br>`Gyro offset`|
|imu_axes|Hexadecimal, 6 digits|`IMU axes mask`<br>`directions`|
|imu_flag|Hexadecimal, 2 digits|`IMU calibration`<br>`status flags:`<br>`1: Calibrated`<br>`0: Not`<br>`calibrated`<br>`Bit`<br>`fields:`<br>`Bit 0: Gyro z axis`<br>`Bit 1: Gyro y`<br>`axis`|



**UM2791** - **Rev 3** 

**page 183/241** 

**UM2791 Dead reckoning NMEA Messages** 

|**Parameter**|**Format**|**Description**|
|---|---|---|
|||`Bit 2: Gyro x`<br>`axis`<br>`Bit 3: Acc z axis`<br>`Bit 4: Acc y`<br>`axis`<br>`Bit 5: Acc x`<br>`axis`<br>`IMU installation`<br>`status flags:`<br>`1: Self-detected`<br>`0: Not`<br>`self-detected`<br>`Bit`<br>`fields:`<br>`Bit 6: Roll`<br>`installation`<br>`angle`<br>`Bit 7: Pitch`<br>`installation`<br>`angle`|
|acc_x_offset|Double, 6 significant digits|`g`|
|acc_y_offset|Double, 6 significant digits|`g`|
|acc_z_offset|Double, 6 significant digits|`g`|
|height|Double, 1 significant digits|`meters`|
|acc_offset_std_dev|Double, 6 significant digits|`g`|
|height_std_dev|Double, 3 significant digits|`meters`|
|checksum|Hexadecimal, 2 digits|`Checksum of the`<br>`message`<br>`bytes without`<br>`*<checksum><cr><lf>`<br>`characters`|



## **Results:** 

These messages are provided only when the corresponding events occur. 

**UM2791** - **Rev 3** 

**page 184/241** 

**UM2791 Firmware configuration data block (CDB)** 

## **12 Firmware configuration data block (CDB)** 

All configuration parameters are grouped in a data block. Each field is addressed by a unique ID. The IDs are made by three digits: the most significant one represents the parameter type and the others are used to identify different parameters of the same type. 

## **12.1 CDB-ID 101 – NMEA port setting** 

Allow setting the NMEA port number. 

System reboot needed to have new setting in use. 

## **12.2 CDB-ID 102 – NMEA port baud rate setting** 

Allow setting the baud rate for the NMEA port number. 

**Table 210. CDB-ID 102 field description** 

|**Parameter value**|**Baudrate**|
|---|---|
|0x0|300 baud|
|0x1|600 baud|
|0x2|1200 baud|
|0x3|2400 baud|
|0x4|4800 baud|
|0x5|9600 baud|
|0x 6|14400 baud|
|0x 7|19200 baud|
|0x 8|38400 baud|
|0x 9|57600 baud|
|0xA|115200 baud|
|0xB|230400 baud|
|0xC|460800 baud|
|0xD|921600 baud|



System reboot needed to have new setting in use. 

## **12.3 CDB-ID 104 – Mask angle setting** 

Allow setting the minimum elevation angle at which a satellite can be tracked. Satellite with elevation below the mask angle cannot be tracked. 

System reboot needed to have new setting in use. 

## **12.4** 

## **CDB-ID 105 – GNSS Tracking CN0 threshold** 

Allow setting the minimum CN0 [dB] at which a satellite can be tracked. Satellite with CN0 below the configured threshold cannot be tracked. 

A Teseo-Module engine reset (suspend/restart) is needed to have this setting in place. 

**UM2791** - **Rev 3** 

**page 185/241** 

**UM2791 CDB-ID 120 – Cold start setting** 

## **12.5 CDB-ID 120 – Cold start setting** 

Allow setting the data to be cleared during the COLD start command execution. This parameter is a bitmask where bit=1 indicates the data to be cleared. 

**Table 211. CDB-ID 120 field description** 

|**Bit**|**Bitmask**|**Description**|
|---|---|---|
|0|0x1|Clear almanacs|
|1|0x2|Clear ephemeris|
|2|0x4|Clear position|
|3|0x8|Clear time|



Any bitmask combination is allowed, the default one is 0xE. 

This setting is in place as soon as the $PSTMSETPAR is performed. 

## **12.6 CDB-ID 121 – Number of decimal digits for speed and course data in NMEA messages** 

Allow setting the number of decimal digits for the speed and course data in NMEA messages. It affects both RMC and VTG messages. 

It is possible to set a different number of decimal digits. 

**Table 212. CDB-ID 121 field description** 

|**Bit**|**Values**|**Description**|
|---|---|---|
|From B0 to B3|From 1 up to 5|Allow setting the number of decimal digits for speed value in RMC and VTG massages|
|From B4 to B7|From 1 up to 5|Allow setting the number of decimal digits for course value in RMC and VTG messages.|



## **12.7 CDB-ID 122 – NMEA format configuration** 

Allow setting the change the format of NMEA. Note that this changing the default value of this parameter the Bit 6 of CDB-ID 200 – Application ON/OFF is bypassed. 

The default value of this parameter is 0x0C. 

In case of wrong configuration NMEA is configured as 3.01 like. 

**Table 213. CDB-ID 122 field description** 

|**Bit**|**Values**|**Description**|
|---|---|---|
|From B0 to B3|Hexadecimal|Changes the NMEA format<br>0x01 = NMEA is 3.00 like<br>0x02 = NMEA is 3.01 like<br>0x04 = NMEA is 4.10 like<br>0x0C = Depends on Bit 6 of CDB-ID 200|



## **12.8** 

## **CDB-ID 125 – Notch filter setting** 

Allow setting the notch filter usage on GPS RF path, GLONASS RF path or both GPS and GLONASS RF paths. The notch filter can be enabled and inserted in the RF path (normal mode – see b0, b1 below) or the notch filter can be enabled but inserted only if locked on a jammer (auto-insertion mode – see b2, b3 below). 

**UM2791** - **Rev 3** 

**page 186/241** 

**UM2791** 

**CDB-ID 127 – Number of decimal digits in NMEA position messages** 

## **Table 214. CDB-ID 125 field description** 

|**Bitmask**|**Description**|
|---|---|
|b0..b3 = 0x00|Notch Filter is disabled on both GPS and GLONASS paths|
|b0|Enable/disable notch filter on GPS path (normal mode).|
|b1|Enable/disable notch filter on GLONASS path (normal mode).|
|b2|Enable/disable notch filter on GPS path in auto-insertion mode.|
|b3|Enable/disable notch filter on GLONASS path in auto-insertion mode.|



## **12.9 CDB-ID 127 – Number of decimal digits in NMEA position messages** 

Allow setting the number of decimal digits for the NMEA position messages. 

It is possible to set a different number of decimal digits for GGA and for both RMC and GLL messages. 

**Table 215. CDB-ID 127 field description** 

|**Bit**|**Values**|**Description**|
|---|---|---|
|[3 : 0]|From 1 up to 5|Allow setting the number of decimal digits for the RMC and GLL messages|
|[7 : 4]|From 1 up to 5|Allow setting the number of decimal digits for the GGA message.|



## **12.10 CDB-ID 128 – Differential source type** 

Allow selecting the differential mode source type. 

## **Table 216. CDB-ID 128 field description** 

|**Value**|**Description**|
|---|---|
|0x0 - NONE|No differential source.|
|0x1 - SBAS|SBAS is the source for differential correction.|
|0x2 - RTCM|RTCM is the source for differential corrections.|
|0x3 - AUTO|RTCM (if available) or SBAS (if available) is the source for differential corrections.|



## **12.11 CDB-ID 129 – GLONASS satellite ID type** 

Allow selecting between two different ways to report the GLONASS satellites ID in the GSV and GSA messages. 

## **Table 217. CDB-ID 129 field description** 

|**Value**|**Description**|
|---|---|
|0x0|GLONASS satellite ID based on the satellite frequency.<br>If lowest frequency is marked with freq_ID = 1 and highest frequency is marked with freq_ID = 14, the satellite IDs are<br>reported, starting from lowest frequency as 64+freq_ID. Satellites from 79 up to 92 are the antipodal of satellites from<br>65 up to 78 (they are received at the same frequency).|
|0x1|GLONASS satellite ID based on the satellite slot (reported in almanacs and ephemeris data).<br>The satellite IDs are reported as 64+slot_number. The slot number is in the range from 1 up to 24.|



**UM2791** - **Rev 3** 

**page 187/241** 

**UM2791 CDB-ID 131 – NMEA talker ID** 

## **12.12 CDB-ID 131 – NMEA talker ID** 

Allow setting the second character of the NMEA talker ID for the GGA, RMC, VTG, GLL NMEA sentences. The talked ID for GSV and GSA is managed in a different way (see CDB-ID 200, bits 19 and 20). 

## **12.13** 

## **CDB-ID 132 – GNSS positioning CN0 threshold** 

Allow setting the minimum CN0 [dB] at which a satellite can be used in the position solution. Satellites with CN0 below the configured threshold are not used in the position evaluation. 

A Teseo-Module engine reset (suspend/restart) is needed to have this setting in place. 

## **12.14 CDB-ID 135 – SBAS default service** 

Allow setting the default service for the SBAS library. 

System reboot needed to have new setting in use. 

_Note: for compatibility, a default SBAS PRN can also be set. In that case the SBAS AUTO service will be used._ 

## **12.15 CDB-ID 138 – RTCM port setting** 

Allow setting the RTCM port number. 

_Note: the RTCM feature is supported on all serial ports. It can be configured also to work on the same serial port already used for NMEA messages._ 

System reboot needed to have new setting in use. 

## **12.16 CDB-ID 139 – RTCM port baud rate setting** 

Allow setting the baud rate for the RTCM port number. 

**Table 218. CDB-ID 139 field description** 

|**Parameter value**|**Baudrate**|
|---|---|
|0x0|300 baud|
|0x1|600 baud|
|0x2|1200 baud|
|0x3|2400 baud|
|0x4|4800 baud|
|0x5|9600 baud|
|0x 6|14400 baud|
|0x 7|19200 baud|
|0x 8|38400 baud|
|0x 9|57600 baud|
|0xA|115200 baud|
|0xB|230400 baud|
|0xC|460800 baud|
|0xD|921600 baud|



System reboot needed to have new setting in use. 

**UM2791** - **Rev 3** 

**page 188/241** 

**UM2791** 

**CDB-ID 190 - CDB-ID 201 - CDB-ID 228 - NMEA message List 0 parameters** 

## **12.17 CDB-ID 190 - CDB-ID 201 - CDB-ID 228 - NMEA message List 0 parameters** 

CDB-ID 201 and CDB-ID 228 allow enabling/disabling each NMEA message in the message list 0. CDB-ID 201 represents first 32 bits (low bits) of extended 64 bits NMEA message list. See CDB-ID 228 for second 32 bits (high bits) of 64 bits message list. 

CDB-ID 190 allows setting the message list output rate for the message list 0. It is a scaling factor referred to the selected fix rate. The default value is 1 and means that messages are sent out on every fix. Setting the scaling factor to “N” means that the corresponding message list is sent out every “N” fixes. 

_Note: The message list 0 is the standard message list. Only the message list 0 should be used if the NMEA multiple rate features is not required._ 

For each bit: 

- 0 means feature disabled 

- 1 means feature enabled 

## **Table 219. CDB-ID 201 - CDB-ID 228 fields description** 

||**Bit(1)**|**Bitmask**<br>**(32 bits)**|**Function**|
|---|---|---|---|
|Low 32 bits|0|0x1|$GPGNS Message|
||1|0x2|$GPGGA Message|
||2|0x4|$GPGSA Message|
||3|0x8|$GPGST Message|
||4|0x10|$GPVTG Message|
||5|0x20|$PSTMNOISE Message|
||6|0x40|$GPRMC Message|
||7|0x80|$PSTMRF Message|
||8|0x100|$PSTMTG Message|
||9|0x200|$PSTMTS Message|
||10|0x400|$PSTMPA Message|
||11|0x800|$PSTMSAT Message|
||12|0x1000|$PSTMRES Message|
||13|0x2000|$PSTMTIM Message|
||14|0x4000|$PSTMWAAS Message|
||15|0x8000|$PSTMDIFF Message|
||16|0x10000|$PSTMCORR Message|
||17|0x20000|$PSTMSBAS Message|
||18|0x40000|$PSTMTESTRF Message|
||19|0x80000|$GPGSV Message|
||20|0x100000|$GPGLL Message|
||21|0x200000|$PSTMPPSDATA Message|
||22|0x400000|RESERVED|
||23|0x800000|$PSTMCPU Message|
||24|0x1000000|$GPZDA Message|
||25|0x2000000|$PSTMTRAIMSTATUS Message|
||26|0x4000000|$PSTMPOSHOLD Message|
||27|0x8000000|$PSTMKFCOV Message|



**UM2791** - **Rev 3** 

**page 189/241** 

**UM2791** 

**CDB-ID 190 - CDB-ID 201 - CDB-ID 228 - NMEA message List 0 parameters** 

||**Bit(1)**|**Bitmask**<br>**(32 bits)**|**Function**|
|---|---|---|---|
|Low 32 bits|28|0x10000000|$PSTMAGPS Message|
||29|0x20000000|$PSTMLOWPOWERDATA Message|
||30|0x40000000|$PSTMNOTCHSTATUS|
||31|0x80000000|$PSTMTM Message|
|High 32 bits|32|0x1|$PSTMPV Message|
||33|0x2|$PSTMPVQ Message|
||34|0x4|$PSTMUTC Message|
||35|0x8|$PSTMADCDATA Message|
||36|0x10|RESERVED|
||37|0x20|RESERVED|
||38|0x40|RESERVED|
||39|0x80|$GPDTM Message|
||40|0x100|$PSTMEPHEM Message|
||41|0x200|$PSTMALMANAC Message|
||42|0x400|$PSTMIONOPARAMS Message|
||43|0x800|RESERVED|
||44|0x1000|$PSTMBIASDATA Message|
||45|0x2000|$GPGBS Message|
||46|0x4000|$PSTMPVRAW Message|
||47|0x8000|RESERVED|
||48|0x10000|$PSTMFEDATA Message|
||49|0x20000|RESERVED|
||50|0x40000|$PSTMODO Message|
||51|0x80000|$PSTMGEOFENCE Message|
||52|0x100000|$PSTMLOGSTATUS Message|
||53|0x200000|$PSTMGNSSINTEGRITY Message|
||54|0x400000|RESERVED|
||55|0x800000|DRAW messages:<br>•<br>$PSTMDRGPS<br>•<br>$PSTMDRCAL<br>•<br>$PSTMDRSINT|
||56|0x1000000|$PSTMDRDBG|
||57|0x2000000|DRAW messages:|



**UM2791** - **Rev 3** 

**page 190/241** 

**UM2791** 

**CDB-ID 191 - CDB-ID 210 - CDB-ID 229 - NMEA message list 1 parameters** 

||**Bit(1)**|**Bitmask**<br>**(32 bits)**|**Function**|
|---|---|---|---|
|High 32 bits|||•<br>$PSTMDRMMFB<br>•<br>$PSTMDRMMFBKF<br>•<br>$PSTMDRTUNNEL<br>•<br>$PSTMDRSTYPE<br>•<br>$PSTMDRGNSA<br>•<br>$PSTMDRDBG_INIT<br>•<br>$PSTMDRIMUAA<br>•<br>$PSTMDRUPD<br>•<br>$PSTMDRDEBUG<br>•<br>$PSTMDREPE<br>•<br>$PSTMDRPVASD|
||58|0x4000000|•<br>$PSTMDRPVA|
||59|0x8000000|•<br>$PSTMDRNVM_WRITE<br>•<br>$PSTMDRDBGNVM_WRIT<br>•<br>$PSTM_KALMAN_INIT<br>•<br>$PSTMDRNVM_READ<br>•<br>$PSTMDRDBGNVM_READ|
||60|0x10000000|DRAW messages:<br>•<br>$PSTMDRSENMSG|
||61|0x20000000|DRAW messages:<br>•<br>$PSTMDR1<br>•<br>$PSTMDR2|
||62|0x40000000|•<br>$PSTMDRCONFID (DRAW)<br>•<br>$PSTMDRBSD (DRUM)|
||63|0x80000000|$--RLM return link message|



_1. The Bit-value indicates the bit position, thus multiple choices are possible._ 

_Note: The message list 0 is the standard message list. Only the message list 0 should be used if the NMEA multiple rate features is not required._ 

## **12.18 CDB-ID 191 - CDB-ID 210 - CDB-ID 229 - NMEA message list 1 parameters** 

CDB-ID 210 and CDB 229 allow enabling/disabling each NMEA message in the message list 2. CDB-ID 210 represents first 32 bits (low bits) of extended 64 bits NMEA message list, CDB-ID 220 represents second 32 bits (high bits) of extended 64 bits NMEA message list. 

CDB-ID 191 allows setting the message list 1 output rate. It is a scaling factor referred to the selected fix rate. The default value is 1 and means that messages are sent out on every fix. Setting the scaling factor to “N” means that the corresponding message list is sent out every “N” fixes. 

**Table 220. NMEA message list 1 CDB-IDs** 

|**CDB-ID**|**Description**|
|---|---|
|191|Message list 1 - Output rate scaling factor|
|210|Message list 1 - Low bitmap mask|
|229|Message list 1 - High bitmap mask|



**UM2791** - **Rev 3** 

**page 191/241** 

**UM2791** 

**CDB-ID 192 - CDB-ID 211 - CDB-ID 230 - NMEA message list 2 parameters** 

## **12.19 CDB-ID 192 - CDB-ID 211 - CDB-ID 230 - NMEA message list 2 parameters** 

CDB-ID 211 and CDB 230 allow enabling/disabling each NMEA message in the message list 2. CDB-ID 211 represents first 32 bits (low bits) of extended 64 bits NMEA message list. See CDB-ID 230 for second 32 bits (high bits) of 64 bits message list. The message list configuration is done in the same way as for the message list 0. 

If not used the message list must be set to “0”. 

CDB-ID 230 allows setting the message list output rate for the message list 2. It is a scaling factor referred to the selected fix rate. The default value is 1 and means that messages are sent out on every fix. Setting the scaling factor to “N” means that the corresponding message list is sent out every “N” fixes. 

**Table 221. NMEA message list 2 CDB-IDs** 

|**CDB-ID**|**Description**|
|---|---|
|192|Message list 2 - Output rate scaling factor|
|211|Message list 2 - Low bitmap mask|
|230|Message list 2 - High bitmap mask|



_Note:_ 

_The message list 2 is RESERVED for those messages which need to be sent at high rate (e.g. 10 Hz) and/or require accurate message output timing (low jitter). If high rate messages or low jitter are not required, this message list should not be used._ 

## **12.20 CDB-ID 197 – PPS clock** 

Allow setting the PPS clock frequency. For accurate timing application 64MHz is mandatory. 

**Table 222. CDB-ID 197 field description** 

|**Values**|**Description**|
|---|---|
|16|Sets PPS clock to 16MHz|
|32|Sets PPS clock to 32MHz|
|64|Sets PPS clock to 64MHz|



## **12.21 CDB-ID 198 – GNSS mask angle positioning** 

Set the GNSS mask angle for positioning algorithm. Satellites with elevation below the mask angle are not used in the position solution. 

## **12.22 CDB-ID 199 – Local geodetic datum selection** 

Set the local geodetic datum to be used when position data is reported over the NMEA messages. See Section  Appendix A  Local geodetic datum tables for the list of all supported datum. In the last column of tables is reported the number to be used for the CDB-ID configuration according to the selected datum. 

## **12.23 CDB-ID 200 - CDB-ID 227 - application ON/OFF** 

All features are mapped in a 64 bits bitmap with one bit for each feature; CDB-ID 200 represents the first 32 bits (low 32 bits) and CDB-227 represents the second 32 bits (high 32bits). 

For each bit: 

- 0 means feature disabled; 

- 1 means feature enabled 

**UM2791** - **Rev 3** 

**page 192/241** 

**UM2791** 

**CDB-ID 200 - CDB-ID 227 - application ON/OFF** 

## **Table 223. CDB-ID 200 field description** 

|**Bit(1)**|**Bitmask**|**Function**|**Description**|
|---|---|---|---|
|0|0x1|RESERVED||
|1|0x2|RESERVED||
|2|0x4|SBAS (WAAS / EGNOS)<br>augmentation system|Enable/disable the SBAS engine. When enabled, the SBAS engine starts searching for SBAS<br>satellites at system startup.|
|3|0x8|Enabling SBAS satellite<br>reporting in the GSV<br>messages|If enabled the SBAS satellite is reported in the GSV messages. The SBAS satellite ID,<br>reported in the GSV messages, is in the range from 33 to 51 according to the NMEA<br>specifications|
|4|0x10|ST-AGNSS enable|Enable/disable the ST-AGNSS functionality. During ST-AGNSS processing a high CPU load<br>is required, for best performances it is suggested to increase the CPU frequency when the<br>ST-AGNSS is enabled. The server based assisted GPS (P-GNSS) is included in the ST-<br>AGNSS software. It is enabled/disabled if the ST-AGNSS functionality is enabled/disabled.|
|5|0x20|2.5ppm TCXO support<br>enable|Enable/disable support for TCXO with 2.5ppm accuracy|
|6|0x40|NMEA v301 support<br>enable|Enable/disable the NMEA v3.01 support. To support the NMEA v3.01 standard some new<br>values have been reported in the –RMC, --VTG and –GLL NMEA messages. This feature is<br>enabled by default. To ensure fully compatibility with previous releases, the old NMEA format<br>can be restored disabling this feature|
|7|0x80|QZSS distributed<br>acquisition mode enable|Enable/disable the distributed acquisition operative mode for the QZSS constellation. When<br>distributed acquisition mode for QZSS is enabled, the acquisition stage usage is widespread<br>along the time in order to mitigate the current consumption spikes required by the acquisition<br>engine.|
|9|0x200|Send “config text” in the<br>“Header Message” at<br>start up|Enable/disable sending the configured text on the NMEA port at startup.|
|10|0x400|Send standard ST NMEA<br>Headers|Enable/disable sending the ST standard headers on the NMEA port at startup.|
|11|0x800|RTCM enable|Enable/disable the RTCM data processing.|
|12|0x1000|FDE Algorithm|Enable/disable the False Detection and Exclusion algorithm.|
|14|0x4000|Walking Mode Algorithm|Enable/disable the Walking Mode algorithm.|
|15|0x8000|Stop Detection Algorithm|Enable/disable the Stop Detection algorithm.|
|16|0x10000|GPS constellation enable|Enable/disable the GPS constellation. When this bit is enabled GPS satellites are enabled to<br>be tracked and used for positioning.<br>This bit setting affect also the talker ID of GSV and GSA NMEA messages. If only the GPS<br>constellation is enabled the NMEA talker ID for GSV and GSA is “GP”. If GLONASS<br>constellation is also enabled “GP” is used for GPS related GSV messages while “GN” is used<br>for the GSA messages.|
|17|0x20000|GLONASS constellation<br>enable|Enable/disable the GLONASS constellation. When this bit is enabled GLONASS satellites are<br>enabled to be tracked. To be used for positioning also the Bit 21 should be enabled.<br>This bit setting affect also the talker ID of GSV and GSA NMEA messages. If only the<br>GLONASS constellation is enabled the NMEA talker ID for GSV and GSA is “GL”. If GPS<br>constellation is also enabled “GL” is used for GLONASS related GSV messages while “GN” is<br>used for the GSA messages|
|18|0x40000|QZSS constellation<br>enable|Enable/disable the QZSS constellation. When this bit is enabled QZSS satellites are enabled<br>to be tracked and used for positioning|
|19|0x80000|NMEA GNGSV enable|Enable/disable the “GN” talker ID for GSV messages reporting satellite for all constellations.<br>When this bit is enabled, only the talker ID “GN” is used for GSV messages.|
|20|0x100000|NMEA GNGSA enable|Enable/disable the “GN” talker ID for GSA messages reporting satellite for all constellations.<br>When this bit is enabled, only the talker ID “GN” is used for GSA messages.|
|21|0x200000|GLONAS usage for<br>positioning enable|Enable/disable the usage of GLONASS satellite for the GNSS position fix. If this bit is<br>disabled and GLONASS constellation is enabled, the GLONASS satellites are only tracked.|



**UM2791** - **Rev 3** 

**page 193/241** 

**UM2791** 

**CDB-ID 200 - CDB-ID 227 - application ON/OFF** 

|**Bit(1)**|**Bitmask**|**Function**|**Description**|
|---|---|---|---|
|22|0x400000|GPS usage for<br>positioning enable|Enable/disable the usage of GPS satellite for the GNSS position fix. If this bit is disabled and<br>GPS constellation is enabled, the GPS satellites are only tracked|
|23|0x800000|QZSS usage for<br>positioning enable|Enable/disable the usage of QZSS satellites for the GNSS position fix. If this bit is disabled<br>and QZSS constellation is enabled, the QZSS satellites are only tracked.|
|24|0x1000000|PPS enabling|Enable/disable the PPS generation on the PPS pin.|
|25|0x2000000|PPS polarity inversion|Enable/disable the PPS signal polarity inversion. If polarity inversion is disabled (Bit25 = 0)<br>the PPS signal has the rising edge on the PPS event. If polarity inversion is enabled (Bit25 =<br>1) the PPS signal has a falling edge on the PPS event.|
|26|0x4000000|Position Hold enable|Enable/disable the Position Hold functionality (timing applications).|
|27|0x8000000|TRAIM algorithm enable|Enable/disable the TRAIM algorithm (timing applications).|
|28|0x10000000|RESERVED||
|29|0x20000000|High dynamics enable.|Enable/disable the high dynamics functionality. This feature increases the sample rate of the<br>DSP measurements. It is required when high fix rate (> 5Hz) is selected|
|30|0x40000000|ST NMEA DSP raw<br>messages enable|Enable/disable the DSP raw messages over the NMEA port. They are proprietary messages<br>which reports info from DSP stage.|
|31|0x80000000|Low power algorithm<br>enable|Enable/disable the low power management features|



_1. The Bit-value indicates the bit position (starting from 0 as least significant bit), thus multiple choices are possible._ 

**Table 224. CDB-ID 227 field description** 

|**Bit(1)**|**Bitmask**|**Function**|**Description**|
|---|---|---|---|
|0|0x1|NMEA commands eco<br>enable|Enable/disable the command eco on the NMEA port|
|1|0x2|NMEA Time To First Fix<br>enable|Enable/disable the Time To First Fix message on the NMEA port. If enabled, the TTFF<br>message is sent only one time as soon as the GNSS position fix is achieved.|
|2|0x4|Few satellites position<br>estimation enable|Enable/disable the position estimation algorithm when tracked satellites are less than 3.|
|3|0x8|Reserved|Reserved|
|4|0x10|Return Link Message enable|Enable/disable the Return Link Message on NMEA port|
|5|0x20|Reserved|Reserved|
|6|0x40|Galileo constellation enable|Enable/disable the Galileo constellation. When this bit is enabled Galileo satellites are<br>enabled to be tracked and used for positioning|
|7|0x80|Galileo usage for positioning<br>enable|Enable/disable the usage of Galileo satellite for the GNSS position fix. If this bit is disabled<br>and Galileo constellation is enabled, the Galileo satellites are only tracked.|
|8|0x100|Beidou constellation enable|Enable/disable the Beidou constellation. When this bit is enabled Beidou satellites are<br>enabled to be tracked and used for positioning.|
|9|0x200|Beidou usage for positioning<br>enable|Enable/disable the usage of Beidou satellite for the GNSS position fix. If this bit is disabled<br>and Beidou constellation is enabled, the Beidou satellites are only tracked.|
|10|0x400|RESERVED||
|11|0x800|RTC usage disabling|Enable/disable the usage of RTC from the GNSS engine. It is recommended to have RTC<br>usage disabled (Bit12 set to 1) is the RTC crystal is not mounted.|
|12|0x1000|Fast Satellite Drop feature<br>enable|Enable/disable the Fast Satellite Drop feature. When fast satellite drop is enabled, the<br>GNSS software reports NO FIX status immediately after the tunnel entrance; the position<br>update is no more propagated for some seconds inside the tunnel.|
|13|0x2000|RESERVED||
|14|0x4000|Excluded satellites reporting<br>enable|Enable/disable the excluded satellites reporting in the GGA, GSA, GNS and PSTMTG<br>nmea messages.|



**UM2791** - **Rev 3** 

**page 194/241** 

**UM2791 CDB-ID 202 – NCO range max value** 

|**Bit(1)**|**Bitmask**|**Function**|**Description**|
|---|---|---|---|
||||If this bit is enabled, satellites excluded by positioning stage due to RAIM or FDE<br>algorithms, are included in the number of used satellites (present in the GGA, GNS and<br>PSTMG messages) and their satellites IDs are included in the list of used satellite (present<br>in the GSA message). This bit is disabled by default.|
|15|0x8000|RESERVED||
|16|0x10000|RESERVED||
|17|0x20000|RESERVED||
|18|0x40000|RESERVED||
|19|0x80000|RESERVED||
|20|0x100000|RESERVED||
|21|0x200000|External RTC oscillator<br>enable|Enable/disable the usage on an external oscillator for the RTC peripheral. When enabled<br>the internal oscillator is not used and the RTC clock must be fed from the xtal_in pin|
|22|0x400000|RESERVED||
|23|0x800000|RESERVED||
|24|0x1000000|RESERVED||
|25|0x2000000|RESERVED||
|26|0x4000000|RTC calibration enable|Enable/disable the RTC calibration feature. When enabled the RTC counter is calibrated<br>using the accurate GNSS internal time reference.|
|27|0x8000000|RESERVED||
|28|0x10000000|RESERVED||
|29|0x20000000|RESERVED||
|30|0x40000000|LLI interface Enable/Disable|Enable/disable Low Latency Interface|
|31|0x80000000|Min week handler switch|Automatically manage Min Wek number|



_1. The Bit-value indicates the bit position (starting from 0 as least significant bit), thus multiple choices are possible._ 

- _Note: • if the ST-AGNSS feature is not required (bit 4) and it is disabled, it is strongly suggested to clear all STAGNSS data from the NVM memory. This can be done via NMEA sending the_ 

      - _“$PSTMSTAGPSINVALIDATE,7” command. If the NVM was empty (e.g. the ST-AGNSS has been never enabled or the NVM has been completely erased before) the invalidate command is not required._ 

   - _When GPS and GLONASS constellation are enabled, the GSV messages are sent in two separate sets: one with “GP” as talker ID and one with “GL”._ 

   - _Only “GN” is supported as talker ID for QZSS GSV and GSA messages._ 

   - _In this case the GSV messages are sent in a single set reporting satellites for all enabled constellations._ 

## **12.24 CDB-ID 202 – NCO range max value** 

Allow setting the upper limit for the NCO search range. 

The NCO range and center frequency settings depend on the TCXO in use. There is the possibility to let the GNSS software to evaluate automatically the best range and center values for the selected TCXO. In such case all NCO configuration parameters (CDB-ID 202, 203 and 204) must be set to 0. 

System reboot need to have new setting in use. 

_Note: configured value is used only if the NCO value is not yet stored in the GNSS backup memory._ 

## **12.25 CDB-ID 203 – NCO range min value** 

Allow setting the lower limit for the NCO search range. 

**UM2791** - **Rev 3** 

**page 195/241** 

**UM2791 CDB-ID 204 – NCO centre value** 

The NCO range and center frequency settings depend on the TCXO in use. There is the possibility to let the GNSS software to evaluate automatically the best range and center values for the selected TCXO. In such case all NCO configuration parameters (CDB-ID 202, 203 and 204) must be set to 0. 

System reboot needed to have new setting in use. 

_Note:_ 

_configured value is used only if the NCO value is not yet stored in the GNSS backup memory._ 

## **12.26 CDB-ID 204 – NCO centre value** 

Allow setting the NCO centre frequency. 

The NCO range and center frequency settings depend on the TCXO in use. There is the possibility to let the GNSS software to evaluate automatically the best range and center values for the selected TCXO. In such case all NCO configuration parameters (CDB-ID 202, 203 and 204) must be set to 0. 

System reboot needed to have new setting in use. 

_Note:_ 

_configured value is used only if the NCO value is not yet stored in the Teseo-Module backup memory._ 

## **12.27** 

## **CDB-ID 205 – position data time delay** 

Allow setting the time delay (ms) between the measurements (on the UTC second) and the GNSS position data delivery. This parameter should be never bigger than the time period of the configured fix rate. 

If “0” is used, the time delay is set in accordance with the CPU speed: 

- 50 ms if CPU is running @ 208 MHz 

- 500 ms if CPU is running @ 52 MHz 

System reboot need to have new setting in use. 

## **12.28 CDB-ID 213 – PPS operating mode setting 1** 

Allow setting different operating modes for the PPS signal generation. Full operating mode setting is achieved using both 213 and 214 parameters. This parameter includes different fields as reported in the following table: 

**Table 225. CDB-ID 213 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[3 : 0]|0: on every second<br>1: on even seconds<br>2: on odd seconds|PPS generation mode|
|[7 : 4]|0: UTC<br>1: GPS_UTC (GPS Time)<br>2: GLONASS_UTC (GLONASS Time)<br>3: UTC_SU<br>4: GPS_UTC_FROM_GLONASS|Reference time on which the PPS signal is synchronized.<br>NOTES:<br>•<br>UTC(SU) is the Soviet Union UTC, it is derived from GLONASS time<br>applying the UTC delta time downloaded from GLONASS satellites.<br>•<br>GPS_UTC_FROM_GLONASS is the GPS time derived from GLONASS<br>time applying the GPS delta time downloaded from GLONASS<br>satellites.<br>•<br>If the software is configured to work in GLONASS only mode, UTC(SU)<br>is identical to UTC and GPS_UTC_FROM_GLONASS is identical to<br>GPS_UTC.|
|[11 :<br>8]|1: NO FIX<br>2: 2D FIX<br>3: 3D FIX|GNSS fix condition for PPS signal generation.<br>NO FIX: PPS signal is present even in GNSS NO fix conditions.<br>2D FIX: the PPS is present if the GNSS is at least in 2D fix condition.<br>3D FIX: the PPS is present only if the GNSS is in 3D fix conditions.|



**UM2791** - **Rev 3** 

**page 196/241** 

**UM2791 CDB-ID 214 – PPS operating mode setting 2** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[23 :<br>16]|0..24|Minimun number of satellites used for timing correction. PPS signal is<br>generated if the number of satellites used for time correction is bigger than the<br>minimun number. This parameter should be set to 0 if the threshold is not<br>used.|
|[24 :<br>31]|0..90|Satellite elevation mask for time correction. It is the minimum satellite<br>elevation angle to use the satellite for time correction. If this parameter is set<br>to 0 there is no satellites filtered based on the elevation.|



## **12.29 CDB-ID 214 – PPS operating mode setting 2** 

Allow setting different operating modes for the PPS signal generation. Full operating mode setting is achieved using both 213 and 214 parameters. This parameter includes different fields as reported in the following table: 

**Table 226. CDB-ID 214 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|0: mixing constellation disabled<br>1: GPS sats are enabled for GLONASS time correction.<br>2: GLONASS sats are enabled for GPS time correction.|Enable/disable mixing constellations for time correction.|



## **12.30 CDB-ID 215 – position hold auto survey samples** 

Sets the number of position samples to be captured before entering in the position hold mode. The auto survey procedure is disabled if the number of samples is set to 0. 

## **12.31 CDB-ID 218 – SBAS satellite parameter** 

Allow to add or modify a SBAS satellite parameter into default list 

**Table 227. CDB-ID 218 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|From 120 to 138|SBAS PRN|
|[15 : 8]|From 0 to 180|Satellite longitude in degree|
|[16]|0: EAST<br>1: WEST|Longitude sense|
|[18 : 17]|0: WAAS<br>1: EGNOS<br>2: MSAS<br>3:GAGAN|The SBAS service|



## **12.32 CDB-ID 219 – SBAS satellite parameter** 

Allow to add or modify a SBAS satellite parameter into default list. 

**Table 228. CDB-ID 219 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|From 120 to 138|SBAS PRN|



**UM2791** - **Rev 3** 

**page 197/241** 

**UM2791 CDB-ID 220 – adaptive and cyclic operating mode setting 1** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[15 : 8]|From 0 to 180|Satellite longitude in degree|
|[16]|0: EAST<br>1: WEST|Longitude sense|
|[18 : 17]|0: WAAS<br>1: EGNOS<br>2: MSAS<br>3:GAGAN|The SBAS service|



## **12.33 CDB-ID 220 – adaptive and cyclic operating mode setting 1** 

Allow setting different operating modes for the adaptive low power algorithm. This parameter includes different fields as reported in the following table: 

**Table 229. CDB-ID 220 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[0]|0/1|Enable/disable the Adaptive feature multi-constellation algorithm.<br>0: Disabled<br>1: Enabled|
|[1]|0/1|Enable/disable the Adaptive feature Duty Cycle:<br>0: Disabled<br>1: Enabled|
|[3 : 2]||RESERVED for further usage|
|**Adaptive mode settings**|||
|[11 : 4]|0….255|EHPE average threshold [m]|
|[19 : 12]|0…32|first N satellites (with higher elevation) used for the position calculation (Active channel management) in<br>LOW POWER STATE|
|**Cyclic mode settings**|||
|[31 : 20]|100…740|Duty cycle signal off [ms]|



## **12.34 CDB-ID 222 – LMS operating mode setting 1** 

**Table 230. CDB-ID 222 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[0]|0/1|2D Fix enable/disable:<br>•<br>0: disable<br>•<br>1: enable|
|[1]|0/1|HDOP product in range error metric enable/disable:<br>•<br>0: disable<br>•<br>1: enable|
|[2]|0/1|GLONASS path delay lock enable/disable:<br>•<br>0: disable<br>•<br>1: enable|
|[15 : 8]|0..255|Position residual threshold [m]|



**UM2791** - **Rev 3** 

**page 198/241** 

**UM2791** 

**CDB-ID 223 – LMS operating mode setting 2** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[23: 16]|0..255|Position residual threshold after RAIM [m]|



## **12.35 CDB-ID 223 – LMS operating mode setting 2** 

## **Table 231. CDB-ID 223 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|0..255|Minimum number of satellites in GNSS mode|
|[15 : 8]|0..255|Minimum number of satellites in single constellation mode|
|[31: 16]|-32768..32767|Initial GLONASS path delay [dm]. (It is expressed in 2-complements on 16 bits)|



## **12.36 CDB-ID 231 – CDB-ID 232 - NMEA on I2C port message list 0** 

Allow enabling/disabling each NMEA message in the message list 0 used for sending messages over the I2C port. CDB-ID 231 represents first 32 bits (low bits) of extended 64 bits NMEA message list. See CDB-ID 232 for second 32 bits (high bits) of 64 bits message list. The message list configuration is done in the same way as for the NMEA message list 0 (see CDB-ID 201 and CDB-ID 228 for details). See CDB-ID 201 also for supported message list table. 

## **12.37 CDB-ID 233 – CDB-ID 234 - NMEA on I2C port message list 1** 

Allow enabling/disabling each NMEA message in the message list 1 used for sending messages over the I2C port. CDB-ID 233 represents first 32 bits (low bits) of extended 64 bits NMEA message list. See CDB-ID 234 for second 32 bits (high bits) of 64 bits message list. The message list configuration is done in the same way as for the NMEA message list 0 (see CDB-ID 201 and CDB-ID 228 for details). See CDB-ID 201 also for supported message list table. 

## **12.38 CDB-ID 235 – CDB-ID 236 - NMEA on I2C port message list 2** 

Allow enabling/disabling each NMEA message in the message list 2 used for sending messages over the I2C port. CDB-ID 235 represents first 32 bits (low bits) of extended 64 bits NMEA message list. See CDB-ID 236 for second 32 bits (high bits) of 64 bits message list. The message list configuration is done in the same way as for the NMEA message list 0 (see CDB-ID 201 and CDB-ID 228 for details). See CDB-ID 201 also for supported message list table. 

If not used the message list must be set to “0” (both CDB-ID 235 and CDB-ID 236 must be set to 0). It must be set to “0” also when the dual NMEA port feature is disabled (see CDB-ID 103 for details on enabling/disabling dual NMEA port). 

## **12.39 CDB-ID 237 – default GPS MIN-MAX week number** 

Allow setting of minimum and maximum GPS week number. 

Minimum week number is used for correct GPS week decoding. Teseo-Module software is able to decode correctly the GPS week number for a number of 1024 weeks (about 20 years) starting from minimum week number. 

Maximum week number is used for GPS week validity check. It must be set at least 1024 weeks ahead to the minimum week number. 

**Table 232. CDB-ID 237 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[15 : 0]|0..65535|GPS minimum week number|



**UM2791** - **Rev 3** 

**page 199/241** 

**UM2791 CDB-ID 238 – default UTC delta time** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[31 : 16]|0..65535|GPS maximum week number|



- _Note: • The minimum week number should be moved ahead along years to guarantee at least 20 years of correct week decoding in the future_ 

   - _as soon as the max week number is reached, the Teseo-Module software is no more able to validate the time and so it is no more able to achieve the GNSS position fix_ 

## **12.40 CDB-ID 238 – default UTC delta time** 

Allow setting the default value for the GPS time to UTC delta time seconds (leap seconds). This parameter is used by the Teseo-Module software only if the UTC backup data is not available in the backup memory (e.g. first start up after production or in case of backup memory content lost occurrence). 

## **12.41 CDB-ID 257 – periodic operating mode setting 1** 

Configure the periodic low power mode. This CBD has to be combined with CBD-258.This parameter includes different fields as reported in the following table: 

## **Table 233. CDB-ID 257 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[1 : 0]|0, 1, 2, 3|Periodic feature set Enable/Disable:<br>0: Periodic mode OFF<br>1: Active Periodic mode<br>2: Reserved<br>3: Standby Periodic mode|
|[2]|0/1|Ephemeris refresh required:<br>0: disabled<br>1: enabled|
|[3]|0/1|RTC calibration required:<br>0: disabled<br>1: enabled|
|[7 : 4]||RESERVED|
|[24 : 8]|0..86400|FixPeriod [s]. 0 means the Fix will be given only on WAKEUP pin activation. Value 0 is only valid in<br>Standby Periodic mode.|
|[31 : 25]|1..127|FixOnTime - Number of fix to report every fix wakeup.|



## **12.42** 

## **CDB-ID 258 – periodic operating mode setting 2** 

Configure the periodic low power mode. This CBD has to be combined with CBD-257.This parameter includes different fields as reported in the following table: 

## **Table 234. CDB-ID 258 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|0..255|NoFixCnt [s] - Time to declare fix loss in HOT conditions.|
|[19 : 8]|0..4095|NoFixOff [s] - Off duration time after a fix loss event.|
|[28 : 20]|0..300|NoFixCnt2 [s] – Time to declare fix loss in non-HOT conditions – startup case, obsolete ephemeris …|



**UM2791** - **Rev 3** 

**page 200/241** 

**UM2791 CDB-ID 260 – WLS algorithm configuration** 

## **12.43 CDB-ID 260 – WLS algorithm configuration** 

Allow to configure the WLS algorithm implemented in the positioning stage. 

## **Table 235. CDB-ID 260 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[0]|0..1|Enable/Disable the WLS algorithm usage in the positioning stage.<br>0: disabled<br>1: enabled|
|[7 : 1]|xxx|Not used|
|[15 : 8]|1..100|Parameter1 multiplied by 10.<br>Parameter1 is a coefficient to change the measurements weighting in the position filter.<br>Allowed values are from 0.1 to 10.0 (suggested value is 1.0)<br>•<br>means high acceptance of satellites measurements in the position filter<br>10.0 means low acceptance of satellites measurements in the position filter|
|[23 : 16]|10..100|Parameter2 multiplied by 10.<br>Parameter2 is a coefficient to change the measurements acceptance threshold.<br>Allowed values are from 1.0 to 10.0 (suggested value is 2.5)<br>•<br>means strong satellite exclusions by FDE (high false alarm rate)<br>10.0 means relaxed satellites exclusions by FDE.|



## **12.44 CDB-ID 261 – dynamic modes configuration** 

Allow to configure supported dynamic modes for the satellites tracking engine. This configuration replaces the old high/low dynamic setting in the CDB-ID 200 bit mask 0x20000000. 

_Note: The old High/Low setting is still operative for backward compatibility reasons. To use CDB-ID 261 the CDB-ID 200 bit mask 0x20000000 must be set to 0._ 

**Table 236. CDB-ID 261 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[3 : 0]|0, 1, 2, 3|Dynamic mode selection.<br>0: Low Dynamic<br>1: High Dynamic<br>2: RESERVED<br>3: Auto Dynamic|



## **12.45 CDB-ID 263 – NMEA over I2C configuration** 

Allow configuring the NMEA over I2C. 

**Table 237. CDB-ID 263 field description** 

|**Bits**|**Values**|**Description**|**Default**|
|---|---|---|---|
|[1: 0]|0..3|RESERVED|1|
|[5 :2]|-|RESERVED|0|
|[15 : 6]|0..0x3F|Slave address|0x3A|



**UM2791** - **Rev 3** 

**page 201/241** 

**UM2791 CDB-ID 268 – geofencing configuration 0** 

|**Bits**|**Values**|**Description**|**Default**|
|---|---|---|---|
|31 : 16]|0..2|RESERVED|0|



## **12.46 CDB-ID 268 – geofencing configuration 0** 

Geofencing configuration field 0. 

**Table 238. CDB-ID 268 field description** 

|**Bits**|**Values**|**Description**|**Default**|
|---|---|---|---|
|`[0]`|0..1|0 = Geofencing disabled on boot<br>1 = Geofencing enabled on boot|0|
|`[2 : 1]`|0..3|Geofencing tolerance|0x1|
|`[3]`|0 .. 1|0 = Autostart disabled<br>1 = Autostart enabled|0|
|`[7 : 4]`|-|RESERVED|0x1|
|`[8]`|0..1|0 = Circle 0 disabled<br>1 = Circle 0 enabled|0x1|
|`[9]`|0..1|0 = Circle 1 disabled<br>1 = Circle 1 enabled|0x1|
|`[10]`|0..1|0 = Circle 2 disabled<br>1 = Circle 2 enabled|0x1|
|`[11]`|0..1|0 = Circle 3 disabled<br>1 = Circle 3 enabled|0x1|
|`[31 : 12]`|-|RESERVED|0|



## **12.47 CDB-ID 270 – odometer configuration** 

Odometer configuration field. 

**Table 239. CDB-ID 270 field description** 

|**Bits**|**Values**|**Description**|**Default**|
|---|---|---|---|
|`[0]`|0..1|0: Odometer disabled on boot<br>1: Odometer enabled on boot|0|
|`[1]`|0..1|0: Odometer related NMEA messages disabled<br>1: Odometer related NMEA messages enabled|0|
|`[15 : 2]`|-|RESERVED|0|
|`[31 : 16]`|0..1|Distance in meter to trigger the alarm|0x03E8|



## **12.48 CDB-ID 272 – GNSS integrity check configuration** 

Position and time integrity check enabling/disabling. 

**UM2791** - **Rev 3** 

**page 202/241** 

**UM2791** 

**CDB-ID 300 – low latency Interface rate** 

## **Table 240. CDB-ID 271 field description** 

|**Bits**|**Values**|**Description**|**Default**|
|---|---|---|---|
|`[0]`|0..1|0: Position integrity check disabled<br>1: Position integrity check enabled|0|
|`[1]`|0..1|0: Time integrity check disabled<br>1: Time integrity check enabled|0|



## **12.49** 

## **CDB-ID 300 – low latency Interface rate** 

Allow setting the Low Latency Interface rate. It is the time period between two consecutive NMEA message (only working on message-list-2). 

System reboot needed to have new setting in use. 

## **12.50** 

## **CDB-ID 301 – PPS pulse duration** 

Allow setting the pulse duration of the PPS signal. The pulse duration is intended to be the time distance between the PPS rising edge and the next falling edge if polarity inversion is disabled or the time distance between falling and rising edge if polarity inversion is enabled. 

## **12.51** 

## **CDB-ID 302 – PPS delay correction** 

Allow setting a time correction to compensate any delay introduced on the pulse per second (PPS) signal by cables and/or RF chain. 

## **12.52 CDB-ID 304 – position hold latitude** 

Allow setting the latitude [degrees] for the position hold mode. 

_Note: to be used the position hold functionality must be enabled, see CDB-ID 200 for details._ System reboot needed to have new setting in use. 

## **12.53** 

## **CDB-ID 305 – position hold longitude** 

Allow setting the longitude [degrees] for the position hold mode 

_Note: to be used the position hold functionality must be enabled, see CDB-ID 200 for details._ System reboot needed to have new setting in use. 

## **12.54** 

## **CDB-ID 306 – position hold altitude** 

Allow setting the altitude [m] for the position hold mode. 

The altitude to be configured in this parameter must not be compensated with the geoid correction. If the altitude value is retrieved by the $GPGGA NMEA message, it must be added to the geoid correction (reported in the same $GPGGA message) before setting it in the CDB-ID 306 parameter. 

System reboot needed to have new setting in use. 

_Note:_ 

- _to be used the position hold functionality must be enabled, see CDB-ID 200 for details_ 

## **12.55** 

## **CDB-ID 307 – GPS RF delay correction** 

Allow setting the RF time delay for the GPS signal path. The RF compensation for GPS is independent by the PPS clock setting. The value calibrated for the ST reference design is 713E-9 s. 

**UM2791** - **Rev 3** 

**page 203/241** 

**UM2791 CDB-ID 308 – GLONASS RF delay correction** 

## **12.56 CDB-ID 308 – GLONASS RF delay correction** 

Allow setting the RF time delay for the GLONAS signal path. The RF compensation for GLONASS depends on the PPS clock setting (see CDB-ID). Here are the values calibrated for the ST reference design. 

## **Table 241. CDB-ID 308 field description** 

|**PPS Clock Setting**|**GLONASS RF Correction**|
|---|---|
|32 MHz|-|
|64 MHz|-|



_Note: If the PPS clock setting is changed in the configuration block, also the GLONASS RF delay correction must be changed accordingly. For accurate timing applications is strongly recommended to set PPS clock to 64 MHz._ 

## **12.57** 

## **CDB-ID 309 – TRAIM alarm threshold** 

Allow setting the time error threshold for satellites removal in the TRAIM algorithm. Satellites which have a time error bigger than the TRAIM threshold are not used for time correction. The TRAIM threshold is also used to rise the TRAIM alarm if the time correction error is bigger than it. 

## **12.58 CDB-ID 310 – BeiDou RF delay correction** 

Allow setting the RF time delay for BeiDou signal path. 

## **12.59 CDB-ID 311 – GALILEO RF delay correction** 

Allow setting the RF time delay for GALILEO signal path. 

## **12.60 CDB-ID 314 – CDB-ID 315 – CDB-ID 316 – geofencing circle 0** 

Allows to set up the geofencing circle number 0 parameters. 

**Table 242. Geofencing circle 0 field description** 

|**CDB-ID**|**Type value**|**Description**|
|---|---|---|
|314|Double precision floating number|Circle latitude|
|315|Double precision floating number|Circle longitude|
|316|Double precision floating number|Circle radius in meters|



## **12.61 CDB-ID 317 – CDB-ID 318 - CDB-ID 319 - geofencing circle 1** 

Allows to set up the geofencing circle number 1 parameters. 

**Table 243. Geofencing circle 1 field description** 

|**CDB-ID**|**Type value**|**Description**|
|---|---|---|
|317|Double precision floating number|Circle latitude|
|318|Double precision floating number|Circle longitude|
|319|Double precision floating number|Circle radius in meters|



**UM2791** - **Rev 3** 

**page 204/241** 

**UM2791 CDB-ID 320 – CDB-ID 321 – CDB-ID 322 – geofencing circle 2** 

## **12.62 CDB-ID 320 – CDB-ID 321 – CDB-ID 322 – geofencing circle 2** 

Allows to set up the geofencing circle number 2 parameters. 

**Table 244. Geofencing circle 2 field description** 

|**CDB-ID**|**Type value**|**Description**|
|---|---|---|
|320|Double precision floating number|Circle latitude|
|321|Double precision floating number|Circle longitude|
|322|Double precision floating number|Circle radius in meters|



## **12.63 CDB-ID 323 – CDB-ID 324 – CDB-ID 325 – geofencing circle 3** 

Allows to set up the geofencing circle number 3 parameters. 

**Table 245. Geofencing circle 3 field description** 

|**CDB-ID**|**Type value**|**Description**|
|---|---|---|
|323|Double precision floating number|Circle latitude|
|324|Double precision floating number|Circle longitude|
|325|Double precision floating number|Circle radius in meters|



## **12.64 CDB-ID 400 – default 2D DOP** 

Allow setting the default value for the 2D DOP. This value is used at run-time, after the GNSS start-up phase, as a threshold for the 2D fix validation. DOP below this threshold will be considered valid for position fixing. System reboot needed to have new setting in use. 

## **12.65** 

## **CDB-ID 401 – default 3D DOP** 

Allow setting the default value for the 3D DOP. This value is used at run-time, after the GNSS start-up phase, as a threshold for the 3D fix validation. DOP below this threshold will be considered valid for position fixing. System reboot needed to have new setting in use. 

## **12.66** 

## **CDB-ID 402 – start-up 2D DOP** 

Allow setting the start-up value for the 2D DOP. This value is used during the GNSS start-up phase as a threshold for the 2D fix validation. DOP below this threshold will be considered valid for position fixing. System reboot needed to have new setting in use. 

## **12.67 CDB-ID 403 – start-up 3D DOP** 

Allow setting the start-up value for the 3D DOP. This value is used during the GNSS start-up phase as a threshold for the 3D fix validation. DOP below this threshold will be considered valid for position fixing. System reboot need to have new setting in use. 

## **12.68** 

## **CDB-ID 500 – Text message** 

Allow setting a text message which is sent (if enabled – see bit9 of CDB-ID 200 parameter) at start-up over the NMEA port. The user is free to use this text as product name or as specific configuration marker. System reboot need to have new setting in use. 

**UM2791** - **Rev 3** 

**page 205/241** 

**UM2791 CDB-ID 600 – DRAW main setting** 

## **12.69 CDB-ID 600 – DRAW main setting** 

This data block contains configurations parameters which are the key for Dead-Reckoning workings, i.e. which sensors to enable and use for navigation solution, along with the output rate for both sensor and navigation data. 

**Table 246. CDB-ID 600 field description** 

|**Bits**|**Values**|**Description**|
|---|---|---|
|[7 : 0]|0x16|Reserved (must be 0x16)|
|[14 : 8]|1|Operating mode:<br>•<br>1: odo and reverse over pin (default)<br>•<br>3: odo and reverse over UART<br>•<br>5: speed and reverse over UART|
|[19 : 15]||Reserved|
|[29 : 20]|15 .. 0|Dead-reckoning fix rate|
|[31]|0|Reserved (must be 0x0)|



## **12.70 CDB-ID 653 – DRAW vehicle geometry** 

This data block contains settings specific parameters related to vehicle geometry, as the wheel size, distance and number of pulses per revolution, that are included in the mathematical model used by Teseo-DRAW. 

**Table 247. CDB-ID 653 field description** 

|**Bits**|**Description**|
|---|---|
|`[11 : 0]`|nominal wheel circumference|
|`[23 : 12]`|represents nominal track distance, i.e. the distance between vehicle rear wheels|
|`[31 : 24]`|number of wheel pulses equalling a full wheel revolution|



## **12.71 CDB-ID 667 – DRAW algorithm On/Off** 

## **12.72 CDB-ID 668 – DRAW installation angles** 

This parameter allows to define board installation angles, in order to optimize gyro performance on target vehicle installation. It is of interest only for systems including an onboard 3 axis digital gyroscope without 3 axis accelerometer. 

**Table 248. CDB-ID 668 field description** 

|**Bits**|**Description**|
|---|---|
|[8 : 0]|Installation YAW|
|[17 : 9]|Installation ROLL|
|[26 : 18]|Installation Pitch|
|[31 : 27]|Reserved (must be 0x0)|



**UM2791** - **Rev 3** 

**page 206/241** 

**UM2791 Local geodetic datum tables** 

## **Appendix A Local geodetic datum tables** 

## **Table 249. Africa** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**ADINDAN**|||
|MeanSolution(Ethiopia-Sudan)|ADI-M|0|
|BurkinaFaso|ADI-E|1|
|Cameroon|ADI-F|2|
|Ethiopia|ADI-A|3|
|Mali|ADI-C|4|
|Senegal|ADI-D|5|
|Sudan|ADI-B|6|
|**AFGOOYE**|||
|Somalia|AFG|7|
|**ARC_1950**|||
|Mean_Solution|ARF-M|8|
|Botswana|ARF-A|9|
|Burundi|ARF-H|10|
|Lesotho|ARF-B|11|
|Malawi|ARF-C|12|
|Swaziland|ARF-D|13|
|Zaire|ARF-E|14|
|Zambia|ARF-F|15|
|Zimbabwe|ARF-G|16|
|**ARC_1960**|||
|Mean_Solution|ARS-M|17|
|Kenya|ARS-A|18|
|Tanzania|ARS-B|19|
|**AYABELLE_LIGHTHOUSE**|||
|Djibouti|PHA|20|
|**BISSAU**|||
|Guinea-Bissau|BID|21|
|**CAPE**|||
|South_Africa|CAP|22|
|**CARTHAGE**|||
|Tunisia|CGE|23|
|**DABOLA**|||
|Guinea|DAL|24|
|**EUROPEAN_1950**|||
|Egypt|EUR-F|73|
|Tunisia|EUR-T|83|



**UM2791** - **Rev 3** 

**page 207/241** 

**UM2791 Local geodetic datum tables** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**LEIGON**|||
|Ghana|LEH|25|
|**LIBERIA_1964**|||
|Liberia|LIB|26|
|**MASSAWA**|||
|Eritrea(Ethiopia)|MAS|27|
|**MERCHICH**|||
|Morocco|MER|28|
|**MINNA**|||
|Cameroon|MIN-A|29|
|Nigeria|MIN-B|30|
|**M'PORALOKO**|||
|Gabon|MPO|31|
|**NORTH_SAHARA_1959**|||
|Algeria|NSD|32|
|**OLD_EGYPTIAN_1907**|||
|Egypt|OEG|33|
|**POINT_58**|||
|Mean_Solution (BurkinaFaso-Niger)|PTB|34|
|**POINTE_NOIRE_1948**|||
|Congo|PTN|35|
|**SCHWARZECK**|||
|Namibia|SCK|36|
|**SIERRA_LEONE_1960**|||
|SierraLeone|SRL|37|
|**VOIROL_1960**|||
|Algeria|VOR|38|



**UM2791** - **Rev 3** 

**page 208/241** 

**UM2791 Local geodetic datum tables** 

## **Table 250. Asia** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**AIN_EL_ABD_1970**|||
|Bahrain_Island|AIN-A|39|
|Saudi_Arabia|AIN-B|40|
|**DJAKARTA(BATAVIA)**|||
|Sumatra(Indonesia)|BAT|41|
|**EUROPEAN_1950**|||
|Iran|EUR-H|77|
|**HONG_KONG_1963**|||
|Hong_Kong|HKD|42|
|**HU-TZU-SHAN**|||
|Taiwan|HTN|43|
|**INDIAN**|||
|Bangladesh|IND-B|44|
|India-Nepal|IND-I|45|
|**INDIAN_1954**|||
|Thailand|INF-A|46|
|**INDIAN_1960**|||
|Vietnam(near_16DegNorth)|ING-A|47|
|ConSonIsland(Vietnam)|ING-B|48|
|**INDIAN_1975**|||
|Thailand|INH-A|49|
|Thailand|INH-A1|50|
|**INDONESIAN_1974**|||
|Indonesia|IDN|51|
|**KANDAWALA**|||
|SriLanka|KAN|52|
|**KERTAU_1948**|||
|WestMalaysia-Singapore|KEA|53|
|**KOREAN_1995**|||
|SouthKorea|KGS|54|
|**NAHRWAN**|||
|MasirahIsland(Oman)|NAH-A|55|
|UnitedArabEmirates|NAH-B|56|
|SaudiArabia|NAH-C|57|
|**OMAN**|||
|Oman|FAH|58|
|**QATAR_NATIONAL**|||
|Qatar|QAT|59|
|**SOUTH_ASIA**|||
|Singapore|SOA|60|



**UM2791** - **Rev 3** 

**page 209/241** 

**UM2791 Local geodetic datum tables** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
||||
|**TIMBALAI_1948**|||
|Brunei-East_Malaysia|TIL|61|
|**TOKYO**|||
|MeanSolution|TOY-M|62|
|Japan|TOY-A|63|
|Okinawa|TOY-C|64|
|South Korea|TOY-B|65|
|South Korea|TOY-B1|66|



## **Table 251. Australia** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**AUSTRALIAN_1966**|||
|Australia-Tasmania|AUA|67|
|**AUSTRALIAN_1984**|||
|Australia-Tasmania|AUG|68|



**UM2791** - **Rev 3** 

**page 210/241** 

**UM2791 Local geodetic datum tables** 

## **Table 252. Europe** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**CO-ORDINATE SYSTEM 1937 OF ESTONIA**|||
|Estonia|EST|69|
|**EUROPEAN_1950**|||
|MeanSolution|EUR-M|70|
|WesternEurope|EUR-A|71|
|Cyprus|EUR-E|72|
|Egypt|EUR-F|73|
|England,ChannelIslands,Scotland,ShetlandIslands|EUR-G|74|
|England,Ireland,Scotland,ShetlandIslands|EUR-K|75|
|Greece|EUR-B|76|
|Iran|EUR-H|77|
|ItalySardinia|EUR-I|78|
|ItalySicily|EUR-J|79|
|Malta|EUR-L|80|
|Norway,Finland|EUR-C|81|
|Portugal,Spain|EUR-D|82|
|Tunisia|EUR-T|83|
|**EUROPEAN_1979**|||
|MeanSolution|EUS|84|
|**HJORSEY_1955**|||
|Iceland|HJO|85|
|**IRELAND_1965**|||
|Ireland|IRL|86|
|**ORDNANCE SURVEY OF GREAT BRITAIN 1936**|||
|MeanSolution|OGB-M|87|
|England|OGB-A|88|
|England,IsleOfMan,Wales|OGB-B|89|
|Scotland,ShetlandIslands|OGB-C|90|
|Wales|OGB-D|91|
|**ROME_1940**|||
|Sardinia|MOD|92|
|**S-42(PULKOVO_1942)**|||
|Hungary|SPK-A|93|
|Poland|SPK-B|94|
|Czechoslovakia*|SPK-C|95|
|Latvia|SPK-D|96|
|Kazakhstan|SPK-E|97|
|Albania|SPK-F|98|
|Romania|SPK-G|99|
|**S-JTSK**|||



**UM2791** - **Rev 3** 

**page 211/241** 

**UM2791 Local geodetic datum tables** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|Czechoslovakia|CCD|100|



## **Table 253. North america** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**CAPE_CANAVERAL**|||
|MeanSolution(Florida,Bahamas)|CAC|101|
|**NORTH AMERICAN 1927**|||
|MeanSolution|NAS-C|102|
|WesternUnitedStates|NAS-B|103|
|EasternUnitedStates|NAS-A|104|
|Alaska(ExcludingAleutianIslands)|NAS-D|105|
|AleutianIslands(East180°W)|NAS-V|106|
|AleutianIslands(West180°W)|NAS-W|107|
|Bahamas(Excluding San Salvador Island)|NAS-Q|108|
|SanSalvadorIsland|NAS-R|109|
|CanadaMeanSolution(Including Newfoundland)|NAS-E|110|
|Alberta,BritishColumbia|NAS-F|111|
|EasternCanada|NAS-G|112|
|Manitoba,Ontario|NAS-H|113|
|NorthwestTerritories,Saskatchewan|NAS-I|114|
|Yukon|NAS-J|115|
|CanalZone|NAS-O|116|
|Caribbean|NAS-P|117|
|CentralMerica|NAS-N|118|
|Cuba|NAS-T|119|
|Greenland|NAS-U|120|
|Mexico|NAS-L|121|
|**NORTH AMERICAN 1983**|||
|Alaska(ExcludingAleutianIslands)|NAR-A|122|
|AleutianIslands|NAR-E|123|
|Canada|NAR-B|124|
|CONUS|NAR-C|125|
|Hawaii|NAR-H|126|
|Mexico,CentralAmerica|NAR-D|127|



**UM2791** - **Rev 3** 

**page 212/241** 

**UM2791 Local geodetic datum tables** 

## **Table 254. South america** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**BOGOTA OBSERVATORY**|||
|Colombia|BOO|128|
|**CAMPO NCHAUSPE 1969**|||
|Argentina|CAI|129|
|**CHUA ASTRO**|||
|Paraguay|CHU|130|
|**CORREGO ALEGRE**|||
|Brazil|COA|131|
||||
|**PROVISIONAL SOUTH AMERICAN 1956**|||
|MeanSolution|PRP-M|132|
|Bolivia|PRP-A|133|
|Northern Chile(near 19°S)|PRP-B|134|
|Southern Chile(near 43°S)|PRP-C|135|
|Colombia|PRP-D|136|
|Ecuador|PRP-E|137|
|Guyana|PRP-F|138|
|Peru|PRP-G|139|
|Venezuela|PRP-H|140|
|**PROVISIONAL SOUTH CHILEAN**|||
|Southern Chile (near 53°S)|HIT|141|
|**SOUTH AMERICAN 1969**|||
|MeanSolution|SAN-M|142|
|Argentina|SAN-A|143|
|Bolivia|SAN-B|144|
|Brazil|SAN-C|145|
|Chile|SAN-D|146|
|Colombia|SAN-E|147|
|Ecuador (Excluding Galapagos Islands)|SAN-F|148|
|Baltra,Galapagos Islands|SAN-J|149|
|Guyana|SAN-G|150|
|Paraguay|SAN-H|151|
|Peru|SAN-I|152|
|Trinidad and Tobago|SAN-K|153|
|Venezuela|SAN-L|154|
|**SOUTH AMERICAN GEOCENTRIC REFERENCE SYSTEM(SIRGAS)**|||
|South America|SIR|155|
|**ZANDERIJ**|||
|Suriname|ZAN|156|



**UM2791** - **Rev 3** 

**page 213/241** 

**UM2791 Local geodetic datum tables** 

## **Table 255. Atlantic ocean** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**ANTIGUA ISLAND ASTRO 1943**|||
|Antigua,Leeward Islands|AIA|157|
|**ASCENSION ISLAND 1958**|||
|Ascension Island|ASC|158|
|**ASTRO DOS 71/4**|||
|St.Helena Island|SHB|159|
|**BERMUDA 1957**|||
|Bermuda Islands|BER|160|
|**CAPE CANAVERAL**|||
|Mean Solution (Bahamas and Florida)|CAC|101|
|**DECEPTION ISLAND**|||
|Deception Islandand Antarctica|DID|161|
|**FORT THOMAS 1955**|||
|Nevis, St.Kitts and Leeward Islands|FOT|162|
|**GRACIOSA BASE SW 1948**|||
|Faial, Graciosa, Pico, SaoJorge and Terceira Islands (Azores)|GRA|163|
|**HJORSEY 1955**|||
|Iceland|HJO|85|
|**ISTS 061 ASTRO 1968**|||
|South Georgia Island|ISG|164|
|**L.C. 5 ASTRO 1961**|||
|Cayman Brac Island|LCF|165|
|**MONTSERRAT ISLAND ASTRO 1958**|||
|Montserrat and Leeward Islands|ASM|166|
|**NAPARIMA,BWI**|||
|Trinidad and Tobago|NAP|167|
|**OBSERVATORIO METEOROLOGICO 1939**|||
|Corvo and Flores Islands (Azores)|FLO|168|
|**PICO DE LAS NIEVES**|||
|Canary Islands|PLN|169|
|**PORTO SANTO 1936**|||
|Porto Santo and Madeira Islands|POS|170|
|**PUERTO RICO**|||
|Puerto Rico and Virgin Islands|PUR|171|
|**QORNOQ**|||
|South Greenland|QUO|172|
|**SAO BRAZ**|||
|Sao Miguel and Santa Maria Islands (Azores)|SAO|173|
|**SAPPER HILL 1943**|||
|East Falkland Island|SAP|174|



**UM2791** - **Rev 3** 

**page 214/241** 

**UM2791 Local geodetic datum tables** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**SELVAGEM GRANDE 1938**|||
|Salvage Islands|SGM|175|
|**TRISTAN ASTRO 1968**|||
|Tristan da Cunha|TDC|176|



## **Table 256. Indian ocean** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**ANNA 1 ASTRO 1965**|||
|Cocos Islands|ANO|177|
|**GAN 1970**|||
|Republic of Maldives|GAA|178|
|**ISTS 073 ASTRO 1969**|||
|Diego Garcia|IST|179|
|**KERGUELEN ISLAND 1949**|||
|Kerguelen Island|KEG|180|
|**MAHE 1971**|||
|Mahe Island|MIK|181|
|**REUNION**|||
|Mascarene Islands|REU|182|



**UM2791** - **Rev 3** 

**page 215/241** 

**UM2791 Local geodetic datum tables** 

## **Table 257. Pacific ocean** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**AMERICAN SAMOA 1962**|||
|American Samoa Islands|AMA|183|
|**ASTRO BEACON “E” 1945**|||
|Iwo Jima|ATF|184|
|**ASTRO TERN ISLAND (FRIG) 1961**|||
|Tern Island|TRN|185|
|**ASTRONOMICAL STATION 1952**|||
|Marcus Island|ASQ|186|
|**BELLEVUE (IGN)**|||
|Efate and Erromango Islands|IBE|187|
|**CANTON ASTRO 1966**|||
|Phoenix Islands|CAO|188|
|**CHATHAM ISLAND ASTRO 1971**|||
|Chatham Island (New Zealand)|CHI|189|
|**DOS 1968**|||
|Gizo Island (New Georgia Islands)|GIZ|190|
|**EASTER ISLAND 1967**|||
|Easter Island|EAS|191|
|**GEODETIC DATUM 1949**|||
|New Zealand|GEO|192|
|**GUAM 1963**|||
|Guam|GUA|193|
|**GUX l ASTRO**|||
|Guadalcanal Island|DOB|194|
|**INDONESIAN 1974**|||
|Indonesia|IDN|51|
|**JOHNSTON ISLAND 1961**|||
|Johnston Island|JOH|195|
|**KUSAIE ASTRO 1951**|||
|CarolineIslands, Fed.States of Micronesia|KUS|196|
|**LUZON**|||
|Philippines (Excluding Mindanao Island)|LUZ-A|197|
|Mindanao Island|LUZ-B|198|
|**MIDWAY ASTRO 1961**|||
|Midway Islands|MID_A|199|
|Midway Islands|MID_B|200|
|**OLD_HAWAIIAN**|||
|Mean Solution|OHA-M|201|
|Hawaii|OHA-A|202|
|Kauai|OHA-B|203|



**UM2791** - **Rev 3** 

**page 216/241** 

**UM2791 Local geodetic datum tables** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|Maui|OHA-C|204|
|Oahu|OHA-D|205|
|**OLD HAWAIIAN**|||
|Mean Solution|OHI-M|206|
|Hawaii|OHI-A|207|
|Kauai|OHI-B|208|
|Maui|OHI-C|209|
|Oahu|OHI-D|210|
|**PITCAIRN ASTRO 1967**|||
|Pitcairn Island|PIT|211|
|**SANTO (DOS) 1965**|||
|Espirito Santo Island|SAE|212|
|**VITI LEVU 1916**|||
|VitiLevuIsland (Fiji Islands)|MVS|213|
|**WAKE-ENIWETOK 1960**|||
|Marshall Islands|ENW|214|
|**WAKE ISLAND ASTRO 1952**|||
|Wake Atoll|WAK|215|



**UM2791** - **Rev 3** 

**page 217/241** 

**UM2791 Local geodetic datum tables** 

## **Table 258. Non-satellite derived transformation parameter** 

|**Region**|**Code**|**CDB-ID value**|
|---|---|---|
|**BUKIT RIMPAH**|||
|Bangka and Belitung Islands (Indonesia)|BUR|216|
|**CAMP AREA ASTRO**|||
|Camp McMurdo Area, Antarctica|CAZ|217|
|**EUROPEAN 1950**|||
|Iraq, Israel, Jordan, Kuwait, Lebanon, Saudi Arabia, Syria|EUR-S|218|
|**GUNUNG SEGARA**|||
|Kalimantam (Indonesia)|GSE|219|
|**HERAT NORTH**|||
|Afghanistan|HEN|220|
|**HERMANNSKOGEL**|||
|Slovenia, Croatia, Bosnia and Herzegovina, Serbia|HER|221|
|**INDIAN**|||
|Pakistan|IND_P|222|
|**PULKOVO 1942**|||
|Russia|PUK|223|
|**TANANARIVE OBSERVATORY 1925**|||
|Madagascar|TAN|224|
|**VOIROL 1874**|||
|Tunisia, Algeria|VOI|225|
|**YACARE**|||
|Uruguay|YAC|226|



**Table 259. Terrestrial reference systems** 

|**GLONASS**|**Code**|**CDB-ID value**|
|---|---|---|
|PZ90.2|PZ90_2|227|
|PZ90.11|PZ90_11|254|



**UM2791** - **Rev 3** 

**page 218/241** 

**UM2791 RxNetworks Teseo-Module credential** 

## **Appendix B RxNetworks Teseo-Module credential** 

The table below reports the Teseo-Module credential to access the RxNetworks AGNSS Web Server. Credential access has to be used as described in the ‘ _AN5160: RxNetworks Assisted GNSS Server Interface Specification_ ’, see Reference document. 

**Table 260. Teseo-Module credential access on RxNetworks assisted GNSS server** 

|**String**|**Value**|
|---|---|
|Server address : port|stm.api.location.io:80|
|<cId>|ZYDLLXxEH94dEeX2|
|<mId>|MYST|



**UM2791** - **Rev 3** 

**page 219/241** 

**UM2791 Reference document** 

## **Appendix C Reference document** 

## **Table 261. Document reference** 

|**Document name**|**Document title**|
|---|---|
|AN5160|RxNetworks Assisted GNSS Server Interface Specification|



**UM2791** - **Rev 3** 

**page 220/241** 

**UM2791** 

## **Revision history** 

**Table 262. Document revision history** 

|**Date**|**Revision**|**Changes**|
|---|---|---|
|24-May-2021|1|Initial release.|
|14-Jan-2022|2|Updated the title. Removed some sections due to unsupported features.|
|13-Jul-2023|3|Added sections:<br>Section  11.10.21  $PSTMDR1;<br>Section  11.10.22  $PSTMDR2;Section  11.10.23  $PSTMDRPVASD;<br>Section  11.10.24  $PSTMDRSINT.|



**UM2791** - **Rev 3** 

**page 221/241** 

**UM2791 Contents** 

|**Contents**|**Contents**||
|---|---|---|
|**1**|**Document management. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .2**||
||**1.1**|Acronyms and definitions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 2|
|**2**|**Teseo-Module binary introduction. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .4**||
||**2.1**|Binary configuration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4|
|||**2.1.1**<br>Configuration concept . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4|
||**2.2**|Binary version . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5|
||**2.3**|Firmware update algorithm protocol . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6|
|||**2.3.1**<br>Firmware update on reset . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6|
|**3**|**Communication channels. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .10**||
||**3.1**|Communication over UART port . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .10|
||**3.2**|Communication over I2C port . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .10|
|||**3.2.1**<br>I2C read access . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11|
|||**3.2.2**<br>I2C write access . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11|
|||**3.2.3**<br>I2C communication channel . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11|
|**4**|**Protocol specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .13**||
||**4.1**|NMEA protocol . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .13|
|||**4.1.1**<br>Communication interface . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13|
|||**4.1.2**<br>Commands . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13|
|||**4.1.3**<br>Messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13|
||**4.2**|RTCM protocol . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .13|
|**5**|**Communication interface . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .14**||
||**5.1**|Commands. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .14|
||**5.2**|Messages. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .14|
|||**5.2.1**<br>Standard NMEA messages. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14|
|||**5.2.2**<br>Proprietary messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15|
|**6**|**Dead**|**Reckoning . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .16**|
||**6.1**|Map matching feedback . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .16|
|||**6.1.1**<br>Overview. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16|
|||**6.1.2**<br>Acceptance contidions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17|
|||**6.1.3**<br>Interface . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18|



**UM2791** - **Rev 3** 

**page 222/241** 

**UM2791 Contents** 

||**6.2**|High dead-reckoning fix rate . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .22|
|---|---|---|
||**6.3**|Sensors over UART . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .22|
|||**6.3.1**<br>Typical architecture . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23|
|||**6.3.2**<br>Message format . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23|
|||**6.3.3**<br>Required messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23|
||**6.4**|Enabling messages in configuration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .24|
|**7**|**Assisted GNSS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .25**||
||**7.1**|ST - AGNSS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .25|
||**7.2**|Real-Time AGNSS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .25|
|||**7.2.1**<br>Password generation - details . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26|
|||**7.2.2**<br>Real-Time assistance data uploading procedure. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26|
|**8**|**Low**|**power modes . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .27**|
||**8.1**|Adaptive and cyclic mode state diagram . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .27|
||**8.2**|Periodic mode . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .29|
|||**8.2.1**<br>State machine. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 29|
|||**8.2.2**<br>Good GNSS coverage sequences . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32|
|||**8.2.3**<br>Poor GNSS coverage sequences . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33|
||**8.3**|Shutdown . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .33|
|**9**|**Low**|**latency interface . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .34**|
|**10**|**NMEA command specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .35**||
||**10.1**|ST NMEA command specifications. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .35|
|||**10.1.1**<br>$PSTMINITGPS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 35|
|||**10.1.2**<br>$PSTMINITTIME. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 35|
|||**10.1.3**<br>$PSTMINITFRQ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 36|
|||**10.1.4**<br>$PSTMSETRANGE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 36|
|||**10.1.5**<br>$PSTMALMANAC. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 37|
|||**10.1.6**<br>$PSTMCLRALMS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40|
|||**10.1.7**<br>$PSTMDUMPALMANAC. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40|
|||**10.1.8**<br>$PSTMEPHEM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41|
|||**10.1.9**<br>$PSTMCLREPHS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46|
|||**10.1.10**<br>$PSTMDUMPEPHEMS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46|
|||**10.1.11**<br>$PSTMSRR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47|



**UM2791** - **Rev 3** 

**page 223/241** 

**UM2791 Contents** 

|**10.1.12**|$PSTMGPSRESET. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47|
|---|---|
|**10.1.13**|$PSTMGPSSUSPEND . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47|
|**10.1.14**|$PSTMGPSRESTART . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48|
|**10.1.15**|$PSTMCOLD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48|
|**10.1.16**|$PSTMWARM. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49|
|**10.1.17**|$PSTMHOT . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49|
|**10.1.18**|$PSTMNMEAONOFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49|
|**10.1.19**|$PSTMGNSSINV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50|
|**10.1.20**|$PSTMTIMEINV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50|
|**10.1.21**|$PSTMGETSWVER . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50|
|**10.1.22**|$PSTMNVMSWAP . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51|
|**10.1.23**|$PSTMSBASONOFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51|
|**10.1.24**|$PSTMSBASSERVICE. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51|
|**10.1.25**|$PSTMSBASSAT . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52|
|**10.1.26**|$PSTMSBASM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52|
|**10.1.27**|$PSTMRFTESTON. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53|
|**10.1.28**|$PSTMRFTESTOFF. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53|
|**10.1.29**|$PSTMGETALGO. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54|
|**10.1.30**|$PSTMSETALGO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54|
|**10.1.31**|$PSTMGETRTCTIME. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54|
|**10.1.32**|$PSTMDATUMSELECT . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55|
|**10.1.33**|$PSTMDATUMSETPARAM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55|
|**10.1.34**|$PSTMENABLEPOSITIONHOLD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56|
|**10.1.35**|$PSTMSETCONSTMASK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56|
|**10.1.36**|$PSTMNOTCH . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 57|
|**10.1.37**|$PSTMPPS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58|
|**10.1.38**|$PSTMLOWPOWERONOFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 66|
|**10.1.39**|$PSTMSTANDBYENABLE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 68|
|**10.1.40**|$PSTMFORCESTANDBY. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 68|
|**10.1.41**|$PSTMNMEAREQUEST . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 69|
|**10.1.42**|$PSTMIONOPARAMS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 69|
|**10.1.43**|$PSTMGALILEOGGTO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70|
|**10.1.44**|$PSTMGALILEODUMPGGTO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70|



**UM2791** - **Rev 3** 

**page 224/241** 

**UM2791 Contents** 

||**10.1.45**|$PSTMSETTHTRK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71|
|---|---|---|
||**10.1.46**|$PSTMSETTHPOS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71|
||**10.1.47**|$PSTMGETUCODE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71|
|**10.2**|STM system configuration commands . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .72||
||**10.2.1**|$PSTMSETPAR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 72|
||**10.2.2**|$PSTMGETPAR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 73|
||**10.2.3**|$PSTMSAVEPAR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74|
||**10.2.4**|$PSTMRESTOREPAR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74|
||**10.2.5**|$PSTMCFGPORT. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74|
||**10.2.6**|$PSTMCFGPORT on UART . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75|
||**10.2.7**|$PSTMCFGPORT on I2C . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75|
||**10.2.8**|$PSTMCFGMSGL . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76|
||**10.2.9**|$PSTMCFGGNSS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76|
||**10.2.10**|$PSTMCFGSBAS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 77|
||**10.2.11**|$PSTMCFGPPSGEN . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78|
||**10.2.12**|$PSTMCFGPPSSAT. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 79|
||**10.2.13**|$PSTMCFGPPSPUL . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 80|
||**10.2.14**|$PSTMCFGPOSHOLD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 80|
||**10.2.15**|$PSTMCFGTRAIM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 81|
||**10.2.16**|$PSTMCFGSATCOMP . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 81|
||**10.2.17**|$PSTMCFGLPA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 82|
||**10.2.18**|$PSTMCFGAGPS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 83|
||**10.2.19**|$PSTMCFGAJM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 83|
||**10.2.20**|$PSTMCFGODO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84|
||**10.2.21**|$PSTMCFGGEOFENCE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84|
||**10.2.22**|$PSTMCFGGEOCIR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85|
||**10.2.23**|$PSTMCFGCONST . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85|
||**10.2.24**|$PSTMCFGTHGNSS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 86|
||**10.2.25**|$PSTMCFGTDATA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87|
|**10.3**|Autonomous AGNSS NMEA commands . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .87||
||**10.3.1**|$PSTMSTAGPSONOFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87|
||**10.3.2**|$PSTMSTAGPSINVALIDATE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88|



**UM2791** - **Rev 3** 

**page 225/241** 

**UM2791 Contents** 

|||**10.3.3**|$PSTMGETAGPSSTATUS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88|
|---|---|---|---|
|||**10.3.4**|$PSTMSTAGPSSETCONSTMASK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88|
||**10.4**|Real Time AGNSS NMEA commands . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .89||
|||**10.4.1**|$PSTMSTAGPS8PASSGEN. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 89|
||**10.5**|Dead Reckoning NMEA Commands. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .89||
|||**10.5.1**|$PSTMDRMMFB . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 89|
|||**10.5.2**|$PSTMDRCALCTLT . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 90|
|||**10.5.3**|$PSTMDRNVMSAVE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 91|
|**11**|**Messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .92**|||
||**11.1**|Standard NMEA messages list . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .92||
||**11.2**|ST NMEA messages list. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .92||
||**11.3**|Changing standard NMEA messages format. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .93||
||**11.4**|Preliminary notes about satellites’ PRN range . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .93||
||**11.5**|Standard NMEA messages specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .93||
|||**11.5.1**|$--GGA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 93|
|||**11.5.2**|$--GLL. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 95|
|||**11.5.3**|$--GSA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 96|
|||**11.5.4**|$--GSV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 97|
|||**11.5.5**|$--RMC . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 98|
|||**11.5.6**|$--VTG . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 100|
|||**11.5.7**|$--ZDA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101|
|||**11.5.8**|$--GST . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101|
|||**11.5.9**|$--GBS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 102|
|||**11.5.10**|$--GNS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 104|
|||**11.5.11**|$--DTM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 105|
|||**11.5.12**|$--RLM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 106|
||**11.6**|ST NMEA messages specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .107||
|||**11.6.1**|$PSTMINITGPSOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 107|
|||**11.6.2**|$PSTMINITGPSERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108|
|||**11.6.3**|$PSTMINITTIMEOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108|
|||**11.6.4**|$PSTMINITTIMEERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108|
|||**11.6.5**|$PSTMSETRANGEOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108|



**UM2791** - **Rev 3** 

**page 226/241** 

**UM2791 Contents** 

|**11.6.6**|$PSTMSETRANGEERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109|
|---|---|
|**11.6.7**|$PSTMSBASSERVICEOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109|
|**11.6.8**|$PSTMSBASSERVICEERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109|
|**11.6.9**|$PSTMSBASMOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109|
|**11.6.10**|$PSTMSBASMERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109|
|**11.6.11**|$PSTMGETALGOOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110|
|**11.6.12**|$PSTMGETALGOERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110|
|**11.6.13**|$PSTMSETALGOOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110|
|**11.6.14**|$PSTMSETALGOERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110|
|**11.6.15**|$PSTMGETRTCTIME. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 111|
|**11.6.16**|$PSTMDATUMSELECTOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 111|
|**11.6.17**|$PSTMDATUMSELECTERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 112|
|**11.6.18**|$PSTMDATUMSETPARAMOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 112|
|**11.6.19**|$PSTMDATUMSETPARAMERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 112|
|**11.6.20**|$PSTMPOSITIONHOLDENABLED. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 112|
|**11.6.21**|$PSTMPOSITIONHOLDDISABLED . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113|
|**11.6.22**|$PSTMENABLEPOSITIONHOLDERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113|
|**11.6.23**|$PSTMSETCONSTMASKOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113|
|**11.6.24**|$PSTMSETCONSTMASKERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113|
|**11.6.25**|$PSTMALMANAC. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 114|
|**11.6.26**|$PSTMALMANACOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 116|
|**11.6.27**|$PSTMALMANACERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 116|
|**11.6.28**|$PSTMEPHEM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 116|
|**11.6.29**|$PSTMEPHEMOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 121|
|**11.6.30**|$PSTMEPHEMERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 121|
|**11.6.31**|$PSTMLOWPOWERON . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 121|
|**11.6.32**|$PSTMLOWPOWERERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 122|
|**11.6.33**|$PSTMPPS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 123|
|**11.6.34**|$PSTMPPSERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126|
|**11.6.35**|$PSTMFORCESTANDBYOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126|
|**11.6.36**|$PSTMFORCESTANDBYERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126|
|**11.6.37**|$PSTMGALILEODUMPGGTO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 127|
|**11.6.38**|$PSTMSETTHTRKOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 127|



**UM2791** - **Rev 3** 

**page 227/241** 

**UM2791 Contents** 

|**11.6.39**|$PSTMSETTHTRKERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 127|
|---|---|
|**11.6.40**|$PSTMSETTHPOSOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 128|
|**11.6.41**|$PSTMSETTHPOSERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 128|
|**11.6.42**|$PSTMVER . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 128|
|**11.6.43**|$PSTMRF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129|
|**11.6.44**|$PSTMTESTRF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 130|
|**11.6.45**|$PSTMTG. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 130|
|**11.6.46**|$PSTMTS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 131|
|**11.6.47**|$PSTMPA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 133|
|**11.6.48**|$PSTMSAT . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 134|
|**11.6.49**|$PSTMPRES . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 134|
|**11.6.50**|$PSTMVRES . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 134|
|**11.6.51**|$PSTMNOISE. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 135|
|**11.6.52**|$PSTMCPU . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 135|
|**11.6.53**|$PSTMPPSDATA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 136|
|**11.6.54**|$PSTMPOSHOLD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 137|
|**11.6.55**|$PSTMTRAIMSTATUS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 138|
|**11.6.56**|$PSTMTRAIMUSED. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 138|
|**11.6.57**|$PSTMTRAIMRES . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 139|
|**11.6.58**|$PSTMTRAIMREMOVED. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 139|
|**11.6.59**|$PSTMNAVM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 140|
|**11.6.60**|$PSTMKFCOV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 141|
|**11.6.61**|$PSTMTIM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 142|
|**11.6.62**|$PSTMDIFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 142|
|**11.6.63**|$PSTMSBAS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 142|
|**11.6.64**|$PSTMSBASM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 143|
|**11.6.65**|$PSTMNOTCHSTATUS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 143|
|**11.6.66**|$PSTMLOWPOWERDATA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 144|
|**11.6.67**|$PSTMSTANDBYENABLE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 145|
|**11.6.68**|$PSTMSTANDBYENABLEOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 145|
|**11.6.69**|$PSTMSTANDBYENABLEERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 145|
|**11.6.70**|$PSTMPV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 146|
|**11.6.71**|$PSTMPVRAW. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 147|



**UM2791** - **Rev 3** 

**page 228/241** 

**UM2791 Contents** 

||**11.6.72**|$PSTMPVQ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 148|
|---|---|---|
||**11.6.73**|$PSTMUTC . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 148|
||**11.6.74**|$PSTMERRORMSG. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 149|
||**11.6.75**|$PSTMGNSSINTEGRITY. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 149|
||**11.6.76**|$PSTMGPSSUSPENDED . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 150|
||**11.6.77**|$PSTMGETUCODEOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 150|
||**11.6.78**|$PSTMGETUCODEERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 150|
|**11.7**|ST system configuration messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .150||
||**11.7.1**|$PSTMSETPAROK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 150|
||**11.7.2**|$PSTMSETPARERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 151|
||**11.7.3**|$PSTMRESTOREPAROK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 151|
||**11.7.4**|$PSTMRESTOREPARERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 151|
||**11.7.5**|$PSTMSAVEPAROK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 151|
||**11.7.6**|$PSTMSAVEPARERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 152|
||**11.7.7**|$PSTMSETPAR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 152|
||**11.7.8**|$PSTMGETPARERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 152|
||**11.7.9**|$PSTMCFGPORTOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 152|
||**11.7.10**|$PSTMCFGPORTERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 153|
||**11.7.11**|$PSTMCFGMSGLOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 153|
||**11.7.12**|$PSTMCFGMSGLERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 153|
||**11.7.13**|$PSTMCFGGNSSOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 153|
||**11.7.14**|$PSTMCFGGNSSERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 153|
||**11.7.15**|$PSTMCFGSBASOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 154|
||**11.7.16**|$PSTMCFGSBASERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 154|
||**11.7.17**|$PSTMCFGPPSGENOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 154|
||**11.7.18**|$PSTMCFGPPSGENERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 154|
||**11.7.19**|$PSTMCFGPPSSATOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 155|
||**11.7.20**|$PSTMCFGPPSSATERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 155|
||**11.7.21**|$PSTMCFGPPSPULOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 155|
||**11.7.22**|$PSTMCFGPPSPULERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 155|
||**11.7.23**|$PSTMCFGPOSHOLDOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 155|
||**11.7.24**|$PSTMCFGPOSHOLDERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 156|
||**11.7.25**|$PSTMCFGTRAIMOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 156|



**UM2791** - **Rev 3** 

**page 229/241** 

**UM2791 Contents** 

||**11.7.26**|$PSTMCFGTRAIMERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 156|
|---|---|---|
||**11.7.27**|$PSTMCFGSATCOMPOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 156|
||**11.7.28**|$PSTMCFGSATCOMERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 156|
||**11.7.29**|$PSTMCFGLPAOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 157|
||**11.7.30**|$PSTMCFGLPAERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 157|
||**11.7.31**|$PSTMCFGAGPSOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 157|
||**11.7.32**|$PSTMCFGAGPSERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 157|
||**11.7.33**|$PSTMCFGAJMOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 157|
||**11.7.34**|$PSTMCFGAJMERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 158|
||**11.7.35**|$PSTMCFGODOOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 158|
||**11.7.36**|$PSTMCFGODOERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 158|
||**11.7.37**|$PSTMCFGLOGOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 158|
||**11.7.38**|$PSTMCFGLOGERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 158|
||**11.7.39**|$PSTMCFGGEOFENCEOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 159|
||**11.7.40**|$PSTMCFGGEOFENCEERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 159|
||**11.7.41**|$PSTMCFGGEOCIROK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 159|
||**11.7.42**|$PSTMCFGGEOCIRERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 159|
||**11.7.43**|$PSTMCFGCONSTOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 159|
||**11.7.44**|$PSTMCFGCONSTERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 160|
||**11.7.45**|$PSTMCFGTHGNSSOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 160|
||**11.7.46**|$PSTMCFGTHGNSSERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 160|
||**11.7.47**|$PSTMCFGTDATAOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 160|
||**11.7.48**|$PSTMCFGTDATAERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 161|
|**11.8**|Autonomous AGNSS NMEA messages. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .161||
||**11.8.1**|$PSTMPOLSTARTED. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 161|
||**11.8.2**|$PSTMPOLSUSPENDED. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 161|
||**11.8.3**|$PSTMPOLONOFFERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 161|
||**11.8.4**|$PSTMSTAGPSINVALIDATEOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 161|
||**11.8.5**|$PSTMSTAGPSINVALIDATEERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 162|
||**11.8.6**|$PSTMAGPSSTATUS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 162|
||**11.8.7**|$PSTMSTAGPSSETCONSTMASKOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 162|
||**11.8.8**|$PSTMSTAGPSSETCONSTMASKERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 163|
||**11.8.9**|$PSTMAGPS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 163|



**UM2791** - **Rev 3** 

**page 230/241** 

**UM2791 Contents** 

|||**11.8.10**|$PSTMAGLO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 164|
|---|---|---|---|
||**11.9**|Real Time AGNSS NMEA messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .165||
|||**11.9.1**|$PSTMSTAGPS8PASSRTN . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 165|
||**11.10**|Dead reckoning NMEA Messages . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .165||
|||**11.10.1**|$PSTMDRCALCTLTOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 165|
|||**11.10.2**|$PSTMDRCALCTLTERROR . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 165|
|||**11.10.3**|$PSTMDRNVMSAVEOK. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 165|
|||**11.10.4**|$PSTMDRNVMSAVEERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 166|
|||**11.10.5**|$PSTMIMUSELFTESTCMDOK . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 166|
|||**11.10.6**|$PSTMIMUSELFTESTCMDKO . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 166|
|||**11.10.7**|$PSTMIMUSELFTESTCMDERROR. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 166|
|||**11.10.8**|$PSTMDRSENMSG . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 166|
|||**11.10.9**|$PSTMDRSTATE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 169|
|||**11.10.10**|$PSTMDRGPS . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 170|
|||**11.10.11**|$PSTMDRSTEP . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 170|
|||**11.10.12**|$PSTMDRCONFID . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 171|
|||**11.10.13**|$PSTMDRUPD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 171|
|||**11.10.14**|$PSTMDRTUNNEL. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 172|
|||**11.10.15**|$PSTMDRSTYPE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 173|
|||**11.10.16**|$PSTMDRCAL . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 173|
|||**11.10.17**|$PSTMDRAHRS. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 174|
|||**11.10.18**|$PSTMDREPE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 174|
|||**11.10.19**|$PSTMDRMMFBKF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 175|
|||**11.10.20**|$PSTMDRSENCONFIG . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 176|
|||**11.10.21**|$PSTMDR1. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 177|
|||**11.10.22**|$PSTMDR2. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 178|
|||**11.10.23**|$PSTMDRPVASD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 179|
|||**11.10.24**|$PSTMDRSINT. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 181|
|||**11.10.25**|$PSTMDRNVM_WRITE . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 182|
|||**11.10.26**|$PSTM_KALMAN_INIT. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 182|
|||**11.10.27**|$PSTMDRNVM_READ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 182|
|**12**|**Firmware configuration data block (CDB) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 185**|||



**UM2791** - **Rev 3** 

**page 231/241** 

**UM2791 Contents** 

|**12.1**|CDB-ID|101|– NMEA port setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .185|
|---|---|---|---|
|**12.2**|CDB-ID|102|– NMEA port baud rate setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .185|
|**12.3**|CDB-ID|104|– Mask angle setting. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .185|
|**12.4**|CDB-ID|105|– GNSS Tracking CN0 threshold. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .185|
|**12.5**|CDB-ID|120|– Cold start setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .186|
|**12.6**|CDB-ID|121|– Number of decimal digits for speed and course data in NMEA messages .186|
|**12.7**|CDB-ID|122|– NMEA format configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .186|
|**12.8**|CDB-ID|125|– Notch filter setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .186|
|**12.9**|CDB-ID|127|– Number of decimal digits in NMEA position messages. . . . . . . . . . . . . . . . .187|
|**12.10**|CDB-ID|128|– Differential source type . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .187|
|**12.11**|CDB-ID|129|– GLONASS satellite ID type. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .187|
|**12.12**|CDB-ID|131|– NMEA talker ID. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .188|
|**12.13**|CDB-ID|132|– GNSS positioning CN0 threshold. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .188|
|**12.14**|CDB-ID|135|– SBAS default service. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .188|
|**12.15**|CDB-ID|138|– RTCM port setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .188|
|**12.16**|CDB-ID|139|– RTCM port baud rate setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .188|
|**12.17**|CDB-ID|190|- CDB-ID 201 - CDB-ID 228 - NMEA message List 0 parameters . . . . . . . . .189|
|**12.18**|CDB-ID|191|- CDB-ID 210 - CDB-ID 229 - NMEA message list 1 parameters . . . . . . . . . .191|
|**12.19**|CDB-ID|192|- CDB-ID 211 - CDB-ID 230 - NMEA message list 2 parameters . . . . . . . . . .192|
|**12.20**|CDB-ID|197|– PPS clock . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .192|
|**12.21**|CDB-ID|198|– GNSS mask angle positioning . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .192|
|**12.22**|CDB-ID|199|– Local geodetic datum selection . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .192|
|**12.23**|CDB-ID|200|- CDB-ID 227 - application ON/OFF . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .192|
|**12.24**|CDB-ID|202|– NCO range max value. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .195|
|**12.25**|CDB-ID|203|– NCO range min value . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .195|
|**12.26**|CDB-ID|204|– NCO centre value . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .196|
|**12.27**|CDB-ID|205|– position data time delay . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .196|
|**12.28**|CDB-ID|213|– PPS operating mode setting 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .196|
|**12.29**|CDB-ID|214|– PPS operating mode setting 2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .197|
|**12.30**|CDB-ID|215|– position hold auto survey samples. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .197|
|**12.31**|CDB-ID|218|– SBAS satellite parameter . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .197|



**UM2791** - **Rev 3** 

**page 232/241** 

**UM2791 Contents** 

**12.32** CDB-ID 219 – SBAS satellite parameter . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .197 **12.33** CDB-ID 220 – adaptive and cyclic operating mode setting 1. . . . . . . . . . . . . . . . . . . . . . . . .198 **12.34** CDB-ID 222 – LMS operating mode setting 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .198 **12.35** CDB-ID 223 – LMS operating mode setting 2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .199 **12.36** CDB-ID 231 – CDB-ID 232 - NMEA on I2C port message list 0 . . . . . . . . . . . . . . . . . . . . . .199 **12.37** CDB-ID 233 – CDB-ID 234 - NMEA on I2C port message list 1 . . . . . . . . . . . . . . . . . . . . . .199 **12.38** CDB-ID 235 – CDB-ID 236 - NMEA on I2C port message list 2 . . . . . . . . . . . . . . . . . . . . . .199 **12.39** CDB-ID 237 – default GPS MIN-MAX week number . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .199 **12.40** CDB-ID 238 – default UTC delta time. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .200 **12.41** CDB-ID 257 – periodic operating mode setting 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .200 **12.42** CDB-ID 258 – periodic operating mode setting 2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .200 **12.43** CDB-ID 260 – WLS algorithm configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .201 **12.44** CDB-ID 261 – dynamic modes configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .201 **12.45** CDB-ID 263 – NMEA over I2C configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .201 **12.46** CDB-ID 268 – geofencing configuration 0 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .202 **12.47** CDB-ID 270 – odometer configuration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .202 **12.48** CDB-ID 272 – GNSS integrity check configuration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .202 **12.49** CDB-ID 300 – low latency Interface rate . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.50** CDB-ID 301 – PPS pulse duration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.51** CDB-ID 302 – PPS delay correction. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.52** CDB-ID 304 – position hold latitude . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.53** CDB-ID 305 – position hold longitude. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.54** CDB-ID 306 – position hold altitude . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.55** CDB-ID 307 – GPS RF delay correction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .203 **12.56** CDB-ID 308 – GLONASS RF delay correction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .204 **12.57** CDB-ID 309 – TRAIM alarm threshold . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .204 **12.58** CDB-ID 310 – BeiDou RF delay correction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .204 **12.59** CDB-ID 311 – GALILEO RF delay correction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .204 **12.60** CDB-ID 314 – CDB-ID 315 – CDB-ID 316 – geofencing circle 0 . . . . . . . . . . . . . . . . . . . . .204 **12.61** CDB-ID 317 – CDB-ID 318 - CDB-ID 319 - geofencing circle 1 . . . . . . . . . . . . . . . . . . . . . .204 **12.62** CDB-ID 320 – CDB-ID 321 – CDB-ID 322 – geofencing circle 2 . . . . . . . . . . . . . . . . . . . . .205 

**UM2791** - **Rev 3** 

**page 233/241** 

**UM2791 Contents** 

|**12.63** CDB-ID 323 – CDB-ID 324 – CDB-ID 325 – geofencing circle 3 . . . . . . . . . . . . . . . . . . . . .205|
|---|
|**12.64** CDB-ID 400 – default 2D DOP . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .205|
|**12.65** CDB-ID 401 – default 3D DOP . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .205|
|**12.66** CDB-ID 402 – start-up 2D DOP. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .205|
|**12.67** CDB-ID 403 – start-up 3D DOP. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .205|
|**12.68** CDB-ID 500 – Text message . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .205|
|**12.69** CDB-ID 600 – DRAW main setting . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .206|
|**12.70** CDB-ID 653 – DRAW vehicle geometry . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .206|
|**12.71** CDB-ID 667 – DRAW algorithm On/Off . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .206|
|**12.72** CDB-ID 668 – DRAW installation angles . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .206|
|**Appendix A**<br>**Local geodetic datum tables . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 207**|
|**Appendix B**<br>**RxNetworks Teseo-Module credential . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 219**|
|**Appendix C**<br>**Reference document. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 220**|
|**Revision history . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 221**|



**UM2791** - **Rev 3** 

**page 234/241** 

**UM2791 List of tables** 

## **List of tables** 

|**Table**|**1.**|ST GNSS Teseo-VIC3x supported devices . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1|
|---|---|---|
|**Table**|**2.**|Acronyms . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 2|
|**Table**|**3.**|Teseo-Module firmware subsystem version . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6|
|**Table**|**4.**|Firmware upgrade on reset constants. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9|
|**Table**|**5.**|Default UART configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10|
|**Table**|**6.**|I2C register map . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12|
|**Table**|**7.**|RTCM message type supported. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13|
|**Table**|**8.**|Default UART port configuration. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14|
|**Table**|**9.**|Effects of different MMFB estimated error settings on Teseo-Module output. . . . . . . . . . . . . . . . . . . . . . . . . . . 21|
|**Table**|**10.**|SoU equired sensors vs operating mode. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23|
|**Table**|**11.**|ST-AGNSS NMEA interface . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25|
|**Table**|**12.**|Suggested power mode against the fix periodicity . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 27|
|**Table**|**13.**|Algorithm finite states machine descriptions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 28|
|**Table**|**14.**|Adaptive low power mode . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 29|
|**Table**|**15.**|Periodic mode finite state machine description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 31|
|**Table**|**16.**|$PSTMINITGPS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 35|
|**Table**|**17.**|$PSTMINITTIME field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 36|
|**Table**|**18.**|$PSTMINITFRQ field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 36|
|**Table**|**19.**|$PSTMSETRANGE field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 37|
|**Table**|**20.**|$PSTMALMANAC field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 37|
|**Table**|**21.**|$PSTMALMANAC field description for GPS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 38|
|**Table**|**22.**|$PSTMALMANAC field description for GLONASS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 38|
|**Table**|**23.**|$PSTMALMANAC field description for Galileo constellation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 39|
|**Table**|**24.**|$PSTMALMANAC field description for BeiDou constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 39|
|**Table**|**25.**|$PSTMEPHEM field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41|
|**Table**|**26.**|$PSTMEPHEM field description for GPS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41|
|**Table**|**27.**|$PSTMEPHEM field description for GLONASS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 42|
|**Table**|**28.**|$PSTMEPHEM field description for Galileo constellation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 44|
|**Table**|**29.**|$PSTMEPHEM field description for BeiDou constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45|
|**Table**|**30.**|$PSTMCOLD field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48|
|**Table**|**31.**|$PSTMNMEAONOFF field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49|
|**Table**|**32.**|$PSTMGNSSINV field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50|
|**Table**|**33.**|$PSTMGETSWVER field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50|
|**Table**|**34.**|$PSTMBASSERVICE field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52|
|**Table**|**35.**|$PSTMSBASSAT field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52|
|**Table**|**36.**|$PSTMSBASM field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53|
|**Table**|**37.**|$PSTMRFTESTON field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53|
|**Table**|**38.**|$PSTMGETALGO field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54|
|**Table**|**39.**|$PSTMSETALGO field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54|
|**Table**|**40.**|$PSTMDATUMSELECT field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55|
|**Table**|**41.**|$PSTMDATUMSETPARAM field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55|
|**Table**|**42.**|$PSTMENABLEPOSITIONHOLD field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56|
|**Table**|**43.**|$PSTMSETCONSTMASK field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 57|
|**Table**|**44.**|$PSTMNOTCH field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 57|
|**Table**|**45.**|$PSTMPPS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 59|
|**Table**|**46.**|$PSTMPPS field description on PPS_IF_ON_OFF_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 60|
|**Table**|**47.**|$PSTMPPS field description on PPS_IF_OUT_MODE_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61|
|**Table**|**48.**|$PSTMPPS field description on PPS_IF_REFERENCE_TIME_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61|
|**Table**|**49.**|$PSTMPPS field description on PPS_IF_PULSE_DELAY_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 62|
|**Table**|**50.**|$PSTMPPS field description on PPS_IF_CONSTELLATION_RF_DELAY_CMD . . . . . . . . . . . . . . . . . . . . . . . 62|
|**Table**|**51.**|$PSTMPPS field description on PPS_IF_PULSE_DURATION_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 62|
|**Table**|**52.**|$PSTMPPS field description on PPS_IF_PULSE_POLAROTY_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63|



**UM2791** - **Rev 3** 

**page 235/241** 

**UM2791 List of tables** 

**Table 53.** $PSTMPPS field description on PPS_IF_PULSE_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63 **Table 54.** $PSTMPPS field description on PPS_IF_FIX_CONDITION_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63 **Table 55.** $PSTMPPS field description on PPS_IF_SAT_TRHESHOLD_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 64 **Table 56.** $PSTMPPS field description on PPS_IF_ELEVATION_MASK_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 64 **Table 57.** $PSTMPPS field description on PPS_IF_CONSTELLATION_MASK_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . 64 **Table 58.** $PSTMPPS field description on PPS_IF_TIMING_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65 **Table 59.** $PSTMPPS field description on PPS_IF_POSITION_HOLD_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65 **Table 60.** $PSTMPPS field description on PPS_IF_AUTO_HOLD_SAMPLES_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . 66 **Table 61.** $PSTMPPS field description on PPS_IF_TRAIM_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 66 **Table 62.** $PSTMLOWPOWERONOFF field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 67 **Table 63.** $PSTMSTANDBYENABLE command field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 68 **Table 64.** $PSTMFORCESTANDBY field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 69 **Table 65.** $PSTMNMEAREQUEST field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 69 **Table 66.** $PSTMIONOPARAMS field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70 **Table 67.** $PSTMGALILEOGGTO field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70 **Table 68.** $PSTMCFGSETTHTRK field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71 **Table 69.** $PSTMCFGSETTHPOS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71 **Table 70.** $PSTMSETPAR field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 72 **Table 71.** $PSTMGETPAR field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 73 **Table 72.** $PSTMCFGPORT field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74 **Table 73.** $PSTMCFGPORT field description when port_type is UART . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75 **Table 74.** $PSTMCFGPORT field description when port_type is I2C. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75 **Table 75.** $PSTMCFGMSGL field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76 **Table 76.** $PSTMCFGGNSS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76 **Table 77.** $PSTMCFGSBAS field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 77 **Table 78.** $PSTMCFGSBAS field description when auto-search is enabled . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78 **Table 79.** $PSTMCFGPPSGEN field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 79 **Table 80.** $$PSTMCFGPPSSAT field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 79 **Table 81.** $PSTMCFGPPSPUL field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 80 **Table 82.** $PSTMCFGPOSHOLD field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 80 **Table 83.** $PSTMCFGTRAIM field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 81 **Table 84.** $PSTMCFGSATCOMP field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 81 **Table 85.** $PSTMCFGLPA field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 82 **Table 86.** $PSTMCFGAGPS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 83 **Table 87.** $PSTMCFGAJM field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84 **Table 88.** $PSTMCFGODO field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84 **Table 89.** $PSTMCFGGEOFENCE field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85 **Table 90.** $PSTMCFGGEOCIR field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85 **Table 91.** $PSTMCFGCONST field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 86 **Table 92.** $PSTMCFGTHGNSS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 86 **Table 93.** $PSTMCFGTDATA field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87 **Table 94.** $PSTMSTAGPSPONOFF field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87 **Table 95.** $PSTMSTAGPSINVALIDATE field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88 **Table 96.** $PSTMSTAGPSSETCONSTMASK field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 89 **Table 97.** $PSTMSTAGPS8PASSGEN field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 89 **Table 98.** $PSTMDRMMFB command field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 90 **Table 99.** UART- message-list . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 92 **Table 100.** I2C- message-list. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 92 **Table 101.** ST NMEA messages list . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 92 **Table 102.** Satellite PRNs for each NMEA version . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 93 **Table 103.** $--GGA message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 94 **Table 104.** $--GLL message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 95 **Table 105.** $--GSA message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 96 **Table 106.** $--GSV message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 97 

**UM2791** - **Rev 3** 

**page 236/241** 

**UM2791 List of tables** 

**Table 107.** $--RMC message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 99 **Table 108.** $--VTG message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 100 **Table 109.** $--ZDA message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101 **Table 110.** $--GST message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 102 **Table 111.** $--GBS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 103 **Table 112.** $--GNS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 104 **Table 113.** $--DTM message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 106 **Table 114.** $--RLM message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 107 **Table 115.** $PSTMGETALGOOK field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .110 **Table 116.** $PSTMSETALGOOK field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .110 **Table 117.** $PSTMGETRTCTIME message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .111 **Table 118.** $PSTMDATUMSELECTOK field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .112 **Table 119.** $PSTMSETCONSTMASKOK message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .113 **Table 120.** $PSTMALMANAC message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .114 **Table 121.** $PSTMALMANAC message field description for GPS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .114 **Table 122.** $PSTMALMANAC field description for GLONASS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .114 **Table 123.** $ PSTMALMANAC field description for Galileo constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .115 **Table 124.** $PSTMEPHEM message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .116 **Table 125.** $PSTMEPHEM message field description for GPS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .117 **Table 126.** $PSTMEPHEM message field description for GLONASS constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .117 **Table 127.** $PSTMEPHEM message field description for Galileo constellation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .119 **Table 128.** $PSTMEPHEM message field description for BEIDOU constellation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 120 **Table 129.** $PSTMLOWPOWERON field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 122 **Table 130.** $PSTMPPS field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 123 **Table 131.** $PSTMPPS field description on PPS_IF_PULSE_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 123 **Table 132.** $PSTMPPS field description on PPS_IF_TIMING_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 124 **Table 133.** $PSTMPPS field description on PPS_IF_POSITION_HOLD_DATA_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . 125 **Table 134.** $PSTMPPS field description on PPS_IF_TRAIM_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 125 **Table 135.** $PSTMPPS field description on PPS_IF_TRAIM_RES_CMD . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126 **Table 136.** $PSTMPPS field description on PPS_IF_TRAIM_REMOVED_CMD. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126 **Table 137.** $PSTMGALILEODUMPGGTO message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 127 **Table 138.** $PSTMVER field specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 128 **Table 139.** $PSTMSWCONFIG field specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129 **Table 140.** HW version field specification . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129 **Table 141.** $PSTMRF message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129 **Table 142.** $PSTMTESTRF message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 130 **Table 143.** $PSTMTG message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 130 **Table 144.** kf_config_status bit configuration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 131 **Table 145.** $PSTMTS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 132 **Table 146.** $PSTMPA message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 133 **Table 147.** $PSTMSAT message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 134 **Table 148.** $PSTMPRES message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 134 **Table 149.** $PSTMVRES message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 135 **Table 150.** $PSTMNOISE message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 135 **Table 151.** $PSTMCPU message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 135 **Table 152.** $PSTMPPSDATA message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 136 **Table 153.** $PSTMPOSHOLD message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 137 **Table 154.** $PSTMTRAIMSTATUS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 138 **Table 155.** $PSTMTRAIMUSED message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 139 **Table 156.** $PSTMTRAIMRES message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 139 **Table 157.** $PSTMTRAIMREMOVED message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 139 **Table 158.** $PSTMNAVM message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 140 **Table 159.** Navigation frame data types . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 140 **Table 160.** Galileo payload, 128[bit], 32-bit packing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 141 

**UM2791** - **Rev 3** 

**page 237/241** 

**UM2791 List of tables** 

**Table 161.** $PSTMKFCOV message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 141 **Table 162.** $PSTMTIM message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 142 **Table 163.** $PSTMDIFF message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 142 **Table 164.** $PSTMSBAS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 143 **Table 165.** $PSTMSBASM message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 143 **Table 166.** $PSTMNOTCHSTATUS message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 144 **Table 167.** $PSTMLOWPOWERDATA message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 144 **Table 168.** $PSTMSTANDBYENABLE message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 145 **Table 169.** $PSTMPV message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 146 **Table 170.** $PSTMPVRAW message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 147 **Table 171.** $PSTMPVQ message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 148 **Table 172.** $PSTMUTC message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 148 **Table 173.** $PSTMERRORMSG message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 149 **Table 174.** $PSTMGNSSINTEGRITY message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 149 **Table 175.** $PSTMGETUCODEOK message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 150 **Table 176.** $PSTMSETPAROK message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 151 **Table 177.** $PSTMSETPAR message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 152 **Table 178.** $PSTMAGPSSSTATUS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 162 **Table 179.** $PSTMSTAGPSSETCONSTMASKOK message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 162 **Table 180.** $PSTMAGPS ephemeris aging description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 163 **Table 181.** $PSTMAGPS message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 163 **Table 182.** $PSTMAGLO ephemeris aging description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 164 **Table 183.** $PSTMAGLO message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 164 **Table 184.** $PSTMSTAGPS8PASSRTN message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 165 **Table 185.** $PSTMDRSENMSG message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 167 **Table 186.** $PSTMDRSENMSG message field description when ID = 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 167 **Table 187.** $PSTMDRSENMSG message field description when ID = 2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 167 **Table 188.** $PSTMDRSENMSG message field description when ID = 14 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 167 **Table 189.** $PSTMDRSENMSG message field description when ID = 3 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 168 **Table 190.** $PSTMDRSENMSG message field description when ID = 30 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 168 **Table 191.** $PSTMDRSENMSG message field description when ID = 31 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 169 **Table 192.** $PSTMDRSENMSG message field description when ID = 32 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 169 **Table 193.** $PSTMDRSTATE message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 169 **Table 194.** $PSTMDRGPS message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 170 **Table 195.** $PSTMDRSTEP message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 170 **Table 196.** $PSTMDRCONFID message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 171 **Table 197.** $PSTMDRUPD message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 172 **Table 198.** $PSTMDRTUNNEL message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 172 **Table 199.** $PSTMDRSTYPE message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 173 **Table 200.** $PSTMDRCAL message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 173 **Table 201.** $PSTMDRAHRS message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 174 **Table 202.** $PSTMDREPE message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 175 **Table 203.** $PSTMDRMMFBKF message field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 175 **Table 204.** $PSTMDRSENCONFIG message field description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 176 **Table 205.** $PSTMDR1 fields explanation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 177 **Table 206.** $PSTMDROL fields explanation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 178 **Table 207.** $PSTMDROL fields explanation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 180 **Table 208.** $PSTMDRSINT fields explanation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 181 **Table 209.** $PSTMDRNVM_READ fields explanation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 182 **Table 210.** CDB-ID 102 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 185 **Table 211.** CDB-ID 120 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 186 **Table 212.** CDB-ID 121 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 186 **Table 213.** CDB-ID 122 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 186 **Table 214.** CDB-ID 125 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 187 

**UM2791** - **Rev 3** 

**page 238/241** 

**UM2791 List of tables** 

**Table 215.** CDB-ID 127 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 187 **Table 216.** CDB-ID 128 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 187 **Table 217.** CDB-ID 129 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 187 **Table 218.** CDB-ID 139 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 188 **Table 219.** CDB-ID 201 - CDB-ID 228 fields description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 189 **Table 220.** NMEA message list 1 CDB-IDs . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 191 **Table 221.** NMEA message list 2 CDB-IDs . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 192 **Table 222.** CDB-ID 197 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 192 **Table 223.** CDB-ID 200 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 193 **Table 224.** CDB-ID 227 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 194 **Table 225.** CDB-ID 213 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 196 **Table 226.** CDB-ID 214 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 197 **Table 227.** CDB-ID 218 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 197 **Table 228.** CDB-ID 219 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 197 **Table 229.** CDB-ID 220 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 198 **Table 230.** CDB-ID 222 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 198 **Table 231.** CDB-ID 223 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 199 **Table 232.** CDB-ID 237 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 199 **Table 233.** CDB-ID 257 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 200 **Table 234.** CDB-ID 258 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 200 **Table 235.** CDB-ID 260 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 201 **Table 236.** CDB-ID 261 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 201 **Table 237.** CDB-ID 263 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 201 **Table 238.** CDB-ID 268 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 202 **Table 239.** CDB-ID 270 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 202 **Table 240.** CDB-ID 271 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 203 **Table 241.** CDB-ID 308 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 204 **Table 242.** Geofencing circle 0 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 204 **Table 243.** Geofencing circle 1 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 204 **Table 244.** Geofencing circle 2 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 205 **Table 245.** Geofencing circle 3 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 205 **Table 246.** CDB-ID 600 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 206 **Table 247.** CDB-ID 653 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 206 **Table 248.** CDB-ID 668 field description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 206 **Table 249.** Africa . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 207 **Table 250.** Asia . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 209 **Table 251.** Australia . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 210 **Table 252.** Europe . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .211 **Table 253.** North america . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 212 **Table 254.** South america . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 213 **Table 255.** Atlantic ocean . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 214 **Table 256.** Indian ocean . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 215 **Table 257.** Pacific ocean. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 216 **Table 258.** Non-satellite derived transformation parameter . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 218 **Table 259.** Terrestrial reference systems. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 218 **Table 260.** Teseo-Module credential access on RxNetworks assisted GNSS server . . . . . . . . . . . . . . . . . . . . . . . . . . . . 219 **Table 261.** Document reference. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 220 **Table 262.** Document revision history . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 221 

**UM2791** - **Rev 3** 

**page 239/241** 

**UM2791 List of figures** 

## **List of figures** 

|**Figure**|**1.**|Binary configuration data block . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4|
|---|---|---|
|**Figure**|**2.**|Teseo-Module booting message from UART. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5|
|**Figure**|**3.**|Teseo-Module operations from Power-on/reset . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6|
|**Figure**|**4.**|Teseo-Module firmware upgrade procedure on reset . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8|
|**Figure**|**5.**|Teseo-Module protocol routing over the available ports . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10|
|**Figure**|**6.**|Read operation description. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11|
|**Figure**|**7.**|I2C write operation description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11|
|**Figure**|**8.**|I2C register write operation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12|
|**Figure**|**9.**|I2C register read operation. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12|
|**Figure**|**10.**|Navigation system feat. MMFB on Teseo-Module . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16|
|**Figure**|**11.**|Navigation system feat. MMFB on Teseo-VIC3O. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17|
|**Figure**|**12.**|MMFB fusion engine . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17|
|**Figure**|**13.**|Map data acceptance conditions. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18|
|**Figure**|**14.**|Usage of MMFB interface with correct timing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 19|
|**Figure**|**15.**|Usage of MMFB interface with incorrect timing . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 20|
|**Figure**|**16.**|Typical host-based DR architecture . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23|
|**Figure**|**17.**|Adaptive and cyclic mode state diagram . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 28|
|**Figure**|**18.**|Low power periodic mode state diagram . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 30|
|**Figure**|**19.**|GNSS good coverage sequences . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32|
|**Figure**|**20.**|GNSS poor coverage sequences . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33|



**UM2791** - **Rev 3** 

**page 240/241** 

**UM2791** 

## **IMPORTANT NOTICE – READ CAREFULLY** 

STMicroelectronics NV and its subsidiaries (“ST”) reserve the right to make changes, corrections, enhancements, modifications, and improvements to ST products and/or to this document at any time without notice. Purchasers should obtain the latest relevant information on ST products before placing orders. ST products are sold pursuant to ST’s terms and conditions of sale in place at the time of order acknowledgment. 

Purchasers are solely responsible for the choice, selection, and use of ST products and ST assumes no liability for application assistance or the design of purchasers’ products. 

No license, express or implied, to any intellectual property right is granted by ST herein. 

Resale of ST products with provisions different from the information set forth herein shall void any warranty granted by ST for such product. 

ST and the ST logo are trademarks of ST. For additional information about ST trademarks, refer to www.st.com/trademarks. All other product or service names are the property of their respective owners. 

Information in this document supersedes and replaces information previously supplied in any prior versions of this document. 

© 2023 STMicroelectronics – All rights reserved 

**UM2791** - **Rev 3** 

**page 241/241** 

