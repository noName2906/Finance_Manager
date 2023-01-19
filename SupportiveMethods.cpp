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

bool SupportiveMethods::checkTheDate( int year, int month, int day)
{
    if(1000 <= year <= 3000)
    {
        if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return true;
        else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30)
                return true;
        else if(month == 2)
        {
            if((year%400 == 0 || (year%100 != 0 && year%4 == 0)) && day > 0 && day <= 29)
                return true;
            else if(day > 0 && day <= 28)
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
