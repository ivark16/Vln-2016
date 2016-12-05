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
    cout << "* 1:  Display list.                      * Y.O.D = year of death *" << endl;
    cout << "* 2:  Search for scientist.              * Y.O.B = year of birth *"<< endl;
    cout << "* 3:  Add new scientist.                 * Y.O.A = year of award *" << endl;
    cout << "* 4:  Delete scientist.                  *                       *" << endl;
    cout << "* 5:  Quit.                              *                       *" << endl;
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
            if(!((chooseNumber > 0) && (chooseNumber < 6)))
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
                cout << "* 1:  Display all scientists.            * Y.O.D = year of death *" << endl;
                cout << "* 2:  Display in alphabetical order.     * Y.O.D = year of death *" << endl;
                cout << "* 3:  Display in order of birth year.    * Y.O.B = year of birth *" << endl;
                cout << "* 4:  Display by award                   * Y.O.A = year of award *" << endl;
                cout << "* 5:  Display living scientists          *                       *" << endl;
                cout << "* 6:  Chuck Norris                       *                       *" << endl;
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
                    if(!((displayScientist > 0) && (displayScientist < 7)))
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
                    cout << "***List of all scientists***" << endl;
                    print(scientists);
                    printNames(scientists);
                    break;
                }
                else if (displayScientist == 2)
                {
                    listServices sort;
                    sort.changeTo(_scientist.sortByName());
                    cout << "A list of scientists in alphabetical order" << endl;
                    print(sort);
                    printNames(sort);
                    break;
                }
                 //This case displays the scientists in an organized list from oldest to youngest
                 else if (displayScientist == 3)
                    {
                        _scientist.changeTo(_scientist.sortByBirth());
                        cout << "An organized list starting with the oldest scientist" << endl;
                        print(_scientist);
                        printNames(_scientist);
                    break;
                    }
                //This case sorts the scientists by the year they recived the Turning Award
                else if (displayScientist == 4)
                {
                    _scientist.changeTo(_scientist.sortByAward());
                    cout << "An organized list of scientists in order of when they received a Turing award." << endl;
                    print(_scientist);
                    printNames(_scientist);
                    break;
                }
                    //This case organizes the living scientists from oldest to youngest
                else if (displayScientist == 5)
                {
                    listServices scientists;
                    string searchTerm;
                    scientists.changeTo(_scientist.searchAlive());
                    cout << "An organized list starting with the oldest living scientist" << endl;
                    print(scientists);
                    printNames(scientists);
                    break;
                }
                else if (displayScientist == 6)
                {

                    listServices norris;
                    norris.changeTo(_scientist.chuckNorris());
                    print(norris);
                    printNames(norris);
                    break;
                 }
        }
            break;

        //This case lets you search for a scientist from their name (either the first or last name)
        case 2:
            {
                int searchScientist;
                cout << "------------------------------------------------------------------" << endl;
                cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
                cout << "* 1:  Search for birth year.             * Y.O.D = year of death *" << endl;
                cout << "* 2:  Search for name.                   * Y.O.B = year of birth *"<< endl;
                cout << "* 3:  search for Turing awards.          * Y.O.A = year of award *" << endl;
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
                    int rangeOrSingle;
                    cout << "------------------------------------------------------------------" << endl;
                    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
                    cout << "* 1:  Search for a single year           * Y.O.D = year of death *" << endl;
                    cout << "* 2:  Search for a range                 * Y.O.B = year of birth *"<< endl;
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
                    if(rangeOrSingle == 1)
                    {
                        listServices scientistsBirth;
                        CheckNumbers(scientistsBirth);
                    }
                    else if(rangeOrSingle == 2)
                    {
                        int minYear = yearChecker(1,0,0);
                        int maxYear = yearChecker(1,0,0);
                        listServices scientistsBirth;
                        scientistsBirth.changeTo(scientistsBirth.searchBirth(minYear, maxYear));
                        print(scientistsBirth);
                        printNames(scientistsBirth);
                    }
                    break;
                }
                }

                //This case lets you search for a scientist from their name (either the first or last name)
                else if (searchScientist == 2)
                {
                    listServices scientists;
                    string searchTerm;
                    cout << "Enter a single name to search: ";
                    cin >> searchTerm;
                    scientists.changeTo(_scientist.searchName(searchTerm));
                    print(scientists);
                    printNames(scientists);
                    break;
                 }

                //This case sorts the scientists by the year they recived the Turning Award
                else if (searchScientist == 3)
                {
                    listServices scientists;
                    cout << "Etner a single year to search: ";
                    int year;
                    cin >> year;
                    scientists.changeTo(_scientist.searchAward(year));
                    print(scientists);
                    printNames(scientists);
                    break;
                }
        }
        break;

        // This case allows the user to add in another scientist (or even create a person - that is not real)
        case 3:
            {
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

               _scientist.addNew(firstName, lastName, gender, nationality, birthYear, deathYear, awardYear);
               }
        break;

        //This case Deletes scientist from database
        case 4:
        {
            listServices scientist;
                int ID = 0;
                bool personInDatabase = true;
                int counter = 0;
                int checker = 0;
                string doubleCheck;
                string name;

                cout << "Enter name: ";
                cin >> name;

                print(scientist);
                //here it prints the users that have the name that users wants to delete
                for(int i = 0 ; i < scientist.getSize(); i++)
                {
                    if(scientist.changeToLower(name) ==  scientist.changeToLower(scientist.getFirstNameFromList(i)) || name == scientist.changeToLower(scientist.getLastNameFromList(i)))
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
                        cout << scientist.getNationalityFromList(i) << left;
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
                        counter++;
                        checker = i;
                    }
                    else if(name !=  scientist.changeToLower(scientist.getFirstNameFromList(i)) || name != scientist.changeToLower(scientist.getLastNameFromList(i)))
                    {
                        if(i == (scientist.getSize() - 1) + counter)
                        {
                            cout << "Person is not in database!" << endl;
                            personInDatabase = false;
                            break;
                        }
                    }
                }
                for(int i = 0 ; i < 9 ; i++)
                {
                    cout << "--------";
                }
                cout << endl;
                if(personInDatabase == false)
                {
                    break;
                }
                cout << endl;
                cout << "Enter ID for scientist you want to delete: ";
                cin >> ID;
                cout << "Are you sure you want to delete ?: write Yes to delete or any character to abort: "<< endl;
                cin >> doubleCheck;
                scientist.changeToLower(doubleCheck);
                //here it checks if the user wants to delete and deletes the scientist from the vector
                if(doubleCheck == "yes")
                {
                    scientist.deleteFromList(ID);
                    print(scientist);
                    printNames(scientist);
                    scientist.writeNewFile();
                }
            }
                break;
        case 5:
            stillLooping = false;
            break;
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
    //cout << endl << endl << endl << endl;
        }
    }
}

//this is an error check.  It checks the validity of the name and prompts the user for a new one until one is valid.
string consoleUI::nameChecker(string nameType)
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

       return name;
}

//prompts the user for a gender and checks its validity.  If it is invalid it asks again until it receives a valid gender.
char consoleUI::genderChecker()
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

void consoleUI::print(listServices scientistsToPrint)
{
    int width = scientistsToPrint.searchLongestName();

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
            print(scientist);
            printNames(scientist);
            answear = 'n';
            }
        } while (answear == 'y');
}

//This function checks whehter years are valid.
int consoleUI::yearChecker(const int TYPE, int birthYear, int deathYear)
{
  int year;
  bool cont = true;

  while(cont)
  {
      if(TYPE == 1)
      {
      cout << "Please enter the scientists birth year.";
      }
      else if(TYPE == 2)
      {
      cout << "Please enter the scientists year of death.";
      }
      else if(TYPE == 3)
      {
      cout << "Please enter the year the scientist won the award.";
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
      else
      {
          //end the loop and return the year.
          //this happens when the input is valid.
          cont = false;

      }
  }
  return year;
}

//checks the validity of the nationality.
string consoleUI::nationalityChecker()
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
