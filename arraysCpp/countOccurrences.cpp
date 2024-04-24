#include <iostream>

int main() {
  int arr[] = {1, 3, 2, 0, 1, 4, 2, 5, 0, 3, 1, 1, 3, 0, 0}; // Sample array
  int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  // Create an array to store the count of each element, initialized with zeros
  int count[100] = {0}; // Assuming elements are between 0 and 99

  // Count occurrences of each element in the array
  for (int i = 0; i < size; ++i) {
    count[arr[i]]++;
  }

  // Find the smallest number with non-zero occurrences
  int smallestNumber = -1;
  for (int i = 0; i < 100; ++i) { // Assuming elements are between 0 and 99
    if (count[i] != 0) {
      smallestNumber = i;
      break; // Exit the loop as soon as we find a non-zero occurrence
    }
  }

  // Print the smallest number with its occurrence count
  if (smallestNumber != -1) {
    std::cout << "Smallest number: " << smallestNumber
              << ", Occurrences: " << count[smallestNumber] << std::endl;
  } else {
    std::cout << "Array is empty or all elements are zeros." << std::endl;
  }

  return 0;
}
