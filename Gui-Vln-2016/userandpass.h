#ifndef USERANDPASS_H
#define USERANDPASS_H
#include <iostream>
#include <string>

using namespace std;

class userandpass
{
    string _username;
    string _password;

public:
    userandpass();
    userandpass(string username, string password);
    string getuser();
    string getpassword();
};

#endif // USERANDPASS_H
