#include <iostream>
using namespace std;

int main() {
  int matrix[100][100];
  int m, n;
  // m - row ; n - col
  cin >> m >> n;

  // Enter matrix
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  // start from 2 (both row and col)
  int size = 2;
  int counter = 0;
  int sum = 0;

  // loop the row while row < size;
  for (int i = 0; i < size; ++i) {
    if (counter > 0) {
      sum = 0;
      i = 0;
    }
    counter = 0;
    // loop the col while j < size
    for (int j = 0; j < size; ++j) {
      if (i == 0 && j != size - 1) {
        // get first row
        sum += matrix[i][j];
      }
      // get anti diagonal
      if (i + j == size - 1) {
        sum += matrix[i][j];
      }
      // get last row
      if (i == size - 1 && j > 0) {
        sum += matrix[i][j];
      }
    }
    // i is in the last element of the row
    if (i == size - 1) {
      cout << sum << endl;
      size++;
      counter++;
      // if size is at the end then break
      if (size == m + 1 || size == n + 1) {
        break;
      }
    }
  }

  return 0;
}