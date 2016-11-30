#include "scientistList.h"
#include <iostream>
#include <vector>
using namespace std;

scientistList::scientistList()
{

}

scientistList::scientistList(string nafn, string nafn2, char kyn, int faedingarAr, int danarar, int verdlaun)
{
    fstream myFile;
    myFile.open("turingAwardWinners.txt", ios::app);

    myFile << nafn << " ";
    myFile << nafn2 << " ";
    myFile << kyn << " ";
    myFile << faedingarAr << " ";
    myFile << danarar << " ";
    myFile << verdlaun << " ";

    myFile.close();
}

//Reading from file
bool scientistList::readFile (vector <scientistList>& science)  //returns true if it is not the end of the file.
{
    scientistList bla;
    fstream file;
    file.open("turingAwardWinners.txt");


    file >> bla._firstName;
    file >> bla._lastName;
    file >> bla._sex;
    file >> bla._birthYear;
    file >> bla._deathYear;
    file >> bla._TuringAwards;

    science.push_back(bla);
    if (!file.eof())
    {
        return true;
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
    return firstName;
}

string scientistList::getLastName() const
{
    return lastName;
}
int scientistList::dob() const
{
    return birthYear;
}

int scientistList::dod() const
{
    return deathYear;
}

char scientistList::getSex () const
{
    return sex;
}

int scientistList::getAwards() const
{
    return TuringAwards;
}

string scientistList::fullName() const
{
    string a = getFirstName() + getLastName();
    return a;
}
