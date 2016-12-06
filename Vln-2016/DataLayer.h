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
using namespace std;


class DataLayer
{
    vector<Scientist> _scientists;
    vector<Computer> _computer;
    QSqlDatabase m_db;
public:
    DataLayer();
    ~DataLayer();
    vector<Scientist> readAllFromDataBase();
    void searchForNameFromDatabase(string name);
    int getSizeOfScientists();
    char getGenderAt(int i);



};

#endif // SCIENTISLISTFROMSQL_H
