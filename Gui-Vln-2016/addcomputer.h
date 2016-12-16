#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include "listservices.h"
#include <string>

namespace Ui
{
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    ~addComputer();

private slots:
    void on_addComputer_2_clicked();

private:
    Ui::addComputer *ui;
    listServices _connection;
    string _computerName;
    string _computerType;
    int _yearBuilt;
    bool _wasBuilt;

    //checks the validity of all entered fields
    bool getComputerName();
    bool getComputerType();
    bool getYearCreated();
    bool getBuiltStatus();


};

#endif // ADDCOMPUTER_H
