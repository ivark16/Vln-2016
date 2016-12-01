#ifndef SCIENTISTLIST_H
#define SCIENTISTLIST_H
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


class scientistList
{
private:
    string _firstName;
    string _lastName;
    int _birthYear;
    int _deathYear;
    char _sex;
    int _TuringAwards;

public:
    string firstName;
    string lastName;
    char sex;
    int birthYear;
    int deathYear;
    int TuringAwards;

    scientistList();
    scientistList(string nafn1, string nafn2 , char kyn, int faedingarAr, int danarar, int verdlaun);
    void readFile (vector <scientistList>& science);
    void getScientist();
    string getFirstName() const;
    string getLastName() const;
    string fullName() const;
    int dob() const;
    int dod() const;
    char getSex () const;
    int getAwards() const;

    void setFirstName(string name);
    void setLastName(string name);

};

#endif // SCIENTISTLIST_H
