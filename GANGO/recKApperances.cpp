/* Write a recursive function that prints out the number of occurrences of a
 * number k in an array of N elements (N is read from SI, as well as the array).
 * If the array doesn't contain the number k, print 0.*/

int searchOccurrence(int array[], int size, int k) {
  if (size == 0) {
    return 0;
  }
  if (array[0] == k) {
    return 1 + searchOccurrence(array + 1, size - 1, k);
  }
  return searchOccurrence(array + 1, size - 1, k);
}

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int k;
  std::cin >> k;

  int counter = searchOccurrence(arr, n, k);
  std::cout << counter << "\n";
}
