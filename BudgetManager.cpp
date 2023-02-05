#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Incomes income = enterNewIncomeDetails();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    system("cls");
    cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
    cout << "-----------------------------" << endl;
    cout << "Income added successfully" << endl << endl;
    system("pause");
}

void BudgetManager::addExpense()
{
    Expenses expense = enterNewExpenseDetails();
    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    system("cls");
    cout << ">>>>>>>> EXPENSE MENU <<<<<<<<" << endl;
    cout << "-----------------------------" << endl;
    cout << "Expense added successfully" << endl << endl;
    system("pause");
}

Incomes BudgetManager::enterNewIncomeDetails()
{
    Incomes income;
    SupportiveMethods supportiveMethods;

    int incomeChoice = 0;
    int year = 0, month = 0, day = 0;
    string incomeDate = "", incomeItem = "", incomeAmount = "";

    while(true)
    {
        system("cls");
        cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
        cout << "-----------------------------" << endl;
        cin.sync();
        cout << "1. Today" << endl;
        cout << "2. Specific date" << endl << endl;
        cout << "Please enter \"1\" or \"2\" depends on which date of income you want to add: ";
        cin >> incomeChoice;

        switch (incomeChoice)
        {
        case 1:
            system("cls");
            cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
            cout << "-----------------------------" << endl;
            income.setupIncomeId(incomesFile.getIdOfLastIncome());
            income.setupUserId(ID_LOGGED_USER);
            incomeDate = supportiveMethods.checkCurrentDate();
            income.setupIncomeDate(incomeDate);
            cout << "What does income relate to?: ";
            cin.sync();
            getline(cin, incomeItem);
            income.setupIncomeItem(incomeItem);
            cout << endl;
            cout << "What is amount of this income?: ";
            getline(cin, incomeAmount);
            incomeAmount = supportiveMethods.changeIncomeCommaToDot(incomeAmount);
            income.setupIncomeAmount(incomeAmount);
            return income;
        case 2:
            system("cls");
            cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
            cout << "-----------------------------" << endl;
            cout << "Enter your date in format \"YYYY-MM-DD\": ";
            cin >> incomeDate;
            cout << endl;

            if (incomeDate.length() != 10 || incomeDate[4] != '-' || incomeDate[7] != '-')
            {
                system("cls");
                cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
                cout << "-----------------------------" << endl;
                cout << "Incorrect date format. Please try again." << endl;
                system ("pause");
                system ("cls");
                return enterNewIncomeDetails();
            }
            else
            {
                istringstream stm(incomeDate) ;
                char delim;
                stm >> year >> delim ;
                stm >> month >> delim ;
                stm >> day;

                if (supportiveMethods.checkTheDate(year, month, day) == true)
                {
                    income.setupIncomeId(incomesFile.getIdOfLastIncome());
                    income.setupUserId(ID_LOGGED_USER);
                    income.setupIncomeDate(incomeDate);
                    cout << "What does income relate to?: ";
                    cin.sync();
                    getline(cin, incomeItem);
                    income.setupIncomeItem(incomeItem);
                    cout << endl;
                    cout << "What is amount of this income?: ";
                    getline(cin, incomeAmount);
                    incomeAmount = supportiveMethods.changeIncomeCommaToDot(incomeAmount);
                    cout << incomeAmount << endl;
                    income.setupIncomeAmount(incomeAmount);
                    return income;
                }
                else
                {
                    cout << "Your date format is incorrect. Try again" << endl;
                    system ("pause");
                    system ("cls");
                    return enterNewIncomeDetails();
                }
            }
        default:
            cout << "Incorrect choice. Try again." << endl;
            system ("pause");
            break;
        }
    }
}

Expenses BudgetManager::enterNewExpenseDetails()
{
    Expenses expense;
    SupportiveMethods supportiveMethods;

    int expenseChoice = 0;
    int year = 0, month = 0, day = 0;
    string expenseDate ="", expenseItem = "", expenseAmount = "";

    while(true)
    {
        system("cls");
        cout << ">>>>>>>> EXPENSE MENU <<<<<<<<" << endl;
        cout << "-----------------------------" << endl;
        cin.sync();
        cout << "1. Today" << endl;
        cout << "2. Specific date" << endl << endl;
        cout << "Please enter \"1\" or \"2\" depends on which date of expense you want to add: ";
        cin >> expenseChoice;

        switch (expenseChoice)
        {
        case 1:
            system("cls");
            cout << ">>>>>>>> EXPENSE MENU <<<<<<<<" << endl;
            cout << "------------------------------" << endl;
            expense.setupExpenseId(expensesFile.getIdOfLastExpense());
            expense.setupUserId(ID_LOGGED_USER);
            expenseDate = supportiveMethods.checkCurrentDate();
            expense.setupExpenseDate(expenseDate);
            cout << "What does expense relate to?: ";
            cin.sync();
            getline(cin, expenseItem);
            expense.setupExpenseItem(expenseItem);
            cout << endl;
            cout << "What is amount of this expense?: ";
            getline(cin, expenseAmount);
            expenseAmount = supportiveMethods.changeExpenseCommaToDot(expenseAmount);
            expense.setupExpenseAmount(expenseAmount);
            return expense;
        case 2:
            system("cls");
            cout << ">>>>>>>> EXPENSE MENU <<<<<<<<" << endl;
            cout << "-----------------------------" << endl;
            cout << "Enter your date in format \"YYYY-MM-DD\": ";
            cin >> expenseDate;
            cout << endl;

            if (expenseDate.length() != 10 || expenseDate[4] != '-' || expenseDate[7] != '-')
            {
                cout << "Incorrect date format. Please try again." << endl;
                system ("pause");
                system ("cls");
                return enterNewExpenseDetails();
            }
            else
            {
                istringstream stm(expenseDate) ;
                char delim;
                stm >> year >> delim ;
                stm >> month >> delim ;
                stm >> day;

                if (supportiveMethods.checkTheDate(year, month, day) == true)
                {
                    expense.setupExpenseId(expensesFile.getIdOfLastExpense());
                    expense.setupUserId(ID_LOGGED_USER);
                    expense.setupExpenseDate(expenseDate);
                    cout << "What does expense relate to?: ";
                    cin.sync();
                    getline(cin, expenseItem);
                    expense.setupExpenseItem(expenseItem);
                    cout << endl;
                    cout << "What is amount of this expnese?: ";
                    getline(cin, expenseAmount);
                    expenseAmount = supportiveMethods.changeExpenseCommaToDot(expenseAmount);
                    expense.setupExpenseAmount(expenseAmount);
                    return expense;
                }
                else
                {
                    cout << "Your date format is incorrect. Try again" << endl;
                    system ("pause");
                    system ("cls");
                    return enterNewExpenseDetails();
                }
            }
        default:
            cout << "Incorrect choice. Try again." << endl;
            system ("pause");
            break;
        }
    }
}

void BudgetManager::balanceOfThisMonth()
{
    float sumIncomes = 0;
    float sumExpenses = 0;
    system("cls");
    cout << ">>>>>>>> BALANCE OF THIS MONTH <<<<<<<<" << endl;
    cout << "---------------------------------------" << endl;

    int checkedYear, checkedMonth, checkedDay;
    SupportiveMethods supportiveMethods;
    Dates singleIncomeData;
    Dates singleExpenseData;

    string currentDate = supportiveMethods.checkCurrentDate();
    int currentMonth = supportiveMethods.currentMonth(currentDate);
    int currentYear = supportiveMethods.currentYear(currentDate);

    incomeDates.clear();
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        checkedYear = supportiveMethods.currentYear(incomes[i].getIncomeDate());
        if (checkedYear == currentYear)
        {
            checkedMonth = supportiveMethods.currentMonth(incomes[i].getIncomeDate());
            if (checkedMonth == currentMonth)
            {
                checkedDay = supportiveMethods.currentDay(incomes[i].getIncomeDate());
                singleIncomeData.setupIncomeDay(checkedDay);
                singleIncomeData.setupIncomeMonth(checkedMonth);
                singleIncomeData.setupIncomeYear(checkedYear);
                singleIncomeData.setupIncomeAmount(stof(incomes[i].getIncomeAmount()));
                incomeDates.push_back(singleIncomeData);
            }
        }
    }

    if (incomeDates.empty())
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF THIS MONTH <<<<<<<<" << endl;
        cout << "---------------------------------------" << endl;
        cout << "INCOMES:" << endl;
        cout << "--------" << endl;
        cout << "Your incomes from this month: " << sumIncomes << " zl" << endl << endl << endl;
    }
    else
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF THIS MONTH <<<<<<<<" << endl;
        cout << "---------------------------------------" << endl;
        sumIncomes = incomesSorting(incomeDates);
    }

    expenseDates.clear();
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        checkedYear = supportiveMethods.currentYear(expenses[i].getExpenseDate());
        if (checkedYear == currentYear)
        {
            checkedMonth = supportiveMethods.currentMonth(expenses[i].getExpenseDate());
            if (checkedMonth == currentMonth)
            {
                checkedDay = supportiveMethods.currentDay(expenses[i].getExpenseDate());
                singleExpenseData.setupExpenseDay(checkedDay);
                singleExpenseData.setupExpenseMonth(checkedMonth);
                singleExpenseData.setupExpenseYear(checkedYear);
                singleExpenseData.setupExpenseAmount(stof(expenses[i].getExpenseAmount()));
                expenseDates.push_back(singleExpenseData);
            }
        }
    }
    if (expenseDates.empty())
    {
        cout << "EXPENSES:" << endl;
        cout << "---------" << endl;
        cout << "Your expenses from this month: " << sumExpenses << " zl" <<endl << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget of this month: " << sumIncomes - sumExpenses << " zl" << endl;
        system ("pause");
    }
    else
    {
        sumExpenses = expensesSorting(expenseDates);
        cout << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget of this month: " << sumIncomes - sumExpenses << " zl" << endl << endl;
        system ("pause");
    }
}

void BudgetManager::balanceOfPreviousMonth()
{
    float sumIncomes = 0;
    float sumExpenses = 0;
    system("cls");
    cout << ">>>>>>>> BALANCE OF PREVIOUS MONTH <<<<<<<<" << endl;
    cout << "-------------------------------------------" << endl;

    int checkedYear, checkedMonth, checkedDay;
    SupportiveMethods supportiveMethods;
    Dates singleIncomeData;
    Dates singleExpenseData;

    string currentDate = supportiveMethods.checkCurrentDate();
    int currentMonth = supportiveMethods.currentMonth(currentDate);
    int currentYear = supportiveMethods.currentYear(currentDate);

    incomeDates.clear();
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        if (currentMonth - 1 == 0)
        {
            currentMonth = 13;
            currentYear = currentYear - 1;
        }
        checkedYear = supportiveMethods.currentYear(incomes[i].getIncomeDate());
        if (checkedYear == currentYear)
        {
            checkedMonth = supportiveMethods.currentMonth(incomes[i].getIncomeDate());
            if (checkedMonth == currentMonth - 1)
            {
                checkedDay = supportiveMethods.currentDay(incomes[i].getIncomeDate());
                singleIncomeData.setupIncomeDay(checkedDay);
                singleIncomeData.setupIncomeMonth(checkedMonth);
                singleIncomeData.setupIncomeYear(checkedYear);
                singleIncomeData.setupIncomeAmount(stof(incomes[i].getIncomeAmount()));
                incomeDates.push_back(singleIncomeData);
            }
        }
    }

    if (incomeDates.empty())
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF PREVIOUS MONTH <<<<<<<<" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "INCOMES:" << endl;
        cout << "--------" << endl;
        cout << "Your incomes from previous month: " << sumIncomes << " zl" << endl << endl << endl;
    }
    else
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF PREVIOUS MONTH <<<<<<<<" << endl;
        cout << "-------------------------------------------" << endl;
        sumIncomes = incomesSorting(incomeDates);
    }

    expenseDates.clear();
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        if (currentMonth - 1 == 0)
        {
            currentMonth = 13;
            currentYear = currentYear - 1;
        }
        checkedYear = supportiveMethods.currentYear(expenses[i].getExpenseDate());
        if (checkedYear == currentYear)
        {
            checkedMonth = supportiveMethods.currentMonth(expenses[i].getExpenseDate());
            if (checkedMonth == currentMonth - 1)
            {
                checkedDay = supportiveMethods.currentDay(expenses[i].getExpenseDate());
                singleExpenseData.setupExpenseDay(checkedDay);
                singleExpenseData.setupExpenseMonth(checkedMonth);
                singleExpenseData.setupExpenseYear(checkedYear);
                singleExpenseData.setupExpenseAmount(stof(expenses[i].getExpenseAmount()));
                expenseDates.push_back(singleExpenseData);
            }
        }
    }
    if (expenseDates.empty())
    {
        cout << "EXPENSES:" << endl;
        cout << "---------" << endl;
        cout << "Your expenses from previous month: " << sumExpenses << " zl" <<endl << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget from previous month: " << sumIncomes - sumExpenses << " zl" << endl;
        system ("pause");
    }
    else
    {
        sumExpenses = expensesSorting(expenseDates);
        cout << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget from previous month: " << sumIncomes - sumExpenses << " zl" << endl << endl;
        system ("pause");
    }
}

void BudgetManager::balanceOfSelectedPeriod()
{
    float sumIncomes = 0;
    float sumExpenses = 0;
    string startDate = "", endDate = "";
    int startYear = 0, startMonth = 0, startDay = 0, endYear = 0, endMonth = 0, endDay = 0;

    system("cls");
    cout << ">>>>>>>> BALANCE OF SELECTED PERIOD <<<<<<<<" << endl;
    cout << "--------------------------------------------" << endl << endl;

    cout << "Enter your start date in format YYYY-MM-DD: ";
    cin >> startDate;
    cout << endl << endl;
    cout << "Enter your end date in format YYYY-MM-DD: ";
    cin >> endDate;

    if (startDate.length() != 10 || startDate[4] != '-' || startDate[7] != '-' || endDate.length() != 10 || endDate[4] != '-' || endDate[7] != '-')
    {
        cout << "Incorrect date format. Please try again." << endl;
        system ("pause");
        system ("cls");
        return balanceOfSelectedPeriod();
    }
    else
    {
        istringstream stm(startDate) ;
        char delim;
        stm >> startYear >> delim ;
        stm >> startMonth >> delim ;
        stm >> startDay >> delim;
        istringstream etm(endDate);
        etm >> endYear >> delim ;
        etm >> endMonth >> delim ;
        etm >> endDay >> delim;
    }


    int checkedYear, checkedMonth, checkedDay;
    SupportiveMethods supportiveMethods;
    Dates singleIncomeData;
    Dates singleExpenseData;

    string currentDate = supportiveMethods.checkCurrentDate();

    incomeDates.clear();
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        checkedYear = supportiveMethods.currentYear(incomes[i].getIncomeDate());
        if (checkedYear >= startYear && checkedYear <= endYear)
        {
            checkedMonth = supportiveMethods.currentMonth(incomes[i].getIncomeDate());
            checkedDay = supportiveMethods.currentDay(incomes[i].getIncomeDate());
            if ((checkedYear == startYear && checkedMonth == startMonth && checkedDay >= startDay) || (checkedYear == startYear && checkedMonth > startMonth) || (checkedYear > startYear))
            {
                if ((checkedYear == endYear && checkedMonth == endMonth && checkedDay <= endDay) || (checkedYear == endYear && checkedMonth < endMonth) || (checkedYear < endYear))
                {
                    singleIncomeData.setupIncomeDay(checkedDay);
                    singleIncomeData.setupIncomeMonth(checkedMonth);
                    singleIncomeData.setupIncomeYear(checkedYear);
                    singleIncomeData.setupIncomeAmount(stof(incomes[i].getIncomeAmount()));
                    incomeDates.push_back(singleIncomeData);
                }
            }
        }
    }

    if (incomeDates.empty())
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF SELECTED PERIOD <<<<<<<<" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "INCOMES:" << endl;
        cout << "--------" << endl;
        cout << "Your incomes from " << startDate << " to " << endDate << ": " << sumIncomes << " zl" << endl << endl << endl;
    }
    else
    {
        system("cls");
        cout << ">>>>>>>> BALANCE OF SELECTED PERIOD <<<<<<<<" << endl;
        cout << "--------------------------------------------" << endl;
        sumIncomes = incomesSorting(incomeDates);
    }

    expenseDates.clear();
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        checkedYear = supportiveMethods.currentYear(expenses[i].getExpenseDate());
        if (checkedYear >= startYear && checkedYear <= endYear)
        {
            checkedMonth = supportiveMethods.currentMonth(expenses[i].getExpenseDate());
            checkedDay = supportiveMethods.currentDay(expenses[i].getExpenseDate());
            if ((checkedYear == startYear && checkedMonth == startMonth && checkedDay >= startDay) || (checkedYear == startYear && checkedMonth > startMonth) || (checkedYear > startYear))
            {
                if ((checkedYear == endYear && checkedMonth == endMonth && checkedDay <= endDay) || (checkedYear == endYear && checkedMonth < endMonth) || (checkedYear < endYear))
                {
                    singleExpenseData.setupExpenseDay(checkedDay);
                    singleExpenseData.setupExpenseMonth(checkedMonth);
                    singleExpenseData.setupExpenseYear(checkedYear);
                    singleExpenseData.setupExpenseAmount(stof(expenses[i].getExpenseAmount()));
                    expenseDates.push_back(singleExpenseData);
                }
            }
        }
    }
    if (expenseDates.empty())
    {
        cout << "EXPENSES:" << endl;
        cout << "---------" << endl;
        cout << "Your expenses from " << startDate << " to " << endDate << ": " << sumExpenses << " zl" << endl << endl << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget in selected period: " << sumIncomes - sumExpenses << " zl" << endl;
        system ("pause");
    }
    else
    {
        sumExpenses = expensesSorting(expenseDates);
        cout << endl;
        cout << "YOUR BUDGET:" << endl;
        cout << "------------" << endl;
        cout << "Your total budget in selected period: " << sumIncomes - sumExpenses << " zl" << endl << endl;
        system ("pause");
    }
}

float BudgetManager::incomesSorting(vector <Dates> incomeDates)
{
    float sumIncomes = 0;

    cout << "INCOMES:" << endl;
    cout << "--------" << endl;
    for (unsigned int i = 0; i < incomeDates.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < incomeDates.size(); j++)
        {
            if (incomeDates[i].getIncomeYear() > incomeDates[j].getIncomeYear())
            {
                auto temp = incomeDates[i];
                incomeDates[i] = incomeDates[j];
                incomeDates[j] = temp;
            }
            else if (incomeDates[i].getIncomeYear() == incomeDates[j].getIncomeYear() && incomeDates[i].getIncomeMonth() > incomeDates[j].getIncomeMonth())
            {
                auto temp = incomeDates[i];
                incomeDates[i] = incomeDates[j];
                incomeDates[j] = temp;
            }
            else if (incomeDates[i].getIncomeYear() == incomeDates[j].getIncomeYear() && incomeDates[i].getIncomeMonth() == incomeDates[j].getIncomeMonth() && incomeDates[i].getIncomeDay() > incomeDates[j].getIncomeDay())
            {
                auto temp = incomeDates[i];
                incomeDates[i] = incomeDates[j];
                incomeDates[j] = temp;
            }

        }
    }

    for(unsigned int i = 0; i < incomeDates.size(); i++)
    {
        if (incomeDates.empty())
        {
            sumIncomes = 0;
        }
        else
        {
            cout << incomeDates[i].getIncomeYear() <<"-"<< incomeDates[i].getIncomeMonth() << "-" << incomeDates[i].getIncomeDay() << ": " << fixed << setprecision(2) << incomeDates[i].getIncomeAmount() << " zl" << endl;
            sumIncomes += incomeDates[i].getIncomeAmount();
        }
    }
    cout << "------------------------------" << endl;
    cout << "Your incomes: " << sumIncomes << " zl" << endl << endl;
    return sumIncomes;
    Sleep(1200);
}

float BudgetManager::expensesSorting(vector <Dates> expenseDates)
{
    float sumExpenses = 0;

    cout << "EXPENSES:" << endl;
    cout << "---------" << endl;
    for (unsigned int i = 0; i < expenseDates.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < expenseDates.size(); j++)
        {
            if (expenseDates[i].getExpenseYear() > expenseDates[j].getExpenseYear())
            {
                auto temp = expenseDates[i];
                expenseDates[i] = expenseDates[j];
                expenseDates[j] = temp;
            }
            else if (expenseDates[i].getExpenseYear() == expenseDates[j].getExpenseYear() && expenseDates[i].getExpenseMonth() > expenseDates[j].getExpenseMonth())
            {
                auto temp = expenseDates[i];
                expenseDates[i] = expenseDates[j];
                expenseDates[j] = temp;
            }
            else if (expenseDates[i].getExpenseYear() == expenseDates[j].getExpenseYear() && expenseDates[i].getExpenseMonth() == expenseDates[j].getExpenseMonth() && expenseDates[i].getExpenseDay() > expenseDates[j].getExpenseDay())
            {
                auto temp = expenseDates[i];
                expenseDates[i] = expenseDates[j];
                expenseDates[j] = temp;
            }
        }
    }

    for(unsigned int i = 0; i < expenseDates.size(); i++)
    {
        if (expenseDates.empty())
        {
            sumExpenses = 0;
        }
        else
        {
            cout << expenseDates[i].getExpenseYear() <<"-"<< expenseDates[i].getExpenseMonth() << "-" << expenseDates[i].getExpenseDay() << ": " << expenseDates[i].getExpenseAmount() << " zl" << endl;
            sumExpenses += expenseDates[i].getExpenseAmount();
        }
    }
    cout << "-------------------------------" << endl;
    cout << "Your expenses: " << sumExpenses << " zl" << endl << endl;
    return sumExpenses;
    Sleep(1200);
}


