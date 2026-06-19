import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

TextArea {
    id: logArea
    readOnly: true
    wrapMode: TextArea.Wrap
    color: Theme.textSecondary
    font.family: Theme.monoFamily
    font.pixelSize: Theme.fontSmall
    background: Rectangle {
        color: Theme.bgBase
        radius: Theme.radiusMd
        border.color: Theme.borderSubtle
        border.width: 1
    }
}
