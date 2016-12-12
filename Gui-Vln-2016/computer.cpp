#include "computer.h"

Computer::Computer()
{
    //empty constructor
}

Computer::Computer(int id, string cName, string cType, int yoBuild, bool wBuilt)
{
    _ID = id;
    _computerName = cName;
    _computerType = cType;
    _yearOfBuild = yoBuild;
    _wasBuilt = wBuilt;
}

int Computer::getID()
{
    return _ID;
}

string Computer::getComputerName()
{
    return _computerName;
}

string Computer::getComputerType()
{
    return _computerType;
}

int Computer::getYearOfBuild()
{
    return _yearOfBuild;
}

bool Computer::getWasBuilt()
{
    return _wasBuilt;
}
