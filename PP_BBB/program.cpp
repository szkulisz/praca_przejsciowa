#include "program.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <iostream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <stdlib.h>

Program::Program(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort();
    serial->setPortName("ttyS4");
    serial->setBaudRate(QSerialPort::Baud19200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);


    if (serial->open(QIODevice::ReadWrite)) {
        std::cout << "serial ready" << std::endl;
    } else {
        std::cout << "serial not opened..." << std::endl;
    }

    connect(serial, SIGNAL(readyRead()),this,SLOT(readData()));

    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");//192.168.1.212");
    dataBase.setPort(3306);
    dataBase.setUserName("mgr");
    dataBase.setPassword("mgrr");
    dataBase.setDatabaseName("PP");
    if (!dataBase.open()) {
        std::cout << "Cannot connect with database..." <<std::endl;
        std::cout << dataBase.lastError().text().toStdString() <<std::endl;
    } else {
        std::cout << "database ready" << std::endl;
    }
}


void Program::readData(){

     QString message = serial->readAll();

     QRegExp rx("(\\ |\\=)");
     QStringList tokens = message.split(rx,QString::SkipEmptyParts);
//    std::cout << message.toStdString();
//    serial->write(message.toLocal8Bit());
//    serial->flush();
     if ( tokens.at(0).compare("ADDR") == 0 ) {
         int addr = tokens.at(1).toInt();
         float value = tokens.at(2).toFloat();
         QString unit = tokens.at(3);
         QSqlQuery query, query2, query3, query4;

         query.prepare("SELECT id FROM names WHERE id = ?");
         query.bindValue(0,addr);
         query.exec();

         if ( !query.next() ){
             query2.prepare("CREATE TABLE addr? "
                           "( "
                           "Time DATETIME DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, "
                           "Value float, "
                           "Unit text ) ");
             query2.bindValue(0,addr);
             query2.exec();

             query3.prepare("INSERT INTO names (id, name, measured_variable)"
                           "VALUES (?, \"BEZ NAZWY\", \"NIEZDEFINIOWANO\")");
             query3.bindValue(0,addr);
             query3.exec();
         }
         query4.prepare("INSERT INTO addr? (`Value`, `Unit`)"
                     "VALUES (?, ?)");
         query4.bindValue(0,addr);
         query4.bindValue(1,value);
         query4.bindValue(2,unit);
         query4.exec();

         serial->write("OK");
     } else {
         serial->write("ERR");
     }

}
