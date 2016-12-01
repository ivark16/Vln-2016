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
            Print();
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
                listServices searchName;
                //listServices searchName2;
                int firstOrLast;
                cout << "choose 1 for first name or 2 for last name" << endl;
                cin >> firstOrLast;
                if(firstOrLast == 1)
                {
                    string firstName;
                    cout << "Enter first name ";
                    cin >> firstName;

                    searchName.changeTo(_scientist.searchFirstName(firstName));
                    for (unsigned int i = 0; i < searchName.getSize(); i++)
                    {
                        cout << searchName.getFirstNameFromList(i) << " " << searchName.getLastNameFromList(i) << endl;
                    }

                }
                else
                {
                    string lastName;
                    cout << "Enter last name ";
                    cin >> lastName;

                    searchName.changeTo(_scientist.searchLastName(lastName));
                    for (unsigned int i = 0; i < searchName.getSize(); i++)
                    {
                        cout << searchName.getFirstNameFromList(i) << " " << searchName.getLastNameFromList(i) << endl;

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
            Print();
            for(int i = 0 ; i < scientists.getSize(); i++)
            {
                string a;
                string b;
                if (scientists.getSexFromList(i) == 'm')
                {
                    a = "Male";
                } else {
                    a = "Female";
                }

                cout.width(scientists.searchLongestName());
                cout << left << scientists.getFirstNameFromList(i);
                cout.width(scientists.searchLongestName());
                cout << scientists.getLastNameFromList(i) << left;
                cout.width(scientists.searchLongestName());
                cout << a << left;
                cout.width(scientists.searchLongestName());
                cout << scientists.dobFromList(i) << left;
                cout.width(scientists.searchLongestName());

                if (scientists.dodFromList(i) == 0){
                    cout.width(scientists.searchLongestName());
                    cout << "Alive" << left;
                } else {
                    cout.width(scientists.searchLongestName());
                    cout << scientists.dodFromList(i) << left;
                }
                cout.width(scientists.searchLongestName());
                cout << scientists.getAwardsFromList(i) << endl;
                //cout <<  << endl;

            }
             }
              break;
        case 4:
            //sortAward
            {
            listServices scientistsByAward;
            scientistsByAward.changeTo(_scientist.sortByAward());
            cout << "An organized list of scientists in order of when they received the Turing award." << endl;
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
    case 6:
        //searchBirth
        {
        int year;

        cout << "Enter year: ";
        cin >> year;
        listServices scientistsBirth;
        scientistsBirth.changeTo(scientistsBirth.searchBirth(year));
        cout << "A list of scientists born in your year of choice" << endl;
        Print();
        for(int i = 0; i < scientistsBirth.getSize(); i++)
        {

            cout << scientistsBirth.getFirstNameFromList(i);
            for(int k = 0; k < 15 - scientistsBirth.getFirstNameFromList(i).size(); k++)
            {
                cout << " ";
            }

            cout << _scientist.getLastNameFromList(i) << endl;

        }
         }
          break;

    case 8:
        //sortByBirth

       _scientist.changeTo(_scientist.sortByBirth());
       cout << "An organized list starting with the oldest scientist" << endl;
       Print();
       cout << _scientist.getFirstNameFromList(0);  // taka ut og setja print fallid hans ivars
       cout << _scientist.getFirstNameFromList(1);


        break;

    case 9:
        //sortByAward


        _scientist.changeTo(_scientist.sortByAward());
        cout << "An organized list of scientists in order of when they received a Turing award." << endl;
        Print();
        cout << _scientist.getFirstNameFromList(0);  // taka ut og setja print fallid hans ivars
        cout << _scientist.getFirstNameFromList(1);


         break;

        break;




    }
}




void consoleUI::Print()
{
    listServices scientists;

    cout.width(scientists.searchLongestName());
    cout << left << "number";
    cout.width(scientists.searchLongestName());
    cout << "Firstname" << left;
    cout.width(scientists.searchLongestName());
    cout << "Lastname" << left;
    cout.width(scientists.searchLongestName());
    cout << "gender" << left;
    cout.width(scientists.searchLongestName());
    cout << "D.O.B" << left;
    cout.width(scientists.searchLongestName());
    cout << "D.O.D" << left;
    cout.width(scientists.searchLongestName());
    cout << "Year of award" << left << endl;
    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "--------";
    }
    cout << endl;
}


