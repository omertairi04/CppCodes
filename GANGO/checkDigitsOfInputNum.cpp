/* A number X is entered from standard input, then the numbers are entered until
 * something other than a number is entered. For each of the entered numbers
 * check if the number of digits is equal to the number of digits in X. For each
 * of the entered number, if the condition is met, print the number.*/

#include <iostream>

int countDigit(int n) {
  int count = 0;

  while (n != 0) {
    n /= 10;
    count++;
  }

  return count;
}

int main() {
  int x, number;

  std::cin >> x;
  int digitsOfX = countDigit(x);
  std::cout << digitsOfX << " \n";
  while (std::cin >> number) {

    int counter = countDigit(number);
    std::cout << counter << "\n";
    if (counter == digitsOfX) {
      std::cout << number << " \n";
    }
  }
}
