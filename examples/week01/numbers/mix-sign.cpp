#include <iostream>

// what is the output from the following program?
int main() {
    int j = -20;
    unsigned k = 10;

    if (j+k > 10) {
        std::cout << j << " + " << k << " is greater than 10\n";
    } else {
        std::cout << j << " + " << k << " is less than or = 10\n";
    }
}

