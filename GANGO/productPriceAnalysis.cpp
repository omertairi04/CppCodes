/* You are tasked with analyzing product prices in a store to identify those
 * above and below the average price. The input consists of an integer n,
 * representing the number of products, followed by n prices (of those
 * products). Your goal is to compute the average price of all products and then
 * replace the prices below the average with 0 and prices above the average (or
 * equal) with 1. Print the average prices as well as the transformed array
 * (Check test cases). Ex:
 * 5
 * 100 150 200 250 300
 * Output:
 * 0 0 1 1 1
 */

#include <iostream>

int main() {
  int numProducts;

  std::cin >> numProducts;

  int nProductPrices[numProducts];

  for (int i = 0; i < numProducts; i++) {
    std::cin >> nProductPrices[i];
  }

  int sum = 0;
  for (int i = 0; i < numProducts; i++) {
    sum += nProductPrices[i];
  }

  int avg = sum / numProducts;

  for (int i = 0; i < numProducts; i++) {
    if (nProductPrices[i] >= avg) {
      nProductPrices[i] = 1;
    } else {
      nProductPrices[i] = 0;
    }
  }

  for (int i = 0; i < numProducts; i++) {
    std::cout << nProductPrices[i] << " ";
  }
}
