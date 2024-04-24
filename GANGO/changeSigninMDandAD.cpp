/* Find and change the sign of the elements in the matrix that are
 * simultaneously under the main diagonal and anti-diagonal. If they're
 * positive, make them negative, if they're negative make them positive. */

#include <iostream>

int main() {
  int n, k;

  std::cin >> n;

  int arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == j) || (i + j == n - 1)) {
        arr[i][j] *= -1;
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
