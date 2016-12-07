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
    bool deleteFunction(string x);
    bool addFunction(string name1, string name2, char gender, string nation, int yob, int yod, int yoa);
    vector<Scientist> readInAlphabeticalOrder();

};

#endif // SCIENTISLISTFROMSQL_H
