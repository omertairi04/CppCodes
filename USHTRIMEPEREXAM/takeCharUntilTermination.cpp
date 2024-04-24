#include <iostream>
#include <cstring>

const int maxSize = 100;  // Adjust the size according to your needs

int main() {
    int numArrays;

    std::cout << "Enter the number of character arrays you want to enter: ";
    std::cin >> numArrays;

    char inputArrays[numArrays][maxSize];

    // Take input for each character array
    for (int i = 0; i < numArrays; ++i) {
        std::cout << "Enter character array" << i + 1 << ": ";
        std::cin >> inputArrays[i];
    }

    // Print each character array
    for (int i = 0; i < numArrays; ++i) {
        std::cout << "Character array" << i + 1 << ": " << inputArrays[i] << std::endl;
    }

    // Print the number of characters in each array
    for (int i = 0; i < numArrays; ++i) {
        std::cout << "Number of characters in array" << i + 1 << ": " << std::strlen(inputArrays[i]) << std::endl;
    }

    return 0;
}
