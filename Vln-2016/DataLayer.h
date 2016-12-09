#ifndef SCIENTISLISTFROMSQL_H
#define SCIENTISLISTFROMSQL_H
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <vector>
#include <scientist.h>
#include <connection.h>
#include <computer.h>
#include<searching.h>

using namespace std;


class DataLayer
{
    vector<searching> _searching;
    vector<Scientist> _scientists;
    vector<Computer> _computer;
    vector<connection> _connection;
    QSqlDatabase m_db;
public:
    DataLayer();
    ~DataLayer();
    vector<Computer> readAllFromDataComputerBase();
    vector<searching> searchForScientistFromSearchingDatabse(string x);
    vector<searching> searchForComputerFromSearchingDatabase(string x);
    vector<Scientist> readAllFromScientistsDataBase();

    vector<Scientist> searchForNameFromDatabase(string name);
    int getSizeOfScientists();
    char getGenderAt(int i);
    int getBirthYearAt(int i);
    int getDeathYearAt(int i);
    int getAwardYearAt(int i);
    bool deleteFunction(int x);
    bool addFunction(Scientist newScientist);
    vector<Scientist> readInAlphabeticalOrder();
    vector<Scientist> readInReverseAlphabeticalOrder();
    vector<Scientist> readInOldestOrder();
    vector<Scientist> readInYoungestOrder();
    vector<Scientist> searchForTuringAwardWinners(int x);
    vector<Scientist> searchForYearOfBirth(int x);
    vector<Scientist> searchRangeForYearOfBirth(int x, int y);

    vector<Computer> readInAlphabeticalOrderComputer();
    vector<Computer> readInReverseAlphabeticalOrderComputer();
    vector<Computer> readInOldestOrderComputer();
    vector<Computer> readInYoungestOrderComputer();
    bool addFunctionComputer(Computer newComputer);
    bool addFunctionConnect(connection newConnection);
    bool deleteFunctionComputer(int x);
    bool deleteConnectionFunctionScientist(int x);
    bool deleteConnectionFunctionComputer(int x);
    vector<Computer> checkInComputer(string x);


    bool checkIfExists(string x);
    bool checkIfComputerExists(string x);

    vector<Computer> checkInComputerYear(int x, int y);
    vector<Computer> checkInComputerSingleYear(int x);
    vector<Computer> checkInComputerType(string x);
    vector<Computer> ComputerWasBuilt();
    vector<Computer> ComputerWasNotBuilt();

    bool updateFirstName(string x, int y);
    bool updateLastName(string x, int y);
    bool updateGender(char g, int y);
    bool updateNationality(string x, int y);
    bool updateYOB (int x, int y);
    bool updateYOD (int x, int y);
    bool updateYOA (int x, int y);

};

#endif // SCIENTISLISTFROMSQL_H
