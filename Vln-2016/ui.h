#ifndef UI_H
#define UI_H
#include "listservices.h"
#include "DataLayer.h"
#include "scientist.h"
#include "computer.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

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
    void printScientists(vector<Scientist> scientistsToPrint);
    void printComputers(vector<Computer> computersToPrint);
    void printS();
    void printC();

    //check functions
    void CheckNumbers (listServices checkNumbersForScientist);
    int yearChecker(const int TYPE, int birthYear, int deathYear);
    string nationalityChecker();
    int deathYearChecker();
    int awardYearChecker();
    int birthYearChecker();
    string nameChecker(string nameType);
    char genderChecker();
    string computerNameChecker();
    string computerTypeChecker();
    bool boolChecker();

    //Headders
    void headerCase();
    void mainMenuCase();
    void caseOneCase();
    void caseTwoCase();
    void caseFourCase();
    void caseFiveCase();







};

#endif // UI_H
