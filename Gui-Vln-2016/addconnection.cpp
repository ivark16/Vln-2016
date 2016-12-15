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

}

addConnection::~addConnection()
{
    delete ui;
}


void addConnection::on_addConnection_2_clicked()
{

        int scientistIndex = ui ->scientistList ->currentIndex().row();
        int computerIndex = ui -> computerList -> currentIndex().row();

        int scientistID = _allScientists[scientistIndex].getID();
        int computerID = _allComputers[computerIndex].getID();

        connection newConnection(scientistID, computerID);
        _connection.addConnectionToDatabase(newConnection);

        ui ->addConnection_2 ->setDisabled(true);

        //clear both lists

        ui ->scientistList ->clear();
        ui ->computerList ->clear();

        displayScientists();
        displayComputers();
}


void addConnection::displayScientists()
{
    for(unsigned int i = 0; i < _allScientists.size(); i++)
    {
        QString scientistFullName = QString::fromStdString(((_allScientists[i].getFirstName() + " " + _allScientists[i].getLastName())));
        ui ->scientistList->addItem(scientistFullName);
    }
}

void addConnection::displayComputers()
{

    for(unsigned int i = 0; i < _allComputers.size();i++)
    {
        QString computerName = QString::fromStdString(_allComputers[i].getComputerName());
        ui ->computerList ->addItem(computerName);
    }

}

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
