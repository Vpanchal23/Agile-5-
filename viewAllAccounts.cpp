#include "Bank.h"

void viewAllAccounts(LinkedList& list)
{
	Node* current;

	current = list.head;
	    if (!current)
	    {
	        cout << "\nNo accounts available." << endl;
	        return;
	    }
	    cout << "\t ************************************************************************ \n"
			 << "\t *                          CURRENT ACCOUNTS                            * \n"
			 << "\t ************************************************************************ \n"
			 << "\t *\n"
			 << "\t *\n";
	    while (current)
	    {
	        cout << "\t * Account Number: " << current->accountNumber
	             << " | Name: " << current->name
	             << " | Account Type: " << current->accountType
	             << " | Balance: $" << current->balance << endl;
	        cout << "\t *\n";

	        current = current->next;
	    }
	    cout << "\t *\n"
	    	 << "\t ************************************************************************ \n";
	}
