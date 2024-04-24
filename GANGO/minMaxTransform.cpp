
/* Input a square matrix, find the smallest and largest number by row, min and
 * max. After we get the min and max replace those numbers of the matrix with
 * min = 0 and max = 1; Print the result. And also do the same for under the
 * main and anti-diagonal.*/

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
    int max = arr[i][0], min = arr[i][0];
    for (int j = 0; j < n; j++) {
      // std::cout << arr[j][i] << " ";
      if (arr[j][i] > max) {
        max = arr[j][i];
      }
      if (arr[j][i] < min) {
        min = arr[j][i];
      }
    }
    // std::cout << "\n";

    for (int j = 0; j < n; j++) {
      if (arr[i][j] == min) {
        arr[i][j] = 0;
      }
      if (arr[i][j] == max) {
        arr[i][j] = 1;
      }
    }

    // std::cout << "max" << max << " \n";
    // std::cout << "min" << min << " \n";
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}
