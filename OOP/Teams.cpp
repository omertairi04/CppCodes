#include <cstring>
#include <iostream>
using namespace std;

class Team {
  char name[50];
  int yearOfFounding;
  char city[50];

public:
  Team(char *name = "", int yearOfFounding = 0, char *city = "") {
    strcpy(this->name, name);
    this->yearOfFounding = yearOfFounding;
    strcpy(this->city, city);
  }

  char *getName() { return name; }

  void print() { cout << name << " " << yearOfFounding << endl; }
};

class Game {
  Team host;
  Team guest;
  int hostGoals, guestGoals;

public:
  Game(Team h, Team g, int hg, int gg)
      : host(h), guest(g), hostGoals(hg), guestGoals(gg) {}

  Team getHost() const { return host; }
  Team getGuest() const { return guest; }

  int getHostGoals() const { return hostGoals; }

  int getGuestGoals() const { return guestGoals; }
};

Team winner(const Game game1, const Game game2) {
  if (strcmp(game1.getHost().getName(), game2.getGuest().getName()) == 0 &&
      strcmp(game2.getHost().getName(), game1.getGuest().getName()) == 0) {
    int goalsHost = game1.getHostGoals() + game2.getGuestGoals();
    int goalsGuest = game1.getGuestGoals() + game2.getHostGoals();
    if (goalsHost >= goalsGuest) {
      return game1.getHost();
    } else {
      return game1.getGuest();
    }
  }
  return Team();
}

int main() {
  Team t1("Barcelona", 1900, "Barcelona");
  Team t2("Real Madrid", 1890, "Madrid");
  Team t3("Elche", 1950, "Elche");
  Game g1(t1, t2, 5, 0);
  Game g2(t2, t1, 2, 2);
  Game g3(t1, t3, 6, 2);
  Team w = winner(g1, g2);
  w.print();
  return 0;
}
