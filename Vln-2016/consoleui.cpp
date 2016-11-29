#include "consoleui.h"
#include "scientistList.h"
#include "listservices.h"
#include <vector>
#include <iostream>

using namespace std;

consoleUI::consoleUI()
{

}

consoleUI::consoleUI(int chooseNumber)
{
    _chooseNumber = chooseNumber;
}

void consoleUI::run()
{
    int chooseNumber = 0;

    cout << "Enter number: ";
    cout << "1: for entire list." << endl;
    cout << "2: Search by name." << endl;
    cout << "3: Search if alive." << endl;
    cout << "4: Search for award." << endl;
    cout << "5: to add new scientist." << endl;
    cin >> chooseNumber;

    switch (chooseNumber)
    {
        case 1:
            //vector <scientistList> scientists = _scientist.();
            break;
        case 2:
            int firstOrLast;
            cout << "choose 1 for firstname or 2 for lastname" << endl;
            cin >> firstOrLast;
            if(firstOrLast == 1)
            {
                string firstName;
                cout << "Enter firstname";
                cin >> firstName;
                //searchfirstname
            }
            else
            {
                string lastName;
                cout << "Enter lastname:";
                cin >> lastName;

            }
            break;
        case 3:
            //sortAlive
            vector <scientistList> scientists = _scientist.sortByAlive();
            for(unsigned int i = 0 ; i < scientists.size(); i++)
            {
                cout << scientists[i].getFirstName() << endl;
            }
            break;
    }
}


