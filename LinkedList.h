// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class LinkedList {
public:
    Node* head;

    // Constructor initializes head to NULL
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insertAtEnd(string accountNumber, string name, string accountType, double balance);

    // Function to load linked list from a file
    void loadFromFile(const string& filename);

    // Function to convert the linked list to a text file
    void convertLinkedListToTextFile(const string& filename);

    // Function to delete a node by account number from the linked list
    void deleteNode(string accountNumber);

    // Function to find a node by account number
    Node* findNode(const string& accountNumber);

    // Function to display the account list in a formatted way
    void displayAccounts();

    // Function to display a brief list of accounts (account number and name)
    void displayAccountsBrief();
};

#endif // LINKEDLIST_H
