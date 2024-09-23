// BankFunctions.cpp
#include "BankFunctions.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

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

// Handle viewing accounts
void handleViewAccounts(LinkedList& accountsList) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Viewing All Accounts", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    accountsList.displayAccounts();
}

// Handle editing an account's balance
void handleEditAccount(LinkedList& accountsList) {
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
    accountsList.displayAccountsBrief();

    string accountNumber;
    double newBalance;

    cout << "\nEnter the account number to edit: ";
    cin >> accountNumber;

    Node* current = accountsList.findNode(accountNumber);
    if (current == nullptr) {
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

    current->balance = newBalance;
    cout << "\033[1;32mBalance updated successfully!\033[0m\n";
}

// Handle adding a new account
void handleAddAccount(LinkedList& accountsList) {
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
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

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

    accountsList.insertAtEnd(accountNumber, name, accountType, balance);
    cout << "\033[1;32mNew account added successfully!\033[0m\n";
}

// Handle deleting an account
void handleDeleteAccount(LinkedList& accountsList) {
    clearScreen();
    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Delete Account", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    // Display accounts for selection
    cout << "\033[1;36mAvailable Accounts:\033[0m\n";
    accountsList.displayAccountsBrief();

    string accountNumber;

    cout << "\nEnter the account number to delete: ";
    cin >> accountNumber;

    accountsList.deleteNode(accountNumber);
}

// Handle depositing money to an account
void handleDeposit(LinkedList& accountsList) {
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
    accountsList.displayAccountsBrief();

    string accountNumber;
    double amount;

    cout << "\nEnter the account number to deposit into: ";
    cin >> accountNumber;

    Node* current = accountsList.findNode(accountNumber);
    if (current == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\033[1;31mInvalid amount.\033[0m\n";
        return;
    }

    current->balance += amount;
    cout << "\033[1;32mDeposit successful!\033[0m\n";
}

// Handle withdrawing money from an account
void handleWithdraw(LinkedList& accountsList) {
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
    accountsList.displayAccountsBrief();

    string accountNumber;
    double amount;

    cout << "\nEnter the account number to withdraw from: ";
    cin >> accountNumber;

    Node* current = accountsList.findNode(accountNumber);
    if (current == nullptr) {
        cout << "\033[1;31mAccount not found.\033[0m\n";
        return;
    }

    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount <= 0 || amount > current->balance) {
        cout << "\033[1;31mInvalid amount.\033[0m\n";
        return;
    }

    current->balance -= amount;
    cout << "\033[1;32mWithdrawal successful!\033[0m\n";
}
