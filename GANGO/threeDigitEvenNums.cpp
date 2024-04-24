#include <iostream>

/*A given number n is entered from standard input, and then n three-digit
 *numbers are entered. Your task is to find the largest number whose sum of
 *digits must be an even number.*/

int largestNumberDigits(int num) {
  int sum = 0;

  while (num != 0) {
    int ld = num % 10;
    if (ld % 2 != 0) {
      sum += ld;
    }
    num /= 10;
  }

  return sum;
}

int main() {
  int n;
  std::cin >> n;

  int max;
  while (n != 0) {
    int input;
    max = input;
    std::cin >> input;
    if (input > 100 && input < 999) {
      int largest = largestNumberDigits(input);
      if (largest > max) {
        max = largest;
      }
    }
    n--;
  }
  std::cout << "max" << max << std::endl;
}
