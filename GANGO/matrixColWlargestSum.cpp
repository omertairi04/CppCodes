/* Enter a matrix and find the column with the largest sum and add that value to
 * that element column */

#include <iostream>

int main() {
  int m, n;

  std::cin >> m >> n;

  int arr[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }

  int maxSum = 0;
  int /* row = 0,*/ col = 0;
  for (int i = 0; i < m; i++) {
    int currentMax = 0;
    for (int j = 0; j < n; j++) {
      currentMax += arr[j][i];
      col = j;
    }
    if (currentMax > maxSum) {
      maxSum = currentMax;
    }
    // std::cout << "\n";
  }

  for (int i = 0; i < m; i++) {
    arr[i][col] = maxSum;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << " \n";
  }

  std::cout << maxSum << " \n";
  std::cout << col << " \n";
}
