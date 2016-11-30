#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "scientistList.h"
#include <vector>


class listServices
{
    vector<scientistList> _computerScientists;

public:
    listServices();
vector<scientistList> sortByName();
vector<scientistList>   sortByBirth();
vector<scientistList>    sortByAlive();
vector<scientistList>   sortByAward();
 void   addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear);

 vector<scientistList>   searchLastName(string lastName);
 vector<scientistList>   searchBirth(int birthYear);
 vector<scientistList>   searchAlive(int deathYear);
 vector<scientistList>   searchAward(int awardYear);

};

#endif // LISTSERVICES_H
