/* Write a program that reads two natural numbers, a start and an end, from the
standard input. The program should print
 * the largest palindrome in the range [start, end] as output.
The solution should be implemented using three functions:
- reverse(int number) - a function to calculate the reversed number (for
example, for 123, it should return 321)]
- isPalindrome(int number) - a function that checks if a number reads the same
from left to right and from right to left.
- findLargest(int start, int end) - a function that finds the largest palindrome
in the range [start, end]. */

#include <climits>
#include <cstdlib>
#include <iostream>

bool isPalindrome(int num) {
  std::string str = std::to_string(num);
  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

int reverse(int num) {
  int rev = 0;
  while (num != 0) {
    int ld = num % 10;
    rev = rev * 10 + ld;
    num /= 10;
  }
  return rev;
}

int findLargest(int start, int end) {
  int largest = start;
  for (int i = start; i <= end; i++) {
    if (isPalindrome(i)) {
      if (i > largest) {
        largest = i;
      }
    }
  }
  return largest;
}

int main() {

  int start, end;

  std::cin >> start >> end;

  int largestPalindrome = findLargest(start, end);
  std::cout << "Largest palindrome in range [" << start << ", " << end
            << "]: " << largestPalindrome << std::endl;
}
