#include "User.h"

void User::setupId(int newId)
{
    if (newId >= 0)
        id = newId;
}

void User::setupLogin(string newLogin)
{
    login = newLogin;
}

void User::setupPassword(string newPassword)
{
    password = newPassword;
}

void User::setupName(string newName)
{
    name = newName;
}

void User::setupSurname(string newSurname)
{
    surname = newSurname;
}

int User::getId()
{
    return id;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}
