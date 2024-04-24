/* From SI a number n is entered, then read n elements of an array.
 * Transform the array in a way such that elements in even positions will be
 * multiplied by 2, and elements in odd positions will be increased by 2. Print
 * the array and separate the elements by space between them. EX:
 * 5
 * 1 2 3 4 5
 * Output:
 * 2 4 6 6 10*/

#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      arr[i] *= 2;
    }
    if (i % 2 != 0) {
      arr[i] += 2;
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
}