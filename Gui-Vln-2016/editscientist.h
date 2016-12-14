#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include <vector>
#include "listservices.h"
#include "scientist.h"

namespace Ui {
class editscientist;
}

class editscientist : public QDialog
{
    Q_OBJECT

public:
    explicit editscientist(QWidget *parent = 0);
    ~editscientist();
    void displayForUpdate(int Id);

private slots:

    void on_pushButtonUpdate_clicked();

private:
    int _ID;
    Ui::editscientist *ui;
    listServices _lists;
    string _firstName;
    string _lastName;
    char _gender;
    string _nationality;
    int _birthYear;
    int _deathYear;
    int _awardYear;

    bool getGender();
    bool getFirstName();
    bool getLastName();
    bool getNationality();
    bool getBirthYear();
    bool getDeathYear();
    bool getAwardYear();


};

#endif // EDITSCIENTIST_H
