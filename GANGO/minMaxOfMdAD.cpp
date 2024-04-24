/* Input a square matrix and find the max and min by row. Replace the max and
 * min of the anti and main diagonals like so: min = 0, max = 1;*/

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
      if (arr[j][i] > max) {
        max = arr[j][i];
      }
      if (arr[j][i] < min) {
        min = arr[j][i];
      }
    }

    for (int j = 0; j < n; j++) {
      if (i == j) {
        if (arr[i][j] == max) {
          arr[i][j] = 1;
        }
        if (arr[i][j] == min) {
          arr[i][j] = 0;
        }
      }
    }

    for (int j = 0; j < n; j++) {
      if ((i + j) == n - 1) {
        if (arr[i][j] == max) {
          arr[i][j] = 1;
        }
        if (arr[i][j] == min) {
          arr[i][j] = 0;
        }
      }
    }

    //   for (int j = 0; j < n; j++) {
    //     if (i == j || (i + j) == n - 1) {
    //       if (arr[i][j] == max) {
    //         arr[i][j] = 1;
    //       }
    //       if (arr[i][j] == min) {
    //         arr[i][j] = 0;
    //       }
    //     }
    //   }
    // }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}