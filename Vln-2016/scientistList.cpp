#include "scientistList.h"
using namespace std;

scientistList::scientistList()
{

}

scientistList::scientistList(string nafn, char kyn, int faedingarAr, int danarar, int verdlaun)
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
bool scientistList::readFile ()
{
    fstream file;
    file.open("turingAwardWinners.txt");


    file >> _name;
    file >> _sex;
    file >> _birthYear;
    file >> _deathYear;
    file >> _TuringAwards;
    if (file.eof())
    {
        return true;
    }
    file.close();
    return false;
}

void scientistList::getScientist ()
{
    name = _name;
    sex = _sex;
    birthYear = _birthYear;
    deathYear = _deathYear;
    TuringAwards = _TuringAwards;
}

string scientistList::getName()
{
    return name;
}

int scientistList::dob()
{
    return birthYear;
}

int scientistList::dod()
{
    return deathYear;
}

char scientistList::getSex ()
{
    return sex;
}

int scientistList::getAwards()
{
    return TuringAwards;
}
