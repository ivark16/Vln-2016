#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vantar numberbreitur í txt-sjalinu
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

    //Get foll
    int getID();
    string getComputerName();
    string getComputerType();
    int getYearOfBuild();
    bool getWasBuilt();

};

#endif // COMPUTER_H
