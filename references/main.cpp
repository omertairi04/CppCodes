#include <iostream>
using namespace std;

void change(int &var) { var++; }

int main() {
  int a;
  cin >> a;
  int &b = a;
  cout << a << " " << b << "\n";
  change(a);
  cout << a << " " << b << "\n";
}