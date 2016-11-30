#include "consoleui.h"
#include <iostream>
#include <iomanip>
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
            //
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
            {
            listServices scientists;
            scientists.changeTo(_scientist.sortByAlive());
            cout << "An organized list starting with the oldest living scientist" << endl;
            for(int i = 0 ; i < scientists.getSize(); i++)
            {
                cout.width(15);
                cout << scientists.getFirstNameFromList(i) << left << scientists.getLastNameFromList(i) << endl;

            }
             }
              break;
        case 4:
            //sortAward
        //sortAlive
            {
            listServices scientistsByAward;
            scientistsByAward.changeTo(_scientist.sortByAward());
            cout << "An organized list starting with the oldest living scientist" << endl;
            for(int i = 0 ; i < scientistsByAward.getSize(); i++)
            {
                cout.width(15);
                cout << scientistsByAward.getFirstNameFromList(i) << left << scientistsByAward.getLastNameFromList(i) << endl;

            }
             }
            break;

        case 5:
    {
            //addNew
        string firstName;
        string lastName;
        char gender;
        int birthYear;
        char isAlive;
        int deathYear;
        char isWinner;
        int awardYear;

        cout << "Please enter the scientist's first name: ";
        cin >> firstName;
        cout << "Please enter the scientist's last name: ";
        cin >> lastName;
        cout << "Enter the scientist's gender (m/f) : ";
        cin >> gender;
        cout << "Enter the scientist's birth year: ";
        cin >> birthYear;
        cout << "Is the scientist still alive? (y/n) ";
        cin >> isAlive;
        if(isAlive == 'n')
        {
        cout << "Enter the scientist's year of death: ";
        cin >>  deathYear;
        }
        else if(isAlive == 'y')
        {
        deathYear = 0;
        }
        else
        {
        "Invalid entry.  Please enter either y (yes) or n (no)";
        }
        cout << "Did the scientist win a Turing award? (y/n)";
        cin >> isWinner;
        if(isWinner == 'y')
        {
        cout << "Enter the year the scientist won: ";
        cin >>  awardYear;
        }
        else if(isWinner == 'n')
        {
        awardYear = 0;
        }
        else
        {
        "Invalid entry.  Please enter either y (yes) or n (no)";
        }

        _scientist.addNew(firstName, lastName, gender, birthYear, deathYear, awardYear);
    }
        break;

    }
}


