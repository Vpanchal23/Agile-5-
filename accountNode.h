// accountNode.h
#ifndef ACCOUNTNODE_H
#define ACCOUNTNODE_H

#include <string>
using namespace std;

// Structure for a node in the linked list
struct accountNode {
	string name;            // Account Holder Name
    string accountNumber;
    string accountType;     // Type of account (e.g., "Savings", "Checking")
    double balance;         // Balance in the account
    accountNode* next;      // Pointer to the next node
};

#endif // ACCOUNTNODE_H
