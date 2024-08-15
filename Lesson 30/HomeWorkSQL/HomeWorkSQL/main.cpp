#include <QCoreApplication>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QTcpSocket tcpSocket;

       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");

    return a.exec();
}
