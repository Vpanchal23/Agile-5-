#include <iostream>
#include <iomanip>

#include "nodeType.h"

using namespace std;

int main()
{
	nodeType* first;
	nodeType* last;

	InitializeList(&first, &last);

	InsertItemInList(&first, &last, "Bill", 10200, 2500, 1);
	InsertItemInList(&first, &last, "Susan", 10210, 2000, 2);
	InsertItemInList(&first, &last, "John", 20100, 3500, 5);
	InsertItemInList(&first, &last, "Ravi", 30100, 1800, 4);
	InsertItemInList(&first, &last, "Sheila", 20200, 6000, 6);
   InsertItemInList(&first, &last, "Hamid", 51001, 18000, 3, 0.075, 18);

    cout << "New January:\n-------------" << endl;
    for (int i = 0; i < bankAccountType::ACCOUNT_INSTANCES; i++)
    {
        GetNodeByIndex(first, i)->data->createMonthlyStatement();
        GetNodeByIndex(first, i)->data->print();
        cout << endl;
    }

    cout << "\nNew February:\n-------------" << endl;
    for (int i = 0; i < bankAccountType::ACCOUNT_INSTANCES; i++)
    {
        GetNodeByIndex(first, i)->data->createMonthlyStatement();
        GetNodeByIndex(first, i)->data->print();
        cout << endl;
    }

    for (int i = 0; i < bankAccountType::ACCOUNT_INSTANCES; i++)
    {
         GetNodeByIndex(first, i)->data->withdraw(500);
    }

    cout << "\nNew March:\n-------------" << endl;
    for (int i = 0; i < bankAccountType::ACCOUNT_INSTANCES; i++)
    {
        GetNodeByIndex(first, i)->data->createMonthlyStatement();
        GetNodeByIndex(first, i)->data->print();
        cout << endl;
    }

	 DeleteList(first, last);

    return 0;
}
