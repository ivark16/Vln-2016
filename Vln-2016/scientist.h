#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Scientist
{
    string _firstName;
    string _lastName;
    string _nationality;
    int _birthYear;
    int _deathYear;
    char _sex;
    int _TuringAwards;

public:
    Scientist();
};

#endif // SCIENTIST_H
