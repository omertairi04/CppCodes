#include <iostream>
using namespace std;

// Function to calculate factorial recursively
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to check if a number is strong
bool isStrong(int num) {
    int originalNum = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return sum == originalNum;
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size;
    
    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    
    cout << "Strong numbers: \n";
    for (int i = 0; i < size; ++i) {
        if (isStrong(arr[i])) {
            cout << arr[i] << endl;
        }
    }

    return 0;
}
