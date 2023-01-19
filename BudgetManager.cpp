#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Incomes income = enterNewIncomeDetails();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << endl << "Income added successfully" << endl << endl;
    system ("pause");
}

Incomes BudgetManager::enterNewIncomeDetails()
{
    Incomes income;

    int incomeChoice = 0;
    int year = 0, month = 0, day = 0;
    constexpr char DELIMITER = '-';

    while(true)
    {
        system("cls");
        cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
        cout << "-----------------------------" << endl;
        cin.sync();
        cout << "1. Today" << endl;
        cout << "2. Specific date" << endl << endl;
        cout << "Please enter "1" or "2" depends on which date of income you want to add: ";
        cin >> incomeChoice;

        switch (incomeChoice)
        {
        case 1:
            system("cls");
            cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
            cout << "-----------------------------" << endl;
            income.setupIncomeId(getIdOfNewIncome());
            income.setupUserId(ID_LOGGED_USER);
            incomeDate = SupportiveMethods::checkCurrentDate();
            income.setupIncomeDate(incomeDate);
            cout << "What does income relate to? :";
            getline(cin, incomeItem);
            income.setupIncomeItem(incomeItem);
            cout << endl << endl;
            cout << "What is amount of this income? :";
            cin >> incomeAmount;
            income.setupAmount(incomeAmount);
            return income;
        case 2:
            system("cls");
            cout << ">>>>>>>> INCOME MENU <<<<<<<<" << endl;
            cout << "-----------------------------" << endl;
            cout << "Enter your date in format: YYYY-MM-DD: ";
            cin >> incomeDate;
            cout << endl;

            if (incomeDate.length() != 10)
            {
                cout << "Incorrect date format. Please try again." << endl;
                system ("pause");
                system ("cls");
                return enterNewIncomeDetails();
            }
            else
            {
                istringstream stm(date) ;
                char delim;
                stm >> year >> delim ;
                stm >> month >> delim ;
                stm >> day;

                if (SupportiveMethods::checkTheDate(year, month, day) == true)
                {
                    income.setupIncomeId(getIdOfNewIncome());
                    income.setupUserId(ID_LOGGED_USER);
                    income.setupIncomeDate(incomeDate);
                    cout << "Your date saved correctly" << endl;
                    Sleep (2500);
                    cout << "What does income relate to? :";
                    getline(cin, incomeItem);
                    income.setupIncomeItem(incomeItem);
                    cout << endl << endl;
                    cout << "What is amount of this income? :";
                    cin >> incomeAmount;
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

int BudgetManager::getIdOfNewIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
