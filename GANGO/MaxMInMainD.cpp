/*
Write a program that, for a matrix entered from the keyboard, replaces the
elements of the main diagonal with the difference between the maximum and
minimum element in the matrix. Print the resulting matrix to the screen.*/

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

  int max = arr[0][0], min = arr[0][0];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
      if (arr[i][j] < min) {
        min = arr[i][j];
      }
    }
  }

  int diff = max - min;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        arr[i][j] = diff;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}