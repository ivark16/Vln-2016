#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <QMessageBox>

editcomputer::editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputer)
{
    ui->setupUi(this);
}

editcomputer::~editcomputer()
{
    delete ui;
}

void editcomputer::displayForUpdate(int id)
{
    _ID = id;

    vector<Computer> newvector;
    newvector = _lists.displayComputerById(id);
    QString name = QString::fromStdString(newvector[0].getComputerName());
    QString type = QString::fromStdString(newvector[0].getComputerType());
    QString yob = QString::number(newvector[0].getYearOfBuild());

    ui->lineEditName->setText(name);
    ui->lineEditType->setText(type);
    ui->lineEditYOB->setText(yob);

}

void editcomputer::on_pushButtonUpdateComputer_clicked()
{
    bool isLegitComputer;

    bool hasName = getNAme();
    bool hasType = getType();
    bool hasBuildYear = getYearOfBuild();
    //bool hasBeenBuilt = wasBuilt();

    isLegitComputer = (hasName && hasType && hasBuildYear);

    if(isLegitComputer)
    {
        _lists.updateNameComputer(_name, _ID);
        _lists.updateTypeComputer(_type, _ID);
        _lists.updateYOCComputer(_yearBuilt, _ID);

        QMessageBox popup;
        popup.setText("The Computer has successfully been updated to the database");
        popup.exec();
    }
}

bool editcomputer::getNAme()
{
    string potentialName = ui -> lineEditName ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditName->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    /*for(unsigned int i = 0; i < potentialName.size(); i++)
    {
        if(isalpha(potentialName[i]))
        {
            //do nothing
        }
        else
        {
            hasOnlyChar = false;
        }
    }*/

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->labelName ->setText("<span style='color: red'>First name required</span>");

    }
    /*else if(!hasOnlyChar)
    {
        ui ->labelName ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }*/
    else if(potentialName.size() < 1 || potentialName.size() > 40)
    {
        ui -> labelName ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _name = potentialName;
    }
    return (hasContent && hasOnlyChar && !(potentialName.size() < 1 || potentialName.size() > 40));
}

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
    /*for(unsigned int i = 0; i < potentialType.size(); i++)
    {
        if(isalpha(potentialType[i]))
        {
            //do nothing
        }
        else
        {
            hasOnlyChar = false;
        }
    }*/

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->labelType ->setText("<span style='color: red'>First name required</span>");

    }
    /*else if(!hasOnlyChar)
    {
        ui ->labelType ->setText("<span style='color: red'>Name can only contain latin characters</span>");
    }*/
    else if(potentialType.size() < 2 || potentialType.size() > 40)
    {
        ui -> labelType ->setText("<span style=' color: red'>Name must be between 2 and 16 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _type= potentialType;
    }
    return (hasContent && hasOnlyChar && !(potentialType.size() < 2 || potentialType.size() > 40));


}

bool editcomputer::getYearOfBuild()
{
    int potentialBuildYear = ui -> lineEditYOB ->text().toInt();
    string potentialBuildYearString =(ui ->lineEditYOB ->text()).toStdString();

    bool hasContent = true;
    bool hasOnlyNumbers = true;
    bool isInRange = true;

    //Checks that there is something in the field
    if((ui ->lineEditYOB->text()).isEmpty())
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
    if(potentialBuildYear <1700 || potentialBuildYear > 2016)
    {
        isInRange = false;
    }

    //throws errors when necessary
    if(!hasContent)
    {
        ui -> labelYOB ->setText("<span style='color: red'>Birth year required</span>");

    }
    else if(!hasOnlyNumbers)
    {
        ui ->labelYOB ->setText("<span style='color: red'>Birth year can only contain numbers</span>");
    }
    else if(!isInRange)
    {
        ui ->labelYOB ->setText("<span style=' color: red'>No computer scientists born in this year </span>");
    }
    else
    {
        //If there are no problems, the birth year is legal.
        _yearBuilt = potentialBuildYear;
    }


    return(hasContent && hasOnlyNumbers && isInRange);
}
