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
                cout << "* 6:  Chuck Norris.                      *                       *" << endl;
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

                    }
                    else
                    {
                        invalidInput = false;
                    }
                }
                if (displayScientist == 1)
                {

                    vector<Scientist> newvector;

                    cout << "***List of all scientists***" << endl;
                    newvector = _lists.displayScientist();
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
                    int numb;
                    vector<Scientist> newVector;
                    cout << "***List of all scientist in alphabetic order***" << endl;
                    cout << "Enter 1 for ascending order or 2 for descending order: ";
                    cin >> numb;
                    if(numb == 1)
                    {
                        newVector = _lists.scientistInAlphabeticalOrder();
                        for(unsigned int i = 0 ; i < newVector.size() ; i++)
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
                    else if(numb == 2)
                    {
                        newVector = _lists.scientistInReverseAlphabeticalOrder();
                        for(unsigned int i = 0 ; i < newVector.size() ; i++)
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
                }
                else if (displayScientist == 3)
                {
                    vector<Scientist> living;

                    cout << "***List of all living scientists***" << endl;
                    living = _lists.searchAliveScientist();
                    for(unsigned int i = 0 ; i < living.size() ; i++)
                    {
                        cout << living[i].getFirstName()  << "\t";
                        cout << living[i].getLastName() << "\t";
                        cout << living[i].getNationality() << "\t";
                        cout << living[i].getGender() << "\t";
                        cout << living[i].getBirthYear() << "\t";
                        cout << living[i].getDeathYear()  << "\t";
                        cout << living[i].getAwardYear();
                        cout << endl;
                    }
                    break;
                }
                else if (displayScientist == 4)
                {
                   vector<Scientist> dead;
                   cout << "***List of all dead scientists***" << endl;
                   dead = _lists.searchDeadScientist();
                   for(unsigned int i = 0 ; i < dead.size() ; i++)
                   {
                       cout << dead[i].getFirstName()  << "\t";
                       cout << dead[i].getLastName() << "\t";
                       cout << dead[i].getNationality() << "\t";
                       cout << dead[i].getGender() << "\t";
                       cout << dead[i].getBirthYear() << "\t";
                       cout << dead[i].getDeathYear()  << "\t";
                       cout << dead[i].getAwardYear();
                       cout << endl;
                   }
                   break;
                }
                    //This case organizes the living scientists from oldest to youngest
                else if (displayScientist == 5)
                {
                    int numb;
                    vector<Scientist> order;
                    cout << "choose 1 for order of youngest or 2 for order of oldest: ";
                    cin >> numb;
                    if(numb == 1)
                    {
                        order = _lists.youngestOrderScientist();
                        printNames(order);
                        /*
                        for(unsigned int i = 0 ; i < order.size() ; i++)
                        {
                            cout << order[i].getFirstName()  << "\t";
                            cout << order[i].getLastName() << "\t";
                            cout << order[i].getNationality() << "\t";
                            cout << order[i].getGender() << "\t";
                            cout << order[i].getBirthYear() << "\t";
                            cout << order[i].getDeathYear()  << "\t";
                            cout << order[i].getAwardYear();
                            cout << endl;
                        }*/
                    }
                    else if (numb == 2)
                    {
                        order = _lists.oldestOrderScientist();
                        for(unsigned int i = 0 ; i < order.size() ; i++)
                        {
                            cout << order[i].getFirstName()  << "\t";
                            cout << order[i].getLastName() << "\t";
                            cout << order[i].getNationality() << "\t";
                            cout << order[i].getGender() << "\t";
                            cout << order[i].getBirthYear() << "\t";
                            cout << order[i].getDeathYear()  << "\t";
                            cout << order[i].getAwardYear();
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "wrong input" << endl;
                    }
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
                cout << "* 4:  Display if was built               *                       *" << endl;
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
                    vector<Computer> newvector;

                    cout << "***List of all computers***" << endl;
                    newvector = _lists.displayComputer();
                    printComputers();
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
                    vector<Computer> newvector;
                    int numb;
                    cout << "***List of computer in alphabetical order***" << endl;
                    cout << "Enter 1 for list in ascending order or 2 for descending order: ";
                    cin >> numb;
                    if(numb == 1)
                    {
                        newvector = _lists.computerInAlphabeticalOrder();
                        for(unsigned int i = 0 ; i < newvector.size() ; i++)
                        {
                            cout << newvector[i].getComputerName() << "\t";
                            cout << newvector[i].getComputerType() << "\t";
                            cout << newvector[i].getYearOfBuild() << "\t";
                            cout << newvector[i].getWasBuilt();
                            cout << endl;
                        }
                    }
                    else if(numb == 2)
                    {
                        newvector = _lists.computerInReverseAlphabeticalOrder();
                        for(unsigned int i = 0 ; i < newvector.size() ; i++)
                        {
                            cout << newvector[i].getComputerName() << "\t";
                            cout << newvector[i].getComputerType() << "\t";
                            cout << newvector[i].getYearOfBuild() << "\t";
                            cout << newvector[i].getWasBuilt();
                            cout << endl;
                        }
                    }
                }
                else if (displayScientist == 3)
                {
                    int numb;
                    vector<Computer> yearOfBuild;
                    cout << "***List of build year***" << endl;
                    cout << "Enter 1 for order of youngest or 2 for oldest: ";
                    cin >> numb;
                    if(numb == 1)
                    {
                        yearOfBuild = _lists.youngestOrderComputer();
                        for(unsigned int i = 0 ; i < yearOfBuild.size() ; i++)
                        {
                            cout << yearOfBuild[i].getComputerName() << "\t";
                            cout << yearOfBuild[i].getComputerType() << "\t";
                            cout << yearOfBuild[i].getYearOfBuild() << "\t";
                            cout << yearOfBuild[i].getWasBuilt();
                            cout << endl;
                        }
                    }
                    else if(numb == 2)
                    {
                        yearOfBuild = _lists.oldestOrderComputer();
                        for(unsigned int i = 0 ; i < yearOfBuild.size() ; i++)
                        {
                            cout << yearOfBuild[i].getComputerName() << "\t";
                            cout << yearOfBuild[i].getComputerType() << "\t";
                            cout << yearOfBuild[i].getYearOfBuild() << "\t";
                            cout << yearOfBuild[i].getWasBuilt();
                            cout << endl;
                        }
                    }
                    break;
                }

                //This case displays the scientists in an organized list from oldest to youngest
                else if (displayScientist == 4)
                {
                    break;
                }

            }
                break;
            case 3:
            {

             //Search for a scientist or computers.
                int searchScientistOrComputers;
                cout << "------------------------------------------------------------------" << endl;
                cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                cout << "* 1:  Search scientist.                  * Y.O.B = year of birth *" << endl;
                cout << "* 2:  Search computers.                  *                       *" << endl;
                cout << "*----------------------------------------*-----------------------*" << endl;
                cout << "-----------------------------------------------------------------" << endl;
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
                  if(!((searchScientistOrComputers > 0) && (searchScientistOrComputers < 3)))
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
                           /*while(invalidInput)
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
                                   int maxYear = yearChecker(4,minYear,0);
                                   listServices scientistsBirth;
                                   scientistsBirth.changeTo(scientistsBirth.searchBirth(minYear, maxYear));
                                   print(scientistsBirth);
                                   printNames(scientistsBirth);
                               }
                                break;
                            }*/
                       }

                       //This case lets you search for a scientist from their name (either the first or last name)
                       else if (searchScientist == 2)
                       {
                           /*listServices scientists;
                           string searchTerm;
                           cout << "Enter a single name to search: ";
                           cin >> searchTerm;
                           //scientists.changeTo(scientists.searchName(searchTerm));
                           _myData.searchForNameFromDatabase(searchTerm);
                           print(scientists);
                           if (_myData.getSizeOfScientists() == 0)
                           {
                               cout << "Person is not in database!" << endl;
                               cout << "-------------------------------------------------------------" << endl;
                               break;
                           }
                           else
                           {
                               printNames(scientists);
                               break;
                           }*/

                        }

                       //This case sorts the scientists by the year they recived the Turning Award
                       else if (searchScientist == 3)
                       {
                           /*listServices scientists;
                           cout << "Enter a single year to search: ";
                           int year;
                           cin >> year;
                           scientists.changeTo(scientists.searchAward(year));
                           print(scientists);
                           printNames(scientists);
                           break;*/
                       }
                }


              if(searchScientistOrComputers == 2)
              {
                  //Search for computers.
                   int searchComputers;
                   cout << "------------------------------------------------------------------" << endl;
                   cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                   cout << "* 1:  Search for a computer name.        *                       *" << endl;
                   cout << "* 2:  Search for a computer type.        *                       *" << endl;
                   cout << "*----------------------------------------*-----------------------*" << endl;
                   cout << "-----------------------------------------------------------------" << endl;
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
                }
            }
                break;

            case 4:
            {
            //add new scientist to the database
            //CHECK FUNCTIONS NEEDED
             int addScientistOrComputer;
             cout << "------------------------------------------------------------------" << endl;
             cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
             cout << "* 1:  Add a scientist.                   * Y.O.B = year of birth *" << endl;
             cout << "* 2:  Add a computer.                    *                       *" << endl;
             cout << "*----------------------------------------*-----------------------*" << endl;
             cout << "-----------------------------------------------------------------" << endl;
             cout << "Enter number: ";

             bool invalidInput = true;
             while(invalidInput)
             {
                 while (!(cin >> addScientistOrComputer))
                 {
                     cin.clear();
                     cin.ignore(1000,'\n');
                     cout << "Not valid input, please try again: ";
                 }
                 if(!((addScientistOrComputer > 0) && (addScientistOrComputer < 3)))
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
                 string fName;
                 string lName;
                 char gender;
                 string nationality;
                 int bYear;
                 int dYear;
                 int aYear;
                 cout << "Enter all relevant information (temporary until checks have been amended)" << endl;
                 cin >> fName >> lName >> gender >> nationality >> bYear >> dYear >> aYear;  //AMEND
                 Scientist newScientist( fName, lName, gender, nationality, bYear, dYear, aYear);
                 _lists.addScientistToDatabase(newScientist);
             }
             if(addScientistOrComputer == 2)
             {
                string name;
                string type;
                int YOB;
                bool wasBuilt;
                cout << "Enter all relevant information (temporary until checks have been amended)" << endl;
                cin >> name >> type >> YOB >> wasBuilt;
                Computer newComputer(name, type, YOB, wasBuilt);
                _lists.addComputerToDatabase(newComputer);

             }

            }
                break;
            case 5:
            {
             //DELETE a nice boy
             int deleteScientistOrComputer;
             cout << "------------------------------------------------------------------" << endl;
             cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
             cout << "* 1:  Delete a scientist.                * Y.O.B = year of birth *" << endl;
             cout << "* 2:  Delete a computer.                 *                       *" << endl;
             cout << "*----------------------------------------*-----------------------*" << endl;
             cout << "-----------------------------------------------------------------" << endl;
             cout << "Enter number: ";

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
                    //DELETE SCIENTIST
             }
             if(deleteScientistOrComputer == 2)
             {
                    //DELETE COMPUTER
             }



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

/*void ui::print(vector<Scientist> scientistsToPrint)
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
}*/

// This function prints all names in a table to the console
void ui::printNames (vector<Scientist> scientistsToPrint)
{
    int counter = 1;
    for(unsigned int i = 0; i < scientistsToPrint.size(); i++)
    {
        string sex;
        string isDead;

        if(scientistsToPrint[i].getGender() == 'm')
        {
            sex = "male";
        }
        else if(scientistsToPrint[i].getGender() == 'f')
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
        //cout << scientistsToPrint[i].getDeathYear() << left;
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
            isDead = "None";
            cout.width(10);
            cout << isDead << left;
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

void ui::printComputers()
{
    //TEMPORARY.  delete this when you uncomment the original.
}


/*
void ui::printComputers()
{

    int width = _lists.searchLongestNameComputer();

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

}*/
void ui::printScientist()
{

    int width = _lists.searchLongestNameScientist();

    cout.width(5);
    cout << left << "No.";
    cout.width(width);
    cout << "First name" << left;
    cout.width(width);
    cout << "Last name" << left;
    cout.width(width);
    cout << "Gender" << left;
    cout.width(width);
    cout << "Nationality" << left;
    cout.width(width);
    cout << "Year of birth" << left;
    cout.width(width);
    cout << "Year of death" << left;
    cout.width(width);
    cout << "Year of award" << left;

    for(int i = 0; i < 9; i++)
    {
        cout << "--------";
    }
    cout << endl;

}
