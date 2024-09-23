#ifndef BANKFUNCTIONS_H
#define BANKFUNCTIONS_H

#include "LinkedList.h"
#include <string>

// Function to auto-generate a unique account number
std::string generateAccountNumber(LinkedList& accountsList);

// Function to handle viewing all accounts
void handleViewAccounts(LinkedList& accountsList);

// Function to handle editing an account's balance
void handleEditAccount(LinkedList& accountsList);

// Function to handle adding a new account
void handleAddAccount(LinkedList& accountsList);

// Function to handle deleting an account
void handleDeleteAccount(LinkedList& accountsList);

// Function to handle depositing money to an account
void handleDeposit(LinkedList& accountsList);

// Function to handle withdrawing money from an account
void handleWithdraw(LinkedList& accountsList);

#endif // BANKFUNCTIONS_H
