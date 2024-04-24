#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

class Bill {
  char *billNumber;
  int expense;
  char month[8];
  bool status;

public:
  Bill(){};

  Bill(char *num, int exp, char *m, bool s) {
    billNumber = new char[strlen(num + 1)];
    strcpy(billNumber, num);
    expense = exp;
    strcpy(month, m);
    status = s;
  }

  bool operator==(const Bill &b) {
    if (strcmp(billNumber, b.billNumber) == 0)
      return true;
    return false;
  }

  friend ostream &operator<<(ostream &out, Bill &b) {
    out << b.billNumber << " (" << b.month << ") - " << b.expense;
    return out;
  }

  char *getBillNumber() { return billNumber; }

  bool getStatus() { return status; }

  ~Bill() { delete[] billNumber; }
};

class UserProfile {
  char username[31];
  Bill *bills[30];
  int numInBills;

public:
  UserProfile(char *name) {
    strcpy(username, name);
    numInBills = 0;
    for (int i = 0; i < 30; i++) {
      bills[i] = NULL;
    }
  }

  UserProfile &operator+=(const Bill &bill) {
    if (numInBills >= 30) {
      return *this;
    }
    for (int i = 0; i < numInBills; i++) {
      if (*bills[i] == bill) { // Corrected comparison
        cout << "The bill already exists" << endl;
        return *this;
      }
    }

    bills[numInBills] = new Bill(bill);
    numInBills++;
    return *this;
  }

  friend ostream &operator<<(ostream &out, UserProfile &u) {
    for (int i = 0; i < u.numInBills; i++) {
      if (u.bills[i]->getStatus() != true) {
        out << "Pending bills for " << u.username << " are: " << u.bills[i];
      }
    }
    return out;
  }

  int totalDue(int month, int year) {
    cout << "Total due for month ";
    return 0;
  }
};

int main() {
  char number[50], month[8], name[50];
  int price, n;
  bool status;

  int type;
  cin >> type;

  if (type == 1) {
    cout << "-----Test Bill & operator &lt;&lt;-----" << endl;
    cin >> number >> price >> month >> status;
    Bill b(number, price, month, status);
    cout << b;
  } else if (type == 2) {
    cout << "-----Test Bill & operator == -----" << endl;
    cin >> number >> price >> month >> status;
    Bill b1(number, price, month, status);
    cin >> number >> price >> month >> status;
    Bill b2(number, price, month, status);
    if (b1 == b2)
      cout << "Equal" << endl;
    else
      cout << "Not equal" << endl;
  } else if (type == 3) {
    cout << "-----Test UserProfile & operator += &&lt;&lt; -----" << endl;
    cin >> name >> n;
    UserProfile up(name);
    for (int i = 0; i < n; i++) {
      cin >> number >> price >> month >> status;
      Bill s(number, price, month, status);
      up += s;
    }
    cout << up;
  } else if (type == 4) {
    cout << "-----Test UserProfile & operator += & totalDue -----" << endl;
    cin >> name >> n;
    UserProfile up(name);
    for (int i = 0; i < n; i++) {
      cin >> number >> price >> month >> status;
      Bill s(number, price, month, status);
      up += s;
    }
    int m, y;
    cin >> m >> y;
    cout << "Total due for month " << m << " and year " << y << " is:";
    cout << up.totalDue(m, y) << endl;
  } else if (type == 5) {
    cout << "-----Test all -----" << endl;
    cin >> name >> n;
    UserProfile up(name);
    for (int i = 0; i < n; i++) {
      cin >> number >> price >> month >> status;
      Bill s(number, price, month, status);
      up += s;
    }
    cout << up;
    int m, y;
    cin >> m >> y;
    cout << "Total due for month " << m << " and year " << y << " is:";
    cout << up.totalDue(m, y) << endl;
  }

  return 0;
}
