// accountLinkedList.cpp
#include "accountLinkedList.h"
#include <iomanip>

using namespace std;

// Insert a node at the end of the list
void accountLinkedList::insertAtEnd(string name, string accountNumber, string accountType, double balance) {
	accountNode* newNode = new accountNode();
    newNode->name = name;
    newNode->accountNumber = accountNumber;
    newNode->accountType = accountType;
    newNode->balance = balance;
    newNode->next = nullptr;

    // If the list is empty, update the head to the new node
    if (!head) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    accountNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Update the last node's next to the new node
    temp->next = newNode;
}

// Load the linked list from a file
void accountLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string name, accountNumber, accountType;
    double balance;

    // Manually process each line of the file
    while (file >> name >> accountNumber >> accountType >> balance) {
        insertAtEnd(name, accountNumber, accountType, balance);
    }

    file.close();
}

// Convert the linked list to a text file
void accountLinkedList::convertLinkedListToTextFile(const string& filename) {
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    accountNode* current = head;
    while (current != nullptr) {
        outfile << current->name << " " << current->accountNumber << " "
				<< current->accountType << " " << current->balance << endl;
        current = current->next;
    }

    outfile.close();
}

// Delete a node by account number from the linked list
void accountLinkedList::deleteNode(string accountNumber) {
    if (!head) {  // Check if the list is empty
        cout << "\033[1;31mNo accounts available.\033[0m\n";  // Red text
        return;
    }

    // If the head node itself holds the accountNumber to be deleted
    if (head->accountNumber == accountNumber) {
        accountNode* temp = head;  // Save the current head
        head = head->next;  // Move the head to the next node
        delete temp;        // Free the old head
        cout << "\033[1;32mAccount " << accountNumber << " deleted successfully.\033[0m\n";
        return;
    }

    // Search for the node to be deleted and keep track of the previous node
    accountNode* current = head;
    accountNode* previous = nullptr;
    while (current != nullptr && current->accountNumber != accountNumber) {
        previous = current;
        current = current->next;
    }

    // If the accountNumber was not found in the list
    if (current == nullptr) {
        cout << "\033[1;31mAccount " << accountNumber << " not found.\033[0m\n";
        return;
    }

    // Unlink the node from the linked list
    previous->next = current->next;
    delete current;  // Free the memory
    cout << "\033[1;32mAccount " << accountNumber << " deleted successfully.\033[0m\n";
}

// Find a node by account number
accountNode* accountLinkedList::findNode(const string accountNumber) {
    accountNode* current = head;
    while (current != nullptr) {
        if (current->accountNumber == accountNumber) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Return null if account is not found
}

// Display accounts in a formatted way
void accountLinkedList::displayMyAccounts() {
    if (head == nullptr) {
        cout << "\n\033[1;31mNo accounts available.\033[0m\n";  // Red text
        return;
    }

//    cout << "\033[1;35m";  // Magenta text for table headers
//    cout << left << setw(15) << "Account Number"
//         << setw(20) << "Name"
//         << setw(20) << "Type"
//         << setw(15) << "Balance" << endl;
//    cout << "═══════════════════════════════════════════════════════════════════════\n";
//    cout << "\033[0m";  // Reset text

    accountNode* temp = head;
    while (temp != nullptr) {
        cout << left << setw(15) << temp->accountNumber
             << setw(20) << temp->name
             << setw(20) << temp->accountType
             << right << setw(9) << fixed << setprecision(2) << temp->balance
			 << setw(6)  << ' ' << endl;
        temp = temp->next;
    }
}

// Display a brief list of accounts
//void accountLinkedList::displayAnAccount() {
//    if (head == nullptr) {
//        cout << "\n\033[1;31mNo accounts available.\033[0m\n";  // Red text
//        return;
//    }
//
//    cout << "\033[1;35m";  // Magenta text for table headers
//    cout << left << setw(15) << "Account Number"
//         << setw(20) << "Name" << endl;
//    cout << "═══════════════════════════════════════════════════════════════════════\n";
//    cout << "\033[0m";  // Reset text
//
//    accountNode* temp = head;
//    while (temp != nullptr) {
//        cout << left << setw(15) << temp->accountNumber
//             << setw(20) << temp->name << endl;
//        temp = temp->next;
//    }
//}

//accountNode* accountLinkedList::confirmAccount(string name,string password) {
//	accountNode* current = head;
//    while (current != nullptr) {
//        if (current->name == name && current->password == password) {
//            return current;
//        }
//        current = current->next;
//    }
//    return nullptr;  // Return null if account is not found
//}
