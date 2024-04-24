#include <cctype>
#include <iostream>
using namespace std;
#define SIZE 91
int main() {
  int m, fC[SIZE];
  char ch, index;
  for (m = 0; m < SIZE; m++)
    fC[m] = 0;
  while ((ch = cin.get()) != EOF) {
    if (isalpha(ch)) {
      if (islower(ch))
        ch = toupper(ch);
      fC[ch]++;
    }
  }
  cout << "The text contains" << endl;
  cout << "Letter\t\tNumber of occurences" << endl;
  for (index = 'A'; index <= 'Z'; index++)
    cout << index << "\t\t" << fC[index] << endl;
  return 0;
}