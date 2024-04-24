#include <cstring>
#include <iostream>
using namespace std;

enum Gender { MALE, FEMALE };

class Mate {
  char name[50];
  int age;
  Gender gender;

public:
  Mate() {}

  Mate(char *n, int a, Gender g) {
    strcpy(name, n);
    age = a;
    gender = g;
  }

  int getNameNumber() {
    int sum = 0;
    char *n = name;
    while (*n) {
      sum += *n;
      ++n;
    }
    return sum;
  }
};

class Date {
  Mate m1;
  Mate m2;

public:
  Date(Mate &_m1, Mate &_m2) {
    m1 = _m1;
    m2 = _m2;
  }

  bool isSuccess() {
    return (m1.getNameNumber() + m2.getNameNumber()) % 2 == 0;
  }
};

int main() {
  Mate m1("Barby", 20, MALE);
  Mate m2("Ken", 25, FEMALE);

  Date date(m1, m2);
  if (date.isSuccess()) {
    cout << "The date was success, lets make another one..." << endl;
  } else {
    cout << "This did not work out, good bye!" << endl;
  }

  return 0;
}