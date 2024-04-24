/*
Write a program where a 5 digit number is entered from standard input. The
program prints 1 if the number is special, and 0 otherwise. A number is
considered special if it is divisible by the sum of its second and third
digits, and the first, third and the fifth digits are in a strictly ascending
order. Be careful about division by 0, print -1 in such a case.
*/

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  bool isSpecial = false;

  int secondDigit = (n / 1000) % 10;
  //   std::cout << secondDigit << " \n";
  int thirdDigit = (n / 100) % 10;
  //   std::cout << thirdDigit << " \n";

  int sumOfsecondAndThird = secondDigit + thirdDigit;

  int lastDigit = n % 10;
  //   std::cout << lastDigit << " \n";

  int firstDigit = n / 10000;
  //   std::cout << firstDigit << " \n";

  if (n % sumOfsecondAndThird == 0 && firstDigit < secondDigit &&
      secondDigit < thirdDigit && thirdDigit < lastDigit) {
    isSpecial = true;
  }

  std::cout << isSpecial << " \n";
}
