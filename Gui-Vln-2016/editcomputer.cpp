#include "editcomputer.h"
#include "ui_editcomputer.h"

editcomputer::editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputer)
{
    ui->setupUi(this);
}

editcomputer::~editcomputer()
{
    delete ui;
}
