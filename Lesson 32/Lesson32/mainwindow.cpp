#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Какой вы мальчик");

    ui->pushButton->setText("Врррвах");
    ui->pushButton->setCheckable(true);

    ui->radioButton_3->setText("Да");
    ui->radioButton_4->setText("Нет");
    ui->radioButton_3->setChecked(true);


    ui->comboBox->addItem("Шарик");
    ui->comboBox->addItem("Бобик");
    ui->comboBox->addItem("Дружок");

    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);

    ui->progressBar->setFormat("%p%");

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::updatePushButtonText);
}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->progressBar->value() < 10)
        {
            ui->progressBar->setValue(ui->progressBar->value() + 1);
        }
        else
        {
            ui->progressBar->setValue(0);
        }
}

void MainWindow::updatePushButtonText(int index)
{
    ui->progressBar->setValue(0);
    if (index == 0) // Шарик
    {
        ui->pushButton->setText("Врррвах");
    }
    else if (index == 1) // Бобик
    {
        ui->pushButton->setText("Гав-гав");
    }
    else if (index == 2) // Дружок
    {
        ui->pushButton->setText("Тяв-тяв");
    }
}

