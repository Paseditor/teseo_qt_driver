import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    function log(msg) { cfgResult.append(Qt.formatTime(new Date(), "HH:mm:ss.zzz") + "  " + msg) }

    ScrollView {
        id: configScroll
        anchors.fill: parent
        anchors.margins: Theme.sp16
        contentWidth: availableWidth
        clip: true

        ColumnLayout {
            width: configScroll.availableWidth
            spacing: Theme.sp12

            // CDB + Quick Config
            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.sp12

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: cdbContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: cdbContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("CDB PARAMETERS"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("Block") }
                            StyledComboBox { id: blkCombo; model: [qsTr("Current"),qsTr("Default"),qsTr("NVM")]; Layout.preferredWidth: 90 }
                            SectionLabel { text: "ID" }
                            StyledSpinBox { id: cdbId; from: 0; to: 999; Layout.preferredWidth: 80 }
                            SectionLabel { text: qsTr("Value") }
                            StyledTextField { id: cdbVal; Layout.fillWidth: true; placeholderText: qsTr("hex"); font.family: Theme.monoFamily }
                        }

                        RowLayout {
                            spacing: Theme.sp8
                            PrimaryButton { text: qsTr("GET"); onClicked: { bridge.getParameter(blkCombo.currentIndex+1, cdbId.value); log(qsTr("GET %1").arg(cdbId.value)) } }
                            PrimaryButton { text: qsTr("SET"); onClicked: { bridge.setParameter(blkCombo.currentIndex+1, cdbId.value, cdbVal.text); log(qsTr("SET %1").arg(cdbId.value)) } }
                            GhostButton { text: qsTr("SAVE"); onClicked: { bridge.saveParameters(); log(qsTr("SAVE")) } }
                            GhostButton { text: qsTr("RESTORE"); onClicked: { bridge.restoreFactoryParameters(); log(qsTr("RESTORE")) } }
                            Item { Layout.fillWidth: true }
                        }
                    }
                }

                Rectangle {
                    Layout.preferredWidth: 380
                    Layout.minimumWidth: 380
                    Layout.maximumWidth: 380
                    Layout.preferredHeight: quickContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: quickContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("QUICK CONFIG"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 4
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp6
                            SectionLabel { text: qsTr("Baud") }
                            StyledComboBox { id: baudCfg; model: ["9600","19200","38400","57600","115200","230400","460800","921600"]; currentIndex: 4; Layout.preferredWidth: 100 }
                            PrimaryButton { text: qsTr("Set"); onClicked: { bridge.setBaudRate(parseInt(baudCfg.currentText)); log(qsTr("Baud")) } }
                            Item {}
                            SectionLabel { text: qsTr("Rate") }
                            StyledSpinBox { id: rateCfg; from: 1; to: 20; Layout.preferredWidth: 70 }
                            PrimaryButton { text: qsTr("Set"); onClicked: { bridge.setFixRate(rateCfg.value); log(qsTr("Rate")) } }
                            Item {}
                            SectionLabel { text: "GPS" }
                            StyledComboBox { id: gpsCfg; model: [qsTr("Off"),qsTr("Track"),qsTr("Use")]; currentIndex: 2; Layout.preferredWidth: 70 }
                            SectionLabel { text: "GLO" }
                            StyledComboBox { id: gloCfg; model: [qsTr("Off"),qsTr("Track"),qsTr("Use")]; currentIndex: 2; Layout.preferredWidth: 70 }
                            SectionLabel { text: "GAL" }
                            StyledComboBox { id: galCfg; model: [qsTr("Off"),qsTr("Track"),qsTr("Use")]; Layout.preferredWidth: 70 }
                            SectionLabel { text: "BDS" }
                            StyledComboBox { id: bdsCfg; model: [qsTr("Off"),qsTr("Track"),qsTr("Use")]; Layout.preferredWidth: 70 }
                        }

                        PrimaryButton {
                            text: qsTr("Apply Constellations")
                            Layout.fillWidth: true
                            onClicked: {
                                bridge.cfgConstellations(gpsCfg.currentIndex+1, gloCfg.currentIndex+1, galCfg.currentIndex+1, bdsCfg.currentIndex+1)
                                log(qsTr("Constellations"))
                            }
                        }
                    }
                }
            }

            // RTCM
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: rtcmContent.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: rtcmContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("RTCM DIFFERENTIAL CORRECTIONS"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("Source") }
                        StyledComboBox { id: diffSrc; model: [qsTr("NONE"),qsTr("SBAS"),qsTr("RTCM"),qsTr("AUTO")]; currentIndex: 3; Layout.preferredWidth: 80 }
                        PrimaryButton { text: qsTr("Apply"); onClicked: { bridge.setDifferentialSource(diffSrc.currentIndex); log(qsTr("Diff")) } }
                        Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 20; color: Theme.borderSubtle }
                        GhostButton { text: qsTr("RTCM ON"); onClicked: { bridge.enableRtcm(true); log(qsTr("RTCM ON")) } }
                        GhostButton { text: qsTr("RTCM OFF"); onClicked: { bridge.enableRtcm(false); log(qsTr("RTCM OFF")) } }
                        Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 20; color: Theme.borderSubtle }
                        SectionLabel { text: qsTr("Port") }
                        StyledSpinBox { id: rtcmPort; from: 0; to: 255; Layout.preferredWidth: 60 }
                        SectionLabel { text: qsTr("Baud") }
                        StyledSpinBox { id: rtcmBaud; from: 0; to: 15; value: 11; Layout.preferredWidth: 60 }
                        GhostButton { text: qsTr("Cfg"); onClicked: { bridge.cfgRtcmPort(rtcmPort.value); bridge.cfgRtcmBaudRate(rtcmBaud.value); log(qsTr("RTCM Cfg")) } }
                        Item { Layout.fillWidth: true }
                    }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("RTCM Data (hex)") }
                        StyledTextField { id: rtcmHex; Layout.fillWidth: true; placeholderText: qsTr("hex frame..."); font.family: Theme.monoFamily }
                        PrimaryButton { text: qsTr("Send"); onClicked: { bridge.sendRtcmDataHex(rtcmHex.text); log(qsTr("RTCM Sent")) } }
                    }
                }
            }

            // GNSS / SBAS / Geofence
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: gnssContent.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: gnssContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("GNSS / SBAS / GEOFENCE"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    GridLayout {
                        columns: 8
                        columnSpacing: Theme.sp8
                        rowSpacing: Theme.sp6
                        SectionLabel { text: qsTr("UART") }
                        StyledSpinBox { id: uartP; from: 0; to: 255; Layout.preferredWidth: 60 }
                        StyledComboBox { id: uartB; model: ["9600","19200","38400","57600","115200","230400","460800","921600"]; currentIndex: 4; Layout.preferredWidth: 100 }
                        GhostButton { text: qsTr("Cfg UART"); onClicked: { bridge.cfgPortUart(uartP.value, parseInt(uartB.currentText)); log(qsTr("UART")) } }
                        SectionLabel { text: "I2C" }
                        StyledTextField { id: i2cAddr; text: "3A"; Layout.preferredWidth: 50; font.family: Theme.monoFamily }
                        GhostButton { text: qsTr("Cfg I2C"); onClicked: { bridge.cfgPortI2c(parseInt(i2cAddr.text, 16)); log(qsTr("I2C")) } }
                        Item {}

                        SectionLabel { text: qsTr("GNSS") }
                        StyledSpinBox { id: gnssTrk; from: 0; to: 255; Layout.preferredWidth: 60 }
                        StyledSpinBox { id: gnssPos; from: 0; to: 255; Layout.preferredWidth: 60 }
                        GhostButton { text: qsTr("Cfg"); onClicked: { bridge.cfgGnss(gnssTrk.value, gnssPos.value, 0, 0, 0, 0, 0); log(qsTr("GNSS")) } }
                        SectionLabel { text: qsTr("Trk CN0") }
                        StyledSpinBox { id: trkC; from: 0; to: 50; Layout.preferredWidth: 60 }
                        SectionLabel { text: qsTr("Pos CN0") }
                        StyledSpinBox { id: posC; from: 0; to: 50; Layout.preferredWidth: 60 }

                        SectionLabel { text: "SBAS" }
                        StyledCheckBox { id: sbasEn; text: qsTr("En"); checked: true }
                        StyledCheckBox { id: sbasAuto; text: qsTr("Auto"); checked: true }
                        StyledComboBox { id: sbasSvc; model: ["WAAS","EGNOS","MSAS","GAGAN","SDCM","OFF","AUTO"]; currentIndex: 6; Layout.preferredWidth: 80 }
                        GhostButton { text: qsTr("Cfg SBAS"); onClicked: { bridge.cfgSbas(sbasEn.checked?1:0, 0, sbasAuto.checked?1:0, parseInt(sbasSvc.currentText)); log(qsTr("SBAS")) } }
                        SectionLabel { text: qsTr("Geo") }
                        StyledCheckBox { id: geoEn; text: qsTr("En") }
                        StyledSpinBox { id: geoTol; from: 0; to: 3; Layout.preferredWidth: 50 }
                    }
                }
            }

            // PPS / TRAIM / Time
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

                    Text { text: qsTr("PPS / TRAIM / TIME"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    GridLayout {
                        columns: 8
                        columnSpacing: Theme.sp8
                        rowSpacing: Theme.sp6
                        SectionLabel { text: "PPS" }
                        StyledCheckBox { id: ppsEn; text: qsTr("En") }
                        StyledComboBox { id: ppsMode; model: [qsTr("Every"),qsTr("Even"),qsTr("Odd")]; Layout.preferredWidth: 70 }
                        StyledComboBox { id: ppsClk; model: ["16MHz","32MHz","64MHz"]; Layout.preferredWidth: 70 }
                        StyledComboBox { id: ppsRef; model: ["UTC","GPS","GLONASS"]; Layout.preferredWidth: 80 }
                        GhostButton { text: qsTr("Cfg PPS"); onClicked: { bridge.cfgPpsGeneral(ppsEn.checked, ppsMode.currentIndex, ppsClk.currentIndex, ppsRef.currentIndex); log(qsTr("PPS")) } }
                        Item {}
                        Item {}

                        SectionLabel { text: "TRAIM" }
                        StyledCheckBox { id: traimEn; text: qsTr("En") }
                        StyledSpinBox { id: traimAlarm; from: 0; to: 100; Layout.preferredWidth: 70 }
                        GhostButton { text: qsTr("Cfg"); onClicked: { bridge.cfgTraim(traimEn.checked, traimAlarm.value); log(qsTr("TRAIM")) } }
                        SectionLabel { text: qsTr("PosHold") }
                        StyledCheckBox { id: phEn; text: qsTr("En") }
                        GhostButton { text: qsTr("Cfg"); onClicked: { bridge.cfgPositionHold(phEn.checked); log(qsTr("PosHold")) } }
                        Item {}

                        SectionLabel { text: qsTr("Time") }
                        StyledSpinBox { id: tMinW; from: 0; to: 9999; Layout.preferredWidth: 70 }
                        StyledSpinBox { id: tMaxW; from: 0; to: 9999; Layout.preferredWidth: 70 }
                        GhostButton { text: qsTr("Cfg Time"); onClicked: { bridge.cfgTimeData(tMinW.value, tMaxW.value, rateCfg.value, 0); log(qsTr("Time")) } }
                        Item {}
                        Item {}
                        Item {}
                        Item {}
                    }
                }
            }

            // Results
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 0
                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 28
                        color: Theme.bgElevated
                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: Theme.sp12
                            text: qsTr("RESULTS")
                            font.pixelSize: Theme.fontTiny
                            font.weight: Font.Bold
                            font.letterSpacing: 1
                            color: Theme.textMuted
                        }
                    }
                    LogTextArea {
                        id: cfgResult
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}
