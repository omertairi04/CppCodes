#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    string str[n];

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    if (n % 2 == 1) {
        for (int i=n;i>n;i++) {
            cout << str[i] << "";
        }    
    }

    

}
