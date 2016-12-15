#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

int login::checkLogin()
{
    int _cl =1;
    if ( (!ui->lineEditUser->text().isEmpty()) &&(!ui->lineEditPwd->text().isEmpty()))
    {
            if((ui->lineEditUser->text()=="admin") && (ui->lineEditPwd->text()=="1234"))
            {
                QMessageBox::about(this, tr("Login success"), tr("<p>Welcome...</p>"));
                _cl = 0;
            }
            else
            {
                QMessageBox::about(this, tr("Login unsuccess"), tr("<p>Wrong password</p>"));
                _cl = 1;
            }
     }
     return _cl;
}

void login::on_pushButtonLogin_clicked()
{
    vector<userandpass> checking;
    QString username;
    QString password;
    checking = _lists.checkForUsers();
    username = ui->lineEditUser->text();
    password = ui->lineEditPwd->text();


    for(unsigned int i = 0 ; i < checking.size() ; i++ )
    {
        QString getUser = QString::fromStdString(checking[i].getuser());
        QString getPwd = QString::fromStdString(checking[i].getpassword());
        if(getUser == username)
        {
            if(getPwd == password)
            {
                QMessageBox popup;
                popup.setText("Login successful");
                popup.exec();
                close();
            }
            else
            {
                QMessageBox errorpwd;
                errorpwd.setText("wrong password");
                errorpwd.exec();
            }
        }
    }
}


void login::on_pushButton_2_clicked()
{
    _users.setModal(true);
    _users.exec();
}
