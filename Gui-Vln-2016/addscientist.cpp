#include "addscientist.h"
#include "ui_addscientist.h"
#include "scientist.h"
#include "listservices.h"
#include <string>
#include <cstdlib>

using namespace std;

addScientist::addScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientist)
{
    ui->setupUi(this);
}

addScientist::~addScientist()
{
    delete ui;
}


void addScientist::on_addScientistButton_clicked()
{
    //set all errors to empty
    ui ->birthYearLabel ->setText("");
    ui ->deathYearLabel ->setText("");
    ui ->firstNameLabel ->setText("");
    ui ->lastNameLabel ->setText("");
    ui ->genderLabel ->setText("");
    ui ->nationalityLabel ->setText("");

    //Check if required fields have stuff in them

    string firstName = ui->firstNameBox->text().toStdString();
    string lastName = ui->lastNameBox->text().toStdString();
  //char gender = Qstring::tostdstring(ui ->genderSelectBox ->);
    string nationality = ui ->nationalityBox->text().toStdString();
    int birthYear;
    int deathYear;
    int awardYear;

    if((ui ->firstNameBox->text()).isEmpty())
    {
        ui -> firstNameLabel ->setText("First name required");
    }
    if((ui ->lastNameBox->text()).isEmpty())
    {
        ui -> lastNameLabel ->setText("Last name required");
    }
    if((ui ->nationalityBox->text()).isEmpty())
    {
        ui -> nationalityLabel ->setText("Nationality required");
    }


}
