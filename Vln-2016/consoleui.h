#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "listservices.h"
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class consoleUI
{
    int _chooseNumber;
    listServices _scientist;
public:
    consoleUI();
    consoleUI(int chooseNumber);
    void run();
    void displayList();
    void searchFirstName();
    void searchLastName();

    void Print();
};

#endif // CONSOLEUI_H
