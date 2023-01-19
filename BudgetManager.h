#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "UserManager.h"
#include "UsersFile.h"
#include "IncomesFile.h"
#include "Incomes.h"
#include "User.h"
#include "SupportiveMethods.h"

using namespace std;

class BudgetManager
{
    int incomeId;
    string incomeDate, incomeItem;
    float incomeAmount;
    const int ID_LOGGED_USER;
    vector <Incomes> incomes;
    int getIdOfNewIncome();

    Incomes enterNewIncomeDetails();
    IncomesFile incomesFile;

public:
    BudgetManager(string incomesFileName, int idLoggedUser)
    : ID_LOGGED_USER(idLoggedUser), incomesFile(incomesFileName) {
    incomes = incomesFile.loadIncomesFromFile(idLoggedUser);
    };
    void addIncome();
};

#endif
