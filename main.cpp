// main.cpp
#include "LinkedList.h"
#include "BankFunctions.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	string arr[10];
	short acctNumDataBase;
	LinkedList accountsList;  // Employee's working list
	const string filename = "accounts.txt";  // File where data is stored

	acctNumDataBase = 0;
	// Load accounts from accounts.txt
	accountsList.loadFromFile(filename, arr, &acctNumDataBase);

	// Seed the random number generator once
	srand(static_cast<unsigned int>(time(nullptr)));

	Node* current;
	string name;
	string psswrd;
	bool invalid;
	char choice;
	int userChoice;

	do
	{
		invalid = true;
		cout << "LOGIN\n";
		cout << "User name: ";
		getline(cin, name);

		cout << "Password: ";
		getline(cin, psswrd);

		current = accountsList.confirmAccount(name, psswrd);

		if(current != nullptr)
		{
			invalid = false;
		}
		else
		{
			do
			{
				cout << "\nIncorrect username or password"
					 << "\nWould you like to try again (type N to exit)? ";
				cin.get(choice);
				cin.ignore(1000, '\n');

				choice = tolower(choice);

				switch(choice)
				{
					case 'y':
						break;
					case 'n':
						invalid = false;
						break;
				}
			}while(choice != 'y' &&
				   choice != 'n');
		}
	}while(invalid);

	if(current != nullptr)
	{
		switch((current->employee))
		{
			case 0:
				invalid = true;
				do
				{
					displayCustomerMenu();
					cin >> userChoice;

					if (cin.fail() || userChoice < 1 || userChoice > 7)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[1;31mInvalid input. Please enter a number between 1 and 7.\033[0m\n";
						cout << "\n\033[1;33mPress Enter to return to the menu...\033[0m";
						cin.ignore(1000, '\n');
					}

						switch (userChoice)
						{
							case 1:
								handleViewMyAccounts(current);
								break;
							case 2:
								handleAddAccount(accountsList, current, &acctNumDataBase, filename);
								break;
							case 3:
								handleDeleteAccount(accountsList, current, current->employee, filename);
								break;
							case 4:
								handleDeposit(accountsList, current, current->employee, filename);
								break;
							case 5:
								handleWithdraw(accountsList, current, current->employee, filename);
								break;
							case 6:
								handleFundTransfers(accountsList, current, current->employee, filename);
								break;
							case 7:
								clearScreen();
								cout << "\033[1;32mExiting program ...\033[0m\n";
						//		accountsList.convertLinkedListToTextFile(filename);
								invalid = false;
								break;
						}

				}while(invalid);
				break;
			default:
				invalid = true;
				do
				{
					displayEmployeeMenu();
					cin >> userChoice;

					if (cin.fail() || userChoice < 1 || userChoice > 8)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[1;31mInvalid input. Please enter a number between 1 and 8.\033[0m\n";
						cout << "\n\033[1;33mPress Enter to return to the menu...\033[0m";
						cin.ignore(1000, '\n');
					}
						switch (userChoice)
						{
							case 1:
								handleViewAccounts(accountsList);
								break;
							case 2:
							{
								clearScreen();
								string borderTop1 = "╔═══════════════════════════════════════════════════════════════════════╗\n";
								string borderBottom1 = "╚═══════════════════════════════════════════════════════════════════════╝\n";

								cout << "\033[1;34m";  // Bold Blue text
								cout << borderTop1;
								cout << "║" << centerText("Choose Customer Account", 71) << "║\n";
								cout << borderBottom1;
								cout << "\033[0m";  // Reset text

								// Display accounts for selection
								cout << "\033[1;36mCustomer Accounts:\033[0m\n";
								accountsList.displayLoginAccounts();

								string numberToFind;

								cout << "\nEnter the login account ID number to which you want to add a bank account: ";
								cin >> numberToFind;
								cin.ignore(1000, '\n');

								Node* current2 = accountsList.findLoginAccount(numberToFind);

								handleAddAccount(accountsList, current2, &acctNumDataBase, filename);
								break;
							}
							case 3:
								handleEditAccount(accountsList);
								break;
							case 4:
								handleDeleteAccount(accountsList, current, current->employee, filename);
								break;
							case 5:
								handleDeposit(accountsList, current, current->employee, filename);
								break;
							case 6:
								handleWithdraw(accountsList, current, current->employee, filename);
								break;
							case 7:
								handleFundTransfers(accountsList, current, current->employee, filename);
								break;
							case 8:
								clearScreen();
								cout << "\033[1;32mExiting program ...\033[0m\n";
						//		accountsList.convertLinkedListToTextFile(filename);
								invalid = false;
								break;
						}

				}while(invalid);
		}
	}

    return 0;
}
