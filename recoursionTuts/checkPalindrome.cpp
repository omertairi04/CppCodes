#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string &text , int start , int end) {
    if (start >= end) return true;

    if (text[start] != text[end]) {
        return false;
    } else {
        return isPalindrome(text,start + 1, end - 1);
    }
}

int main() {
    string words;
    getline(cin , words);

    // remove spaces from string
    words.erase(remove(words.begin(), words.end(), ' '),words.end());

    bool palindrome = isPalindrome(words , 0 , words.length() - 1);

    if (palindrome) {
        cout << " given string is palindrome";
    } else {
        cout << " given string is NOT palindrome";
    }
}

