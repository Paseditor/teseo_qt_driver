#ifndef STYLE_H
#define STYLE_H

#include <QString>

namespace Style {

inline QString global()
{
    return R"(
        * {
            font-family: 'Segoe UI', 'SF Pro Display', 'Helvetica Neue', sans-serif;
            font-size: 13px;
        }

        QMainWindow {
            background-color: #0f172a;
        }

        QTabWidget::pane {
            border: 1px solid #1e293b;
            background-color: #0f172a;
            border-radius: 8px;
        }

        QTabBar::tab {
            background-color: #1e293b;
            color: #94a3b8;
            padding: 10px 20px;
            margin-right: 2px;
            border-top-left-radius: 8px;
            border-top-right-radius: 8px;
            border: 1px solid #334155;
            border-bottom: none;
            min-width: 100px;
        }

        QTabBar::tab:selected {
            background-color: #0f172a;
            color: #e2e8f0;
            border-bottom: 2px solid #38bdf8;
        }

        QTabBar::tab:hover:!selected {
            background-color: #334155;
            color: #e2e8f0;
        }

        QGroupBox {
            background-color: #1e293b;
            border: 1px solid #334155;
            border-radius: 10px;
            margin-top: 14px;
            padding: 18px 14px 14px 14px;
            color: #e2e8f0;
            font-weight: 600;
            font-size: 13px;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 2px 12px;
            color: #38bdf8;
            background-color: #1e293b;
            border-radius: 4px;
        }

        QLabel {
            color: #cbd5e1;
            font-size: 12px;
        }

        QLineEdit, QSpinBox, QDoubleSpinBox, QComboBox {
            background-color: #0f172a;
            border: 1px solid #334155;
            border-radius: 6px;
            padding: 7px 10px;
            color: #e2e8f0;
            selection-background-color: #38bdf8;
            selection-color: #0f172a;
        }

        QLineEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus {
            border: 1px solid #38bdf8;
        }

        QComboBox::drop-down {
            border: none;
            width: 24px;
        }

        QComboBox::down-arrow {
            image: none;
            border-left: 5px solid transparent;
            border-right: 5px solid transparent;
            border-top: 6px solid #94a3b8;
            margin-right: 8px;
        }

        QComboBox QAbstractItemView {
            background-color: #1e293b;
            border: 1px solid #334155;
            color: #e2e8f0;
            selection-background-color: #334155;
        }

        QPushButton {
            background-color: #334155;
            color: #e2e8f0;
            border: 1px solid #475569;
            border-radius: 6px;
            padding: 8px 16px;
            font-weight: 500;
        }

        QPushButton:hover {
            background-color: #475569;
            border-color: #38bdf8;
        }

        QPushButton:pressed {
            background-color: #1e293b;
        }

        QPushButton:checked {
            background-color: #0c4a6e;
            border-color: #38bdf8;
            color: #38bdf8;
        }

        QCheckBox {
            color: #cbd5e1;
            spacing: 8px;
        }

        QCheckBox::indicator {
            width: 18px;
            height: 18px;
            border: 2px solid #475569;
            border-radius: 4px;
            background-color: #0f172a;
        }

        QCheckBox::indicator:checked {
            background-color: #38bdf8;
            border-color: #38bdf8;
        }

        QTextEdit {
            background-color: #0f172a;
            border: 1px solid #334155;
            border-radius: 8px;
            color: #cbd5e1;
            padding: 8px;
            font-family: 'Cascadia Code', 'Consolas', 'Fira Code', monospace;
            font-size: 11px;
        }

        QTableWidget {
            background-color: #0f172a;
            border: 1px solid #334155;
            border-radius: 8px;
            gridline-color: #1e293b;
            color: #cbd5e1;
        }

        QTableWidget::item {
            padding: 6px;
            border-bottom: 1px solid #1e293b;
        }

        QTableWidget::item:selected {
            background-color: #1e3a5f;
            color: #e2e8f0;
        }

        QHeaderView::section {
            background-color: #1e293b;
            color: #94a3b8;
            padding: 8px;
            border: none;
            border-bottom: 2px solid #38bdf8;
            font-weight: 600;
            font-size: 11px;
        }

        QScrollBar:vertical {
            background-color: #0f172a;
            width: 8px;
            border-radius: 4px;
        }

        QScrollBar::handle:vertical {
            background-color: #334155;
            border-radius: 4px;
            min-height: 30px;
        }

        QScrollBar::handle:vertical:hover {
            background-color: #475569;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0;
        }

        QStatusBar {
            background-color: #1e293b;
            color: #94a3b8;
            border-top: 1px solid #334155;
            font-size: 12px;
        }

        QToolTip {
            background-color: #1e293b;
            color: #e2e8f0;
            border: 1px solid #38bdf8;
            border-radius: 4px;
            padding: 6px;
        }
    )";
}

} // namespace Style

#endif // STYLE_H
