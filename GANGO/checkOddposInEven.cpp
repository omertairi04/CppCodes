/* Write a program that will read two natural numbers. The program should check
 * if the digits in the odd position of the number are in the even position in
 * the second number. If this condition is met the program prints DA otherwise
 * NE. The first digit is in the 0th position starting from the left. */

#include <iostream>

bool checkDigit(int x, int y) {
  while (x > 0) {
    int ld_x = x % 10;
    x /= 10;

    int ld_y = y % 10;
    y /= 10;

    // Check if digit in odd position of x exists in even position of y
    if (ld_x % 2 == 1 && ld_x == ld_y) {
      return true;
    }
  }
  return false;
}

int main() {
  int first, second;

  std::cin >> first >> second;

  //   std::cout << checkDigit(first, second) << " \n";
  if (checkDigit(first, second)) {
    std::cout << "DA \n";
  } else {
    std::cout << "NE \n";
  }
}
