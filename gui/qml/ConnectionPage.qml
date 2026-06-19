import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    ColumnLayout {
        anchors.centerIn: parent
        width: 420
        spacing: Theme.sp8

        Text {
            text: qsTr("Serial Connection")
            font.pixelSize: Theme.fontDisplay
            font.weight: Font.Light
            color: Theme.textPrimary
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
        Text {
            text: qsTr("Connect to Teseo-VIC3 GNSS module via UART")
            font.pixelSize: Theme.fontBody
            color: Theme.textMuted
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Item { Layout.preferredHeight: Theme.sp16 }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: connContent.implicitHeight + 2 * Theme.sp24
            color: Theme.bgCard
            border.color: Theme.borderSubtle
            border.width: 1
            radius: Theme.radiusXl

            ColumnLayout {
                id: connContent
                anchors.fill: parent
                anchors.margins: Theme.sp24
                spacing: Theme.sp16

                RowLayout {
                    spacing: Theme.sp12
                    SectionLabel { text: qsTr("PORT"); Layout.preferredWidth: 72; Layout.alignment: Qt.AlignRight }
                    StyledComboBox {
                        id: portCombo
                        Layout.fillWidth: true
                        model: ListModel { id: portModel }
                        textRole: "display"
                        Component.onCompleted: refreshPorts()
                    }
                }

                RowLayout {
                    spacing: Theme.sp12
                    SectionLabel { text: qsTr("BAUD"); Layout.preferredWidth: 72; Layout.alignment: Qt.AlignRight }
                    StyledComboBox {
                        id: baudCombo
                        Layout.fillWidth: true
                        model: ["9600","19200","38400","57600","115200","230400","460800","921600"]
                        currentIndex: 4
                    }
                }

                GhostButton {
                    text: qsTr("Refresh Ports")
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 120
                    onClicked: refreshPorts()
                }

                Rectangle { Layout.preferredHeight: 1; Layout.fillWidth: true; color: Theme.borderSubtle }

                Button {
                    id: connectBtn
                    Layout.fillWidth: true
                    Layout.preferredHeight: 44

                    contentItem: Text {
                        text: bridge.connected ? qsTr("Disconnect") : qsTr("Connect")
                        color: Theme.bgBase
                        font.pixelSize: Theme.fontLabel
                        font.weight: Font.Bold
                        font.letterSpacing: 1
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        radius: Theme.radiusLg
                        color: bridge.connected
                            ? (connectBtn.down ? "#991b1b" : connectBtn.hovered ? "#dc2626" : Theme.error)
                            : (connectBtn.down ? Theme.accentMuted : connectBtn.hovered ? Theme.accentGlow : Theme.accent)
                    }

                    onClicked: {
                        if (bridge.connected) bridge.disconnectDevice()
                        else {
                            var ports = bridge.availablePorts()
                            if (portCombo.currentIndex >= 0 && portCombo.currentIndex < ports.length)
                                bridge.connectDevice(ports[portCombo.currentIndex].name, parseInt(baudCombo.currentText))
                        }
                    }
                }
            }
        }
    }

    function refreshPorts() {
        portModel.clear()
        var ports = bridge.availablePorts()
        for (var i = 0; i < ports.length; i++)
            portModel.append({"display": ports[i].name + "  \u2502  " + ports[i].desc, "name": ports[i].name})
    }
}
