#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <iostream>
#include "string"

using namespace std;


class playGame
{
    int _answer;
    int _userAnswer;

public:
    playGame();
    playGame(int answer, int userAnswer);
    int getAnswer();
    int gerUserAnswer();


};

#endif // PLAYGAME_H
