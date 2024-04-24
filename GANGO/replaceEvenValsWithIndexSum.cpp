/* Find the even values in a matrix and replace them with the sum of the
 * indexes. */

#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int arr[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] % 2 == 0) {
        int sum = i + j;
        arr[i][j] = sum;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}
