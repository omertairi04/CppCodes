/* Numbers m, n and p are read from SI. Find the first 10 numbers greater than
 * m, that contain the digit n p-times. Implement the solution using a function
 * countOccurrence(int number, int digit) that takes two arguments, a number and
 * a digit, and returns the count of how many times the digit occurs in the
 * number.*/

int countOccurrence(int n, int d) {
  int count = 0;
  while (n) {
    int ld = n % 10;
    if (ld == d) {
      count++;
    }
    n /= 10;
  }

  return count;
}

#include <iostream>

int main() {
  int m, n, p;
  std::cin >> m >> n >> p;
  int countOf10M = 1; // Initialize countOf10M to 1

  while (countOf10M <= 10) {
    int occurrence = countOccurrence(m, n);
    if (occurrence == p) {
      std::cout << m << " ";
      countOf10M++;
    }
    m++;
  }
}
