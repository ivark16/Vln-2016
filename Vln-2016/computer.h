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

public:
    Computer();
    Computer(string fComputer);
    string getFirstComputer();

};

#endif // COMPUTER_H
