#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class UsersFile
{
    int id;
    string login, password, name, surname;
    const string usersFileName;
    vector <User> users;

    bool whetherFileIsEmpty();
    vector <User> getUserData();

public:
    UsersFile(string USERS_FILE_NAME) : usersFileName(USERS_FILE_NAME) {};
    int getIdOfNewUser();
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();

};

#endif
