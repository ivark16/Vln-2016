#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QDialog>
#include "listServices.h"
#include "scientist.h"
#include "computer.h"

namespace Ui
{
class addConnection;
}

class addConnection : public QDialog
{
    Q_OBJECT

public:
    explicit addConnection(QWidget *parent = 0);
    ~addConnection();

private slots:
    void on_addConnection_2_clicked();

    void on_scientistList_clicked(const QModelIndex &index);

    void on_computerList_clicked(const QModelIndex &index);

private:
    Ui::addConnection *ui;
    listServices _connection;
    void displayScientists();
    void displayComputers();
    vector<Scientist> _allScientists = _connection.displayScientist();
    vector<Computer> _allComputers = _connection.displayComputer();
    bool _scientistSelected;
    bool _computerSelected;


};

#endif // ADDCONNECTION_H
