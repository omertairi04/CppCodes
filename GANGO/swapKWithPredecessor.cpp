/* A number N is read from standard input, which represents the length of the
 * array, and then the elements for the same array are entered and finally the
 * number K. Write a program that transforms the array in a way that you swap
 * the element on the position K with its predecessor. Note that the change
 * should be made when you read the array from left to right and also in the
 * opposite direction (from right to left). Input:
 * 8
 * 1 2 3 4 5 6 7 8
 * 2
 * Output:
 * 1 3 2 4 5 7 6 8*/

#include <iostream>
int main() {

  int n, k;
  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cin >> k;
  for (int i = 0; i < n; i++) {
    if (i == k) {
      // std::cout << "i: " << i << "\nk " << k << " ";
      std::swap(arr[i - 1], arr[k]);
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << " \n";
}
