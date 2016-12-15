#include "searching.h"

searching::searching()
{

}

searching::searching(int idScientist, int idComputer, string firstname, string lastname, string computername, string computertype , int yearbuilt)
{
    _idScientist = idScientist;
    _IdComputer = idComputer;
    _firstName = firstname;
    _lastName = lastname;
    _computerName = computername;
    _computerType = computertype;
    _yearbuilt = yearbuilt;
}

int searching::getSearchScientistId()
{
    return _idScientist;
}

int searching::getSearchComputerId()
{
    return _IdComputer;
}

string searching::getSearchFirstName()
{
    return _firstName;
}

string searching::getSearchLastName()
{
    return _lastName;
}

string searching::getSearchComputerName()
{
    return _computerName;
}

string searching::getSearchComputerType()
{
    return _computerType;
}

int searching::getSearchYearBuilt()
{
    return _yearbuilt;
}
