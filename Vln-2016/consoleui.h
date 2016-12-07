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
    //listServices _scientist;
    DataLayer _myData;
public:
    consoleUI();
    consoleUI(int chooseNumber);
    void run();
    void displayList();
    void searchFirstName();
    void searchLastName();
    string nameChecker(string nameType);
    char genderChecker();


    void print(listServices scientistsToPrint);
    void printNames (listServices scientistsToPrint);
    void CheckNumbers (listServices checkNumbersForScientist);
    int yearChecker(const int year, int birthYear, int deathYear);
    string nationalityChecker();



};

#endif // CONSOLEUI_H
