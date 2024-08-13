#include <QtWidgets>
#include <QMessageBox>

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        QMessageBox msg;
        msg.setText ("Hello Graphic Word!");
        msg.setWindowTitle("I'm Life!");
        msg.setStyleSheet("color: green");
        msg. setIcon(QMessageBox::Information);

        msg.show();

        return a.exec();
    }
