#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;
    User enterNewUserDetails();
    int getIdOfNewUser();
    bool whetherLoginExists(string login);
    UsersFile usersFile;

public:
    UserManager(string usersFileName) : usersFile(usersFileName) {
    idLoggedUser =  0;
    users = usersFile.loadUsersFromFile();
    }

    void userRegistration();
    int userLogging();
    bool whetherUserIsSignedIn();
    int getIdLoggedUser();
};

#endif
