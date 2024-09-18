#include <fstream>
#include <iostream>
#include "LinkedList.h"

using namespace std;

// Insert a node at the end of the list
void LinkedList::insertAtEnd(string accountNumber, string name, string accountType, double balance) {
    Node* newNode = new Node();
    newNode->accountNumber = accountNumber;
    newNode->name = name;
    newNode->accountType = accountType;
    newNode->balance = balance;
    newNode->next = nullptr;

    // If the list is empty, update the head to the new node
    if (!head) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Update the last node's next to the new node
    temp->next = newNode;
}

// Load the linked list from a file
void LinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string accountNumber, name, accountType;
    double balance;

    // Assuming each line has accountNumber, name, accountType, balance separated by spaces or tabs
    while (file >> accountNumber >> name >> accountType >> balance) {
        insertAtEnd(accountNumber, name, accountType, balance);
    }

    file.close();
}

// Compare original and edited lists, marking changes in an array
void LinkedList::findChanges(Node* originalHead, bool changedLines[], int maxLines) {
    Node* currentOriginal = originalHead;
    Node* currentEdited = head;
    int lineNumber = 0;

    // Traverse both lists and mark changes in the array
    while (currentOriginal != nullptr && currentEdited != nullptr) {
        if (currentOriginal->accountNumber != currentEdited->accountNumber ||
            currentOriginal->name != currentEdited->name ||
            currentOriginal->accountType != currentEdited->accountType ||
            currentOriginal->balance != currentEdited->balance) {
            changedLines[lineNumber] = true;  // Mark the line as changed
        } else {
            changedLines[lineNumber] = false;  // No change
        }
        currentOriginal = currentOriginal->next;
        currentEdited = currentEdited->next;
        lineNumber++;
    }
}

// Update the file with only the changed lines
void LinkedList::updateFileWithChanges(const string& filename, bool changedLines[], int totalLines) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string fileLines[100];  // Assume the file has no more than 100 lines
    int lineCount = 0;
    string line;

    // Load the file into an array of strings
    while (getline(file, line)) {
        fileLines[lineCount] = line;
        lineCount++;
    }
    file.close();

    // Update the changed lines
    Node* temp = head;
    for (int i = 0; i < lineCount; i++) {
        if (changedLines[i]) {
            fileLines[i] = temp->accountNumber + " " + temp->name + " " + temp->accountType + " " + to_string(temp->balance);
        }
        temp = temp->next;
    }

    // Write the updated content back to the file
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        outfile << fileLines[i] << endl;
    }
    outfile.close();
}

// Convert the linked list to a text file
void LinkedList::convertLinkedListToTextFile(const string& filename) {
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        outfile << current->accountNumber << " " << current->name << " " << current->accountType << " " << current->balance << endl;
        current = current->next;
    }

    outfile.close();
}

// Delete a node by accountNumber from the linked list
void LinkedList::deleteNode(string accountNumber) {
    if (!head) {  // Check if the list is empty
        cout << "List is empty." << endl;
        return;
    }

    // If the head node itself holds the accountNumber to be deleted
    if (head->accountNumber == accountNumber) {
        Node* temp = head;  // Save the current head
        head = head->next;  // Move the head to the next node
        delete temp;  // Free the old head
        cout << "Node with account number " << accountNumber << " deleted." << endl;
        return;
    }

    // Search for the node to be deleted and keep track of the previous node
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->accountNumber != accountNumber) {
        previous = current;
        current = current->next;
    }

    // If the accountNumber was not found in the list
    if (current == nullptr) {
        cout << "Node with account number " << accountNumber << " not found." << endl;
        return;
    }

    // Unlink the node from the linked list
    previous->next = current->next;
    delete current;  // Free the memory
    cout << "Node with account number " << accountNumber << " deleted." << endl;
}
