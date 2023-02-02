#ifndef DATES_H
#define DATES_H

#include <iostream>

using namespace std;

class Dates
{
    int incomeDay, incomeMonth, incomeYear, expenseDay, expenseMonth, expenseYear;
    float incomeAmount, expenseAmount;

public:
    void setupIncomeDay (int newIncomeDay);
    void setupIncomeMonth (int newIncomeMonth);
    void setupIncomeYear (int newIncomeYear);
    void setupIncomeAmount (float newIncomeAmount);

    void setupExpenseDay (int newExpenseDay);
    void setupExpenseMonth (int newExpenseMonth);
    void setupExpenseYear (int newExpenseYear);
    void setupExpenseAmount (float newExpenseAmount);

    int getIncomeDay();
    int getIncomeMonth();
    int getIncomeYear();
    float getIncomeAmount();

    int getExpenseDay();
    int getExpenseMonth();
    int getExpenseYear();
    float getExpenseAmount();
};

#endif
