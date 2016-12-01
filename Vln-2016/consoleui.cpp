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
    cout << "4: Sort by award year.                *" << endl;
    cout << "5: Add new scientist.                 *" << endl;
    cout << "6: Search for birth year.             *" << endl;
    cout << "7: Enter Function.                    *" << endl;
    cout << "8: Sort by birthyear.                 *" << endl;
    cout << "9: Search for Turing award winner.    *" << endl;
    cout << "10:                                   *" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter number: ";

    cin >> chooseNumber;

    switch (chooseNumber)
    {
        case 1:
        {
            listServices scientists;
            cout << "***List of all scientists***" << endl;
            print();
            printNames(scientists);
        }
            break;
        case 2:
            //Searching from first or last name
            {
                listServices searchName;
                //listServices searchName2;
                int firstOrLast;
                cout << "Choose 1 for first name or 2 for last name: ";
                cin >> firstOrLast;
                if(firstOrLast == 1)
                {
                    string firstName;
                    cout << "Enter first name: ";
                    cin >> firstName;
                    searchName.changeTo(_scientist.searchFirstName(firstName));
                    print();
                    printNames(searchName);
                }
                else
                {
                    string lastName;
                    cout << "Enter last name: ";
                    cin >> lastName;
                    searchName.changeTo(_scientist.searchLastName(lastName));
                    print();
                    printNames(searchName);
                }
            }
            break;
        case 3:
            //sortAlive
            {
                listServices scientists;
                string searchTerm;
                scientists.changeTo(_scientist.searchAlive());
                cout << "An organized list starting with the oldest living scientist" << endl;
                print();
                printNames(scientists);
             }
              break;
        case 4:
            //sortAward
            {
                listServices scientistsByAward;
                scientistsByAward.changeTo(_scientist.sortByAward());
                cout << "An organized list of scientists in order of when they received the Turing award." << endl;
                print();
                printNames(scientistsByAward);
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
                    cout << "Invalid entry.  Please enter either y (yes) or n (no)";
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
                    cout << "Invalid entry.  Please enter either y (yes) or n (no)";
                }

                _scientist.addNew(firstName, lastName, gender, birthYear, deathYear, awardYear);
            }
            break;
    case 6:
        //searchBirth
        {
            int year;
            cout << "Enter year: ";
            cin >> year;
            listServices scientistsBirth;
            scientistsBirth.changeTo(scientistsBirth.searchBirth(year));
            cout << "A list of scientists born in your year of choice" << endl;
            print();
            printNames(scientistsBirth);
         }
          break;

    case 8:
        //sortByBirth

            _scientist.changeTo(_scientist.sortByBirth());
            cout << "An organized list starting with the oldest scientist" << endl;
            print();
            printNames(_scientist);
        break;

    case 9:
        //sortByAward
            _scientist.changeTo(_scientist.sortByAward());
            cout << "An organized list of scientists in order of when they received a Turing award." << endl;
            print();
            printNames(_scientist);
         break;
    }
}

void consoleUI::print()
{
    listServices scientists;

    cout.width(4);
    cout << left << "No.";
    cout.width(scientists.searchLongestName());
    cout << "Firstname" << left;
    cout.width(10);
    cout << "Lastname" << left;
    cout.width(10);
    cout << "gender" << left;
    cout.width(10);
    cout << "D.O.B" << left;
    cout.width(10);
    cout << "D.O.D" << left;
    cout.width(scientists.searchLongestName());
    cout << "Y.O.A." << left << endl;
    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "--------";
    }
    cout << endl;
}

void consoleUI::printNames (listServices scientistsToPrint)
{
    int counter = 1;
    for(int i = 0; i < scientistsToPrint.getSize() ; i++)
    {
        string sex;
        string isDead;
        if(scientistsToPrint.getSexFromList(i) == 'm')
        {
            sex = "male";
        }
        else
        {
            sex = "female";
        }
        cout.width(5);
        cout << left << counter;
        counter++;
        cout.width(10);
        cout << scientistsToPrint.getFirstNameFromList(i) << left;
        cout.width(10);
        cout << scientistsToPrint.getLastNameFromList(i) << left;
        cout.width(10);
        cout << sex << left;
        cout.width(10);
        cout << scientistsToPrint.dobFromList(i) << left;
        if(scientistsToPrint.dodFromList(i) == 0)
        {
            isDead = "Alive";
            cout.width(10);
            cout << isDead << left;
        }
        else
        {
            cout.width(10);
            cout << scientistsToPrint.dodFromList(i) << left;
        }
        cout.width(10);
        cout << scientistsToPrint.getAwardsFromList(i) << left;;
        cout << "   *" << endl;

    }
    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "--------";
    }
    cout << endl;
}
