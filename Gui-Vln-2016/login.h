#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "listservices.h"
#include "registeruser.h"
#include "userandpass.h"
#include <iostream>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    //Push button for login
    void on_pushButtonLogin_clicked();

    //Push button for register
    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    listServices _lists;
    registeruser _users;

    //Functions for decrytion
    string theDecrypter(string text);
    string deChiperText(string text, int shift);
    char shiftCharacter(char character, int shift);
    bool isUpperCase(char character);
    bool isLowerCase(char character);

};

#endif // LOGIN_H
