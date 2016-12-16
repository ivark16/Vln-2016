#ifndef SCIENTISLISTFROMSQL_H
#define SCIENTISLISTFROMSQL_H
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QByteArray>
#include <vector>
#include <scientist.h>
#include <connection.h>
#include <computer.h>
#include<searching.h>
#include "userandpass.h"

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

    //Join functions.
    vector<searching> searchForScientistFromSearchingDatabse(string x);
    vector<searching> searchForComputerFromSearchingDatabase(string x);
    vector<searching> searchForConnectionFromSearchingDatabase(string x);
    vector<searching> displayAllfromSearching();
    vector<searching> displayFirstNamefromSearchingAscendingOrder();
    vector<searching> displayFirstNamefromSearchingDescendingOrder();
    vector<searching> displayLastNamefromSearchingAscendingOrder();
    vector<searching> displayLastNamefromSearchingDescendingOrder();
    vector<searching> displayComputerNamefromSearchingAscendingOrder();
    vector<searching> displayComputerNamefromSearchingDescendingOrder();
    vector<searching> displayComputerTypefromSearchingAscendingOrder();
    vector<searching> displayComputerTypefromSearchingDescendingOrder();
    vector<searching> displayComputerYearfromSearchingAscendingOrder();
    vector<searching> displayComputerYearfromSearchingDescendingOrder();

    //Functions that return their current size.
    int getSizeOfScientists();
    int getSizeOfComputer();
    int getSizeOfConnection();
    int getscientistIdrAt(int i);
    int getcomputersIdAt(int i);
    int getBirthYearAt(int i);
    int getDeathYearAt(int i);
    int getAwardYearAt(int i);
    char getGenderAt(int i);

    //Delete functions.
    bool deleteFunction(int x);
    bool deleteFunctionComputer(int x);
    bool deleteConnectionFunctionScientist(int x);
    bool deleteConnectionFunctionComputer(int x);

    //Display functions for scientist.
    vector<Scientist> readInAlphabeticalOrder();
    vector<Scientist> readInReverseAlphabeticalOrder();
    vector<Scientist> readInOldestOrder();
    vector<Scientist> readInYoungestOrder();
    vector<Scientist> readAllFromScientistsDataBase();
    vector<Scientist> readAllFromScientistDataBaseById(int x);
    vector<Scientist> readInAscendingByID();
    vector<Scientist> readInDiscendingByID();
    vector<Scientist> readInAlphabeticalOrderNationality();
    vector<Scientist> readInReverseAlphabeticalOrderNationality();
    vector<Scientist> readInAlphabeticalOrderGender();
    vector<Scientist> readInReverseAlphabeticalOrderGender();
    vector<Scientist> readInAscendingByYOA();
    vector<Scientist> readInDescendingByYOA();

    //Search functions for scientists.
    vector<Scientist> searchForTuringAwardWinners(int x);
    vector<Scientist> searchForYearOfBirth(int x);
    vector<Scientist> searchForDeadPeople(int x);
    vector<Scientist> searchRangeForYearOfBirth(int x, int y);
    vector<Scientist> searchForNameFromDatabase(string name);
    vector<Scientist> searchFullNameFromDatabase(string name);
    vector<Scientist> searchNationality(string name);

    //Display functions for computer.
    vector<Computer> readInAlphabeticalOrderComputer();
    vector<Computer> readInReverseAlphabeticalOrderComputer();
    vector<Computer> readInOldestOrderComputer();
    vector<Computer> readInYoungestOrderComputer();
    vector<Computer> readAllFromDataComputerBase();
    vector<Computer> readAllFromDataComputerBaseById(int x);
    vector<Computer> readIdInAscendingOrder();
    vector<Computer> readIdInDescindingOrder();
    vector<Computer> readTypeInAlphabeticalOrder();
    vector<Computer> readTypeInReverseAlphabeticalOrder();
    vector<Computer> ComputerWasBuiltASC();
    vector<Computer> ComputerWasBuiltDESC();

    //Add functions for computer, connect and scientist.
    bool addFunctionComputer(Computer newComputer);
    bool addFunctionConnect(connection newConnection);
    bool addFunction(Scientist newScientist);

    //Check functions for computer.
    vector<Computer> checkInComputer(string x);
    vector<Computer> checkInComputerYear(int x, int y);
    vector<Computer> checkInComputerSingleYear(int x);
    vector<Computer> checkInComputerType(string x);
    vector<Computer> ComputerWasBuilt();
    vector<Computer> ComputerWasNotBuilt();

    //Display functions for connection.
    vector<connection> readAllFromDataConnectionBase();

    //Functions for updating scientist database
    bool updateFirstName(string x, int y);
    bool updateLastName(string x, int y);
    bool updateGender(char g, int y);
    bool updateNationality(string x, int y);
    bool updateYOB (int x, int y);
    bool updateYOD (int x, int y);
    bool updateYOA (int x, int y);

    //Functions for updating computer database.
    bool updateNameComputer(string x, int y);
    bool updateTypeComputer(string x, int y);
    bool updateYOCComputer (int x, int y);
    bool updateWasComputerBuilt (int x, int y);

    //Functions for searching for pictures of scientists (that are stored within the database).
    QByteArray searchForPictureForScientist(int id);

    //Functions for login.
    vector<userandpass> readLogin();
    bool registerUser(userandpass newUser);
};

#endif // SCIENTISLISTFROMSQL_H
