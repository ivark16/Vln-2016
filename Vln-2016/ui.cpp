#include "ui.h"
#include <iostream>
#include <iomanip>

using namespace std;

ui::ui()
{

}

ui::ui(int chooseNumber)
{
    _chooseNumber = chooseNumber;
}

void ui::run()
{
     int chooseNumber;

     cout << "           _______ _______ ______ _______ ______      ______ " << endl;
     cout << "          |   |   |       |   __ \\   |   |   __ \\    |  __  |" << endl;
     cout << "          |       |   -   |    __/   |   |      <    |__    |" << endl;
     cout << "          |___|___|_______|___|  |_______|___|__|    |______|" << endl;
     cout << "------------------------------------------------------------------" << endl;
     cout << "*                      Anna Lara Sigurdardottir                  *" << endl;
     cout << "*                        Brynjar Barkarson                       *"<< endl;
     cout << "*                        Dagmar Loftsdottir                      *" << endl;
     cout << "*                     Gabriela Jona Olafsdottir                  *" << endl;
     cout << "*                       Ivar Orn Kristjansson                    *" << endl;
     cout << "*                          Stefan Hjartarson                     *" << endl;
     cout << "------------------------------------------------------------------" << endl;
     cout << endl;


     bool stillLooping = true;

     while(stillLooping)
     {
         cout << "------------------------------------------------------------------" << endl;
         cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
         cout << "* 1:  Display list of Scientist.         * Y.O.D = year of death *" << endl;
         cout << "* 2:  Display list of Computers.         * Y.O.B = year of birth *" << endl;
         cout << "* 3:  Search for scientist/computers.    * Y.O.A = year of award *" << endl;
         cout << "* 4:  Add new scientist/computers.       *                       *" << endl;
         cout << "* 5:  Delete scientist/computers         *                       *" << endl;
         cout << "* 6:  Quit.                              *                       *" << endl;
         cout << "*----------------------------------------*-----------------------*" << endl;
         cout << "-----------------------------------------------------------------" << endl;
         cout << "Enter number: ";


         bool invalidInput = true;
         while(invalidInput)
         {
                 //cin >> chooseNumber;
             while (!(cin >> chooseNumber))
             {
                 cin.clear();
                 cin.ignore(1000,'\n');
                 cout << "Not valid input, please try again: ";
             }
             if(!((chooseNumber > 0) && (chooseNumber < 7)))
             {
                 cout << "Not valid input, please try again: ";
                 invalidInput = true;

             } else {
                 invalidInput = false;
             }
         }

     //This function sends you (from the number you pick) to the right corresponding case
         switch (chooseNumber)
         {
             case 1:
             {
                int displayScientist;
                 cout << "------------------------------------------------------------------" << endl;
                 cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
                 cout << "* 1:  Display all scientists.            * Y.O.B = year of birth *" << endl;
                 cout << "* 2:  Display in alphabetical order.     * Y.O.D = year of death *" << endl;
                 cout << "* 3:  display all living scientist.      * Y.O.A = year of award *" << endl;
                 cout << "* 4:  Display all dead scientist.        *                       *" << endl;
                 cout << "* 5:  Display in order of birth.         *                       *" << endl;
                 cout << "* 6:  Display in order of death.         *                       *" << endl;
                 cout << "* 7:  Chuck Norris.                      *                       *" << endl;
                 cout << "*----------------------------------------*-----------------------*" << endl;
                 cout << "-----------------------------------------------------------------" << endl;
                 cout << "Enter number: ";

                 bool invalidInput = true;
                 while(invalidInput)
                 {
                     //cin >> displayScientist;
                     //invalidInput = false;
                     while (!(cin >> displayScientist))
                     {
                         cin.clear();
                         cin.ignore(1000,'\n');
                         cout << "Not valid input, please try again: ";
                     }
                     if(!((displayScientist > 0) && (displayScientist < 6)))
                     {
                         cout << "Not valid input, please try again: ";
                         invalidInput = true;

                     } else {
                        invalidInput = false;
                     }
                 }

                 if (displayScientist == 1)
                 {
                     listServices scientists;
                     vector<Scientist> newvector;

                     cout << "***List of all scientists***" << endl;
                     newvector = scientists.displayScientist();
                     //print(scientists);
                     for(unsigned int i = 0 ; i < newvector.size() ; i++)
                     {
                         cout << newvector[i].getFirstName()  << "\t";
                         cout << newvector[i].getLastName() << "\t";
                         cout << newvector[i].getNationality() << "\t";
                         cout << newvector[i].getGender() << "\t";
                         cout << newvector[i].getBirthYear() << "\t";
                         cout << newvector[i].getDeathYear()  << "\t";
                         cout << newvector[i].getAwardYear();
                         cout << endl;

                     }
                     break;
                 }
                 else if(displayScientist == 2)
                 {
                     listServices alphabeticOrder;
                     vector<Scientist> newVector;

                     cout << "***List of all scientist in alphabetic order***" << endl;
                     newVector = alphabeticOrder.scientistInAlphabeticalOrder();
                     for(int i = 0 ; i < newVector.size() ; i++)
                     {
                         cout << newVector[i].getFirstName()  << "\t";
                         cout << newVector[i].getLastName() << "\t";
                         cout << newVector[i].getNationality() << "\t";
                         cout << newVector[i].getGender() << "\t";
                         cout << newVector[i].getBirthYear() << "\t";
                         cout << newVector[i].getDeathYear()  << "\t";
                         cout << newVector[i].getAwardYear();
                         cout << endl;
                     }

                 }
                 else if (displayScientist == 3)
                 {
                     listServices sort;
                     sort.changeTo(sort.sortByName());
                     cout << "A list of scientists in alphabetical order" << endl;
                     //print(sort);
                     //printNames(sort);
                     break;
                 }
                  //This case displays the scientists in an organized list from oldest to youngest
                 else if (displayScientist == 4)
                 {
                     listServices sort;
                     sort.changeTo(sort.sortByBirth());
                     cout << "An organized list starting with the oldest scientist" << endl;
                    // print(_scientist);
                     //printNames(_scientist);
                     break;
                 }
                     //This case organizes the living scientists from oldest to youngest
                 else if (displayScientist == 5)
                 {
                     listServices scientists;
                     string searchTerm;
                     scientists.changeTo(scientists.searchAlive());
                     cout << "An organized list starting with the oldest living scientist" << endl;
                    // print(scientists);
                     //printNames(scientists);
                     break;
                 }
                 else if (displayScientist == 6)
                 {

                     listServices norris;
                     //norris.changeTo(norris.chuckNorris());
                     //print(norris);
                     //printNames(norris);
                     break;
                 }
            }
                break;
            case 2:
            {
                int displayScientist;
                cout << "------------------------------------------------------------------" << endl;
                cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                cout << "* 1:  Display all Computers.             * Y.O.B = year of birth *" << endl;
                cout << "* 2:  display all in alphabetical order  * Y.O.D = year of death *" << endl;
                cout << "* 3:  display all when was built         * Y.O.A = year of award *" << endl;
                cout << "* 4:  display all by type                *                       *" << endl;
                cout << "* 5:  Display if was built               *                       *" << endl;
                cout << "*----------------------------------------*-----------------------*" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                cout << "Enter number: ";

                bool invalidInput = true;
                while(invalidInput)
                {
                    //cin >> displayScientist;
                    //invalidInput = false;
                    while (!(cin >> displayScientist))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Not valid input, please try again: ";
                    }
                    if(!((displayScientist > 0) && (displayScientist < 5)))
                    {
                        cout << "Not valid input, please try again: ";
                        invalidInput = true;

                    }
                    else
                    {
                        invalidInput = false;
                    }
                }

                if (displayScientist == 1)
                {
                    listServices scientists;
                    vector<Computer> newvector;

                    cout << "***List of all computers***" << endl;
                    newvector = scientists.displayComputer();
                    for(unsigned int i = 0 ; i < newvector.size() ; i++)
                    {
                        cout << newvector[i].getComputerName() << "\t";
                        cout << newvector[i].getComputerType() << "\t";
                        cout << newvector[i].getYearOfBuild() << "\t";
                        cout << newvector[i].getWasBuilt();
                        cout << endl;
                    }
                    break;
                }

                else if(displayScientist == 2)
                {
                   listServices scientists;
                   vector<Computer> newvector;

                   cout << "***List of all computers***" << endl;
                   newvector = scientists.displayComputer();
                   for(unsigned int i = 0 ; i < newvector.size() ; i++)
                   {
                       cout << newvector[i].getComputerName() << "\t";
                       cout << newvector[i].getComputerType() << "\t";
                       cout << newvector[i].getYearOfBuild() << "\t";
                       cout << newvector[i].getWasBuilt();
                       cout << endl;
                   }
                }

                else if (displayScientist == 3)
                {
                    listServices sort;
                    sort.changeTo(sort.sortByName());
                    cout << "A list of scientists in alphabetical order" << endl;
                    //print(sort);
                    //printNames(sort);
                    break;
                }

                //This case displays the scientists in an organized list from oldest to youngest
                else if (displayScientist == 4)
                {
                    listServices sort;
                    sort.changeTo(sort.sortByBirth());
                    cout << "An organized list starting with the oldest scientist" << endl;
                    //print(_scientist);
                    //printNames(_scientist);
                    break;
                }
                //This case organizes the living scientists from oldest to youngest
                else if (displayScientist == 5)
                {
                    listServices scientists;
                    string searchTerm;
                    scientists.changeTo(scientists.searchAlive());
                    cout << "An organized list starting with the oldest living scientist" << endl;
                    //print(scientists);
                    //printNames(scientists);
                    break;
                }
            }
                break;
            case 3:
            {

            }
                break;
            case 4:
            {

            }
                break;
            case 5:
            {

            }
            case 6:
            {
                stillLooping = false;
            }
            if(stillLooping)
            {
                string thisDoesNothing;
                cout << "Enter any letter and press enter to continue!";
                cin >> thisDoesNothing;
                for(int i = 0 ; i <= 4 ; i++)
                {
                    for(int j = 0 ; j < 8 ; j++ )
                    {
                        cout << "--------";
                    }
                    cout << endl;
                }
            }
        }
    }
}

/*void ui::print(listServices scientistsToPrint)
{
    int width = scientistsToPrint.searchLongestNameScientist();
     cout.width(5);
     cout << left << "No.";
     cout.width(width);
     cout << "Firstname" << left;
     cout.width(width);
     cout << "Lastname" << left;
     cout.width(10);
     cout << "gender" << left;
     cout.width(width);
     cout << "nation" << left;
     cout.width(10);
     cout << "Y.O.B" << left;
     cout.width(10);
     cout << "Y.O.D" << left;
     cout.width(10);
     cout << "Y.O.A" << left << endl;
     for(int i = 0 ; i < 9 ; i++)
     {
         cout << "---------";
     }
         cout << endl;
}

// This function prints all names in a table to the console
/*void ui::printNames (Scientist scientistsToPrint)
{
    int counter = 1;
    cout << scientistsToPrint.getSizeOfScientistList();
    for(int i = 0; i < scientistsToPrint.getSizeOfScientistList() ; i++)
    {
        string sex;
        string isDead;

        if(scientistsToPrint.getGenderFromListAt(i) == 'm')
        {
            sex = "male";
        }
        else if(scientistsToPrint.getGenderFromListAt(i) == 'f')
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
        int width = scientistsToPrint.searchLongestName();

        //adjusts width to longest name
        cout.width(width);
        cout << scientistsToPrint.getFirstNameFromList(i) << left;
        cout.width(width);
        cout << scientistsToPrint.getLastNameFromList(i) << left;
        cout.width(10);
        cout << sex << left;
        cout.width(width);
        cout << scientistsToPrint.getNationalityFromList(i) << left;
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
        if(scientistsToPrint.getAwardsFromList(i) == 0)
        {
            isDead = "None";
            cout.width(10);
            cout << isDead << left;
        }
        else
        {
            cout.width(10);
            cout << scientistsToPrint.getAwardsFromList(i) << left;
        }
        cout.width(10);
        cout << "   *" << endl;
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "---------";
    }
    cout << endl;

}*/

void ui::printComputers()
{
    listServices print;
    int width = print.searchLongestNameComputer();

    cout.width(5);
    cout << left << "No.";
    cout.width(width);
    cout << "Name" << left;
    cout.width(width);
    cout << "Type" << left;
    cout.width(10);
    cout << "Year built" << left;
    cout.width(width);
    cout << "Was it complete?" << left;

    for(int i = 0; i < 9; i++)
    {
        cout << "--------";
    }
    cout << endl;

}
