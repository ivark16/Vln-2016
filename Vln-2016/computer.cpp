#include "computer.h"

Computer::Computer()
{
    //empty constructor
}

Computer::Computer(string cNames, string cType, string tComputers, int yoBuild)
{
    _computerNames = cNames;
    _computerType = cType;
    _tableComputers = tComputers;
    _yearOfBuild = yoBuild;
}

string Computer::getComputerNames()
{
    return _computerNames;
}
string Computer::getComputerType()
{
    return _computerType;
}
string Computer::getTableComputers()
{
    return _tableComputers;
}
int Computer::getYearOfBuild()
{
    return _yearOfBuild;
}
