#include <iostream>
using namespace std;

int reverse(int num) {
    int reversedN = 0;

    while (num != 0) {
        int ld = num % 10;
        num /= 10;
        reversedN = reversedN * 10 + ld;
    }

    return reversedN;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        int ld = num % 10;
        num /= 10;
        sum += ld;        
    } 

    return sum;
}

void printInterval(int f, int q) {
    for (int i = f; i <= q; ++i) {
        int sum = sumOfDigits(i);
        int rev = reverse(sum);
        if (sum != 0 && i % rev == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int n,b;
    cin >> n >> b;
    
    printInterval(n, b);
}

