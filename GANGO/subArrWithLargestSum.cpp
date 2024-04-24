/* Write a program to find the subarray with the largest sum of elements and
 * print that sum. Additionally, find and print the percentage of elements used
 * in the subarray compared to the total number of elements in the array. Ex: 10
 * -2 1 -3 4 -1 2 1 -5 4 2
 * Output:
 * Maximum Sum: 7
 * Percentage of elements: 70%
percentage = (float(sum) / n) * 100.0; */

#include <iostream>
using namespace std;

int main() {
  int n, f[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  int maxSum = f[0];
  int currentSum = f[0];
  for (int i = 1; i < n; i++) {
    currentSum = max(f[i], currentSum + f[i]);
    maxSum = max(maxSum, currentSum);
  }

  cout << "Max sum: " << maxSum << endl;
  double percentage = (static_cast<double>(maxSum) / n) * 100.0;
  cout << "Percentage: " << percentage << "%" << endl;

  return 0;
}
