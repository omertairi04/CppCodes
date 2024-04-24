#include <cstring>
#include <iostream>

bool isPalindrome(char txt[100]) {
  for (int i = 0; i < strlen(txt) / 2; i++) {
    if (txt[i] != txt[strlen(txt) - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  char str[100];
  std::cin.getline(str, 100);

  std::cout << isPalindrome(str);
}