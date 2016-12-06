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
#include<searching.h>
using namespace std;


class DataLayer
{
    vector<Scientist> _dataFromDatabase;
    vector<Computer> _computerDataFromDatabase;
    vector<searching> _joinSearchFromDatabase;
    QSqlDatabase m_db;
public:
    DataLayer();
    ~DataLayer();
    vector<Scientist> readAllFromScientistDataBase();
    vector<Computer> readAllFromDataComputerBase();
    vector<searching> readAllDataFromSearchingDatabse();

};

#endif // SCIENTISLISTFROMSQL_H
