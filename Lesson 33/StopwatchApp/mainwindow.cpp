#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_running(false),
    m_lapCount(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Таймер");
    ui->btnStartStop->setText("Старт");
    ui->labelTime->setText("0.0 сек");
    ui->btnLap->setText("Круг");
    ui->btnClear->setText("Отчистить");
    m_stopwatch = new Stopwatch(this);

    connect(m_stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTime);
    ui->btnLap->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnStartStop_clicked() {
    if (m_running) {
        m_stopwatch->stop();
        ui->btnStartStop->setText("Старт");
        ui->btnLap->setEnabled(false);
    } else {
        m_stopwatch->start();
        ui->btnStartStop->setText("Стоп");
        ui->btnLap->setEnabled(true);
    }
    m_running = !m_running;
}

void MainWindow::on_btnClear_clicked() {
    m_stopwatch->stop();
    m_stopwatch->reset();
    ui->labelTime->setText("0.0 сек");
    ui->textBrowser->clear();
    m_lapCount = 0;
    ui->btnStartStop->setText("Старт");
    ui->btnLap->setEnabled(false);
    m_running = false;
}

void MainWindow::on_btnLap_clicked() {
    m_lapCount++;
    double lapTime = m_stopwatch->elapsedTime();
    ui->textBrowser->append(QString("Круг %1, время: %2 сек").arg(m_lapCount).arg(lapTime));
}

void MainWindow::updateTime(double time) {
    ui->labelTime->setText(QString::number(time, 'f', 1) + " сек");
}
