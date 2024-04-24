/* Write an array of characters and modify the program so that all the vowels to
 * become uppercase letters and all the consonants to become lowercase letters,
 * and vice versa.*/

#include <cctype>
#include <cstring>
#include <iostream>

bool isVowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {

  char string[100];

  std::cin.getline(string, 100);

  for (int i = 0; i < strlen(string); i++) {
    if (isVowel(string[i])) {
      string[i] = toupper(string[i]);
    } else {
      string[i] = tolower(string[i]);
    }
  }

  std::cout << string << "\n";
}