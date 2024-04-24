// Write a program in which four numbers are entered. If the sum of the first
// two entered numbers is even, and if the sum of the last two numbers is odd,
// print 1, otherwise print 0.

#include <iostream>

int main() {
  int n1, n2, n3, n4;

  std::cin >> n1 >> n2 >> n3 >> n4;

  int sumOfFirst2 = n1 + n2;
  int sumOfLast2 = n3 + n4;

  if (sumOfFirst2 % 2 == 0 && sumOfLast2 % 2 != 0) {
    std::cout << "1";
  } else {
    std::cout << "0";
  }
}
