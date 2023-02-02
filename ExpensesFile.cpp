#include "ExpensesFile.h"


bool ExpensesFile::whetherFileIsEmpty()
{
    fstream file;
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

vector <Expenses> ExpensesFile::loadExpensesFromFile(int idLoggedUser)
{
    Expenses expense;

    fstream file(expensesFileName);

    CMarkup xml;
    xml.Load(expensesFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem(("Expense")) )
    {
        xml.FindChildElem("ExpenseID");
        expense.setupExpenseId(atoi(xml.GetChildData().c_str()));
        xml.FindChildElem("UserID");
        if (atoi(xml.GetChildData().c_str()) == idLoggedUser)
        {
            expense.setupUserId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Date");
            expense.setupExpenseDate(xml.GetChildData());
            xml.FindChildElem("Item");
            expense.setupExpenseItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            expense.setupExpenseAmount(xml.GetChildData());
            expenses.push_back(expense);
        }
    }
    return expenses;
}

int ExpensesFile::getIdOfLastExpense()
{
    Expenses expense;

    fstream file(expensesFileName);

    if (file.good() == false)
    {
        return 1;
    }

    else
    {
        CMarkup xml;
        xml.Load(expensesFileName);
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem(("Expense")) )
    {
        xml.FindChildElem("ExpenseID");
        idOfLastExpense = atoi(xml.GetChildData().c_str());
    }
        return idOfLastExpense + 1;
    }
}

void ExpensesFile::addExpenseToFile(Expenses expense)
{
    CMarkup xml;

    if (!xml.Load(expensesFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem ("ExpenseID", expense.getExpenseId());
    xml.AddElem("UserID", expense.getUserId());
    xml.AddElem("Date", expense.getExpenseDate());
    xml.AddElem("Item", expense.getExpenseItem());
    xml.AddElem("Amount", expense.getExpenseAmount());

    xml.Save(expensesFileName);
}
