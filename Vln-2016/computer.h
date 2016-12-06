#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vantar numberbreitur í txt-sjalinu
class Computer
{
    string _computerName;
    string _computerType;
    int _yearOfBuild;
    bool _wasBuilt;

public:
    Computer();
    Computer(string cName, string cType, int yoBuild, bool wBuilt);
    string getComputerName();
    string getComputerType();
    int getYearOfBuild();
    bool getWasBuilt();

};

#endif // COMPUTER_H
