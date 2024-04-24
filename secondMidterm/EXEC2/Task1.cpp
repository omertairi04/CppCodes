#include <iostream>
using namespace std;

int main() {
    int avg=0 , belowAvg , aboveAvg, n;

    cin >> n;

    int prices[n];

    for (int i=0;i<n;i++) {
        cin >> prices[i];
    }

    for (int i=0;i<n;i++) {
        avg += prices[i] / n;
    }

    for (int i=0;i<n;i++) {
        if (prices[i] < avg) {
            belowAvg ++;
            cout << " 0 " << " ";
        } else {
            aboveAvg++;
            aboveAvg = 1;
            cout << " 1 " << " ";
        }
    }

    cout << "\n";

}

