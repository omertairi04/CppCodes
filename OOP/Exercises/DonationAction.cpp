#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

class DonationAction {
  char *name;
  char id[50];
  int collectedFundValue;
  int neededFundValue;

  void copy(DonationAction &d) {
    if (correctId(d.id)) {
      name = new char[strlen(d.name) + 1];
      strcpy(this->name, name);
      strcpy(this->id, d.id);
      collectedFundValue = d.collectedFundValue;
      neededFundValue = d.neededFundValue;
    }
  }

public:
  DonationAction() {}

  DonationAction(char *name, char *id, int needed) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    if (correctId(id)) {
      strcpy(this->id, id);
      collectedFundValue = 0;
      neededFundValue = needed;
    }
  }

  DonationAction(DonationAction &d) { copy(d); }

  int getNeededMoney() { return neededFundValue - collectedFundValue; }

  friend ostream &operator<<(ostream &out, DonationAction &c) {
    if (c.collectedFundValue >= c.neededFundValue) {
      out << c.id << " " << c.name << c.getNeededMoney() << endl;
    } else {
      out << c.id << " " << c.name << " collected\n";
    }
    return out;
  }

  DonationAction &operator+=(int n) {
    this->collectedFundValue += n;
    return *this;
  }

  bool operator<(DonationAction &other) {
    if (this->getNeededMoney() != other.getNeededMoney())
      return false;
    return this->id < other.id;
  }

  bool correctId(char *id) {
    if (strlen(id) > 9) {
      cout << "The id number has more than 9 characters\n";
      return false;
    }
    for (int i = 0; i < strlen(id); i++) {
      if (!isdigit(id[i])) {
        cout << "The id number has a non-digit character \n";
        return false;
      }
    }
    return true;
  }

  char *getId() { return id; }

  ~DonationAction() { delete[] name; }
};

class DonationSociety {
  char presidentName[30];
  DonationAction *actions;
  int capacity;
  int numOfActions;

public:
  DonationSociety(char *name) {
    strcpy(presidentName, name);
    capacity = 20;
    actions = new DonationAction[capacity];
    numOfActions = 0;
  }

  bool takeDonation(char *id, int donatedFund) {
    for (int i = 0; i < numOfActions; i++) {
      if (actions[i].getId() == id) {
        actions[i] += donatedFund;
        return true;
      }
    }
    return false;
  }

  DonationSociety &operator+=(DonationAction &a) {
    if (numOfActions >= capacity) {
      capacity *= 2;
      DonationAction *tmp = new DonationAction[capacity];
      for (int i = 0; i < numOfActions; i++)
        tmp[i] = actions[i];
      delete[] actions;
      actions = tmp;
    }
    for (int i = 0; i < numOfActions; i++) {
      if (actions[i].getId() == a.getId())
        return *this;
    }
    actions[numOfActions] = a;
    numOfActions++;
    return *this;
  }

  friend ostream &operator<<(ostream &out, DonationSociety &d) {
    int minIndex = 0;
    for (int i = 0; i < d.numOfActions; i++) {
      if (d.actions[minIndex] < d.actions[i]) {
        cout << d.actions[minIndex];
        minIndex = i;
      }
    }
    out << d.presidentName << endl;
    return out;
  }

  ~DonationSociety() { delete[] actions; }
};

int main() {

  DonationSociety donacii("Velko Velkovski");
  int n;
  char naziv[50], id[50];
  int potrebnasuma, doniranasuma;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin.get();
    cin.getline(naziv, 50);
    cin >> id >> potrebnasuma;

    DonationAction edna(naziv, id, potrebnasuma);
    donacii += edna;
  }

  // donation
  cin >> n;
  for (int i = 0; i < n; i++) {

    cin >> id >> doniranasuma;

    if (!donacii.takeDonation(id, doniranasuma))
      cout << "The donation is not taken. Wrong ID." << endl;
  }
  cout << "===============" << endl;
  cout << donacii;
}
