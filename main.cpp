// main.cpp
#include "LinkedList.h"
#include "BankFunctions.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// Display the main menu with numbered options
void displayMenu() {
    clearScreen();

    string borderTop = "╔═══════════════════════════════════════════════════════════════════════╗\n";
    string borderBottom = "╚═══════════════════════════════════════════════════════════════════════╝\n";

    cout << "\033[1;34m";  // Bold Blue text
    cout << borderTop;
    cout << "║" << centerText("Banking System Menu", 71) << "║\n";
    cout << borderBottom;
    cout << "\033[0m";  // Reset text

    cout << "\033[1;36m";  // Cyan text for menu
    cout << "║" << left << setw(71) << " 1. View Accounts" << "║\n";
    cout << "║" << left << setw(71) << " 2. Add New Account" << "║\n";
    cout << "║" << left << setw(71) << " 3. Edit Account Balance" << "║\n";
    cout << "║" << left << setw(71) << " 4. Delete Account" << "║\n";
    cout << "║" << left << setw(71) << " 5. Deposit" << "║\n";
    cout << "║" << left << setw(71) << " 6. Withdraw" << "║\n";
    cout << "║" << left << setw(71) << " 7. Exit Program" << "║\n";
    cout << borderBottom;
    cout << "\033[1;33m";  // Yellow text for input prompt
    cout << "Choose an option (1-7): ";
    cout << "\033[0m";  // Reset text
}

int main() {
    LinkedList employeeList;  // Employee's working list
    const string filename = "accounts.txt";  // File where data is stored

    // Load accounts from accounts.txt
    employeeList.loadFromFile(filename);

    int choice = 0;
    bool exitProgram = false;

    // Seed the random number generator once
    srand(static_cast<unsigned int>(time(nullptr)));

    while (!exitProgram) {
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 7) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[1;31mInvalid input. Please enter a number between 1 and 7.\033[0m\n";
            cout << "\n\033[1;33mPress Enter to return to the menu...\033[0m";
            cin.ignore();
            cin.get();
            continue;
        }

        switch (choice) {
            case 1:
                handleViewAccounts(employeeList);
                break;
            case 2:
                handleAddAccount(employeeList);
                break;
            case 3:
                handleEditAccount(employeeList);
                break;
            case 4:
                handleDeleteAccount(employeeList);
                break;
            case 5:
                handleDeposit(employeeList);
                break;
            case 6:
                handleWithdraw(employeeList);
                break;
            case 7:
                clearScreen();
                cout << "\033[1;32mExiting program and saving changes...\033[0m\n";
                employeeList.convertLinkedListToTextFile(filename);
                exitProgram = true;
                break;
        }

        if (!exitProgram) {
            cout << "\n\033[1;33mPress Enter to return to the menu...\033[0m";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
