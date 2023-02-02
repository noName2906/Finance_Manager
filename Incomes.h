#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes
{
    int incomeId, userId;
    string incomeDate, incomeItem, incomeAmount;

public:

    void setupIncomeId (int newIncomeId);
    void setupUserId (int newUserId);
    void setupIncomeDate (string newIncomeDate);
    void setupIncomeItem (string newIncomeItem);
    void setupIncomeAmount (string newIncomeAmount);

    int getIncomeId();
    int getUserId();
    string getIncomeDate();
    string getIncomeItem();
    string getIncomeAmount();
};

#endif
