#ifndef UTILS_H
#define UTILS_H

#include <string>

// Terminal width for centering
const int TERMINAL_WIDTH = 73;  // Adjusted for border characters

// Function to center text based on terminal width
std::string centerText(const std::string& text, int width = TERMINAL_WIDTH);

// Clear screen function for cross-platform
void clearScreen();

// Input validation functions
bool isNumber(const std::string& str);

int getValidatedChoice(int minChoice, int maxChoice);

// Display menu header
void displayMenuHeader(const std::string& title);

// Pause for user input
void pauseForUser();

bool ReadDeadlockBool(std::string &name, int &ssn);

void FreeDeadlock();

std::string DataEncryption(std::string data);

std::string DataDecryption(std::string data);

#endif // UTILS_H
