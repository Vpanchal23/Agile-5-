// Node.h
#ifndef NODE_H
#define NODE_H

#include "accountLinkedList.h"
#include <string>
using namespace std;

// Structure for a node in the linked list
struct Node {
	string name;            // Account Holder Name
    string serialNumber;
//    string accountType;     // Type of account (e.g., "Savings", "Checking")
//    double balance;         // Balance in the account
    string password;
    bool employee;
    bool accountsCreated;
    accountLinkedList accounts;
    Node* next;             // Pointer to the next node
};

#endif // NODE_H
