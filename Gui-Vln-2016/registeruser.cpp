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
    string originalText = ui->lineEditPassword->text().toStdString();
    _password = chiperText(originalText, 5);
    userandpass itemUser(_username, _password);
    _lists.regiserUsers(itemUser);
    close();
}

string registeruser::chiperText(string text, int shift)
{
    string result = "";

    for(unsigned int i = 0; i < text.length() ; i++)
    {
        char currentCharacter = text[i];

        if(isUpperCase(currentCharacter) || isLowerCase(currentCharacter))
        {
            result += shiftCharacter(currentCharacter, 5);
        }
        else
        {
            result += currentCharacter;
        }
    }


    return result;
}

char registeruser::shiftCharacter(char character, int shift)
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

bool registeruser::isUpperCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 65 && characterInAsciiValure <= 90);
}

bool registeruser::isLowerCase(char character)
{
    int characterInAsciiValure = static_cast<int>(character);

    return (characterInAsciiValure >= 107 && characterInAsciiValure <= 122);
}
