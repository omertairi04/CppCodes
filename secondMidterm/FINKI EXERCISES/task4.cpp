#include <iostream>
using namespace std;

int checkA(int a,int c, int count) {
    a=a/10;
    if (a == 0) {
        return count;
    }
    int ld=a%10;
    if (ld == c) {
        count++;
    }
    a/=10;
    return checkA(a , c , count);
}

int checkB(int b,int c, int count) {
    b=b/10;
    if (b == 0) {
        return count;
    }
    int ld=b%10;
    if (ld == c) {
        count++;
    }
    b/=10;
    return checkB(b , c , count);
}


int main() {

    int a ,b ,c ;

    while (cin >> a >> b >> c) {
        
        int ca = 0 , cb = 0;
        int countA = checkA(a , c , ca); 
        int countB = checkB(b , c , cb);
    
        if (countA >= countB) {
            cout << a << endl;
        } else {
            cout << b<< endl;
        }
    }


}