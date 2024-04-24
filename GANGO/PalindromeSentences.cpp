/* Write a program to check how many palindrome sentences an array of characters
 * has.  */

#include <cctype>
#include <cstring>
#include <iostream>

char letters(char arr[101]) {
  char letters[100];
  int j = 0;

  for (int i = 0; i < strlen(arr); i++) {
    if (isalpha(arr[i])) {
      letters[j] = arr[i];
      j++;
    }
  }
  letters[j] = '\0';
  return letters[j];
}

int counter(int count) {
  return count++;
}

bool isPalindrome(char txt[101]) {
  int count = 0;
  for (int i = 0; i < strlen(txt) / 2; i += 2) {
    if (toupper(letters(txt)) != toupper(letters(txt))) {
      return false;
    }
  }
  return true;
}

int main() {

  char string[100];

  std::cin.getline(string, 100);

  std::cout << isPalindrome(string) << "\n";
}