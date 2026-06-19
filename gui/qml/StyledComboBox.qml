import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

ComboBox {
    id: sCombo
    implicitHeight: 32
    font.pixelSize: Theme.fontBody
    background: Rectangle {
        radius: Theme.radiusMd
        color: Theme.bgInput
        border.color: sCombo.activeFocus ? Theme.borderFocus : Theme.borderSubtle
        border.width: 1
    }
    contentItem: Text {
        text: sCombo.currentText
        color: Theme.textPrimary
        font: sCombo.font
        leftPadding: Theme.sp12
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    indicator: Text {
        x: sCombo.width - Theme.sp24
        y: sCombo.height / 2 - height / 2
        text: "\u25BC"
        font.pixelSize: 8
        color: Theme.textMuted
    }
    popup: Popup {
        y: sCombo.height
        width: sCombo.width
        implicitHeight: contentItem.implicitHeight
        padding: 1
        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: sCombo.popup.visible ? sCombo.delegateModel : null
        }
        background: Rectangle {
            radius: Theme.radiusMd
            color: Theme.bgElevated
            border.color: Theme.borderDefault
            border.width: 1
        }
    }
    delegate: ItemDelegate {
        width: sCombo.width
        contentItem: Text {
            text: modelData
            color: Theme.textPrimary
            font.pixelSize: Theme.fontBody
            leftPadding: Theme.sp12
            verticalAlignment: Text.AlignVCenter
        }
        background: Rectangle {
            color: highlighted ? Theme.bgCard : "transparent"
            radius: Theme.radiusSm
        }
    }
}
