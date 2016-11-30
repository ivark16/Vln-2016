#include <iostream>
#include "consoleui.h"
using namespace std;

int main(int argc, char *argv[])
{
    consoleUI Master;
    Master.run();

    return 0;

}
#include "list.h"
using namespace std;

list::list()
{

}

//Reading from file
bool list::readFile ()
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

void list::getScientist ()
{
    name = _name;
    sex = _sex;
    birthYear = _birthYear;
    deathYear = _deathYear;
    TuringAwards = _TuringAwards;
}

