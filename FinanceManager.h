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
    const string EXPENSES_FILE_NAME;

public:
    FinanceManager(string usersFileName, string incomesFileName, string expensesFileName)
    : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
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
    void addExpense();
    void balanceOfThisMonth();

};

#endif
