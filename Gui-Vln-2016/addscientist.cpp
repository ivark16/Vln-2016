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

        bool hasFirstName = getFirstName();
        bool hasLastName = getLastName();
        bool hasGender = getGender();
        bool hasNationality = getNationality();
        bool hasBirthYear = getBirthYear();
        bool hasDeathYear = getDeathYear();
        bool hasAwardYear; // =_awardYear =(ui ->turingAwardBox -> text()).toInt();

    //if it's all legal, add the scientist to the database.  Maybe open a little popup.



        isLegalScientist = (hasFirstName && hasLastName && hasGender && hasNationality && hasBirthYear);


    if(isLegalScientist)
    {
        Scientist newScientist(0, _firstName, _lastName, 'm', _nationality, _birthYear, _deathYear, _awardYear);
        _connection.addScientistToDatabase(newScientist);

        ui -> firstNameLabel -> setText("GREAT SUCCESS");
    }

}

//NOT NEEDED!!
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
    if(ui->genderSelectBox ->currentIndex() == 0 || ui->genderSelectBox ->currentIndex() == 1)
    {
        ui ->genderLabel ->setText("<span style='color: red'>Gender required</span>");
        hasContent = false;
    }
    //hasContent is true if and only if all required fields have entries.
    return hasContent;
}

bool addScientist::getGender()
{
    if((ui->genderSelectBox->currentIndex()) == 2)
    {
        _gender = 'm';
        return true;
    }
    else if((ui ->genderSelectBox->currentIndex()) == 3)
    {
        _gender = 'f';
        return true;
    }
    else if((ui ->genderSelectBox ->currentIndex()) == 4)
    {
        _gender = 'o';
        return true;
    }
    else
    {
        ui -> genderLabel ->setText("<span style=' color: red'>Gender required</span>");
        return false;
    }
}

//The integer this function returns indicates whether the name is legal, and if not, what the problem is.
bool addScientist::getFirstName()
{

    string potentialName = ui ->firstNameBox ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->firstNameBox->text()).isEmpty())
    {
        hasContent = false;
    }

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

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->firstNameLabel ->setText("<span style='color: red'>First name required</span>");

    }
    else if(!hasOnlyChar)
    {
        ui ->firstNameLabel ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> firstNameLabel ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _firstName = potentialName;
    }

    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));
}

bool addScientist::getLastName()
{

    string potentialName = ui ->lastNameBox ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lastNameBox->text()).isEmpty())
    {
        hasContent = false;
    }

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

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->lastNameLabel ->setText("<span style='color: red'>Last name required</span>");
    }
    else if(!hasOnlyChar)
    {
        ui ->lastNameLabel ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> lastNameLabel ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the last name is legal.
        _lastName = potentialName;
    }

    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));
}

bool addScientist::getNationality()
{

    string potentialNationality = ui ->nationalityBox ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->nationalityBox->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    for(unsigned int i = 0; i < potentialNationality.size(); i++)
    {
        if(isalpha(potentialNationality[i]))
        {
            //do nothing
        }
        else
        {
            hasOnlyChar = false;
        }
    }

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->nationalityLabel ->setText("<span style='color: red'>Nationality required</span>");

    }
    else if(!hasOnlyChar)
    {
        ui ->nationalityLabel ->setText("<span style='color: red'>Nationality can only contain latin characters</span>");
    }
    else if(potentialNationality.size() < 5 || potentialNationality.size() > 21)
    {
        ui ->nationalityLabel ->setText("<span style=' color: red'>Nationality be between 4 and 20 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _nationality = potentialNationality;
    }

    return (hasContent && hasOnlyChar && !(potentialNationality.size() < 5 || potentialNationality.size() > 21));
}

bool addScientist::getBirthYear()
{
    int potentialBirthYear = ui ->birthYearBox ->text().toInt();
    string potentialBirthYearString =(ui ->birthYearBox ->text()).toStdString();

    bool hasContent = true;
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->birthYearBox->text()).isEmpty())
    {
        hasContent = false;
    }

    //checks that it has only numbers
    for(unsigned int i = 0; i < potentialBirthYearString.size();i++)
    {
        if(!isdigit(potentialBirthYearString[0]))
        {
            hasOnlyNumbers = false;
        }
    }

    //checks that it is in range
    if(potentialBirthYear <1791 || potentialBirthYear > 2016)
    {
        isInRange = false;
    }

    //throws errors when necessary
    if(!hasContent)
    {
        ui ->birthYearLabel ->setText("<span style='color: red'>Birth year required</span>");

    }
    else if(!hasOnlyNumbers)
    {
        ui ->birthYearLabel ->setText("<span style='color: red'>Birth year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->birthYearLabel ->setText("<span style=' color: red'>No computer scientists born in this year </span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _birthYear = potentialBirthYear;
    }


    return(hasContent && hasOnlyNumbers && isInRange);

}

bool addScientist::getDeathYear()
{
    int potentialDeathYear = ui ->deathYearBox ->text().toInt();
    string potentialDeathYearString =(ui ->deathYearBox ->text()).toStdString();

    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->deathYearBox->text()).isEmpty())
    {
        _deathYear = 0;
        return true;
    }

    //checks that it has only numbers
    for(unsigned int i = 0; i < potentialDeathYearString.size();i++)
    {
        if(!isdigit(potentialDeathYearString[0]))
        {
            hasOnlyNumbers = false;
        }
    }
    //checks that it is in range
    if(potentialDeathYear <_birthYear || potentialDeathYear > 2016)
    {
        isInRange = false;
    }

    //throws errors when necessary

    if(!hasOnlyNumbers)
    {
        ui ->deathYearLabel ->setText("<span style='color: red'>Death year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->deathYearLabel ->setText("<span style=' color: red'>Not legal death year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _deathYear = potentialDeathYear;
    }

    return(hasOnlyNumbers && isInRange);

}
