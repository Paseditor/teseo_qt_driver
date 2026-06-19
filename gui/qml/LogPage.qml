import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "."

Item {
    property bool paused: false

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Theme.sp16
        spacing: Theme.sp12

        // Toolbar
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 36
            color: Theme.bgCard
            radius: Theme.radiusMd
            border.color: Theme.borderSubtle
            border.width: 1

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: Theme.sp12
                anchors.rightMargin: Theme.sp12
                spacing: Theme.sp8

                GhostButton {
                    text: qsTr("Clear")
                    onClicked: logArea.clear()
                }
                GhostButton {
                    text: paused ? qsTr("Resume") : qsTr("Pause")
                    btnColor: paused ? Theme.warning : Theme.textSecondary
                    onClicked: paused = !paused
                }
                Rectangle { Layout.preferredWidth: 1; Layout.preferredHeight: 20; color: Theme.borderSubtle }
                StyledCheckBox { id: showNmea; text: qsTr("NMEA"); checked: true }
                StyledCheckBox { id: autoScroll; text: qsTr("Auto-scroll"); checked: true }
                Item { Layout.fillWidth: true }
                Text {
                    text: logArea.length + " chars"
                    font.pixelSize: Theme.fontTiny
                    font.family: Theme.monoFamily
                    color: Theme.textDisabled
                }
            }
        }

        // Log area
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Theme.bgCard
            radius: Theme.radiusLg
            border.color: Theme.borderSubtle
            border.width: 1

            ScrollView {
                anchors.fill: parent
                anchors.margins: 1

                TextArea {
                    id: logArea
                    readOnly: true
                    wrapMode: TextArea.Wrap
                    color: Theme.textSecondary
                    font.family: Theme.monoFamily
                    font.pixelSize: Theme.fontSmall
                    background: Rectangle { color: Theme.bgBase; radius: Theme.radiusLg }

                    Connections {
                        target: bridge
                        onNmeaReceived: {
                            if (paused || !showNmea.checked) return
                            var clr = sentence.indexOf("$PSTM") === 0 ? Theme.accent : Theme.textMuted
                            logArea.append("<span style='color:" + clr + "'>" + Qt.formatTime(new Date(), "HH:mm:ss.zzz") + "  " + sentence + "</span>")
                            if (autoScroll.checked) logArea.cursorPosition = logArea.length - 1
                        }
                        onResponseReceived: {
                            if (paused) return
                            logArea.append("<span style='color:" + Theme.success + "'>" + Qt.formatTime(new Date(), "HH:mm:ss.zzz") + "  TX: " + response + "</span>")
                            if (autoScroll.checked) logArea.cursorPosition = logArea.length - 1
                        }
                        onErrorOccurred: {
                            logArea.append("<span style='color:" + Theme.error + "'>" + Qt.formatTime(new Date(), "HH:mm:ss.zzz") + "  ERROR: " + error + "</span>")
                            if (autoScroll.checked) logArea.cursorPosition = logArea.length - 1
                        }
                    }
                }
            }
        }
    }
}
