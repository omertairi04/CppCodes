#include <iostream>
#include<cstring>

using namespace std;

class Bill {
    char *number;
    int expense;
    char *year;
    bool payed;

public:
    Bill() {};

    Bill(char *num, int expense, char *y, bool payed) {
        number = new char[strlen(num) + 1];
        strcpy(this->number, number);
        this->expense = expense;
        year = new char[strlen(y) + 1];
        strcpy(this->year , year);
        this->payed = payed;
    }

    Bill(const Bill & b) {
        this->number = new char[strlen(b.number) + 1];
        strcpy(this->number , b.number);
        this->expense = b.expense;
        year = new char[strlen(b.year) + 1];
        strcpy(this->year , b.year);
        this->payed = b.payed;
    }


    char *getNumber() const {
      return number;
    }

    void setNumber(char *number) {
      Bill::number = number;
    }

    void setExpense(int expense) {
      Bill::expense = expense;
    }

    void setYear(char *year) {
      Bill::year = year;
    }

    void setPayed(bool payed) {
      Bill::payed = payed;
    }

    int getExpense() const {
      return expense;
    }

    char *getYear() const {
      return year;
    }

    bool isPayed() const {
      return payed;
    }

    bool operator==(const Bill &b) const {
      if(strcmp(this->number, b.number) == 0) {
        return true;
      };
      return false;
    }

    Bill& operator=(const Bill&b) {
      delete [] number;
      delete [] year;
      this->number = new char[strlen(b.number) + 1];
      strcpy(this->number , b.number);
      this->expense = b.expense;
      year = new char[strlen(b.year) + 1];
      strcpy(this->year , b.year);
      this->payed = b.payed;
      return *this;
    }

    friend ostream &operator<<(ostream &out, Bill &b) {
      out <<b.number << "(" << b.year << ") - " <<  b.expense << endl;
      return out;
    }

    int getMonth() const{
      return (year[0]-'0')*10 + year[1]-'0';
    }

    int gyear() const{
      return (year[3]-'0')*1000 + (year[4]-'0')*100 + (year[5]-'0')*10 + year[6]-'0';
    }

    ~Bill() {
        delete [] number;
        delete [] year;
    }
};

class UserProfile {
    char name[31];
    Bill *bills[31];
    int numOfBills;
public:
    UserProfile() {};

    UserProfile(char *n) {
      strcpy(this->name , n);
      for (int i=0;i<31;i++) {
        bills[i] = nullptr;
      }
      numOfBills = 0;
    }

    UserProfile &operator+=(const Bill &b) {
      if (this->numOfBills >= 30) {
        return *this;
      }
      for (int i=0;i<numOfBills;i++) {
        if (*bills[i] == b) {
          cout << "The bill already exists" << endl;
          return *this;
        }
      }

      bills[numOfBills] = new Bill(b);
      numOfBills++;
      return *this;
    }

    friend ostream& operator<<(ostream &out , const UserProfile &u) {
      for (int i=0;i<u.numOfBills;i++) {
        if (!u.bills[i]->isPayed()) {
          out << "Pending  bills for " << u.name << " are: \n";
          out << *u.bills[i] << endl;
        }
      }
      return out;
    }


//
//    friend ostream& operator<<(ostream& out, const UserProfile& up){
//      out << "Unpaid bills of user " << up.name << " are:\n";
//      for (int i = 0; i < up.numOfBills; i++){
//        if (!up.bills[i]->isPayed()){
//          out << *up.bills[i] << endl;
//        }
//      }
//      return out;
//    }
    int totalDue(int month , int year) {
      int sum(0);
      for (int i=0;i<numOfBills; i++){
        int m = bills[i]->getMonth();
        int y = bills[i]->gyear();
        if (month ==m && year == y) {
          sum += bills[i]->getExpense();
        }
      }
      return sum;
    }
};

int main() {
  char number[50], month[8], name[50];
  int price, n;
  bool status;


  int type;
  cin >> type;

  if (type == 1) {
    cout << "-----Test Bill & operator &lt;&lt;-----" << endl ;
    cin >> number >> price >> month >> status;
    Bill b(number, price, month, status);
    cout << b;
  } else if (type == 2) {
    cout << "-----Test Bill & operator == -----" << endl ;
    cin >> number >> price >> month >> status;
    Bill b1(number, price, month, status);
    cin >> number >> price >> month >> status;
    Bill b2(number, price, month, status);
    if (b1 == b2) cout << "Equal" << endl;
    else cout << "Not equal" << endl;
  } else if (type == 3) {
    cout << "-----Test UserProfile & operator += &&lt;&lt; -----" << endl ;
    cin >> name >> n;
    UserProfile up(name);
    for (int i = 0; i < n; i++) {
      cin >> number >> price >> month >> status;
      Bill s(number, price, month, status);
      up += s;
    }
    cout << up;
  } else if (type == 4) {
    cout << "-----Test UserProfile & operator += & totalDue -----" << endl ;
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
    cout << "-----Test all -----" << endl ;
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

