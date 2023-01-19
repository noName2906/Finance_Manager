#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Incomes.h"
#include "User.h"
#include "UsersFile.h"
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class IncomesFile
{
    const string incomesFileName;
    int idOfLastIncome;
    int ID_LOGGED_USER;

    vector <Incomes> incomes;
    bool whetherFileIsEmpty();
    Incomes getIncomesData();

public:
    IncomesFile(string INCOMES_FILE_NAME) : incomesFileName(INCOMES_FILE_NAME) {};
    int getIdOfNewIncome();
    int getIdOfLastIncome();
    void addIncomeToFile(Incomes income);
    vector <Incomes> loadIncomesFromFile();

};

#endif
