#include "Bank.h"

void editAnAccount(LinkedList& list)
{

	Node *current;
	string searchItem;
	short userChoice;
	string name;
	double balance;
	bool invalid;

	invalid = true;
	cout << "\033[H\033[2J" << endl;

	cout << "\t ************************************************************************ \n"
		 << "\t *                       SEARCH FOR AN ACCOUNT                          * \n"
		 << "\t ************************************************************************ \n"
		 << "\t *\n"
		 << "\t *\n"
		 << "\t    Enter the account number: ";

	getline(cin, searchItem);
	current = list.head;
	while (current)
	{
		if (current->accountNumber == searchItem)
		{
			name = current->name;
			balance = current->balance;

			do
			{
				invalid = true;
				cout << "\033[H\033[2J" << endl;

				cout << "\t ************************************************************************ \n"
					 << "\t *                              EDIT ACCOUNT                            * \n"
					 << "\t ************************************************************************ \n"
					 << "\t *\n"
					  << "\t *\n"
					<< "\t *  1. Change Owner Name        --> " << name       << endl
//					<< "\t *  2. Change Account Number    --> " << acctNumber << endl
					<< "\t *  2. Change Account Balance   --> " << balance    << endl
					  << "\t *  3. Save Changes.\n"
					  << "\t *  4. Exit.\n"
					  << "\t *\n"
					  << "\t ************************************************************************ \n"
					<< "\t  <Choice>: ";

				if (!(cin >> userChoice))
				{
					cin.clear();
					userChoice = -1;
				}
				cin.ignore(1000, '\n');

				switch (userChoice)
				{
					case 1:
							cout << "\n\t Owner's Name: ";
							getline(cin, name);
							break;
//					case 2:
//							do
//							{
//								cout << "\n\t Account Number: ";
//								if (!(cin  >> acctNumber))
//								{
//									cin.clear();
//									cout << "\n\t Invalid input - Please enter a number\n";
//								}
//								else if (acctNumber < 0)
//								{
//									cout << "\n\t Invalid input - Please try again\n";
//								}
//								else
//								{
//									invalid = false;
//								}
//								cin.ignore(1000, '\n');
//							}while (invalid);
//							break;
					case 2:
							do
							{
								cout << "\n\t Account Balance: ";
								if (!(cin  >> balance))
								{
									cin.clear();
									cout << "\n\t Invalid input - Please enter a number\n";
								}
								else if (balance < 0)
								{
									cout << "\n\t Invalid input - Please enter a number greater or equal to 0\n";
								}
								else
								{
									invalid = false;
								}
								cin.ignore(1000, '\n');
							}while (invalid);
							break;
					case 3:
							current->name = name;
//							current->data->setAccountNumber(acctNumber);
							current->balance = balance;
							break;
					case 4:
							break;
					default:
							cout << "\n\t Please enter a number between 1 - 4\n"
								  << "\n\t Press enter to try again";
							cin.ignore(1000, '\n');
				}

			}while (userChoice != 3 &&
					  userChoice != 4);

			return;
		}
	        current = current->next;
	}
	    cout << "Account not found." << endl;

}

