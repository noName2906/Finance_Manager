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
        budgetManager = new budgetManager(INCOMES_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void FinanceManager::addIncome()
{
    budgetManager -> addIncome();
}
