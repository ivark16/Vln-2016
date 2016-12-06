#include "computer.h"

Computer::Computer()
{
    //empty constructor
}

Computer::Computer(string fComputer)
{
    _firstComputer = fComputer;
}

string Computer::getFirstComputer()
{
    return _firstComputer;
}
