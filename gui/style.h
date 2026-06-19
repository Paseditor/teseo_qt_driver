// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

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
            background-color: #0a0e1a;
        }

        QTabWidget::pane {
            border: 1px solid #1a1f35;
            background-color: #0a0e1a;
            border-radius: 8px;
        }

        QTabBar::tab {
            background-color: #12162a;
            color: #6b7394;
            padding: 10px 18px;
            margin-right: 2px;
            border-top-left-radius: 8px;
            border-top-right-radius: 8px;
            border: 1px solid #1a1f35;
            border-bottom: none;
            min-width: 90px;
            font-weight: 500;
        }

        QTabBar::tab:selected {
            background-color: #0a0e1a;
            color: #00d4ff;
            border-bottom: 2px solid #00d4ff;
            font-weight: 600;
        }

        QTabBar::tab:hover:!selected {
            background-color: #1a1f35;
            color: #8b93b8;
        }

        QGroupBox {
            background-color: #111628;
            border: 1px solid #1e2440;
            border-radius: 10px;
            margin-top: 14px;
            padding: 16px 12px 12px 12px;
            color: #c8cee8;
            font-weight: 600;
            font-size: 12px;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 2px 10px;
            color: #00d4ff;
            background-color: #111628;
            border-radius: 4px;
            font-weight: 700;
        }

        QLabel {
            color: #8b93b8;
            font-size: 12px;
            background: transparent;
            border: none;
            padding: 0;
        }

        QLineEdit {
            background-color: #080c18;
            border: 1px solid #252b45;
            border-radius: 6px;
            padding: 6px 10px;
            color: #e0e4f0;
            min-height: 20px;
            selection-background-color: #00d4ff;
            selection-color: #0a0e1a;
        }

        QLineEdit:focus {
            border: 1px solid #00d4ff;
        }

        QLineEdit:disabled {
            background-color: #0d1020;
            color: #4a5070;
        }

        QSpinBox, QDoubleSpinBox {
            background-color: #080c18;
            border: 1px solid #252b45;
            border-radius: 6px;
            padding: 4px 8px;
            padding-right: 28px;
            color: #e0e4f0;
            min-height: 22px;
            min-width: 60px;
            selection-background-color: #00d4ff;
            selection-color: #0a0e1a;
        }

        QSpinBox:focus, QDoubleSpinBox:focus {
            border: 1px solid #00d4ff;
        }

        QSpinBox::up-button, QDoubleSpinBox::up-button {
            subcontrol-origin: border;
            subcontrol-position: top right;
            width: 24px;
            height: 50%;
            border: none;
            border-left: 1px solid #1e2440;
            border-bottom: 1px solid #1e2440;
            border-top-right-radius: 5px;
            background-color: #12162a;
        }

        QSpinBox::up-button:hover, QDoubleSpinBox::up-button:hover {
            background-color: #1a1f35;
        }

        QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed {
            background-color: #252b45;
        }

        QSpinBox::down-button, QDoubleSpinBox::down-button {
            subcontrol-origin: border;
            subcontrol-position: bottom right;
            width: 24px;
            height: 50%;
            border: none;
            border-left: 1px solid #1e2440;
            border-top: none;
            border-bottom-right-radius: 5px;
            background-color: #12162a;
        }

        QSpinBox::down-button:hover, QDoubleSpinBox::down-button:hover {
            background-color: #1a1f35;
        }

        QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed {
            background-color: #252b45;
        }

        QComboBox {
            background-color: #080c18;
            border: 1px solid #252b45;
            border-radius: 6px;
            padding: 6px 10px;
            padding-right: 30px;
            color: #e0e4f0;
            min-height: 22px;
            min-width: 60px;
        }

        QComboBox:focus {
            border: 1px solid #00d4ff;
        }

        QComboBox:disabled {
            background-color: #0d1020;
            color: #4a5070;
        }

        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: center right;
            width: 26px;
            height: 100%;
            border: none;
            border-left: 1px solid #1e2440;
            border-top-right-radius: 5px;
            border-bottom-right-radius: 5px;
            background-color: #12162a;
        }

        QComboBox::drop-down:hover {
            background-color: #1a1f35;
        }

        QComboBox QAbstractItemView {
            background-color: #111628;
            border: 1px solid #252b45;
            color: #e0e4f0;
            selection-background-color: #1a2540;
            selection-color: #00d4ff;
            outline: none;
            padding: 4px;
        }

        QPushButton {
            background-color: #1a1f35;
            color: #c8cee8;
            border: 1px solid #252b45;
            border-radius: 6px;
            padding: 7px 14px;
            font-weight: 500;
            min-height: 22px;
        }

        QPushButton:hover {
            background-color: #252b45;
            border-color: #00d4ff;
            color: #00d4ff;
        }

        QPushButton:pressed {
            background-color: #0e1220;
        }

        QPushButton:disabled {
            background-color: #0d1020;
            color: #3a4060;
            border-color: #1a1f35;
        }

        QPushButton:checked {
            background-color: #0a2a3e;
            border-color: #00d4ff;
            color: #00d4ff;
        }

        QCheckBox {
            color: #8b93b8;
            spacing: 8px;
            font-size: 12px;
            background: transparent;
        }

        QCheckBox::indicator {
            width: 18px;
            height: 18px;
            border: 2px solid #252b45;
            border-radius: 4px;
            background-color: #080c18;
        }

        QCheckBox::indicator:checked {
            background-color: #00d4ff;
            border-color: #00d4ff;
        }

        QCheckBox::indicator:hover {
            border-color: #00d4ff;
        }

        QTextEdit {
            background-color: #080b16;
            border: 1px solid #1a1f35;
            border-radius: 8px;
            color: #a8b0d0;
            padding: 8px;
            font-family: 'Cascadia Code', 'Consolas', 'Fira Code', monospace;
            font-size: 11px;
            selection-background-color: #00d4ff;
            selection-color: #0a0e1a;
        }

        QTableWidget {
            background-color: #080b16;
            border: 1px solid #1a1f35;
            border-radius: 8px;
            gridline-color: #141829;
            color: #a8b0d0;
            selection-background-color: #0a2a3e;
            selection-color: #00d4ff;
        }

        QTableWidget::item {
            padding: 6px;
            border-bottom: 1px solid #111628;
        }

        QTableWidget::item:selected {
            background-color: #0a2a3e;
            color: #00d4ff;
        }

        QTableWidget::item:hover {
            background-color: #141829;
        }

        QHeaderView::section {
            background-color: #111628;
            color: #6b7394;
            padding: 8px;
            border: none;
            border-bottom: 2px solid #00d4ff;
            font-weight: 700;
            font-size: 11px;
        }

        QScrollBar:vertical {
            background-color: #0a0e1a;
            width: 10px;
            border-radius: 5px;
            margin: 0;
        }

        QScrollBar::handle:vertical {
            background-color: #252b45;
            border-radius: 5px;
            min-height: 30px;
        }

        QScrollBar::handle:vertical:hover {
            background-color: #3a4060;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0;
        }

        QScrollBar:horizontal {
            background-color: #0a0e1a;
            height: 10px;
            border-radius: 5px;
        }

        QScrollBar::handle:horizontal {
            background-color: #252b45;
            border-radius: 5px;
            min-width: 30px;
        }

        QScrollBar::handle:horizontal:hover {
            background-color: #3a4060;
        }

        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
            width: 0;
        }

        QStatusBar {
            background-color: #0d1020;
            color: #6b7394;
            border-top: 1px solid #1a1f35;
            font-size: 12px;
            padding: 2px;
        }

        QToolTip {
            background-color: #1a1f35;
            color: #e0e4f0;
            border: 1px solid #00d4ff;
            border-radius: 4px;
            padding: 6px 10px;
            font-size: 12px;
        }
    )";
}

} // namespace Style

#endif // STYLE_H
