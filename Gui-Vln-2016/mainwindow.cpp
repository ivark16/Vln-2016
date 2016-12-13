#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableViewScientist_clicked(const QModelIndex &index)
{
    //ui->button_remove_student->setEnabled(true);
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
        //QString gender = QChar::QChar(currentScientist.getGender());
        QString nationality = QString::fromStdString(currentScientist.getNationality());
        QString birtYear = QString::number(currentScientist.getBirthYear());
        QString deathYear = QString::number(currentScientist.getDeathYear());
        QString awardYear = QString::number(currentScientist.getAwardYear());
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
void MainWindow::on_pushButtonSearchScientist_clicked()
{
    string inputSearch = ui->lineEditScientist->text().toStdString();


    if (isdigit(inputSearch[0]) == true)
    {
        int b = atoi(inputSearch.c_str());
        vector<Scientist> searchYear = scientistService.checkBirthYear(b);
        if (searchYear.size() == 0)
        {
            searchYear = scientistService.checkForAward(b);
            displayScientist(searchYear);
        }
        else
        {
            displayScientist(searchYear);
        }
    }
    else
    {
         vector<Scientist> searchname = scientistService.searchForName(inputSearch);
         if (searchname.size() == 0)
         {
             searchname = scientistService.checkFullName(inputSearch);
             displayScientist(searchname);
         }
         else
         {
            displayScientist(searchname);
         }

    }

}

