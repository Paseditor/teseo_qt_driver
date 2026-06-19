// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2024 ArneeCode. All rights reserved.

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPainter>
#include <QLinearGradient>
#include <QThread>
#include <QApplication>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = nullptr)
        : QSplashScreen(parent, QPixmap())
    {
        QPixmap pix(500, 300);
        pix.fill(Qt::transparent);

        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);

        QLinearGradient bg(0, 0, 500, 300);
        bg.setColorAt(0, QColor(15, 23, 42));
        bg.setColorAt(0.5, QColor(30, 41, 59));
        bg.setColorAt(1, QColor(15, 23, 42));
        p.setBrush(bg);
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(0, 0, 500, 300, 16, 16);

        QLinearGradient accent(0, 258, 500, 258);
        accent.setColorAt(0, QColor(56, 189, 248));
        accent.setColorAt(0.5, QColor(99, 102, 241));
        accent.setColorAt(1, QColor(168, 85, 247));
        p.setBrush(accent);
        p.drawRoundedRect(QRect(40, 255, 420, 3), 2, 2);

        p.setPen(QColor(226, 232, 240));
        QFont titleFont("Segoe UI", 28, QFont::Bold);
        p.setFont(titleFont);
        p.drawText(QRect(0, 40, 500, 50), Qt::AlignCenter, "ArneeCode");

        p.setPen(QColor(148, 163, 184));
        QFont subFont("Segoe UI", 11);
        p.setFont(subFont);
        p.drawText(QRect(0, 90, 500, 30), Qt::AlignCenter, "Teseo-VIC3 GNSS Test Tool");

        p.setPen(QColor(100, 116, 139));
        QFont verFont("Segoe UI", 9);
        p.setFont(verFont);
        p.drawText(QRect(0, 125, 500, 20), Qt::AlignCenter, "v1.0.0  |  Qt 5.15.2  |  UM2791 Rev 3");

        p.setPen(QPen(QColor(56, 189, 248, 120), 2));
        p.setBrush(Qt::NoBrush);
        int cx = 250, cy = 175;
        p.drawEllipse(cx - 18, cy - 18, 36, 36);
        p.drawLine(cx - 25, cy, cx + 25, cy);
        p.drawLine(cx, cy - 25, cx, cy + 25);
        p.drawEllipse(cx - 8, cy - 8, 16, 16);

        p.end();

        setPixmap(pix);
        setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
    }

    void showProgress(const QString &msg)
    {
        showMessage(msg, Qt::AlignBottom | Qt::AlignHCenter, QColor(148, 163, 184));
    }
};

#endif // SPLASHSCREEN_H
