#include <iostream>
using namespace std;

int check(int num, int last , int count) {

    if (num == 0) {
        return count;
    }

    if (num%10 == last) {
        count++;
    }

    num /= 10;

    return check(num,last,count);    

}

int main() {
    
    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<n;i++) {
        int count=0;
        int result = check(arr[i],arr[i]%10,count);
        cout << result << " ";
    }
    

}