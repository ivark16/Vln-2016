#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "scientistList.h"
#include <vector>


class listServices
{
    vector<scientistList> _computerScientists;

public:
    listServices();
 void   sortByName();
 void   sortByBirth();
 void   sortByAlive();
 void   sortByAward();
 void   addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear);

 vector<scientistList>   searchLastName(string lastName);
 vector<scientistList>   searchBirth(int birthYear);
 vector<scientistList>   searchAlive(int deathYear);
 vector<scientistList>   searchAward(int awardYear);



};

#endif // LISTSERVICES_H