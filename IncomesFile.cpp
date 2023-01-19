#include "IncomesFile.h"


bool IncomesFile::whetherFileIsEmpty()
{
    fstream file;
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

/*User UsersFile::getUserData()
{
    User user;
    //do dokonczenia
} */

vector <Incomes> IncomesFile::loadIncomesFromFile()
{
    User user;
    Incomes income;

   fstream file(incomesFileName);

    CMarkup xml;
    xml.Load(incomesFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem(("Income")) )
    {
        xml.FindChildElem("IncomeID");
        income.setupIncomeId(atoi(xml.GetChildData().c_str()));
        cout << "Income ID : " << income.getIncomeId() << endl;
        xml.FindChildElem("UserID");
        if (atoi(xml.GetChildData().c_str()) == ID_LOGGED_USER)
        {
            income.setupUserId(atoi(xml.GetChildData().c_str()));
            cout << "User ID : " << income.getUserId() << endl;
            xml.FindChildElem("Date");
            income.setupIncomeDate(xml.GetChildData());
            cout << "Date : " << income.getIncomeDate() << endl;
            xml.FindChildElem("Item");
            income.setupIncomeItem(xml.GetChildData());
            cout << "Item : " << income.getIncomeItem() << endl;
            xml.FindChildElem("Amount");
            income.setupIncomeAmount(stof(xml.GetChildData()));
            cout << "Amount : " << income.getIncomeAmount() << endl;
            incomes.push_back(income);
            return incomes;
        }
    }
}

int IncomesFile::getIdOfNewIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void IncomesFile::addIncomeToFile(Incomes income)
{
    CMarkup xml;

    if (!xml.Load(incomesFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    else
    {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem ("IncomeID", income.getIncomeId());
    xml.AddElem("UserID", income.getUserId());
    xml.AddElem("Date", income.getIncomeDate());
    xml.AddElem("Item", income.getIncomeItem());
    xml.AddElem("Amount", income.getIncomeAmount());

    xml.Save(incomesFileName);
}
