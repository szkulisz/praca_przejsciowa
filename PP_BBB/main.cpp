#include <QCoreApplication>
#include "program.h"


QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    system("config-pin P9.11 uart");
    system("config-pin P9.13 uart");

    Program program;


    return a.exec();
//    return 0;
}


