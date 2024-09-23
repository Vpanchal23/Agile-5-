// BankFunctions.h
#ifndef BANKFUNCTIONS_H
#define BANKFUNCTIONS_H

#include "LinkedList.h"

// View accounts
void handleViewAccounts(LinkedList& accountsList);

// Edit account based on Account Number
void handleEditAccount(LinkedList& accountsList);

// Allows employee to add account
void handleAddAccount(LinkedList& accountsList);

// Allows employee to delete a user account
void handleDeleteAccount(LinkedList& accountsList);

// Deposit function
void handleDeposit(LinkedList& accountsList);

// Withdraw function
void handleWithdraw(LinkedList& accountsList);

#endif // BANKFUNCTIONS_H
