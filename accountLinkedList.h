// accountLinkedList.h
#ifndef ACCOUNTLINKEDLIST_H
#define ACCOUNTLINKEDLIST_H

#include "accountNode.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class accountLinkedList {
public:
	accountNode* head;

    // Constructor initializes head to NULL
    accountLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insertAtEnd(string name, string accountNumber, string accountType, double balance);

    // Function to load linked list from a file
    void loadFromFile(const string& filename);

    // Function to convert the linked list to a text file
    void convertLinkedListToTextFile(const string& filename);

    // Function to delete a node by account number from the linked list
    void deleteNode(string accountNumber);

    // Function to find a node by account number
    accountNode* findNode(const string accountNumber);

    // Function to display the account list in a formatted way
    void displayMyAccounts();

    // Function to display a brief list of accounts (account number and name)
//    void displayAnAccount();

//    accountNode* confirmAccount(string name,string password);
};

#endif // ACCOUNTLINKEDLIST_H
