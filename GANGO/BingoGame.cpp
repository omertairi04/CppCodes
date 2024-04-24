/* In the Bingo game, an unknown number of numbers with values between 1 and 90
 * are drawn in order. More than 8 numbers are always drawn, while input stops
 * when a number outside the range of values is entered. Apart from the main
 * win, players also play on a wildcard number, the wildcard number is formed in
 * the following way: The less significant digits of the first 7 drawn numbers
 * are blinded, and all subsequent numbers entered are added to that number (the
 * last one entered which is out of range should not be added).
 *
 * Your task is to print the thus obtained wildcard number.
 *
 * Explanation of the test case:
 * The numbers entered are: 2 32 45 78 64 21 7 65 18 32 88 1 99
 *
 * The less significant digits than the first seven numbers pasted give the
 * number: 2258417*/

#include <iostream>

int main() {

  int unknownNumber, inputtedNumbers, countInputNums, sumOfLd;
  while (std::cin >> unknownNumber) {
    if (unknownNumber > 90) {
      break;
    }
    if (countInputNums < 7) {
      int ld = unknownNumber % 10;
      sumOfLd = (sumOfLd * 10) + ld;
    }
    // std::cout << unknownNumber << "\n";
    countInputNums++;
  }

  std::cout << sumOfLd;
}
