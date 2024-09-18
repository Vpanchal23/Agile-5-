#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

#include "Node.h"
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

    // Function to compare original and edited lists, marking changes in an array
    void findChanges(Node* originalHead, bool changedLines[], int maxLines);

    // Function to update the .txt file with only the changed lines
    void updateFileWithChanges(const string& filename, bool changedLines[], int totalLines);

    // Function to convert the linked list to a text file
    void convertLinkedListToTextFile(const string& filename);

    // Function to delete a node by account number from the linked list
    void deleteNode(string accountNumber);
};

#endif // LINKEDLIST_H
