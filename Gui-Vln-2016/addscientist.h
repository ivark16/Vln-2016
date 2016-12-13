#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include <string>
#include "listservices.h"

using namespace std;

namespace Ui {
class addScientist;
}

class addScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addScientist(QWidget *parent = 0);
    ~addScientist();

private slots:


    void on_addScientistButton_clicked();

private:
    Ui::addScientist *ui;
    listServices _connection;
    string _firstName;
    string _lastName;
    char _gender;
    string _nationality;
    int _birthYear;
    int _deathYear;
    int _awardYear;


    bool checkForEmpty();
    bool getGender();
    bool getFirstName();

};

#endif // ADDSCIENTIST_H
