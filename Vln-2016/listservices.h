#ifndef LISTSERVICES_H
#define LISTSERVICES_H
#include "scientistList.h"
#include "DataLayer.h"
#include <vector>

class listServices
{
    vector<scientistList> _computerScientists;
    DataLayer _myData;
    scientistList _data;
public:
    listServices();
    string getFirstNameFromList(int i);
    string getLastNameFromList(int i);
    string getNationalityFromList(int i);
    string fullNameFromList(int i) const; // Returns full name from scientistList
    int dobFromList(int i) const; // Returns date of birth from scientistList
    int dodFromList(int i) const; // Returns date of death from scientistList
    int getSizeOfScientistList();
    char getGenderFromListAt(int i);
    int getAwardsFromList(int i) const;

    //FREEESH
    void searchForName(string name);
    vector<Scientist> displayScientist();
    vector<Computer> displayComputer();
    int getSizeOfData();
    vector<Scientist> scientistInAlphabeticalOrder();
    vector<Computer> computerInAlphabeticalOrder();
    int searchLongestNameScientist();
    int searchLongestNameComputer();
    vector<Scientist> oldestOrderScientist();






    //GAMALT
    vector<scientistList> searchName(string searchTerm); // Returns vector with scientists with same name as the string
    vector<scientistList> sortByName(); // Returns vectors with names in alphabetical order
    vector<scientistList>   sortByBirth(); // Returns vector with dob in correct order (lowest first and so on)
    vector<scientistList>   sortByAward(); // Returns vector with Turing awards in correct order (lowest first and so on)
    // The function below adds a new scientist to the file by calling constructor in scientistList.
    void   addNew(string firstName, string lastName, char gender, string nationality, int birthYear, int deathYear, int awardYear);
    vector<scientistList>   searchLastName(string lastName); // Searches last name and returns the persons in vector
    vector<scientistList>   searchFirstName(string firstName); // Searches first name and returns the persons in vector
    vector<scientistList>   searchBirth(int minYear, int maxYear); // Searches scientists with same birthdays as the user inputs and returns vector
    vector<scientistList>   searchAlive(); // Searches if the person is alive and returns a vector
    vector<scientistList>   searchAward(int awardYear); // Searches if the anyone has won Turing award in the database and returns vector
    vector<scientistList>   chuckNorris(); // Changes every scientist into Chuck Norris because Chuck Norris
    void changeTo(vector<scientistList> rhs); // This function is used to assign a vector rhs to another vector
    int getSize (); // Returns size of vector
    int searchLongestName(); // returns size of longest name
    string changeToLower(string input); // Changes uppercase letters to lower case letters
    void deleteFromList(int ID); //Deletes a scientist from the list
    void writeNewFile(); //Overwrites the vector to a new .txt file
};

#endif // LISTSERVICES_H
