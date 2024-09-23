// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>

// Terminal width for centering
const int TERMINAL_WIDTH = 73;  // Adjusted for border characters

// Function to center text based on terminal width
std::string centerText(const std::string& text, int width = TERMINAL_WIDTH);

// Clear screen function for cross-platform
void clearScreen();

#endif // UTILS_H
