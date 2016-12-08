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

vector<Scientist> listServices::scientistInAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrder();
    return returnScientist;
}

vector<Computer> listServices::computerInAlphabeticalOrder()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.readInAlphabeticalOrderComputer();
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

//This function adds a new scientist to the list.  It creates a new instance of scientistList by calling a constructor that adds a new entry to the .txt file.
vector<Scientist> listServices::addNewScientist(string firstName, string lastName, char gender, string nationality, int birthYear, int deathYear, int awardYear)
{
    Scientist newScientist(firstName, lastName, gender, nationality, birthYear, deathYear, awardYear);
    vector<Scientist> addScientist;
    addScientist.push_back(newScientist);
    return addScientist;
}

bool listServices::deleteScientist(string x)
{
    bool check;
    if (_myData.deleteFunction(x))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool listServices::deleteComputer(string x)
{
    bool check;
    if (_myData.deleteFunctionComputer(x))
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
        if(displayScientist()[k].getDeathYear() == 0)
        {
            matchingScientists.push_back(displayScientist()[k]);
        }
    }
    return matchingScientists;
}


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
// This function returns a _computerScientists in alphabetical order. It uses ScientistComparison which is a struct. We didn't know any good
// way to do this so we got the idea from the King him self, Daniel Brandur, that used sort function. Thanks Daniel!
vector<scientistList> listServices::sortByName()
{
    vector<scientistList> sortedByName;
    sortedByName = _computerScientists;
    ScientistComparison cmp;
    std::sort(sortedByName.begin(), sortedByName.end(), cmp);

    return sortedByName;
}
//This function sorts the scientists by their birth year in ascending order.
//In every iteration it finds the lowest birth year, barring the one it found in the last loop and puts it in the index corresponding to the loop number.
vector<scientistList> listServices::sortByBirth()
{
    int currentSmallest;
    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        currentSmallest = _computerScientists[i].dob();  //in the first iteration, the smallest number is the first number
        for(unsigned int j = i; j < _computerScientists.size(); j++)
        {
           if(_computerScientists[j].dob() < currentSmallest)
           {
               currentSmallest = _computerScientists[j].dob();
               scientistList temp;
               temp = _computerScientists[j];
               _computerScientists[j] = _computerScientists[i];
               _computerScientists[i] = temp;
           }
        }
    }
    return _computerScientists;
}
// This function sorts the vector of scientists by what year they received the Turing award in ascending order.
//It puts the recipients of the award first, followed by those who did not receive it.
vector<scientistList>   listServices::sortByAward()
{
    vector<scientistList> sortedList;
    int currentSmallest;
    //This outer for loop runs through the entire vector, and at each index it puts the smallest number out of itself and the ones that come after it
    //at the index i.
    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        //In the first run the smallest is the number already there
        currentSmallest = _computerScientists[i].getAwards();
        //then it checks every single index after it, and if it is smaller than the number already at i, they switch.
        for(unsigned int j = i; j < _computerScientists.size(); j++)
        {
          //In the if sentence below, a 0 in getAwards indicates that the scientist has never received the award.
          //This if statement switches the current index being checked with the index we are attempting to put the next lowest year in
          //if and only if the scientist won the award before the scientist who is currently stored at that index.
           if(_computerScientists[j].getAwards() < currentSmallest && _computerScientists[j].getAwards() != 0)
           {
               scientistList temp;
               temp = _computerScientists[j];
               _computerScientists[j] = _computerScientists[i];
               _computerScientists[i] = temp;
           }
           //if the number at index i is 0, it will switch with whatever number is at j.
           //this is to ensure that those who have not received the award appear at the end of the list.
           if(_computerScientists[i].getAwards() == 0 && _computerScientists[j].getAwards() != 0)
           {
               scientistList temp;
               temp = _computerScientists[j];
               _computerScientists[j] = _computerScientists[i];
               _computerScientists[i] = temp;
           }
        }
    }
    sortedList = _computerScientists;
    return sortedList;
}
//This function adds a new scientist to the list.  It creates a new instance of scientistList by calling a constructor that adds a new entry to the .txt file.
void   listServices::addNew(string firstName, string lastName, char gender, string nationality, int birthYear, int deathYear, int awardYear)
{
    scientistList newScientist(firstName, lastName, gender, nationality, birthYear, deathYear, awardYear);
    _computerScientists.push_back(newScientist);
}
//This function creates and returns a new vector containing only the scientists whose names match the name being searched.
//The name being searched is the string that is taken in as an argument.
vector<scientistList> listServices::searchName(string searchTerm)
{
    vector<scientistList> matchingscientists;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        //If the names match, the scientist is added to the new vector.
        if (changeToLower(searchTerm) == changeToLower(_computerScientists[i].getLastName()) || changeToLower(searchTerm) == changeToLower(_computerScientists[i].getFirstName()))
        {
            matchingscientists.push_back(_computerScientists[i]);
        }
    }
    return matchingscientists;
}

//This function creates and returns a new vector containing only the scientists whose birth years match the year being searched.
//The year being searched is the integer that is taken in as an argument.
vector<scientistList> listServices::searchBirth(int minYear, int maxYear)
{
    vector<scientistList> matchingBirthYears;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
      if (minYear <= _computerScientists[i].dob() && _computerScientists[i].dob() <= maxYear)
      {
          matchingBirthYears.push_back(_computerScientists[i]);
      }
    }
    return matchingBirthYears;
}
//This function creates and returns a new vector containing only living scientists.
vector<scientistList> listServices::searchAlive()
{
    vector<scientistList> matchingScientists;
    //this loop goes through all scientists and adds them to the matchingScientists vector if and only if their year of death is listed as 0
    // which means that they are still living.
    for(unsigned int k = 0; k < _computerScientists.size(); k++)
    {
        if(_computerScientists[k].dod() == 00)
        {
            matchingScientists.push_back(_computerScientists[k]);
        }
    }
    return matchingScientists;
}

//This function creates and returns a new vector containing only the scientists who received the Turing award in the year that is being searched.
//The year being searched is the integer that is taken in as an argument.
vector<scientistList> listServices::searchAward(int awardYear)
{
    vector<scientistList> matchingAwardYear;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if (awardYear == _computerScientists[i].getAwards())
        {
            matchingAwardYear.push_back(_computerScientists[i]);
        }
    }
    return matchingAwardYear;
}
// This function is used to assign a vector rhs to another vector
void listServices::changeTo(vector<scientistList> rhs)
{
    _computerScientists  = rhs;
}

// This function returns the size of the vector in the listServices instance.
int listServices::getSize ()
{
    return _computerScientists.size();
}
// binni kallinn með smá snúning
int listServices::searchLongestName()
{
    unsigned int longest = 7;
    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if(longest < getFirstNameFromList(i).size())
        {
            longest = getFirstNameFromList(i).size();
        }
    }
    unsigned int newLongest = longest;
    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if(newLongest < getLastNameFromList(i).size())
        {
            newLongest = getLastNameFromList(i).size();
        }
    }
    return newLongest + 2;
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
// This function changes upper case letters to lower case letters. It takes in string and uses the tolower function. It
// checks every letter and if it is upper case letter than it changes it to lower case letter
string listServices::changeToLower(string input)
{
    for(unsigned int i = 0 ; i < input.length() ; i++)
    {
        input[i] = tolower(input[i]);
    }
    return input;
}
// This function takes ID input from the user in consoleui and deletes the scientist from the vector
void listServices::deleteFromList(int ID)
{
    _computerScientists.erase(_computerScientists.begin() + ID);
}
// This function forwards the vector into scientistlist writeToFile function
void listServices::writeNewFile()
{
    _data.writeToFile(_computerScientists);
}
