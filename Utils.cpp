#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;

void clearScreen() {
    system("clear");
}

string centerText(const string& text, int width) {
    int len = text.length();
    if (len >= width) {
        return text;
    } else {
        int padding = (width - len) / 2;
        return string(padding, ' ') + text + string(padding + (width - len) % 2, ' ');
    }
}
