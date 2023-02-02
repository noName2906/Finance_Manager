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

vector <Incomes> IncomesFile::loadIncomesFromFile(int idLoggedUser)
{
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
        xml.FindChildElem("UserID");
        if (atoi(xml.GetChildData().c_str()) == idLoggedUser)
        {
            income.setupUserId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Date");
            income.setupIncomeDate(xml.GetChildData());
            xml.FindChildElem("Item");
            income.setupIncomeItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            income.setupIncomeAmount(xml.GetChildData());
            incomes.push_back(income);
        }
    }
    return incomes;
}

int IncomesFile::getIdOfLastIncome()
{
    Incomes income;

    fstream file(incomesFileName);

    if (file.good() == false)
    {
        return 1;
    }

    else
    {
        CMarkup xml;
        xml.Load(incomesFileName);
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem(("Income")) )
    {
        xml.FindChildElem("IncomeID");
        idOfLastIncome = atoi(xml.GetChildData().c_str());
    }
        return idOfLastIncome + 1;
    }
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
