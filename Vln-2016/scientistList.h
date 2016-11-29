#ifndef SCIENTISTLIST_H
#define SCIENTISTLIST_H

using namespace std;

#include <string>
#include <fstream>
using namespace std;


class scientistList
{
private:
    string _name;
    int _birthYear;
    int _deathYear;
    char _sex;
    int _TuringAwards;

public:
    string name;
    char sex;
    int birthYear;
    int deathYear;
    int TuringAwards;

    scientistList();
    scientistList(string nafn, char kyn, int faedingarAr, int danarar, int verdlaun);
    bool readFile ();
    void getScientist ();
    string getName();
    int dob();
    int dod();
    char getSex ();
    int getAwards();

};

#endif // SCIENTISTLIST_H
