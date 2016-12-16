#include "addscientist.h"
#include "ui_addscientist.h"
#include "scientist.h"
#include "listservices.h"
#include <string>
#include <cstdlib>
#include <QMessageBox>

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
    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

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
    ui ->turingAwardLabel ->setText("");

    //this runs if no required fields are empty.
    bool hasFirstName = getFirstName();
    bool hasLastName = getLastName();
    bool hasGender = getGender();
    bool hasNationality = getNationality();
    bool hasBirthYear = getBirthYear();
    bool hasDeathYear = getDeathYear();
    bool hasAwardYear = getAwardYear(); // =_awardYear =(ui ->turingAwardBox -> text()).toInt();

    //A scientist is only legal if they have a name, gender, nationality, birth year and if they have a death year or
    isLegalScientist = (hasFirstName && hasLastName && hasGender && hasNationality && hasBirthYear && hasDeathYear && hasAwardYear);

    if(isLegalScientist)
    {
        //adds the scientist to the database
        Scientist newScientist(0, _firstName, _lastName, _gender, _nationality, _birthYear, _deathYear, _awardYear);
        _connection.addScientistToDatabase(newScientist);
        QMessageBox popup;
        popup.setText("The scientist has successfully been added to the database.");
        popup.exec();

        //sets all text boxes to empty, in case the user wants to add another scientist.
        ui ->birthYearBox ->setText("");
        ui ->deathYearBox ->setText("");
        ui ->firstNameBox ->setText("");
        ui ->genderSelectBox ->setCurrentIndex(0);
        ui ->lastNameBox -> setText("");
        ui ->nationalityBox -> setText("");
        ui ->turingAwardBox -> setText ("");
    }
}

//checks the validity of the gender entered by the user
bool addScientist::getGender()
{
    if((ui->genderSelectBox->currentIndex()) == 2)
    {
        _gender = 'M';
        return true;
    }
    else if((ui ->genderSelectBox->currentIndex()) == 3)
    {
        _gender = 'F';
        return true;
    }
    else if((ui ->genderSelectBox ->currentIndex()) == 4)
    {
        _gender = 'O';
        return true;
    }
    //if no gender is selected it displays an error
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
    //else no errors, valid first name
    else
    {
        //Make sure that the first letter of the name is upper case
        potentialName[0] = toupper(potentialName[0]);
        //If there are no problems, the first name is legal.
        _firstName = potentialName;
    }
    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));
}

//checks the validity of the entered name
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
    //else no issues, name is valid
    else
    {
        //make sure the first letter is uppercase
        potentialName[0] = toupper(potentialName[0]);
        //If there are no problems, the last name is legal.
        _lastName = potentialName;
    }
    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));
}

//checks the validity of the nationality
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
        if(isalpha(potentialNationality[i]) || potentialNationality[i] == ' ')
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
    else if(potentialNationality.size() < 4 || potentialNationality.size() > 21)
    {
        ui ->nationalityLabel ->setText("<span style=' color: red'>Nationality be between 4 and 20 characters</span>");
    }
    //else no errors, nationality is valid
    else
    {
        //make sure the first letter is upper case so it sorts correctly
        potentialNationality[0] = toupper(potentialNationality[0]);
        //If there are no problems, the first name is legal.
        _nationality = potentialNationality;
    }
    return (hasContent && hasOnlyChar && !(potentialNationality.size() < 4 || potentialNationality.size() > 21));
}

//checks the validity of the entered birth year
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

//checks the validity of the entered year of death (if there is one, this field can be left blank)
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

//checks the validity of the award year if there is one, it is not a required field
bool addScientist::getAwardYear()
{
    int potentialAwardYear = ui ->turingAwardBox ->text().toInt();
    string potentialAwardYearString =(ui ->turingAwardBox ->text()).toStdString();
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->turingAwardBox->text()).isEmpty())
    {
        _awardYear = 0;
        return true;
    }

    //checks that it has only numbers
    for(unsigned int i = 0; i < potentialAwardYearString.size();i++)
    {
        if(!isdigit(potentialAwardYearString[0]))
        {
            hasOnlyNumbers = false;
        }
    }
    //checks that it is in range
    if((potentialAwardYear <_birthYear) || ((potentialAwardYear > _deathYear) || (_deathYear != 0)) || ((potentialAwardYear > 2016) && (potentialAwardYear < 1966)))
    {
        isInRange = false;
    }

    //throws errors when necessary
    if(!hasOnlyNumbers)
    {
        ui ->turingAwardLabel ->setText("<span style='color: red'>Award year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->turingAwardLabel ->setText("<span style=' color: red'>Not legal award year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _awardYear = potentialAwardYear;
    }
    return(hasOnlyNumbers && isInRange);
}
