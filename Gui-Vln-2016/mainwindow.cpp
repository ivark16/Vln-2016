#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addScientist.h"
#include "addComputer.h"

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
    vector<connection> connections = scientistService.displayConnection();
    displayConnection(connections);
}

void MainWindow::displayConnection(vector<connection> connections)
{
    ui->tableWidgetConnection->clearContents();

    ui->tableWidgetConnection->setRowCount(connections.size());

    for (unsigned int row = 0; row < connections.size(); row++)
    {
        connection currentConnection = connections[row];

        QString scientistId = QString::number(currentConnection.getScientistId());
        QString computersId = QString::number(currentConnection.getComputersId());
        //QString ID = QString::number(currentConnection.getID());

        //ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ID));
        ui->tableWidgetConnection->setItem(row, 1,  new QTableWidgetItem(scientistId));
        ui->tableWidgetConnection->setItem(row, 2,  new QTableWidgetItem(computersId));
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

void MainWindow::on_pushButton_clicked()
{
    vector<Scientist> scientist;
    if (ui->comboBoxScientist->currentText() == "")
    {
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        //scientist = scientistService.();
    }
   else if (ui->comboBoxScientist->currentText() == "Alphabetical order of names")
    {
        scientist = scientistService.scientistInAlphabeticalOrder();
    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        //scientist = scientistService.;
    }
    else if (ui->comboBoxScientist->currentText() == "Gender")
    {
        //scientist = scientistService.;
    }
    else if (ui->comboBoxScientist->currentText() == "Year of birth")
    {
        scientist = scientistService.youngestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of death")
    {
        scientist = scientistService.oldestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        //scientist = scientistService.;
    }

    displayScientist(scientist);
}

void MainWindow::on_radioButtonAscending_clicked()
{

}

void MainWindow::on_radioButtonDescending_clicked()
{

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
