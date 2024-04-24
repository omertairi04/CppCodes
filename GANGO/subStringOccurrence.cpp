/* Write a program that for an array of characters (containing 300 characters).
 * Now write a program that from an input for a given character prints the
 * substring from the first occurrence until the last occurrence of the
 * character. Ignore the case of the letters. Ex: Zdravo kako si? Output: avo ka
 */

#include <cctype>
#include <cstring>
#include <iostream>

void subString(char arr[100], char c) {
  int length = strlen(arr), start = 0, end = 0;

  for (int i = 0; i < length; i++) {
    if (arr[i] == c) {
      start = i;
      break;
    }
  }

  for (int i = length - 1; i >= 0; i--) {
    if (arr[i] == c) {
      end = i;
      break;
    }
  }

  for (int i = start; i <= end; i++) {
    std::cout << arr[i];
  }
}

int main() {
  char arr[301], c;
  std::cin.getline(arr, 301);

  std::cin >> c;

  subString(arr, c);
}
