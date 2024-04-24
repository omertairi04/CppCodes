/* Write a function letterFrequency(char text[], char letter) that for a given
 * letter will print information about the relative frequency of occurrence of
 * that letter in the text string text(as a lowercase and as an uppercase
 * letter). Limit is 1000 characters. The relative frequency of a letter is
 * calculated as the quotient of the number of occurrences of that letter and
 * the total number of letters in the text. Ex: Fejmi qazimi is the goat, edin
 * is the elephant, elmi is elegant and electric.
 *     E*/

#include <cctype>
#include <cstring>
#include <iostream>

double letterFrequency(char text[], char letter) {
  int length = strlen(text);
  double charCounter = 0, totalLetters = 0;

  for (int i = 0; i < length; i++) {
    if (text[i] == letter) {
      charCounter++;
    }
    if (isalpha(text[i])) {
      totalLetters++;
    }
  }

  return charCounter / totalLetters;
}

int main() {

  char string[100], c;

  std::cin.getline(string, 100);
  std::cin >> c;

  std::cout << letterFrequency(string, c);
}