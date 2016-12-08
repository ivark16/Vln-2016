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
                    printScientists(newvector);
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
                        printScientists(newVector);
                    }
                    else if(numb == 2)
                    {
                        newVector = _lists.scientistInReverseAlphabeticalOrder();
                        printScientists(newVector);
                    }
                }
                else if (displayScientist == 3)
                {
                    vector<Scientist> living;

                    cout << "***List of all living scientists***" << endl;
                    living = _lists.searchAliveScientist();
                    printScientists(living);
                    break;
                }
                else if (displayScientist == 4)
                {
                   vector<Scientist> dead;
                   cout << "***List of all dead scientists***" << endl;
                   dead = _lists.searchDeadScientist();
                   printScientists(dead);
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
                        printScientists(order);
                    }
                    else if (numb == 2)
                    {
                        order = _lists.oldestOrderScientist();
                        for(unsigned int i = 0 ; i < order.size() ; i++)
                        printScientists(order);
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
                    //printScientists(norris);
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
                cout << "* 2:  display all in alphabetical order. * Y.O.D = year of death *" << endl;
                cout << "* 3:  display all when was built.        * Y.O.A = year of award *" << endl;
                cout << "* 4:  Display if was built.              *                       *" << endl;
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
                    printC();
                    printComputers(newvector);
                    /*for(unsigned int i = 0 ; i < newvector.size() ; i++)
                    {
                        cout << newvector[i].getComputerName() << "\t";
                        cout << newvector[i].getComputerType() << "\t";
                        cout << newvector[i].getYearOfBuild() << "\t";
                        cout << newvector[i].getWasBuilt();
                        cout << endl;
                    }*/
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

                //This case displays if the computer was built or not
                else if (displayScientist == 4)
                {
                    int numb;
                    vector<Computer> built;
                    cout << "Enter 1 for list of computers that were built or 2 for not built: ";
                    cin >> numb;
                    if(numb == 1)
                    {
                        built = _lists.myComputerWasBuilt();
                        for(unsigned int i = 0 ; i < built.size() ; i++)
                        {
                            cout << built[i].getComputerName() << "\t";
                            cout << built[i].getComputerType() << "\t";
                            cout << built[i].getYearOfBuild() << "\t";
                            cout << built[i].getWasBuilt();
                            cout << endl;
                        }
                    }
                    else if(numb == 2)
                    {
                        built = _lists.myComputerWasNotBuilt();
                        for(unsigned int i = 0 ; i < built.size() ; i++)
                        {
                            cout << built[i].getComputerName() << "\t";
                            cout << built[i].getComputerType() << "\t";
                            cout << built[i].getYearOfBuild() << "\t";
                            cout << built[i].getWasBuilt();
                            cout << endl;
                        }
                    }
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
                           cout << "* 1:  Search for a single year.          * Y.O.D = year of death *" << endl;
                           cout << "* 2:  Search for a range.                * Y.O.B = year of birth *"<< endl;
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
                                   printScientists(scientistsBirth);
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
                               printScientists(scientists);
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
                           printScientists(scientists);
                           break;*/
                       }
                }


              if(searchScientistOrComputers == 2)
              {
                  //Search for computers.
                   int searchComputers;
                   cout << "------------------------------------------------------------------" << endl;
                   cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                   cout << "* 1:  Search for name.                   *                       *" << endl;
                   cout << "* 2:  Search for type.                   *                       *" << endl;
                   cout << "* 3:  Search for year of built.          *                       *" << endl; //Ma laga
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
             cout << "------------------------------------------------------------------" << endl;
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
void ui::printScientists (vector<Scientist> scientistsToPrint)
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

void ui::printComputers(vector<Computer> computersToPrint)
{
    int counter = 1;
    int width = _lists.searchLongestNameComputer();
    for(unsigned int i = 0; i < computersToPrint.size(); i++)
    {
        cout.width(5);
        cout << left << counter;
        counter++;

        //adjusts width to longest name
        cout.width(width);
        cout << computersToPrint[i].getComputerName() << left;
        cout.width(width);
        cout << computersToPrint[i].getComputerType() << left;
        cout.width(width);
        int yearBuilt = computersToPrint[i].getYearOfBuild();
        if(yearBuilt == 0)
        {
            cout << "N/A";
        }
        else
        {
            cout << yearBuilt;
        }
        cout << endl;
    }

    for(int i = 0 ; i < 9 ; i++)
    {
        cout << "---------";
    }
    cout << endl;
}

void ui::printS()
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

void ui::printC()
{
    int width = _lists.searchLongestNameComputer();

    cout.width(5);
    cout << left << "No.";
    cout.width(width);
    cout << "Name" << left;
    cout.width(width);
    cout << "Type" << left;
    cout.width(width);
    cout << "Year built" << left;
    cout << endl;
}

//Checks for validity

/*
void ui::CheckNumbers (listServices checkNumbersForScientist)
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
*/

//This function checks whehter years are valid.
int ui::yearChecker(const int TYPE, int birthYear, int deathYear)
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
      else if (TYPE == 4)
      {
          cout << "Please insert second year.";
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

int ui::birthYearChecker()
{
    bool cont = false;
    int year;

    while(!cont)
    {
        cout << "Enter the scientist's birth year: " ;
        cin >> year;
        //checks that the entry is legit
        if(isdigit(year))
        {
            cont = true;
        }
        else
        {
            cout << "Invalid input.  Please enter a valid birth year" << endl;
        }
    }

    return year;
}

//
int ui::deathYearChecker()
{
    bool cont = false;
    int dyear;

    while(!cont)
    {
        cout << "Enter the scientists' year of death: " ;
        cin >> dyear;
        //checks that the entry is legit
        if(isdigit(dyear))
        {
            cont = true;
        }
        else
        {
            cout << "Invalid input.  Please enter a valid year of death." << endl;
        }
    }

    return dyear;
}

//
int ui::awardYearChecker()
{
    bool cont = false;
    int ayear;

    while(!cont)
    {
        cout << "Enter the scientists' year of award: " ;
        cin >> ayear;
        //checks that the entry is legitemate
        if(isdigit(ayear))
        {
            cont = true;
        }
        else
        {
            cout << "Invalid input.  Please enter a valid year of award." << endl;
        }
    }

    return ayear;
}
