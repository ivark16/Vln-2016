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

    myFile << endl;
    myFile << nafn << " ";
    myFile << nafn2 << " ";
    myFile << kyn << " ";
    myFile << faedingarAr << " ";
    myFile << danarar << " ";
    myFile << verdlaun;

    myFile.close();
}

//Reading from file
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

void scientistList::writeToFile(vector<scientistList> newFile)
{

    ofstream myfile;
    remove("turingAwardWinners.txt");
    myfile.open("turingAwardWinners.txt");
    if(myfile.is_open())
    {
        for(unsigned int i = 0 ; i < newFile.size() ; i++)
        {
            myfile << newFile[i].getFirstName() << " ";
            myfile << newFile[i].getLastName() << " ";
            myfile << newFile[i].getSex() << " ";
            myfile << newFile[i].dob() << " ";
            myfile << newFile[i].dod() << " ";
            myfile << newFile[i].getAwards() << " " << endl;

        }
        myfile.close();
    }


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


void scientistList::setFirstName(string name)
{
   _firstName = name;
}

void scientistList::setLastName(string name)
{
   _lastName = name;
}
