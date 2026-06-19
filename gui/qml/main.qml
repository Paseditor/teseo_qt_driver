import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 780
    minimumWidth: 1024
    minimumHeight: 680
    title: qsTr("Teseo-VIC3 GNSS Test Tool")
    color: Theme.bgBase
    font.family: Theme.fontFamily

    header: Rectangle {
        height: 48
        color: Theme.bgHeader
        border.color: Theme.borderSubtle
        border.width: 1

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Theme.sp16
            anchors.rightMargin: Theme.sp16
            spacing: Theme.sp8

            Text {
                text: "\u25C8"
                font.pixelSize: Theme.fontHeading
                color: Theme.accent
            }
            Text {
                text: qsTr("TESEO-VIC3")
                font.pixelSize: Theme.fontBody
                font.weight: Font.Bold
                font.letterSpacing: 2
                color: Theme.textPrimary
            }
            Text {
                text: qsTr("GNSS Test Tool")
                font.pixelSize: Theme.fontCaption
                color: Theme.textMuted
            }

            Item { Layout.fillWidth: true }

            Rectangle {
                Layout.preferredWidth: 8
                Layout.preferredHeight: 8
                radius: 4
                color: bridge.connected ? Theme.success : Theme.error
            }
            Text {
                text: bridge.connected ? qsTr("Connected") : qsTr("Disconnected")
                font.pixelSize: Theme.fontCaption
                font.weight: Font.Medium
                color: bridge.connected ? Theme.success : Theme.textMuted
            }
            Rectangle {
                Layout.preferredWidth: 1
                Layout.preferredHeight: 20
                color: Theme.borderSubtle
            }
            Text {
                text: bridge.swVersion || "v2.0"
                font.pixelSize: Theme.fontTiny
                font.family: Theme.monoFamily
                color: Theme.textDisabled
            }
        }
    }

    footer: Rectangle {
        height: 24
        color: Theme.bgFooter
        border.color: Theme.borderSubtle
        border.width: 1

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Theme.sp12
            anchors.rightMargin: Theme.sp12

            Text {
                text: bridge.utcTime + "  |  " + bridge.utcDate
                font.pixelSize: Theme.fontTiny
                font.family: Theme.monoFamily
                color: Theme.textDisabled
            }
            Item { Layout.fillWidth: true }
            Text {
                text: bridge.latitude.toFixed(6) + ", " + bridge.longitude.toFixed(6)
                font.pixelSize: Theme.fontTiny
                font.family: Theme.monoFamily
                color: Theme.textDisabled
            }
            Rectangle {
                Layout.preferredWidth: 1
                Layout.preferredHeight: 12
                color: Theme.borderSubtle
            }
            Text {
                text: bridge.satellitesUsed + " sats"
                font.pixelSize: Theme.fontTiny
                font.family: Theme.monoFamily
                color: Theme.textDisabled
            }
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // ── Sidebar Nav ───────────────────────────────────
        Rectangle {
            Layout.preferredWidth: 52
            Layout.fillHeight: true
            color: Theme.bgSurface
            border.color: Theme.borderSubtle
            border.width: 0
            Column {
                id: navColumn
                anchors.top: parent.top
                anchors.topMargin: Theme.sp8
                width: parent.width
                spacing: 2

                Repeater {
                    id: navRepeater
                    model: [
                        { icon: "\u2630", label: qsTr("Conn") },
                        { icon: "\u25C9", label: qsTr("Info") },
                        { icon: "\u26A1", label: qsTr("Cmd") },
                        { icon: "\u2699", label: qsTr("Cfg") },
                        { icon: "\u2302", label: qsTr("AGNSS") },
                        { icon: "\u2192", label: qsTr("DR") },
                        { icon: "\u25CB", label: qsTr("Log") }
                    ]
                    Rectangle {
                        width: navColumn.width
                        height: 44
                        color: navArea.containsMouse || stack.currentIndex === index
                               ? Theme.bgCard : "transparent"

                        MouseArea {
                            id: navArea
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: stack.currentIndex = index
                        }

                        Column {
                            anchors.centerIn: parent
                            spacing: 2
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: modelData.icon
                                font.pixelSize: 14
                                color: stack.currentIndex === index ? Theme.accent : Theme.textMuted
                            }
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: modelData.label
                                font.pixelSize: Theme.fontTiny
                                font.weight: stack.currentIndex === index ? Font.DemiBold : Font.Normal
                                color: stack.currentIndex === index ? Theme.accent : Theme.textDisabled
                            }
                        }

                        Rectangle {
                            width: 2
                            height: parent.height
                            anchors.right: parent.right
                            color: stack.currentIndex === index ? Theme.accent : "transparent"
                        }
                    }
                }
            }
        }

        // ── Main Content ──────────────────────────────────
        StackLayout {
            id: stack
            Layout.fillWidth: true
            Layout.fillHeight: true

            ConnectionPage {}
            InfoPage {}
            CommandPage {}
            ConfigPage {}
            AGNSSPage {}
            DeadReckoningPage {}
            LogPage {}
        }
    }
}
