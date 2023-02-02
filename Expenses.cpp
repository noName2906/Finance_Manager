#include "Expenses.h"

void Expenses::setupExpenseId (int newExpenseId)
{
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}

void Expenses::setupUserId (int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}

void Expenses::setupExpenseDate (string newExpenseDate)
{
    expenseDate = newExpenseDate;
}

void Expenses::setupExpenseItem(string newExpenseItem)
{
    expenseItem = newExpenseItem;
}

void Expenses::setupExpenseAmount(string newExpenseAmount)
{
    expenseAmount = newExpenseAmount;
}

int Expenses::getExpenseId()
{
    return expenseId;
}

int Expenses::getUserId()
{
    return userId;
}

string Expenses::getExpenseDate()
{
    return expenseDate;
}

string Expenses::getExpenseItem()
{
    return expenseItem;
}

string Expenses::getExpenseAmount()
{
    return expenseAmount;
}
