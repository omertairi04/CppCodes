#include <iostream>
using namespace std;

int main() {

    string str[100];

    for (int i=0;i<5;i++) {
        cin >> str[i];
    }


    for (int i=0;i<5;i++) {
        cout << str[i] << " ";
    }
}