#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Declare variables
    int MAX = 100;
    char inputString[MAX], result[MAX];
    int position, length;

    // Input: Read a line of characters into the 'inputString' array
    cin.getline(inputString, MAX);

    // Input: Read integers 'position' and 'length'
    cin >> position >> length;

    // Check if the specified position is within the length of the string
    if (position <= strlen(inputString)) {
        // Copy a portion of the string starting from 'position' and with length 'length' into 'result'
        strncpy(result, inputString + position - 1, length);

        // Add null terminator to 'result' to ensure it is a valid C-string
        result[length] = '\0';

        // Output: Print the result
        cout << "Result: " << result << endl;
    } else {
        // Output: Print an error message if the specified position is invalid
        cout << "Invalid input, the read string has only " << strlen(inputString) << " characters.\n";
    }

    return 0;
}
