/*
The structure Transaction must have the following information:

- Identification number (int)

- Paid amount (int)

- Commission (int)

- Was the transaction paid with a debit or credit card (0 - debit, 1 - credit)


Input limit: 0 < N < 100


Input format:

N

id1 sum1 commission1 type1

...

idn sumn Commissionn typen

Структура на влезните податоци:
N
id1 sum 1 commission 1 type 1
...
idn sum n Commission n type n

Example
3               2 222
1 100 10 0      3 11
2 202 20 1
3 10 1 1
*/

#include <iostream>

struct Transaction {
  int id;
  int paidAmount;
  int comission;
  bool paidType; // 0 - debit , 0 - credit

  void read() { std::cin >> id >> paidAmount >> comission >> paidType; }

  bool paidWithCredit(bool &flag) {
    if (paidType == 1) {
      int res = paidAmount + comission;
      std::cout << id << " " << res << "\n";
      flag = true;
    }
  }
};

int main() {
  int n;
  std::cin >> n;

  Transaction t[n];

  for (int i = 0; i < n; i++) {
    t[i].read();
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    t[i].paidWithCredit(flag);
  }
  if (!flag) {
    std::cout << "No credit card information \n";
  }
}
