/*A given number n is entered from standard input, and then n three-digit
 *numbers are entered. Your task is to find the largest number whose sum of
 *digits must be an even number.*/

#include <iostream>

int sumDigits(int num) {
  int sum = 0;
  return sum + sumDigits(num / 10);
}

int main() {
  int n, number, sumOfLargestEven;
  std::cin >> n;

  while (std::cin >> number) {

    if (number > 100 && number < 1000) {
      int sum = sumDigits(number);

      // sumOfLargestEven = number;
    }
  }
}

// TO DO
