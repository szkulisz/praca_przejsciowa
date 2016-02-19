#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QSqlDatabase>
//class QSqlDatabase;
class QSerialPort;

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = 0);

private:

    QSqlDatabase dataBase;
    QSerialPort *serial;

signals:

public slots:
    void readData();


};

#endif // PROGRAM_H
