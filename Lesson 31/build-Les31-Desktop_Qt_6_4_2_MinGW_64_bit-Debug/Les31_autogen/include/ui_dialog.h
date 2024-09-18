/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Dialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName("spinBox");

        gridLayout->addWidget(spinBox, 4, 0, 1, 1);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(pushButton_2, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217 \321\205\320\276\321\201\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\320\236\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
