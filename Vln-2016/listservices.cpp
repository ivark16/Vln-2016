#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


void listServices::searchForName(string name)
{
    _myData.searchForNameFromDatabase(name);
}

int listServices::getSizeOfScientistList()
{
   return _myData.getSizeOfScientists();
}

vector<Scientist> listServices::displayScientist()
{
    vector<Scientist> display;
    display = _myData.readAllFromScientistsDataBase();
    return display;
}

vector<Computer> listServices::displayComputer()
{
    vector<Computer> display;
    display = _myData.readAllFromDataComputerBase();
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

bool listServices::checkIfScientistIsInDataBase (string x)
{
    bool bla;
    if (_myData.checkIfExists(x))
    {
        bla = true;
    }
    else
    {
        bla = false;
    }
    return bla;
}

bool listServices::checkIfComputerIsInDataBase (string x)
{
    bool bla;
    if (_myData.checkIfComputerExists(x))
    {
        bla = true;
    }
    else
    {
        bla = false;
    }
    return bla;
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

// Binni med Chuck Norris grin
/*vector<Scientist> listServices::chuckNorrisData()
{
    vector<scientistList> matchingFirstNames;
    string firstName = "Chuck";
    string lastName = "Norris";
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        _computerScientists[i].setFirstName(firstName);
        _computerScientists[i].setLastName(lastName);

        matchingFirstNames.push_back(_computerScientists[i]);

    }
    return matchingFirstNames;
}*/



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


// This struct is used to print code in alphabetical order.
struct ScientistComparison
{
    bool operator ()(scientistList i, scientistList j) {return (i.fullName() < j.fullName());}
};
//This function is used to return the (first) name of the Scientists at intex i
string listServices::getFirstNameFromList(int i)
{
    return _computerScientists[i].getFirstName();
}
//This function is used to return the (last) name of the Scientists at intex i
string listServices::getLastNameFromList(int i)
{
    return _computerScientists[i].getLastName();
}
//Returns nationality of scientist at index i
string listServices::getNationalityFromList(int i)
{
    return _computerScientists[i].getNationality();
}
//Will return the (full) name of the Scientists at intex i
string listServices::fullNameFromList(int i) const
{
    return _computerScientists[i].fullName();
}
//Returns the Scientists date of birth at intex i
int listServices::dobFromList(int i) const
{
    return _computerScientists[i].dob();
}
//Returns the Scientists date of death at intex i
int listServices::dodFromList(int i) const
{
    return _computerScientists[i].dod();
}
//This function is returning the Scientists gender at intex i
char listServices::getGenderFromListAt(int i)
{
    return _myData.getGenderAt(i);
}
//This function returns the Awards from the list at intex i
int listServices::getAwardsFromList(int i) const
{
    return _computerScientists[i].getAwards();
}
//A constructor for listServices.  readFile reads data from a .txt file and puts it in the member vector _computerScientists.
listServices::listServices()
{

}
// This function is used to assign a vector rhs to another vector
void listServices::changeTo(vector<scientistList> rhs)
{
    _computerScientists  = rhs;
}

// Binni med Chuck Norris grin
vector<scientistList> listServices::chuckNorris()
{
    vector<scientistList> matchingFirstNames;
    string firstName = "Chuck";
    string lastName = "Norris";
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        _computerScientists[i].setFirstName(firstName);
        _computerScientists[i].setLastName(lastName);

        matchingFirstNames.push_back(_computerScientists[i]);

    }
    return matchingFirstNames;
}

