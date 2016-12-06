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
    vector<searching> _searching;
    vector<Scientist> _scientists;
    vector<Computer> _computer;
    QSqlDatabase m_db;
public:
    DataLayer();
    ~DataLayer();
    vector<Computer> readAllFromDataComputerBase();
    vector<searching> readAllDataFromSearchingDatabse();
    vector<Scientist> readAllFromScientistsDataBase();
    void searchForNameFromDatabase(string name);


};

#endif // SCIENTISLISTFROMSQL_H
