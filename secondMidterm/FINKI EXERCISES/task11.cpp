#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cin >> str;

    bool foundFirstDigit = false;
    int firstDigitIndex = -1;
    int secondDigitIndex = -1;

    // Finding the indices of the first and second digits
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            if (!foundFirstDigit) {
                foundFirstDigit = true;
                firstDigitIndex = i;
            } else {
                secondDigitIndex = i;
                break;
            }
        }
    }

    // Printing the result based on the found indices
    if (firstDigitIndex == -1) {
        cout << "No digits" << endl;
    } else if (secondDigitIndex == -1) {
        for (int i = firstDigitIndex; i < str.size(); ++i) {
            cout << str[i];
        }
        cout << endl;
    } else {
        for (int i = firstDigitIndex; i <= secondDigitIndex; ++i) {
            cout << str[i];
        }
        cout << endl;
    }

    return 0;
}
