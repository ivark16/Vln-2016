#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include <vector>
#include "listservices.h"
#include "scientist.h"

namespace Ui {
class editscientist;
}

class editscientist : public QDialog
{
    Q_OBJECT

public:
    explicit editscientist(QWidget *parent = 0);
    ~editscientist();
    void displayForUpdate(int Id);

private slots:


    void on_pushButton_2_clicked();

private:
    int _ID;
    Ui::editscientist *ui;


    listServices _lists;

};

#endif // EDITSCIENTIST_H
