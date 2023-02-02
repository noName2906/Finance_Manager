#ifndef SUPPORTIVEMETHODS_H
#define SUPPORTIVEMETHODS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class SupportiveMethods
{
public:
    float floatIncomeAmount;
    static string convertionIntToString(int number);
    static int convertionStringToInt(string number);
    string checkCurrentDate();
    bool checkTheDate(int year, int month, int day);
    string changeIncomeCommaToDot(string incomeAmount);
    string changeExpenseCommaToDot(string expenseAmount);
    int currentDay(string currentDate);
    int currentMonth(string currentDate);
    int currentYear(string currentDate);
};

#endif
