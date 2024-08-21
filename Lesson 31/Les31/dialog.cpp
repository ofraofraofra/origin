#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString host = ui->lineEdit->text();
    QString dbName = ui->lineEdit_2->text();
    QString user = ui->lineEdit_3->text();
    QString password = ui->lineEdit_4->text();
    uint port = ui->spinBox->value();
    close(); // для закрытия окна диалога
}

