#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addScientist.h"
#include "addComputer.h"
#include "addconnection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxScientist->addItem("");
    ui->comboBoxScientist->addItem("ID");
    ui->comboBoxScientist->addItem("Alphabetical order of names");
    ui->comboBoxScientist->addItem("Alphabetical order of nationality");
    ui->comboBoxScientist->addItem("Gender");
    ui->comboBoxScientist->addItem("Year of birth");
    ui->comboBoxScientist->addItem("Year of death");
    ui->comboBoxScientist->addItem("Year of award");
    ui->comboBoxComputer->addItem("");
    ui->comboBoxComputer->addItem("ID");
    ui->comboBoxComputer->addItem("Name");
    ui->comboBoxComputer->addItem("Type");
    ui->comboBoxComputer->addItem("Year built");
    ui->comboBoxComputer->addItem("Was it built?");
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
        QString gender = QString::fromStdString(s);
        if(gender == "m" || gender == "M")
        {
            gender = "Male";
        }
        else if(gender == "f" || gender == "F")
        {
            gender = "Female";
        }
        else
        {
            gender = "Other";
        }
        QString nationality = QString::fromStdString(currentScientist.getNationality());
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
    currentlyDisplayScientist = scientists;
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
        QString wasBuilt;
        if(allComputer.getWasBuilt())
        {
            wasBuilt = "Yes";
        }
        else
        {
            wasBuilt = "No";
        }

        ui->tableWidget_2->setItem(row , 0, new QTableWidgetItem(ID));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(type));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(yob));
        ui ->tableWidget_2->setItem(row,4,new QTableWidgetItem(wasBuilt));
    }
    currentlyDisplayComputer = computers;
}

void MainWindow::on_tableWidget_2_clicked(const QModelIndex &index)
{
        ui->pushButtonDeleteComputer->setEnabled(true);
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

void MainWindow::on_tableWidgetConnection_clicked(const QModelIndex &index)
{
    //ui->button_remove_connection->setEnabled(true);
}

void MainWindow::displayAllConnections()
{
    vector<searching> connections = scientistService.displayAllFromSearching();
    displayConnection(connections);
}

void MainWindow::displayConnection(vector<searching> connections)
{
    ui->tableWidgetConnection->clearContents();

    ui->tableWidgetConnection->setRowCount(connections.size());

    for (unsigned int row = 0; row < connections.size(); row++)
    {
        searching currentConnection = connections[row];

        QString firstName = QString::fromStdString(currentConnection.getSearchFirstName());
        QString lastName = QString::fromStdString(currentConnection.getSearchLastName());
        QString name = QString::fromStdString(currentConnection.getSearchComputerName());
        QString type = QString::fromStdString(currentConnection.getSearchComputerType());
        QString yob = QString::number(currentConnection.getSearchYearBuilt());

        ui->tableWidgetConnection->setItem(row, 0,  new QTableWidgetItem(firstName));
        ui->tableWidgetConnection->setItem(row, 1,  new QTableWidgetItem(lastName));
        ui->tableWidgetConnection->setItem(row, 2, new QTableWidgetItem(name));
        ui->tableWidgetConnection->setItem(row, 3, new QTableWidgetItem(type));
        ui->tableWidgetConnection->setItem(row, 4, new QTableWidgetItem(yob));
    }
}
void MainWindow::on_pushButtonEditConnection_clicked()
{

}

void MainWindow::on_pushButtonAddConnection_clicked()
{
    addConnection addNew;
    addNew.exec();
}

void MainWindow::on_pushButtonDeleteConnection_clicked()
{

}

//------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_pushButtonAddScientist_clicked()
{
    addScientist addScientist;
    addScientist.exec();
    displayAllScientists();
}

void MainWindow::on_pushButtonDeleteScientist_clicked()
{
    int scientistNo = ui->tableWidget->currentIndex().row();
    Scientist currentScientist = currentlyDisplayScientist.at(scientistNo);
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

// This function opens the Edit table and inserts the name from table into lineEdit in the edit table
void MainWindow::on_pushButtonEditScientist_clicked()
{
    int selectCurrentStudent = ui->tableWidget->currentIndex().row();
    Scientist currscientist = currentlyDisplayScientist.at(selectCurrentStudent);
    int id = currscientist.getID();
    _edit.displayForUpdate(id);
    _edit.setModal(true);
    _edit.exec();
    displayAllScientists();

}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteScientist->setEnabled(true);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEditComputer_textChanged(const QString &arg1)
{
    ui->labelComputerErrorMessage->setText("");
    string inputSearch = ui->lineEditComputer->text().toStdString();
    vector<Computer> searchname;
    vector<Computer> searchYear;

    if (isdigit(inputSearch[0]) == true)
    {
        int b = atoi(inputSearch.c_str());
        searchYear = scientistService.searchWhenBuiltSingleYear(b);
        displayComputer(searchYear);
    }
    else
    {
         searchname = scientistService.searchForNameComputer(inputSearch);
         if (searchname.size() == 0)
         {
             searchname = scientistService.searchForTypeComputer(inputSearch);
             displayComputer(searchname);
         }
         else
         {
            displayComputer(searchname);
         }
    }
    if (searchname.size()==0 && searchYear.size() == 0)
    {
        ui->labelComputerErrorMessage->setText("<span style=' color: red'> No computer found </span>");
    }
}

void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    int computerNo = ui->tableWidget_2->currentIndex().row();
    Computer currentComputer = currentlyDisplayComputer.at(computerNo);
    int id = currentComputer.getID();
    bool success = scientistService.deleteComputerFromDatabase(id);

    if (success == true)
    {
        displayAllComputer();
        ui->pushButtonDeleteComputer->setEnabled(false);
    }
    else
    {
        ui->labelErrorMessageForDelete->setText("<span style=' color: red'> Error, computer was not deleted </span>");
    }
}

void MainWindow::on_actionHelp_triggered()
{   HelpWindow window;
    window.exec();
}

void MainWindow::on_addComputers_clicked()
{
    addComputer addComputer;
    addComputer.exec();
    displayAllComputer();
}

void MainWindow::on_radioButtonAscending_clicked()
{
    vector<Scientist> scientist;
    if (ui->comboBoxScientist->currentText() == "")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInAscendingByID();
    }
   else if (ui->comboBoxScientist->currentText() == "Alphabetical order of names")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        //ui->radioButtonAscending->setCheckable(false);
        scientist = scientistService.scientistInAlphabeticalOrder();

    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInAlphabeticalOrderNationality();
    }
    else if (ui->comboBoxScientist->currentText() == "Gender")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInAlphabeticalOrderGender();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of birth")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        //ui->radioButtonAscending->setCheckable(false);
        scientist = scientistService.oldestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of death")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.youngestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of Award")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInAscendingByYOA();
    }
    displayScientist(scientist);
}

void MainWindow::on_radioButtonDescending_clicked()
{
    vector<Scientist> scientist;
    if (ui->comboBoxScientist->currentText() == "")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInDiscendingByID();
    }
   else if (ui->comboBoxScientist->currentText() == "Alphabetical order of names")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.scientistInReverseAlphabeticalOrder();
    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInReverseAlphabeticalOrderNationality();
    }
    else if (ui->comboBoxScientist->currentText() == "Gender")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInReverseAlphabeticalOrderGender();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of birth")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.youngestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of death")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.oldestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of award")
    {
        ui->radioButtonAscending->setCheckable(false);
        ui->radioButtonAscending->update();
        scientist = scientistService.readInDescendingByYOA();
    }
    displayScientist(scientist);
}

void MainWindow::on_pushButton_2_clicked()
{
    int selectCurrentComputer = ui->tableWidget_2->currentIndex().row();
    Computer currComputer = currentlyDisplayComputer.at(selectCurrentComputer);
    int id = currComputer.getID();
    _editComputer.displayForUpdate(id);
    _editComputer.setModal(true);
    _editComputer.exec();
    displayAllComputer();
}

void MainWindow::on_pushButtonAscendingComputer_clicked()
{
    vector<Computer> computer;
    if (ui->comboBoxComputer->currentText() == "")
    {
        computer = scientistService.displayComputer();
    }
    else if (ui->comboBoxComputer->currentText() == "ID")
    {
        //computer = scientistService.;
    }
   else if (ui->comboBoxComputer->currentText() == "Name")
    {
        computer = scientistService.computerInAlphabeticalOrder();
    }
    else if (ui->comboBoxComputer->currentText() == "Alphabetical order of type")
    {
        //computer = scientistService;
    }
    else if (ui->comboBoxComputer->currentText() == "Year built")
    {
        computer = scientistService.oldestOrderComputer();
    }
    else if (ui->comboBoxComputer->currentText() == "Was it built?")
    {
        //computer = scientistService;
    }
    displayComputer(computer);
}

void MainWindow::on_pushButtonDescendingComputer_clicked()
{
    vector<Computer> computer;
    if (ui->comboBoxComputer->currentText() == "")
    {
        computer = scientistService.displayComputer();
    }
    else if (ui->comboBoxComputer->currentText() == "ID")
    {
        //computer = scientistService.;
    }
   else if (ui->comboBoxComputer->currentText() == "Name")
    {
        computer = scientistService.computerInReverseAlphabeticalOrder();
    }
    else if (ui->comboBoxComputer->currentText() == "Type")
    {
        //computer = scientistService;
    }
    else if (ui->comboBoxComputer->currentText() == "Year built")
    {
        computer = scientistService.youngestOrderComputer();
    }
    else if (ui->comboBoxComputer->currentText() == "Was it built?")
    {
        //computer = scientistService;
    }
    displayComputer(computer);
}
