import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    function log(msg) { cmdLog.append(Qt.formatTime(new Date(), "HH:mm:ss.zzz") + "  " + msg) }

    RowLayout {
        anchors.fill: parent
        anchors.margins: Theme.sp16
        spacing: Theme.sp12

        // ── Left: Command Groups ──────────────────────────
        ScrollView {
            id: commandScroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 0
            contentWidth: availableWidth
            clip: true

            ColumnLayout {
                width: commandScroll.availableWidth
                spacing: Theme.sp12

                // Start / Reset
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: startContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: startContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("START / RESET"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 4
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp8
                            GhostButton { text: qsTr("Hot"); Layout.fillWidth: true; onClicked: { bridge.hotStart(); log(qsTr("Hot Start")) } }
                            GhostButton { text: qsTr("Warm"); Layout.fillWidth: true; onClicked: { bridge.warmStart(); log(qsTr("Warm Start")) } }
                            GhostButton { text: qsTr("Cold"); Layout.fillWidth: true; onClicked: { bridge.coldStart(); log(qsTr("Cold Start")) } }
                            DangerButton { text: qsTr("Reset"); Layout.fillWidth: true; onClicked: { bridge.systemReset(); log(qsTr("System Reset")) } }
                            GhostButton { text: qsTr("GNSS Reset"); Layout.fillWidth: true; onClicked: { bridge.gnssReset(); log(qsTr("GNSS Reset")) } }
                            GhostButton { text: qsTr("Suspend"); Layout.fillWidth: true; onClicked: { bridge.gnssSuspend(); log(qsTr("Suspend")) } }
                            GhostButton { text: qsTr("Restart"); Layout.fillWidth: true; Layout.columnSpan: 2; onClicked: { bridge.gnssRestart(); log(qsTr("Restart")) } }
                        }
                    }
                }

                // Constellation / SBAS
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: constContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: constContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("CONSTELLATION / SBAS"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("Mask") }
                            StyledSpinBox { id: constMask; from: 0; to: 255; value: 3; Layout.preferredWidth: 80 }
                            PrimaryButton { text: qsTr("Set"); onClicked: { bridge.setConstellationMask(constMask.value); log(qsTr("Mask %1").arg(constMask.value)) } }
                            Item { Layout.fillWidth: true }
                            GhostButton { text: qsTr("SBAS Auto"); onClicked: { bridge.setSbasService(15); log(qsTr("SBAS Auto")) } }
                            GhostButton { text: qsTr("SBAS OFF"); onClicked: { bridge.setSbasService(7); log(qsTr("SBAS OFF")) } }
                            GhostButton { text: qsTr("Toggle"); onClicked: { bridge.toggleSbas(); log(qsTr("SBAS Toggle")) } }
                        }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("SBAS PRN") }
                            StyledSpinBox { id: sbasPrn; from: 120; to: 140; value: 120; Layout.preferredWidth: 80 }
                            GhostButton { text: qsTr("Set Sat"); onClicked: { bridge.setSbasSatellite(sbasPrn.value); log(qsTr("SBAS PRN %1").arg(sbasPrn.value)) } }
                            Item { Layout.fillWidth: true }
                            GhostButton { text: qsTr("NMEA ON"); onClicked: { bridge.setNmeaOutput(true); log(qsTr("NMEA ON")) } }
                            GhostButton { text: qsTr("NMEA OFF"); onClicked: { bridge.setNmeaOutput(false); log(qsTr("NMEA OFF")) } }
                        }
                    }
                }

                // PPS / Standby
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: ppsContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: ppsContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("PPS / STANDBY"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 5
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp8
                            GhostButton { text: qsTr("PPS ON"); Layout.fillWidth: true; onClicked: { bridge.ppsSetOnOff(true); log(qsTr("PPS ON")) } }
                            GhostButton { text: qsTr("PPS OFF"); Layout.fillWidth: true; onClicked: { bridge.ppsSetOnOff(false); log(qsTr("PPS OFF")) } }
                            GhostButton { text: qsTr("Stby ON"); Layout.fillWidth: true; onClicked: { bridge.setStandbyEnable(true); log(qsTr("Standby ON")) } }
                            GhostButton { text: qsTr("Stby OFF"); Layout.fillWidth: true; onClicked: { bridge.setStandbyEnable(false); log(qsTr("Standby OFF")) } }
                            GhostButton { text: qsTr("Get Status"); Layout.fillWidth: true; onClicked: { bridge.getStandbyStatus(); log(qsTr("Get Standby")) } }
                            GhostButton { text: qsTr("Force Stby 10s"); Layout.fillWidth: true; onClicked: { bridge.forceStandby(10); log(qsTr("Force Standby")) } }
                        }
                    }
                }

                // Algorithms / RF / IMU
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: algoContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: algoContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("ALGORITHMS / RF / IMU"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 3
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp8
                            GhostButton { text: qsTr("FDE ON"); Layout.fillWidth: true; onClicked: { bridge.setAlgorithmStatus(1, true); log(qsTr("FDE ON")) } }
                            GhostButton { text: qsTr("FDE OFF"); Layout.fillWidth: true; onClicked: { bridge.setAlgorithmStatus(1, false); log(qsTr("FDE OFF")) } }
                            GhostButton { text: qsTr("Get FDE"); Layout.fillWidth: true; onClicked: { bridge.getAlgorithmStatus(1); log(qsTr("Get FDE")) } }
                            GhostButton { text: qsTr("RF Test ON"); Layout.fillWidth: true; onClicked: { bridge.rfTestOn(24); log(qsTr("RF Test ON")) } }
                            GhostButton { text: qsTr("RF Test OFF"); Layout.fillWidth: true; onClicked: { bridge.rfTestOff(); log(qsTr("RF Test OFF")) } }
                            GhostButton { text: qsTr("IMU Self Test"); Layout.fillWidth: true; onClicked: { bridge.imuSelfTest(); log(qsTr("IMU Test")) } }
                        }
                    }
                }

                // Status / Invalidation
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: statusContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: statusContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("STATUS / INVALIDATION"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 4
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp8
                            GhostButton { text: qsTr("All Versions"); Layout.fillWidth: true; onClicked: { bridge.getAllVersions(); log(qsTr("Versions")) } }
                            GhostButton { text: qsTr("SW Version"); Layout.fillWidth: true; onClicked: { bridge.getSoftwareVersion(255); log(qsTr("SW Ver")) } }
                            GhostButton { text: qsTr("RTC Time"); Layout.fillWidth: true; onClicked: { bridge.getRtcTime(); log(qsTr("RTC")) } }
                            GhostButton { text: qsTr("Unique Code"); Layout.fillWidth: true; onClicked: { bridge.getUniqueCode(); log(qsTr("UID")) } }
                            GhostButton { text: qsTr("Invalidate Fix"); Layout.fillWidth: true; onClicked: { bridge.invalidateGnssFix(true); log(qsTr("Inv Fix")) } }
                            GhostButton { text: qsTr("Restore Fix"); Layout.fillWidth: true; onClicked: { bridge.invalidateGnssFix(false); log(qsTr("Rest Fix")) } }
                            GhostButton { text: qsTr("Invalidate RTC"); Layout.fillWidth: true; onClicked: { bridge.invalidateRtc(); log(qsTr("Inv RTC")) } }
                            GhostButton { text: qsTr("NVM Swap"); Layout.fillWidth: true; onClicked: { bridge.nvmSwap(); log(qsTr("NVM Swap")) } }
                        }
                    }
                }

                // Low Power / Notch
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: lpContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: lpContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("LOW POWER / NOTCH"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        RowLayout {
                            spacing: Theme.sp8
                            GhostButton { text: qsTr("LP ON"); onClicked: { bridge.cfgLowPowerAlgorithm(1,1,10,1,8,60,180,1,1,15,9,700,0); log(qsTr("LP ON")) } }
                            GhostButton { text: qsTr("LP OFF"); onClicked: { bridge.cfgLowPowerAlgorithm(0,0,0,0,0,0,0,0,0,0,0,0,0); log(qsTr("LP OFF")) } }
                            Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 20; color: Theme.borderSubtle }
                            SectionLabel { text: qsTr("Notch") }
                            StyledComboBox { id: notchSat; model: ["GPS","GLONASS"]; Layout.preferredWidth: 80 }
                            StyledComboBox { id: notchMode; model: ["Off","Always","Auto"]; currentIndex: 2; Layout.preferredWidth: 80 }
                            GhostButton { text: qsTr("Apply"); onClicked: { bridge.setNotchFilter(notchSat.currentIndex, notchMode.currentIndex); log(qsTr("Notch")) } }
                            Item { Layout.fillWidth: true }
                        }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("Datum") }
                            StyledComboBox { id: datumCombo; model: ["WGS84","TOKYO","OSGB"]; Layout.preferredWidth: 80 }
                            GhostButton { text: qsTr("Apply"); onClicked: { bridge.selectDatum(datumCombo.currentIndex); log(qsTr("Datum")) } }
                            Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 20; color: Theme.borderSubtle }
                            GhostButton { text: qsTr("Log ON"); onClicked: { bridge.cfgLog(1); log(qsTr("Log ON")) } }
                            GhostButton { text: qsTr("Log OFF"); onClicked: { bridge.cfgLog(0); log(qsTr("Log OFF")) } }
                            Item { Layout.fillWidth: true }
                        }
                    }
                }
            }
        }

        // ── Right: Custom + Log ───────────────────────────
        ColumnLayout {
            Layout.preferredWidth: 360
            Layout.minimumWidth: 360
            Layout.maximumWidth: 360
            Layout.fillWidth: false
            Layout.fillHeight: true
            spacing: Theme.sp12

            // Custom command
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: customContent.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: customContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("CUSTOM COMMAND"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    RowLayout {
                        spacing: Theme.sp8
                        StyledTextField {
                            id: customCmd
                            Layout.fillWidth: true
                            placeholderText: "$PSTM..."
                            font.family: Theme.monoFamily
                            onAccepted: sendBtn.clicked()
                        }
                        PrimaryButton {
                            id: sendBtn
                            text: qsTr("Send")
                            onClicked: {
                                if (customCmd.text) {
                                    bridge.sendCommand(customCmd.text)
                                    log(qsTr("TX: %1").arg(customCmd.text))
                                }
                            }
                        }
                    }
                }
            }

            // Log
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 0

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 32
                        color: Theme.bgElevated

                        RowLayout {
                            anchors.fill: parent
                            anchors.leftMargin: Theme.sp12
                            anchors.rightMargin: Theme.sp12
                            Text { text: qsTr("COMMAND LOG"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.textMuted }
                            Item { Layout.fillWidth: true }
                            Text {
                                text: qsTr("Clear")
                                font.pixelSize: Theme.fontTiny
                                color: Theme.textDisabled
                                MouseArea {
                                    anchors.fill: parent
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: cmdLog.clear()
                                }
                            }
                        }
                    }

                    LogTextArea {
                        id: cmdLog
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}
