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

void ui::run()
{
     //Displaying Group 9 case
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
                string displayScientist;
                //Displaying Case 1 header
                do
                {
                    caseOneCase();
                    cin >> displayScientist;

                    if (displayScientist == "1")
                    {
                        vector<Scientist> newvector;
                        cout << "***List of all scientists***" << endl;
                        newvector = _lists.displayScientist();
                        printS();
                        printScientists(newvector);
                        break;
                    }
                    else if(displayScientist == "2")
                    {
                        string numb;
                        vector<Scientist> newVector;
                        do
                        {
                            cout << "Enter 1 for ascending order or 2 for descending order: ";
                            cin >> numb;
                            if(numb == "1")
                            {
                                newVector = _lists.scientistInAlphabeticalOrder();
                                cout << "***List of all scientist in alphabetic order***" << endl;
                                printS();
                                printScientists(newVector);
                                break;
                            }
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
                    else if (displayScientist == "3")
                    {
                        vector<Scientist> living;

                        cout << "***List of all living scientists***" << endl;
                        living = _lists.searchAliveScientist();
                        printS();
                        printScientists(living);
                        break;
                    }
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
                            if(numb == "1")
                            {
                                order = _lists.youngestOrderScientist();
                                printS();
                                printScientists(order);
                                break;
                            }
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
                    else if (displayScientist == "6")
                    {

                        //listServices norris;
                        //norris.changeTo(norris.chuckNorris());
                        //print(norris);
                        //printScientists(norris);
                    }
                    else
                    {
                        cout << "Invalid input, please try again! " << endl;
                    }
                } while (displayScientist != "1" || displayScientist != "2" || displayScientist != "3" || displayScientist != "4" || displayScientist != "5" || displayScientist != "6");
            }
            else if (chooseNumber == "2")
            {
                string displayScientist;

                //printing menu for caseTwoCase
                do
                {
                    caseTwoCase();
                    cin >> displayScientist;
                    if (displayScientist == "1")
                    {
                        vector<Computer> newvector;

                        cout << "***List of all computers***" << endl;
                        newvector = _lists.displayComputer();
                        printC();
                        printComputers(newvector);
                        break;
                    }

                    else if(displayScientist == "2")
                    {
                        vector<Computer> newvector;
                        string numb;
                        do
                        {
                            cout << "Enter 1 for list in ascending order or 2 for descending order: ";
                            cin >> numb;
                            if(numb == "1")
                            {
                                newvector = _lists.computerInAlphabeticalOrder();
                                cout << "***List of computer in alphabetical order***" << endl;
                                printC();
                                printComputers(newvector);
                                break;
                            }
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
                    else if (displayScientist == "3")
                    {
                        string numb;
                        vector<Computer> yearOfBuild;
                        do
                        {
                            cout << "***List of build year***" << endl;
                            cout << "Enter 1 for order of youngest or 2 for oldest: ";
                            cin >> numb;
                            if(numb == "1")
                            {
                                yearOfBuild = _lists.youngestOrderComputer();
                                printC();
                                printComputers(yearOfBuild);
                                break;
                            }
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
                            if(numb == "1")
                            {
                                built = _lists.myComputerWasBuilt();
                                printC();
                                printComputers(built);
                            }
                            else if(numb == "2")
                            {
                                built = _lists.myComputerWasNotBuilt();
                                printC();
                                printComputers(built);
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
            else if (chooseNumber == "3")
            {

             //Search for a scientist or computers.
                int searchScientistOrComputers;
                cout << "------------------------------------------------------------------" << endl;
                cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                cout << "* 1:  Search scientist.                  * Y.O.B = year of birth *" << endl;
                cout << "* 2:  Search computers.                  *                       *" << endl;
                cout << "* 3:  Search connections.                *                       *" << endl;
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
                             // searchResults = _lists.checkRangeBirthYear(minYear, maxYear);
                              printS();
                              printScientists(searchResults);
                          }
                          break;
                      }


                       //This case lets you search for a scientist from their name (either the first or last name)
                       else if (searchScientist == 2)
                       {
                           string searchTerm;
                           cout << "Enter a single name to search: ";
                           cin >> searchTerm;
                           vector<Scientist> nameSearch = _lists.checkName(searchTerm);
                           printS();
                           if (nameSearch.size() == 0)
                           {
                               cout << "Person is not in database!" << endl;
                               cout << "-------------------------------------------------------------" << endl;
                               break;
                           }
                           else
                           {
                               printScientists(nameSearch);
                               break;
                           }
                        }

                       //This case sorts the scientists by the year they recived the Turning Award
                       else if (searchScientist == 3)
                       {

                           cout << "Enter a single year to search: ";
                           int year;
                           cin >> year;
                           vector<Scientist> awardSearch;
                           awardSearch = _lists.checkForAward(year);
                           printS();
                           if (awardSearch.size() == 0)
                           {
                               cout << "There is no match in the database!" << endl;
                               cout << "-------------------------------------------------------------" << endl;
                               break;
                           }
                           else
                           {
                               printScientists(awardSearch);
                               break;
                           }
                           printScientists(awardSearch);
                           break;
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
                       cout << "Enter a single year to search: ";
                       int year;
                       cin >> year;
                       //searchResults = _lists.;
                   }
                   else if(searchComputers == 3)
                   {
                       //TODO
                   }
                }
              if(searchScientistOrComputers == 3)
              {
                  //Search for connections.
                   int searchConnections;
                   cout << "------------------------------------------------------------------" << endl;
                   cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
                   cout << "* 1:  Search by scientist.               *                       *" << endl;
                   cout << "* 2:  Search by computer.                *                       *" << endl;
                   cout << "*----------------------------------------*-----------------------*" << endl;
                   cout << "------------------------------------------------------------------" << endl;
                   cout << "Enter number: ";

                   bool invalidInput = true;
                   while(invalidInput)
                   {
                      while (!(cin >> searchConnections))
                      {
                          cin.clear();
                          cin.ignore(1000,'\n');
                          cout << "Not valid input, please try again: ";
                      }
                      if(!((searchConnections > 0) && (searchConnections < 3)))
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
                   if(searchConnections == 1)
                   {
                       string searchTerm;
                       cout << "Enter a single name to search: ";
                       cin >> searchTerm;
                       connections = _lists.displaySearchJoinScientistName(searchTerm);
                   }
                   else if(searchConnections == 2)
                   {
                       string searchTerm;
                       cout << "Enter a single name to search: ";
                       cin >> searchTerm;
                       connections = _lists.displaySearchJoinComputerName(searchTerm);
                       //MISSING PRINT FUNCTIONS
                   }
              }
            }

            else if (chooseNumber == "4")
            {
            //add new scientist to the database
            //CHECK FUNCTIONS NEEDED
             int addScientistOrComputer;
             // Calling headder for case 4
             caseFourCase();

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
                     Scientist newScientist( firstName, lastName, gender, nationality, birthYear, deathYear, awardYear);
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
                if(addScientistOrComputer == 3)
                {
                    int scientistId;
                    int computerId;
                    cout << "Enter ID for connection" << endl;
                    cin >> scientistId >> computerId;
                    connection newConnection(scientistId, computerId);
                    _lists.addConnectionToDatabase(newConnection);
                }

            }
            else if (chooseNumber == "5")
            {
             //DELETE a nice boy
             int deleteScientistOrComputer;
             caseFiveCase();

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
            else if (chooseNumber == "6")
            {
                string input;
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
                            //id = editScientist[0].
                            if (editScientist.size() == 0)
                            {
                                check2 = false;
                            }
                            else
                            {
                                check2 = true;
                            }
                        }while (check2 == false);
                        do
                        {
                            printS();
                            printScientists(editScientist);
                            cout << "Please insert what you would like to edit (example: insert firstname to edit Scientists firstname): ";
                            cin >> name;
                            if (name == "firstname" || name == "firstName")
                            {
                                string firstname;
                                cout << "Input new first name: ";
                                cin >> firstname;
                                _lists.updateFirstNameScientist(firstname, id);
                                check = true;
                                break;
                            }
                            else if (name == "lastname" || name == "lastName")
                            {
                                string lastname;
                                cout << "Input new first name: ";
                                cin >> lastname;
                                check = true;
                                break;
                            }
                            else if (name == "gender" || name == "Gender")
                            {
                                char sex;
                                cout << "Input new gender";
                                cin >> sex;
                                check = true;
                                break;
                            }
                            else if (name == "nationality" || name == "Nationality")
                            {
                                string nationality;
                                cout << "Input new nationality: ";
                                cin >> nationality;
                                check = true;
                                break;
                            }
                            else if (name == "yob" || name == "YOB")
                            {
                                int yob;
                                cout << "Input new year of birth: ";
                                cin >> yob;
                                check = true;
                                break;
                            }
                            else if (name == "yod" || name == "YOD")
                            {
                                int yod;
                                cout << "Input new year of death: ";
                                cin >> yod;
                                check = true;
                                break;
                            }
                            else if (name == "yoa" || name == "YOA")
                            {
                                int yoa;
                                cout << "Input new year of award: ";
                                cin >> yoa;
                                check = true;
                                break;
                            }
                            else
                            {
                                cout << "Invalid input, please try again" << endl;
                                cout << "Valid inputs are: firstname, lastname, gender, Nationality, YOB, YOD, YOA" << endl;
                                check = false;
                            }
                        }while (check == false);
                    }
                    else if (input == "2")
                    {

                    }
                    else
                    {
                        cout << "Invalid input, please try agian" << endl;
                    }
                } while (input != "1" || input != "2");
                break;
            }
            else if (chooseNumber == "7")
            {
                break;
            }
            else
            {
                cout << "Invalid input, please try again!" << endl;

            }
            if(stillLooping == true && (chooseNumber == "1" || chooseNumber == "2" || chooseNumber == "3" || chooseNumber == "4" || chooseNumber == "5" || chooseNumber == "6"))
            {
                if (getenv("windir"))
                {
                     string thisDoesNothing;
                     cout << "Input anything and than press enter. ";
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

void ui::printComputers(vector<Computer> computersToPrint)
{
    int counter = 1;
    int width = _lists.searchLongestNameComputer();
    for(unsigned int i = 0; i < computersToPrint.size(); i++)
    {
        string na;
        cout.width(5);
        cout << left << counter;
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
            na = "N/A";
            cout << na;
        }
        else
        {
            cout << yearBuilt;
        }
        if (computersToPrint[i].getWasBuilt() == 1)
        {
            cout << "True";
        }
        else
        {
            cout << "False";
        }
        if (na == "N/A")
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

void ui::printC()
{
    int width = _lists.searchLongestNameComputer();

    cout.width(5);
    cout << left << "No.";
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

//This function checks whehter years are valid.
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

void ui::mainMenuCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display list of Scientist.         * Y.O.D = year of death *" << endl;
    cout << "* 2:  Display list of Computers.         * Y.O.B = year of birth *" << endl;
    cout << "* 3:  Search for scientist/computers.    * Y.O.A = year of award *" << endl;
    cout << "* 4:  Add new scientist/computers.       *  N/A = Not applicable *" << endl;
    cout << "* 5:  Delete scientist/computers         *                       *" << endl;
    cout << "* 6:  Edit scientist/computers           *                       *" << endl;
    cout << "* 7:  Quit.                              *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

void ui::caseOneCase()
{
    int displayScientist;
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Scientist ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display all scientists.            * Y.O.B = year of birth *" << endl;
    cout << "* 2:  Display in alphabetical order.     * Y.O.D = year of death *" << endl;
    cout << "* 3:  display all living scientist.      * Y.O.A = year of award *" << endl;
    cout << "* 4:  Display all dead scientist.        *  N/A = Not applicable *" << endl;
    cout << "* 5:  Display in order of birth.         *                       *" << endl;
    cout << "* 6:  Chuck Norris.                      *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

void ui::caseTwoCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Display all Computers.             * Y.O.B = year of birth *" << endl;
    cout << "* 2:  display all in alphabetical order. * Y.O.D = year of death *" << endl;
    cout << "* 3:  display all when was built.        * Y.O.A = year of award *" << endl;
    cout << "* 4:  Display if was built.              *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

void ui::caseFourCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Add a scientist.                   * Y.O.B = year of birth *" << endl;
    cout << "* 2:  Add a computer.                    *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

void ui::caseFiveCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Delete a scientist.                * Y.O.B = year of birth *" << endl;
    cout << "* 2:  Delete a computer.                 *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}

void ui::caseSixCase()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "*------ Database for Computers ----------*--------Glossary-------*" << endl;
    cout << "* 1:  Edit a scientist.                  * Y.O.B = year of birth *" << endl;
    cout << "* 2:  Edit a computer.                   *                       *" << endl;
    cout << "*----------------------------------------*-----------------------*" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Enter number: ";
}
