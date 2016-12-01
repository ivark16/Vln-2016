#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "scientistList.h"
#include <vector>


class listServices
{
    vector<scientistList> _computerScientists;

public:
    listServices();
    string getFirstNameFromList(int i);
    string getLastNameFromList(int i);
    string fullNameFromList(int i) const;
    int dobFromList(int i) const;
    int dodFromList(int i) const;
    char getSexFromList(int i) const;
    int getAwardsFromList(int i) const;


    vector<scientistList> searchName(string searchTerm);
    vector<scientistList> sortByName();
    vector<scientistList>   sortByBirth();
    vector<scientistList>    sortByAlive();
    vector<scientistList>   sortByAward();
    void   addNew(string firstName, string lastName, char gender, int birthYear, int deathYear, int awardYear);


    vector<scientistList>   searchLastName(string lastName);
    vector<scientistList>   searchFirstName(string firstName);
    vector<scientistList>   searchBirth(int birthYear);
    vector<scientistList>   searchAlive();
    vector<scientistList>   searchAward(int awardYear);
    vector<scientistList>   chuckNorris();
    void changeTo(vector<scientistList> rhs);
    int getSize ();
    int searchLongestName();
    string changeToLower(string input);

};

#endif // LISTSERVICES_H
