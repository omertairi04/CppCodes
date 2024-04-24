/* Enter a square matrix. Transform the matrix so that the negative number is
 * replaced by the sum of its neighbors. Addition (sum of the neighbors of a
 * member of a matrix is seen horizontally from it and vertically).*/

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
      if (arr[i][j] < 0) {
        int sum = 0;
        if (i > 0) {
          int top = arr[i - 1][j];
          // std::cout << "top: " << top << "\n";
          sum += top;
        }
        if (i < n - 1) {
          int bottom = arr[i + 1][j];
          // std::cout << "bottom: " << bottom << "\n";
          sum += bottom;
        }
        if (j > 0) {
          int left = arr[i][j - 1];
          // std::cout << "left: " << left << "\n";
          sum += left;
        }
        if (j < n - 1) {
          int right = arr[i][j + 1];
          // std::cout << "right: " << right << "\n";
          sum += right;
        }
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
