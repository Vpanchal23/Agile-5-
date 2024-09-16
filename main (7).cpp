#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cstdlib>   // for random account number generation
#include <ctime>     // for seeding the random number generator

using namespace std;

// Generate a random account number
string generateAccountNumber() {
    srand(time(0)); // Seed random number generator
    return to_string(rand() % 100000 + 10000); // Generate random 5-digit account number
}

// Display account type options and get user selection
string selectAccountType() {
    int choice;
    cout << "Select account type:\n";
    cout << "1. Savings\n";
    cout << "2. Checking\n";
    cout << "3. Certificate of Deposit (CD)\n";
    cout << "Select an option (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: return "Savings";
        case 2: return "Checking";
        case 3: return "Certificate of Deposit";
        default: cout << "Invalid choice. Defaulting to Savings." << endl; return "Savings";
    }
}

void displayMenu() {
    cout << "\nBanking System Menu:" << endl;
    cout << "1. View all accounts" << endl;
    cout << "2. Edit account balance" << endl;
    cout << "3. Add new account" << endl;
    cout << "4. Delete account" << endl;
    cout << "5. Exit Program (Save Changes)" << endl;
    cout << "Select an option (1-5): ";
}

void handleViewAccounts(LinkedList& accountsList) {
    Node* current = accountsList.head;
    if (!current) {
        cout << "\nNo accounts available." << endl;
        return;
    }
    cout << "\nCurrent Accounts:" << endl;
    while (current) {
        cout << "Account Number: " << current->accountNumber
             << " | Name: " << current->name
             << " | Account Type: " << current->accountType
             << " | Balance: $" << current->balance << endl;
        current = current->next;
    }
}

void handleEditAccount(LinkedList& accountsList) {
    string accountNumber;
    double newBalance;

    cout << "Enter the account number to edit: ";
    cin >> accountNumber;

    Node* current = accountsList.head;
    while (current) {
        if (current->accountNumber == accountNumber) {
            cout << "Current balance: $" << current->balance << endl;
            cout << "Enter new balance: ";
            cin >> newBalance;
            current->balance = newBalance;
            cout << "Balance updated successfully." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Account not found." << endl;
}

void handleAddAccount(LinkedList& accountsList) {
    string accountNumber = generateAccountNumber();
    string name, accountType;
    double balance;

    cout << "Enter name: ";
    cin.ignore();  // Ignore leftover newline from previous input
    getline(cin, name);
    accountType = selectAccountType();
    cout << "Enter initial balance: ";
    cin >> balance;

    accountsList.insertAtEnd(accountNumber, name, accountType, balance);
    cout << "New account added successfully." << endl;
}

void handleDeleteAccount(LinkedList& accountsList) {
    string accountNumber;

    cout << "Enter the account number to delete: ";
    cin >> accountNumber;

    accountsList.deleteNode(accountNumber);
}

int main() {
    LinkedList employeeList;  // This will be the employee's working list
    const string filename = "accounts.txt";  // Name of the file where data is stored

    // Load accounts into the employee list from accounts.txt
    employeeList.loadFromFile(filename);  // Load data from the .txt file

    int choice = 0;
    bool exitProgram = false;  // Flag to control when the program should exit

    while (!exitProgram) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                handleViewAccounts(employeeList);
                break;
            case 2:
                handleEditAccount(employeeList);
                break;
            case 3:
                handleAddAccount(employeeList);
                break;
            case 4:
                handleDeleteAccount(employeeList);
                break;
            case 5:
                cout << "Would you like to exit and save changes? (y/n): ";
                char exitChoice;
                cin >> exitChoice;
                if (exitChoice == 'y' || exitChoice == 'Y') {
                    // Save the entire list back to the accounts.txt file (overwrite)
                    employeeList.convertLinkedListToTextFile(filename);
                    cout << "Changes saved. Exiting program..." << endl;
                    exitProgram = true;  // Exit the loop
                }
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}
