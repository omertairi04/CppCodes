#include <iostream>
#include <string>
using namespace std;

int main() {
    char text[100];
    char character[100];
    int numOfStrings;

    cout << "Enter the number of strings: ";
    cin >> numOfStrings;
    cin.ignore(); // Ignore the newline character in the input buffer

    int count = 0;

    cout << "Enter the character to count: ";
    cin.getline(character, 100);

    for (int i = numOfStrings; i > 0; i--) {
        cout << "Enter string " << numOfStrings - i + 1 << ": ";
        cin.getline(text, 100);

        for (int j = 0; text[j] != '\0'; j++) {
            if (text[j] == character[0]) {
                count++;
            }
        }
    }

    cout << "The character '" << character[0] << "' occurs " << count << " times in the entered strings." << endl;

    return 0;
}