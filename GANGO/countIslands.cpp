#include <iostream>

int main() {
  int m, n;

  std::cin >> m >> n;

  int arr[n][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }

  int islandSum = 0;
  for (int i = 1; i < m - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (arr[i][j] == 1) {
        bool top = false, left = false, right = false, bottom = false;
        if (arr[i - 1][j] == 1) {
          top = true;
        }
        if (arr[i + 1][j] == 1) {
          bottom = true;
        }
        if (arr[i][j + 1] == 1) {
          right = true;
        }
        if (arr[i][j - 1] == 1) {
          left = true;
        }

        if (top && left && right && bottom) {
          islandSum++;
          arr[i][j] = 0;
          arr[i - 1][j] = 0;
          arr[i + 1][j] = 0;
          arr[i][j + 1] = 0;
          arr[i][j - 1] = 0;
        }
      }
    }
  }

  std::cout << islandSum << "\n";

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}