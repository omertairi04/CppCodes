/*
Write a program that for a given array of integers (input from the keyboard),
will print the largest element. The program should include a recursive function
for finding the largest element in a given array.
*/

#include <iostream>

// Recursive function
int largest_element(int n, int arr[]) {

  if (n == 1)
    return arr[0]; // Base condition

  return std::max(arr[n - 1], largest_element(n - 1, arr));
}

int smallest_element(int size, int arr[]) {

  if (size == 1)
    return arr[0];

  return std::min(arr[size - 1], smallest_element(size - 1, arr));
}

int main() {

  const int MAX = 100;
  int arr[MAX];
  int i = 0;

  while (i < MAX && std::cin >> arr[i]) {
    i++;
  }

  // Output the elements of the array
  std::cout << "Output:" << std::endl;
  for (int j = 0; j < i; j++) {
    std::cout << arr[j] << " ";
  }
  std::cout << "\n";

  std::cout << "largest element " << largest_element(i, arr) << "\n";
  std::cout << "smallest element " << smallest_element(i, arr) << "\n";
}