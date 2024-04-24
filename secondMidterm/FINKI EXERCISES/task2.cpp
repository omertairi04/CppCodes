#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;

    while (getline(cin, str) && !str.empty()) {
        for (char c : str) {
            if (isalpha(c)) {
                char shifted = (tolower(c) - 'a' + 3) % 26 + 'a';
                cout << shifted;
            } else {
                cout << c;
            }
        }
        cout << endl;  // Print a newline after processing each line
    }

    return 0;
}
