#include "scientist.h"

Scientist::Scientist()
{
 //empty constructor
}

Scientist::Scientist(string fName, string lName, string nationality, int bYear, int dYear, char gender, int aYear)
{
    _firstName = fName;
    _lastName = lName;
    _nationality = nationality;
    _birthYear = bYear;
    _deathYear = dYear;
    _sex = gender;
    _awardYear = aYear;
}

string Scientist::getFirstName()
{
    return _firstName;
}
string Scientist::getLastName()
{
    return _lastName;
}
string Scientist::getNationality()
{
    return _nationality;
}
int Scientist::getBirthYear()
{
    return _birthYear;
}
int Scientist::getDeathYear()
{
    return _deathYear;
}
char Scientist::getGender()
{
    return _sex;
}
int Scientist::getAwardYear()
{
    return _awardYear;
}

