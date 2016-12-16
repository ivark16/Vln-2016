#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

login::~login()
{
    delete ui;
}

//This function is for when user presses login button
void login::on_pushButtonLogin_clicked()
{
    //sets the warnings to be empty in case the user has entered legitemate information.
    ui ->labelUser ->setText("");
    ui ->labelPwd ->setText("");

    vector<userandpass> checking;
    QString username;
    QString password;
    checking = _lists.checkForUsers();
    username = ui->lineEditUser->text();
    password = ui->lineEditPwd->text();
    bool userExists = false;

    for(unsigned int i = 0 ; i < checking.size() ; i++ )
    {
        QString getUser = QString::fromStdString(checking[i].getuser());
        QString getPwd = QString::fromStdString(checking[i].getpassword());
        if(getUser == username)
        {
            userExists = true;
            QString convert;
            string convertedKey;

            //Changes Qstring to normal string
            string decrypt = getPwd.toLocal8Bit().constData();
            convertedKey = theDecrypter(decrypt);
            QString decryptedPwd = QString::fromStdString(convertedKey);
            if(decryptedPwd == password)
            {
                //sends accept signal to main
                QDialog::accept();
                QMessageBox popup;
                popup.setText("Login successful");
                popup.exec();


            }
            else
            {
               ui ->labelPwd ->setText("<span style='color: red'>Incorrect password</span>");
            }
        }
    }
    if(!userExists)
    {
        //if its empty, nothing is displayed but if it
        if(!ui ->lineEditUser ->text().isEmpty())
        {
              ui ->labelUser ->setText("<span style='color: red'>User does not exist</span>");
        }
    }
}

//This is for when user presses register button
void login::on_pushButton_2_clicked()
{
    _users.setModal(true);
    _users.exec();
}

//This is the primary function for decrypting
string login::theDecrypter(string text)
{
    string decrypt = "";
    int key = 21;
    decrypt = deChiperText(text, key);
    return decrypt;
}

//This is function takes the string and how many shifts the decrytion has to have
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

//This function shifts the string
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

//This function checks if the character is uppercase
bool login::isUpperCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 65 && characterInAsciiValure <= 90);
}

//This function checks if the character is lowercase
bool login::isLowerCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 97 && characterInAsciiValure <= 122);
}
