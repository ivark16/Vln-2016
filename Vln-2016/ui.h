#ifndef UI_H
#define UI_H
#include "listservices.h"
#include"scientist.h"
#include <iostream>
#include <vector>
#include <stdio.h>

class ui
{
    int _chooseNumber;
    Scientist _scientist;
public:
    ui();
    ui(int chooseNumber);
    void run();
    void print(listServices scientistsToPrint);
    void printNames(Scientist scientistsToPrint);

};

#endif // UI_H
