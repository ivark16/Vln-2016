#include "searching.h"

searching::searching()
{

}

searching::searching(string firstname, string lastname, string computername, int yearbuilt)
{
    _firstName = firstname;
    _lastName = lastname;
    _computerName = computername;
    _yearbuilt = yearbuilt;
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

int searching::getSearchYearBuilt()
{
    return _yearbuilt;
}
