#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>

namespace Ui {
class addScientist;
}

class addScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addScientist(QWidget *parent = 0);
    ~addScientist();

private slots:

 //   void on_addScientistButton_clicked();

private:
    Ui::addScientist *ui;
};

#endif // ADDSCIENTIST_H
