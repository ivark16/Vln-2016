#include "scientistList.h"
#include <iostream>
using namespace std;

scientistList::scientistList()
{

}

scientistList::scientistList(string nafn, string nafn2, char kyn, int faedingarAr, int danarar, int verdlaun)
{
    fstream myFile;
    myFile.open("turingAwardWinners.txt", ios::app);

    myFile << nafn << " ";
    myFile << kyn << " ";
    myFile << faedingarAr << " ";
    myFile << danarar << " ";
    myFile << verdlaun << " ";

    myFile.close();
}

//Reading from file
bool scientistList::readFile ()  //returns true if it is not the end of the file.
{
    fstream file;
    file.open("turingAwardWinners.txt");


    file >> _firstName;
    file >> _lastName;
    file >> _sex;
    file >> _birthYear;
    file >> _deathYear;
    file >> _TuringAwards;
    if (file.eof())
    {
        return true;
        cout << "Returns true";
    }
    file.close();
    return false;
}

void scientistList::getScientist ()
{
    firstName = _firstName;
    lastName = _lastName;
    sex = _sex;
    birthYear = _birthYear;
    deathYear = _deathYear;
    TuringAwards = _TuringAwards;
}

string scientistList::getFirstName() const
{
    return _firstName;
}

string scientistList::getLastName() const
{
    return _lastName;
}
int scientistList::dob() const
{
    return _birthYear;
}

int scientistList::dod() const
{
    return _deathYear;
}

char scientistList::getSex () const
{
    return _sex;
}

int scientistList::getAwards() const
{
    return _TuringAwards;
}

string scientistList::fullName() const
{
    string a = getFirstName() + getLastName();
    return a;
}
