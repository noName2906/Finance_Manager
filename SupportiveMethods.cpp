#include "SupportiveMethods.h"

string SupportiveMethods::convertionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportiveMethods::convertionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportiveMethods::checkCurrentDate()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();
    return str;
}

bool SupportiveMethods::checkTheDate (int year, int month, int day)
{
    if (year > 0)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return true;
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30)
                return true;
        else if (month == 2)
        {
            if ((year%400 == 0 || (year%100 != 0 && year%4 == 0)) && day > 0 && day <= 29)
                return true;
            else if (day > 0 && day <= 28)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

string SupportiveMethods::changeIncomeCommaToDot(string incomeAmount)
{
    for(unsigned int i = 0; i < incomeAmount.length(); i++)
    {
        if (incomeAmount[i] == ',')
        {
            incomeAmount[i] = '.';
        }
        incomeAmount[i];
    }

    stringstream out;
    out << fixed << setprecision(2) << stof(incomeAmount);
    return out.str();
}

string SupportiveMethods::changeExpenseCommaToDot(string expenseAmount)
{
    for(unsigned int i = 0; i < expenseAmount.length(); i++)
    {
        if (expenseAmount[i] == ',')
        {
            expenseAmount[i] = '.';
        }
        expenseAmount[i];
    }

    stringstream out;
    out << fixed << setprecision(2) << stof(expenseAmount);
    return out.str();
}

int SupportiveMethods::currentDay(string currentDate)
{
    istringstream in{currentDate};
    in.exceptions(ios::failbit);
    tm tm;
    in >> get_time(&tm, "%Y-%m-%d");

    int day = tm.tm_mday;

    return day;
}

int SupportiveMethods::currentMonth(string currentDate)
{
    istringstream in{currentDate};
    in.exceptions(ios::failbit);
    tm tm;
    in >> get_time(&tm, "%Y-%m-%d");

    int month = tm.tm_mon + 1;

    return month;
}

int SupportiveMethods::currentYear(string currentDate)
{
    istringstream in{currentDate};
    in.exceptions(ios::failbit);
    tm tm;
    in >> get_time(&tm, "%Y-%m-%d");

    int year = tm.tm_year + 1900;

    return year;
}

