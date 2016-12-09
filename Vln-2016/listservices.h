#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "scientistList.h"
#include "DataLayer.h"
#include <vector>

class listServices
{
    vector<scientistList> _computerScientists;
    DataLayer _myData;
    scientistList _data;
public:
    listServices();
    string getFirstNameFromList(int i);
    string getLastNameFromList(int i);
    string getNationalityFromList(int i);
    string fullNameFromList(int i) const; // Returns full name from scientistList
    int dobFromList(int i) const; // Returns date of birth from scientistList
    int dodFromList(int i) const; // Returns date of death from scientistList
    int getSizeOfScientistList();
    char getGenderFromListAt(int i);
    int getAwardsFromList(int i) const;

    //FREEESH
    vector<Scientist> searchForName(string name);
    vector<Scientist> displayScientist();
    vector<Computer> displayComputer();
    int getSizeOfScientist();
    int getSizeOfComputer();
    void addScientistToDatabase(Scientist newScientist);
    void addComputerToDatabase(Computer newComputer);
    void addConnectionToDatabase(connection newConnection);
    void deleteScientistFromDatabase(int x);
    void deleteComputerFromDatabase(int x);
    vector<Scientist> scientistInAlphabeticalOrder();
    vector<Scientist> scientistInReverseAlphabeticalOrder();
    vector<Computer> computerInAlphabeticalOrder();
    vector<Computer> computerInReverseAlphabeticalOrder();
    int searchLongestNameScientist();
    int searchLongestNameComputer();
    vector<Scientist> oldestOrderScientist();
    vector<Computer> oldestOrderComputer();
    vector<Scientist> youngestOrderScientist();
    vector<Computer> youngestOrderComputer();
    bool checkIfScientistIsInDataBase (string x);
    bool checkIfComputerIsInDataBase (string x);
    vector<Scientist> searchAliveScientist();
    vector<Scientist> searchDeadScientist();
    vector<Computer> searchWhenBuiltRange(int a, int b);
    vector<Computer> searchWhenBuiltSingleYear(int a);
    vector<Computer> myComputerWasNotBuilt();
    vector<Computer> myComputerWasBuilt();
    vector<Scientist> checkForAward(int x);
    vector<Scientist> checkBirthYear(int x);
    vector<Scientist> checkRangeBirthYear(int x, int y);
    vector<searching> displaySearchJoinScientistName(string x);
    vector<searching> displaySearchJoinComputerName(string x);
    vector<Scientist> checkName(string s);
    vector<Computer> searchForNameComputer(string s);
    bool updateFirstNameScientist(string x, int id);
    bool updateLastNameScientist(string x, int id);
    bool updateGenderScientist(char x, int id);
    bool updateNationalityScientist(string x, int id);
    bool updateYOBScientist(int x, int id);
    bool updateYODScientist(int x, int id);
    bool updateYOAScientist(int x, int id);
    bool updateNameComputer(string x, int id);
    bool updateTypeComputer(string x, int id);
    bool updateYOCComputer(int x, int id);
    vector<Computer> searchForTypeComputer(string s);

};

#endif // LISTSERVICES_H
