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
    bool isLegitComputer;
    bool hasUserName = getUserName();
    bool hasPassWord = getPassWord();

    isLegitComputer = (hasUserName && hasPassWord);

    if(isLegitComputer)
    {
        _username = ui->lineEditUserName->text().toStdString();
        string originalText = ui->lineEditPassword->text().toStdString();
        _password = chiperText(originalText, 5);
        userandpass itemUser(_username, _password);
        _lists.regiserUsers(itemUser);
        close();
    }

}

string registeruser::chiperText(string text, int shift)
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

    return (characterInAsciiValure >= 97 && characterInAsciiValure <= 122);
}

bool registeruser::getUserName()
{
    string potentialUSer = ui -> lineEditUserName ->text().toStdString();

    bool hasLegalCharacters = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditUserName->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    for(unsigned int i = 0; i < potentialUSer.size(); i++)
    {
        if(isalpha(potentialUSer[i]) || isdigit(potentialUSer[i]) || potentialUSer[i] == ' ')
        {
            //do nothing
        }
        else
        {
            hasLegalCharacters = false;
        }
    }

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->labelUser ->setText("<span style='color: red'>Input required</span>");

    }
    else if(!hasLegalCharacters)
    {
        ui ->labelUser ->setText("<span style='color: red'>Name can only contain characters, numbers and spaces</span>");
    }
    else if(potentialUSer.size() < 2 || potentialUSer.size() > 10)
    {
        ui -> labelUser ->setText("<span style=' color: red'>Name must be between 2 and 10 characters</span>");
    }
    else
    {
        //If there are no problems, the first name is legal.
        _username = potentialUSer;
    }
    return (hasContent && hasLegalCharacters && !(potentialUSer.size() < 2 || potentialUSer.size() > 10));
}

bool registeruser::getPassWord()
{
    string potentialPassWord = ui -> lineEditPassword ->text().toStdString();

    bool hasOnlyChar = true;
    bool hasContent = true;

    //Checks that there is something in the field
    if((ui ->lineEditPassword->text()).isEmpty())
    {
        hasContent = false;
    }

    //check that it has only characters
    for(unsigned int i = 0; i < potentialPassWord.size(); i++)
    {
        if(isalpha(potentialPassWord[i]))
        {
            //do nothing
        }
        else
        {
            hasOnlyChar = false;
        }
    }

    //Throws errors if any are needed
    if(!hasContent)
    {
        ui ->labelPwd->setText("<span style='color: red'>Last name required</span>");
    }
    else if(!hasOnlyChar)
    {
        ui ->labelPwd ->setText("<span style='color: red'>Password can only contain latin characters</span>");
    }
    else if(potentialPassWord.size() <= 3 || potentialPassWord.size() >= 10)
    {
        ui -> labelPwd ->setText("<span style=' color: red'>Password must be between 2 and 10 characters</span>");
    }
    else
    {
        //If there are no problems, the password is legal.
        _password = potentialPassWord;
    }
    return (hasContent && hasOnlyChar && !(potentialPassWord.size() <= 3 || potentialPassWord.size() >= 10));
}
