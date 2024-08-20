#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onOkClicked);
   connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onCancelClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOkClicked() {
    QString host = ui->lineEdit->text();
    QString dbName = ui->lineEdit_2->text();
    QString user = ui->lineEdit_3->text();
    QString password = ui->lineEdit_4->text();
    uint port = ui->spinBox->value();
}

void MainWindow::onCancelClicked() {

}
