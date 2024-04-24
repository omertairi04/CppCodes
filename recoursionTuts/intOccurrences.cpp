#include <iostream>
using namespace std;

int countOccurrences(int arr[], int size , int element) {
    if (size == 0) return 0;
    
    if (arr[0] == element) {
        return 1 + countOccurrences(arr + 1,size - 1,element);
    }
    else {
        return countOccurrences(arr + 1, size -1, element);
    }
}

int main(){
    int n , el;
    cin >> n;
    int arr[n];
    
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    cout << "Enter element: \n";
    cin >> el;
    cout << countOccurrences(arr, n, el);
}
