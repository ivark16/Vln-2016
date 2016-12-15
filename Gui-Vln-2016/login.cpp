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
            QString convert;
            string convertedKey;
            string decrypt = getPwd.toLocal8Bit().constData();
            convertedKey = theDecrypter(decrypt);
            QString decryptedPwd = QString::fromStdString(convertedKey);
            if(decryptedPwd == password)
            {
                QDialog::accept();
                QMessageBox popup;
                popup.setText("Login successful");
                popup.exec();

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

string login::theDecrypter(string text)
{
    string decrypt = "";
    int key = 21;
    decrypt = deChiperText(text, key);
    return decrypt;
}

string login::deChiperText(string text, int shift)
{
    string result = "";

    for(unsigned int i = 0; i < text.length() ; i++)
    {
        char currentCharacter = text[i];

        if(isUpperCase(currentCharacter) || isLowerCase(currentCharacter))
        {
            result += shiftCharacter(currentCharacter, shift);
        }
        else
        {
            result += currentCharacter;
        }
    }

    return result;
}

char login::shiftCharacter(char character, int shift)
{
    int characterAsciiValue = static_cast<int>(character);
    int characterAsciiOffset = 0;

    if(isUpperCase(character))
    {
        characterAsciiOffset = 65;
    }
    else if(isLowerCase(character))
    {
        characterAsciiOffset = 97;
    }

    if(characterAsciiOffset)
    {
        characterAsciiValue -= characterAsciiOffset;
        characterAsciiValue = (characterAsciiValue + shift) % 26;
        characterAsciiValue += characterAsciiOffset;
    }

    return static_cast<char>(characterAsciiValue);
}

bool login::isUpperCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 65 && characterInAsciiValure <= 90);
}

bool login::isLowerCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 97 && characterInAsciiValure <= 122);
}
