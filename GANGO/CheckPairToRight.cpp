
/* Write a program that for a given N numbers in an array, will check whether
 * the pair that is next to each other is a prime number. NOTE: The array is
 * made up of digits 0 to 9. EX: 11 1 7 4 0 2 1 8 1 1 3 7 OUTPUT: number 17 is a
 * prime number number 40 is not a prime number number 21 is not a prime number
 * number 81 is not a prime number
 * number 13 is a prime number
 * number 7 is a prime number */

#include <iostream>
#include <string>

bool isPrime(int num) {
  if (num == 0 || num == 1) {
    return false;
  }
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int concatenate(int num1, int num2) {
  std::string str1 = std::to_string(num1);
  std::string str2 = std::to_string(num2);
  std::string joined = str1 + str2;
  return std::stoi(joined);
}

int main() {
  int n, number;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> number;
    if (number >= 0 && number <= 9) {
      arr[i] = number;
    } else {
      std::cout << "Invalid input: " << number << " is not a digit (0-9)."
                << std::endl;
      // Handle invalid input as needed, e.g., continue;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    int pair = concatenate(arr[i], arr[i + 1]);
    if (isPrime(pair)) {
      std::cout << "number " << pair << " is a prime number" << std::endl;
    } else {
      std::cout << "number " << pair << " is not a prime number" << std::endl;
    }
    i++;
  }

  return 0;
}
