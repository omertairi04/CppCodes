#include <iostream>
using namespace std;

int countOccurrence(int n, int digit) {
    int count = 0;
    while (n > 0) {
        if (n % 10 == digit) {
            count++;
        }
        n /= 10;
    }
    return count;
}

void findNumbers(int m , int n , int p) {
    int foundCount = 0;
    int currentNum = m + 1;

    while (foundCount < 10) {
        if (countOccurrence(currentNum, n) == p) {
            cout << currentNum << " ";
            foundCount++;
        }
        currentNum++;
    }
    cout << "\n";
}

int main() {
    
    int m , n ,p;

    cin >> m >> n >> p;

    findNumbers(m, n, p);

    return 0;    

}





