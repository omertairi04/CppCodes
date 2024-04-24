#include <algorithm>
#include <iostream>

/*
Write a program to rotate the elements of an array one place to the right.
Finally, print the rotated array to the screen. Read the elements of the array
from the standard input.
*/

int main() {
  int n;

  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    int tmp = arr[0];
    if (i == 0) {
      arr[0] = arr[n - 1];
    }
    if (i == n - 1) {
      arr[n - 1] = tmp;
    }
    arr[i] = arr[i + 1];
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << "\n";
}
