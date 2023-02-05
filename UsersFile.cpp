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
        xml.FindChildElem("Login");
        user.setupLogin(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setupPassword(xml.GetChildData());
        xml.FindChildElem("Name");
        user.setupName(xml.GetChildData());
        xml.FindChildElem("Surname");
        user.setupSurname(xml.GetChildData());
        users.push_back(user);
    }
    return users;
}

int UsersFile::getIdOfNewUser()
{
    vector <User> users;

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

void UsersFile::changePassword(int idLoggedUser, string newPassword)
{
    vector <User> users;
    User user;

    CMarkup xml;
    xml.Load(usersFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem(("User")) )
    {
        xml.FindChildElem("ID");
        if (atoi(xml.GetChildData().c_str()) == idLoggedUser)
        {
            user.setupId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Login");
            user.setupLogin(xml.GetChildData());
            xml.FindChildElem("Password");
            xml.RemoveChildElem();
            xml.AddChildElem("Password", newPassword);
            user.setupPassword(newPassword);
            xml.FindChildElem("Name");
            user.setupName(xml.GetChildData());
            xml.FindChildElem("Surname");
            user.setupSurname(xml.GetChildData());
            users.push_back(user);
            xml.Save(usersFileName);
        }
        else
        {
            user.setupId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Login");
            user.setupLogin(xml.GetChildData());
            xml.FindChildElem("Password");
            user.setupPassword(xml.GetChildData());
            xml.FindChildElem("Name");
            user.setupName(xml.GetChildData());
            xml.FindChildElem("Surname");
            user.setupSurname(xml.GetChildData());
            users.push_back(user);
            xml.Save(usersFileName);
        }
    }
}
