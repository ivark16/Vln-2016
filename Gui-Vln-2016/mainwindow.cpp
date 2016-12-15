#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addScientist.h"
#include "addComputer.h"
#include "addconnection.h"
#include <QObject>
#include <QMediaObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxScientist->addItem("Display scientists");
    ui->comboBoxScientist->addItem("------------------------------------");
    ui->comboBoxScientist->addItem("ID");
    ui->comboBoxScientist->addItem("Alphabetical order of names");
    ui->comboBoxScientist->addItem("Alphabetical order of nationality");
    ui->comboBoxScientist->addItem("Gender");
    ui->comboBoxScientist->addItem("Year of birth");
    ui->comboBoxScientist->addItem("Year of death");
    ui->comboBoxScientist->addItem("Year of award");
    ui->comboBoxComputer->addItem("Display computers");
    ui->comboBoxComputer->addItem("------------------");
    ui->comboBoxComputer->addItem("ID");
    ui->comboBoxComputer->addItem("Name");
    ui->comboBoxComputer->addItem("Type");
    ui->comboBoxComputer->addItem("Year built");
    ui->comboBoxComputer->addItem("Was it built?");
    ui->comboBoxConnection->addItem("Display connections");
    ui->comboBoxConnection->addItem("-----------------------");
    ui->comboBoxConnection->addItem("First Name");
    ui->comboBoxConnection->addItem("Last Name");
    ui->comboBoxConnection->addItem("Computer Name");
    ui->comboBoxConnection->addItem("Type");
    ui->comboBoxConnection->addItem("Year built");
    displayAllScientists();
    displayAllComputer();
    displayAllConnections();
    playMusic(ui ->playAudio ->isChecked());

    //_musicPlayer = new QMediaPlayer(this);
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
        ui->pushButtonEditComputers->setEnabled(true);
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
    ui->pushButtonDeleteConnection->setEnabled(true);
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
    currentlyDisplayConnection = connections;
}

void MainWindow::on_pushButtonAddConnection_clicked()
{
    addConnection addNew;
    addNew.exec();
    displayAllConnections();
}

void MainWindow::on_pushButtonDeleteConnection_clicked()
{
    int connectNo = ui->tableWidgetConnection->currentIndex().row();
    searching currentConnection = currentlyDisplayConnection.at(connectNo);
    int idComputer = currentConnection.getSearchComputerId();
    int idScientist = currentConnection.getSearchScientistId();
    bool success = scientistService.deleteConnectionFromDatabase(idComputer, idScientist);

    if (success == true)
    {
        displayAllConnections();
        ui->pushButtonDeleteConnection->setEnabled(false);
    }
    else
    {
        //ui->labelErrorMessageForDelete->setText("<span style=' color: red'> Error, scientist was not deleted </span>");
    }
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

    ui->pushButtonEditScientist->setEnabled(false);

}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteScientist->setEnabled(true);
    ui->pushButtonEditScientist->setEnabled(true);
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

void MainWindow::on_pushButtonAscending_clicked()
{
    vector<Scientist> scientist;
    if (ui->comboBoxScientist->currentText() == "")
    {
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        scientist = scientistService.readInAscendingByID();
    }
   else if (ui->comboBoxScientist->currentText() == "Alphabetical order of names")
    {
        scientist = scientistService.scientistInAlphabeticalOrder();

    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        scientist = scientistService.readInAlphabeticalOrderNationality();
    }
    else if (ui->comboBoxScientist->currentText() == "Gender")
    {
        scientist = scientistService.readInAlphabeticalOrderGender();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of birth")
    {
        scientist = scientistService.oldestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of death")
    {
        scientist = scientistService.youngestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of Award")
    {
        scientist = scientistService.readInAscendingByYOA();
    }
    displayScientist(scientist);
}

void MainWindow::on_pushButtonDescending_clicked()
{
    vector<Scientist> scientist;
    if (ui->comboBoxScientist->currentText() == "")
    {
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        scientist = scientistService.readInDiscendingByID();
    }
   else if (ui->comboBoxScientist->currentText() == "Alphabetical order of names")
    {
        scientist = scientistService.scientistInReverseAlphabeticalOrder();
    }
    else if (ui->comboBoxScientist->currentText() == "Alphabetical order of nationality")
    {
        scientist = scientistService.readInReverseAlphabeticalOrderNationality();
    }
    else if (ui->comboBoxScientist->currentText() == "Gender")
    {
        scientist = scientistService.readInReverseAlphabeticalOrderGender();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of birth")
    {
        scientist = scientistService.youngestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of death")
    {
        scientist = scientistService.oldestOrderScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "Year of award")
    {
        scientist = scientistService.readInDescendingByYOA();
    }
    displayScientist(scientist);
}

void MainWindow::on_pushButtonEditComputers_clicked()
{
    int selectCurrentComputer = ui->tableWidget_2->currentIndex().row();
    Computer currComputer = currentlyDisplayComputer.at(selectCurrentComputer);
    int id = currComputer.getID();
    _editComputer.displayForUpdate(id);
    _editComputer.setModal(true);
    _editComputer.exec();
    displayAllComputer();

    ui->pushButtonEditComputers->setEnabled(false);
}

void MainWindow::on_pushButtonAscendingComputer_clicked()
{
    vector<Computer> computer;
    if (ui->comboBoxComputer->currentText() == "ID")
    {
        computer = scientistService.computerIdAscendingOrder();
    }
   else if (ui->comboBoxComputer->currentText() == "Name")
    {
        computer = scientistService.computerInAlphabeticalOrder();
    }
    else if (ui->comboBoxComputer->currentText() == "Type")
    {
        computer = scientistService.computertypeAscendingOrder();
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
    if (ui->comboBoxComputer->currentText() == "ID")
    {
        computer = scientistService.computerIdDescendingOrder();
    }
   else if (ui->comboBoxComputer->currentText() == "Name")
    {
        computer = scientistService.computerInReverseAlphabeticalOrder();
    }
    else if (ui->comboBoxComputer->currentText() == "Type")
    {
        computer = scientistService.computertypeDescendingOrder();
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

//if the check button in the corner is checked, the music will play.
//The music we used is Disco House by Bernhard Kosten.
// Link: http://www.flashkit.com/loops/Easy_Listening/discohouse-140130084506.html
//This music is free to use under a "Linkware" license.
void MainWindow::playMusic(bool checkState)
{

    _sweetPlaylist->addMedia(QUrl("qrc:/sounds/sounds/dico_house.MP3"));
    _sweetPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    _sweetPlaylist->setCurrentIndex(1);

    _sweetMusic->setPlaylist(_sweetPlaylist);
    if(checkState == false)
    {
        _sweetMusic ->stop();
    }
    else if(checkState == true)
    {
        _sweetMusic ->setVolume(50);
        _sweetMusic ->play();
    }
}


void MainWindow::on_lineEditSearchConnection_textChanged(const QString &arg1)
{
    ui->labelErrorMessageConnection->setText("");
    string inputSearch = ui->lineEditSearchConnection->text().toStdString();
    vector<searching> search;

    search = scientistService.displaySearchJoinComputerName(inputSearch);
    displayConnection(search);

    if (search.size() == 0)
    {
        search = scientistService.displaySearchJoinScientistName(inputSearch);
        displayConnection(search);
    }

    if (search.size() == 0)
    {
        ui->labelErrorMessageConnection->setText("<span style=' color: red'> No connection found </span>");
    }
}

void MainWindow::on_pushButtonAdvancedSearchScientist_clicked()
{
    //ConnectionTable connection;
    //connection.exec();
}

void MainWindow::on_playAudio_clicked()
{
    if(ui->playAudio ->isChecked())
    {
        playMusic(true);
    }
    else
    {
        playMusic(false);
    }
}


void MainWindow::on_pushButtonAscendingConnection_clicked()
{
    vector<searching> connection;
    if (ui->comboBoxConnection->currentText() == "First Name")
    {
        connection = scientistService.readInAscendingByFirstName();
    }
    else if (ui->comboBoxConnection->currentText() == "Last Name")
    {
        connection = scientistService.readInAscendingByLastName();
    }
    else if (ui->comboBoxConnection->currentText() == "Computer Name")
    {
        connection = scientistService.readInAscendingByCompName();
    }
    else if (ui->comboBoxConnection->currentText() == "Type")
    {
        connection = scientistService.readInAscendingByCompType();
    }
    else if (ui->comboBoxConnection->currentText() == "Year built")
    {
        connection = scientistService.readInAscendingByYearBuilt();
    }
    displayConnection(connection);
}

void MainWindow::on_pushButtonDesendingConnection_clicked()
{
    {
        vector<searching> connection;
        if (ui->comboBoxConnection->currentText() == "First Name")
        {
            connection = scientistService.readInDiscendingFirstName();
        }
        else if (ui->comboBoxConnection->currentText() == "Last Name")
        {
            connection = scientistService.readInDiscendingLastName();
        }
        else if (ui->comboBoxConnection->currentText() == "Computer Name")
        {
            connection = scientistService.readInDiscendingCompName();
        }
        else if (ui->comboBoxConnection->currentText() == "Type")
        {
            connection = scientistService.readInDiscendingByCompType();
        }
        else if (ui->comboBoxConnection->currentText() == "Year built")
        {
            connection = scientistService.readInDiscendingByYearBuilt();
        }
        displayConnection(connection);
    }
}
