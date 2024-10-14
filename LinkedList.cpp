// LinkedList.cpp
#include "LinkedList.h"
#include <iomanip>

using namespace std;

// Insert a node at the end of the list
void LinkedList::insertAtEnd(string name, string serialNumber, string password, bool employee, bool accountsCreated) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->serialNumber = serialNumber;
    newNode->password = password;
    newNode->employee = employee;
    newNode->accountsCreated = accountsCreated;
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
void LinkedList::loadFromFile(const string& filename, string arr[], short *index) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string  name, serialNumber, password;
    bool employee, accountsCreated;

    // Manually process each line of the file
    while (file >> name >> serialNumber >> password >> employee >> accountsCreated) {
        insertAtEnd(name, serialNumber, password, employee, accountsCreated);

        if (accountsCreated)
		{
			Node* current = head;
			string textFile;
			textFile = serialNumber + ".txt";

			while(current->next != nullptr)
			{
				current = current->next;
			}
			current->accounts.loadFromFile(textFile);
		}
    }

    file.close();
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
        outfile << current->name << " " << current->serialNumber << " "
				<< current->password << " " << current->employee << " "
				<< current->accountsCreated << endl;

        if (current->accountsCreated)
        {
        	string textFile;
        	textFile = current->serialNumber + ".txt";
        	current->accounts.convertLinkedListToTextFile(textFile);
		}
        current = current->next;
    }

    outfile.close();
}

// Delete a node by account number from the linked list
//void LinkedList::deleteNode(string accountNumber) {
//    if (!head) {  // Check if the list is empty
//        cout << "\033[1;31mNo accounts available.\033[0m\n";  // Red text
//        return;
//    }
//
//    // If the head node itself holds the accountNumber to be deleted
//    if (head->accountNumber == accountNumber) {
//        Node* temp = head;  // Save the current head
//        head = head->next;  // Move the head to the next node
//        delete temp;        // Free the old head
//        cout << "\033[1;32mAccount " << accountNumber << " deleted successfully.\033[0m\n";
//        return;
//    }
//
//    // Search for the node to be deleted and keep track of the previous node
//    Node* current = head;
//    Node* previous = nullptr;
//    while (current != nullptr && current->accountNumber != accountNumber) {
//        previous = current;
//        current = current->next;
//    }
//
//    // If the accountNumber was not found in the list
//    if (current == nullptr) {
//        cout << "\033[1;31mAccount " << accountNumber << " not found.\033[0m\n";
//        return;
//    }
//
//    // Unlink the node from the linked list
//    previous->next = current->next;
//    delete current;  // Free the memory
//    cout << "\033[1;32mAccount " << accountNumber << " deleted successfully.\033[0m\n";
//}

// Find a node by account number
Node* LinkedList::findNode(const string accountNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->accounts.findNode(accountNumber) != nullptr) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Return null if account is not found
}

// Display accounts in a formatted way
void LinkedList::displayAccounts() {
    if (head == nullptr) {
        cout << "\n\033[1;31mNo accounts available.\033[0m\n";  // Red text
        return;
    }

    cout << "\033[1;35m";  // Magenta text for table headers
    cout << left << setw(15) << "Account Number"
         << setw(20) << "Name"
         << setw(20) << "Type"
         << setw(15) << "Balance" << endl;
    cout << "═══════════════════════════════════════════════════════════════════════\n";
    cout << "\033[0m";  // Reset text

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->accountsCreated)
        {
        	temp->accounts.displayMyAccounts();
        }
        temp = temp->next;
    }
}

// Display a brief list of accounts
//void LinkedList::displayAccountsBrief() {
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
//    Node* temp = head;
//    while (temp != nullptr) {
//        cout << left << setw(15) << temp->accountNumber
//             << setw(20) << temp->name << endl;
//        temp = temp->next;
//    }
//}

Node* LinkedList::confirmAccount(string name,string password) {
    Node* current = head;
    while (current != nullptr) {
        if (current->name == name && current->password == password) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Return null if account is not found
}

void LinkedList::displayLoginAccounts() {
    if (head == nullptr) {
        cout << "\n\033[1;31mNo accounts available.\033[0m\n";  // Red text
        return;
    }

    cout << "\033[1;35m";  // Magenta text for table headers
    cout << left << setw(15) << "ID Number"
         << setw(20) << "Name"
         << setw(20) << ' '
         << setw(15) << ' ' << endl;
    cout << "═══════════════════════════════════════════════════════════════════════\n";
    cout << "\033[0m";  // Reset text

    Node* temp = head;
    while (temp != nullptr) {
    	cout << left << setw(15) << temp->serialNumber
    	             << setw(20) << temp->name
    	             << setw(20) << ' '
    	             << setw(15) << ' ' << endl;
        temp = temp->next;
    }
}

// Find a node by ID number
Node* LinkedList::findLoginAccount(const string idNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->serialNumber == idNumber) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Return null if account is not found
}
