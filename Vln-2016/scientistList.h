#ifndef SCIENTISTLIST_H
#define SCIENTISTLIST_H
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;


class scientistList
{
private:
    string _firstName;
    string _lastName;
    string _nationality;
    int _birthYear;
    int _deathYear;
    char _sex;
    int _TuringAwards;

public:
    scientistList();
    scientistList(string nafn1, string nafn2, char kyn, string nationality, int faedingarAr, int danarar, int verdlaun); // Constructor that appends to file
    void readFile (vector <scientistList>& science); // Reads from file into vector from Listservices
    string getFirstName() const;
    string getLastName() const;
    string getNationality() const;
    string fullName() const; // Returns full name
    int dob() const; // Returns date of birth
    int dod() const; // Returns date of death
    char getSex () const;
    int getAwards() const; // Returns year of turing award winner

    void setFirstName(string name);
    void setLastName(string name);
    void writeToFile(vector<scientistList> &newFile);

};

#endif // SCIENTISTLIST_H
