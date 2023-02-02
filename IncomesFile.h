#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Incomes.h"
#include "User.h"
#include "UserManager.h"
#include "UsersFile.h"
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class IncomesFile
{
    const string incomesFileName;
    int idOfLastIncome;
    int ID_LOGGED_USER;

    SupportiveMethods supportiveMethods;
    vector <Incomes> incomes;
    bool whetherFileIsEmpty();
    Incomes getIncomesData();

public:
    IncomesFile(string INCOMES_FILE_NAME) : incomesFileName(INCOMES_FILE_NAME) {};
    int getIdOfLastIncome();
    void addIncomeToFile(Incomes income);
    vector <Incomes> loadIncomesFromFile(int idLoggedUser);

};

#endif
