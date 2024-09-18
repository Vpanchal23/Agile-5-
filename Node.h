#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// Structure for a node in the linked list
struct Node {
    string accountNumber;   // Account Number
    string name;            // Account Holder Name
    string accountType;     // Type of account (e.g., "Savings", "Checking")
    double balance;         // Balance in the account
    Node* next;             // Pointer to the next node
};

#endif //NODE_H
