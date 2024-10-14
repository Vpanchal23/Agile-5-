#ifndef BANKFUNCTIONS_H
#define BANKFUNCTIONS_H

#include "LinkedList.h"
#include <string>

// Display the main menu for customers with numbered options
void displayCustomerMenu();

// Display the main menu for employees with numbered options
void displayEmployeeMenu();

// Function to auto-generate a unique account number
std::string generateAccountNumber(LinkedList& accountsList);

// Function to handle viewing all accounts from one user
void handleViewMyAccounts(Node* current);

// Function to handle editing an account's balance
void handleEditAccount(LinkedList& accountsList);

// Function to handle adding a new account
void handleAddAccount(LinkedList& accountsList, Node *current, short *index, string acctFile);

// Function to handle deleting an account
void handleDeleteAccount(LinkedList& accountsList, Node* current, bool employee, string acctFile);

// Function to handle depositing money to an account
void handleDeposit(LinkedList& accountsList, Node* current, bool employee, string acctFile);

// Function to handle withdrawing money from an account
void handleWithdraw(LinkedList& accountsList, Node* current, bool employee, string acctFile);

// Function to handle viewing all accounts
void handleViewAccounts(LinkedList& list);

// Function to handle transfers between bank accounts
void handleFundTransfers(LinkedList& accountsList, Node* current, bool employee, string acctFile);

#endif // BANKFUNCTIONS_H
