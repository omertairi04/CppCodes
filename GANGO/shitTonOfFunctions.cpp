/* To define and implement the following functions:
 * 1. int reverseNumber(int num) - a function that takes one argument, num, and
 * returns its reverse. Ex. for the number 1234, the function should return
 * 4321.
 *
 * 2. int sumOfDigits(int num) - a function that takes one argument, num,
 * returns the sum of its digits. Ex. for the number 1234, the function should
 * return 10(1+2+3+4=10).
 *
 * 3. void printInterval(int f, int q) - a function that takes two arguments, f
 * and q, and doesn't return anything since its a void The purpose of this
 * function is to int all numbers in the interval f to b (including both), for
 * which the number X is divisible by the reverse of the sum of its digits. Use
 * the first two functions to implement this one.
 *
 * Example for such a number:
 * For 992, the sum of its digits it's 9+9+2=20. The reverse of the sum of it's
 * digits is 20 -> 2. Since 992 is divisible by 2, it fulfills the condition.*/

#include <iostream>

int reverseNumber(int num) {
  int rev = 0;
  while (num != 0) {
    int ld = num % 10;
    rev = rev * 10 + ld;
    num /= 10;
  }

  return rev;
}

int sumOfDigits(int num) {
  if (num == 0)
    return 0;
  return (num % 10 + sumOfDigits(num / 10));
}

void printInterval(int f, int q) {
  for (int i = f; i <= q; ++i) {
    int sumD = sumOfDigits(i);
    int rev = reverseNumber(sumD);
    if (i % rev == 0) {
      std::cout << i << " ";
    }
  }
}
int main() {
  int f, q;
  std::cout << "Enter the interval (f and q): ";
  std::cin >> f >> q;

  std::cout << "Numbers in the interval divisible by the reverse of the sum of "
               "their digits: ";
  printInterval(f, q);
  std::cout << std::endl;

  return 0;
}
