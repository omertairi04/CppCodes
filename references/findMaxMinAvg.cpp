/* Write a C++ function named findMaxMinAvg that takes an array of integers and
 * its size as parameters. The function should find the maximum, minimum, and
 * average values of the elements in the array. You should use references for
 * returning these values.
*/

#include <iostream>

void findMaxMinAvg(int arr[], int size, int &max, int &min, double &avg) {
  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }

    if (arr[i] < min) {
      min = arr[i];
    }
  }

  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  avg = sum / size;

  std::cout << "Max: " << max << "\n";
  std::cout << "Min: " << min << "\n";
  std::cout << "Avg: " << avg << "\n";
}

int main() {

  int n;
  std::cin >> n;

  int arr[n];
  int max = arr[0], min = arr[0
  ];
  double avg = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  findMaxMinAvg(arr, n, max, min, avg);
}
