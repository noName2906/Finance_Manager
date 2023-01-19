#include "Incomes.h"

void Incomes::setupIncomeId (int newIncomeId)
{
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}

void Incomes::setupUserId (int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}

void Incomes::setupIncomeDate (string newIncomeDate)
{
    incomeDate = newIncomeDate;
}

void Incomes::setupIncomeItem(string newIncomeItem)
{
    incomeItem = newIncomeItem;
}

void Incomes::setupIncomeAmount(float newIncomeAmount)
{
    incomeAmount = newIncomeAmount;
}

int Incomes::getIncomeId()
{
    return incomeId;
}

int Incomes::getUserId()
{
    return userId;
}

string Incomes::getIncomeDate()
{
    return incomeDate;
}

string Incomes::getIncomeItem()
{
    return incomeItem;
}

float Incomes::getIncomeAmount()
{
    return incomeAmount;
}
