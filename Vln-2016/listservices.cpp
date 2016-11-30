#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

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

listServices::listServices()
{
        scientistList nextScientist;
        nextScientist.readFile(_computerScientists);
}

vector<scientistList> listServices::sortByName()
{
    vector<scientistList> sortedByName;

    ScientistComparison cmp;

    std::sort(sortedByName.begin(), sortedByName.end(), cmp);


    return sortedByName;
}
vector<scientistList> listServices::sortByBirth()
{
    vector<scientistList> sortedList;
    int currentSmallest;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        currentSmallest = _computerScientists[i].dob();
        for(unsigned int j = i; j < _computerScientists.size(); j++)
        {
           if(_computerScientists[i].dob() < currentSmallest)
           {
               scientistList temp;
               temp = _computerScientists[i];
               _computerScientists[i] = _computerScientists[j];
               _computerScientists[i] = temp;
               sortedList.push_back(temp);
           }
        }
    }
    return sortedList;
}

vector<scientistList>   listServices::sortByAlive()
{
    vector<scientistList> sortedList;
    int currentYear;

  for(unsigned int i = 0; i < _computerScientists.size(); i++)
  {
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
sortedList = _computerScientists;
return sortedList;
}

vector<scientistList>   listServices::sortByAward()
{

    vector<scientistList> sortedList;
    int currentSmallest;

    for(unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        currentSmallest = _computerScientists[i].getAwards();
        for(unsigned int j = i; j < _computerScientists.size(); j++)
        { //in the if sentence below, a 0 in getAwards indicates that the scientist has never received the award.
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

void   listServices::addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear)
{
    scientistList newScientist(firstName, lastName, gender, birthYear, deathYear, awardYear);
    _computerScientists.push_back(newScientist);
}

vector<scientistList> listServices::searchLastName(string lastName)
{
    vector<scientistList> matchingLastNames;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if (lastName == _computerScientists[i].getLastName())
        {
            matchingLastNames.push_back(_computerScientists[i]);
        }
    }
    return matchingLastNames;
}

vector<scientistList> listServices::searchFirstName(string firstName)
{
    vector<scientistList> matchingFirstNames;
    for (unsigned int i = 0; i < _computerScientists.size(); i++)
    {
        if (firstName == _computerScientists[i].getLastName())
        {
            matchingFirstNames.push_back(_computerScientists[i]);
        }
    }
    return matchingFirstNames;
}


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

vector<scientistList> listServices::searchAlive(int deathYear)
{
    vector<scientistList> livingScientists;

    for(unsigned int k = 0; k < _computerScientists.size(); k++)
    {
        if(_computerScientists[k].dod() == 0)
        {
            livingScientists.push_back(_computerScientists[k]);
        }
    }
    return livingScientists;
}

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



void listServices::changeTo(vector<scientistList> rhs)
{
    _computerScientists  = rhs;
}

int listServices::getSize ()
{
    return _computerScientists.size();
}

