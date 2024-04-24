#include <cstring>
#include <iostream>
using namespace std;

class Goal {
  char scorer[10];
  int time; // minute
  char team[50];

public:
  Goal() {}

  Goal(char *scorer, int time, char *team) {
    strcpy(this->scorer, scorer);
    this->time = time;
    strcpy(this->team, this->team);
  }

  Goal(const Goal &g) {
    strcpy(this->scorer, g.scorer);
    time = g.time;
    strcpy(this->scorer, g.team);
  }

  friend ostream &operator<<(ostream &out, Goal &g) {
    out << g.time << " " << g.scorer << endl;
    return out;
  }

  // postfix ++
  Goal operator++(int i) {
    Goal r(*this);
    time++;
    return r;
  }

  // prefix --
  Goal operator--() {
    time--;
    return *this;
  }

  ~Goal() {}
};

class Game {
  Goal *goals;
  int capacity;
  int numOfGoals;
  char team1[50];
  char team2[50];

public:
  Game() {}

  Game(char *team1, char *team2) : numOfGoals(0) {
    strcpy(this->team1, team1);
    strcpy(this->team2, team2);
    capacity = 10;
    goals = new Goal[10];
  }

  Game &operator+=(const Goal &g) {
    if (numOfGoals >= capacity) {
      resizeArray();
    }
    goals[numOfGoals++] = g;
    return *this;
  }

  void resizeArray() {
    capacity *= 2;
    Goal *newGoal = new Goal[capacity];

    for (int i = 0; i < numOfGoals; i++) {
      newGoal[i] = goals[i];
    }
    delete[] goals;
    goals = newGoal;
  }

  friend ostream &operator<<(ostream &out, Game &game) {
    out << game.team1 << " - " << game.team2 << endl;
    for (int i = 0; i < game.numOfGoals; i++) {
      out << game.goals[i];
    }

    return out;
  }
};

int main() {
  char team1[50];
  char team2[50];
  cin >> team1;
  cin >> team2;
  Game n(team1, team2);
  int x;
  cin >> x;
  char player[100];
  int m;
  for (int i = 0; i < x; ++i) {
    cin >> player;
    cin >> m;
    cin >> team1;
    Goal g(player, m, team1);
    n += g;
  }
  cout << n << endl;
  return 0;
}
