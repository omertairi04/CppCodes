#include <iostream>
using namespace std;

int main() {
  // add elements to array
  const int size = 5;
  int numbers[size];

  for (int i = 0; i < size; i++) {
    cin >> numbers[i];
  }

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum++;
    cout << "Numbers in " << numbers[i] << endl;
  }
}
