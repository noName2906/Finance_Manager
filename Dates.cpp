#include "Dates.h"

void Dates::setupIncomeDay (int newIncomeDay)
{
    if (newIncomeDay >= 0)
        incomeDay = newIncomeDay;
}

void Dates::setupIncomeMonth (int newIncomeMonth)
{
    if (newIncomeMonth >= 0)
        incomeMonth = newIncomeMonth;
}

void Dates::setupIncomeYear (int newIncomeYear)
{
    if (newIncomeYear >= 0)
        incomeYear = newIncomeYear;
}

void Dates::setupIncomeAmount (float newIncomeAmount)
{
    if (newIncomeAmount >= 0)
        incomeAmount = newIncomeAmount;
}

void Dates::setupExpenseDay (int newExpenseDay)
{
    if (newExpenseDay >= 0)
        expenseDay = newExpenseDay;
}

void Dates::setupExpenseMonth (int newExpenseMonth)
{
    if (newExpenseMonth >= 0)
        expenseMonth = newExpenseMonth;
}

void Dates::setupExpenseYear (int newExpenseYear)
{
    if (newExpenseYear >= 0)
        expenseYear = newExpenseYear;
}

void Dates::setupExpenseAmount (float newExpenseAmount)
{
    if (newExpenseAmount >= 0)
        expenseAmount = newExpenseAmount;
}

int Dates::getIncomeDay()
{
    return incomeDay;
}

int Dates::getIncomeMonth()
{
    return incomeMonth;
}

int Dates::getIncomeYear()
{
    return incomeYear;
}

float Dates::getIncomeAmount()
{
    return incomeAmount;
}

int Dates::getExpenseDay()
{
    return expenseDay;
}

int Dates::getExpenseMonth()
{
    return expenseMonth;
}

int Dates::getExpenseYear()
{
    return expenseYear;
}

float Dates::getExpenseAmount()
{
    return expenseAmount;
}

