// BankFunctions.cpp
#include "BankFunctions.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Display the main menu for customers with numbered options
void displayCustomerMenu() {
    clearScreen();

    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Banking System Menu", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    cout << "\033[1;36m";  // Cyan text for menu
    cout << "║" << left << setw(71) << " 1. View My Accounts" << "║\n";
    cout << "║" << left << setw(71) << " 2. Open New Account" << "║\n";
    cout << "║" << left << setw(71) << " 3. Close An Account" << "║\n";
    cout << "║" << left << setw(71) << " 4. Deposit" 		  << "║\n";
    cout << "║" << left << setw(71) << " 5. Withdraw" 		  << "║\n";
    cout << "║" << left << setw(71) << " 6. Transfer" 		  << "║\n";
    cout << "║" << left << setw(71) << " 7. Exit"       	  << "║\n";
    cout << borderBottom;
    cout << "\033[1;33m";  // Yellow text for input prompt
    cout << "Choose an option (1-7): ";
    cout << "\033[0m";  // Reset text
}

// Display the main menu for employees with numbered options
void displayEmployeeMenu() {
    clearScreen();

    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Banking System Menu", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    cout << "\033[1;36m";  // Cyan text for menu
    cout << "║" << left << setw(71) << " 1. View All Accounts" 		  << "║\n";
    cout << "║" << left << setw(71) << " 2. Open New Account" 		  << "║\n";
    cout << "║" << left << setw(71) << " 3. Edit Account Information" << "║\n";
    cout << "║" << left << setw(71) << " 4. Close An Account" 		  << "║\n";
    cout << "║" << left << setw(71) << " 5. Deposit" 				  << "║\n";
    cout << "║" << left << setw(71) << " 6. Withdraw" 				  << "║\n";
    cout << "║" << left << setw(71) << " 7. Transfer" 				  << "║\n";
    cout << "║" << left << setw(71) << " 8. Exit" 			          << "║\n";
    cout << borderBottom;
    cout << "\033[1;33m";  // Yellow text for input prompt
    cout << "Choose an option (1-8): ";
    cout << "\033[0m";  // Reset text
}

// Auto-generate unique account number
string generateAccountNumber(LinkedList& accountsList) {
    string accountNumber;
    bool unique = false;
    while (!unique) {
        accountNumber = to_string(rand() % 900000 + 100000);  // Generate a 6-digit random account number
        if (accountsList.findNode(accountNumber) == nullptr) {
            unique = true;
        }
    }
    return accountNumber;
}

// Handle viewing accounts for customer
void handleViewMyAccounts(Node* current) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Viewing My Accounts", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    cout << "\033[1;35m";  // Magenta text for table headers
	cout << left << setw(15) << "Account Number"
		 << setw(20) << "Name"
		 << setw(20) << "Type"
		 << setw(15) << "Balance" << endl;
	cout << "═══════════════════════════════════════════════════════════════════════\n";
	cout << "\033[0m";  // Reset text

    // what would happen if there is no accounts?? working on it
    current->accounts.displayMyAccounts();

	cout << "\n Press enter to continue ...";
	cin.ignore(1000, '\n');
}

// Handle editing an account's balance
void handleEditAccount(LinkedList& list) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Edit Account Balance", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    list.displayAccounts();

    string accountNumber;
    double newBalance;

    cout << "\nEnter the account number to edit: ";
    cin >> accountNumber;

    Node* current = list.findNode(accountNumber);

    accountNode* current2 = nullptr;

    if (current != nullptr)
	{
	current2 = current->accounts.findNode(accountNumber);
	}
	if (current2 == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "Enter the new balance: ";
    cin >> newBalance;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\033[1;31mInvalid input for balance.\033[0m\n";
        return;
    }

    current2->balance = newBalance;
    cout << "\033[1;32mBalance updated successfully!\033[0m\n";
}

// Handle adding a new account
void handleAddAccount(LinkedList& accountsList, Node *current, short *index, string acctFile) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Add New Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    string accountNumber = generateAccountNumber(accountsList);
    string name, accountType;
    double balance;

    cout << "Generated Account Number: " << accountNumber << endl;
//    cout << "Enter Account Holder Name: ";
//    cin.ignore();
//    getline(cin, name);
    name = current->name;

    // Provide options for account type
    cout << "Select Account Type:\n";
    cout << "1. Checking\n";
    cout << "2. Savings\n";
    cout << "3. HighInterestSavings\n";
    cout << "4. CertificateOfDeposit\n";
    cout << "Enter your choice (1-4): ";
    int typeChoice;
    cin >> typeChoice;

    switch (typeChoice) {
        case 1:
            accountType = "Checking";
            break;
        case 2:
            accountType = "Savings";
            break;
        case 3:
            accountType = "HighInterestSavings";
            break;
        case 4:
            accountType = "CertificateOfDeposit";
            break;
        default:
            cout << "\033[1;31mInvalid account type selected.\033[0m\n";
            return;
    }

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if (cin.fail() || balance < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\033[1;31mInvalid input for balance.\033[0m\n";
        return;
    }

    current->accounts.insertAtEnd(name, accountNumber, accountType, balance);
    if (!(current->accountsCreated))
    {
    	current->serialNumber = generateAccountNumber(accountsList);
    }
    current->accountsCreated = true;
    accountsList.convertLinkedListToTextFile(acctFile);
    index++;
    cout << "\033[1;32mNew account added successfully!\033[0m\n";
}

// Handle deleting an account
void handleDeleteAccount(LinkedList& accountsList, Node* current, bool employee, string acctFile) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Close An Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    if (employee)
    {
    	accountsList.displayAccounts();
    }
    else
    {
    	cout << "\033[1;35m";  // Magenta text for table headers
		cout << left << setw(15) << "Account Number"
			 << setw(20) << "Name"
			 << setw(20) << "Type"
			 << setw(15) << "Balance" << endl;
		cout << "═══════════════════════════════════════════════════════════════════════\n";
		cout << "\033[0m";  // Reset text

    	current->accounts.displayMyAccounts();
    }

    string accountNumber;

    cout << "\nEnter the account number to close: ";
    cin >> accountNumber;
    cin.ignore(1000, '\n');

    if (employee)
	{
		current = accountsList.findNode(accountNumber);
	}

    current->accounts.deleteNode(accountNumber);

    accountsList.convertLinkedListToTextFile(acctFile);
}

// Handle depositing money to an account
void handleDeposit(LinkedList& accountsList, Node* current, bool employee, string acctFile) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Deposit to Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    if (employee)
	{
		accountsList.displayAccounts();
	}
	else
	{
		cout << "\033[1;35m";  // Magenta text for table headers
		cout << left << setw(15) << "Account Number"
			 << setw(20) << "Name"
			 << setw(20) << "Type"
			 << setw(15) << "Balance" << endl;
		cout << "═══════════════════════════════════════════════════════════════════════\n";
		cout << "\033[0m";  // Reset text

		current->accounts.displayMyAccounts();
	}

    string accountNumber;
    double amount;

    cout << "\nEnter the account number to deposit into: ";
    cin >> accountNumber;

    if (employee)
	{
		current = accountsList.findNode(accountNumber);
	}
    accountNode* current2 = current->accounts.findNode(accountNumber);
    if (current2 == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "Enter the amount to deposit: ";
    cin >> amount;
    cin.ignore(1000, '\n');

    if (amount <= 0) {
        cout << "\033[1;31mInvalid amount.\033[0m\n";
        return;
    }

    current2->balance += amount;

    accountsList.convertLinkedListToTextFile(acctFile);

    cout << "\033[1;32mDeposit successful!\033[0m\n";
}

// Handle withdrawing money from an account
void handleWithdraw(LinkedList& accountsList, Node* current, bool employee, string acctFile) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Withdraw from Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    if (employee)
	{
		accountsList.displayAccounts();
	}
	else
	{
		cout << "\033[1;35m";  // Magenta text for table headers
		cout << left << setw(15) << "Account Number"
			 << setw(20) << "Name"
			 << setw(20) << "Type"
			 << setw(15) << "Balance" << endl;
		cout << "═══════════════════════════════════════════════════════════════════════\n";
		cout << "\033[0m";  // Reset text

		current->accounts.displayMyAccounts();
	}

    string accountNumber;
    double amount;

    cout << "\nEnter the account number to withdraw from: ";
    cin >> accountNumber;

    if (employee)
	{
		current = accountsList.findNode(accountNumber);
	}
    accountNode* current2 = current->accounts.findNode(accountNumber);
    if (current2 == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    cin.ignore(1000, '\n');

    if (amount <= 0 || amount > current2->balance) {
        cout << "\033[1;31mInvalid amount.\033[0m\n";
        return;
    }

    current2->balance -= amount;

    accountsList.convertLinkedListToTextFile(acctFile);

    cout << "\033[1;32mWithdrawal successful!\033[0m\n";
}

void LoginSystem(LinkedList& accountsList)
{
	Node* current;
	string usrName;
	string password;
	bool invalid;

	invalid = true;
	do
	{
		clearScreen();

		cout << "login system\n";
		cout << "Enter user name()";
		getline(cin, usrName);
		cout << "Enter password";
		getline(cin, password);

		if(usrName != "exit" && usrName != "EXIT")
		{
			current = accountsList.confirmAccount(usrName, password);

			if(current != nullptr)
			{
				invalid = false;
			}
			else
			{
				cout << "Either the user name or password are incorrect.\n";
				cout << "If you do not remember your account or do not have one, type exit instead of a user name to close the program.\n";
				cout << "Please press enter to try again";
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			invalid = false;
			current = nullptr;
		}
	}while(invalid);

	return;
}

// Handle viewing accounts for customer
void handleViewAccounts(LinkedList& list) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Viewing All Accounts", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    list.displayAccounts();

	cout << "\nPress enter to continue ...";
	cin.ignore(1000, '\n');
}

void handleFundTransfers(LinkedList& accountsList, Node* current, bool employee, string acctFile) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Deposit to Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    if (employee)
	{
		accountsList.displayAccounts();
	}
	else
	{
		cout << "\033[1;35m";  // Magenta text for table headers
		cout << left << setw(15) << "Account Number"
			 << setw(20) << "Name"
			 << setw(20) << "Type"
			 << setw(15) << "Balance" << endl;
		cout << "═══════════════════════════════════════════════════════════════════════\n";
		cout << "\033[0m";  // Reset text

		current->accounts.displayMyAccounts();
	}

    string accountNumber;
    double amount;

    cout << "\nEnter the account number from which you will make the transfer: ";
    cin >> accountNumber;
    cin.ignore(1000, '\n');

    current = accountsList.findNode(accountNumber);
	accountNode* current2 = current->accounts.findNode(accountNumber);
	if (current2 == nullptr) {
		cout << "\033[1;31mAccount not found.\033[0m\n";
		return;
	}

    cout << "\nEnter the account number to which you wish to make the deposit: ";
    cin >> accountNumber;
    cin.ignore(1000, '\n');

    current = accountsList.findNode(accountNumber);
    accountNode* current3 = current->accounts.findNode(accountNumber);
    if (current3 == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "\nEnter the amount you want to transfer: ";
    cin >> amount;
    cin.ignore(1000, '\n');

    if (amount <= 0) {
        cout << "\033[1;31mInvalid amount.\033[0m\n";
        return;
    }

    current2->balance -= amount;
    current3->balance += amount;

    accountsList.convertLinkedListToTextFile(acctFile);

    cout << "\033[1;32mTransfer successful!\033[0m\n";
}

int getch() {
    int ch;
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    ch = getchar();
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return ch;
}
