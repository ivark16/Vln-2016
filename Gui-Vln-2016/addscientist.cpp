#include "addscientist.h"
#include "ui_addscientist.h"

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
