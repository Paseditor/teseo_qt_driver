import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    RowLayout {
        anchors.fill: parent
        anchors.margins: Theme.sp16
        spacing: Theme.sp12

        // ── Left: Data Panels ─────────────────────────────
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Theme.sp12

            // Position
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: posGrid.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                GridLayout {
                    id: posGrid
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    columns: 2
                    columnSpacing: Theme.sp24
                    rowSpacing: Theme.sp8

                    SectionLabel { text: qsTr("LATITUDE") }
                    ValueDisplay {
                        text: bridge.latitude.toFixed(7) + (bridge.latitude >= 0 ? " N" : " S")
                        font.family: Theme.monoFamily
                    }
                    SectionLabel { text: qsTr("LONGITUDE") }
                    ValueDisplay {
                        text: bridge.longitude.toFixed(7) + (bridge.longitude >= 0 ? " E" : " W")
                        font.family: Theme.monoFamily
                    }
                    SectionLabel { text: qsTr("ALTITUDE") }
                    ValueDisplay { text: bridge.altitude.toFixed(2) + " m"; font.family: Theme.monoFamily }
                    SectionLabel { text: qsTr("SPEED") }
                    ValueDisplay { text: bridge.speedKmh.toFixed(1) + " km/h"; font.family: Theme.monoFamily }
                    SectionLabel { text: qsTr("COURSE") }
                    ValueDisplay { text: bridge.course.toFixed(1) + "\u00B0"; font.family: Theme.monoFamily }
                    SectionLabel { text: qsTr("FIX") }
                    Text {
                        text: Theme.fixQualityText(bridge.fixQuality)
                        font.pixelSize: Theme.fontBody
                        font.weight: Font.DemiBold
                        color: bridge.fixValid ? Theme.success : Theme.error
                    }
                    SectionLabel { text: qsTr("SATs USED") }
                    ValueDisplay { text: bridge.satellitesUsed; font.family: Theme.monoFamily }
                }
            }

            // DOP + Accuracy
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: dopGrid.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                GridLayout {
                    id: dopGrid
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    columns: 4
                    columnSpacing: Theme.sp24
                    rowSpacing: Theme.sp8

                    SectionLabel { text: "HDOP" }
                    ValueDisplay { text: bridge.hdop.toFixed(1); font.family: Theme.monoFamily }
                    SectionLabel { text: qsTr("UTC TIME") }
                    ValueDisplay { text: bridge.utcTime; font.family: Theme.monoFamily; font.pixelSize: Theme.fontCaption }

                    SectionLabel { text: "PDOP" }
                    ValueDisplay { text: bridge.pdop.toFixed(1); font.family: Theme.monoFamily }
                    SectionLabel { text: qsTr("UTC DATE") }
                    ValueDisplay { text: bridge.utcDate; font.family: Theme.monoFamily; font.pixelSize: Theme.fontCaption }

                    SectionLabel { text: "VDOP" }
                    ValueDisplay { text: bridge.vdop.toFixed(1); font.family: Theme.monoFamily }
                    SectionLabel { text: "EHPE" }
                    ValueDisplay { text: bridge.ehpe.toFixed(1) + " m"; font.family: Theme.monoFamily }
                }
            }

            // Device Info
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: devGrid.implicitHeight + 2 * Theme.sp16
                color: Theme.bgCard
                radius: Theme.radiusLg
                border.color: Theme.borderSubtle
                border.width: 1

                GridLayout {
                    id: devGrid
                    anchors.fill: parent
                    anchors.margins: Theme.sp16
                    columns: 2
                    columnSpacing: Theme.sp24
                    rowSpacing: Theme.sp6

                    SectionLabel { text: qsTr("FIRMWARE") }
                    ValueDisplay { text: bridge.swVersion || "---"; font.family: Theme.monoFamily; font.pixelSize: Theme.fontCaption }
                    SectionLabel { text: qsTr("UNIQUE CODE") }
                    ValueDisplay { text: bridge.uniqueCode || "---"; font.family: Theme.monoFamily; font.pixelSize: Theme.fontCaption }
                }
            }

            Item { Layout.fillHeight: true }
        }

        // ── Right: Satellite Table ────────────────────────
        Rectangle {
            Layout.preferredWidth: 340
            Layout.fillHeight: true
            color: Theme.bgCard
            radius: Theme.radiusLg
            border.color: Theme.borderSubtle
            border.width: 1

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                // Header
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 36
                    color: Theme.bgElevated
                    radius: Theme.radiusLg

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: Theme.sp12
                        anchors.rightMargin: Theme.sp12
                        Text { text: "PRN"; font.pixelSize: Theme.fontSmall; font.weight: Font.Bold; color: Theme.textMuted; Layout.preferredWidth: 40 }
                        Text { text: qsTr("Elev"); font.pixelSize: Theme.fontSmall; font.weight: Font.Bold; color: Theme.textMuted; Layout.preferredWidth: 40 }
                        Text { text: qsTr("Azim"); font.pixelSize: Theme.fontSmall; font.weight: Font.Bold; color: Theme.textMuted; Layout.preferredWidth: 44 }
                        Text { text: "CN0"; font.pixelSize: Theme.fontSmall; font.weight: Font.Bold; color: Theme.textMuted; Layout.preferredWidth: 40 }
                        Text { text: qsTr("Used"); font.pixelSize: Theme.fontSmall; font.weight: Font.Bold; color: Theme.textMuted; Layout.fillWidth: true }
                    }
                }

                ListView {
                    id: satList
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    model: ListModel { id: satModel }
                    clip: true

                    delegate: Rectangle {
                        required property int prn
                        required property int elev
                        required property int azim
                        required property int cn0
                        required property bool used
                        required property int index

                        width: satList.width
                        height: 28
                        color: index % 2 === 0 ? "transparent" : Qt.rgba(1,1,1,0.02)

                        RowLayout {
                            anchors.fill: parent
                            anchors.leftMargin: Theme.sp12
                            anchors.rightMargin: Theme.sp12
                            spacing: 0

                            Text { text: prn; font.pixelSize: Theme.fontSmall; font.family: Theme.monoFamily; color: Theme.textPrimary; Layout.preferredWidth: 40 }
                            Text { text: elev; font.pixelSize: Theme.fontSmall; font.family: Theme.monoFamily; color: Theme.textSecondary; Layout.preferredWidth: 40 }
                            Text { text: azim; font.pixelSize: Theme.fontSmall; font.family: Theme.monoFamily; color: Theme.textSecondary; Layout.preferredWidth: 44 }

                            Rectangle {
                                Layout.preferredWidth: 40
                                Layout.preferredHeight: 14
                                radius: 2
                                color: Theme.bgBase

                                Rectangle {
                                    width: Math.max(2, parent.width * Math.min(cn0 / 50, 1.0))
                                    height: parent.height
                                    radius: 2
                                    color: Theme.cn0Color(cn0)
                                }
                            }

                            Item { Layout.preferredWidth: Theme.sp8 }

                            Text {
                                text: used ? "\u25CF" : "\u25CB"
                                font.pixelSize: 8
                                color: used ? Theme.success : Theme.textDisabled
                                Layout.fillWidth: true
                            }
                        }
                    }
                }
            }
        }
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var sats = bridge.satellitesModel()
            satModel.clear()
            for (var i = 0; i < sats.length; i++)
                satModel.append(sats[i])
        }
    }
}
