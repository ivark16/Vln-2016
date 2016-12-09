#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <iostream>
#include "string"

using namespace std;



class playGame
{
public:
    playGame();
    void printTable (char ticTacToeTable [3][3]);
    bool checkForWinner (char ticTacToeTable[3][3]);
    bool insertCharacters(char ticTacToeTable[3][3], char place, char player);
    int theGame (char ticTacToeTable [3][3]);

};

#endif // PLAYGAME_H
