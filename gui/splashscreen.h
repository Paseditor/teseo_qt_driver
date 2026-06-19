// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPainter>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QThread>
#include <QApplication>
#include <QFont>
#include <QPen>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = nullptr)
        : QSplashScreen(parent, QPixmap())
    {
        const int W = 560, H = 340;
        QPixmap pix(W, H);
        pix.fill(Qt::transparent);

        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);
        p.setRenderHint(QPainter::TextAntialiasing);

        // Background
        QLinearGradient bg(0, 0, W, H);
        bg.setColorAt(0.0, QColor(6, 10, 22));
        bg.setColorAt(0.4, QColor(10, 14, 30));
        bg.setColorAt(1.0, QColor(6, 10, 22));
        p.setPen(Qt::NoPen);
        p.setBrush(bg);
        p.drawRoundedRect(0, 0, W, H, 18, 18);

        // Subtle grid pattern
        p.setPen(QPen(QColor(20, 28, 50, 60), 1));
        for (int x = 0; x < W; x += 30)
            p.drawLine(x, 0, x, H);
        for (int y = 0; y < H; y += 30)
            p.drawLine(0, y, W, y);

        // Radial glow top-right
        QRadialGradient glow1(W - 80, 60, 180);
        glow1.setColorAt(0.0, QColor(0, 212, 255, 25));
        glow1.setColorAt(1.0, QColor(0, 212, 255, 0));
        p.setBrush(glow1);
        p.drawEllipse(W - 260, -120, 360, 360);

        // Radial glow bottom-left
        QRadialGradient glow2(80, H - 40, 150);
        glow2.setColorAt(0.0, QColor(139, 92, 246, 18));
        glow2.setColorAt(1.0, QColor(139, 92, 246, 0));
        p.setBrush(glow2);
        p.drawEllipse(-70, H - 190, 300, 300);

        // Top accent line
        QLinearGradient topLine(0, 0, W, 0);
        topLine.setColorAt(0.0, QColor(0, 212, 255, 0));
        topLine.setColorAt(0.3, QColor(0, 212, 255, 180));
        topLine.setColorAt(0.7, QColor(139, 92, 246, 180));
        topLine.setColorAt(1.0, QColor(139, 92, 246, 0));
        p.setBrush(topLine);
        p.drawRoundedRect(QRect(40, 0, W - 80, 3), 2, 2);

        // Bottom accent line
        QLinearGradient botLine(0, 0, W, 0);
        botLine.setColorAt(0.0, QColor(139, 92, 246, 0));
        botLine.setColorAt(0.3, QColor(139, 92, 246, 120));
        botLine.setColorAt(0.7, QColor(0, 212, 255, 120));
        botLine.setColorAt(1.0, QColor(0, 212, 255, 0));
        p.setBrush(botLine);
        p.drawRoundedRect(QRect(40, H - 3, W - 80, 3), 2, 2);

        // GNSS Satellite icon
        int cx = W / 2, cy = 115;
        // Outer ring
        p.setPen(QPen(QColor(0, 212, 255, 100), 2));
        p.setBrush(Qt::NoBrush);
        p.drawEllipse(cx - 32, cy - 32, 64, 64);
        // Middle ring
        p.setPen(QPen(QColor(0, 212, 255, 140), 1.5));
        p.drawEllipse(cx - 20, cy - 20, 40, 40);
        // Cross lines
        p.setPen(QPen(QColor(0, 212, 255, 80), 1));
        p.drawLine(cx - 40, cy, cx + 40, cy);
        p.drawLine(cx, cy - 40, cx, cy + 40);
        // Inner dot
        QRadialGradient dot(cx, cy, 10);
        dot.setColorAt(0.0, QColor(0, 212, 255, 220));
        dot.setColorAt(1.0, QColor(0, 212, 255, 60));
        p.setBrush(dot);
        p.setPen(Qt::NoPen);
        p.drawEllipse(cx - 10, cy - 10, 20, 20);
        // Signal arcs
        p.setPen(QPen(QColor(0, 212, 255, 50), 1.5));
        p.drawArc(cx - 48, cy - 48, 96, 96, 30 * 16, 120 * 16);
        p.drawArc(cx - 48, cy - 48, 96, 96, 210 * 16, 120 * 16);

        // Title
        p.setPen(QColor(224, 228, 240));
        QFont titleFont("Segoe UI", 30, QFont::DemiBold);
        p.setFont(titleFont);
        p.drawText(QRect(0, 55, W, 50), Qt::AlignCenter, "ArneeCode");

        // Subtitle
        p.setPen(QColor(0, 212, 255));
        QFont subFont("Segoe UI", 12, QFont::Normal);
        p.setFont(subFont);
        p.drawText(QRect(0, 160, W, 30), Qt::AlignCenter, "Teseo-VIC3  GNSS  Test  Tool");

        // Version info
        p.setPen(QColor(75, 85, 130));
        QFont verFont("Segoe UI", 9);
        p.setFont(verFont);
        p.drawText(QRect(0, 195, W, 20), Qt::AlignCenter, "v1.0.0   |   Qt 5.15.2   |   UM2791 Rev 3   |   2026");

        // Loading dots animation area
        p.setPen(QColor(0, 212, 255, 160));
        QFont loadFont("Segoe UI", 10);
        p.setFont(loadFont);
        p.drawText(QRect(0, 275, W, 20), Qt::AlignCenter, "Initializing...");

        // Progress bar background
        p.setBrush(QColor(20, 28, 50));
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(QRect(80, 300, W - 160, 4), 2, 2);

        // Progress bar fill (partial - for visual effect)
        QLinearGradient progress(80, 0, 80 + (W - 160) * 0.6, 0);
        progress.setColorAt(0.0, QColor(0, 212, 255));
        progress.setColorAt(1.0, QColor(139, 92, 246));
        p.setBrush(progress);
        p.drawRoundedRect(QRect(80, 300, (W - 160) * 0.6, 4), 2, 2);

        p.end();

        setPixmap(pix);
        setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
    }

    void showProgress(const QString &msg)
    {
        showMessage(msg, Qt::AlignBottom | Qt::AlignHCenter, QColor(75, 85, 130));
    }
};

#endif // SPLASHSCREEN_H
