#include "connectiontable.h"
#include "ui_connectiontable.h"

ConnectionTable::ConnectionTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionTable)
{
    ui->setupUi(this);
}

ConnectionTable::~ConnectionTable()
{
    delete ui;
}

void ConnectionTable::on_pushButtonAdvancedSearch_clicked()
{

}
