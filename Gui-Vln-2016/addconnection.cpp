#include "addconnection.h"
#include "ui_addconnection.h"

addConnection::addConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConnection)
{
    ui->setupUi(this);
    displayScientists();
    displayComputers();
    ui ->addConnection_2 ->setDisabled(true);

    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

addConnection::~addConnection()
{
    delete ui;
}

//adds the connection to the database if it is valid
void addConnection::on_addConnection_2_clicked()
{
    //get the index of the selected scientist and computer
    int scientistIndex = ui ->scientistList ->currentIndex().row();
    int computerIndex = ui -> computerList -> currentIndex().row();

    //get the id of the selected scientist and computer
    int scientistID = _allScientists[scientistIndex].getID();
    int computerID = _allComputers[computerIndex].getID();

    //creates a connection between them
    connection newConnection(scientistID, computerID);
    _connection.addConnectionToDatabase(newConnection);

    //after the connection has been added the button is no longer clickable until new selections have been made.
    ui ->addConnection_2 ->setDisabled(true);

    //clear both lists and display them again to deselect.  The window should now be as it was when first opened.
    ui ->scientistList ->clear();
    ui ->computerList ->clear();
    displayScientists();
    displayComputers();
}


//displays all scientists in their respective list
void addConnection::displayScientists()
{
    for(unsigned int i = 0; i < _allScientists.size(); i++)
    {
        //Names are stored in two parts, this creates a new string that contains both names so that the scientists are more recognisable
        QString scientistFullName = QString::fromStdString(((_allScientists[i].getFirstName() + " " + _allScientists[i].getLastName())));

        ui ->scientistList->addItem(scientistFullName);
    }
}

//displays all computers in their respective list
void addConnection::displayComputers()
{
    for(unsigned int i = 0; i < _allComputers.size();i++)
    {
        QString computerName = QString::fromStdString(_allComputers[i].getComputerName());
        ui ->computerList ->addItem(computerName);
    }

}

//the two functions below ensure that the button is only clickable when both a scientist and a computer have been selected

void addConnection::on_scientistList_clicked(const QModelIndex &index)
{
    _scientistSelected = true;
    if(_computerSelected)
    {
        ui ->addConnection_2 ->setDisabled(false);
    }
}

void addConnection::on_computerList_clicked(const QModelIndex &index)
{
    _computerSelected = true;
    if(_scientistSelected)
    {
        ui ->addConnection_2 ->setDisabled(false);
    }
}
