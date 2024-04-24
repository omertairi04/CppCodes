#include <iostream>
using namespace std;

int multiply(int x , int y) {
    if (x == 0 || y==0) return 0;
    if (y > 0) {
        return x + multiply(x, y - 1);
    } else {
        return -x + multiply(x, y + 1);
    }
}

int main() {
    int num1 , num2;
    cin >> num1 >> num2;

    int result = multiply(num1,num2);
    cout << result;
}
