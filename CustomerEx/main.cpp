#include <iostream>
#include <ostream>
#include <string>
#include <exception>

using namespace std;

enum typeC {
    STANDARD,
    LOYAL,
    VIP
};

class UserExistsException : public exception {
  virtual const char* what() const throw() {
    return "The user already exists in the list";
  }
};

class Customer {
protected:
  string name;
  string email;
  typeC type;
  int baseDiscount;
  int additionalDiscount;
  int productsPurchased;

  // Constants
  static const int LOYAL_BASE_DISCOUNT = 10;
  static const int VIP_ADDITIONAL_DISCOUNT = 20;

public:
  Customer(const string &name="", const string &email="", typeC type=STANDARD, int products_purchased=0)
    : name(name.substr(0, 50)),  // Limit name to 50 characters
      email(email.substr(0, 50)),  // Limit email to 50 characters
      type(type),
      productsPurchased(products_purchased),
      additionalDiscount(0)  // Initialize additional discount to 0
  {
    if (type == STANDARD) {
      this->baseDiscount = 0;
    } else if (type == LOYAL) {
      this->baseDiscount = LOYAL_BASE_DISCOUNT;
    } else if (type == VIP) {
      this->baseDiscount = LOYAL_BASE_DISCOUNT;
      this->additionalDiscount = VIP_ADDITIONAL_DISCOUNT;
    }
  }

  int getProductsPurchased() {
    return this->productsPurchased;
  }

  void setType(typeC newType) {
    this->type = newType;
  }

  // Setter for base discount
  void setBaseDiscount(int b) {
    if (type == LOYAL || type == VIP) {
      this->baseDiscount = b;
    }
  }

  friend std::ostream & operator<<(std::ostream &os, const Customer &obj) {
    return os
           << obj.name << "\n" << obj.email << "\n" << obj.productsPurchased << "\n "
    << obj.type << obj.baseDiscount;
  }

  string getEmail() const {
    return email;
  }
};

class FINKI_bookstore {
  Customer *customers;
  int numOfBayer;

public:
  FINKI_bookstore() = default;

  FINKI_bookstore(Customer *customers, int num_of_bayer) {
    this->numOfBayer = num_of_bayer;
    this->customers = new Customer[numOfBayer];

    for (int i=0;i<numOfBayer;i++) {
      this->customers[i] = customers[i];
    }
  }

  void setCustomers(const Customer *newCustomers , int n) {
    if (n > numOfBayer) {
      delete [] customers;
      this->numOfBayer = n;
      customers = new Customer[numOfBayer];
    }
    for (int i=0;i<n;i++) {
      this->customers[i] = newCustomers[i];
    }
  }

  Customer &operator+=(Customer &newC) {
    Customer *newCustomers = new Customer[numOfBayer + 1];
    for (int i=0;i<numOfBayer;i++) {
      newCustomers[i] = customers[i];
    }
    UserExistsException e;
    numOfBayer += 1;
    try {
      for (int i=0;i<numOfBayer - 1;i++) {
        if (newC.getEmail() == customers[i].getEmail()) {
          throw e;
        }
      }
    } catch (exception& ex) {
      cout << ex.what();
    }
    newCustomers[numOfBayer] = newC;
  }

  void update() {
    // check loyals
    for (int i=0;i<numOfBayer;i++) {
      if (customers[i].getProductsPurchased() > 5) {
        customers[i].setType(LOYAL);
      }
      else if (customers[i].getProductsPurchased() > 10) {
        customers[i].setType(VIP);
      }
    }
  }

  friend std::ostream & operator<<(std::ostream &os, const FINKI_bookstore &obj) {

    for (int i=0;i<obj.numOfBayer;i++) {
      os << obj.customers[i];
    }

    return os;
  }
};

int main(){
  int testCase;
  cin >> testCase;
  int MAX = 50;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setBaseDiscount(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception!!!) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);

    fc+=c;

    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;

}

