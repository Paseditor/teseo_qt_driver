import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

CheckBox {
    id: sCb
    contentItem: Text {
        text: sCb.text
        color: Theme.textSecondary
        font.pixelSize: Theme.fontCaption
        leftPadding: Theme.sp24 + Theme.sp4
        verticalAlignment: Text.AlignVCenter
    }
    indicator: Rectangle {
        implicitWidth: Theme.sp16
        implicitHeight: Theme.sp16
        x: sCb.leftPadding
        y: parent.height / 2 - height / 2
        radius: Theme.radiusSm
        color: sCb.checked ? Theme.accent : Theme.bgInput
        border.color: sCb.checked ? Theme.accent : Theme.borderDefault
        border.width: 1
        Text {
            anchors.centerIn: parent
            text: "\u2713"
            font.pixelSize: 10
            font.weight: Font.Bold
            color: Theme.bgBase
            visible: sCb.checked
        }
    }
}
