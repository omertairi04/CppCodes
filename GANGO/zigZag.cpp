
/* A positive integer is given. Your task is to write a program that will check
 * if the number is zig-zag, or rather if the digits of the number are
 * alternately larger - smaller digit. Ex: 12121 (1 < 2, 2 > 1, 1 > 2  ... ). If
 * the number is zigzag print 1, otherwise 0. The zigzag function must be
 * recursive, otherwise half of the points are won. INPUT: 12121 OUTPUT: 1 */

#include <iostream>
bool isZigZag(int num) {
  if (num < 100) {
    return false;
  }
  int d1 = num % 10;
  num /= 10;
  int d2 = num % 10;
  num /= 10;
  int d3 = num % 10;

  // Check if the digits form a zigzag pattern
  if ((d1 < d2 && d2 > d3) || (d1 > d2 && d2 < d3)) {
    // Recur on the remaining digits
    return isZigZag(num / 10);
  } else {
    return false;
  }
}
int main() {

  int n;
  std::cin >> n;

  // std::cout << isZigZag(n);
  if (isZigZag(n)) {
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }
}