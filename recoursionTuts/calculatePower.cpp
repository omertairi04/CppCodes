#include <iostream>
using namespace std;

int power(int base , int exp) {
    if (exp == 0) return 1;
    
    return base * power(base , exp - 1);
}

int main () {
    int base , exponent;
    cin >> base >> exponent;

    int result = power(base , exponent);
    cout << result << "\n";
}