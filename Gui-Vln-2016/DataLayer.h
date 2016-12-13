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

    //Join functions
    vector<searching> searchForScientistFromSearchingDatabse(string x);
    vector<searching> searchForComputerFromSearchingDatabase(string x);
    vector<searching> searchForConnectionFromSearchingDatabase(string x);

    int getSizeOfScientists();
    int getSizeOfComputer();
    int getSizeOfConnection();
    int getscientistIdrAt(int i);
    int getcomputersIdAt(int i);
    char getGenderAt(int i);
    int getBirthYearAt(int i);
    int getDeathYearAt(int i);
    int getAwardYearAt(int i);

    //Delete functions
    bool deleteFunction(int x);
    bool deleteFunctionComputer(int x);
    bool deleteConnectionFunctionScientist(int x);
    bool deleteConnectionFunctionComputer(int x);

    //Display functions for scientist
    vector<Scientist> readInAlphabeticalOrder();
    vector<Scientist> readInReverseAlphabeticalOrder();
    vector<Scientist> readInOldestOrder();
    vector<Scientist> readInYoungestOrder();
    vector<Scientist> readAllFromScientistsDataBase();

    //Search functions for scientists
    vector<Scientist> searchForTuringAwardWinners(int x);
    vector<Scientist> searchForYearOfBirth(int x);
    vector<Scientist> searchRangeForYearOfBirth(int x, int y);
    vector<Scientist> searchForNameFromDatabase(string name);
    vector<Scientist> searchFullNameFromDatabase(string name);

    //Display functions for computer
    vector<Computer> readInAlphabeticalOrderComputer();
    vector<Computer> readInReverseAlphabeticalOrderComputer();
    vector<Computer> readInOldestOrderComputer();
    vector<Computer> readInYoungestOrderComputer();
    vector<Computer> readAllFromDataComputerBase();

    //Add functions for computer, connect and scientist
    bool addFunctionComputer(Computer newComputer);
    bool addFunctionConnect(connection newConnection);
    bool addFunction(Scientist newScientist);

    //Check functions for computer
    vector<Computer> checkInComputer(string x);
    vector<Computer> checkInComputerYear(int x, int y);
    vector<Computer> checkInComputerSingleYear(int x);
    vector<Computer> checkInComputerType(string x);
    vector<Computer> ComputerWasBuilt();
    vector<Computer> ComputerWasNotBuilt();

    //Display functions for connection
    //vector<Computer> readInAlphabeticalOrderConnection();
    //vector<Computer> readInReverseAlphabeticalOrderConnection();
    vector<connection> readAllFromDataConnectionBase();

    //Functions for updating scientist database
    bool updateFirstName(string x, int y);
    bool updateLastName(string x, int y);
    bool updateGender(char g, int y);
    bool updateNationality(string x, int y);
    bool updateYOB (int x, int y);
    bool updateYOD (int x, int y);
    bool updateYOA (int x, int y);

    //Functions for updating computer database
    bool updateNameComputer(string x, int y);
    bool updateTypeComputer(string x, int y);
    bool updateYOCComputer (int x, int y);
    bool updateWasComputerBuilt (int x, int y);
};

#endif // SCIENTISLISTFROMSQL_H
