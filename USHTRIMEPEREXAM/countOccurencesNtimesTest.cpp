#include <cctype>
#include <iostream>
using namespace std;

#define SIZE 91

int main() {
  int letterKeepTrack[SIZE];
  char character;

  for (int i = 0; i < SIZE; i++) {
    letterKeepTrack[i] = 0;
  }

  while ((character = cin.get()) != EOF) {
    if (isalpha(character)) {
      if (islower(character)) {
        character = toupper(character);
      }
      letterKeepTrack[character - 'A']++;
    }
  }

  for (int i = 0; i < SIZE; i++) {
    cout << letterKeepTrack[i] << " ";
  }

  return 0;
}
