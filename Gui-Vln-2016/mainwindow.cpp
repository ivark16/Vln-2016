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
    // Writes into comboboxes what user can chooose from to display in ascending or descending order
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

    //These functions disable the acending and descending buttons
    ui->pushButtonAscendingConnection->setEnabled(false);
    ui->pushButtonDesendingConnection->setEnabled(false);
    ui->pushButtonAscending->setEnabled(false);
    ui->pushButtonDescending->setEnabled(false);
    ui->pushButtonAscendingComputer->setEnabled(false);
    ui->pushButtonDescendingComputer->setEnabled(false);

    //Displays all tables
    displayAllScientists();
    displayAllComputer();
    displayAllConnections();
    playMusic(ui ->playAudio ->isChecked());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Displays all scientists by reading all scientists into vector and displays them on the table in dislayScientist
void MainWindow::displayAllScientists()
{
    vector<Scientist> scientist = scientistService.displayScientist();
    displayScientist(scientist);
}

//Displays scientists to table in gui
void MainWindow::displayScientist(vector<Scientist> scientists)
{
    ui->tableWidget->clearContents();

    //Sets how many rows the table has to use by checking the size of the vector
    ui->tableWidget->setRowCount(scientists.size());

    //Inputting into table from vector
    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        //Changing char to string
        char a = currentScientist.getGender();
        string s(1, a);

        //Changing strings and numbers to Qstring
        QString firstName = QString::fromStdString(currentScientist.getFirstName());
        QString lastName = QString::fromStdString(currentScientist.getLastName());
        QString gender = QString::fromStdString(s);

        //Checks if the scientist is male, female or other and writes corresponding text to the table
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

        //Inputting Qstrings into table
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ID));
        ui->tableWidget->setItem(row, 1,  new QTableWidgetItem(firstName));
        ui->tableWidget->setItem(row, 2,  new QTableWidgetItem(lastName));
        ui->tableWidget->setItem(row, 3,  new QTableWidgetItem(gender));
        ui->tableWidget->setItem(row, 4,  new QTableWidgetItem(nationality));
        ui->tableWidget->setItem(row, 5,  new QTableWidgetItem(birtYear));
        ui->tableWidget->setItem(row, 6,  new QTableWidgetItem(deathYear));
        ui->tableWidget->setItem(row, 7,  new QTableWidgetItem(awardYear));
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    currentlyDisplayScientist = scientists;
}

//Displays all computer by reading all computer from data base into vector and displays them on the table in dislayComputer
void MainWindow::displayAllComputer()
{
    vector<Computer> computers = scientistService.displayComputer();
    displayComputer(computers);
}

//Displays Computer to table in gui
void MainWindow::displayComputer(vector<Computer> computers)
{
    ui->tableWidget_2->clearContents();

    //Sets row count to how many Computers are in data base
    ui->tableWidget_2->setRowCount(computers.size());

    //Inputting from vector into table
    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer allComputer = computers[row];

        //Changing strings, numbers and bool to Qstring
        QString ID = QString::number(allComputer.getID());
        QString name = QString::fromStdString(allComputer.getComputerName());
        QString type = QString::fromStdString(allComputer.getComputerType());
        QString yob = QString::number(allComputer.getYearOfBuild());
        QString wasBuilt;

        //Changes if computer was built to yes else no
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
        ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    currentlyDisplayComputer = computers;
}

//When you click computer table it enables delete and edit buttons so you can edit or delete that scientist
void MainWindow::on_tableWidget_2_clicked(const QModelIndex &index)
{
        ui->pushButtonDeleteComputer->setEnabled(true);
        ui->pushButtonEditComputers->setEnabled(true);
}

//When you click the combobox 'display computer' it enables Ascending and Descending buttons so you can choose which way you want the computers to be displayd.
void MainWindow::on_comboBoxComputer_currentIndexChanged(const QString &arg1)
{
    ui->pushButtonAscendingComputer->setEnabled(true);
    ui->pushButtonDescendingComputer->setEnabled(true);
}

//Function to search for scientist, can search names, nationality, year born, year of death and turing award
void MainWindow::on_lineEditScientist_textChanged(const QString &arg1)
{
    ui->labelErrorMessageFromScientist->setText("");
    string inputSearch = ui->lineEditScientist->text().toStdString();
    vector<Scientist> searchname;
    vector<Scientist> searchYear;

    //Checks if the input from the user is a number
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

    //If there is no scientist with users search it displays this message to the user
    if (searchname.size()==0 && searchYear.size() == 0)
    {
        ui->labelErrorMessageFromScientist->setText("<span style=' color: red'> No scientist found </span>");
    }
}

//When you click on a connection the delete button is enabled so you can delete connection
void MainWindow::on_tableWidgetConnection_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteConnection->setEnabled(true);
}

//When you click the combobox 'display connection' it enables Ascending and Descending buttons so you can choose which way you want the connections to be displayd.
void MainWindow::on_comboBoxConnection_currentIndexChanged(const QString &arg1)
{
    ui->pushButtonAscendingConnection->setEnabled(true);
    ui->pushButtonDesendingConnection->setEnabled(true);
}

//Display all connections by reading the from data base and putts them into vector
void MainWindow::displayAllConnections()
{
    vector<searching> connections = scientistService.displayAllFromSearching();
    displayConnection(connections);
}

//Inputs connections from vector into table
void MainWindow::displayConnection(vector<searching> connections)
{
    ui->tableWidgetConnection->clearContents();
    //Checks how many rows table has to be by checking size of vector
    ui->tableWidgetConnection->setRowCount(connections.size());

    for (unsigned int row = 0; row < connections.size(); row++)
    {
        searching currentConnection = connections[row];
        //Converting strings and int to QString
        QString firstName = QString::fromStdString(currentConnection.getSearchFirstName());
        QString lastName = QString::fromStdString(currentConnection.getSearchLastName());
        QString name = QString::fromStdString(currentConnection.getSearchComputerName());
        QString type = QString::fromStdString(currentConnection.getSearchComputerType());
        QString yob = QString::number(currentConnection.getSearchYearBuilt());
        //Inputs Qstrings into table
        ui->tableWidgetConnection->setItem(row, 0,  new QTableWidgetItem(firstName));
        ui->tableWidgetConnection->setItem(row, 1,  new QTableWidgetItem(lastName));
        ui->tableWidgetConnection->setItem(row, 2, new QTableWidgetItem(name));
        ui->tableWidgetConnection->setItem(row, 3, new QTableWidgetItem(type));
        ui->tableWidgetConnection->setItem(row, 4, new QTableWidgetItem(yob));
        ui->tableWidgetConnection->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    currentlyDisplayConnection = connections;
}

//When add button in connections is clicked it executes the add connection window
void MainWindow::on_pushButtonAddConnection_clicked()
{
    addConnection addNew;
    addNew.exec();
    //Calls displayAllConnections to update the table after adding a scientist
    displayAllConnections();
}

//Deletes connection of the connection user clicked on
void MainWindow::on_pushButtonDeleteConnection_clicked()
{
    //To find what connection user clicked on
    int connectNo = ui->tableWidgetConnection->currentIndex().row();
    searching currentConnection = currentlyDisplayConnection.at(connectNo);

    //Finds id's of computer and scientist from the connection
    int idComputer = currentConnection.getSearchComputerId();
    int idScientist = currentConnection.getSearchScientistId();
    bool success = scientistService.deleteConnectionFromDatabase(idComputer, idScientist);

    if (success == true)
    {

        ui->pushButtonDeleteConnection->setEnabled(false);
        ui->pushButtonEditScientist->setEnabled(false);
    }
    displayAllConnections();
}

//When add scientist putton is clicked it executes the add scientist window
void MainWindow::on_pushButtonAddScientist_clicked()
{
    addScientist addScientist;
    addScientist.exec();

    //updates table so new scientist will be displayed
    displayAllScientists();
}

//When user has clicked on a scientist the delete button is enabled and you can delete that scientist
void MainWindow::on_pushButtonDeleteScientist_clicked()
{
    //Finding what scientist the user clicked on
    int scientistNo = ui->tableWidget->currentIndex().row();
    Scientist currentScientist = currentlyDisplayScientist.at(scientistNo);

    //Finding the id of the scientist
    int id = currentScientist.getID();

    //deleting scientist from data base by id
    bool success = scientistService.deleteScientistFromDatabase(id);

    if (success == true)
    {
        //Disables edit and delete buttons and updates table
        ui->pushButtonDeleteScientist->setEnabled(false);
        ui->pushButtonEditScientist->setEnabled(false);
    }
    displayAllScientists();
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

    //Disables delete and edit buttons
    ui->pushButtonEditScientist->setEnabled(false);
    ui->pushButtonDeleteScientist->setEnabled(false);
}

//When scientist table is clicked it enables the delete and edit buttons so user can edit and delete that scientist
void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteScientist->setEnabled(true);
    ui->pushButtonEditScientist->setEnabled(true);
}

//When you click the combobox 'display scientist' it enables Ascending and Descending buttons so you can choose which way you want the scientists to be displayd.
void MainWindow::on_comboBoxScientist_currentIndexChanged(const QString &arg1)
{
    ui->pushButtonAscending->setEnabled(true);
    ui->pushButtonDescending->setEnabled(true);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

//This searches computers when user inputs something in the line edit. This function will start immedietly to search when there
//is some input
void MainWindow::on_lineEditComputer_textChanged(const QString &arg1)
{
    ui->labelComputerErrorMessage->setText("");
    string inputSearch = ui->lineEditComputer->text().toStdString();
    vector<Computer> searchname;
    vector<Computer> searchYear;

    //Checks if the input is digit else searches as a string
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

    //If there is no computer found this will print out "no computer found " message
    if (searchname.size()==0 && searchYear.size() == 0)
    {
        ui->labelComputerErrorMessage->setText("<span style=' color: red'> No computer found </span>");
    }
}

//When the delete putton in computer is clicked it will delete that computer by id
void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    //Finds what computer was built and gets that id
    int computerNo = ui->tableWidget_2->currentIndex().row();
    Computer currentComputer = currentlyDisplayComputer.at(computerNo);
    int id = currentComputer.getID();

    //Delete computer by id
    bool success = scientistService.deleteComputerFromDatabase(id);

    if (success == true)
    {
        //Disables edit and delete push botton and reloads the table

        ui->pushButtonDeleteComputer->setEnabled(false);
        ui->pushButtonEditComputers->setEnabled(false);
    }
    displayAllComputer();
}

//Executes the help window
void MainWindow::on_actionHelp_triggered()
{
    HelpWindow window;
    window.exec();
}

//Executes add window for computer and reloads the table
void MainWindow::on_addComputers_clicked()
{
    addComputer addComputer;
    addComputer.exec();
    displayAllComputer();
}

//When the ascending button is clicked in scientist table it will check where the user is in the combobox and then put the table in ascending order by the users choice
void MainWindow::on_pushButtonAscending_clicked()
{
    vector<Scientist> scientist;

    if (ui->comboBoxScientist->currentText() == "")
    {
        ui->pushButtonAscending->setEnabled(true);
        scientist = scientistService.displayScientist();
    }
    else if (ui->comboBoxScientist->currentText() == "ID")
    {
        ui->pushButtonAscending->setEnabled(true);
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

//When the descending button is clicked in scientist table it will check where the user is in the combobox and then put the table in descending order by the users choice
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

//When the edit putton is clicked after a computer has been choosen it will execute the edit window and display the computer in the window. There you can edit the computer
void MainWindow::on_pushButtonEditComputers_clicked()
{
    int selectCurrentComputer = ui->tableWidget_2->currentIndex().row();
    Computer currComputer = currentlyDisplayComputer.at(selectCurrentComputer);
    int id = currComputer.getID();
    _editComputer.displayForUpdate(id);
    _editComputer.setModal(true);
    _editComputer.exec();
    displayAllComputer();

    //Disables edit and delete butttons
    ui->pushButtonEditComputers->setEnabled(false);
    ui->pushButtonDeleteComputer->setEnabled(false);
}

//When the ascending button is clicked in computer table it will check where the user is in the combobox and then put the table in ascending order by the users choice
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
        computer = scientistService.ComputerWasBuiltASC();
    }
    displayComputer(computer);
}

//When the descending button is clicked in computer table it will check where the user is in the combobox and then put the table in descending order by the users choice
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
        computer = scientistService.ComputerWasBuiltDESC();
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

//This function searches connections, it will do every time user starts to input something in the search
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

    //If no connection is found this message will appear beside the search
    if (search.size() == 0)
    {
        ui->labelErrorMessageConnection->setText("<span style=' color: red'> No connection found </span>");
    }
}

//This function plays the music
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

//When the ascending button is clicked in connection table it will check where the user is in the combobox and then put the table in ascending order by the users choice
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

//When the descending button is clicked in connection table it will check where the user is in the combobox and then put the table in descending order by the users choice
void MainWindow::on_pushButtonDesendingConnection_clicked()
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

//When user double clicks scientist another window will open with more information about the scientist with picture and bio
void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    int scientistNo = ui->tableWidget->currentIndex().row();
    Scientist currentScientist = currentlyDisplayScientist.at(scientistNo);
    int id = currentScientist.getID();

    ConnectionTable bla;
    bla.display(id);
    bla.exec();

}
