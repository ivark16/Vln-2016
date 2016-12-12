#include "scientist.h"

Scientist::Scientist()
{
 //empty constructor
}

Scientist::Scientist(int id, string fName, string lName, char gender, string nationality, int bYear, int dYear, int aYear)
{
    _ID = id;
    _firstName = fName;
    _lastName = lName;
    _nationality = nationality;
    _birthYear = bYear;
    _deathYear = dYear;
    _sex = gender;
    _awardYear = aYear;

    //DataLayer writer;
    //writer.addNewScientist(fName, lName, nationality, bYear, dYear, gender, aYear); ADD THIS FUNCTION TO DATALAYER
}

void Scientist::readFile(vector<Scientist>& scientists)
{
    //DataLayer reader;
    /*  WRITE THESE FUNCTIONS TO DATALAYER
    do(
    _firstName = reader.getFirstName(i);
    _lastName = reader.getLastName(i);
    _nationality = reader.getNationality(i);
    _birthYear = reader.getBirthYear(i);
    _deathYear = reader.getDeathYear(i);
    _sex = reader.getGender(i);
    _awardYear = reader.getAwardYear(i);
    ) while {reader.hasMoreScientists()}
    */
}

int Scientist::getID()
{
    return _ID;
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
