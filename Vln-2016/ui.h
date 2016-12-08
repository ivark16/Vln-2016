#ifndef UI_H
#define UI_H
#include "listservices.h"
#include "DataLayer.h"
#include "scientist.h"
#include "computer.h"
#include <iostream>
#include <vector>
#include <stdio.h>

class ui
{
    int _chooseNumber;
    Scientist _scientist;
    listServices _lists;
public:
    ui();
    ui(int chooseNumber);
    void run();
    void print(listServices scientistsToPrint);
    void printNames(vector<Scientist> scientistsToPrint);
<<<<<<< HEAD
    void printComputers(vector<Computer> computersToPrint);

=======
    void printComputers();
    void printScientist();
>>>>>>> 383d732c22352ffe39eca498c1350c6f296cfaeb
};

#endif // UI_H
