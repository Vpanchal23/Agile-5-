#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

struct AccountNode {
    std::string accountNumber;
    std::string accountType;
    double balance;
    AccountNode* next;

    // Constructor
    AccountNode(const std::string& accountNumber, const std::string& accountType, double balance);

    // Destructor
    ~AccountNode();

    // Account operations
    void deposit(double amount);
    void withdraw(double amount);
};

#endif // ACCOUNT_H