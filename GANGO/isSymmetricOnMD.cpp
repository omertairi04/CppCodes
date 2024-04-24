// Write a program that, for a square matrix entered from the keyboard, prints
// to the screen whether it is symmetric with respect to the main diagonal.

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
        
      }
    }
  }
}
