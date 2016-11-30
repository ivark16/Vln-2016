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
        {
            int counter = 1;
            listServices scientists;
            cout << "***List of all scientists***" << endl;
            cout.width(10);
            cout << left << "number";
            cout.width(10);
            cout << "Firstname" << left;
            cout.width(10);
            cout << "Lastname" << left;
            cout.width(10);
            cout << "gender" << left;
            cout.width(10);
            cout << "D.O.B" << left;
            cout.width(10);
            cout << "D.O.D" << left;
            cout.width(10);
            cout << "Year of award" << left << endl;
            for(int i = 0 ; i < 9 ; i++)
            {
                cout << "--------";
            }
            cout << endl;
            for(int i = 0; i < scientists.getSize() - 1 ; i++)
            {

                string sex;
                string isDead;
                if(scientists.getSexFromList(i) == 'm')
                {
                    sex = "male";
                }
                else
                {
                    sex = "female";
                }
                cout.width(10);
                cout << left << counter;
                counter++;
                cout.width(10);
                cout << scientists.getFirstNameFromList(i) << left;
                cout.width(10);
                cout << scientists.getLastNameFromList(i) << left;
                cout.width(10);
                cout << sex << left;
                cout.width(10);
                cout << scientists.dobFromList(i) << left;
                if(scientists.dodFromList(i) == 0)
                {
                    isDead = "Alive";
                    cout.width(10);
                    cout << isDead << left;
                }
                else
                {
                    cout.width(10);
                    cout << scientists.dodFromList(i) << left;
                }
                cout.width(10);
                cout << scientists.getAwardsFromList(i) << left;;
                cout << "   *" << endl;

            }
            for(int i = 0 ; i < 9 ; i++)
            {
                cout << "--------";
            }
            cout << endl;
        }
            break;
        case 2:
            //Searching from first or last name
            {
                int firstOrLast;
                cout << "choose 1 for first name or 2 for last name" << endl;
                cin >> firstOrLast;
                if(firstOrLast == 1)
                {
                    listServices searchName;
                    string firstName;
                    cout << "Enter first name ";
                    cin >> firstName;
                    searchName.changeTo(_scientist.searchFirstName(firstName));
                    cout.width(15);
                    for (unsigned int i = 0; i < searchName.getSize(); i++)
                    {
                        cout << searchName.getFirstNameFromList(i);
                    }

                }
                else
                {
                    listServices searchName;
                    string lastName;
                    cout << "Enter last name ";
                    cin >> lastName;
                    searchName.changeTo(_scientist.searchLastName(lastName));
                    cout.width(15);
                    for (unsigned int i = 0; i < searchName.getSize(); i++)
                    {
                        cout << searchName.getLastNameFromList(i);
                    }
                }
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


