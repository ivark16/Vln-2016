#include "addscientist.h"
#include "ui_addscientist.h"
#include "scientist.h"
#include "listservices.h"
#include <string>
#include <cstdlib>

using namespace std;

addScientist::addScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientist)
{
    ui->setupUi(this);
    ui ->genderSelectBox ->addItem("Gender");
    ui ->genderSelectBox ->addItem("---");
    ui ->genderSelectBox ->addItem("Male");
    ui ->genderSelectBox ->addItem("Female");
    ui ->genderSelectBox ->addItem("Other");

}

addScientist::~addScientist()
{
    delete ui;
}


void addScientist::on_addScientistButton_clicked()
{
    //this boolean is true only when the entry is fully legal
    bool isLegalScientist = false;

    //set all errors to empty every time the button is clicked.
    ui ->birthYearLabel ->setText("");
    ui ->deathYearLabel ->setText("");
    ui ->firstNameLabel ->setText("");
    ui ->lastNameLabel ->setText("");
    ui ->genderLabel ->setText("");
    ui ->nationalityLabel ->setText("");

    //this runs if no required fields are empty.
    if(checkForEmpty())
    {
        bool hasFirstName = getFirstName(); // ui->firstNameBox->text().toStdString();
        _lastName = ui->lastNameBox->text().toStdString();
        bool hasGender = getGender();
        _nationality = ui ->nationalityBox->text().toStdString();
        _birthYear =  (ui ->birthYearBox ->text()).toInt();
        _deathYear = (ui -> deathYearBox -> text()).toInt();
        _awardYear =(ui ->turingAwardBox -> text()).toInt();
    }

    //if it's all legal, add the scientist to the database.  Maybe open a little popup.

    if(isLegalScientist)
    {
        Scientist newScientist(0, _firstName, _lastName, 'm', _nationality, _birthYear, _deathYear, _awardYear);
        _connection.addScientistToDatabase(newScientist);
    }

}

bool addScientist::checkForEmpty()
{
    bool hasContent = true;
    if((ui ->firstNameBox->text()).isEmpty())
    {
        ui -> firstNameLabel ->setText("<span style='color: red'>First name required</span>");
        hasContent = false;
    }
    if((ui ->lastNameBox->text()).isEmpty())
    {
        ui -> lastNameLabel ->setText("<span style='color: red'>Last name required</span>");
        hasContent = false;
    }
    if((ui ->nationalityBox->text()).isEmpty())
    {
        ui -> nationalityLabel ->setText("<span style='color: red'>Nationality required</span>");
        hasContent = false;
    }
    if((ui ->birthYearBox ->text()).isEmpty())
    {
        ui ->birthYearLabel ->setText("<span style='color: red'>Birth year required</span>");
        hasContent = false;
    }
    if(ui->genderSelectBox ->currentText() == "Gender" || ui->genderSelectBox ->currentText() == "---")
    {
        ui ->genderLabel ->setText("<span style='color: red'>Gender required</span>");
        hasContent = false;
    }
    //hasContent is true if and only if all required fields have entries.
    return hasContent;
}

bool addScientist::getGender()
{
    if(ui->genderLabel->selectedText() == "Male")
    {
        _gender = 'm';
        return true;
    }
    else if(ui ->genderLabel->selectedText() == "Female")
    {
        _gender = 'f';
        return true;
    }
    else if(ui ->genderLabel ->selectedText() == "Other")
    {
        _gender = 'o';
        return true;
    }
    else
    {
        return false;
    }
}

//The integer this function returns indicates whether the name is legal, and if not, what the problem is.
bool addScientist::getFirstName()
{
    string potentialName = ui ->firstNameBox ->text().toStdString();
    bool hasOnlyChar = true;

    //check that it has only characters
    for(unsigned int i = 0; i < potentialName.size(); i++)
    {
        if(isalpha(potentialName[i]))
        {
            //do nothing
        }
        else
        {
            hasOnlyChar = false;
        }
    }
    if(!hasOnlyChar)
    {
        ui ->birthYearLabel ->setText("<span style=' color: red'>....</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> birthYearLabel ->setText("<span style=' color: red'> Names must be between 2 and 16 characters </span>");
    }


    return (hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));
}
