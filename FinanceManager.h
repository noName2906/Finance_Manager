#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class FinanceManager
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME;

public:
    FinanceManager(string usersFileName, string incomesFileName)
    : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName) {
    budgetManager = NULL;
    };
    ~FinanceManager()
    {
        delete budgetManager;
        budgetManager = NULL;
    };

    void userRegistration();
    void userLogging();
    void addIncome();

};

#endif
