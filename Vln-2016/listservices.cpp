#include "listservices.h"
#include <vector>
#include <string>

using namespace std;

listServices::listServices()
{
    bool isEndOfFile;
    do {
        scientistList nextScientist;
        isEndOfFile = nextScientist.readFile();
        _computerScientists.push_back(nextScientist);
    }while(!isEndOfFile); //This loop fills the computerScientist vector ( a member variable) with computer scientists from the list class.

}

void   listServices::sortByName()
{
    //TODO: flokka eftir nafni
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

void   listServices::sortByAlive()
{
  for(unsigned int i = 0; i < _computerScientists.size(); i++)
  {
      for(unsigned int j = i ; i < _computerScientists.size(); j++)
      {

      }
  }




}

void   listServices::sortByAward()
{
    //TODO
}
/*

void   listServices::addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear)
{
    //TODO
}

vector<scientistList> listServices::searchLastName(string lastName)
{
    vector<scientistList> matchingNames;
    //TODO
    return matchingNames;
}

vector<scientistList> listServices::searchBirth(int birthYear)
{
    vector<scientistList> matchingBirthYears;
    //TODO
    return matchingBirthYears;
}

vector<scientistList> listServices::searchAlive(int deathYear)
{
    vector<scientistList> livingScientists;
    //TODO
    return livingScientists;
}

vector<scientistList> listServices::searchAward(int awardYear)
{
    vector<scientistList> matchingAwardYear;
    //TODO
    return matchingAwardYear;
}
*/
