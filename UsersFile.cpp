#include "UsersFile.h"


bool UsersFile::whetherFileIsEmpty()
{
    fstream file;
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

/*User UsersFile::getUserData()
{
    User user;
    //do dokonczenia
} */

vector <User> UsersFile::loadUsersFromFile()
{
    vector <User> users;
    User user;

   fstream file(usersFileName);

    CMarkup xml;
    xml.Load(usersFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem(("User")) )
    {
        xml.FindChildElem("ID");
        user.setupId(atoi(xml.GetChildData().c_str()));
        cout << "User ID : " << user.getId() << endl;
        xml.FindChildElem("Login");
        user.setupLogin(xml.GetChildData());
        cout << "Login : " << user.getLogin() << endl;
        xml.FindChildElem("Password");
        user.setupPassword(xml.GetChildData());
        cout << "Password : " << user.getPassword() << endl;
        xml.FindChildElem("Name");
        user.setupName(xml.GetChildData());
        cout << "Name : " << user.getName() << endl;
        xml.FindChildElem("Surname");
        user.setupSurname(xml.GetChildData());
        cout << "Surname : " << user.getSurname() << endl;
        users.push_back(user);
    }
    return users;
}

int UsersFile::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UsersFile::addUserToFile(User user)
{
    CMarkup xml;

    if (!xml.Load(usersFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("ID", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(usersFileName);
}
