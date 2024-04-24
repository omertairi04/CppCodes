#include <iostream>
#include <cctype>
using namespace std;

int main() {

    // Aa Ee Ii Oo Uu

    string text;
    getline(cin, text);

    int countVowel = 0;
    for (int i=0;i<text.length();i++) {
        char c = tolower(text[i]);

        if (c == 'a' || c == 'e' || c=='o' || c=='i' || c=='u'){
            countVowel++;
        }
    }

    cout << countVowel << "\n";

}