#include "listservices.h"
#include <vector>

listServices::listServices()
{
    bool isEndOfFile;
    do {
        list nextScientist();
        isEndOfFile = nextScientist.readFile ();
        _computerScientists.push_back(nextScientist);
    }while(!isEndOfFile); //This loop fills the computerScientist vector ( a member variable) with computer scientists from the list class.

}

void   listServices::sortByName()
{
    //TODO: flokka eftir nafni
}
void   listServices::sortByBirth()
{
    //TODO
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

vector<list> listServices::searchLastName(string lastName)
{
    vector<list> matchingNames;
    //TODO
    return matchingNames;
}

vector<list> listServices::searchBirth(int birthYear)
{
    vector<list> matchingBirthYears;
    //TODO
    return matchingBirthYears;
}

vector<list> listServices::searchAlive(int deathYear)
{
    vector<list> livingScientists;
    //TODO
    return livingScientists;
}

vector<list> listServices::searchAward(int awardYear)
{
    vector<list> matchingAwardYear;
    //TODO
    return matchingAwardYear;
}
