#include <iostream>
using namespace std;

bool isPrime(int number , int divisor = 2) {
    if (number <= 2) {
        return (number == 2);
    }
    if (number % divisor == 0) {
        return false;
    } else {
        if (divisor * divisor > number) {
            return true;
        } else {
            return isPrime(number , divisor + 1);
        }
    }
}

int sumOfPrime(int start , int end) {
    if (start > end) {
        return 0;
    } else {
        int sum = isPrime(start) ? start : 0;
        return sum + sumOfPrime(start + 1, end);
    }
}

int main() {
    int start , end;
    cin >> start >> end;

    int sum = sumOfPrime(start , end);
    cout << sum;
}

