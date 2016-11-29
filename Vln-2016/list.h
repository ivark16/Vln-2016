#ifndef LIST_H
#define LIST_H
#include <string>
#include <fstream>
using namespace std;


class list
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

    list();
    bool readFile ();
    void getScientist ();

};

#endif // LIST_H
