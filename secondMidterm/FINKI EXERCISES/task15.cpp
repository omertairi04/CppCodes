#include <cctype>
#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin,  str);
    char separator = ' ';
    int i=0;
    string temp;
    while (str[i] != '\0') {
        if (str[i] != separator) {
            if (isalpha(str[i])) {
                temp += str[i];
            }
        } else {
            if (!temp.empty()) {
                cout << temp << "\n";
                temp.clear();
            }
        }
        i++;
    }

    if (!temp.empty()) {
        cout << temp << " \n";
    }

    return 0;

}

// Testing #123 and some text.