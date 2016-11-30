#include "consoleui.h"

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
    cout << "---------------------------------------" << endl;
    cout << "------- Database for Scientist --------" << endl;
    cout << "1: Display entire list.               *" << endl;
    cout << "2: Search by name.                    *" << endl;
    cout << "3: Search if alive.                   *" << endl;
    cout << "4: Search for award.                  *" << endl;
    cout << "5: Add new scientist.                 *" << endl;
    cout << "6: Enter Function.                    *" << endl;
    cout << "7: Enter Function.                    *" << endl;
    cout << "8: Enter Function.                    *" << endl;
    cout << "9: Enter Function.                    *" << endl;
    cout << "10: Enter Function.                   *" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter number: ";
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


