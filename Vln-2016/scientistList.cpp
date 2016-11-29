#include "scientistList.h"
using namespace std;

scientistList::scientistList()
{

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
