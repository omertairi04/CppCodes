#include <cstring>
#include <iostream>
/* Write a program that reads two natural numbers, start and end, from standard
 * input. Then the program should find and print the palindromes in the range
 * [start, end]. A palindrome is defined as a number that remains the same even
 * when its digits are in reverse order. Your task is to find the smallest and
 * largest palindromes in the given range. */

bool checkPali(int num) {
  int original = num;
  int reversed = 0;
  while (num > 0) {
    int digit = num % 10;
    reversed = reversed * 10 + digit;
    num /= 10;
  }
  return original == reversed;
}

int main() {
  int start, end;
  std::cin >> start >> end;

  int max = start, min = end;
  for (int i = start; i <= end; i++) {
    if (checkPali(i)) {
      if (i < min) {
        min = i;
      }
      if (i > max) {
        max = i;
      }
      std::cout << i << std::endl;
    }
  }
  std::cout << "max: " << max << std::endl;
  std::cout << "min: " << min << std::endl;

  return 0;
}
