#ifndef SEARCHING_H
#define SEARCHING_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class searching
{
    string _firstName;
    string _lastName;
    string _computerName;
    int _yearbuilt;
public:
    searching();
    searching(string firstname, string lastname,string computername,int yearbuilt);
    string getSearchFirstName();
    string getSearchLastName();
    string getSearchComputerName();
    int getSearchYearBuilt();
};

#endif // SEARCHING_H
