/* Write a program that for a given array of characters, if it has special
 * characters replace them with *, and if it's a normal character and is in an
 * odd position transform it into an uppercase letter, and if it's in an even
 * position to transform it into a lower case letter. */

#include <cctype>
#include <cstring>
#include <iostream>

int main() {
  char arr[100];

  std::cin.getline(arr, 100);

  for (int i = 0; i < strlen(arr); i++) {
    if (i % 2 == 0) {
      arr[i] = tolower(arr[i]);
    } else if (i % 2 != 0) {
      arr[i] = toupper(arr[i]);
    }

    if (!isalnum(arr[i]) && arr[i] != ' ') {
      arr[i] = '*';
    }
  }

  std::cout << arr;
}
