#include "ui.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
//#include <curses.h>

using namespace std;

ui::ui()
{

}

ui::ui(int chooseNumber)
{
    _chooseNumber = chooseNumber;
}

//This function is called on in the main function.  It runs the entire program.  Important function.
void ui::run()
{
    //password protects our database
     enterPassword();
     //clears the screen
     if (getenv("windir"))
     {
          system("cls");
     }
     else
     {
         system("clear");
     }

     //Displaying cool group 9 logo and credits.
     headerCase();

     bool stillLooping = true;
     do
     {
         string chooseNumber;
         //Displaying main menu case
         mainMenuCase();
         cin >> chooseNumber;

        //This function sends you (from the number you pick) to the right corresponding case
            if (chooseNumber == "1")
            {
                //Displays scientists (an additional menu is inside)
                caseOneCase();
            }
            else if (chooseNumber == "2")
            {
                //Displays all computers (an additional menu is inside)
                 caseTwoCase();
            }
            else if (chooseNumber == "3")
            {
                //Allows you to search through the database (an additional menu is inside)
                caseThreeCase();
            }

            else if (chooseNumber == "4")
            {
                //To add a scientist
                caseFourCase();
            }
            else if (chooseNumber == "5")
            {
                //Delete a scientist or computer
                caseFiveCase();
            }
            else if (chooseNumber == "6")
            {
                //Edit a scientist or computer
                caseSixMajorCase();
            }
            else if (chooseNumber == "7")
            {
                //Play a fun trivia game
                playGame();
            }
            else if (chooseNumber == "8")
            {
                exit(1);
            }
            else
            {
                cout << "Invalid input, please try again!" << endl;

            }
            //Clears the screen
            if(stillLooping == true && (chooseNumber == "1" || chooseNumber == "2" || chooseNumber == "3" || chooseNumber == "4" || chooseNumber == "5" || chooseNumber == "6"))
            {
                if (getenv("windir"))
                {
                     string thisDoesNothing;
                     cout << "Input anything and than press enter: ";
                     cin >> thisDoesNothing;
                     system("cls");
                }
                else
                {
                    string thisDoesNothing;
                    cout << "Input anything and than press enter. ";
                    cin >> thisDoesNothing;
                    system("clear");
                }
            }
        } while(stillLooping);
}

//This function password protects the entire database against wrongdoers who neglect to read the readme.txt
void ui::enterPassword()
{
    string password;
    cout << "This is a password protected database."  << endl;
    cout << "Please reference the readme.txt file included." << endl;
    cout << "Enter password: ";
    cin >> password;
    if(password != "chuckNorris")
    {
        cout << "Incorrect password." << endl << "Please reference the readme.txt file before attempting to access the database." << endl;
        exit(1);
    }
}

// This function prints all names in a table to the console
void ui::printScientists (vector<Scientist> scientistsToPrint)
{
    int counter = 1;
    for(unsigned int i = 0; i < scientistsToPrint.size(); i++)
    {
        string sex;
        string isDead;
        string bla;

        if(scientistsToPrint[i].getGender() == 'm' || scientistsToPrint[i].getGender() == 'M')
        {
            sex = "male";
        }
        else if(scientistsToPrint[i].getGender() == 'f' || scientistsToPrint[i].getGender() == 'F')
        {
            sex = "female";
        }
        else
        {
            sex = "other";
        }
        cout.width(5);
        cout << left << scientistsToPrint[i].getID();
        counter++;
        int width = _lists.searchLongestNameScientist();

        //adjusts width to longest name
        cout.width(width);
        cout << scientistsToPrint[i].getFirstName() << left;
        cout.width(width);
        cout << scientistsToPrint[i].getLastName() << left;
        cout.width(10);
        cout << sex << left;
        cout.width(width);
        cout << scientistsToPrint[i].getNationality() << left;
        cout.width(10);
        cout << scientistsToPrint[i].getBirthYear() << left;
        if(scientistsToPrint[i].getDeathYear() == 0)
        {
            isDead = "Alive";
            cout.width(10);
            cout << isDead << left;
        }
        else
        {
            cout.width(10);
            cout << scientistsToPrint[i].getDeathYear() << left;
        }
        cout.width(10);
        if(scientistsToPrint[i].getAwardYear() == 0)
        {
            bla = "None";
            cout.width(10);
            cout << bla;
        }
        else
        {
            cout.width(10);
            cout << scientistsToPrint[i].getAwardYear() << left;
        }
        cout.width(10);
        cout << "   *" << endl;
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "---------";
    }
    cout << endl;

}

//Prints all computers in a table.
void ui::printComputers(vector<Computer> computersToPrint)
{
    int counter = 1;
    int width = _lists.searchLongestNameComputer();
    for(unsigned int i = 0; i < computersToPrint.size(); i++)
    {
        string na;
        cout.width(5);
        cout << left << computersToPrint[i].getID();
        counter++;

        //adjusts width to longest name
        cout.width(width);
        cout << computersToPrint[i].getComputerName() << left;
        cout.width(width+3);
        cout << computersToPrint[i].getComputerType() << left;
        cout.width(width);
        int yearBuilt = computersToPrint[i].getYearOfBuild();
        if(yearBuilt == 0)
        {
            na = "N/A ";
            cout << na;
        }
        else
        {
            cout << yearBuilt;
        }
        if (computersToPrint[i].getWasBuilt() == 1)
        {
            cout << "True ";
        }
        else
        {
            cout << "False";
        }
        if (na == "N/A ")
        {
            cout << "     *" << endl;
        }
        else
        {
            cout << "      *" << endl;
        }
    }

    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "---------";
    }
    cout << endl;
}

//Prints connections between computers and scientists in a table
void ui::printJoin(vector<searching> joinToPrint)
{
    int counter = 1;
    int width;
    //adjust width to longest name
    int widthSci = _lists.searchLongestNameScientist();
    int widthCom = _lists.searchLongestNameComputer();
    if (widthSci < widthCom)
    {
        width = widthCom;
    }
    else
    {
        width = widthSci;
    }

    for(unsigned int i = 0; i < joinToPrint.size(); i++)
    {
        string na;
        cout.width(15);
        counter++;
        cout << joinToPrint[i].getSearchFirstName() << left;
        cout.width(width-10);
        cout << joinToPrint[i].getSearchLastName() << left;
        cout.width(width-12);
        cout << joinToPrint[i].getSearchComputerName() << left;
        cout.width(width);
        cout << joinToPrint[i].getSearchComputerType() << left;
        cout.width(width);
        cout << joinToPrint[i].getSearchYearBuilt() << left << "    *";
        cout.width(width);

        int yearBuilt = joinToPrint[i].getSearchYearBuilt();
        if(yearBuilt == 0)
        {
            na = "N/A ";
            cout << na;
        }
        cout << endl;
    }
        cout << "---------------------------------------------------------------------------------";
    cout << endl;
}
//prints a header for scientist prints
void ui::printS()
{
    int width = _lists.searchLongestNameScientist();

    cout.width(5);
    cout << left << "No.";
    cout.width(width);
    cout << "First name" << left;
    cout.width(width);
    cout << "Last name" << left;
    cout.width(width-3);
    cout << "Gender" << left;
    cout.width(width+2);
    cout << "Nationality" << left;
    cout.width(width-2);
    cout << "Y.O.B." << left;
    cout.width(width);
    cout << "Y.O.D." << left;
    cout.width(width);
    cout << "Y.O.A." << endl;

    for(int i = 0; i < 9; i++)
    {
        cout << "---------";
    }
    cout << endl;
}
//prints a header for computer prints
void ui::printC()
{
    int width = _lists.searchLongestNameComputer();

    cout.width(5);
    cout << left << "ID";
    cout.width(width+2);
    cout << "Name" << left;
    cout.width(width);
    cout << "Type" << left;
    cout.width(width);
    cout << "Y.O.B." << left;
    cout.width(width);
    cout << "Was built?";
    cout << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << "---------";
    }
    cout << endl;
}
//Prints a header for the join table.
void ui::printConnection()
{
    int width = _lists.searchLongestNameScientist();

    cout.width(13);
    cout << left << "First name" << left;
    cout.width(width+2);
    cout << "Last name" << left;
    cout.width(width+3);
    cout << "N.O.C." << left;
    cout.width(width+5);
    cout << "T.O.C.";
    cout.width(width);
    cout << "Y.O.B";
    cout << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << "---------";
    }
    cout << endl;
}


//this is an error check.  It checks the validity of the name and prompts the user for a new one until one is valid.
string ui::nameChecker(string nameType)
{
    string name;
    bool cont = false;
    bool hasOnlyChar = true;

       while(!cont)
       {
       cout << "Please enter the scientist's " << nameType << ": ";
       cin >> name;
       //check whether it has anything that is a non-alphabet character in it.  If so, it is an invalid entry.
       for(unsigned int i = 0; i < name.length(); i++)
       {
           if(!isalpha(name[i]) && name[i] != '.')
           {
               hasOnlyChar = false;
           }
       }
       //the length must be between 2 and 16 for it to be valid.
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
       //returnName = name;
       name[0] = toupper(name[0]);
       return name;
}

//This function prompts the user for a name, then checks
string ui::computerNameChecker()
{
    string name;
    bool cont = false;
       while(!cont)
       {
       cout << "Please enter the computer's name: ";
       cin >> name;
       //the length must be between 2 and 20 for it to be valid.
       if(name.length() <2 || name.length()>20)
          {
              cout <<"Error: Names must be between 2 and 20 characters." << endl;
           }
       else
       {
          cont = true;
       }
       }
       name[0] = toupper(name[0]);
       return name;
}

//error check for when a computer is added.  it checks the type.
string ui::computerTypeChecker()
{
    string name;
    bool cont = false;
       while(!cont)
       {
       cout << "Please enter the computer's type: ";
       cin >> name;
       //the length must be between 2 and 20 for it to be valid.
       if(name.length() <2 || name.length()>20)
          {
             cout <<"Error: Names must be between 2 and 20 characters." << endl;
           }
       else
       {
          cont = true;
       }
       }
       name[0] = toupper(name[0]);
       return name;
}

//prompts the user for a gender and checks its validity.  If it is invalid it asks again until it receives a valid gender.
char ui::genderChecker()
{
    bool cont = false;
    string gender;

    while(!cont)
    {
        cout << "Enter the scientist's gender (m/f/o) : " ;
        cin >> gender;
        //checks that the entry is only a single character, that is either m, f or o
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

//This function checks whether years are valid.
int ui::yearChecker(const int TYPE, int birthYear, int deathYear)
{
    int year;
    bool cont = true;

    while(cont)
    {
        if(TYPE == 1)
        {
        cout << "Please enter the scientists birth year: ";
        }
        else if(TYPE == 2)
        {
        cout << "Please enter the scientists year of death: ";
        }
        else if(TYPE == 3)
        {
        cout << "Please enter the year the scientist won the award: ";
        }
        else if (TYPE == 4)
        {
          cout << "Please insert second year: ";
        }
        else if (TYPE == 5)
        {
          cout << "Please enter the year the computer was designed: ";
        }
        //This loops until there is a valid input from the user, it ignores up to 1000 things.
        while (!(cin >> year))
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "Not valid input, please try again: ";
        }
        //The TYPE is used to denote whether you are looking for a birth year, death year or a turing award year.
        if(TYPE == 1 && (year < 1791 || year > 2016))
        {
          cout << "Invalid year." << endl;
        }
        else if(TYPE == 2 && (year >2016 || year<1791 || year <= birthYear))
        {
          cout << "Invalid year." << endl;
        }
        else if(TYPE == 3 && (year <1966 || year > 2016 || year < birthYear || (year > deathYear && deathYear != 0)))
        {
          cout << "Invalid year." << endl;
        }
        else if (TYPE == 4 && (birthYear > year))
        {
          cout << "Invalid year." << endl;
        }
        else if (TYPE == 5 && (year < 1822 || year > 2016))
        {
          cout << "Invalid year." << endl;
        }
        else
        {
          //end the loop and return the year.
          //this happens when the input is valid.
          cont = false;

        }
    }
    return year;
}

//gets valid yes-or-no input from the user
bool ui::boolChecker()
{
    string input;
    cout << "Please enter either 'yes' or 'no" << endl;
    while(true)
    {
        cin >> input;
        if(input == "yes" || input == "Yes")
        {
            return true;
            break;
        }
        else if(input == "no" || input == "No")
        {
            return false;
            break;
        }
        else
        {
            cout << "invalid input, please enter either 'yes' or 'no" << endl;
        }
    }
}

//checks the validity of the nationality.
string ui::nationalityChecker()
{
    string nationality;
    bool cont = false;
    bool hasOnlyChar = true;

       while(!cont)
       {
       cout << "Please enter the scientist's nationality: ";
       cin >> nationality;
       for(unsigned int i = 0; i < nationality.length(); i++)
       {
           if(!isalpha(nationality[i]) && nationality[i] != '.')
           {
               hasOnlyChar = false;
           }
       }
       if(nationality.length() <5 || nationality.length()>16)
          {
           cout <<"Error: Nationalities must be between 5 and 16 characters." << endl;
           }
       else if(!hasOnlyChar)
       {
          cout << "Error: Nationalities can only contain characters from the latin alphabet." << endl;
          hasOnlyChar = true;
       }
       else
       {
          cont = true;
       }
    }

       return nationality;
}
//Prints a header and credits.
void ui::headerCase()
{
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
}

//prints our main menu
void ui::mainMenuCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*-----------------------*" << endl;
    cout << "* 1:  Display list of Scientist.         *                       *" << endl;
    cout << "* 2:  Display list of Computers.         *                       *" << endl;
    cout << "* 3:  Search for scientist/computers.    *                       *" << endl;
    cout << "* 4:  Add new scientist/computers.       *                       *" << endl;
    cout << "* 5:  Delete scientist/computers         *                       *" << endl;
    cout << "* 6:  Edit scientist/computers           *                       *" << endl;
    cout << "* 7:  Lets play a game                   *                       *" << endl;
    cout << "* 8:  Quit.                              *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

//Displays scientists
void ui::caseOneCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display all scientists.            * Y.O.B = year of birth *" << endl;
    cout << "* 2:  Display in alphabetical order.     * Y.O.D = year of death *" << endl;
    cout << "* 3:  display all living scientist.      * Y.O.A = year of award *" << endl;
    cout << "* 4:  Display all dead scientist.        *                       *" << endl;
    cout << "* 5:  Display in order of birth.         *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";

    string displayScientist;
    do
    {
        cin >> displayScientist;

        // Displays all scientists
        if (displayScientist == "1")
        {
            vector<Scientist> newvector;
            cout << "***List of all scientists***" << endl;
            newvector = _lists.displayScientist();
            printS();
            printScientists(newvector);
            break;
        }

        //Displays all scientists in alphabetical order
        else if(displayScientist == "2")
        {
            string numb;
            vector<Scientist> newVector;
            do
            {
                cout << "Enter 1 for ascending order or 2 for descending order: ";
                cin >> numb;
                //prints scientists in ascending order
                if(numb == "1")
                {
                    newVector = _lists.scientistInAlphabeticalOrder();
                    cout << "***List of all scientist in alphabetic order***" << endl;
                    printS();
                    printScientists(newVector);
                    break;
                }
                //prints them in descending order
                else if(numb == "2")
                {
                    newVector = _lists.scientistInReverseAlphabeticalOrder();
                    printS();
                    printScientists(newVector);
                    break;
                }
                else
                {
                    cout << "Invalid input, please try again! " << endl;
                }
            } while (numb != "1" || numb != "2");
            break;
        }
        //prints only living scientists
        else if (displayScientist == "3")
        {
            vector<Scientist> living;

            cout << "***List of all living scientists***" << endl;
            living = _lists.searchAliveScientist();
            printS();
            printScientists(living);
            break;
        }
        //prints all dead scientists
        else if (displayScientist == "4")
        {
           vector<Scientist> dead;
           cout << "***List of all dead scientists***" << endl;
           dead = _lists.searchDeadScientist();
           printS();
           printScientists(dead);
           break;
        }
        //This case organizes the living scientists from oldest to youngest
        else if (displayScientist == "5")
        {
            string numb;
            vector<Scientist> order;
            do
            {
                cout << "choose 1 for order of youngest or 2 for order of oldest: ";
                cin >> numb;
                //prints them in ascending order of age
                if(numb == "1")
                {
                    order = _lists.youngestOrderScientist();
                    printS();
                    printScientists(order);
                    break;
                }
                //prints them in descending order of age
                else if (numb == "2")
                {
                    order = _lists.oldestOrderScientist();
                    printS();
                    printScientists(order);
                    break;
                }
                else
                {
                    cout << "Invalid input, please try again! " << endl;
                }
            } while (numb != "1" || numb != "2");
            break;
        }
        else
        {
            cout << "Invalid input, please try again! " << endl;
        }
    } while (displayScientist != "1" || displayScientist != "2" || displayScientist != "3" || displayScientist != "4" || displayScientist != "5" || displayScientist != "6");


}


//Displays all computers
void ui::caseTwoCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display all Computers.             *                       *" << endl;
    cout << "* 2:  display all in alphabetical order. *                       *" << endl;
    cout << "* 3:  display all when was built.        *                       *" << endl;
    cout << "* 4:  Display if was built.              *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";
    string displayScientist;

    //printing menu for caseTwoCase
    do
    {
        cin >> displayScientist;
        //displays all computers in whatever order they are in in the databse
        if (displayScientist == "1")
        {
            vector<Computer> newvector;

            cout << "***List of all computers***" << endl;
            newvector = _lists.displayComputer();
            printC();
            printComputers(newvector);
            break;
        }
        //displays computers in alphabetic order
        else if(displayScientist == "2")
        {
            vector<Computer> newvector;
            string numb;
            do
            {
                cout << "Enter 1 for list in ascending order or 2 for descending order: ";
                cin >> numb;
                //displays computers in alphabetic order
                if(numb == "1")
                {
                    newvector = _lists.computerInAlphabeticalOrder();
                    cout << "***List of computer in alphabetical order***" << endl;
                    printC();
                    printComputers(newvector);
                    break;
                }
                //display computers in reverse alphabetic order
                else if(numb == "2")
                {
                    newvector = _lists.computerInReverseAlphabeticalOrder();
                    cout << "***List of computer in reverse alphabetical order***" << endl;
                    printC();
                    printComputers(newvector);
                    break;
                }
                else
                {
                    cout << "Invalid input, please try again! " << endl;
                }
            }while (numb != "1" || numb != "2");
            break;
        }
        //displays computers in order of when they were built.
        else if (displayScientist == "3")
        {
            string numb;
            vector<Computer> yearOfBuild;
            do
            {
                cout << "***List of build year***" << endl;
                cout << "Enter 1 for order of youngest or 2 for oldest: ";
                cin >> numb;
                //displays them from youngest to oldest
                if(numb == "1")
                {
                    yearOfBuild = _lists.youngestOrderComputer();
                    printC();
                    printComputers(yearOfBuild);
                    break;
                }
                //displays them from oldest to youngest
                else if(numb == "2")
                {
                    yearOfBuild = _lists.oldestOrderComputer();
                    printC();
                    printComputers(yearOfBuild);
                    break;
                }
                else
                {
                    cout << "Invalid input, please try again!" << endl;
                }
            } while(numb != "1" || numb != "2");
            break;
        }

        //This case displays if the computer was built or not
        else if (displayScientist == "4")
        {
            string numb;
            vector<Computer> built;
            do
            {
                cout << "Enter 1 for list of computers that were built or 2 for not built: ";
                cin >> numb;
                //displays ones that were built
                if(numb == "1")
                {
                    built = _lists.myComputerWasBuilt();
                    printC();
                    printComputers(built);
                    break;
                }
                //displays ones that werent
                else if(numb == "2")
                {
                    built = _lists.myComputerWasNotBuilt();
                    printC();
                    printComputers(built);
                    break;
                }
                else
                {
                    cout << "Invalid input, please try again!" << endl;
                }
            } while (numb != "1" || numb != "2");
            break;
        }
    } while (displayScientist != "1" || displayScientist != "2" || displayScientist != "3" || displayScientist != "4");
}

//This function allows you to search the databse
void ui::caseThreeCase()
{

    //Search for a scientist or computers.  It first prints a
       int searchScientistOrComputers;
       cout << "------------------------------------------------------------------" << endl;
       cout << "*------ Database for Computers ----------*-----------------------*" << endl;
       cout << "* 1:  Search scientist.                  *                       *" << endl;
       cout << "* 2:  Search computers.                  *                       *" << endl;
       cout << "* 3:  Search connections.                *                       *" << endl;
       cout << "*----------------------------------------*-----------------------*" << endl;
       cout << "------------------------------------------------------------------" << endl;
       cout << "Enter number: ";

     bool invalidInput = true;
     while(invalidInput)
     {
         while (!(cin >> searchScientistOrComputers))
         {
             cin.clear();
             cin.ignore(1000,'\n');
             cout << "Not valid input, please try again: ";
         }
         if(!((searchScientistOrComputers > 0) && (searchScientistOrComputers < 4)))
         {
             cout << "Not valid input, please try again: ";
             invalidInput = true;
         }
         else
         {
             invalidInput = false;
         }
     }

     if(searchScientistOrComputers == 1)
     {
         //searches scientists
           searchScientist();
     }

     if(searchScientistOrComputers == 2)
     {
         //searhces computers
           searchComputers();
     }
     if(searchScientistOrComputers == 3)
     {
         //searches connections
           searchConnections();
     }
}

//This is used to add new scientists, comptuers and connections to the database.
void ui::caseFourCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*-----------------------*" << endl;
    cout << "* 1:  Add a scientist.                   *                       *" << endl;
    cout << "* 2:  Add a computer.                    *                       *" << endl;
    cout << "* 3:  Add a connection                   *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";

     int addScientistOrComputer;
     bool invalidInput = true;
     while(invalidInput)
     {
         while (!(cin >> addScientistOrComputer))
         {
             cin.clear();
             cin.ignore(1000,'\n');
             cout << "Not valid input, please try again: ";
         }
         if(!((addScientistOrComputer > 0) && (addScientistOrComputer < 4)))
         {
             cout << "Not valid input, please try again: ";
             invalidInput = true;
         }
         else
             {
                 invalidInput = false;
             }
         }

         if(addScientistOrComputer == 1)
         {
             //add a scientist
            addScientist();
         }
         if(addScientistOrComputer == 2)
         {
             //add a computer
            addComputer();
         }
         if(addScientistOrComputer == 3)
         {
             //add a connection
             addConnection();
         }

}

//This deletes a scientist or a computer from the database
void ui::caseFiveCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*-----------------------*" << endl;
    cout << "* 1:  Delete a scientist.                *                       *" << endl;
    cout << "* 2:  Delete a computer.                 *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";

    int deleteScientistOrComputer;
    bool invalidInput = true;
    while(invalidInput)
    {
        while (!(cin >> deleteScientistOrComputer))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Not valid input, please try again: ";
        }
        if(!((deleteScientistOrComputer > 0) && (deleteScientistOrComputer < 3)))
        {
            cout << "Not valid input, please try again: ";
            invalidInput = true;
        }
        else
        {
            invalidInput = false;
        }
    }

    if(deleteScientistOrComputer == 1)
    {
        string scientName;
        vector<Scientist> ceckForDeleteS;
        int idDelete;
        cout << "Enter name for scientist you want to delete: ";
        cin >> scientName;
        ceckForDeleteS = _lists.searchForName(scientName);
        printS();
        printScientists(ceckForDeleteS);
        cout << "Enter id for scientist to delete" << endl;
        cin >> idDelete;
        _lists.deleteScientistFromDatabase(idDelete);
    }

    if(deleteScientistOrComputer == 2)
    {
           //DELETE COMPUTER
        string compName;
        vector<Computer> checkForDeleteC;
        cout << "Enter name for computer u want to delete";
        cin >> compName;
        checkForDeleteC = _lists.searchForNameComputer(compName);
        printC();
        printComputers(checkForDeleteC);
        int idDelete;
        cout << "Enter id for computer to delete" << endl;
        cin >> idDelete;
        _lists.deleteComputerFromDatabase(idDelete);
    }

}

void ui::caseSixCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*-----------------------*" << endl;
    cout << "* 1:  Edit a scientist.                  *                       *" << endl;
    cout << "* 2:  Edit a computer.                   *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";

}
void ui::searchScientist()
{

    //searchScientist()
      int searchScientist;
      cout << "------------------------------------------------------------------" << endl;
      cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
      cout << "* 1:  Search for birth year.             *                       *" << endl;
      cout << "* 2:  Search for name.                   *                       *"<< endl;
      cout << "* 3:  search for Turing awards.          *                       *" << endl;
      cout << "*----------------------------------------*-----------------------*" << endl;
      cout << "-----------------------------------------------------------------" << endl;
      cout << "Enter number: ";

      bool invalidInput = true;
      while(invalidInput)
      {
             while (!(cin >> searchScientist))
             {
                 cin.clear();
                 cin.ignore(1000,'\n');
                 cout << "Not valid input, please try again: ";
             }
             if(!((searchScientist > 0) && (searchScientist < 4)))
             {
                 cout << "Not valid input, please try again: ";
                 invalidInput = true;

             }
             else
             {
                 invalidInput = false;
             }
      }

         //this case allows you to search for scientists using birth years.
         if (searchScientist == 1)
         {
             searchScientistByBirthYear();
         }


         //This case lets you search for a scientist from their name (either the first or last name)
         else if (searchScientist == 2)
         {
             searchScientistByName();
         }

         //This case sorts the scientists by the year they recived the Turning Award
         else if (searchScientist == 3)
         {
             searchScientistByAward();
         }
    }

//Is called by the searchScientist function and searches for either a single year or a range of years.
void ui::searchScientistByBirthYear()
{

    int rangeOrSingle;
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Search for a single year.          * Y.O.D = year of death *" << endl;
    cout << "* 2:  Search for a range.                * Y.O.B = year of birth *"<< endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";

    bool invalidInput = true;
    while(invalidInput)
    {
        while (!(cin >> rangeOrSingle))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Not valid input, please try again: ";
        }
        if(!((rangeOrSingle > 0) && (rangeOrSingle < 3)))
        {
            cout << "Not valid input, please try again: ";
            invalidInput = true;
        }
        else
        {
            invalidInput = false;
        }
   }
   vector<Scientist> searchResults;
   if(rangeOrSingle == 1)
   {
       int yearToCheck = yearChecker(1,0,0);
       searchResults = _lists.checkBirthYear(yearToCheck);
       printS();
       printScientists(searchResults);
   }
   else if(rangeOrSingle == 2)
   {
       int minYear = yearChecker(1,0,0);
       int maxYear = yearChecker(4,minYear,0);
       searchResults = _lists.checkRangeBirthYear(minYear, maxYear);
       printS();
       printScientists(searchResults);
   }
}

void ui::searchScientistByName()
{

    string searchTerm;
    cout << "Enter a single name to search: ";
    cin >> searchTerm;
    vector<Scientist> nameSearch = _lists.checkName(searchTerm);
    if (nameSearch.size() == 0)
    {
        if(searchTerm == "bird" || searchTerm == "Bird")
        {
            printBird();
        }
        else
        {
        printS();
        cout << "Person is not in database!" << endl;
        cout << "-------------------------------------------------------------" << endl;
        }
    }
    else
    {
        printS();
        printScientists(nameSearch);
    }
}

void ui::searchScientistByAward()
{

}

//Search for computers.
void ui::searchComputers()
{
 int searchComputers;
 cout << "------------------------------------------------------------------" << endl;
 cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
 cout << "* 1:  Search for name.                   *                       *" << endl;
 cout << "* 2:  Search for type.                   *                       *" << endl;
 cout << "* 3:  Search for year of creation.       *                       *" << endl;
 cout << "*----------------------------------------*-----------------------*" << endl;
 cout << "------------------------------------------------------------------" << endl;
 cout << "Enter number: ";

 bool invalidInput = true;
 while(invalidInput)
 {
    while (!(cin >> searchComputers))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Not valid input, please try again: ";
    }
    if(!((searchComputers > 0) && (searchComputers < 4)))
    {
        cout << "Not valid input, please try again: ";
        invalidInput = true;
    }
    else
    {
        invalidInput = false;
    }
 }
 vector<Computer> searchResults;

    if(searchComputers == 1)
    {
        string searchTerm;
        cout << "Enter a single name to search: ";
        cin >> searchTerm;
        searchResults = _lists.searchForNameComputer(searchTerm);
        printC();
        printComputers(searchResults);
    }
    else if(searchComputers == 2)
    {
        cout << "Enter a type to search: ";
        string type;
        cin >> type;
        searchResults = _lists.searchForTypeComputer(type);
        printC();
        printComputers(searchResults);
    }
        else if(searchComputers == 3)
        {
        //Search for computers.
        int searchComputers;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "*------ Database for Computers --------*---------Glossary----------*" << endl;
        cout << "* 1:  Search for a single year.        *  N.O.C.= Name of computer *" << endl;
        cout << "* 2:  Search a range of years.         *  T.O.C.= Type of computer *" << endl;
        cout << "* 2:                                   *  Y.O.C.= Year of creation *" << endl;
        cout << "*--------------------------------------*---------------------------*" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number: ";

        bool invalidInput = true;
        while(invalidInput)
    {
    while (!(cin >> searchComputers))
    {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Not valid input, please try again: ";
        }
        if(!((searchComputers > 0) && (searchComputers < 3)))
        {
             cout << "Not valid input, please try again: ";
             invalidInput = true;
        }
        else
        {
             invalidInput = false;
        }
    }
    if(searchComputers == 1)
    {
        cout << "Enter a single year to search: ";
        int year;
        cin >> year;
        searchResults = _lists.searchWhenBuiltSingleYear(year);
        printC();
        printComputers(searchResults);
    }
    else if(searchComputers == 2)
    {
     cout << "Enter the lower bound (a year): ";
     int year1;
     cin >> year1;
     cout << "Enter the upper bound (a year): ";
     int year2;
     cin >> year2;
     searchResults = _lists.searchWhenBuiltRange(year1, year2);
     printC();
     printComputers(searchResults);
    }
    }
}

void ui::searchConnections()
{
    //Search for connections.
     int searchC;
     cout << "------------------------------------------------------------------" << endl;
     cout << "*------ Database for Connections ----*---------------------------*" << endl;
     cout << "* 1:  Search by scientist.           *                           *" << endl;
     cout << "* 2:  Search by computer.            *                           *" << endl;
     cout << "*                                    *                           *" << endl;
     cout << "*------------------------------------*---------------------------*" << endl;
     cout << "------------------------------------------------------------------" << endl;
     cout << "Enter number: ";

     bool invalidInput = true;
     while(invalidInput)
     {
        while (!(cin >> searchC))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Not valid input, please try again: ";
        }
        if(!((searchC > 0) && (searchC < 3)))
        {
            cout << "Not valid input, please try again: ";
            invalidInput = true;
        }
        else
        {
            invalidInput = false;
        }
     }
     vector<searching> connections;
     if(searchC == 1)
     {
         string searchTerm;
         cout << "Enter a single name to search: ";
         cin >> searchTerm;
         connections = _lists.displaySearchJoinScientistName(searchTerm);
         printConnection();
         if (connections.size() == 0)
         {
             cout << "No connection in database!" << endl;
         }
         else
         {
            printJoin(connections);
         }

     }
     else if(searchC == 2)
     {
         string searchTerm;
         cout << "Enter a single name to search: ";
         cin >> searchTerm;
         connections = _lists.displaySearchJoinComputerName(searchTerm);
         printConnection();
         if (connections.size() == 0)
         {
             cout << "No connection in database!" << endl;
         }
         else
         {
            printJoin(connections);
         }
     }
}

//This function is for the bird easter egg.  When you search for "bird" or "Bird" the console will display a bird.
void ui::printBird()
{
    cout << endl << endl << endl << endl;
    cout << "      __ _             _ __        __ _   " << endl;
    cout << "     /  ('>-         -<')  \\      /  ('>- " << endl;
    cout << "     \\__/               \\__/      \\__/    " << endl;
    cout << "      L\\_               _/I        L\\_    " << endl;
    cout << "Unfortunately, there are no bird scientists." << endl;
}

void ui::addScientist()
{
    int id = 0;
    string firstName;
    string lastName;
    char gender;
    string nationality;
    int birthYear;
    char isAlive;
    int deathYear;
    char isWinner;
    int awardYear;

    firstName = nameChecker("first name");
    lastName = nameChecker("last name");
    gender = genderChecker();
    nationality = nationalityChecker();
    birthYear = yearChecker(1, 0, 0);
    cout << "Is the scientist still alive? (y/n) ";
    cin >> isAlive;
    if(isAlive == 'n')
    {
        deathYear = yearChecker(2, birthYear, 0);
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
       awardYear = yearChecker(3, birthYear, deathYear);
    }
    else if(isWinner == 'n')
    {
        awardYear = 0;
    }
    else
    {
        cout << "Invalid entry.  Please enter either y (yes) or n (no)";
    }
    Scientist newScientist(id, firstName, lastName, gender, nationality, birthYear, deathYear, awardYear);
    _lists.addScientistToDatabase(newScientist);
}

void ui::addComputer()
{
    int id = 0;
    string name = computerNameChecker();
    string type = computerTypeChecker();
    int YOB = yearChecker(5,0,0);
    bool wasBuilt = boolChecker();
   // cout << "Enter all relevant information (temporary until checks have been amended)" << endl;
   // cin >> name >> type >> YOB >> wasBuilt;


    Computer newComputer(id, name, type, YOB, wasBuilt);
    _lists.addComputerToDatabase(newComputer);
}

void ui::addConnection()
{
    bool checkerS = false;
    bool checkerC = false;
    vector<Scientist> cs;
    vector<Computer> cc;
    cs = _lists.displayScientist();
    cc = _lists.displayComputer();
    int scientistId;
    int computerId;
    printS();
    //displays all scientists
    printScientists(_lists.displayScientist());
    cout << "Enter the ID of the scientist you want to connect: " << endl;
    while(!(cin >> scientistId))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input, please try again!" << endl;
    }
    printC();
    //displays all computers
    printComputers(_lists.displayComputer());
    cout << "Enter the ID of the computer you want to connect:" << endl;
    while(!(cin >> computerId))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input, please try again!" << endl;
    }
    for(unsigned int i = 0 ; i < cs.size(); i++)
    {
        if(scientistId == cs[i].getID())
        {
            checkerS = true;
        }
    }
    for(unsigned int i = 0; i < cc.size() ; i++)
    {
        if(computerId == cc[i].getID())
        {
            checkerC = true;
        }
    }
    if(checkerS == true && checkerC == true)
    {
        connection newConnection(scientistId, computerId);
        _lists.addConnectionToDatabase(newConnection);
    }
    else
    {
        cout << "*ERROR* scientist or computer not found!" << endl;
    }
}

void ui::caseSixMajorCase()
{
    string input;
    int counter;
    do
    {
        caseSixCase();
        cin >> input;

        if (input == "1")
        {
            string name;
            bool check;
            bool check2;
            int id;
            vector<Scientist> editScientist;
            do
            {
                cout << "Please insert name of scientist you want to edit: ";
                cin >> name;
                editScientist = _lists.searchForName(name);

                if (editScientist.size() == 0)
                {
                    string answear;
                    cout << "No sientist in database! Do you want to continue? (y/n)";
                    cin >> answear;
                    if (answear == "y" || answear == "Y")
                    {
                        check2 = false;
                    }
                    else
                    {
                        counter = 1;
                        check2 = true;
                    }

                }
                else
                {
                    check2 = true;
                }
            }while (check2 == false);
            if (counter == 1)
            {
                break;
            }
            do
            {
                bool check3;
                printS();
                printScientists(editScientist);
                cout << "Enter ID of scientist you want to edit: ";
                cin >> id;
                for (unsigned int i = 0; i < editScientist.size(); i++)
                {
                    if(editScientist[i].getID() == id)
                    {
                        check3 = true;
                        break;
                    }
                    else
                    {
                        check3 = false;
                    }
                }
                if (check3 == false)
                {
                    cout << "Invalid ID, no scientist has this ID." << endl;
                    break;
                }
                cout << "Please insert what you would like to edit (example: insert firstname to edit Scientists firstname): ";
                cin >> name;
                if (name == "firstname" || name == "firstName")
                {
                    string firstname;
                    cout << "Input new first name: ";
                    cin >> firstname;
                    firstname[0] = toupper(firstname[0]);
                    if (_lists.updateFirstNameScientist(firstname, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "lastname" || name == "lastName")
                {
                    string lastname;
                    cout << "Input new last name: ";
                    cin >> lastname;
                    lastname[0] = toupper(lastname[0]);
                    if (_lists.updateLastNameScientist(lastname, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "gender" || name == "Gender")
                {
                    char sex;
                    bool check;
                    do
                    {
                        cout << "Input new gender: ";
                        cin >> sex;
                        if (sex != 'm' && sex != 'M' && sex != 'f' && sex != 'F' && sex != 'o' && sex != 'O')
                        {
                            cout << "Invalid input, input can only be m, f and o. Please try agian!" << endl;
                            check = true;
                        }
                        else
                        {
                            check = false;
                        }
                    }while (check == true);

                    sex = toupper(sex);
                    if (_lists.updateGenderScientist(sex, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    //break;
                }
                else if (name == "nationality" || name == "Nationality")
                {
                    string nationality;
                    cout << "Input new nationality: ";
                    cin >> nationality;
                    nationality[0] = toupper(nationality[0]);
                    if (_lists.updateNationalityScientist(nationality, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "yob" || name == "YOB")
                {
                    int yob;
                    cout << "Input new year of birth: ";
                    while(!(cin >> yob))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid input, please try again!" << endl;
                    }
                    if (_lists.updateYOBScientist(yob, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "yod" || name == "YOD")
                {
                    int yod;
                    cout << "Input new year of death: ";
                    while(!(cin >> yod))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid input, please try again!" << endl;
                    }
                    if (_lists.updateYODScientist(yod, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "yoa" || name == "YOA")
                {
                    int yoa;
                    cout << "Input new year of award: ";
                    while(!(cin >> yoa))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid input, please try again!" << endl;
                    }
                    if (_lists.updateYOAScientist(yoa, id))
                    {
                        cout << "Person edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else
                {
                    cout << endl << "Invalid input, please try again" << endl;
                    cout << "Valid inputs are: firstname, lastname, gender, Nationality, YOB, YOD, YOA" << endl << endl;
                    check = false;
                }
            }while (check == false);
            break;
        }
        else if (input == "2")
        {
            string name;
            bool check;
            bool check2;
            int id;
            vector<Computer> editScientist;
            do
            {
                cout << "Please insert name of computer you want to edit: ";
                cin >> name;
                editScientist = _lists.searchForNameComputer(name);
                cout << editScientist.size() << endl;
                if (editScientist.size() == 0)
                {
                    string answear;
                    cout << "No computer in database! Do you want to continue? (y/n)";
                    cin >> answear;
                    if (answear == "y" || answear == "Y")
                    {
                        check2 = false;
                    }
                    else
                    {
                        counter = 1;
                        check2 = true;
                    }
                }
                else
                {
                    check2 = true;
                }
            }while (check2 == false);
            if (counter == 1)
            {
                //break;
            }
            do
            {
                bool check3;
                printC();
                printComputers(editScientist);
                cout << "Enter ID of computer you want to edit: ";
                cin >> id;
                for (unsigned int i = 0; i < editScientist.size(); i++)
                {
                    if(editScientist[i].getID() == id)
                    {
                        check3 = true;
                        break;
                    }
                    else
                    {
                        check3 = false;
                    }
                }
                if (check3 == false)
                {
                    cout << "Invalid ID, no computer has this ID." << endl;
                    break;
                }
                cout << "Please insert what you would like to edit (example: insert name to edit Computers name): ";
                cin >> name;
                if (name == "name" || name == "Name")
                {
                    string name;
                    cout << "Input new name: ";
                    cin >> name;
                    name[0] = toupper(name[0]);
                    if (_lists.updateNameComputer(name, id))
                    {
                        cout << "Computer edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "type" || name == "Type")
                {
                    string type;
                    cout << "Input new type: ";
                    cin >> type;
                    type[0] = toupper(type[0]);
                    if (_lists.updateTypeComputer(type, id))
                    {
                        cout << "Computer edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "yoc" || name == "YOC")
                {
                    int yoc;
                    cout << "Input new year of creation: ";
                    while(!(cin >> yoc))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid input, please try again!" << endl;
                    }
                    if (_lists.updateYOCComputer(yoc, id))
                    {
                        cout << "Computer edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else if (name == "wib" || name == "WIB")
                {
                    bool check;
                    int wib;

                    cout << "To edit if it was built please input 1 for true or 0 for false: ";
                    while(!(cin >> wib))
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid input, please try again!" << endl;
                    }
                    if (_lists.updateWasBuilt(wib, id))
                    {
                        cout << "Computer edited successfully" << endl;
                    }
                    check = true;
                    break;
                }
                else
                {
                    cout << endl << "Invalid input, please try again" << endl;
                    cout << "Valid inputs are: name, type, yoc (yoc stands for year of creation), wib (wib stands for was it built)" << endl << endl;
                    check = false;
                }
            }while (check == false);
            break;
        }
        else
        {
            cout << "Invalid input, please try again" << endl;
        }
    } while (input != "1" || input != "2");
    //break;
}

void ui::caseSixCaseOne()
{

}

int playGame;
        // Calling headder for case 7


void ui::playGame()
{
    int playGame = 0;
    caseSevenCase(playGame);
    caseSevenCase2(playGame);
    caseSevenCase3(playGame);
    caseSevenCase4(playGame);
    caseSevenCase5(playGame);
    double grade = (double)(playGame)/5.0 * 10;
    cout << "Game over!  You answered " << playGame;
    cout << " questions correctly out of 5 total." << endl;
    cout << "Your grade is " << grade;
    if (getenv("windir"))
    {
         string thisDoesNothing;
         cout << "Input anything and than press enter: ";
         cin >> thisDoesNothing;
         system("cls");
    }
    else
    {
        string thisDoesNothing;
        cout << "Input anything and than press enter. ";
        cin >> thisDoesNothing;
        system("clear");
    }

}



void ui::caseSevenCase(int &playGame)
{
   string answer = "2";
   string useranswer = "0";
   cout << "------------------------------------------------------------------" << endl;
   cout << "* Which of these is NOT a computer?      *-----------------------*" << endl;
   cout << "* 1:  Optiva.                            *                       *" << endl;
   cout << "* 2:  Paseo.                             *                       *" << endl;
   cout << "* 3:  Acorn.                             *                       *" << endl;
   cout << "* 4:  Z1.                                *                       *" << endl;
   cout << "*----------------------------------------*-----------------------*" << endl;
   cout << "------------------------------------------------------------------" << endl;
   cout << "Enter number: ";
   cin >> useranswer;
   if(answer == useranswer)
   {
       playGame++;
   }
}
void ui::caseSevenCase2(int &playGame)
{
   string answer = "3";
   string useranswer = "0";
   cout << "------------------------------------------------------------------" << endl;
   cout << "* The first hard disk was introduced in 1956 by? *---------------*" << endl;
   cout << "* 1:  Apple.                                     *               *" << endl;
   cout << "* 2:  Microsoft.                                 *               *" << endl;
   cout << "* 3:  IBM.                                       *               *" << endl;
   cout << "* 4:  Dell.                                      *               *" << endl;
   cout << "*------------------------------------------------*---------------*" << endl;
   cout << "------------------------------------------------------------------" << endl;
   cout << "Enter number: ";
   cin >> useranswer;
   if(answer == useranswer)
   {
       playGame++;
   }
}
void ui::caseSevenCase3(int &playGame)
{
   string answer = "1";
   string useranswer = "0";
   cout << "------------------------------------------------------------------" << endl;
   cout << "* Who invented C++?                      *-----------------------*" << endl;
   cout << "* 1:  Bjarne Stroustrup.                 *                       *" << endl;
   cout << "* 2:  Larry Page.                        *                       *" << endl;
   cout << "* 3:  Ken Thompson.                      *                       *" << endl;
   cout << "* 4:  Sophie Wilson.                     *                       *" << endl;
   cout << "*----------------------------------------*-----------------------*" << endl;
   cout << "------------------------------------------------------------------" << endl;
   cout << "Enter number: ";
   cin >> useranswer;
   if(answer == useranswer)
   {
       playGame++;
   }
}
void ui::caseSevenCase4(int &playGame)
{
   string answer = "4";
   string useranswer = "0";
   cout << "------------------------------------------------------------------" << endl;
   cout << "* Who popularized the term \"Bug\"?      *-----------------------*" << endl;
   cout << "* 1:  Frances Allen.                     *                       *" << endl;
   cout << "* 2:  Shafi Goldwasser.                  *                       *" << endl;
   cout << "* 3:  Adele Goldberg.                    *                       *" << endl;
   cout << "* 4:  Grace Hopper.                      *                       *" << endl;
   cout << "*----------------------------------------*-----------------------*" << endl;
   cout << "------------------------------------------------------------------" << endl;
   cout << "Enter number: ";
   cin >> useranswer;
   if(answer == useranswer)
   {
       playGame++;
   }
}
void ui::caseSevenCase5(int &playGame)
{
   string answer = "1";
   string useranswer;
   cout << "------------------------------------------------------------------" << endl;
   cout << "* What year was the Pascal calculator invented? *----------------*" << endl;
   cout << "* 1:  1642.                                     *                *" << endl;
   cout << "* 2:  1578.                                     *                *" << endl;
   cout << "* 3:  1743.                                     *                *" << endl;
   cout << "* 4:  1894.                                     *                *" << endl;
   cout << "*-----------------------------------------------*----------------*" << endl;
   cout << "------------------------------------------------------------------" << endl;
   cout << "Enter number: ";
   cin >> useranswer;
   if(answer == useranswer)
   {
       playGame++;
   }
}

