#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "DataLayer.h"
#include <vector>
#include <QByteArray>

class listServices
{
    DataLayer _myData;
public:
    listServices();


    //Functions for searching and displaying search
    vector<Scientist> searchForName(string name);
    vector<Scientist> checkName(string s);
    vector<searching> displaySearchJoinScientistName(string x);
    vector<searching> displaySearchJoinComputerName(string x);
    vector<searching> displaySearchJoinConnectionName(string x);
    vector<searching> displayAllFromSearching();
    vector<Computer> searchForNameComputer(string s);
    vector<Computer> searchForTypeComputer(string s);

    //Function for displaying Scientist
    vector<Scientist> displayScientist();
    vector<Scientist> displayScientistById(int x);

    //Function for displaying Computers
    vector<Computer> displayComputer();
    vector<Computer> displayComputerById(int x);

    //Function for displaying connections
    vector<connection> displayConnection();

    //Function to get the current size of these vectors
    int getSizeOfScientist();
    int getSizeOfComputer();

    //functions for adding a Scientist
    void addScientistToDatabase(Scientist newScientist);

    //Function for addign a computer
    void addComputerToDatabase(Computer newComputer);

    //Functoin for adding a connection
    void addConnectionToDatabase(connection newConnection);

    //Functions for deleting Scientists
    bool deleteScientistFromDatabase(int x);

    //Functions for deleting Computer
    bool deleteComputerFromDatabase(int x);

    //Functions for deleting Connection
    bool deleteConnectionFromDatabase(int x, int y);

    //Functions for alphabetical order of Scientists
    vector<Scientist> scientistInAlphabeticalOrder();
    vector<Scientist> scientistInReverseAlphabeticalOrder();

    //Function for alphabetical order of computers
    vector<Computer> computerInAlphabeticalOrder();
    vector<Computer> computerInReverseAlphabeticalOrder();
    vector<Computer> computerIdAscendingOrder();
    vector<Computer> computerIdDescendingOrder();
    vector<Computer> computertypeAscendingOrder();
    vector<Computer> computertypeDescendingOrder();

    //Function for alphabetical order of connections
    vector<connection> connectionInAlphabeticalOrder();
    vector<connection> connectionInReverseAlphabeticalOrder();

    //Functions for searsching longest names
    int searchLongestNameScientist();
    int searchLongestNameComputer();
    int searchLongestNameConnection();

    //Functions to search for oldest and youngest
    vector<Scientist> oldestOrderScientist();
    vector<Computer> oldestOrderComputer();
    vector<Scientist> youngestOrderScientist();
    vector<Computer> youngestOrderComputer();

    //Functions to see if Scientist/Computer/Connection is already in database
    bool checkIfScientistIsInDataBase (string x);
    bool checkIfComputerIsInDataBase (string x);
    bool checkIfConnectionIsInDataBase (string x);

    //Functions to see if Scientist is alive/dead
    vector<Scientist> searchAliveScientist();
    vector<Scientist> searchDeadScientist();

    //Function to search if and when a computer was built
    vector<Computer> searchWhenBuiltRange(int a, int b);
    vector<Computer> searchWhenBuiltSingleYear(int a);
    vector<Computer> myComputerWasNotBuilt();
    vector<Computer> myComputerWasBuilt();

    //Function to check for Turing Awars
    vector<Scientist> checkForAward(int x);

    //Function to check for birth year
    vector<Scientist> checkBirthYear(int x);
    vector<Scientist> checkRangeBirthYear(int x, int y);

    //Function ??
    vector<Scientist> checkDeathYear(int x);
    vector<Scientist> checkNationality(string s);
    vector<Scientist> checkFullName(string s);

    //Functions to edit a scientist
    bool updateFirstNameScientist(string x, int id);
    bool updateLastNameScientist(string x, int id);
    bool updateGenderScientist(char x, int id);
    bool updateNationalityScientist(string x, int id);
    bool updateYOBScientist(int x, int id);
    bool updateYODScientist(int x, int id);
    bool updateYOAScientist(int x, int id);

    //Functions to edit a computer
    bool updateNameComputer(string x, int id);
    bool updateTypeComputer(string x, int id);
    bool updateYOCComputer(int x, int id);
    bool updateWasBuilt(int x, int id);

    //Functions for Ascending/Descending order by ID
    vector<Scientist> readInAscendingByID();
    vector<Scientist> readInDiscendingByID();

    //Functions for Ascending/Descending order by FirstName
    vector<searching> readInAscendingByFirstName();
    vector<searching> readInDiscendingFirstName();

    //Functions for Ascending/Descending order by LastName
    vector<searching> readInAscendingByLastName();
    vector<searching> readInDiscendingLastName();


    //Functions for Ascending/Descending order by CompName
    vector<searching> readInAscendingByCompName();
    vector<searching> readInDiscendingCompName();

    //Functions for Ascending/Descending order by CompType
    vector<searching> readInAscendingByCompType();
    vector<searching> readInDiscendingByCompType();

    //Functions for Ascending/Descending order by YearBuilt
    vector<searching> readInAscendingByYearBuilt();
    vector<searching> readInDiscendingByYearBuilt();

    //Functions for Ascending/Descending alphabetical order by nationality
    vector<Scientist> readInAlphabeticalOrderNationality();
    vector<Scientist> readInReverseAlphabeticalOrderNationality();

    //Functions for Ascending/Descending alphabetical order by Gender
    vector<Scientist> readInAlphabeticalOrderGender();
    vector<Scientist> readInReverseAlphabeticalOrderGender();

    //Functions for Ascending/Descending order by year of award
    vector<Scientist> readInAscendingByYOA();
    vector<Scientist> readInDescendingByYOA();

    //Search for scientist by ID to display picture and bio

    QByteArray searchScientistPicture(int id);

    //Functions for login
    vector<userandpass> checkForUsers();
    void regiserUsers(userandpass newUser);


};

#endif // LISTSERVICES_H
