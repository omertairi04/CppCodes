#include <iostream>

int main() {
  // Input string
  char str[] = "I am a programmer from Kumanova";

  // Define variables
  const int maxWords = 20;   // Maximum number of words
  char words[maxWords][100]; // Assuming maximum word length is 50 characters
  int wordCount = 0;         // Counter for the number of words found
  int wordIndex = 0;         // Index to navigate within each word

  // Iterate through each character in the string
  for (int i = 0; str[i] != '\0'; ++i) {
    // If the current character is a space or the end of the string
    if (str[i] == ' ' || str[i + 1] == '\0') {
      // Null-terminate the current word
      words[wordCount][wordIndex] = '\0';
      // Move to the next word
      wordCount++;
      wordIndex = 0;
      // If maximum words reached, break out of the loop
      if (wordCount >= maxWords) {
        break;
      }
    } else {
      // Copy the character to the current word
      words[wordCount][wordIndex] = str[i];
      // Move to the next character within the current word
      wordIndex++;
    }
  }

  // Output each word separately
  std::cout << "Separated words:" << std::endl;
  for (int i = 0; i < wordCount; ++i) {
    std::cout << words[i] << std::endl;
  }

  return 0;
}