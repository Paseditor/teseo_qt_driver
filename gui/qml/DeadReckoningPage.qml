import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    function log(msg) { drLog.append(Qt.formatTime(new Date(), "HH:mm:ss") + "  " + msg) }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Theme.sp16
        spacing: Theme.sp12

        RowLayout {
            Layout.fillWidth: true
            spacing: Theme.sp12

            // MMFB
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: mmfbContent.implicitHeight + 2 * Theme.sp16
                Layout.alignment: Qt.AlignTop
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: mmfbContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("MAP MATCHING FEEDBACK"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    GridLayout {
                        columns: 2
                        columnSpacing: Theme.sp12
                        rowSpacing: Theme.sp6
                        SectionLabel { text: qsTr("Timestamp") }
                        StyledTextField { id: mmfbTs; text: "120000.000"; Layout.preferredWidth: 120; font.family: Theme.monoFamily }
                        SectionLabel { text: qsTr("Lat Valid") }
                        StyledCheckBox { id: mmfbLatV; text: ""; checked: true }
                        SectionLabel { text: qsTr("Lon Valid") }
                        StyledCheckBox { id: mmfbLonV; text: ""; checked: true }
                        SectionLabel { text: qsTr("Latitude") }
                        StyledSpinBox { id: mmfbLat; from: -90000000; to: 90000000; Layout.preferredWidth: 130; property real rVal: value / 1000000 }
                        SectionLabel { text: qsTr("Longitude") }
                        StyledSpinBox { id: mmfbLon; from: -180000000; to: 180000000; Layout.preferredWidth: 130; property real rVal: value / 1000000 }
                        SectionLabel { text: qsTr("Lat Err (m)") }
                        StyledSpinBox { id: mmfbLatErr; from: 0; to: 1000; Layout.preferredWidth: 80 }
                        SectionLabel { text: qsTr("Lon Err (m)") }
                        StyledSpinBox { id: mmfbLonErr; from: 0; to: 1000; Layout.preferredWidth: 80 }
                    }

                    PrimaryButton {
                        text: qsTr("Send MMFB")
                        Layout.fillWidth: true
                        onClicked: {
                            bridge.sendMapMatchingFeedback(mmfbTs.text, mmfbLatV.checked, mmfbLonV.checked, mmfbLat.rVal, mmfbLon.rVal, mmfbLatErr.value, mmfbLonErr.value)
                            log(qsTr("MMFB sent"))
                        }
                    }
                }
            }

            // Sensors & DR
            Rectangle {
                Layout.preferredWidth: 420
                Layout.minimumWidth: 420
                Layout.maximumWidth: 420
                Layout.preferredHeight: drContent.implicitHeight + 2 * Theme.sp16
                Layout.alignment: Qt.AlignTop
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                ColumnLayout {
                    id: drContent
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    spacing: Theme.sp8

                    Text { text: qsTr("SENSORS & DR CONTROL"); font.pixelSize: Theme.fontTiny; font.weight: Font.Bold; font.letterSpacing: 1; color: Theme.accentMuted }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("Sensor ID") }
                        StyledSpinBox { id: senId; from: 0; to: 99; value: 31; Layout.preferredWidth: 60 }
                        SectionLabel { text: "X" }
                        StyledSpinBox { id: senX; from: -99999; to: 99999; Layout.preferredWidth: 70 }
                        SectionLabel { text: "Y" }
                        StyledSpinBox { id: senY; from: -99999; to: 99999; Layout.preferredWidth: 70 }
                        SectionLabel { text: "Z" }
                        StyledSpinBox { id: senZ; from: -99999; to: 99999; Layout.preferredWidth: 70 }
                    }

                    GridLayout {
                        columns: 3
                        columnSpacing: Theme.sp8
                        rowSpacing: Theme.sp8
                        GhostButton { text: qsTr("Send Sensor"); Layout.fillWidth: true; onClicked: { bridge.sendSensorMessage(senId.value, senX.value, senY.value, senZ.value); log(qsTr("Sensor")) } }
                        GhostButton { text: qsTr("Calibrate Tilt"); Layout.fillWidth: true; onClicked: { bridge.drCalibrateTilt(); log(qsTr("Tilt")) } }
                        GhostButton { text: qsTr("Save DR NVM"); Layout.fillWidth: true; onClicked: { bridge.drSaveToNvm(); log(qsTr("DR NVM")) } }
                    }

                    Rectangle { Layout.preferredHeight: 1; Layout.fillWidth: true; color: Theme.borderSubtle }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("Odometer") }
                        StyledCheckBox { id: odoEn; text: qsTr("Enable") }
                        PrimaryButton { text: qsTr("Apply"); onClicked: { bridge.cfgOdometerSimple(odoEn.checked); log(qsTr("Odometer")) } }
                        Item { Layout.fillWidth: true }
                    }

                    RowLayout {
                        spacing: Theme.sp8
                        SectionLabel { text: qsTr("AJM GPS") }
                        StyledSpinBox { id: ajmGps; from: 0; to: 2; Layout.preferredWidth: 60 }
                        SectionLabel { text: qsTr("AJM GLO") }
                        StyledSpinBox { id: ajmGlo; from: 0; to: 2; Layout.preferredWidth: 60 }
                        PrimaryButton { text: qsTr("Apply AJM"); onClicked: { bridge.cfgAntiJamming(ajmGps.value, ajmGlo.value); log(qsTr("AJM")) } }
                        Item { Layout.fillWidth: true }
                    }
                }
            }
        }

        // DR Log
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
                    Layout.preferredHeight: 28
                    color: Theme.bgElevated
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: Theme.sp12
                        text: qsTr("DR LOG")
                        font.pixelSize: Theme.fontTiny
                        font.weight: Font.Bold
                        font.letterSpacing: 1
                        color: Theme.textMuted
                    }
                }
                LogTextArea {
                    id: drLog
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }
    }
}
