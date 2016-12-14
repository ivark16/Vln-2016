#include "editscientist.h"
#include "ui_editscientist.h"

editscientist::editscientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscientist)
{
    ui->setupUi(this);
}

editscientist::~editscientist()
{
    delete ui;
}

void editscientist::displayForUpdate(int Id)
{
    _ID = Id;
    vector<Scientist> newvector;

    //char a = newvector[_ID].getGender();
    //string s(1,a);
    newvector = _lists.displayScientist();
    QString firstname = QString::fromStdString(newvector[_ID].getFirstName());
    ui->lineEditFirstName->setText(firstname);
    QString lastname = QString::fromStdString(newvector[_ID].getLastName());
    //QString gender = QString::fromStdString(s);
    QString nation = QString::fromStdString(newvector[_ID].getNationality());
    QString yob = QString::number(newvector[_ID].getBirthYear());
    QString yod = QString::number(newvector[_ID].getDeathYear());
    QString yoa = QString::number(newvector[_ID].getAwardYear());

    ui->lineEditFirstName->setText(firstname);
    ui->lineEditLastName->setText(lastname);
    //ui->lineEditGender->setText(gender);
    ui->lineEditNationality->setText(nation);
    ui->lineEditYOB->setText(yob);
    ui->lineEditYOD->setText(yod);
    ui->lineEditYOA->setText(yoa);
}


void editscientist::on_pushButton_2_clicked()
{
    vector<Scientist> newvector;
    newvector = _lists.displayScientist();


    //string s(1, a);
    QString firstname = QString::fromStdString(newvector[_ID].getFirstName());


}
