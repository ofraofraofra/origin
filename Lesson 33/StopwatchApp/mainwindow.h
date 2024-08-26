#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStartStop_clicked();
    void on_btnClear_clicked();
    void on_btnLap_clicked();
    void updateTime(double time);

private:
    Ui::MainWindow *ui;
    Stopwatch *m_stopwatch;
    bool m_running;
    int m_lapCount;
};

#endif // MAINWINDOW_H
