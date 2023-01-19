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
    static string convertionIntToString(int number);
    static int convertionStringToInt(string number);
    string checkCurrentDate();
    bool checkTheDate(int year, int month, int day);
};

#endif
