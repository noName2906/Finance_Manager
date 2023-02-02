#include "FinanceManager.h"

void FinanceManager::userRegistration()
{
    userManager.userRegistration();
}

void FinanceManager::userLogging()
{
    userManager.userLogging();
    if (userManager.whetherUserIsSignedIn())
    {
        budgetManager = new BudgetManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void FinanceManager::addIncome()
{
    budgetManager -> addIncome();
}

void FinanceManager::addExpense()
{
    budgetManager -> addExpense();
}

void FinanceManager::balanceOfThisMonth()
{
    budgetManager -> balanceOfThisMonth();
}
