#include "scientistList.h"
#include <iostream>
#include <vector>
using namespace std;

scientistList::scientistList()
{

}

// Constructor to input new Scientist to file, this does not overrite the file, only append the file.
scientistList::scientistList(string nafn, string nafn2, char kyn, int faedingarAr, int danarar, int verdlaun)
{
    fstream myFile;
    myFile.open("turingAwardWinners.txt", ios::app);

    myFile << endl;
    myFile << nafn << " ";
    myFile << nafn2 << " ";
    myFile << kyn << " ";
    myFile << faedingarAr << " ";
    myFile << danarar << " ";
    myFile << verdlaun;

    myFile.close();
}

// Reading from file turingAwardWinners.txt, this function reads from file and imports it to vector that is sent from the
// function from listServices.
void scientistList::readFile (vector <scientistList>& science)  //returns true if it is not the end of the file.
{
    fstream file;
    file.open("turingAwardWinners.txt");
    if(file.fail())
    {
        exit(1);
    }
    while(!file.eof())
    {
        scientistList bla;
        file >> bla._firstName;
        file >> bla._lastName;
        file >> bla._sex;
        file >> bla._birthYear;
        file >> bla._deathYear;
        file >> bla._TuringAwards;
        science.push_back(bla);
     }
        file.close();
}

string scientistList::getFirstName() const
{
    return _firstName;
}

string scientistList::getLastName() const
{
    return _lastName;
}

// Returning date of birth
int scientistList::dob() const
{
    return _birthYear;
}

// Returning date of death
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

//Returning full name
string scientistList::fullName() const
{
    string a = getFirstName() + getLastName();
    return a;
}

// For Chuck Norris
void scientistList::setFirstName(string name)
{
   _firstName = name;
}

// For Chuck Norris
void scientistList::setLastName(string name)
{
   _lastName = name;
}
