#ifndef SEARCHING_H
#define SEARCHING_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class searching
{
    int _idScientist;
    int _IdComputer;
    string _firstName;
    string _lastName;
    string _computerName;
    string _computerType;
    int _yearbuilt;
public:
    searching();
    searching(int idscientist, int idcomputer, string firstname, string lastname,string computername, string computertype,int yearbuilt);
    int getSearchScientistId();
    int getSearchComputerId();
    string getSearchFirstName();
    string getSearchLastName();
    string getSearchComputerName();
    string getSearchComputerType();
    int getSearchYearBuilt();
};

#endif // SEARCHING_H
