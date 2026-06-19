import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

SpinBox {
    id: sSpin
    implicitHeight: 32
    leftPadding: Theme.sp24
    rightPadding: Theme.sp24
    font.pixelSize: Theme.fontBody

    background: Rectangle {
        radius: Theme.radiusMd
        color: Theme.bgInput
        border.color: sSpin.activeFocus ? Theme.borderFocus : Theme.borderSubtle
        border.width: 1
    }
    contentItem: TextInput {
        text: sSpin.value
        color: Theme.textPrimary
        font: sSpin.font
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        readOnly: !sSpin.editable
        validator: sSpin.validator
    }

    down.indicator: Rectangle {
        x: 0
        height: sSpin.height
        implicitWidth: Theme.sp24
        radius: Theme.radiusMd
        color: sSpin.down.pressed ? Theme.bgElevated
                                  : sSpin.down.hovered ? Theme.bgCard : "transparent"
        border.color: Theme.borderSubtle
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "\u2212"
            color: sSpin.enabled ? Theme.textSecondary : Theme.textDisabled
            font.pixelSize: Theme.fontHeading
        }
    }

    up.indicator: Rectangle {
        x: sSpin.width - width
        height: sSpin.height
        implicitWidth: Theme.sp24
        radius: Theme.radiusMd
        color: sSpin.up.pressed ? Theme.bgElevated
                                : sSpin.up.hovered ? Theme.bgCard : "transparent"
        border.color: Theme.borderSubtle
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "+"
            color: sSpin.enabled ? Theme.textSecondary : Theme.textDisabled
            font.pixelSize: Theme.fontHeading
        }
    }
}
