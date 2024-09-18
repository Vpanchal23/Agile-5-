#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <cstdlib>   // for random account number generation
#include <ctime>     // for seeding the random number generator
#include "LinkedList.h"

// Generate a random account number
string generateAccountNumber();

void createAnAccount(LinkedList& list);
void editAnAccount(LinkedList& list);
void deleteAnAccount(LinkedList& list);
void viewAllAccounts(LinkedList& list);



#endif /* BANK_H_ */
