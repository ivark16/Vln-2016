#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();
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
