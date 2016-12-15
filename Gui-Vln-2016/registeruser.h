#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QDialog>
#include "listservices.h"
#include "userandpass.h"

namespace Ui {
class registeruser;
}

class registeruser : public QDialog
{
    Q_OBJECT

public:
    explicit registeruser(QWidget *parent = 0);
    ~registeruser();

private slots:
    void on_pushButtonRegister_clicked();

private:
    Ui::registeruser *ui;
    listServices _lists;
    string _username;
    string _password;

    string chiperText(string text, int shift);
    char shiftCharacter(char character, int shift);
    bool isUpperCase(char character);
    bool isLowerCase(char character);
};

#endif // REGISTERUSER_H
