import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

Button {
    id: dBtn
    contentItem: Text {
        text: dBtn.text
        color: Theme.textPrimary
        font.pixelSize: Theme.fontCaption
        font.weight: Font.DemiBold
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    background: Rectangle {
        implicitHeight: 32
        radius: Theme.radiusMd
        color: dBtn.down ? "#991b1b" :
               dBtn.hovered ? "#dc2626" : Theme.error
    }
}
