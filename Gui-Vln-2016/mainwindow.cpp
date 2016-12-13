#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addScientist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputer();
    displayAllConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableViewScientist_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteScientist->setEnabled(true);
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> scientist = scientistService.displayScientist();
    displayScientist(scientist);
}

void MainWindow::displayScientist(vector<Scientist> scientists)
{
    ui->tableWidget->clearContents();

    ui->tableWidget->setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        char a = currentScientist.getGender();
        string s(1, a);
        QString firstName = QString::fromStdString(currentScientist.getFirstName());
        QString lastName = QString::fromStdString(currentScientist.getLastName());
        QString gender = QString::fromStdString(s);        QString nationality = QString::fromStdString(currentScientist.getNationality());
        QString birtYear = QString::number(currentScientist.getBirthYear());
        QString deathYear = QString::number(currentScientist.getDeathYear());
        if(deathYear == "0")
        {
            deathYear = "Alive";
        }
        QString awardYear = QString::number(currentScientist.getAwardYear());
        if(awardYear == "0")
        {
            awardYear = "None";
        }
        QString ID = QString::number(currentScientist.getID());

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ID));
        ui->tableWidget->setItem(row, 1,  new QTableWidgetItem(firstName));
        ui->tableWidget->setItem(row, 2,  new QTableWidgetItem(lastName));
        ui->tableWidget->setItem(row, 3,  new QTableWidgetItem(gender));
        ui->tableWidget->setItem(row, 4,  new QTableWidgetItem(nationality));
        ui->tableWidget->setItem(row, 5,  new QTableWidgetItem(birtYear));
        ui->tableWidget->setItem(row, 6,  new QTableWidgetItem(deathYear));
        ui->tableWidget->setItem(row, 7,  new QTableWidgetItem(awardYear));
    }
    currrentlyDisplaydStudent = scientists;
}

void MainWindow::displayAllComputer()
{
    vector<Computer> computers = scientistService.displayComputer();
    displayComputer(computers);
}

void MainWindow::displayComputer(vector<Computer> computers)
{
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(computers.size());
    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer allComputer = computers[row];

        QString ID = QString::number(allComputer.getID());
        QString name = QString::fromStdString(allComputer.getComputerName());
        QString type = QString::fromStdString(allComputer.getComputerType());
        QString yob = QString::number(allComputer.getYearOfBuild());

        ui->tableWidget_2->setItem(row , 0, new QTableWidgetItem(ID));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(type));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(yob));
    }
}

void MainWindow::on_tableWidget_2_clicked(const QModelIndex &index)
{

}

//Fall til ad leita ad visindamonnum, leitar ad nofnum og fæðingarári vísindamanna.
void MainWindow::on_lineEditScientist_textChanged(const QString &arg1)
{
    ui->labelErrorMessageFromScientist->setText("");
    string inputSearch = ui->lineEditScientist->text().toStdString();
    vector<Scientist> searchname;
    vector<Scientist> searchYear;

    if (isdigit(inputSearch[0]) == true)
    {
        int b = atoi(inputSearch.c_str());
        searchYear = scientistService.checkBirthYear(b);
        if (searchYear.size() == 0)
        {
            searchYear = scientistService.checkForAward(b);
            if (searchYear.size() == 0)
            {
                searchYear = scientistService.checkDeathYear(b);
                displayScientist(searchYear);
            }
            else
            {
                displayScientist(searchYear);
            }
        }
        else
        {
            displayScientist(searchYear);
        }
    }
    else
    {
         searchname = scientistService.searchForName(inputSearch);
         if (searchname.size() == 0)
         {
             searchname = scientistService.checkNationality(inputSearch);
             displayScientist(searchname);
         }
         else
         {
            displayScientist(searchname);
         }
    }
    if (searchname.size()==0 && searchYear.size() == 0)
    {
        ui->labelErrorMessageFromScientist->setText("<span style=' color: red'> No scientist found </span>");
    }
}

//Connection------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_tableWidget_3_clicked(const QModelIndex &index)
{
    //ui->button_remove_connection->setEnabled(true);
}

void MainWindow::displayAllConnections()
{
    vector<connection> connections = scientistService.displayConnection();
    displayConnection(connections);
}

void MainWindow::displayConnection(vector<connection> connections)
{
    ui->tableWidget_3->clearContents();

    ui->tableWidget_3->setRowCount(connections.size());

    for (unsigned int row = 0; row < connections.size(); row++)
    {
        connection currentConnection = connections[row];

        QString scientistId = QString::number(currentConnection.getScientistId());
        QString computersId = QString::number(currentConnection.getComputersId());
        //QString ID = QString::number(currentConnection.getID());

        //ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ID));
        ui->tableWidget_3->setItem(row, 1,  new QTableWidgetItem(scientistId));
        ui->tableWidget_3->setItem(row, 2,  new QTableWidgetItem(computersId));
    }
}
void MainWindow::on_pushButtonEditConnection_clicked()
{

}

void MainWindow::on_pushButtonAddConnection_clicked()
{

}

void MainWindow::on_pushButtonDeleteConnection_clicked()
{

}

//------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_pushButtonAddScientist_clicked()
{
    addScientist addScientist;
    addScientist.exec();
}

void MainWindow::on_pushButtonDeleteScientist_clicked()
{
    int scientistNo = ui->tableWidget->currentIndex().row();
    Scientist currentScientist = currrentlyDisplaydStudent.at(scientistNo);
    int id = currentScientist.getID();
    bool success = scientistService.deleteScientistFromDatabase(id);

    if (success == true)
    {
        displayAllScientists();
        ui->pushButtonDeleteScientist->setEnabled(false);
    }
    else
    {
        ui->labelErrorMessageForDelete->setText("<span style=' color: red'> Error, scientist was not deleted </span>");
    }
}

void MainWindow::on_pushButtonEditScientist_clicked()
{
    editscientist edit;
    edit.setModal(true);
    edit.exec();
}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteScientist->setEnabled(true);
}
