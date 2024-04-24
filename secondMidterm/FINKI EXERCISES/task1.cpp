#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function to perform cyclic shifting on a character
char shiftChar(char c, int shift) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + shift) % 26 + base;
    }
    return c;
}

// Recursive function to transform a string
void transformString(string& str, int shift, size_t index = 0) {
    if (index < str.length()) {
        str[index] = shiftChar(str[index], shift);
        transformString(str, shift, index + 1);
    }
}

int main() {
    int N, X;
    cin >> N >> X;
    cin.ignore(); // Consume newline after reading X

    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str);

        // Transform the string using recursion
        transformString(str, X);

        // Output the transformed string
        cout << str << endl;
    }

    return 0;
}
