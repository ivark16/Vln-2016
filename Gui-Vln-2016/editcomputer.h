#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H
#include <QDialog>
#include <vector>
#include "listservices.h"
#include "computer.h"

namespace Ui
{
class editcomputer;
}

class editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputer(QWidget *parent = 0);
    ~editcomputer();
    void displayForUpdate(int id);

private slots:
    //This activates if the button is pressed
    void on_pushButtonUpdateComputer_clicked();

private:
    Ui::editcomputer *ui;
    listServices _lists;
    int _ID;
    string _name;
    string _type;
    int _yearBuilt;
    bool _wasBuilt;

    //Error Functions
    bool getNAme();
    bool getType();
    bool getYearOfBuild();
    bool wasBuilt();

};

#endif // EDITCOMPUTER_H
