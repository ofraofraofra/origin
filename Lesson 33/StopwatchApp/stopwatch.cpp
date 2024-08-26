#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), m_elapsedTime(0), m_lapCount(0) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::start() {
    m_timer->start(100); // Обновление каждые 0.1 секунды
}

void Stopwatch::stop() {
    m_timer->stop();
}

void Stopwatch::reset() {
    m_elapsedTime = 0;
    m_lapCount = 0;
    emit timeUpdated(m_elapsedTime);
}

void Stopwatch::updateTime() {
    m_elapsedTime += 0.1;
    emit timeUpdated(m_elapsedTime);
}
