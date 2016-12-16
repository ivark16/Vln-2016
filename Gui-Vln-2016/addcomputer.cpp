#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "listservices.h"
#include "computer.h"
#include <QMessageBox>
#include <cstdlib>

using namespace std;

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);
    ui ->wasBuiltBox ->addItem("Built status");
    ui ->wasBuiltBox ->addItem("---");
    ui ->wasBuiltBox ->addItem("Was built");
    ui ->wasBuiltBox ->addItem("Was not built");

    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

addComputer::~addComputer()
{
    delete ui;
}

//adds the scientist if it is valid when the button is clicked
void addComputer::on_addComputer_2_clicked()
{
    //set all errors to empty every time the button is clicked.
    ui ->computerNameLabel ->setText("");
    ui ->computerTypeLabel ->setText("");
    ui ->YearOfCreationLabel ->setText("");
    ui ->WasBuiltLabel ->setText("");

    //runs all functions that check the legality of the entered fields
    bool hasName = getComputerName();
    bool hasType = getComputerType();
    bool hasYearCreated = getYearCreated();
    bool hasBuiltStatus = getBuiltStatus();
    bool isLegalComputer = (hasName && hasType && hasYearCreated && hasBuiltStatus);

    if(isLegalComputer)
    {
        Computer newComputer(0, _computerName, _computerType, _yearBuilt, _wasBuilt);
        _connection.addComputerToDatabase(newComputer);
        QMessageBox popup;
        popup.setText("The computer has been added to the database.");
        popup.exec();

        //sets all text boxes to empty, in case the user wants to add another scientist.
        ui ->computerName ->setText("");
        ui ->computerType ->setText("");
        ui ->yearOfCreation ->setText("");
        ui ->wasBuiltBox ->setCurrentIndex(0);
    }
}

//checks the validity of the entered computer name
bool addComputer::getComputerName()
{
    string potentialName = ui ->computerName ->text().toStdString();
    bool hasLegalCharacters = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->computerName->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters, numbers or spaces
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
        ui ->computerNameLabel ->setText("<span style='color: red'>Name required</span>");
    }
    else if(!hasLegalCharacters)
    {
        ui ->computerNameLabel ->setText("<span style='color: red'>Name can only contain characters, numbers or spaces</span>");
    }
    else if(potentialName.size() < 3 || potentialName.size() > 16)
    {
        ui -> computerNameLabel ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //Make sure that the first letter of the name is upper case
        potentialName[0] = toupper(potentialName[0]);
        //If there are no problems, the first name is legal.
        _computerName = potentialName;
    }
    return (hasContent && hasLegalCharacters && !(potentialName.size() < 3 || potentialName.size() > 16));
}

//checks the validity of the computer type
bool addComputer::getComputerType()
{
    string potentialType = ui ->computerType ->text().toStdString();
    bool hasLegalCharacters = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->computerType->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters, numbers or spaces
    for(unsigned int i = 0; i < potentialType.size(); i++)
    {
        if(isalpha(potentialType[i]) || isdigit(potentialType[i]) || potentialType[i] == ' ')
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
        ui ->computerTypeLabel ->setText("<span style='color: red'>Type required</span>");
    }
    else if(!hasLegalCharacters)
    {
        ui ->computerTypeLabel ->setText("<span style='color: red'>Type can only contain characters, numbers or spaces</span>");
    }
    else if(potentialType.size() < 3 || potentialType.size() > 16)
    {
        ui -> computerTypeLabel ->setText("<span style=' color: red'>Type must be between 2 and 16 characters</span>");
    }
    else
    {
        //Make sure that the first letter of the name is upper case
        potentialType[0] = toupper(potentialType[0]);
        //If there are no problems, the first name is legal.
        _computerType = potentialType;
    }
    return (hasContent && hasLegalCharacters && !(potentialType.size() < 3 || potentialType.size() > 16));
}

//checks the validity of the entered year
bool addComputer::getYearCreated()
{
    int potentialCreationYear = ui ->yearOfCreation ->text().toInt();
    string potentialCreationYearString =(ui ->yearOfCreation ->text()).toStdString();
    bool hasContent = true;
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->yearOfCreation->text()).isEmpty())
    {
        hasContent = false;
    }

    //checks that it has only numbers
    for(unsigned int i = 0; i < potentialCreationYearString.size();i++)
    {
        if(!isdigit(potentialCreationYearString[0]))
        {
            hasOnlyNumbers = false;
        }
    }

    //checks that it is in range
    if(potentialCreationYear <1822 || potentialCreationYear > 2016)
    {
        isInRange = false;
    }

    //throws errors when necessary
    if(!hasContent)
    {
        ui ->YearOfCreationLabel ->setText("<span style='color: red'>Creation year required</span>");
    }
    else if(!hasOnlyNumbers)
    {
        ui ->YearOfCreationLabel ->setText("<span style='color: red'>Creation year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->YearOfCreationLabel ->setText("<span style=' color: red'>No computer created in this year</span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _yearBuilt = potentialCreationYear;
    }
    return(hasContent && hasOnlyNumbers && isInRange);
}

//checks that there is an item selected in the built status combobox
bool addComputer::getBuiltStatus()
{
    if((ui->wasBuiltBox->currentIndex()) == 2)
    {
        _wasBuilt = false;
        return true;
    }
    else if((ui ->wasBuiltBox->currentIndex()) == 3)
    {
        _wasBuilt = true;
        return true;
    }
    else
    {
        ui -> WasBuiltLabel ->setText("<span style=' color: red'>Built status required</span>");
        return false;
    }
}
