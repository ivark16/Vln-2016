#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <QMessageBox>

editcomputer::editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputer)
{
    //List in combobox
    ui->setupUi(this);
    ui ->BuiltStatus ->addItem("Built status");
    ui ->BuiltStatus ->addItem("---");
    ui ->BuiltStatus ->addItem("Was built");
    ui ->BuiltStatus ->addItem("Was not built");
}

editcomputer::~editcomputer()
{
    delete ui;
}

//Displays in lineeditwhat computer user has chosen in mainwindow
void editcomputer::displayForUpdate(int id)
{
    _ID = id;
    vector<Computer> newvector;
    newvector = _lists.displayComputerById(id);
    QString name = QString::fromStdString(newvector[0].getComputerName());
    QString type = QString::fromStdString(newvector[0].getComputerType());
    QString yob = QString::number(newvector[0].getYearOfBuild());
    int wasBuiltIndex;

    if(!newvector[0].getWasBuilt())
    {
        wasBuiltIndex = 3;
    }
    else if(newvector[0].getWasBuilt())
    {
        wasBuiltIndex = 2;
    }

    ui->lineEditName->setText(name);
    ui->lineEditType->setText(type);
    ui->YearOfCreation->setText(yob);
    ui ->BuiltStatus ->setCurrentIndex(wasBuiltIndex);
}

void editcomputer::on_pushButtonUpdateComputer_clicked()
{
    bool isLegitComputer;
    bool hasName = getNAme();
    bool hasType = getType();
    bool hasBuildYear = getYearOfBuild();
    bool hasBuiltStatus = wasBuilt();

    isLegitComputer = (hasName && hasType && hasBuildYear && hasBuiltStatus);

    if(isLegitComputer)
    {
        _lists.updateNameComputer(_name, _ID);
        _lists.updateTypeComputer(_type, _ID);
        _lists.updateYOCComputer(_yearBuilt, _ID);
        _lists.updateWasBuilt(_wasBuilt, _ID);

        QMessageBox popup;
        popup.setText("The Computer has successfully been updated in the database");
        popup.exec();
    }
}

//Error check if the name is within certain parameters
bool editcomputer::getNAme()
{
    string potentialName = ui -> lineEditName ->text().toStdString();

    bool hasLegalCharacters = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditName->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    for(unsigned int i = 0; i < potentialName.size(); i++)
    {
        if(isalpha(potentialName[i]) || isdigit(potentialName[i]) || potentialName[i] == ' ')
        {
            //do nothing
        }
        else
        {
            hasLegalCharacters = false;
        }
    }

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->nameLabel ->setText("<span style='color: red'>First name required</span>");

    }
    else if(!hasLegalCharacters)
    {
        ui ->nameLabel ->setText("<span style='color: red'>Name can only contain characters, numbers and spaces</span>");
    }
    else if(potentialName.size() < 2 || potentialName.size() > 16)
    {
        ui -> nameLabel ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _name = potentialName;
    }
    return (hasContent && hasLegalCharacters && !(potentialName.size() < 3 || potentialName.size() > 16));
}

//Error check if the type is within certain parameters
bool editcomputer::getType()
{
    string potentialType = ui -> lineEditType ->text().toStdString();
    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditType->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    for(unsigned int i = 0; i < potentialType.size(); i++)
    {
        if(isalpha(potentialType[i]))
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
        ui ->typeLabel ->setText("<span style='color: red'>Type required</span>");

    }
    else if(!hasOnlyChar)
    {
        ui ->typeLabel ->setText("<span style='color: red'>Type can only contain latin characters</span>");
    }
    else if(potentialType.size() < 2 || potentialType.size() > 16)
    {
        ui -> typeLabel ->setText("<span style=' color: red'>Type must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _type= potentialType;
    }
    return (hasContent && hasOnlyChar && !(potentialType.size() < 2 || potentialType.size() > 16));
}

//Error check if the yearbuild is within certain parameters
bool editcomputer::getYearOfBuild()
{
    int potentialBuildYear = ui -> YearOfCreation ->text().toInt();
    string potentialBuildYearString =(ui ->YearOfCreation ->text()).toStdString();
    bool hasContent = true;
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->YearOfCreation->text()).isEmpty())
    {
        hasContent = false;
    }

    //checks that it has only numbers
    for(unsigned int i = 0; i < potentialBuildYearString.size();i++)
    {
        if(!isdigit(potentialBuildYearString[0]))
        {
            hasOnlyNumbers = false;
        }
    }

    //checks that it is in range
    if(potentialBuildYear <1822 || potentialBuildYear > 2016)
    {
        isInRange = false;
    }

    //throws errors when necessary
    if(!hasContent)
    {
        ui -> YearOfCreationLabel ->setText("<span style='color: red'>Creation year required</span>");

    }
    else if(!hasOnlyNumbers)
    {
        ui ->YearOfCreationLabel ->setText("<span style='color: red'>Creation year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->YearOfCreationLabel ->setText("<span style=' color: red'>No computers made in this year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _yearBuilt = potentialBuildYear;
    }
    return(hasContent && hasOnlyNumbers && isInRange);
}

//Error check if the wasbuilt is within certain parameters
bool editcomputer::wasBuilt()
{
    if(ui ->BuiltStatus->currentIndex() <2 || ui ->BuiltStatus ->currentIndex() >3)
    {
        ui ->BuiltStatusLabel->setText("<span style=' color: red'>Built status required</span>");
        return false;
    }
    else if(ui ->BuiltStatus->currentIndex() == 2)
    {
        _wasBuilt = true;
        return true;
    }
    else
    {
        _wasBuilt = false;
        return true;
    }
}
