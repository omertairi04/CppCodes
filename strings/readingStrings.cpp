#include <iostream>

#define N 10

int main() {
  char ch, str[N];
  int i = 0;
  while ((i < N - 1) && (ch = getchar()) != '\n') {
    str[i++] = ch;
    std::cout << "ch in loop: " << ch << " ";
  }
  str[i] = '\0';
}