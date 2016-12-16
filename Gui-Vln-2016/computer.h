#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Computer
{
    int _ID;
    string _computerName;
    string _computerType;
    int _yearOfBuild;
    bool _wasBuilt;

public:
    Computer();
    Computer(int id, string fComputer, string tComputers, int yoBuild, bool wBuilt);

    //Get functions to access data
    int getID();
    string getComputerName();
    string getComputerType();
    int getYearOfBuild();
    bool getWasBuilt();
};

#endif // COMPUTER_H
