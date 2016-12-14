#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "listservices.h"
#include "computer.h"
#include <QMessageBox>

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);

    ui->setupUi(this);
    ui ->wasBuiltBox ->addItem("Built status");
    ui ->wasBuiltBox ->addItem("---");
    ui ->wasBuiltBox ->addItem("Was built");
    ui ->wasBuiltBox ->addItem("Was not built");
}

addComputer::~addComputer()
{
    delete ui;
}

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

bool addComputer::getComputerName()
{

    return false;
}

bool addComputer::getComputerType()
{

    return false;
}

bool addComputer::getYearCreated()
{

    return false;
}

bool addComputer::getBuiltStatus()
{
    return false;
}
