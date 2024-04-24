
/* Write a program that reads two natural numbers, start and end, from standard
 * input. Then the program should find and print the palindromes in the range
 * [start, end]. A palindrome is defined as a number that remains the same even
 * when its digits are in reverse order. Your task is to find the smallest and
 * largest palindromes in the given range. */

#include <iostream>
#include <string>

bool isPali(std::string str) {
  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {

  int start, end;

  std::cin >> start >> end;

  int max = start, smallest = end;
  for (int i = start; i <= end; i++) {
    std::string text = std::to_string(i);
    bool pali = isPali(text);
    if (pali) {
      if (i > max) {
        max = i;
      }
      if (i < smallest) {
        smallest = i;
      }
    }
  }

  std::cout << max << " " << smallest << "\n";
}
