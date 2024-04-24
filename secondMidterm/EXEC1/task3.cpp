#include <iostream>
using namespace std;

int reverse(int number) {
    int originalNumber = number;
    int reversedNumber = 0;
    
    while (originalNumber != 0) {
        int lastDigit = originalNumber % 10;
        originalNumber /= 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
    }

    return reversedNumber;
}

bool isPalindrome(int number) {

    int reversedNumber = reverse(number);
    if (number == reversedNumber) {
        return true;
    } else {
        return false;
    }
}

int findLargest(int start, int end) {
    int largest = -1;

    for (int i=start; i<=end;i++) {
        if (isPalindrome(i) && i > largest) {
            largest = i;
        }
    }

    return largest;
}

int main() {
    int start , end;

    cin >> start >> end;

    int largest = findLargest(start, end);    
    cout << largest << "\n";
}