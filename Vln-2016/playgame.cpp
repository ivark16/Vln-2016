#include "playgame.h"

playGame::playGame()
{

}


const int ARRAT_SIZE = 3;

void playGame::printTable (char ticTacToeTable [ARRAT_SIZE][ARRAT_SIZE])
{
    for (int i = 0; i < ARRAT_SIZE; i++)
    {
        for (int j = 0; j < ARRAT_SIZE; j++)
        {
            cout << ticTacToeTable[i][j] << " ";
        }
        cout << endl;
    }
}
bool playGame::checkForWinner (char ticTacToeTable[ARRAT_SIZE][ARRAT_SIZE])
{
    //Horizontal Check
    for (int i = 0; i < 3; i++)
    {
        if (ticTacToeTable[i][0] == ticTacToeTable[i][1] && ticTacToeTable[i][1] == ticTacToeTable [i][2])
            {
                cout << "Winner is: " << ticTacToeTable[i][0] << endl;
                return true;
            }
    }
    //Vertical Check
    for (int i = 0; i < 3; i++)
    {
            if (ticTacToeTable[0][i] == ticTacToeTable[1][i] && ticTacToeTable[1][i] == ticTacToeTable [2][i])
            {
                cout << "Winner is: " << ticTacToeTable[0][i] << endl;
                return true;
            }
    }
    //Right cross Check
    for (int i = 0; i < 3; i++)
    {
        if (ticTacToeTable [0][0] == ticTacToeTable [1][1] && ticTacToeTable [1][1] == ticTacToeTable [2][2])
        {
            cout << "Winner is: " << ticTacToeTable[0][0] << endl;
                    return true;
        }
    }

    //Left cross Check
    for (int i = 0; i < 3; i++)
    {
        if (ticTacToeTable [0][2] == ticTacToeTable [1][1] && ticTacToeTable [1][1] == ticTacToeTable[2][0])
        {
            cout << "Winner is: " << ticTacToeTable[0][2] << endl;
            return true;
        }
    }
    return false;
}

bool playGame::insertCharacters(char ticTacToeTable[ARRAT_SIZE][ARRAT_SIZE], char place, char player)
{
    bool valid = false;
    for (int i = 0; i< ARRAT_SIZE; i++)
    {
        for (int j = 0 ; j < ARRAT_SIZE; j ++)
        {
            if (ticTacToeTable[i][j] == place)
            {
                ticTacToeTable[i][j] = player;
                valid = true;
            }
        }
    }
    return valid;
}
int playGame::theGame (char ticTacToeTable [ARRAT_SIZE][ARRAT_SIZE])
{
    char player = 'X';
    int draw = 0;
    while (draw < 9)
    {
        cout << player << " position: ";
        char place;
        cin >> place;
        bool isValid = insertCharacters(ticTacToeTable, place, player);

        if (!isValid)
        {
            cout << "Illegal move!" << endl;
        }
        else if (player == 'X')
        {
            printTable (ticTacToeTable);
            player = 'O';
            draw++;
        }
        else
        {
            printTable (ticTacToeTable);
            player = 'X';
            draw++;
        }
        if (checkForWinner(ticTacToeTable) == true)
        {
            return 0;
        }
    }
    cout << "Draw!" << endl;
    return 0;
}
