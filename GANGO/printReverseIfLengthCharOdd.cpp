/* Write an array of characters. If the number of the given characters is an odd
 * number, print the array in reverse. */

#include <cstring>
#include <iostream>

int main() {
  char arr[100];

  std::cin.getline(arr, 100);

  if (strlen(arr) % 2 != 0) {
    for (int i = strlen(arr) - 1; i >= 0; i--) {
      std::cout << arr[i];
    }
  }
}