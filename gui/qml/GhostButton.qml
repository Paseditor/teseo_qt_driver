import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

Button {
    id: gBtn
    property color btnColor: Theme.textSecondary
    contentItem: Text {
        text: gBtn.text
        color: gBtn.hovered ? Theme.textPrimary : gBtn.btnColor
        font.pixelSize: Theme.fontCaption
        font.weight: Font.Medium
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    background: Rectangle {
        implicitHeight: 32
        radius: Theme.radiusMd
        color: gBtn.down ? Theme.bgElevated :
               gBtn.hovered ? Theme.bgCard : "transparent"
        border.color: gBtn.hovered ? Theme.borderDefault : Theme.borderSubtle
        border.width: 1
    }
}
