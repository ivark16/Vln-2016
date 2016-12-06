#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vantar numberbreitur í txt-sjalinu
class Computer
{
    string _firstComputer;
    string _tableComputers;
    int _yearOfBuild;

public:
    Computer();
    Computer(string fComputer, string tComputers, int yoBuild);
    string getFirstComputer();
    string getTableComputers();
    int getYearOfBuild();

};

#endif // COMPUTER_H
