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

    int id = ui->lineEditAdvancedSearch->text().toInt();
    QByteArray myArray = _list.searchScientistPicture(id);

    if (id == 15)
    {
        ui->textBrowserAdvancedSearch->setText("Alan Turing");
    }

    if (myArray.size() != 0)
    {
        QPixmap photo;       
        photo.loadFromData(myArray);
        ui->labelPixMap->setPixmap(photo.scaled(100, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        ui->labelPixMap->setScaledContents(true);
    }
    else
    {
        ui->labelPixMap->setText("<span style=' color: red'> Sorry, no scientist found. </span>");
    }

}

void ConnectionTable::display(int id)
{
    QByteArray myArray = _list.searchScientistPicture(id);

    if (id == 15)
    {
        ui->textBrowserAdvancedSearch->setText("Alan Turing");
    }

    if (myArray.size() != 0)
    {
        QPixmap photo;
        photo.loadFromData(myArray);
        ui->labelPixMap->setPixmap(photo.scaled(100, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        ui->labelPixMap->setScaledContents(true);
    }
    else
    {
        ui->labelPixMap->setText("<span style=' color: red'> Sorry, no scientist found. </span>");
    }

}

