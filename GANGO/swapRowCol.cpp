// Create a function that computes the transpose of a given matrix. The
// transpose of a matrix switches the rows and columns.

#include <cctype>
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
      if (i < j) {
        std::swap(arr[i][j], arr[j][i]);
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