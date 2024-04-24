#include <iostream>
#include <string>
using namespace std;

void reverseString (string & text , int start , int end) {
    if (start >= end) {
        return;
    }

    swap(text[start] , text[end]);
    reverseString(text,start + 1, end - 1);
}

int main () {
    string words;
    getline(cin , words);

    reverseString(words, 0, words.length() - 1);

    cout << "reversed string: " << words << endl;
}