pragma Singleton
import QtQuick 2.15

QtObject {
    // Surfaces
    readonly property color bgBase:      "#07090f"
    readonly property color bgSurface:   "#0c1019"
    readonly property color bgCard:      "#111827"
    readonly property color bgElevated:  "#1a2332"
    readonly property color bgInput:     "#0a0e17"
    readonly property color bgHeader:    "#0e1220"
    readonly property color bgFooter:    "#080b14"

    // Borders
    readonly property color borderSubtle:  "#1a2236"
    readonly property color borderDefault: "#243044"
    readonly property color borderFocus:   "#00b8d9"

    // Text
    readonly property color textPrimary:   "#e8ecf4"
    readonly property color textSecondary: "#7b8baa"
    readonly property color textMuted:     "#4a5578"
    readonly property color textDisabled:  "#2d3654"

    // Accent
    readonly property color accent:        "#00b8d9"
    readonly property color accentMuted:   "#006d82"
    readonly property color accentGlow:    "#00e5ff"

    // Semantic
    readonly property color success:       "#10b981"
    readonly property color error:         "#ef4444"
    readonly property color warning:       "#f59e0b"
    readonly property color info:          "#3b82f6"

    // Satellite CN0 scale
    readonly property color cn0Weak:       "#ef4444"
    readonly property color cn0Fair:       "#f59e0b"
    readonly property color cn0Good:       "#10b981"
    readonly property color cn0Strong:     "#00b8d9"

    // Typography
    readonly property string fontFamily:      "Segoe UI"
    readonly property string monoFamily:      "Cascadia Code"
    readonly property int    fontTiny:        9
    readonly property int    fontSmall:       10
    readonly property int    fontCaption:     11
    readonly property int    fontBody:        12
    readonly property int    fontLabel:       13
    readonly property int    fontHeading:     16
    readonly property int    fontDisplay:     22

    // Spacing
    readonly property int    sp4:  4
    readonly property int    sp6:  6
    readonly property int    sp8:  8
    readonly property int    sp12: 12
    readonly property int    sp16: 16
    readonly property int    sp20: 20
    readonly property int    sp24: 24
    readonly property int    sp32: 32

    // Radii
    readonly property int    radiusSm: 4
    readonly property int    radiusMd: 6
    readonly property int    radiusLg: 10
    readonly property int    radiusXl: 14

    // Shadows
    readonly property color shadowColor: "#00000060"

    function cn0Color(value) {
        if (value >= 40) return cn0Strong
        if (value >= 30) return cn0Good
        if (value >= 20) return cn0Fair
        return cn0Weak
    }

    function fixQualityText(code) {
        var map = {
            0: qsTr("No Fix"),
            1: qsTr("GPS SPS"),
            2: qsTr("DGPS"),
            6: qsTr("Estimated (DR)")
        }
        return map[code] || qsTr("Unknown")
    }
}
