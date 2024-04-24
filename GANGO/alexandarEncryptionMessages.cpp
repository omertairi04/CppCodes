
/* Alexandar tries to communicate via encrypted messages. He gives us the
 * following instructions on how to decipher the numbers he wants to send us to
 * make them readable. For a given number entered on standard input, reverse the
 * same. At the same time, the character x is also entered, for which all the
 * digits in the even positions of the number should be replaced with that
 * character. To print the reversed number with the even position character.
 * Note: The rightmost digits is winter as the 0th digit.
 * Example: the number 12345 has even digits 5,3,1; and inverted 54321.*/

#include <iostream>
#include <string>

int reversedNum(int num) {
  int reversed = 0;
  while (num != 0) {
    int ld = num % 10;
    reversed = (reversed * 10) + ld;
    num /= 10;
  }

  return reversed;
}

std::string msgWithText(int num, char x) {}

int main() {

  int si;
  std::cin >> si;

  char x;
  std::cin >> x;

  int rev = reversedNum(si);
  std::cout << rev << "\n";

  int position = 1; // Position starts from 1
  int extractedDigits = 0;

  while (rev != 0) {
    if (position % 2 == 0) {
      int digit = rev % 10; // Get the last digit
      // Add the digit to the result
      extractedDigits = extractedDigits * 10 + digit;
    }
    // Move to the next position
    position++;
    // Remove the last digit
    rev /= 10;
  }

  std::cout << "Digits at even positions: " << extractedDigits << std::endl;

  // while (rev > 0) {
  //   int rem = rev % 10;

  //   if (rem % 2 == 0) {
  //   }
  // }
}
