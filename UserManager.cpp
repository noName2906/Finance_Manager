#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = enterNewUserDetails();
    users.push_back(user);
    usersFile.addUserToFile(user);

    system("cls");
    cout << ">>>>> USER SIGN UP <<<<<" << endl;
    cout << "------------------------" << endl;
    cout << "Account created successfully" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserDetails()
{
    User user;

    user.setupId(getIdOfNewUser());

    string name, surname, login;
    do
    {
        system("cls");
        cout << ">>>>> USER SIGN UP <<<<<" << endl;
        cout << "------------------------" << endl;
        cout << "Enter your name: ";
        cin >> name;
        user.setupName(name);
        cout << "Enter your surname: ";
        cin >> surname;
        user.setupSurname(surname);
        cout << "Enter your new login: ";
        cin >> login;
        user.setupLogin(login);
    }
    while (whetherLoginExists(user.getLogin()) == true);

    string password;
    cout << "Enter your new password: ";
    cin >> password;
    user.setupPassword(password);

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::whetherLoginExists(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            system ("cls");
            cout << ">>>>> USER SIGN UP <<<<<" << endl;
            cout << "-----------------------------" << endl;
            cout << "Your login already exists. Please use a different one." << endl;
            Sleep (2500);
            return true;
        }
    }
    return false;
}

int UserManager::userLogging()
{
    string login, password;

    system ("cls");
    cout << ">>>>> USER SIGN IN <<<<<" << endl;
    cout << "------------------------" << endl;
    cout << "Enter your login: ";
    cin.sync();
    getline(cin, login);

    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            idLoggedUser = users[i].getId();

            for (int counter = 3; counter > 0; counter--)
            {
                system ("cls");
                cout << ">>>>> USER SIGN IN <<<<<" << endl;
                cout << "------------------------" << endl;
                cout << "Number of remaining trials: " << counter << endl << endl;
                cout << "Eneter your password: ";
                cin.sync();
                getline(cin, password);
                cout << endl << endl;

                if (users[i].getPassword() == password)
                {
                    system ("cls");
                    cout << ">>>>> USER SIGN IN <<<<<" << endl;
                    cout << "------------------------" << endl;
                    cout << "You signed in correctly" << endl << endl;
                    system ("pause");
                    return idLoggedUser;
                }
            }
            system ("cls");
            cout << ">>>>> USER SIGN IN <<<<<" << endl;
            cout << "------------------------" << endl;
            cout << "You entered wrong password 3 times. The program will be closed. Try again." << endl << endl;
            system("pause");
            exit(0);
        }
    }
    system ("cls");
    cout << ">>>>> USER SIGN IN <<<<<" << endl;
    cout << "------------------------" << endl;
    cout << "No user with such login. Try again." << endl << endl;
    system("pause");
    return userLogging();
}

bool UserManager::whetherUserIsSignedIn()
{
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

void UserManager::changePassword()
{
    string newPassword = "";

    system ("cls");
    cout << ">>>>> CHANGE PASSWORD  <<<<<" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter your new password: ";
    cin >> newPassword;

    usersFile.changePassword(idLoggedUser, newPassword);

    system ("cls");
    cout << ">>>>> CHANGE PASSWORD  <<<<<" << endl;
    cout << "----------------------------" << endl;
    cout << "Your password has changed correctly" << endl;
    Sleep(1200);
}
