
/* From SI, a square matrix with n rows and columns is read. First, the number n
 * is read, and then the n * n elements of the matrix are read. Your task is to
 * write a program in C++ that will determine if the given matrix is a "magic
 * square". A magic square is a square matrix where the sum of the elements in
 * each row and column is the same. If the matrix is a "magic square", print
 * "True" and replace the elements from the main and secondary diagonals with
 * the sum of the elements that is the same for each row and columns Otherwise
 * print, "False".*/

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

  int rowSum = 0, colSum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rowSum += arr[i][i];
      colSum += arr[j][n - i - j];
    }
  }

  if (rowSum != colSum) {
    std::cout << "False\n";
    return 0;
  }

  std::cout << "True\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == j) && (i + j) == n - 1) {
        arr[i][j] = colSum;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        arr[i][j] = colSum;
      }
      if ((i + j) == n - 1) {
        arr[i][j] = colSum;
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
