#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vantar numberbreitur í txt-sjalinu
class Computer
{
    string _computerNames;
    string _computerType;
    string _tableComputers;
    int _yearOfBuild;

public:
    Computer();
    Computer(string cNames, string cType, string tComputers, int yoBuild);
    string getComputerNames();
    string getComputerType();
    string getTableComputers();
    int getYearOfBuild();

};

#endif // COMPUTER_H
