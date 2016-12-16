#include "listservices.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//This function searches for the name "name", which is user input.
vector<Scientist> listServices::searchForName(string name)
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.searchForNameFromDatabase(name);
    return returnScientist;
}

//This function returns its size from the datalayer to the ui.
int listServices::getSizeOfScientist()
{
    return _myData.getSizeOfScientists();
}

int listServices::getSizeOfComputer()
{
    return _myData.getSizeOfComputer();
}

//This function accesses the datalayer, collects all the scientists.
vector<Scientist> listServices::displayScientist()
{
    vector<Scientist> display;
    display = _myData.readAllFromScientistsDataBase();
    return display;
}

//This function accesses the datalayer and collects all the scientists by their ID.
vector<Scientist> listServices::displayScientistById(int x)
{
    vector<Scientist> displayByIdScientist;
    displayByIdScientist = _myData.readAllFromScientistDataBaseById(x);
    return displayByIdScientist;
}

//This function accesses the datalayer and collects all the computers.
vector<Computer> listServices::displayComputer()
{
    vector<Computer> display;
    display = _myData.readAllFromDataComputerBase();
    return display;
}

//This function accesses the datalayer, collects all the computers by their ID.
vector<Computer> listServices::displayComputerById(int x)
{
    vector<Computer> displayById;
    displayById = _myData.readAllFromDataComputerBaseById(x);
    return displayById;
}

//This function accesses the datalayer, collects all the connections between scientists and computers.
vector<connection> listServices::displayConnection()
{
    vector<connection> display;
    display = _myData.readAllFromDataConnectionBase();
    return display;
}

//This function adds a new scientist to the database.
void listServices::addScientistToDatabase(Scientist newScientist)
{
    _myData.addFunction(newScientist);
}

//This function adds a new computer to the database.
void listServices::addComputerToDatabase(Computer newComputer)
{
    _myData.addFunctionComputer(newComputer);
}

//Adds a new connection to the database.
void listServices::addConnectionToDatabase(connection newConnection)
{
    _myData.addFunctionConnect(newConnection);
}

//Returns all the scientists by their ID in an alphabetical order.
vector<Scientist> listServices::readInAscendingByID()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAscendingByID();
    return returnScientist;
}

//Returns all the scientists by their ID in a reverse alphabetical order.
vector<Scientist> listServices::readInDiscendingByID()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInDiscendingByID();
    return returnScientist;
}

//Returns all the scientists by their nationality in an alphabetical order.
vector<Scientist> listServices::readInAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrderNationality();
    return returnScientist;
}

//Returns all the scientists by their nationality in a reverse alphabetical order.
vector<Scientist> listServices::readInReverseAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrderNationality();
    return returnScientist;
}

//Returns all the scientists by their gender in an alphabetical order.
vector<Scientist> listServices::readInAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrderGender();
    return returnScientist;
}

//Returns all the scientists by their gender in an reverse alphabetical order.
vector<Scientist> listServices::readInReverseAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrderGender();
    return returnScientist;
}

//Returns all the scientists by the year they receved the turning award in an ascending order.
vector<Scientist> listServices::readInAscendingByYOA()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAscendingByYOA();
    return returnScientist;
}

//Returns all the scientists by the year they receved the turning award in an descending order.
vector<Scientist> listServices::readInDescendingByYOA()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInDescendingByYOA();
    return returnScientist;
}

//Returns a picture of a scientist (by their ID).
QByteArray listServices::searchScientistPicture(int id)
{
   QByteArray picture = _myData.searchForPictureForScientist(id);
   return picture;
}

//Returns all the scientists by their name in an alphabetical order.
vector<Scientist> listServices::scientistInAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInAlphabeticalOrder();
    return returnScientist;
}

//Returns the scientists by their name in a reverse alphabetical order.
vector<Scientist> listServices::scientistInReverseAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInReverseAlphabeticalOrder();
    return returnScientist;
}

//Returns all the computers by their name in an alphabetical order.
vector<Computer> listServices::computerInAlphabeticalOrder()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.readInAlphabeticalOrderComputer();
    return returnComputer;
}

//Returns all the computers by teir name in a reverse alphabetical order.
vector<Computer> listServices::computerInReverseAlphabeticalOrder()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.readInReverseAlphabeticalOrderComputer();
    return returnComputer;
}

//Returns all the computers by if they were built in an ascending order.
vector<Computer> listServices::ComputerWasBuiltASC()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.ComputerWasBuiltASC();
    return returnComputer;
}

//Returns all the computers by if they were built in a descending order.
vector<Computer> listServices::ComputerWasBuiltDESC()
{
    vector<Computer> returnComputer;
    returnComputer = _myData.ComputerWasBuiltDESC();
    return returnComputer;
}

//Returns a list of the scientists from oldest to youngest.
vector<Scientist> listServices::oldestOrderScientist()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInOldestOrder();
    return returnScientist;
}

//Returns a list of the computers from oldest to youngest.
vector<Computer> listServices::oldestOrderComputer()
{
    vector<Computer> display;
    display = _myData.readInOldestOrderComputer();
    return display;
}

//This function displays the scientists in an order from the youngest to oldest.
vector<Scientist> listServices::youngestOrderScientist()
{
    vector<Scientist> returnScientist;
    returnScientist = _myData.readInYoungestOrder();
    return returnScientist;
}

//This function displays the computer in an order from the newest one to the oldest.
vector<Computer> listServices::youngestOrderComputer()
{
    vector<Computer> display;
    display = _myData.readInYoungestOrderComputer();
    return display;
}

//function for searching the connection table by the scientists name.
vector<searching> listServices::displaySearchJoinScientistName(string x)
{
    vector<searching> displayJoinScientist;
    displayJoinScientist = _myData.searchForScientistFromSearchingDatabse(x);
    return displayJoinScientist;
}

//function for searching the connection table by a computers name.
vector<searching> listServices::displaySearchJoinComputerName(string x)
{
    vector<searching> displayJoinComputer;
    displayJoinComputer = _myData.searchForComputerFromSearchingDatabase(x);
    return displayJoinComputer;
}

//This function deletes a scientist from the database.
bool listServices::deleteScientistFromDatabase(int x)
{
    bool check;

    if (_myData.deleteFunction(x) == true && _myData.deleteConnectionFunctionScientist(x) == true)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function deletes computers from the database.
bool listServices::deleteComputerFromDatabase(int x)
{
    bool check;

    if(_myData.deleteFunctionComputer(x) == true && _myData.deleteConnectionFunctionComputer(x) == true)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function deletes a connection between a computer and a scientist from the database.
bool listServices::deleteConnectionFromDatabase(int x, int y)
{
    bool check;

    if(_myData.deleteConnectionFunctionComputer(x) == true && _myData.deleteConnectionFunctionScientist(y) == true)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function creates and returns a new vector containing only living scientists.
vector<Scientist> listServices::searchAliveScientist()
{
    vector<Scientist> matchingScientists;

    //this loop goes through all scientists and adds them to the matchingScientists vector if and only if their year of death is listed as 0
    // which means that they are still living.
    for(unsigned int k = 0; k < displayScientist().size(); k++)
    {
        if(displayScientist()[k].getDeathYear() == 00)
        {
            matchingScientists.push_back(displayScientist()[k]);
        }
    }
    return matchingScientists;
}

//This function creates and returns a new vector containing only living scientists.
vector<Scientist> listServices::searchDeadScientist()
{
    vector<Scientist> matchingScientists;

    //this loop goes through all scientists and adds them to the matchingScientists vector if and only if their year of death is listed as 0
    // which means that they are still living.
    for(unsigned int k = 0; k < displayScientist().size(); k++)
    {
        if(!(displayScientist()[k].getDeathYear() == 00))
        {
            matchingScientists.push_back(displayScientist()[k]);
        }
    }
    return matchingScientists;
}

//This function recives the the right corresponding computer for name the user has inputed.
vector<Computer> listServices::searchForNameComputer(string s)
{
    vector<Computer> returnComputers;
    returnComputers = _myData.checkInComputer(s);
    return returnComputers;
}

//This function recives the the right corresponding computer for type of computer the user has inputed.
vector<Computer> listServices::searchForTypeComputer(string s)
{
    vector<Computer> returnComputers;
    returnComputers = _myData.checkInComputerType(s);
    return returnComputers;
}

//This function recives the the right corresponding computer bult in the year the user has inputed.
vector<Computer> listServices::searchWhenBuiltSingleYear(int a)
{
    vector<Computer> returnRange;
    returnRange = _myData.checkInComputerSingleYear(a);
    return returnRange;
}

//This function collects scientist that have an award from the database.
vector<Scientist> listServices::checkForAward(int x)
{
    vector<Scientist> award;
    award = _myData.searchForTuringAwardWinners(x);
    return award;
}

//This function collects scientist by there birthyear from the database.
vector<Scientist> listServices::checkBirthYear(int x)
{
    vector<Scientist> award;
    award = _myData.searchForYearOfBirth(x);
    return award;
}

//This function collects scientist by there deathyear from the database.
vector<Scientist> listServices::checkDeathYear(int x)
{
    vector<Scientist> award;
    award = _myData.searchForDeadPeople(x);
    return award;
}

//This function collects computers by their name from the database.
vector<Scientist> listServices::checkName(string s)
{
    vector<Scientist> names;
    names = _myData.searchForNameFromDatabase(s);
    return names;
}

//This function collects scientist by their nationality from the database.
vector<Scientist> listServices::checkNationality(string s)
{
    vector<Scientist> names;
    names = _myData.searchNationality(s);
    return names;
}

//This function lets the user update the scientists first name.
bool listServices::updateFirstNameScientist(string x, int id)
{
    bool check;

    if (_myData.updateFirstName(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the scientists last name.
bool listServices::updateLastNameScientist(string x, int id)
{
    bool check;
    if (_myData.updateLastName(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the scientists gender.
bool listServices::updateGenderScientist(char x, int id)
{
    bool check;

    if (_myData.updateGender(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the scientists nationality.
bool listServices::updateNationalityScientist(string x, int id)
{
    bool check;

    if (_myData.updateNationality(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the scientists year of birth.
bool listServices::updateYOBScientist(int x, int id)
{
    bool check;

    if (_myData.updateYOB(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the scientists year of birth.
bool listServices::updateYODScientist(int x, int id)
{
    bool check;

    if (_myData.updateYOD(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the year the scientist recived the Turning Award.
bool listServices::updateYOAScientist(int x, int id)
{
    bool check;

    if (_myData.updateYOA(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the name of the computers.
bool listServices::updateNameComputer(string x, int id)
{
    bool check;

    if (_myData.updateNameComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the type of computer.
bool listServices::updateTypeComputer(string x, int id)
{
    bool check;

    if (_myData.updateTypeComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update the year the computer was created.
bool listServices::updateYOCComputer(int x, int id)
{
    bool check;

    if (_myData.updateYOCComputer(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function lets the user update if the computer was built.
bool listServices::updateWasBuilt(int x, int id)
{
    bool check;

    if (_myData.updateWasComputerBuilt(x, id))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//to get the longest name in order to align the table right.
int listServices::searchLongestNameScientist()
{
    vector<Scientist> display;
    display = _myData.readAllFromScientistsDataBase();

    unsigned int longest = 7;

    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(longest < display[i].getFirstName().size())
        {
            longest = display[i].getFirstName().size();
        }
    }

    unsigned int newLongest = longest;

    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(newLongest < display[i].getLastName().size())
        {
            newLongest = display[i].getLastName().size();
        }
    }
    return newLongest + 2;
}

//to get the longest name in order to align the table right.
int listServices::searchLongestNameComputer()
{
    vector<Computer> display;
    display = _myData.readAllFromDataComputerBase();

    unsigned int longest = 7;

    for(unsigned int i = 0; i < display.size(); i++)
    {
        if(longest < display[i].getComputerName().size())
        {
            longest = display[i].getComputerName().size();
        }
    }
    return longest + 2;
}

//A constructor for listServices.
listServices::listServices()
{

}

//Returns the computers ID in an ascending order.
vector<Computer> listServices::computerIdAscendingOrder()
{
    vector<Computer> returnIdAscComputer;
    returnIdAscComputer = _myData.readIdInAscendingOrder();
    return returnIdAscComputer;
}

//Returns the computers ID in a descending order.
vector<Computer> listServices::computerIdDescendingOrder()
{
    vector<Computer> returnIdDescComputer;
    returnIdDescComputer = _myData.readIdInDescindingOrder();
    return returnIdDescComputer;
}

//Returns the computers type in an ascending order.
vector<Computer> listServices::computertypeAscendingOrder()
{
    vector<Computer> returntypeAscComputer;
    returntypeAscComputer = _myData.readTypeInAlphabeticalOrder();
    return returntypeAscComputer;
}

//Returns the computers type in an descending order.
vector<Computer> listServices::computertypeDescendingOrder()
{
    vector<Computer> returntypeDescComputer;
    returntypeDescComputer = _myData.readTypeInReverseAlphabeticalOrder();
    return returntypeDescComputer;
}

//Returns a list of connections between scientists and computers.
vector<searching> listServices::displayAllFromSearching()
{
    vector<searching> displayAllScientistComputer;
    displayAllScientistComputer = _myData.displayAllfromSearching();
    return displayAllScientistComputer;
}

//Checks in database for username when logging in.
vector<userandpass> listServices::checkForUsers()
{
    vector<userandpass> checkUser;
    checkUser = _myData.readLogin();
    return checkUser;
}

//Registers a new user (password and username) to the database.
void listServices::regiserUsers(userandpass newUser)
{
    _myData.registerUser(newUser);
}

QByteArray listServices::returnBitArry(QByteArray bit)
{
    return bit;
}

//Returns the scientist by their first name in an acending order.
vector<searching> listServices::readInAscendingByFirstName()
{
    vector<searching> readInAscendingByFirstName;
    readInAscendingByFirstName = _myData.displayFirstNamefromSearchingAscendingOrder();
    return readInAscendingByFirstName;
}

//Returns the scientist by their first name in a descending order.
vector<searching> listServices::readInDiscendingFirstName()
{
    vector<searching> readInDiscendingFirstName;
    readInDiscendingFirstName = _myData.displayFirstNamefromSearchingDescendingOrder();
    return readInDiscendingFirstName;
}

//Returns the scientist by their last name in an acending order.
vector<searching> listServices::readInAscendingByLastName()
{
    vector<searching> readInAscendingByLastName;
    readInAscendingByLastName = _myData.displayLastNamefromSearchingAscendingOrder();
    return readInAscendingByLastName;
}

//Returns the scientist by their first name in a descending order.
vector<searching> listServices::readInDiscendingLastName()
{
    vector<searching> readInDiscendingLastName;
    readInDiscendingLastName = _myData.displayLastNamefromSearchingDescendingOrder();
    return readInDiscendingLastName;
}

//Returns a computer by its name in an acending order.
vector<searching> listServices::readInAscendingByCompName()
{
    vector<searching> readInAscendingByCompName;
    readInAscendingByCompName = _myData.displayComputerNamefromSearchingAscendingOrder();
    return readInAscendingByCompName;
}

//Returns a computer by its name in a descending order.
vector<searching> listServices::readInDiscendingCompName()
{
    vector<searching> readInDiscendingCompName;
    readInDiscendingCompName = _myData.displayComputerNamefromSearchingDescendingOrder();
    return readInDiscendingCompName;
}

//Returns a computer by its type in an acending order.
vector<searching> listServices::readInAscendingByCompType()
{
    vector<searching> readInAscendingByCompType;
    readInAscendingByCompType = _myData.displayComputerTypefromSearchingAscendingOrder();
    return readInAscendingByCompType;
}

//Returns a computer by its name in a descending order.
vector<searching> listServices::readInDiscendingByCompType()
{
    vector<searching> readInDiscendingByCompType;
    readInDiscendingByCompType = _myData.displayComputerTypefromSearchingDescendingOrder();
    return readInDiscendingByCompType;
}

//Returns a computer by the year it was created in an acending order.
vector<searching> listServices::readInAscendingByYearBuilt()
{
    vector<searching> readInAscendingByYearBuilt;
    readInAscendingByYearBuilt = _myData.displayComputerYearfromSearchingAscendingOrder();
    return readInAscendingByYearBuilt;
}

//Returns a computer by the year it was created in a descending order.
vector<searching> listServices::readInDiscendingByYearBuilt()
{
    vector<searching> readInDiscendingByYearBuilt;
    readInDiscendingByYearBuilt = _myData.displayComputerYearfromSearchingDescendingOrder();
    return readInDiscendingByYearBuilt;
}
