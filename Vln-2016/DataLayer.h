#ifndef SCIENTISLISTFROMSQL_H
#define SCIENTISLISTFROMSQL_H
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <vector>
#include <scientist.h>
#include <computer.h>


class DataLayer
{

    //vector<Scientist> _dataFromDatabase;
    //vector<Computer> _computerDataFromDatabase;
    QSqlDatabase m_db;
public:
    DataLayer();
    ~DataLayer();
    void readAllFromDataBase() const;

};

#endif // SCIENTISLISTFROMSQL_H
