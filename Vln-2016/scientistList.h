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
    bool readFile ();
    void getScientist ();

};

#endif // SCIENTISTLIST_H
