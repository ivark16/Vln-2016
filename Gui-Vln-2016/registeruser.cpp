#include "registeruser.h"
#include "ui_registeruser.h"

registeruser::registeruser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registeruser)
{
    ui->setupUi(this);
}

registeruser::~registeruser()
{
    delete ui;
}

void registeruser::on_pushButtonRegister_clicked()
{
    _username = ui->lineEditUserName->text().toStdString();
    _password = ui->lineEditPassword->text().toStdString();
    userandpass itemUser(_username, _password);
    _lists.regiserUsers(itemUser);
    close();
}

string registeruser::chiperText(string text, int shift)
{

}

char registeruser::shiftCharacter(char character, int shift)
{

}

bool registeruser::isUpperCase(char character)
{

}

bool registeruser::isLowerCase(char character)
{

}
