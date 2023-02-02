#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include<bits/stdc++.h>

#include "UserManager.h"
#include "UsersFile.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Incomes.h"
#include "Expenses.h"
#include "Dates.h"
#include "User.h"
#include "SupportiveMethods.h"

using namespace std;

class BudgetManager
{
    int incomeId, expensesId;
    string incomeDate, incomeItem, incomeAmount, expenseDate, expenseItem, expenseAmount;
    const int ID_LOGGED_USER;
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    vector <Dates> incomeDates;
    vector <Dates> expenseDates;
    vector <Dates> singleIncomeData;
    vector <Dates> singleExpenseData;

    Incomes enterNewIncomeDetails();
    IncomesFile incomesFile;
    Expenses enterNewExpenseDetails();
    ExpensesFile expensesFile;
    void selectIncomesToDisplay();
    float incomesSorting(vector <Dates> incomeDates);
    float expensesSorting(vector <Dates> expenseDates);

public:
    BudgetManager(string incomesFileName, string  expensesFileName, int idLoggedUser)
    : ID_LOGGED_USER(idLoggedUser), incomesFile(incomesFileName), expensesFile(expensesFileName) {
    incomes = incomesFile.loadIncomesFromFile(idLoggedUser);
    expenses = expensesFile.loadExpensesFromFile(idLoggedUser);
    };
    void addIncome();
    void addExpense();
    void balanceOfThisMonth();
};

#endif
