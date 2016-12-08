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
    int getBirthYearAt(int i);
    int getDeathYearAt(int i);
    int getAwardYearAt(int i);
    bool deleteFunction(string x);
    bool addFunction(Scientist newScientist);
    vector<Scientist> readInAlphabeticalOrder();
    vector<Scientist> readInReverseAlphabeticalOrder();
    vector<Scientist> readInOldestOrder();
    vector<Scientist> readInYoungestOrder();
    vector<Computer> readInAlphabeticalOrderComputer();
    vector<Computer> readInReverseAlphabeticalOrderComputer();
    vector<Computer> readInOldestOrderComputer();
    vector<Computer> readInYoungestOrderComputer();
    bool addFunctionComputer(Computer newComputer);
    bool deleteFunctionComputer(string x);
    vector<Computer> checkInComputer(string x);

    bool checkIfExists(string x);
    bool checkIfComputerExists(string x);
};

#endif // SCIENTISLISTFROMSQL_H
