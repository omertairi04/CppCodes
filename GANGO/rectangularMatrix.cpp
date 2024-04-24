/* You enter a rectangular matrix (2 rows and 5 columns) and print the
 * arrollowing:
 EX:
 2 5
 1 2 3 4 5
 6 7 8 9 10

 Output:     Could also do this:
  1            1 7
 * 2 6         2 8
 * 3 7         3 9
 * 4 8         4 10
 * 5 9         5
 * 10
 */

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

  std::cout << arr[0][0] << std::endl;

  for (int j = 1; j < n; j++) {
    for (int i = 0; i - j < n && i < m; i++) {
      std::cout << arr[i][j + i] << " ";
    }
    std::cout << std::endl;
  }
}
