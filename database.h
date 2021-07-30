#ifndef DATABASE_H
#define DATABASE_H

/*
 * Connection à la base de donnée
 */
#include<QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QSqlError>

class dataBase:public QWidget
{
public:
    dataBase();
    void connClose();
    bool connOpen();
};

#endif // DATABASE_H
