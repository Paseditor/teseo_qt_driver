import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

TextField {
    id: sInput
    color: Theme.textPrimary
    placeholderTextColor: Theme.textDisabled
    font.pixelSize: Theme.fontBody
    font.family: Theme.fontFamily
    leftPadding: Theme.sp12
    rightPadding: Theme.sp12
    topPadding: Theme.sp8
    bottomPadding: Theme.sp8
    background: Rectangle {
        radius: Theme.radiusMd
        color: Theme.bgInput
        border.color: sInput.activeFocus ? Theme.borderFocus : Theme.borderSubtle
        border.width: 1
    }
}
