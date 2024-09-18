#include "Bank.h"

string generateAccountNumber() {
    srand(time(0)); // Seed random number generator
    return to_string(rand() % 100000 + 10000); // Generate random 5-digit account number
}
