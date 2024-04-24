#include <iostream>
#include <string>
using namespace std;

void generatePermutations(string &text , int left , int right) {
    if (left == right) {
        cout << text << endl;return;
    }
    
    for (int i=left; i <=right;i++) {
        swap(text[left] , text[i]);
        generatePermutations(text, left + 1, right);
        swap(text[left] , text[i]);
    }
}

int main() {
    string words;
    getline(cin , words);
    generatePermutations(words , 0 , words.length() - 1);
}