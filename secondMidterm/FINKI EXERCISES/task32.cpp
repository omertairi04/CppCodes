#include <iostream>
#include <cstring>
using namespace std;

bool isValidWord(const char* word) {
    int length = strlen(word);
    return length >= 4 && length <= 20;
}

int countUniqueLetters(const char* word) {
    int counts[26] = {0};

    for (int i = 0; word[i] != '\0'; ++i) {
        if (isalpha(word[i])) {
            int index = tolower(word[i]) - 'a';
            counts[index] = 1;
        }
    }

    int uniqueCount = 0;
    for (int i = 0; i < 26; ++i) {
        uniqueCount += counts[i];
    }

    return uniqueCount;
}

int main() {
    char word[21];
    char maxUniqueWord[21];
    int maxUniqueCount = -1;

    while (cin >> word) {
        if (isValidWord(word)) {
            int uniqueCount = countUniqueLetters(word);

            if (uniqueCount > maxUniqueCount) {
                maxUniqueCount = uniqueCount;
                strcpy(maxUniqueWord, word);
            }
        }
    }

    cout << maxUniqueWord << endl;

    return 0;
}
