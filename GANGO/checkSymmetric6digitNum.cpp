/* Check if a specific inputted six-digit number is symmetric. This means that
   the first digit of the number should be the same as the last, the second
   should be the same as the second-to-last, and so on. For example symmetric
   numbers are: 123321, 890098, 999999. If the number is symmetric print 1,
   otherwise print 0.
*/

#include <iostream>
#include <string>

bool checkSymmetry(std::string str) {
  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;

  std::string str;
  str = std::to_string(n);
  bool isSymmetric = checkSymmetry(str);
  std::cout << isSymmetric << " \n";
}
