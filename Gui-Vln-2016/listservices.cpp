#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


// searches for the name "name", which is user input
vector<Scientist> listServices::searchForName(string name)
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.searchForNameFromDatabase(name);
    return returnScientist;
}

int listServices::getSizeOfScientist()
{
   return _myData.getSizeOfScientists();
}

int listServices::getSizeOfComputer()
{
    return _myData.getSizeOfComputer();
}

//the functions below are referenced in the ui.  These are primarily links between the ui and the data layer

vector<Scientist> listServices::displayScientist()
{
    vector<Scientist> display;
    display = _myData.readAllFromScientistsDataBase();
    return display;
}

vector<Scientist> listServices::displayScientistById(int x)
{
    vector<Scientist> displayByIdScientist;
    displayByIdScientist = _myData.readAllFromScientistDataBaseById(x);
    return displayByIdScientist;
}

vector<Computer> listServices::displayComputer()
{
    vector<Computer> display;
    display = _myData.readAllFromDataComputerBase();
    return display;
}

vector<Computer> listServices::displayComputerById(int x)
{
    vector<Computer> displayById;
    displayById = _myData.readAllFromDataComputerBaseById(x);
    return displayById;
}

vector<connection> listServices::displayConnection()
{
    vector<connection> display;
    display = _myData.readAllFromDataConnectionBase();
    return display;
}

void listServices::addScientistToDatabase(Scientist newScientist)
{
    _myData.addFunction(newScientist);
}

void listServices::addComputerToDatabase(Computer newComputer)
{
    _myData.addFunctionComputer(newComputer);
}

void listServices::addConnectionToDatabase(connection newConnection)
{
    _myData.addFunctionConnect(newConnection);
}

vector<Scientist> listServices::readInAscendingByID()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAscendingByID();
    return returnScientist;
}

vector<Scientist> listServices::readInDiscendingByID()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInDiscendingByID();
    return returnScientist;
}

vector<Scientist> listServices::readInAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrderNationality();
    return returnScientist;
}

vector<Scientist> listServices::readInReverseAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrderNationality();
    return returnScientist;
}

vector<Scientist> listServices::readInAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrderGender();
    return returnScientist;
}

vector<Scientist> listServices::readInReverseAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrderGender();
    return returnScientist;
}

vector<Scientist> listServices::readInAscendingByYOA()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAscendingByYOA();
    return returnScientist;
}

vector<Scientist> listServices::readInDescendingByYOA()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInDescendingByYOA();
    return returnScientist;
}

vector<Scientist> listServices::scientistInAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrder();
    return returnScientist;
}

vector<Scientist> listServices::scientistInReverseAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrder();
    return returnScientist;
}

vector<Computer> listServices::computerInAlphabeticalOrder()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.readInAlphabeticalOrderComputer();
    return returnComputer;
}

vector<Computer> listServices::computerInReverseAlphabeticalOrder()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.readInReverseAlphabeticalOrderComputer();
    return returnComputer;
}

vector<Scientist> listServices::oldestOrderScientist()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInOldestOrder();
    return returnScientist;
}

vector<Computer> listServices::oldestOrderComputer()
{
    vector<Computer> display;
    display = _myData.readInOldestOrderComputer();
    return display;
}

vector<Scientist> listServices::youngestOrderScientist()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInYoungestOrder();
    return returnScientist;
}

vector<Computer> listServices::youngestOrderComputer()
{
    vector<Computer> display;
    display = _myData.readInYoungestOrderComputer();
    return display;
}

vector<searching> listServices::displaySearchJoinScientistName(string x)
{
    vector<searching> displayJoinScientist;
    displayJoinScientist = _myData.searchForScientistFromSearchingDatabse(x);
    return displayJoinScientist;
}

vector<searching> listServices::displaySearchJoinComputerName(string x)
{
    vector<searching> displayJoinComputer;
    displayJoinComputer = _myData.searchForComputerFromSearchingDatabase(x);
    return displayJoinComputer;
}

bool listServices::deleteScientistFromDatabase(int x)
{
    bool check;
    if (_myData.deleteFunction(x) == true && _myData.deleteConnectionFunctionScientist(x) == true)
    {
        check = true;
    }
    else
    {
        check == false;
    }
    return check;
}

bool listServices::deleteComputerFromDatabase(int x)
{
    bool check;
    if(_myData.deleteFunctionComputer(x) == true && _myData.deleteConnectionFunctionComputer(x) == true)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::deleteConnectionFromDatabase(int x, int y)
{
    bool check;
    if(_myData.deleteConnectionFunctionComputer(x) == true && _myData.deleteConnectionFunctionScientist(y) == true)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function creates and returns a new vector containing only living scientists.
vector<Scientist> listServices::searchAliveScientist()
{
    vector<Scientist> matchingScientists;
    //this loop goes through all scientists and adds them to the matchingScientists vector if and only if their year of death is listed as 0
    // which means that they are still living.
    for(unsigned int k = 0; k < displayScientist().size(); k++)
    {
        if(displayScientist()[k].getDeathYear() == 00)
        {
            matchingScientists.push_back(displayScientist()[k]);
        }
    }
    return matchingScientists;
}

//This function creates and returns a new vector containing only living scientists.
vector<Scientist> listServices::searchDeadScientist()
{
    vector<Scientist> matchingScientists;
    //this loop goes through all scientists and adds them to the matchingScientists vector if and only if their year of death is listed as 0
    // which means that they are still living.
    for(unsigned int k = 0; k < displayScientist().size(); k++)
    {
        if(!(displayScientist()[k].getDeathYear() == 00))
        {
            matchingScientists.push_back(displayScientist()[k]);
        }
    }
    return matchingScientists;
}

vector<Computer> listServices::searchForNameComputer(string s)
{
    vector<Computer> returnComputers;
    returnComputers = _myData.checkInComputer(s);
    return returnComputers;
}

vector<Computer> listServices::searchForTypeComputer(string s)
{
    vector<Computer> returnComputers;
    returnComputers = _myData.checkInComputerType(s);
    return returnComputers;
}

vector<Computer> listServices::searchWhenBuiltRange(int a, int b)
{
    vector<Computer> returnRange;
    returnRange = _myData.checkInComputerYear(a, b);
    return returnRange;
}

vector<Computer> listServices::searchWhenBuiltSingleYear(int a)
{
    vector<Computer> returnRange;
    returnRange = _myData.checkInComputerSingleYear(a);
    return returnRange;
}

vector<Computer> listServices::myComputerWasBuilt()
{
    vector<Computer> returnRange;
    returnRange = _myData.ComputerWasBuilt();
    return returnRange;
}

vector<Computer> listServices::myComputerWasNotBuilt()
{
    vector<Computer> returnRange;
    returnRange = _myData.ComputerWasNotBuilt();
    return returnRange;
}


vector<Scientist> listServices::checkForAward(int x)
{
    vector<Scientist> award;
    award = _myData.searchForTuringAwardWinners(x);
    return award;
}

vector<Scientist> listServices::checkBirthYear(int x)
{
    vector<Scientist> award;
    award = _myData.searchForYearOfBirth(x);
    return award;
}

vector<Scientist> listServices::checkDeathYear(int x)
{
    vector<Scientist> award;
    award = _myData.searchForDeadPeople(x);
    return award;
}

vector<Scientist> listServices::checkName(string s)
{
    vector<Scientist> names;
    names = _myData.searchForNameFromDatabase(s);
    return names;
}

vector<Scientist> listServices::checkFullName(string s)
{
    vector<Scientist> names;
    names = _myData.searchFullNameFromDatabase(s);
    return names;
}

vector<Scientist> listServices::checkNationality(string s)
{
    vector<Scientist> names;
    names = _myData.searchNationality(s);
    return names;
}

vector<Scientist> listServices::checkRangeBirthYear(int x, int y)
{
    vector<Scientist> award1;
    award1 = _myData.searchRangeForYearOfBirth(x, y);
    return award1;
}

bool listServices::updateFirstNameScientist(string x, int id)
{
    bool check;
    if (_myData.updateFirstName(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateLastNameScientist(string x, int id)
{
    bool check;
    if (_myData.updateLastName(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateGenderScientist(char x, int id)
{
    bool check;
    if (_myData.updateGender(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateNationalityScientist(string x, int id)
{
    bool check;
    if (_myData.updateNationality(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateYOBScientist(int x, int id)
{
    bool check;
    if (_myData.updateYOB(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateYODScientist(int x, int id)
{
    bool check;
    if (_myData.updateYOD(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateYOAScientist(int x, int id)
{
    bool check;
    if (_myData.updateYOA(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateNameComputer(string x, int id)
{
    bool check;
    if (_myData.updateNameComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateTypeComputer(string x, int id)
{
    bool check;
    if (_myData.updateTypeComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateYOCComputer(int x, int id)
{
    bool check;
    if (_myData.updateYOCComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::updateWasBuilt(int x, int id)
{
    bool check;
    if (_myData.updateWasComputerBuilt(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//to get the longest name in order to align the table right
int listServices::searchLongestNameScientist()
{
    vector<Scientist> display;
    display = _myData.readAllFromScientistsDataBase();
    unsigned int longest = 7;
    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(longest < display[i].getFirstName().size())
        {
            longest = display[i].getFirstName().size();
        }
    }
    unsigned int newLongest = longest;
    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(newLongest < display[i].getLastName().size())
        {
            newLongest = display[i].getLastName().size();
        }
    }
    return newLongest + 2;
}

//to get the longest name in order to align the table right
int listServices::searchLongestNameComputer()
{
    vector<Computer> display;
    display = _myData.readAllFromDataComputerBase();
    unsigned int longest = 7;
    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(longest < display[i].getComputerName().size())
        {
            longest = display[i].getComputerName().size();
        }
    }
    return longest + 2;
}

//A constructor for listServices.
listServices::listServices()
{

}

vector<Computer> listServices::computerIdAscendingOrder()
{
    vector<Computer> returnIdAscComputer;
    returnIdAscComputer = _myData.readIdInAscendingOrder();
    return returnIdAscComputer;
}

vector<Computer> listServices::computerIdDescendingOrder()
{
    vector<Computer> returnIdDescComputer;
    returnIdDescComputer = _myData.readIdInDescindingOrder();
    return returnIdDescComputer;
}

vector<Computer> listServices::computertypeAscendingOrder()
{
    vector<Computer> returntypeAscComputer;
    returntypeAscComputer = _myData.readTypeInAlphabeticalOrder();
    return returntypeAscComputer;
}

vector<Computer> listServices::computertypeDescendingOrder()
{
    vector<Computer> returntypeDescComputer;
    returntypeDescComputer = _myData.readTypeInReverseAlphabeticalOrder();
    return returntypeDescComputer;
}

vector<searching> listServices::displayAllFromSearching()
{
    vector<searching> displayAllScientistComputer;
    displayAllScientistComputer = _myData.displayAllfromSearching();
    return displayAllScientistComputer;
}
