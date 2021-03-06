#ifndef UI_H
#define UI_H
#include "listservices.h"
#include "DataLayer.h"
#include "scientist.h"
#include "computer.h"
#include "connection.h"
#include "search.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

class ui
{
    int _chooseNumber;
    Computer _computer;
    Scientist _scientist;
    listServices _lists;
public:
    ui();
    ui(int chooseNumber);
    void run();

    // Print functions, prints out hedders and tables
    void print(listServices scientistsToPrint);
    void printScientists(vector<Scientist> scientistsToPrint);
    void printComputers(vector<Computer> computersToPrint);
    void printS();
    void printC();
    void printConnection();
    void printJoin(vector<searching>);
    void printBird();
    void enterPassword();



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
    void caseThreeCase();
    void caseFourCase();
    void caseFiveCase();
    void caseSixCase();

    //Search functions for case 3
    void searchScientist();
    void searchScientistByBirthYear();
    void searchScientistByName();
    void searchComputers();
    void searchComputersByCreation();
    void searchConnections();
    void searchScientistByAward();

    //Add function for case 4
    void addScientist();
    void addComputer();
    void addConnection();

    //functions for case six
    void caseSixMajorCase();
    void caseSixCaseOne(int &counter);

    //functions for case seven
    void caseSevenCase(int &playGame);
    void caseSevenCase2(int &playGame);
    void caseSevenCase3(int &playGame);
    void caseSevenCase4(int &playGame);
    void caseSevenCase5(int &playGame);
    void playGame();




};

#endif // UI_H
