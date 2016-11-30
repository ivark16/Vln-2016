#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct ScientistComparison {
    bool operator ()(scientistList i, scientistList j) {return (i.fullName() < j.fullName());}
};

string listServices::getFirstNameFromList(int i)
{
    string name;
    name = _computerScientists[i].getFirstName();
    return name;
}

string listServices::getLastNameFromList(int i)
{
    string name;
    name = _computerScientists[i].getLastName();
    return name;
}

string listServices::fullNameFromList(int i) const
{
    string a = _computerScientists[i].fullName();
    return a;
}

int listServices::dobFromList(int i) const
{
    int a = _computerScientists[i].dob();
    return a;
}

int listServices::dodFromList(int i) const
{
    int a = _computerScientists[i].dod();
    return a;
}

char listServices::getSexFromList(int i) const
{
    char a = _computerScientists[i].getSex();
    return a;
}

int listServices::getAwardsFromList(int i) const
{
    int a = _computerScientists[i].getAwards();
    return a;
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

    return newLongest;

}

