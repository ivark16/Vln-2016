#include "editscientist.h"
#include "ui_editscientist.h"

editscientist::editscientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscientist)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Firstname");
    ui->comboBox->addItem("Lastname");
    ui->comboBox->addItem("Gender");
    ui->comboBox->addItem("Nationality");
    ui->comboBox->addItem("Year of birth");
    ui->comboBox->addItem("Year of death");
    ui->comboBox->addItem("Year of award");
}

editscientist::~editscientist()
{
    delete ui;
}
