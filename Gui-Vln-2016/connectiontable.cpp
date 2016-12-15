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

    if (myArray.size() != 0)
    {
        QPixmap photo;
        //photo.
        photo.loadFromData(myArray);
        ui->labelPixMap->setPixmap(photo);
    }
    else
    {
        ui->labelPixMap->setText("fuck");
    }

    /*string filepath = QFileDialog::getOpenFileName(
                this,
                "Search For Images",
                "",
                "Image files (*.png *.jpg"
                ).toStdString();
    if (filepath.length())
    {
        QPixmap map(QString::fromStdString(filepath));
        ui->labelPixMap->setPixmap(map);

    }
    else
    {

    }*/
}
