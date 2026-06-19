import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    function log(msg) { agnssLog.append(Qt.formatTime(new Date(), "HH:mm:ss") + "  " + msg) }

    ScrollView {
        id: agnssScroll
        anchors.fill: parent
        anchors.margins: Theme.sp16
        contentWidth: availableWidth
        clip: true

        ColumnLayout {
            width: agnssScroll.availableWidth
            spacing: Theme.sp12

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.sp12

                // Init Position & Time
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: initContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: initContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("INITIALIZE POSITION & TIME"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        GridLayout {
                            columns: 3
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp6
                            SectionLabel { text: qsTr("Lat") }
                            StyledSpinBox { id: initLat; from: -90000000; to: 90000000; Layout.preferredWidth: 120; property real rVal: value / 1000000 }
                            StyledComboBox { id: initLatRef; model: ["N","S"]; Layout.preferredWidth: 50 }
                            SectionLabel { text: qsTr("Lon") }
                            StyledSpinBox { id: initLon; from: -180000000; to: 180000000; Layout.preferredWidth: 120; property real rVal: value / 1000000 }
                            StyledComboBox { id: initLonRef; model: ["E","W"]; Layout.preferredWidth: 50 }
                            SectionLabel { text: qsTr("Alt (m)") }
                            StyledSpinBox { id: initAlt; from: -1500; to: 100000; Layout.preferredWidth: 120 }
                            Item {}
                        }

                        RowLayout {
                            spacing: Theme.sp8
                            PrimaryButton {
                                text: qsTr("Init GPS")
                                onClicked: { bridge.initGps(initLat.rVal, initLatRef.currentText, initLon.rVal, initLonRef.currentText, initAlt.value, new Date(), new Date()); log(qsTr("InitGPS")) }
                            }
                            PrimaryButton {
                                text: qsTr("Init Time")
                                onClicked: { bridge.initTime(new Date(), new Date()); log(qsTr("InitTime")) }
                            }
                            Item { Layout.fillWidth: true }
                        }
                    }
                }

                // ST-AGNSS
                Rectangle {
                    Layout.preferredWidth: 360
                    Layout.minimumWidth: 360
                    Layout.maximumWidth: 360
                    Layout.preferredHeight: agnssContent.implicitHeight + 2 * Theme.sp16
                    color: Theme.bgCard
                    radius: Theme.radiusLg
                    border.color: Theme.borderSubtle
                    border.width: 1

                    ColumnLayout {
                        id: agnssContent
                        anchors.fill: parent
                        anchors.margins: Theme.sp16
                        spacing: Theme.sp8

                        Text { text: qsTr("ST-AGNSS"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("Freq") }
                            StyledSpinBox { id: freqOff; from: -100000; to: 100000; Layout.preferredWidth: 90 }
                            PrimaryButton { text: qsTr("Set"); onClicked: { bridge.initFrequency(freqOff.value); log(qsTr("Freq")) } }
                            Item { Layout.fillWidth: true }
                        }

                        GridLayout {
                            columns: 3
                            columnSpacing: Theme.sp8
                            rowSpacing: Theme.sp8
                            GhostButton { text: qsTr("ST-AGPS ON"); Layout.fillWidth: true; onClicked: { bridge.stagpsOnOff(true); log(qsTr("ST-AGPS ON")) } }
                            GhostButton { text: qsTr("ST-AGPS OFF"); Layout.fillWidth: true; onClicked: { bridge.stagpsOnOff(false); log(qsTr("ST-AGPS OFF")) } }
                            GhostButton { text: qsTr("Get Status"); Layout.fillWidth: true; onClicked: { bridge.stagpsGetStatus(); log(qsTr("Status")) } }
                            GhostButton { text: qsTr("Invalidate"); Layout.fillWidth: true; onClicked: { bridge.stagpsInvalidate(7); log(qsTr("Invalidate")) } }
                            GhostButton { text: qsTr("AGPS ON"); Layout.fillWidth: true; onClicked: { bridge.cfgAgps(true); log(qsTr("AGPS ON")) } }
                            GhostButton { text: qsTr("AGPS OFF"); Layout.fillWidth: true; onClicked: { bridge.cfgAgps(false); log(qsTr("AGPS OFF")) } }
                        }

                        RowLayout {
                            spacing: Theme.sp8
                            SectionLabel { text: qsTr("Mask") }
                            StyledSpinBox { id: stagMask; from: 0; to: 255; value: 1; Layout.preferredWidth: 70 }
                            GhostButton { text: qsTr("Set Mask"); onClicked: { bridge.stagpsSetConstellationMask(stagMask.value); log(qsTr("Mask")) } }
                            Item { Layout.fillWidth: true }
                        }
                    }
                }
            }

            // Almanac / Ephemeris
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: injContent.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: injContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("ALMANAC / EPHEMERIS INJECTION"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("Sat ID") }
                        StyledSpinBox { id: injSat; from: 0; to: 99; Layout.preferredWidth: 60 }
                        SectionLabel { text: qsTr("Hex Data") }
                        StyledTextField { id: injHex; Layout.fillWidth: true; placeholderText: qsTr("almanac/ephemeris hex..."); font.family: Theme.monoFamily }
                    }

                    GridLayout {
                        columns: 6
                        columnSpacing: Theme.sp8
                        rowSpacing: Theme.sp8
                        GhostButton { text: qsTr("Load Alm"); Layout.fillWidth: true; onClicked: { bridge.loadAlmanac(injSat.value, injHex.text); log(qsTr("Load Alm")) } }
                        GhostButton { text: qsTr("Load Eph"); Layout.fillWidth: true; onClicked: { bridge.loadEphemeris(injSat.value, injHex.text); log(qsTr("Load Eph")) } }
                        GhostButton { text: qsTr("Dump Alm"); Layout.fillWidth: true; onClicked: { bridge.dumpAlmanacs(); log(qsTr("Dump Alm")) } }
                        GhostButton { text: qsTr("Clear Alm"); Layout.fillWidth: true; onClicked: { bridge.clearAlmanacs(); log(qsTr("Clear Alm")) } }
                        GhostButton { text: qsTr("Dump Eph"); Layout.fillWidth: true; onClicked: { bridge.dumpEphemeris(); log(qsTr("Dump Eph")) } }
                        GhostButton { text: qsTr("Clear Eph"); Layout.fillWidth: true; onClicked: { bridge.clearEphemeris(); log(qsTr("Clear Eph")) } }
                    }
                }
            }

            // Galileo / Iono
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: galContent.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: galContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("GALILEO GGTO / IONOSPHERE"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: "BRD" }
                        StyledSpinBox { id: gBrd; from: 0; to: 1; value: 1; Layout.preferredWidth: 50 }
                        SectionLabel { text: "WN0G" }
                        StyledSpinBox { id: gWn; from: 0; to: 999; Layout.preferredWidth: 60 }
                        SectionLabel { text: "t0G" }
                        StyledSpinBox { id: gT0; from: 0; to: 99999; Layout.preferredWidth: 70 }
                        SectionLabel { text: "A0G" }
                        StyledSpinBox { id: gA0; from: -99999; to: 99999; Layout.preferredWidth: 70 }
                        SectionLabel { text: "A1G" }
                        StyledSpinBox { id: gA1; from: -99999; to: 99999; Layout.preferredWidth: 70 }
                        GhostButton { text: qsTr("Set GGTO"); onClicked: { bridge.setGalileoGgto(gBrd.value, gWn.value, gT0.value, gA0.value, gA1.value, true); log(qsTr("GGTO")) } }
                        GhostButton { text: qsTr("Dump"); onClicked: { bridge.dumpGalileoGgto(); log(qsTr("Dump GGTO")) } }
                    }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("Iono Type") }
                        StyledComboBox { id: ionoSat; model: ["GPS","GLONASS","Galileo","BeiDou"]; Layout.preferredWidth: 80 }
                        SectionLabel { text: qsTr("Params") }
                        StyledTextField { id: ionoPar; Layout.fillWidth: true; placeholderText: "A0,A1,A2,A3,B0,B1,B2,B3"; font.family: Theme.monoFamily }
                        GhostButton {
                            text: qsTr("Set Iono")
                            onClicked: {
                                var params = ionoPar.text.split(",").map(function(s){return parseInt(s.trim())})
                                bridge.setIonoParams(ionoSat.currentIndex, params); log(qsTr("Iono"))
                            }
                        }
                    }
                }
            }

            // AGNSS Log
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 100
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
                            text: qsTr("AGNSS LOG")
                            font.pixelSize: Theme.fontTiny
                            font.weight: Font.Bold
                            font.letterSpacing: 1
                            color: Theme.textMuted
                        }
                    }
                    LogTextArea {
                        id: agnssLog
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}
