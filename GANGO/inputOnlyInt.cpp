#include <iostream>

/* A number X is entered from standard input, then the numbers are entered until
 * something other than a number is entered. For each of the entered numbers
 * check if the number of digits is equal to the number of digits in X. For each
 * of the entered number, if the condition is met, print the number.*/

int countDigits(int number) {
  int count = 0;
  while (number != 0) {
    number /= 10;
    ++count;
  }
  return count;
}

int main() {
  int x, number;

  // Read X from standard input
  std::cin >> x;

  // Check if X is a valid integer
  if (!std::cin) {
    std::cerr << "Invalid input. Please enter a valid number.\n";
    return 1;
  }

  // Count digits in X
  int xDigitCount = countDigits(x);

  // Read numbers until non-integer input is encountered
  while (std::cin >> number) {
    // Count digits in the entered number
    int numberDigitCount = countDigits(number);

    // Check if the number of digits in the entered number is equal to the
    // number of digits in X
    if (numberDigitCount == xDigitCount) {
      std::cout << number << "\n";
    }
  }

  return 0;
}
