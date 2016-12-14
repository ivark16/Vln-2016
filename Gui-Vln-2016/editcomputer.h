#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>

namespace Ui {
class editcomputer;
}

class editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputer(QWidget *parent = 0);
    ~editcomputer();

private:
    Ui::editcomputer *ui;
};

#endif // EDITCOMPUTER_H
