#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    double elapsedTime() const { return m_elapsedTime; }

signals:
    void timeUpdated(double time);
    void lapTimeUpdated(int lap, double time);

private slots:
    void updateTime();

private:
    QTimer *m_timer;
    double m_elapsedTime;
    int m_lapCount;
};

#endif // STOPWATCH_H
