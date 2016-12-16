#ifndef REGISTERUSER_H
#define REGISTERUSER_H
#include <QDialog>
#include <QMessageBox>
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
    //Function for register button pressed
    void on_pushButtonRegister_clicked();

private:
    Ui::registeruser *ui;
    listServices _lists;
    string _username;
    string _password;

    //Function for encrytion
    string chiperText(string text, int shift);
    char shiftCharacter(char character, int shift);

    //Functions for error handling
    bool isUpperCase(char character);
    bool isLowerCase(char character);
    bool getUserName();
    bool getPassWord();
};

#endif // REGISTERUSER_H
