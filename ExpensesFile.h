#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Expenses.h"
#include "User.h"
#include "UserManager.h"
#include "UsersFile.h"
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class ExpensesFile
{
    const string expensesFileName;
    int idOfLastExpense;
    int ID_LOGGED_USER;

    SupportiveMethods supportiveMethods;
    vector <Expenses> expenses;
    bool whetherFileIsEmpty();
    Expenses getIncomesData();

public:
    ExpensesFile(string EXPENSES_FILE_NAME) : expensesFileName(EXPENSES_FILE_NAME) {};
    int getIdOfLastExpense();
    void addExpenseToFile(Expenses expense);
    vector <Expenses> loadExpensesFromFile(int idLoggedUser);

};

#endif
