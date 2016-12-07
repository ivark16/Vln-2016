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
    int getSizeOfScientists();
    char getGenderAt(int i);
    bool deleteFunction(string x);
    bool addFunction(string name1, string name2, char gender1, string nation, int yob, int yod, int yoa);
    vector<Scientist> readInAlphabeticalOrder();
    vector<Scientist> readInOldestOrder();
    vector<Scientist> readInYoungestOrder();
    vector<Computer> readInAlphabeticalOrderComputer();
    vector<Computer> readInOldestOrderComputer();
    vector<Computer> readInYoungestOrderComputer();
    bool addFunctionComputer(string name1, string type1, int yob, bool wasbuilt1);
    bool deleteFunctionComputer(string x);
    vector<Computer> checkInComputer(string x);
};

#endif // SCIENTISLISTFROMSQL_H
