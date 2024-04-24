#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string text ) {
    for (int i=0;i<text.length() / 2;i++) {
        if (text[i] != text[text.length() - i -1]) {return false;}
    }
    return true;
}

bool numIsPalindrome(int number) {
    string str = to_string(number);
    return isPalindrome(str);
}


int main() {
    char n[100];
    int num;
    cin.getline(n, 100);

    cin >> num;

    cout << " " << isPalindrome(n) << "\n";
    cout << " " << numIsPalindrome(num) << "\n";


}

