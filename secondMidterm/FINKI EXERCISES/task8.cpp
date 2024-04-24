#include <iostream>
using namespace std;

int Odd(int arr[], int n){
    int count=0;
    for (int i=0;i<n;i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }

    return count;
    
}



int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int countOdd = Odd(arr, n);
    cout << countOdd << " \n";

}


