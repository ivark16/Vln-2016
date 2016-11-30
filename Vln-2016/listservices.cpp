#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct ScientistComparison {
    bool operator ()(scientistList i, scientistList j) {return (i.fullName() < j.fullName());}
};


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
               sortedList.push_back(temp);
           }
        }
    }
    return sortedList;
}




void   listServices::addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear)
{
    scientistList newScientist(firstName, lastName, gender, birthYear, deathYear, awardYear);
    _computerScientists.push_back(newScientist);
}/*

vector<scientistList> listServices::searchLastName(string lastName)
{
    vector<scientistList> matchingNames;
    //TODO
    return matchingNames;
}*/

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
/*
vector<scientistList> listServices::searchAward(int awardYear)
{
    vector<scientistList> matchingAwardYear;
    //TODO
    return matchingAwardYear;
}
*/
