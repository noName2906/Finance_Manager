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
    const string usersFileName;
    bool whetherFileIsEmpty();

public:
    UsersFile(string USERS_FILE_NAME) : usersFileName(USERS_FILE_NAME) {};
    int getIdOfNewUser();
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePassword(int idLoggedUser, string newPassword);

};

#endif
