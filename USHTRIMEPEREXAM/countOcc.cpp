#include <cstring>
#include <iostream>

int main() {
  char str[100];
  std::cin.getline(str, 100);

  // std::cout << str;
  char character[100];
  std::cin.getline(character, 100);
  int count = 0;

  for (char c : str) {
    for (int i = 0; character[i] != '\0'; i++) {
      if (c == character[i]) {
        count++;
        // Optionally, you can remove the matched character from the second
        // string character[i] = '\0';
      }
    }
  }

  std::cout << count << "\n";

  // for (char c : str) {
  //   for (int i = 0; character[i] != '\0'; i++) {
  //     if (c == character[i]) {
  //       count++;
  //     }
  //   }
  // }

  // std::cout << count << "\n";
}