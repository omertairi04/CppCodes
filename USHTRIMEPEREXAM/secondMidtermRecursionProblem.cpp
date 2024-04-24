#include <iostream>
#include <cctype>
using namespace std;

int remove5(int n) {
    int currentVal = 0;
    if (currentVal != n) return 0;
    bool shownNegative;

    if (shownNegative != true) {
        cout << n -5;
        return -1;
    } else {
        return n + 5;
    }

}

int main() {

    int n;
    cin >> n;

    cout << remove5(n);    


}