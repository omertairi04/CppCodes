#include <cstring>
#include <iostream>

int main() {
  char str[100];

  std::cin.getline(str, 100);

  char *p = strstr(str, "how");

  std::cout << p << "\n";
}