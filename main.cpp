<<<<<<< HEAD
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
=======
#include "Bank.h"
#include "Utils.h"
#include <iostream>
#include <ctime>

int main() {
    Bank bank;
    std::string filename = "accounts.txt";  // File where data is stored
    ClientNode* current;

    // Load data from accounts.txt
    if (!bank.loadFromFile(filename)) {
        std::cerr << "\033[1;31mFailed to load data from file.\033[0m\n";
    }

    // Initialize the account number generator
    bank.initializeAccountNumberGenerator();

    bool exitProgram = false;
    bool invalid;

    while (!exitProgram) {
        current = bank.LoginSystem();

        if(current)
        {
			switch (current->role) {
				case 0:
				{
					bank.clientInterface(current, filename);
				}
				break;
				default:
					bank.employeeInterface(current, filename);
			}
        }
        else
        {
        	std::cout << "\033[1;31mInvalid username or password.\033[0m\n";
			std::cout << "Would you like to try again? (y/n): ";
			char choice;
			do
			{
				invalid = true;
				std::cin >> choice;
				std::cin.ignore(1000, '\n');

				choice = tolower(choice);
				switch(choice)
				{
					case 'y':
						invalid = false;
						break;
					case 'n':
						exitProgram = true;
						invalid = false;
						break;
					default:
						std::cout << "\033[1;31mInvalid choice. Please try again: \033[0m";
				}
			}while(invalid);
        }

        // Add 4 empty lines between menu functions
        std::cout << "\n\n\n\n";
    }

    return 0;
}
>>>>>>> 9cbd8c0 (project)
