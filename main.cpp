#include <iostream>
#include "FinanceManager.h"

using namespace std;

int main()
{
    FinanceManager financeManager("Users.xml", "Incomes.xml", "Expenses.xml");

    int userChoice = 0, userOption = 0;

    while(true)
    {
        system("cls");
        cout << ">>>>> MAIN MENU <<<<<" << endl;
        cout << "---------------------" << endl;
        cout << "1. Sign up" << endl;
        cout << "2. Sign in" << endl;
        cout << "3. Close the program" << endl;
        cout << "---------------------" << endl;
        cout << "Your choice: ";
        cin >> userChoice;

        switch(userChoice)
        {
        case 1:
            financeManager.userRegistration();
            break;
        case 2:
            financeManager.userLogging();
            while(true)
                {
                    system("cls");
                    cout << ">>>>> USER MENU <<<<<" << endl;
                    cout << "---------------------" << endl;
                    cout << "1. Add income" << endl;
                    cout << "2. Add expense" << endl;
                    cout << "3. Balance of this month" << endl;
                    cout << "4. Balance of previous month" << endl;
                    cout << "5. Balance of selected period" << endl;
                    cout << "---------------------" << endl;
                    cout << "6. Change password" << endl;
                    cout << "7. Log out" << endl;
                    cout << "---------------------" << endl;
                    cout << "Your choice: ";
                    cin >> userOption;

                    switch(userOption)
                    {
                    case 1:
                        financeManager.addIncome();
                        break;
                    case 2:
                        financeManager.addExpense();
                        break;
                    case 3:
                        financeManager.balanceOfThisMonth();
                        break;
                    case 4:
                        financeManager.balanceOfPreviousMonth();
                        break;
                    case 5:
                        financeManager.balanceOfSelectedPeriod();
                        break;
                    case 6:
                        financeManager.changePassword();
                        break;
                    case 7:
                        return main();
                    default:
                        cout << endl;
                        cout << "Incorrect choice. Try once again!" << endl;
                        Sleep (1500);
                        break;
                    }
                }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << endl;
            cout << "Incorrect choice. Try once again!" << endl;
            Sleep (1500);
            break;
        }
    }
    return 0;
}
