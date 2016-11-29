#include "listservices.h"
#include <vector>

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
void   listServices::sortByBirth()
{



}

void   listServices::sortByAlive()
{
    //TODO
}

void   listServices::sortByAward()
{
    //TODO
}

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
