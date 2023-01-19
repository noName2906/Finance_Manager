#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login, password, name, surname;

public:
    void setupId(int newId);
    void setupLogin(string newLogin);
    void setupPassword(string newPassword);
    void setupName(string newName);
    void setupSurname(string newSurname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
