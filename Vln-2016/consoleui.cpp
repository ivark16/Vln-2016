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

bool consoleUI::digitCheck(int num)
{
    if(isdigit(num))
    {
        return true;
        cout << "INNI ISDIGIT" << endl;
    }
    return false;
    cout << "INNI ISDIGIT" << endl;
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

<<<<<<< HEAD

    cin >> chooseNumber;
=======
>>>>>>> 8171b2a759c070e7b0546e6a4aac135c8c51c4bc


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
            if(!((chooseNumber > 0) && (chooseNumber < 13)))
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
                string nationality;
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
                cout << "Nationality: ";
                nationality = nationalityChecker();
                birthYear = yearChecker(1, 0, 0);
                cin >> nationality;
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

    //searchBirth
    case 6:
        {
            listServices scientistsBirth;
            CheckNumbers(scientistsBirth);
        }
          break;

    //This case sorts all the scientists by their name in an alpabetical order
    case 7:
    {
        listServices sort;
        sort.changeTo(_scientist.sortByName());
        cout << "A list of scientists in alphabetical order" << endl;
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
        bool personInDatabase = true;
        string doubleCheck;
        string name;
        cout << "Enter name: ";
        cin >> name;
        print();
        for(int i = 0 ; i < scientist.getSize(); i++)
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

            }
            else if(name !=  scientist.changeToLower(scientist.getFirstNameFromList(i)) || name != scientist.changeToLower(scientist.getLastNameFromList(i)))
            {
                if(i == scientist.getSize() - 1)
                {
                    cout << "Person is not in database!" << endl;
                    personInDatabase = false;
                    break;
                }
            }
        }
        for(int i = 0 ; i < 8 ; i++)
        {
            cout << "--------";
        }
        if(personInDatabase == false)
        {
            break;
        }
        cout << endl;
        cout << "Enter number for scientist you want to delete: ";
        cin >> ID;
        cout << "Are you sure you want to delete ?: " << endl;
        cout << "write Yes to delete or any character to abort: "<< endl;
        cin >> doubleCheck;
        scientist.changeToLower(doubleCheck);
        if(doubleCheck == "yes")
        {
            scientist.deleteFromList(ID);
            print();
            printNames(scientist);
            scientist.writeNewFile();
        }
        else
        {
            break;
        }

    }
        break;

    case 12:
        stillLooping = false;
        break;
 }
if(stillLooping)
{
//string thisDoesNothing;
cout << "Enter any letter and press enter to continue." << endl;
cin.get();
cout << endl << endl << endl << endl;
}

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
    cout << "nation" << left;
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
      else if(TYPE == 2 && (year >2016 || year<1791) && year <= birthYear)
      {
          cout << "Invalid year." << endl;
      }
      else if(TYPE == 3 && (year <1966 || year > 2016) && (year < birthYear || (year > deathYear && deathYear != 0)))
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
