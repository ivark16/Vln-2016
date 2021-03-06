#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include <string>
#include "listservices.h"

using namespace std;

namespace Ui
{
class addScientist;
}

class addScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addScientist(QWidget *parent = 0);
    ~addScientist();

private slots:

    //adds the scientist if it is valid, validity checked by calling to other functions (below).
    void on_addScientistButton_clicked();

private:
    Ui::addScientist *ui;
    listServices _connection;
    string _firstName;
    string _lastName;
    string _nationality;
    char _gender;
    int _birthYear;
    int _deathYear;
    int _awardYear;

    //the functions below check the validity of the entered fields
    bool getGender();
    bool getFirstName();
    bool getLastName();
    bool getNationality();
    bool getBirthYear();
    bool getDeathYear();
    bool getAwardYear();

};

#endif // ADDSCIENTIST_H
