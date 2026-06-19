import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

Button {
    id: pBtn
    property color btnColor: Theme.accent
    contentItem: Text {
        text: pBtn.text
        color: Theme.bgBase
        font.pixelSize: Theme.fontCaption
        font.weight: Font.DemiBold
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    background: Rectangle {
        implicitHeight: 32
        radius: Theme.radiusMd
        color: pBtn.down ? Qt.darker(pBtn.btnColor, 1.2) :
               pBtn.hovered ? Qt.lighter(pBtn.btnColor, 1.15) : pBtn.btnColor
    }
}
