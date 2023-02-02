#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses
{
    int expenseId, userId;
    string expenseDate, expenseItem, expenseAmount;

public:

    void setupExpenseId (int newExpenseId);
    void setupUserId (int newUserId);
    void setupExpenseDate (string newExpenseDate);
    void setupExpenseItem (string newExpenseItem);
    void setupExpenseAmount (string newExpenseAmount);

    int getExpenseId();
    int getUserId();
    string getExpenseDate();
    string getExpenseItem();
    string getExpenseAmount();
};

#endif
