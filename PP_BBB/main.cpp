#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <iostream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QT_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Example use QSerialPortInfo
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            std::cout << "Name : " << info.portName().toStdString();

            std::cout << "Description : " << info.description().toStdString();
            std::cout << "Manufacturer: " << info.manufacturer().toStdString();

            // Example use QSerialPort
            QSerialPort serial;
            serial.setPort(info);
            if (serial.open(QIODevice::ReadWrite))
                serial.close();
        }
//    QSqlDatabase dataBase;
//    dataBase = QSqlDatabase::addDatabase("QMYSQL");
//    dataBase.setHostName("localhost");//192.168.1.212");
//    dataBase.setPort(3306);
//    dataBase.setUserName("mgr");
//    dataBase.setPassword("mgrr");
//    dataBase.setDatabaseName("mgr");
//    std::cout << "Testy..." <<std::endl;
//    if(!dataBase.open()){
//        std::cout << "Błąd..." <<std::endl;
//    }
//    QSqlQuery query;
//    query.exec("INSERT INTO ver1 (ID, Chart, Pend, CV) VALUES (6, 10, 0, 0.5)");
//    query.exec("SELECT * FROM ver1");
//    std::cout << dataBase.lastError().text().toStdString() <<std::endl;
//    std::cout << query.lastError().text().toStdString() <<std::endl;

    //return a.exec();
    return 0;
}

