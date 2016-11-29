#ifndef SCIENTISTLIST_H
#define SCIENTISTLIST_H

using namespace std;

#include <string>
#include <fstream>
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
    bool readFile ();
    void getScientist();
    string getFirstName() const;
    string getLastName() const;
    int dob() const;
    int dod() const;
    char getSex () const;
    int getAwards() const;

};

#endif // SCIENTISTLIST_H
