#include "editscientist.h"
#include "ui_editscientist.h"
#include <QMessageBox>

editscientist::editscientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscientist)
{
    ui->setupUi(this);
    ui ->genderSelectBox ->addItem("Male");
    ui ->genderSelectBox ->addItem("Female");
    ui ->genderSelectBox ->addItem("Other");
}

editscientist::~editscientist()
{
    delete ui;
}

void editscientist::displayForUpdate(int Id)
{
    _ID = Id;

    vector<Scientist> newvector;
    newvector = _lists.displayScientistById(Id);
    QString firstname = QString::fromStdString(newvector[0].getFirstName());
    QString lastname = QString::fromStdString(newvector[0].getLastName());

    //QChar gender = QChar::isLetter();
    if(newvector[0].getGender() == 'm' || newvector[0].getGender() == 'M')
    {
        ui->genderSelectBox->setCurrentIndex(0);
    }
    else if (newvector[0].getGender() == 'f' || newvector[0].getGender() == 'F')
    {
        ui->genderSelectBox->setCurrentIndex(1);
    }
    else
    {
        ui->genderSelectBox->setCurrentIndex(2);
    }

    QString nation = QString::fromStdString(newvector[0].getNationality());
    QString yob = QString::number(newvector[0].getBirthYear());
    QString yod = QString::number(newvector[0].getDeathYear());
    QString yoa = QString::number(newvector[0].getAwardYear());

    ui->lineEditFirstName->setText(firstname);
    ui->lineEditLastName->setText(lastname);
    //ui->lineEditGender->setText(gender);
    ui->lineEditNationality->setText(nation);
    ui->lineEditYOB->setText(yob);
    ui->lineEditYOD->setText(yod);

    if(yoa == "0")
    {
        ui->lineEditYOA->setText("No award");
    }
    else
    {
        ui->lineEditYOA->setText(yoa);
    }
}


void editscientist::on_pushButtonUpdate_clicked()
{
    bool isLegalScientist;
    //this runs if no required fields are empty.

    bool hasFirstName = getFirstName();
    bool hasLastName = getLastName();
    bool hasGender = getGender();
    bool hasNationality = getNationality();
    bool hasBirthYear = getBirthYear();
    bool hasDeathYear = getDeathYear();
    bool hasAwardYear = getAwardYear(); // =_awardYear =(ui ->turingAwardBox -> text()).toInt();

    //A scientist is only legal if they have a name, gender, nationality, birth year and if they have a death year or
    isLegalScientist = (hasFirstName && hasLastName && hasGender && hasNationality && hasBirthYear && hasDeathYear);

    if(isLegalScientist)
    {
        _lists.updateFirstNameScientist(_firstName, _ID);
        _lists.updateLastNameScientist(_lastName, _ID);
        _lists.updateGenderScientist(_gender, _ID);
        _lists.updateNationalityScientist(_nationality, _ID);
        _lists.updateYOBScientist(_birthYear, _ID);
        _lists.updateYODScientist(_deathYear, _ID);
        _lists.updateYOAScientist(_awardYear, _ID);

        QMessageBox popup;
        popup.setText("The scientist has successfully been updated to the database");
        popup.exec();
    }
}

bool editscientist::getGender()
{
    if((ui->genderSelectBox->currentIndex()) == 0)
    {
        _gender = 'm';
        return true;
    }
    else if((ui ->genderSelectBox->currentIndex()) == 1)
    {
        _gender = 'f';
        return true;
    }
    else if((ui ->genderSelectBox ->currentIndex()) == 2)
    {
        _gender = 'o';
        return true;
    }
}

//The integer this function returns indicates whether the name is legal, and if not, what the problem is.
bool editscientist::getFirstName()
{

    string potentialName = ui -> lineEditFirstName ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditFirstName->text()).isEmpty())
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
        ui ->labelFirstName ->setText("<span style='color: red'>First name required</span>");
    }
    else if(!hasOnlyChar)
    {
        ui ->labelFirstName ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> labelFirstName ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _firstName = potentialName;
    }
    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));


}

bool editscientist::getLastName()
{

    string potentialName = ui -> lineEditLastName ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditLastName->text()).isEmpty())
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
        ui ->labelLastName->setText("<span style='color: red'>Last name required</span>");
    }
    else if(!hasOnlyChar)
    {
        ui ->labelLastName ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> labelLastName ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the last name is legal.
        _lastName = potentialName;
    }
    return (hasContent && hasOnlyChar && !(potentialName.size() < 3 || potentialName.size() > 16));

}

bool editscientist::getNationality()
{

    string potentialNationality = ui -> lineEditNationality ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditNationality->text()).isEmpty())
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
        ui ->labelNationality ->setText("<span style='color: red'>Nationality required</span>");

    }
    else if(!hasOnlyChar)
    {
        ui ->labelNationality ->setText("<span style='color: red'>Nationality can only contain latin characters</span>");
    }
    else if(potentialNationality.size() < 4 || potentialNationality.size() > 21)
    {
        ui ->labelNationality ->setText("<span style=' color: red'>Nationality be between 4 and 20 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _nationality = potentialNationality;
    }

    return (hasContent && hasOnlyChar && !(potentialNationality.size() < 4 || potentialNationality.size() > 21));
}

bool editscientist::getBirthYear()
{
    int potentialBirthYear = ui -> lineEditYOB ->text().toInt();
    string potentialBirthYearString =(ui ->lineEditYOB ->text()).toStdString();

    bool hasContent = true;
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->lineEditYOB->text()).isEmpty())
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
        ui -> LabelYOB ->setText("<span style='color: red'>Birth year required</span>");

    }
    else if(!hasOnlyNumbers)
    {
        ui ->LabelYOB ->setText("<span style='color: red'>Birth year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->LabelYOB ->setText("<span style=' color: red'>No computer scientists born in this year </span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _birthYear = potentialBirthYear;
    }
    return(hasContent && hasOnlyNumbers && isInRange);

}

bool editscientist::getDeathYear()
{
    int potentialDeathYear = ui ->lineEditYOD ->text().toInt();
    string potentialDeathYearString =(ui ->lineEditYOD ->text()).toStdString();

    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->lineEditYOD->text()).isEmpty())
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
        ui ->labelYOD ->setText("<span style='color: red'>Death year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->labelYOD ->setText("<span style=' color: red'>Not legal death year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _deathYear = potentialDeathYear;
    }

    return(hasOnlyNumbers && isInRange);
}

bool editscientist::getAwardYear()
{
    int potentialAwardYear = ui ->lineEditYOA ->text().toInt();
    string potentialAwardYearString =(ui ->lineEditYOA ->text()).toStdString();

    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->lineEditYOA->text()).isEmpty())
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
    if(potentialAwardYear <_birthYear || (potentialAwardYear > _deathYear && _deathYear != 0) || potentialAwardYear > 2016 && potentialAwardYear < 1966)
    {
        isInRange = false;
    }

    //throws errors when necessary

    if(!hasOnlyNumbers)
    {
        ui ->lineEditYOA ->setText("<span style='color: red'>Award year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->lineEditYOA ->setText("<span style=' color: red'>Not legal award year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _awardYear = potentialAwardYear;
    }
    return(hasOnlyNumbers && isInRange);

}

