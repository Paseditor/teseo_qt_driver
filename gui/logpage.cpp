// ArneeCode - Teseo-VIC3 Qt Driver
// Copyright (c) 2026 ArneeCode. All rights reserved.

#include "logpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>

LogPage::LogPage(Teseo::TeseoDriver *driver, QWidget *parent)
    : QWidget(parent), m_driver(driver)
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(12, 12, 12, 12);
    layout->setSpacing(8);

    auto *ctrlLayout = new QHBoxLayout;
    ctrlLayout->setSpacing(8);
    auto *clearBtn = new QPushButton("Clear");
    auto *pauseBtn = new QPushButton("Pause");
    pauseBtn->setCheckable(true);
    m_autoScroll = new QCheckBox("Auto-scroll");
    m_autoScroll->setChecked(true);
    m_showNmea = new QCheckBox("Show NMEA");
    m_showNmea->setChecked(true);
    ctrlLayout->addWidget(clearBtn);
    ctrlLayout->addWidget(pauseBtn);
    ctrlLayout->addWidget(m_autoScroll);
    ctrlLayout->addWidget(m_showNmea);
    ctrlLayout->addStretch();

    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setFontFamily("Cascadia Code");
    m_logEdit->setFontPointSize(10);
    m_logEdit->setPlaceholderText("NMEA / PSTM log output...");

    layout->addLayout(ctrlLayout);
    layout->addWidget(m_logEdit);

    connect(clearBtn, &QPushButton::clicked, m_logEdit, &QTextEdit::clear);
    connect(pauseBtn, &QPushButton::clicked, [this, pauseBtn](bool checked) {
        m_paused = checked;
        pauseBtn->setText(checked ? "Resume" : "Pause");
    });

    connect(m_driver, &Teseo::TeseoDriver::nmeaSentenceReceived,
            this, [this](const QByteArray &s) {
        if (m_paused || !m_showNmea->isChecked()) return;
        QString color = s.startsWith("$PSTM") ? "#38bdf8" : "#94a3b8";
        m_logEdit->append(QString("<span style='color:%1'>%2 %3</span>")
                          .arg(color,
                               QDateTime::currentDateTime().toString("HH:mm:ss.zzz"),
                               QString::fromLatin1(s)));
        if (m_autoScroll->isChecked()) {
            QTextCursor c = m_logEdit->textCursor();
            c.movePosition(QTextCursor::End);
            m_logEdit->setTextCursor(c);
        }
    });

    connect(m_driver, &Teseo::TeseoDriver::responseReceived,
            this, [this](const QByteArray &r) {
        if (m_paused) return;
        m_logEdit->append(QString("<span style='color:#4ade80'>%1 TX: %2</span>")
                          .arg(QDateTime::currentDateTime().toString("HH:mm:ss.zzz"),
                               QString::fromLatin1(r)));
    });

    connect(m_driver, &Teseo::TeseoDriver::errorOccurred,
            this, [this](const QString &e) {
        m_logEdit->append(QString("<span style='color:#f87171'>%1 ERROR: %2</span>")
                          .arg(QDateTime::currentDateTime().toString("HH:mm:ss.zzz"), e));
    });
}
