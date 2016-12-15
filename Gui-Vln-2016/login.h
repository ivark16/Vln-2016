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
    int checkLogin();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    listServices _lists;
    registeruser _users;

    string chiperText(string text, int shift);
    char shiftCharacter(char character, int shift);
    bool isUpperCase(char character);
    bool isLowerCase(char character);
};

#endif // LOGIN_H
