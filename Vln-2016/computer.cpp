#include "computer.h"

Computer::Computer()
{
    //empty constructor
}

Computer::Computer(string fComputer, string tComputers, int yoBuild)
{
    _firstComputer = fComputer;
    _tableComputers = tComputers;
    _yearOfBuild = yoBuild;
}

string Computer::getFirstComputer()
{
    return _firstComputer;
}
string Computer::getTableComputers()
{
    return _tableComputers;
}
int Computer::getYearOfBuild()
{
    return _yearOfBuild;
}
