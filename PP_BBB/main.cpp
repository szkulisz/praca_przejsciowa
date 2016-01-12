#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setHostName("localhost");
    dataBase.setPort(3306);
    dataBase.setUserName("root");
    dataBase.setPassword("roott");
    std::cout << "Testy..." <<std::endl;
    if(!dataBase.open()){
        std::cout << "Błąd..." <<std::endl;
    }
    //return a.exec();
    return 0;
}

