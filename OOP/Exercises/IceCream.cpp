#include <cstring>
#include <iostream>
using namespace std;

class IceCream {
  char *name;
  int capacity;
  int length;
  char ingredient[100];
  float price;
  int discount;

public:
  IceCream(){};

  IceCream(char *name, char *ingredient, float price)
      : capacity(10), length(strlen(name)), price(price), discount(0) {
    this->name =
        new char[length +
                 1]; // Allocate memory for name (+1 for null terminator)
    strcpy(this->name, name);
    strcpy(this->ingredient, ingredient);
  }

  // Copy constructor
  IceCream(const IceCream &other)
      : capacity(other.capacity), length(other.length), price(other.price),
        discount(other.discount) {
    name = new char[length +
                    1]; // Allocate memory for name (+1 for null terminator)
    strcpy(name, other.name);
    strcpy(ingredient, other.ingredient);
  }

  friend ostream &operator<<(ostream &out, IceCream &c) {
    for (int i = 0; i < c.length; i++) {
      out << c.name[i];
    }
    out << endl << c.ingredient << c.price;
    if (c.discount > 0) {
      out << "[ " << c.discount << "]\n";
    }
    out << endl;
    return out;
  }

  IceCream operator++() {
    discount += 5;
    return *this;
  }

  IceCream operator+(char *rhs) {
    IceCream result(*this); // creates a copy of the current Ice Cream object
    int rhsLength = strlen(rhs);
    char *newName = new char[length + rhsLength + 2]; // +2 for '+' and '/0'
    strcpy(newName, name);
    newName[length] = '+';
    strcpy(newName + length, rhs);
    delete[] result.name;
    result.name = newName;
    result.length = rhsLength + 1;
    result.price += 10;
    return result;
  }

  void setDiscount(int discount) { this->discount = discount; }

  void setName(char *name) {
    int setLength = strlen(name);

    if (length != setLength) {
      delete[] this->name;
      char *newName = new char[setLength];
      this->name = new char[setLength + 1];
    }
    strcpy(this->name, name);
    length = setLength;
  }

  char *getName() { return name; }

  ~IceCream() { delete[] name; };
};

class IceCreamShop {
  char storeName[50];
  IceCream *iceCreams;
  int capacity;
  int numOfIceCream;

public:
  IceCreamShop() {}

  IceCreamShop(char *name) {
    strcpy(storeName, name);
    capacity = 20;
    numOfIceCream = 0;
    iceCreams = new IceCream[this->capacity];
  }

  void operator+=(IceCream &c) {
    if (numOfIceCream >= capacity) {
      this->capacity *= 2;
      IceCream *icyy = new IceCream[capacity];

      for (int i = 0; i < numOfIceCream; i++) {
        icyy[i] = iceCreams[i];
      }
      delete[] iceCreams;
      iceCreams = icyy;
    }
    iceCreams[numOfIceCream++] = c;
  }

  friend ostream &operator<<(ostream &out, IceCreamShop &c) {
    out << c.storeName << endl;
    for (int i = 0; i < c.numOfIceCream; i++) {
      out << c.iceCreams[i];
    }

    return out;
  }

  ~IceCreamShop() { delete[] iceCreams; }
};

// DO NOT CHANGE THE MAIN FUNCTION, EXCEPT THE MARKED PART FOR HANDLING WITH THE
// EXCEPTION
int main() {
  char name[100];
  char ingr[100];
  float price;
  int discount;

  int testCase;

  cin >> testCase;
  cin.get();
  if (testCase == 1) {
    cout << "====== TESTING IceCream CLASS ======" << endl;
    cin.getline(name, 100);
    cin.getline(ingr, 100);
    cin >> price;
    cin >> discount;
    cout << "CONSTRUCTOR" << endl;
    IceCream ic1(name, ingr, price);
    ic1.setDiscount(discount);
    cin.get();
    cin.getline(name, 100);
    cin.getline(ingr, 100);
    cin >> price;
    cin >> discount;
    IceCream ic2(name, ingr, price);
    ic2.setDiscount(discount);
    cout << "OPERATOR <<" << endl;
    cout << ic1 << endl;
    cout << ic2 << endl;
    cout << "OPERATOR ++" << endl;
    ++ic1;
    cout << ic1 << endl;
    cout << "OPERATOR +" << endl;
    IceCream ic3 = ic2 + "chocolate";
    cout << ic3 << endl;
  } else if (testCase == 2) {
    cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
    cin.getline(name, 100);
    cin.getline(ingr, 100);
    cin >> price;
    cout << "CONSTRUCTOR" << endl;
    IceCream ic1(name, ingr, price);
    cout << ic1 << endl;
    cout << "COPY CONSTRUCTOR" << endl;
    IceCream ic2(ic1);
    cin.get();
    cin.getline(name, 100);
    ic2.setName(name);
    cout << ic1 << endl;
    cout << ic2 << endl;
    cout << "OPERATOR =" << endl;
    ic1 = ic2;
    cin.getline(name, 100);
    ic2.setName(name);
    cout << ic1 << endl;
    cout << ic2 << endl;
    cout << "TESTING EXCEPTION" << endl;

    // your exception handling code

    cin >> discount;
    ic1.setDiscount(discount);

  } else if (testCase == 3) {
    cout << "====== TESTING IceCreamShop ======" << endl;
    char icsName[50];
    cin.getline(icsName, 100);
    cout << "CONSTRUCTOR" << endl;
    IceCreamShop ics(icsName);
    int n;
    cin >> n;
    cout << "OPERATOR +=" << endl;
    for (int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name, 100);
      cin.getline(ingr, 100);
      cin >> price;
      IceCream ic(name, ingr, price);
      ics += ic;
    }
    cout << ics;
  } else if (testCase == 4) {
    cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
    char icsName[50];
    cin.getline(icsName, 100);
    IceCreamShop ics(icsName);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name, 100);
      cin.getline(ingr, 100);
      cin >> price;
      IceCream ic(name, ingr, price);
      ics += ic;
    }
    IceCream x("FINKI fruits",
               "strawberry ice cream, raspberry ice cream, blueberry ice cream",
               60);
    IceCreamShop icp = ics;
    ics += x;
    cout << ics << endl;
    cout << icp << endl;
  }

  return 0;
}
