#include "userandpass.h"

userandpass::userandpass()
{

}

userandpass::userandpass(string username, string password)
{
    _username = username;
    _password = password;
}

string userandpass::getuser()
{
    return _username;
}

string userandpass::getpassword()
{
    return _password;
}
