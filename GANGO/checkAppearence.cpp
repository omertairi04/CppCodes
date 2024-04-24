
/* Write a program that will read n pairs of natural numbers (n is read first,
 * then the n pairs). It is necessary to check for each read pair of numbers,
 * whether all the digits of the first number appear in the second number. If
 * the condition is met, the program prints YES, otherwise NO. Checking whether
 * all the digits of one number appear in a second number should be done with
 * the function appears(int first, int second)*/

#include <iostream>
#include <string>
bool appears(int first, int second) {
  std::string f = std::to_string(first);
  std::string s = std::to_string(second);

  if (f.size() != s.size()) {
    return false;
  } else {
    for (int i = 0; i < f.size(); i++) {
      if (f[i] != s[i]) {
        return false;
      }
    }

    return true;
  }
}

int main() {
  int n, first, second;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> first >> second;
    bool isIn = appears(first, second);

    if (isIn) {
      std::cout << "YES \n";
    } else {
      std::cout << "NO \n";
    }
  }
}
