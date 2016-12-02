#include "consoleui.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
consoleUI::consoleUI()
{

}
//Constructor
consoleUI::consoleUI(int chooseNumber)
{
    _chooseNumber = chooseNumber;
}


bool consoleUI::digitCheck(int digit)
{
    if(isdigit(digit))
    {
        return true;
    }
    return false;
}

//Function that gives you a list of options to choose from
//It prompts the user for an integer and then references the appropriate case in the switch case included.
void consoleUI::run()
{
    int chooseNumber;

    cout << "           _______ _______ ______ _______ ______      ______ " << endl;
    cout << "          |   |   |       |   __ \\   |   |   __ \\    |  __  |" << endl;
    cout << "          |       |   -   |    __/   |   |      <    |__    |" << endl;
    cout << "          |___|___|_______|___|  |_______|___|__|    |______|" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "*                      Anna Lara Sigurdardottir                  *" << endl;
    cout << "*                        Brynjar Barkarsson                      *"<< endl;
    cout << "*                        Dagmar Loftsdottir                      *" << endl;
    cout << "*                     Gabriela Jona Olfafsdottir                 *" << endl;
    cout << "*                       Ivar Orn Kristjansson                    *" << endl;
    cout << "*                          Stefan Hjartarson                     *" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;


    bool stillLooping = true;

    while(stillLooping)
    {
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display entire list.               * Y.O.D = year of death *" << endl;
    cout << "* 2:  Search by name.                    * Y.O.B = year of birth *"<< endl;
    cout << "* 3:  Search if alive.                   * Y.O.A = year of award *" << endl;
    cout << "* 4:  Sort by award year.                *                       *" << endl;
    cout << "* 5:  Add new scientist.                 *                       *" << endl;
    cout << "* 6:  Search for birth year.             *                       *" << endl;
    cout << "* 7:  Disply list in alphabetical order  *                       *" << endl;
    cout << "* 8:  Sort by birthyear.                 *                       *" << endl;
    cout << "* 9:  Search for Turing award winner.    *                       *" << endl;
    cout << "* 10: Chuck Norris.                      *                       *" << endl;
    cout << "* 11: Delete scientis.                   *                       *" << endl;
    cout << "* 12: Exit.                              *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";

    cin >> chooseNumber;


    if((chooseNumber < 1) || (chooseNumber > 12) || digitCheck(chooseNumber))
    {
        bool invalidInput = true;
        while(invalidInput)
        {
            cout << "Please enter a valid input: ";
            cin >> chooseNumber;
            if(!((chooseNumber < 1) || (chooseNumber > 12) || digitCheck(chooseNumber)))
            {
                invalidInput = false;
            }
        }
    }
    else
    {
    }


    //This function sends you (from the number you pick) to the right corresponding case
    switch (chooseNumber)
    {
        //This case displays a list of all the scientists (that is there full names, dob, dod and year of award)
        case 1:
        {
            listServices scientists;
            cout << "***List of all scientists***" << endl;
            print();
            printNames(scientists);
        }
            break;

        //This case lets you search for a scientist from their name (either the first or last name)
        case 2:
            {
                listServices scientists;
                //listServices searchName2;
                string searchTerm;
                cout << "Enter a single name to search: ";
                cin >> searchTerm;
                scientists.changeTo(_scientist.searchName(searchTerm));
                print();
                printNames(scientists);

            }
            break;

        //This case organizes the living scientists from oldest to youngest
        case 3:
            {
                listServices scientists;
                string searchTerm;
                scientists.changeTo(_scientist.searchAlive());
                cout << "An organized list starting with the oldest living scientist" << endl;
                print();
                printNames(scientists);
             }
              break;

        //This case sorts the scientists by the year they received an award
        case 4:
            {
                listServices scientistsByAward;
                scientistsByAward.changeTo(_scientist.sortByAward());
                cout << "An organized list of scientists in order of when they received the Turing award." << endl;
                print();
                printNames(scientistsByAward);
             }
            break;

        // This case allows the user to add in another scientist (or even create a person - that is not real)
        case 5:
            {
                string firstName;
                string lastName;
                char gender;
                int birthYear;
                char isAlive;
                int deathYear;
                char isWinner;
                int awardYear;
                bool cont = false;
                bool hasOnlyChar = true;


                firstName = nameChecker("first name");
                lastName = nameChecker("last name");
                gender = genderChecker();
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

    //searchBirth
    case 6:
        {
            listServices scientistsBirth;
            CheckNumbers(scientistsBirth);
            //char answear;
            /*do {
                int year;
                //char answear2;
                cout << "Enter year: ";
                while (!(cin >> year))
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Not valid input, please try again: ";
                }

                listServices scientistsBirth;
                scientistsBirth.changeTo(scientistsBirth.searchBirth(year, year));
                if (scientistsBirth.getSize() == 0)
                {
                        cout << "Sorry, no scientists where born this year. Do you wanna input another year (y/n)? ";
                        do {
                           cin >> answear;
                           if (answear == 'y')
                           {
                                break;
                           } else if (answear == 'n')
                           {
                                break;
                           } else {
                               cout << "Not valid input, please try again: ";
                               answear = 'y';
                               break;
                           }
                        } while (answear == 'y');


                } else
                    {
                    cout << "A list of scientists born in your year of choice" << endl;
                    print();
                    printNames(scientistsBirth);
                    answear = 'n';
                    }
                } while (answear == 'y');*/
        }
          break;

    //This case sorts all the scientists by their name in an alpabetical order
    case 7:
    {
        listServices sort;
        sort.changeTo(_scientist.sortByName());
        cout << "A list of scinetists in alphabetical order" << endl;
        print();
        printNames(sort);

    }
        break;

    //This case displays the scientists in an organized list from oldest to youngest
    case 8:
            _scientist.changeTo(_scientist.sortByBirth());
            cout << "An organized list starting with the oldest scientist" << endl;
            print();
            printNames(_scientist);
        break;

    //This case sorts the scientists by the year they recived the Turning Award
    case 9:
            _scientist.changeTo(_scientist.sortByAward());
            cout << "An organized list of scientists in order of when they received a Turing award." << endl;
            print();
            printNames(_scientist);
         break;

    //All the scientist will become infinitely more awesome because this case changes all of their names to Chuck Norris
    case 10:
    {
        listServices norris;
 /* for(int i = 0; i < _scientist.chuckNorris(); i++){
       _scientist.chu
  }*/


        norris.changeTo(_scientist.chuckNorris());
        print();
        printNames(norris);
}
        break;

    case 11:
    {
        //Delete from database
        listServices scientist;
        int ID = 0;
        string name;
        cout << "Enter name: ";
        cin >> name;
        print();
        for(int i = 0 ; i < scientist.getSize();)
        {
            if(name ==  scientist.changeToLower(scientist.getFirstNameFromList(i)) || name == scientist.changeToLower(scientist.getLastNameFromList(i)))
            {
                string sex;
                string isDead;

                if(scientist.getSexFromList(i) == 'm')
                {
                    sex = "male";
                }
                else
                {
                    sex = "female";
                }
                cout.width(5);
                cout << left << i;
                cout.width(10);
                cout << scientist.getFirstNameFromList(i) << left;
                cout.width(10);
                cout << scientist.getLastNameFromList(i) << left;
                cout.width(10);
                cout << sex << left;
                cout.width(10);
                cout << scientist.dobFromList(i) << left;
                if(scientist.dodFromList(i) == 0)
                {
                    isDead = "Alive";
                    cout.width(10);
                    cout << isDead << left;
                }
                else
                {
                    cout.width(10);
                    cout << scientist.dodFromList(i) << left;
                }
                cout.width(10);
                cout << scientist.getAwardsFromList(i) << left;;
                cout << "   *" << endl;



                i++;
            }
            else
            {
                i++;
            }
        }
        for(int i = 0 ; i < 9 ; i++)
        {
            cout << "--------";
        }
        cout << endl;
        cout << "Enter number for scientist you want to delete: ";
        cin >> ID;
        scientist.deleteFromList(ID);
        print();
        printNames(scientist);
        scientist.writeNewFile();
    }
        break;

    case 12:
        stillLooping = false;
        break;
 }

string thisDoesNothing;
cout << "Enter any letter and press enter to continue." << endl;
cin >> thisDoesNothing;
cout << endl << endl << endl << endl;


}


}




string consoleUI::nameChecker(string nameType)
{
    string name;
    bool cont = false;
    bool hasOnlyChar = true;

       while(!cont)
       {
       cout << "Please enter the scientist's " << nameType << ": ";
       cin >> name;
       for(unsigned int i = 0; i < name.length(); i++)
       {
           if(!isalpha(name[i]) && name[i] != '.')
           {
               hasOnlyChar = false;
           }
       }
       if(name.length() <2 || name.length()>16)
          {
           cout <<"Error: Names must be between 2 and 16 characters." << endl;
           }
       else if(!hasOnlyChar)
       {
          cout << "Error: Names can only contain characters from the latin alphabet." << endl;
          hasOnlyChar = true;
       }
       else
       {
          cont = true;
       }
       }

       return name;
}

//prompts the user for
char consoleUI::genderChecker()
{
    bool cont = false;
    string gender;

    while(!cont)
    {
        cout << "Enter the scientist's gender (m/f/o) : " ;
        cin >> gender;

        if(isalpha(gender[0]) && (gender[0] == 'm' || gender[0] == 'f' || gender[0] == 'o') && gender.size() == 1)
        {
            cont = true;
        }
        else
        {
            cout << "Invalid input.  Please enter either 'm' for male or 'f' for female or 'o' for other." << endl;
        }
    }

    return gender[0];
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
    cout << "Y.O.B" << left;
    cout.width(10);
    cout << "Y.O.D" << left;
    cout.width(scientists.searchLongestName());
    cout << "Y.O.A" << left << endl;
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
        else if(scientistsToPrint.getSexFromList(i) == 'f')
        {
            sex = "female";
        }
        else
        {
            sex = "other";
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

void consoleUI::CheckNumbers (listServices checkNumbersForScientist)
{
    char answear;
    do {
        int year;
        cout << "Enter year: ";
        while (!(cin >> year))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Not valid input, please try again: ";
        }
        listServices scientist;
        scientist = checkNumbersForScientist;
        scientist.changeTo(scientist.searchBirth(year, year));
        if (scientist.getSize() == 0)
        {
                cout << "Sorry, no scientists where born this year. Do you wanna input another year (y/n)? ";
                do {
                   cin >> answear;
                   if (answear == 'y')
                   {
                        break;
                   } else if (answear == 'n')
                   {
                        break;
                   } else {
                       cout << "Not valid input, please try again: ";
                       answear = 'y';
                       break;
                   }
                } while (answear == 'y');


        } else
            {
            cout << "A list of scientists born in your year of choice" << endl;
            print();
            printNames(scientist);
            answear = 'n';
            }
        } while (answear == 'y');
}
