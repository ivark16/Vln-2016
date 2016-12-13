#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>

namespace Ui {
class editscientist;
}

class editscientist : public QDialog
{
    Q_OBJECT

public:
    explicit editscientist(QWidget *parent = 0);
    ~editscientist();

private:
    Ui::editscientist *ui;
};

#endif // EDITSCIENTIST_H
