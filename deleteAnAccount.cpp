#include "Bank.h"

void deleteAnAccount(LinkedList& list)
{

	Node *current;
	string searchItem;
	string name;
	char choice;

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

				cout << "\n\t ";
				cout << "\n\t Account Number: " << current->accountNumber
				             << " | Name: " << current->name
				             << " | Account Type: " << current->accountType
				             << " | Balance: $" << current->balance << endl;

				cout << "\n\t Would you like to delete this account?(Y/N): ";

				do
				{
					cin.get(choice);
					cin.ignore(1000, '\n');

					choice = tolower(choice);

					switch (choice)
					{
						case 'y':
								cout << "\n\t ";
								list.deleteNode(searchItem);
								cout << "\n\t Account deleted\n"
									  << "\n\t Press enter to continue";
								cin.ignore(1000, '\n');
								break;
						case 'n':
								break;
						default:
								cout << "\n\t Please enter Y or N: ";
					}
				}while (choice != 'y' &&
						  choice != 'n');
				break;
			}
			current = current->next;
		}

}
