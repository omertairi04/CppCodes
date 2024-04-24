#include<iostream>
using namespace std;

int recursiveSum(int m, int k){
    if(m == 0){
        return 0;
    }
    int sum = 0;
    while(m > 0){
        int digit = m % 10;
        if(digit < k){
            sum += digit;
        }
        return sum + recursiveSum(m/10,k);
    }
}

int maxVal = -1;

int main(){
    int n, k, m;
    cin >> n >> k;
    while(n--){
        cin >> m;
        int currentSum = recursiveSum(m, k);
        if (currentSum > maxVal) {
            maxVal = currentSum;
        }
    }

    cout << maxVal << "\n";
    return 0;
}