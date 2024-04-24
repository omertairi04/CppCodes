#include <cstring>
#include <iostream>
using namespace std;

class InvestmentPlan {
  char *investor;
  int sumOfInvestment;
  int shareNumber;
  bool isFromCurrentDay;

  void copy(const InvestmentPlan &p) {
    investor = new char[strlen(p.investor) + 1];
    strcpy(this->investor, p.investor);
    sumOfInvestment = p.sumOfInvestment;
    shareNumber = p.shareNumber;
    isFromCurrentDay = p.isFromCurrentDay;
  }

public:
  InvestmentPlan(){};

  InvestmentPlan(InvestmentPlan &ip) { copy(ip); }

  InvestmentPlan(char *name = "", int sum = 0, int number = 0,
                 bool is = false) {
    investor = new char[strlen(name) + 1];
    strcpy(this->investor, investor);
    sumOfInvestment = sum;
    shareNumber = number;
    isFromCurrentDay = is;
  }

  ~InvestmentPlan() {}
};

class InvestmentFund {
  char *fund;
  InvestmentPlan *investmentplans;
  int plans;    // how many exist in array
  int capacity; // the array size
  int sharePrice;

  void copy(InvestmentFund &f) {
    fund = new char[strlen(f.fund) + 1];
    strcpy(this->fund, f.fund);
    plans = f.plans;
    investmentplans = new InvestmentPlan[plans]; // Add missing semicolon

    // Copy the investment plans from the source object to the current object
    for (int i = 0; i < plans; ++i) {
      investmentplans[i] = f.investmentplans[i]; // Perform deep copy
    }
  }

public:
  InvestmentFund(){};

  virtual double profit() const = 0;

  ~InvestmentFund() { delete[] investmentplans; }
};

class MoneyFund : InvestmentFund {
  static float yearProvision;
};

class ActionFund : InvestmentFund {
  static float yearProvision;  // %
  static float entryProvision; // %

public:
};

float MoneyFund::yearProvision = 1.0;

float ActionFund::yearProvision = 1.5;
float ActionFund::entryProvision = 3.0;

int main() {

  char investitor[80], ime[50];
  double plan, brUdeli, udel;
  bool flag = false;
  int n, m;
  cin >> n;
  InvestmentFund **fondovi = new InvestmentFund *[n];
  for (int i = 0; i < n; i++) {
    cin >> ime;
    cin >> m;
    InvestmentPlan *ip = new InvestmentPlan[m];
    for (int j = 0; j < m; j++) {
      cin >> investitor >> plan >> brUdeli;
      if (j % 2)
        flag = true;
      else
        flag = false;
      InvestmentPlan IP(investitor, plan, brUdeli, flag);
      ip[j] = IP;
    }
    cin >> udel;
    if (i % 2) {
      fondovi[i] = new ActionFund(ime, ip, m, udel);

    } else {
      fondovi[i] = new MoneyFund(ime, ip, m, udel);
    }
  }
  cout << totalProfit(fondovi, n);
  return 0;
}
