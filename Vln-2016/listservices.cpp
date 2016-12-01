#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


// This struct is used to print code in alphabetical order.
struct ScientistComparison {
    bool operator ()(scientistList i, scientistList j) {return (i.fullName() < j.fullName());}
};
//This function is used to return the (first) name of the Scientists at intex i
string listServices::getFirstNameFromList(int i)
{
    string name;
    return _computerScientists[i].getFirstName();
}
//This function is used to return the (last) name of the Scientists at intex i
string listServices::getLastNameFromList(int i)
{
    string name;
    return _computerScientists[i].getLastName();
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
char listServices::getSexFromList(int i) const
{
    return _computerScientists[i].getSex();
}
//This function returns the Awards from the list at intex i
int listServices::getAwardsFromList(int i) const
{
    return _computerScientists[i].getAwards();
}


//A constructor for listServices.  readFile reads data from a .txt file and puts it in the member vector _computerScientists.
listServices::listServices()
{
        scientistList nextScientist;
        nextScientist.readFile(_computerScientists);
}

// This function returns vector in alphabetical order. It uses ScientistComparison that is struct. We didn't know any good
// way to do this so we got the idea from the King him self, Daniel Brandur, that used sort function. Thanks Daniel!
vector<scientistList> listServices::sortByName()
{
    vector<scientistList> sortedByName;

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
           if(_computerScientists[i].dob() < currentSmallest)
           {
               scientistList temp;
               temp = _computerScientists[i];
               _computerScientists[i] = _computerScientists[j];
               _computerScientists[i] = temp;
           }
        }
    }

    return _computerScientists;
}
//This function sorts the vector of scientists by status.  It puts all living scientists first in the vector.
vector<scientistList>   listServices::sortByAlive()
{
  for(unsigned int i = 0; i < _computerScientists.size(); i++)
  {
      int currentYear;
      currentYear = _computerScientists[i].dod();
      for(unsigned int j = i ; j < _computerScientists.size(); j++)
      {
          // if the year of death is listed as 0, the scientist is still alive.  This loop puts the living scientists first in the vector.
          if(_computerScientists[j].dod() == 0)
          {
              scientistList temp = _computerScientists[i];
              _computerScientists[i] = _computerScientists[j];
              _computerScientists[j] = temp;
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

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        currentSmallest = _computerScientists[i].getAwards();
        for(unsigned int j = i; j < _computerScientists.size(); j++)
        { //In the if sentence below, a 0 in getAwards indicates that the scientist has never received the award.
          //This if statement switches the current index being checked with the index we are attempting to put the next lowest year in
          //if and only if the scientist won the award before the scientist who is currently stored at that index.
           if(_computerScientists[i].getAwards() < currentSmallest && _computerScientists[i].getAwards() != 0)
           {
               scientistList temp;
               temp = _computerScientists[i];
               _computerScientists[i] = _computerScientists[j];
               _computerScientists[i] = temp;
           }
        }
    }
    sortedList = _computerScientists;
    return sortedList;
}
//This function adds a new scientist to the list.  It creates a new instance of scientistList by calling a constructor that adds a new entry to the .txt file.
void   listServices::addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear)
{
    scientistList newScientist(firstName, lastName, gender, birthYear, deathYear, awardYear);
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
        if (searchTerm == _computerScientists[i].getLastName() || searchTerm == _computerScientists[i].getFirstName() )
        {
            matchingscientists.push_back(_computerScientists[i]);
        }
    }
    return matchingscientists;
}
/*
vector<scientistList> listServices::searchLastName(string lastName)
{
    vector<scientistList> matchingLastNames;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        //If the names match, the scientist is added to the new vector.
        if (lastName == _computerScientists[i].getLastName())
        {
            matchingLastNames.push_back(_computerScientists[i]);
        }
    }
    return matchingLastNames;
}

//This function creates and returns a new vector containing only the scientists whose first names match the name being searched.
//The name being searched is the string that is taken in as an argument.
vector<scientistList> listServices::searchFirstName(string firstName)
{
    vector<scientistList> matchingFirstNames;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if (firstName == changeToLower(_computerScientists[i].getFirstName()))
        {
            matchingFirstNames.push_back(_computerScientists[i]);
        }
    }
    return matchingFirstNames;
}
*/

//This function creates and returns a new vector containing only the scientists whose birth years match the year being searched.
//The year being searched is the integer that is taken in as an argument.
vector<scientistList> listServices::searchBirth(int birthYear)
{
    vector<scientistList> matchingBirthYears;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
      if (birthYear == _computerScientists[i].dob())
      {
          matchingBirthYears.push_back(_computerScientists[i]);
      }
    }

    return matchingBirthYears;
}

//This function creates and returns a new vector containing only the scientists whose death years match the year being searched.
//The year being searched is the integer that is taken in as an argument.
vector<scientistList> listServices::searchAlive()
{
    vector<scientistList> matchingScientists;

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
    listServices theList;
    unsigned int longest = 7;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if(longest < theList.getFirstNameFromList(i).size())
        {
            longest = theList.getFirstNameFromList(i).size();
        }
    }
    unsigned int newLongest = longest;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if(newLongest < theList.getLastNameFromList(i).size())
        {
            newLongest = theList.getLastNameFromList(i).size();
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


