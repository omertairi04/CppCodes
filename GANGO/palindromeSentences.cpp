/* Write a program to check how many palindrome sentences an array of characters
 * has.  */

#include <cctype>
#include <cstring>
#include <iostream>

int main() {
  char arr[101];

  std::cin.getline(arr, 100);

  int counter = 0;

  for (int i = 0; i < strlen(arr); i++) {
    char reversed = 0;
    for (int j = strlen(arr) - 1; j >= 0; j--) {
      if ((isalnum(arr[j] && isalpha(arr[j])))) {
        arr[j] = reversed;
      }
    }
    if ((!isalnum(arr[i]) && isalpha(arr[i]) && isalnum(reversed) &&
         isalpha(reversed))) {
      if (arr[i] == reversed) {
        counter++;
      }
    }
  }
  std::cout << counter;
}
